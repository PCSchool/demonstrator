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
void BinaryReader::writeBufferToFile(QByteArray array){
    std::cout << "BinaryReader : writeBufferToFile " << endl;
    /*
    if(numUsedBytes == 0){
        bufferIsFull.wait(&mutex);      //wait for buffer to be full
    }
    /*/

    std::string path = dir.path().toLocal8Bit().constData();
    path = path + "/recording_" + std::to_string(numberFile) + ".bin";

    //bufferIsFull.wait(&mutex);
    //write buffer to file
    std::cout << "BinaryWriter::writeToFile() -> ";

    EnterCriticalSection(&shared_buffer_lock);
    //mutex.lock();
    //readWriteLocker->lockForRead();  // write new data to buffer, the buffer gets modified, due to this it is important to lock the buffer

    std::ofstream fout(path, std::ios::binary | std::ios_base::app);
    fout.write(reinterpret_cast<char *>(&array), sizeof(array));
    fout.close();

    // the writing from buffer to file is done, set the new conditions up and unlock
    --numUsedBytes;
    //bufferDoneWriteFile.wakeAll();

    LeaveCriticalSection(&shared_buffer_lock);

    //bufferDoneWriteFile.wakeAll();
}
