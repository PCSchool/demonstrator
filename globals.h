#ifndef GLOBALS_H
#define GLOBALS_H

#include <QSemaphore>

const int DataSize = 100000;
const int BufferSize = 1024;

extern struct TimePointer{
    double x, y;
} pointer;

extern char buffer[BufferSize];

#endif // GLOBALS_H
