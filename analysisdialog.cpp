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
    struct Axis{
        double x, y;
    } axis;

    //open file for binary reading
    std::ifstream fin("testerFile.bin", std::ios_base::in | std::ios_base::binary);
    if(!fin.is_open()){
        std::cout << "NOT OPEN";
    }else{
        //get the length of the file
        fin.seekg(0, ios::end);

        size_t fileSize = fin.tellg();
        fin.seekg(0, ios::beg);

        //create  a <vector> to hold all the bytes in the file
        std::vector<byte> data(fileSize, 0);

        //read the file
        fin.read(reinterpret_cast<char*>(&data[0]), sizeof(fileSize));

        //close the file
        fin.close();
    }

    //CertCreateCertificateContext(PKCS_7_ASN_ENCODING,
    //                             reinterpret_cast<BYTE*>(&data[0]),
    //                               static_cast<DWORD>(data.size()));

    //QFile file("C:/Users/Onera/Documents/SignalSleepDemonstrator/testerFile.bin");
    //file.open(QIODevice::ReadOnly);
    //QDataStream fileStream(&file);
    //fileStream.readRawData(reinterpret_cast<char*>&);

    //std::cout << data.size() << " reading results " << endl;
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
    struct Axis{
        double x, y;
    } axis;

    //recording_0  <-- real recording file, contains 16KB, 16444 bytes
    //testerFile   <-- fake testing file contains 8 bytes
    std::ifstream fin("recording_0.bin", std::ios_base::in | std::ios_base::binary);
    if(!fin.is_open()){
        std::cout << "File couldnt be found nor opened.";
    }else{
        //get the length of the file
        fin.seekg(0, ios::end);

        size_t fileSize = fin.tellg();
        fin.seekg(0, ios::beg);

        //create  a <vector> to hold all the bytes in the file
        std::vector<byte> data(fileSize, 0);

        //read the file
        fin.read(reinterpret_cast<char*>(&data[0]), sizeof(fileSize));

        Axis a;
        //loop in buffer
        int counter = 0;
        QByteArray *array;
        char b[sizeof(array)];

        //read exactly 5 bytes == size bytearray into file and then uh

        uint_fast16_t len;
        fin.read((char*)&len, 2);

        std::string str(len, '\o');
        array = reinterpret_cast<QByteArray*>(&len);

        //option 1. loop const
        /*for (auto i : data){
            std::size_t entry_size = 0;

            reinterpret_cast<char*>(&data[i], sizeof(i));
            //memcpy(&array, b, sizeof(array));
            counter++;
            //convert back to struct Axis
        }*/

        std::cout << " Done reading  \n Bytes readed in file : " << counter << "\n fileSize file : " << fileSize << "\n data size : " << data.size() << endl;
        //close the file
        fin.close();

        //std::cout << sizeof(data) << " bits ";    // sizeof(data) == 12 bits
        //std::cout << sizeof(Axis) << " bits ";  // sizeof(Axis) == 16 bits
        //std::cout << data.size() << " size ";   //sizeof(fileSize) == 4 bits
    }
}

void AnalysisDialog::setDir(QDir dir){
    this->dir = dir;
}

void AnalysisDialog::randomize(){
    xAxis++;
    counter++;
}
