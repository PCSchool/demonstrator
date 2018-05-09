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

//for writing the right structure to a stream
/*std::ostream& operator << (std::ostream& os, const QBuffer &qbuffer){
    std::size_t buffer_bytes_size = qbuffer.size();

    os.write(&qbuffer)
}*/

//write buffer to binary file
void BinaryReader::writeBufferToFile(QByteArray array){
    struct Data{
        double x, y;
    } data;

    std::string path = dir.path().toLocal8Bit().constData();
    path = path + "/recording_" + std::to_string(numberFile) + ".bin";

    EnterCriticalSection(&shared_buffer_lock);

    //option 1. write whole QByteArray to file
    //std::ofstream fout(path, std::ios::binary | std::ios_base::app);
    //fout.write(reinterpret_cast<char *>(&array), sizeof(array));
    //fout.close();

    QByteArray qq;
    BYTE * pByte = reinterpret_cast<byte*>(array.data());
    std::cout <<pByte;

    //option 2.
    //QByteArray, to write data correctly to data write each row individually
    //FILE *file = fopen("recording__0.bin", "wb");
    //for(int i = 0; i < array.size(); i++){
        //fwrite(array[i], sizeof(data), 16, file);
    //}
    //fclose(file);

    //option 3.
    //std::size_t entry_size = array.size();
    //out.write(reinterpret_cast<const char*>(&entry_size), sizeof(entry_size));
    //for(int i = 0; i < array.size(); i++){
        //out.write(reinterpret_cast<const char*>(&array[i]), sizeof(16));
    //}

    //fout.close();

    // the writing from buffer to file is done, set the new conditions up and unlock
    //bufferDoneWriteFile.wakeAll();

    LeaveCriticalSection(&shared_buffer_lock);

    //bufferDoneWriteFile.wakeAll();
}
