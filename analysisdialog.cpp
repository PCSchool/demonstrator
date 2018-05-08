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

    QVector<double> doubleList(QVector<double>(30));
    qbuffer.setBuffer(array);

    struct Axis{
        double x, y;
    } axis;
    axis.y = xAxis;
    axis.x = counter;

    for(int x = 0; x < 15; x++){

        axis.y = counter;
        axis.x = xAxis;
        doubleList.append(xAxis);
        doubleList.append(counter);

        //std::cout << "added: " + QString::number(counter) + " - " + QString::number(xAxis) << endl;

        qbuffer.buffer().prepend(reinterpret_cast<char *>(&axis));
        qbuffer.open(QIODevice::ReadWrite | QIODevice::Truncate );
        qbuffer.write(reinterpret_cast<char *>(&axis), std::ios_base::app | std::ios::binary);
        qbuffer.close();
        std::cout << "analysisDialog: writing " << endl;
        randomize();
    }

    std::ofstream fout(path.toLocal8Bit().constData(), std::ios::binary | std::ios_base::app);
    fout.write(reinterpret_cast<char *>(&array), sizeof(array));
    fout.close();
    std::cout << "test results " << endl;
    for (auto const& c : doubleList)
        std::cout << c << endl;

    std::cout << "done writing , start reading" << endl;
}

void AnalysisDialog::on_btnSelectRecording_clicked()
{
    struct Axis{
        double x, y;
    } axis;

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

        //loop in buffer
        //option 1. loop const
        for (auto i : data){
            std::cout << i << " - ";
            Axis a;
            //memcpy(&axis, data, sizeof(Axis));
            //assert(data.size() == sizeof(Axis));
            memcpy(&a, &data, std::min(data.size(), sizeof(Axis)));
            std::cout << a.x;
        }
        std::cout << " Done writing";

        //option 2. for loop and byte[16]


        //option 3. ?

        //close the file
        fin.close();

        std::cout << data.size();
    }
    std::cout << " open dialog and select recording of choice." << endl;
}

void AnalysisDialog::randomize(){
    xAxis++;
    counter++;
}
