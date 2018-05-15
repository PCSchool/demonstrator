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

    std::string path = dir.path().toLocal8Bit().constData();
    path = path + "/recording_" + std::to_string(numberFile) + ".bin";

    size_t sizeData = sizeof(TimePointer);
    size_t sizeArray = sizeof(array);

    EnterCriticalSection(&shared_buffer_lock);

    //convert QByteArray to Vector and write each row within vector to file
    //must write the content of vector itself &vector[0]

    QVector<TimePointer> vector;
    //BYTE * pByte = reinterpret_cast<byte*>(array.data());

    // 1. recording_1.bin  QDataStream    // save the QFile directoy??
    QFile file("recording_1.bin");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_10);
    out.setByteOrder(QDataStream::LittleEndian);
    out.writeRawData(array.constData(), array.length());
    //out.writeRawData(array.constData(), array.length());
    file.close();

    // 2. recording_2.bin  std::ofstream
    std::ofstream fout("recording_2.bin", std::ios::binary | std::ios_base::app);
    fout.write(reinterpret_cast<char *>(array.data()), sizeof(array) *array.size());
    fout.close();

    //ofstream fout2("recording_1.bin", std::ios_base::app | ios::binary);
    //fout2.write(array.data(), array.size() * sizeof(TimePointer));
    //std::cout << " array size " << array.data();
    //fout2.close();

    // 3. recording_3.bin  FILE
    //FILE *file = fopen("recording_x", "wb");
    //pass argument by const reference
    //for (const auto& value : vector){
    //    fwrite(value, sizeof(TimePointer), sizeData, file);
    //}
    //fclose(file);

    /*FILE *file = fopen("recording__0.bin", "wb");
    for(int i = 0; i < array.sizeData(); i++){
        fwrite(array[i], sizeof(data), 16, file);
    }
    fclose(file);*/

    LeaveCriticalSection(&shared_buffer_lock);
}
