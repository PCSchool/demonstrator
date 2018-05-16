#ifndef GLOBALS_H
#define GLOBALS_H

#include <QSemaphore>

const int DataSize = 100000;
const int BufferSize = 1024;
extern char buffer[BufferSize];

extern struct Data{
    double x, y;
} data;

extern struct TimePointer{
    double x, y;
} pointer;


#endif // GLOBALS_H
