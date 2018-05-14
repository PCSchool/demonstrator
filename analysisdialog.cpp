#include "analysisdialog.h"
#include "ui_analysisdialog.h"
#include <QBuffer>
#include <iostream>
#include <fstream>
#include <QMessageBox>
#include <binaryreader.h>
#include <binarywriter.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>      //library crypt32 missing
#include <wincrypt.h>
#include <windows.h>
#include <QLibrary>

using namespace std;

AnalysisDialog::AnalysisDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnalysisDialog)
{
    ui->setupUi(this);
    xAxis = 0;
    counter = 0;
    Analysis = new Analysis();
    int bufferSize = 1024;
    QByteArray* array = new QByteArray[bufferSize];
    qbuffer.setBuffer(array);
}

AnalysisDialog::~AnalysisDialog()
{
    delete ui;
}

//read out binary file
void AnalysisDialog::on_btnReadBinaryFile_clicked()
{
    TimePointer d1, d2;
    QByteArray array;
    //open file for binary reading
    std::ifstream fin("testerFile.bin", std::ios_base::in | std::ios_base::binary);
    if(!fin.is_open()){
        std::cout << "NOT OPEN";
    }else{
        /*fin.close();
        char buff[1024];
        FILE * file = fopen("recording_2.bin", "rb");
        int bytes_read = fread(buff, sizeof(128), 1024, file);

        std::ifstream in("recording_2.bin", std::ios_base::in | std::ios_base::binary);
        fin.read(buff, 1024);
        fin.close();
         */
    }


    QFile file("C:/Users/Onera/Documents/SignalSleepDemonstrator/testerFile.bin");
    file.open(QIODevice::ReadOnly);

    QDataStream fileStream(&file);
    fileStream.setByteOrder(QDataStream::LittleEndian);

    char *temp = new char[1024];
    fileStream.readRawData(reinterpret_cast<char*>(temp), 1024);
    array.append(temp, 1024);

    delete temp;

    std::cout << "done " << array.size() << " p-- " << sizeof(array);
}

void AnalysisDialog::on_btnGenerate_clicked()
{ 
    QString path = "C:/Users/Onera/Documents/SignalSleepDemonstrator/testerFile.bin";
    QByteArray* array = new QByteArray[1024];
    //ensure file gets created
    ofstream myfile;
    myfile.open(path.toLocal8Bit().constData());
    myfile.close();

    qbuffer.setBuffer(array);

    struct Axis{
        double x, y;
    } axis;
    axis.y = counter;
    axis.x = xAxis;

    for(int x = 0; x < 15; x++){

        axis.x = xAxis;
        axis.y = counter;

        //std::cout << "added: " + QString::number(counter) + " - " + QString::number(xAxis) << endl;

        qbuffer.buffer().prepend(reinterpret_cast<char *>(&axis));
        qbuffer.open(QIODevice::ReadWrite | QIODevice::Truncate );
        qbuffer.write(reinterpret_cast<char *>(&axis), std::ios_base::app | std::ios::binary);
        qbuffer.close();

        char b[sizeof(axis)];
        memcpy(b, &axis, sizeof(axis));

        Axis axis2;
        memcpy(&axis2, b, sizeof(axis2));
        cout << "test x = " << axis2.x << " y = " << axis2.y << endl;

        std::cout << "analysisDialog: writing " << xAxis << " " << counter << endl;
        randomize();
    }

    std::ofstream fout(path.toLocal8Bit().constData(), std::ios::binary | std::ios_base::app);
    fout.write(reinterpret_cast<char *>(&qbuffer), sizeof(qbuffer));
    fout.close();

    std::cout << "done writing , start reading" << endl;
}

void AnalysisDialog::on_btnSelectRecording_clicked()
{
    //recording_0  <-- real recording file, contains 16KB, 16444 bytes
    //testerFile   <-- fake testing file contains 8 bytes
    std::ifstream fin("recording_2.bin", std::ios_base::in | std::ios_base::binary);
    if(!fin.is_open()){
        std::cout << "File couldnt be found nor opened.";
    }else{
        //get the length of the file
        fin.seekg(0, ios::end);

        size_t fileSize = fin.tellg();
        fin.seekg(0, ios::beg);

        //create  a <vector> to hold all the bytes in the file
        std::vector<byte> vector(fileSize, 0);

        //read the file
        fin.read(reinterpret_cast<char*>(&vector[0]), sizeof(fileSize));

        //loop in buffer
        int counter = 0;
        QByteArray *array;
        char b[sizeof(array)];

        uint_fast16_t len;
        fin.read((char*)&len, 2);

        std::string str(len, '\o');
        array = reinterpret_cast<QByteArray*>(&len);
        int length = vector.size();

        QFile myfile("recording_2.bin");
        myfile.setFileName("recording_2.bin");
        //if(!myfile.open(QIODevice::ReadOnly)) return;

        std::cout << " Done reading  \n Bytes readed in file : " << counter << "\n fileSize file : " << fileSize << " \n array_size" << array->size() << "\n data size : " << vector.size() << endl;
    }
}

void AnalysisDialog::setDir(QDir dir){
    this->dir = dir; 
}

void AnalysisDialog::randomize(){
    xAxis++;
    counter++;
}

void AnalysisDialog::on_btnCancel_clicked()
{
    //open file read constantly 16 bytes - 128 bits out
    std::ifstream fin("recording_4.bin", std::ios_base::in | std::ios_base::binary);
    if(!fin.is_open()){
        std::cout << "File couldnt be found nor opened.";
    }else{
        //get the length of the file
        fin.seekg(0, ios::end);

        size_t fileSize = fin.tellg();
        fin.seekg(0, ios::beg);

        std::vector<byte> vector(fileSize, 0);

        //create  a <vector> to hold all the bytes in the file
        fin.read(reinterpret_cast<char*>(&vector[0]), sizeof(fileSize));

        //read the file
        char temp[fileSize];
        //fin.read(reinterpret_cast<char*>(&data[0]), sizeof(fileSize));

        TimePointer d1;
        d1.x = 0;
        d1.y = 0;

        fin.read(temp, 0-128);
        memcpy(&d1, temp, sizeof(TimePointer));
        std::cout << "test d1: " << d1.x << " - " << d1.y << " \n";

        fin.read(&temp[0-128], (128-256));
        memcpy(&d1, temp, sizeof(TimePointer));
        std::cout << "test d2: " << d1.x << " - " << d1.y << " \n";

        fin.read(&temp[128-256], (256-384));
        memcpy(&d1, temp, sizeof(TimePointer));
        std::cout << "test d3: " << d1.x << " - " << d1.y << " \n";
        //each character pointer on the system in 4-bytes long

    }
}

void AnalysisDialog::on_btnSelectRecording_2_clicked()
{
    //dir.path() = QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()));
    QString path = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                dir.path(), QFileDialog::ShowDirsOnly);
    analysis.setRecordingDir(QDir(path));
    analysis.setRecordingFile(QFile(path));
}

void AnalysisDialog::on_btnPrintResult_clicked()
{
    //1. read recording -> get all TimerPoints of recording -> put them in list(?) -> create customplot based of recording
}
