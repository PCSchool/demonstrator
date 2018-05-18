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

//for writing the right structure to a stream
/*std::ostream& operator << (std::ostream& os, const QBuffer &qbuffer){
    std::size_t buffer_bytes_size = qbuffer.size();

    os.write(&qbuffer)
}*/

//write buffer to binary file
void BinaryReader::writeBufferToFile(QByteArray array, QVector<TimePointer> vector){

    std::string path = dir.path().toLocal8Bit().constData();
    path = path + "/recording_" + std::to_string(numberFile) + ".bin";

    size_t sizeData = sizeof(TimePointer);
    size_t sizeArray = sizeof(array);

    EnterCriticalSection(&shared_buffer_lock);

    //convert QByteArray to Vector and write each row within vector to file
    //must write the content of vector itself &vector[0]

    //BYTE * pByte = reinterpret_cast<byte*>(array.data());


    /*1. recording_1.bin  QDataStream    // save the QFile directoy??
    QFile file("recording_1.bin");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_10);
    out.setByteOrder(QDataStream::LittleEndian);
    std::cout << array.size() << "??";
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

    //void BinaryReader::writeBufferToFile(QByteArray array, vector vectorData){
    //std::string path = dir.path().toLocal8Bit().constData();
    //path = path + "/recording_" + std::to_string(numberFile) + ".bin";

    //option 1. write whole QByteArray to file
    //std::ofstream fout(path, std::ios::binary | std::ios_base::app);
    //fout.write(reinterpret_cast<char *>(&array), sizeof(array));
    //fout.close();

    //QFile f("recording_4.bin");   //<-- change later on to path
    //f.setFileName("recording_4.bin");
    //if(!f.open(QIODevice::WriteOnly)) return;

    //BYTE * pByte = reinterpret_cast<byte*>(array.data();

    //QByteArray arrayNew = array.chopped(16);
    //TimePointer* d = reinterpret_cast<TimePointer*>(arrayNew.data());
    //std::cout << "coordinates Data{x = "<< d->x << ", y = " << d->y << "} \n" ;

    QFile file("recording_1.bin");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_10);
    out.setByteOrder(QDataStream::LittleEndian);

    for(int i = 0; i < vector.count(); ++i){
        out << (quint64)vector[i].x;
        out << (quint64)vector[i].y;
    }
    file.close();
    LeaveCriticalSection(&shared_buffer_lock);

    //for(auto i : vectorData){
    //    std::cout << "VectorData: " << i << endl;
    //}

    /*QDataStream dataStream(&f);
    dataStream.setByteOrder(QDataStream::LittleEndian);
    while(!dataStream.atEnd()){

        //dataStream << x;
        result.push_back(x);
        f.write(reinterpret_cast<char*>(&x), sizeof(Data));
    }
    f.close();*?

    FILE *file = fopen("recording__0.bin", "wb");
    for(int i = 0; i < array.size(); i++){
        fwrite(array[i], sizeof(data), 16, file);
    }
    fclose(file);

    //std::size_t entry_size = array.size();
    //out.write(reinterpret_cast<const char*>(&entry_size), sizeof(entry_size));
    //for(int i = 0; i < array.size(); i++){
        //out.write(reinterpret_cast<const char*>(&array[i]), sizeof(16));
    //}

    //fout.close();

    // the writing from buffer to file is done, set the new conditions up and unlock
    //bufferDoneWriteFile.wakeAll();

    LeaveCriticalSection(&shared_buffer_lock);

    //bufferDoneWriteFile.wakeAll();*/
}
