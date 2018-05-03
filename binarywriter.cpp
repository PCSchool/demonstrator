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

BinaryWriter::BinaryWriter()
{
    numberFile = 0;
    dataSize = 1000;
    bufferSize = 1024;
    numUsedBytes = 1;
    QByteArray* array = new QByteArray[bufferSize];
    qbuffer.setBuffer(array);
}


void BinaryWriter::setUserDir(QDir dir){
    //should be used for binarywriter as directory where the file should be stored
    this->dir = dir;
    std::cout << dir.path().toLocal8Bit().constData();
}

//fill the buffer
void BinaryWriter::writeData(double xAxis, double yAxis){
     struct Data{
         double x, y;
     } data;
     data.x = xAxis;
     data.y = yAxis;

     //'lock' thread
     EnterCriticalSection(&shared_buffer_lock);
     qbuffer.buffer().prepend(reinterpret_cast<char *>(&data));
     qbuffer.open(QIODevice::ReadWrite | QIODevice::Truncate );
     qbuffer.write(reinterpret_cast<char *>(&data), std::ios_base::app | std::ios::binary);
     qbuffer.close();

     emit qbuffer.readyRead();  //always emit readyRead() when new data has arrived
     numUsedBytes++; //struct Data is 16 bytes
     LeaveCriticalSection(&shared_buffer_lock);

     //std::cout << sizeof(qbuffer) << " : ";

     if(bufferSize <= sizeof(qbuffer)){
         //signal buffer is full + parameter with qByteArray
         //bufferIsFull.wakeAll();
         std::cout << "signal BinaryWriter -> endl";

         //bufferIsFull.wait(&mutex);
         emit bufferFull(qbuffer.buffer());             //signal buffer is full --> binaryReader will take action, will start reading the buffer and write it to the file within the selected directory
         qbuffer.buffer().clear();                      //empty the buffers
         //bufferDoneWriteFile.wait(&mutex);
     }
}

void BinaryWriter::writeToFile(){
    bufferDoneWriteFile.wait(&mutex);

    //write buffer to file
    std::cout << "BinaryWriter::writeToFile() -> ";

    bufferIsFull.wakeAll();
}
