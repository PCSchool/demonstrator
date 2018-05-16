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
<<<<<<< HEAD
#include <globals.h>
=======

using namespace std;
>>>>>>> 99352342c844220d4eb6fb8227db9ae0e0da1aab

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
     TimePointer data;
     data.x = xAxis;
     data.y = yAxis;
     //std::cout << data.x << " " << data.y << " ";
     numberFile++;
     // std::cout << numberFile << " - ";
     //write new data to buffer
     struct Data{
         double x, y;
     } data;
     data.x = xAxis;
     data.y = yAxis;

     EnterCriticalSection(&shared_buffer_lock);
<<<<<<< HEAD
     //qbuffer.buffer().resize(sizeof(&data));
     qbuffer.buffer().append(reinterpret_cast<char *>(&data));  //prepend
     qbuffer.open(QIODevice::ReadWrite | QIODevice::Truncate );
     qbuffer.write(reinterpret_cast<char *>(&data), std::ios_base::app | std::ios::binary);
     char *empt = reinterpret_cast<char *>(&data);

     std::cout <<"|" << empt << " " << data.x << " " << data.y << " -- ";
     memcpy(&data, empt, sizeof(TimePointer));
     std::cout << " " << data.x << " " << data.y << " | \n";
=======
     vectorData.push_back(data);
     qbuffer.buffer().resize(sizeof(&data));
     qbuffer.buffer().prepend(reinterpret_cast<char*>(&data));
     qbuffer.open(QIODevice::ReadWrite | QIODevice::Truncate );
     qbuffer.write(reinterpret_cast<char *>(&data), std::ios::binary);
>>>>>>> 99352342c844220d4eb6fb8227db9ae0e0da1aab
     qbuffer.close();
     emit qbuffer.readyRead();  //always emit readyRead() when new data has arrived
     numUsedBytes = numUsedBytes + 16; //struct TimePointer is 16 bytes
     LeaveCriticalSection(&shared_buffer_lock);

<<<<<<< HEAD
     //check if ready to write to file
=======
>>>>>>> 99352342c844220d4eb6fb8227db9ae0e0da1aab
     if(bufferSize < numUsedBytes){
         std::cout << QString::number(qbuffer.currentWriteChannel()).toLocal8Bit().constData() << " ";

         //signal buffer is full + parameter with qByteArray
<<<<<<< HEAD
         emit bufferFull(qbuffer.buffer());             //signal buffer is full --> binaryReader will take action, will start reading the buffer and write it to the file within the selected directory
         std::cout << "\n emit signal " << numberFile << " ";
         qbuffer.buffer().clear();
         //empty the buffers
=======
         std::cout << "signal BinaryWriter" << endl;
         emit bufferFull(qbuffer.buffer(), vectorData);             //signal buffer is full --> binaryReader will take action, will start reading the buffer and write it to the file within the selected directory
         qbuffer.buffer().clear();                      //empty the buffers
>>>>>>> 99352342c844220d4eb6fb8227db9ae0e0da1aab
         numUsedBytes = 0;
     }
}

void BinaryWriter::readBuffer(){

}
