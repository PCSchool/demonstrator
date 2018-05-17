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
     //std::cout << data.x << " " << data.y << " ";
     numberFile++;
     // std::cout << numberFile << " - ";
     //write new data to buffer
     data.x = xAxis;
     data.y = yAxis;

     EnterCriticalSection(&shared_buffer_lock);
     qbuffer.buffer().resize(sizeof(&data));
     //qbuffer.buffer().prepend(reinterpret_cast<char*>(&data));
     qbuffer.open(QIODevice::ReadWrite | QIODevice::Truncate );
     qbuffer.write(reinterpret_cast<char *>(&data), std::ios_base::app | std::ios::binary);

     //std::cout <<"|" << data.x << " " << data.y << " -> " << empt  << " <- ";
     //memcpy(&data, empt, sizeof(TimePointer));
     //std::cout << " " << data.x << " " << data.y << " | \n";

     qbuffer.close();
     emit qbuffer.readyRead();  //always emit readyRead() when new data has arrived
     numUsedBytes = numUsedBytes + 16; //struct TimePointer is 16 bytes
     LeaveCriticalSection(&shared_buffer_lock);

     //check if ready to write to file
     if(bufferSize < numUsedBytes){
         std::cout << QString::number(qbuffer.currentWriteChannel()).toLocal8Bit().constData() << " ";

         //signal buffer is full + parameter with qByteArray
         emit bufferFull(qbuffer.buffer());             //signal buffer is full --> binaryReader will take action, will start reading the buffer and write it to the file within the selected directory
         qbuffer.buffer().clear();                      //empty the buffers
         numUsedBytes = 0;
     }
}

void BinaryWriter::readBuffer(){

}
