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
    QByteArray fillArray, array;
    QString pathfile = "recording_1.bin";

     //1 - FILE
    char buff[1024];
    FILE * file = fopen(pathfile.toLocal8Bit().constData(), "rb");
    int bytes_read = fread(buff, sizeof(256), 1024, file);

    std::cout << " 1 : FILE - " <<bytes_read << endl;

    // 2 - std::ifstream
    std::ifstream fin(pathfile.toLocal8Bit().constData(), std::ios_base::in | std::ios_base::binary);
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

        /*fin.read(temp, 0-128);
        memcpy(&d1, temp, sizeof(TimePointer));
        std::cout << "test d1: " << d1.x << " - " << d1.y << " \n";*/

        std::cout << " 2 : std::ifstream - " << vector.size()<<  endl;
        fin.close();
    }

    // 3 - QFile
    QFile file4(pathfile);
    file4.open(QIODevice::ReadOnly);
    fillArray = file4.readAll();
    std::cout << " 3 : QFile - " << fillArray.size() << " " << endl;

    fillArray.clear();

    // 4
    QDataStream fileStream(&file4);
    fileStream.setVersion(QDataStream::Qt_5_10);
    fileStream.setByteOrder(QDataStream::LittleEndian);
    char *temp = new char[sizeof(fileStream)];
    fileStream.readRawData((temp),sizeof(fileStream));
    size_t tt = sizeof(fileStream);
    array.append(temp, tt);
    char *buf = (char *)malloc(sizeof(temp) * tt);
    TimePointer *test = (TimePointer *) buf;
    //std::cout << test->x << " - " << test->y << " " <<endl;
    std::cout << " 4 : QDataStream - " << sizeof(fileStream) << endl;

    //file4.open(QIODevice::WriteOnly | QIODevice::Append);
    //QDataStream in(&file4);
    //in.setVersion(QDataStream::Qt_5_10);
    //in.setByteOrder(QDataStream::LittleEndian);
   // char *raw = new char[sizeof(in)];

    //in.readRawData((temp),sizeof(in));
    //in.readBytes((raw), sizeof(in));
    //array.append((raw), sizeof(in));
    //out.readBytes(file4.)
    //out.readRawData(array.constData(), array.length());

    //TimePointer* tp = reinterpret_cast<TimePointer*>(array.data());
    //memcpy(&d1, temp, sizeof(TimePointer));
    //std::cout << "test d1: " << d1.x << " - " << d1.y << " \n";


    file4.close();

    std::cout << "real bytes : 577 " <<endl ;
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
    //get QByteArray from file
    QFile file("recording_1.bin");
    if(!file.open(QIODevice::ReadOnly))
        return;
    QByteArray array = file.readAll();

    std::cout << "recording_1.bin - " << array.size() << endl;

    //create QDataStream and start reading from it to get all TimePointers
    QDataStream readstream(&array, QIODevice::ReadOnly);


}

//write to file
QDataStream& operator <<(QDataStream& stream, const TimePointer& tp){

}
//read from file
QDataStream& operator >>(QDataStream& stream, TimePointer& tp){
    QFile file("recording_1.bin");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in >> tp;
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
    const QString path =  QFileDialog::getOpenFileName(
                this,
                "Open Document",
                dir.path(),
                "All files (*.*) ;; Document files (*.doc *.rtf);; PNG files (*.png)");
    analysis.setRecordingDir(QDir(path));
    QFile file;
    analysis.setRecordingFilePath(path);
}

void AnalysisDialog::on_btnPrintResult_clicked()
{


}
