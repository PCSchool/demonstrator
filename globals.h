#ifndef GLOBALS_H
#define GLOBALS_H

#include <QSemaphore>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <qdatastream.h>

using namespace std;

const int DataSize = 100000;
const int BufferSize = 1024;
const int readDoubleSize = 8;
const int readTimePointerSize = 16;
const int maxBinFileSize = 40000;//2000000;
extern char buffer[BufferSize];



#pragma pack(push, 1);
typedef struct TimePointer{   //extern or typedef
    double x, y;
} pointer;
#pragma pack(pop);

//write to file << outstream
inline QDataStream &operator<<(QDataStream &out,const TimePointer &tp){
    out << (quint64)tp.x;
    out << (quint64)tp.y;
    return out;
}

//read from file >> instream
inline QDataStream &operator>>(QDataStream &in,TimePointer &tp){
    //resetting the stream is required. position is at then at the start
    in.resetStatus();
    //in.device()->reset();
    tp = TimePointer();

    in >> tp.x;
    in >> tp.y;
    std::cout << tp.x << " " << tp.y << " size tp : " << sizeof(TimePointer) << endl;

    char *empt = reinterpret_cast<char *>(&tp);

    //memcpy(newcopy, original, copy sizeof(char*) into newcopy);
    memcpy(&tp, empt, sizeof(TimePointer));

    std::cout <<"|" << tp.x << " " << tp.y << " -> ";
    return in;
}

#endif // GLOBALS_H
