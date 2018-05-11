#include "binarywriter.h"
#include <QFile>
#include <iostream>
#include <fstream>
#include <ostream>
#include <streambuf>
#include <QDataStream>
#include <QMessageBox>
#include <stdint.h>
#include <cstdlib>
#include <bitset>
#include <QWaitCondition>
#include <stdio.h>
#include <QBuffer>
#include <QDir>
#include <QApplication>
#include <mutex>
#include <recorddialog.h>

using namespace std;

BinaryWriter::BinaryWriter()
{
    numberFile = 0;
    dataSize = 1000;
    bufferSize = 1024;
    numUsedBytes = 1;
    QByteArray* array = new QByteArray[bufferSize];
    qbuffer.setBuffer(array);
    vectorData = new std::vector<Data>;
}

void BinaryWriter::setUserDir(QDir dir){
    //should be used for binarywriter as directory where the file should be stored
    this->dir = dir;
    std::cout << dir.path().toLocal8Bit().constData();
}

//fill the buffer
void BinaryWriter::writeData(double xAxis, double yAxis){
     //write new data to buffer
     struct Data{
         double x, y;
     } data;
     data.x = xAxis;
     data.y = yAxis;

     EnterCriticalSection(&shared_buffer_lock);
     vectorData.push_back(data);
     qbuffer.buffer().resize(sizeof(&data));
     qbuffer.buffer().prepend(reinterpret_cast<char*>(&data));
     qbuffer.open(QIODevice::ReadWrite | QIODevice::Truncate );
     qbuffer.write(reinterpret_cast<char *>(&data), std::ios::binary);
     qbuffer.close();
     emit qbuffer.readyRead();  //always emit readyRead() when new data has arrived
     numUsedBytes = numUsedBytes + 16; //struct Data is 16 bytes
     LeaveCriticalSection(&shared_buffer_lock);

     if(bufferSize < numUsedBytes){
         std::cout << QString::number(qbuffer.currentWriteChannel()).toLocal8Bit().constData() << " ";

         //signal buffer is full + parameter with qByteArray
         std::cout << "signal BinaryWriter" << endl;
         emit bufferFull(qbuffer.buffer(), vectorData);             //signal buffer is full --> binaryReader will take action, will start reading the buffer and write it to the file within the selected directory
         qbuffer.buffer().clear();                      //empty the buffers
         numUsedBytes = 0;
     }else{
         //std::cout << QString::number(0).toLocal8Bit().constData();
     }
}

void BinaryWriter::testRead(){
    struct Data{
        double x, y;
    } data;

    std::cout << "comes here";

    int count  = 0;
    //read values within qbuffer
    //for(auto it = qbuffer.buffer().begin(); it != qbuffer.buffer().end(); ++it){

    std::cout << "BinaryWriter::testRead() -> " << count;
}

void BinaryWriter::writeToFile(){
    bufferDoneWriteFile.wait(&mutex);

    //write buffer to file
    std::cout << "BinaryWriter::writeToFile() -> ";

    bufferIsFull.wakeAll();
}
