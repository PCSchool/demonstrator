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
#include <globals.h>

using namespace std;

BinaryWriter::BinaryWriter()
{
    numberFile = 0;
    dataSize = 1000;
    bufferSize = 1024;
    numUsedBytes = 1;
    QByteArray* array = new QByteArray[bufferSize];
    qbuffer.setBuffer(array);
    //vectorData = new std::vector<TimePointer>;
}

void BinaryWriter::setUserDir(QDir dir){
    //should be used for binarywriter as directory where the file should be stored
    this->dir = dir;
    std::cout << dir.path().toLocal8Bit().constData();
}

//fill the buffer
void BinaryWriter::writeData(double xAxis, double yAxis){
     TimePointer data;
     data.x = xAxis;
     data.y = yAxis;

     EnterCriticalSection(&shared_buffer_lock);
     qbuffer.buffer().resize(sizeof(&data));
     qbuffer.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Append );
     qbuffer.write(static_cast<char*>(static_cast<void*>(&data)), std::ios::binary);
     vector.push_back(data);

     qbuffer.close();
     //emit qbuffer.readyRead();  //always emit readyRead() when new data has arrived
     numUsedBytes = numUsedBytes + 16; //struct TimePointer is 16 bytes
     LeaveCriticalSection(&shared_buffer_lock);

     //check if ready to write to file
     if(bufferSize < numUsedBytes){
         std::cout << QString::number(qbuffer.currentWriteChannel()).toLocal8Bit().constData() << " ";

         //signal buffer is full + parameter with qByteArray
         emit bufferFull(qbuffer.buffer(), vector);             //signal buffer is full --> binaryReader will take action, will start reading the buffer and write it to the file within the selected directory
         qbuffer.buffer().clear();                      //empty the buffers
         qbuffer.reset();
         vector.clear();
         vector.count();
         numUsedBytes = 0;
     }
}

void BinaryWriter::readBuffer(){

}
