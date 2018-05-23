#include "binaryreader.h"
#include <QFile>
#include <iostream>
#include <fstream>
#include <ostream>
#include <streambuf>
#include <QDataStream>
#include <QtDebug>
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
#include <condition_variable>
#include <globals.h>
#include <windows.h>
#include <recorddialog.h>
#include <QVector>

using namespace std;

BinaryReader::BinaryReader()
{
    numberFile = 0;
    dataSize = 1024;
    bufferSize = 1024;
    numUsedBytes = 1;
    QByteArray* array = new QByteArray[bufferSize];
    qbuffer.setBuffer(array);
}

void BinaryReader::setUserDir(QDir dir){
    //should be used for binarywriter as directory where the file should be stored
    this->dir = dir;
}

//write buffer to binary file
void BinaryReader::writeBufferToFile(QByteArray array, QVector<TimePointer> vector){

    std::string path = dir.path().toLocal8Bit().constData();
    path = path + "/recording_" + std::to_string(numberFile) + ".bin";

    EnterCriticalSection(&shared_buffer_lock);
    QFile file("recordFinal.bin");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_10);
    out.setByteOrder(QDataStream::LittleEndian);

    for(int i = 0; i < vector.count(); ++i){
        out << (double)vector[i].x;
        out << (double)vector[i].y;

        //std::cout << vector[i].x << " == " << vector[i].y << "  " << endl;
     }
    file.close();
    LeaveCriticalSection(&shared_buffer_lock);
}
