#ifndef BINARYWRITER_H
#define BINARYWRITER_H

#include <QObject>
#include <QFile>
#include <QWaitCondition>
#include <QMutex>
#include <condition_variable>
#include <QBuffer>
#include <QDir>
#include <QReadWriteLock>
#include <windows.h>

class BinaryWriter : public QObject
{
    Q_OBJECT
public:
    BinaryWriter();  //default constructor, set up values for most attributes

    void convertDoubleToBinary(double d);       //convertDoubleToBinary
    void setUserDir(QDir dir);                  //set directory where the recording files will be stored

    //thread synchronization
    QWaitCondition bufferIsFull;                //true if buffer is full and ready to be written to file, false is buffer still is getting filled
    QWaitCondition bufferDoneWriteFile;         //true when the buffer is done being written into the file, false when the buffer still aint completely written to the file
    QWaitCondition bufferNotEmpty;
    QMutex mutex;                               //QMutex mutex, can be used to lock or unlock certain parts of threads

    QArrayData tester;                          //test QArrayData
    int numberFile;                             //default 0
signals:
    void start();                               //start thread
    void finished();                            //finishes thread
    void error(QString error);                  //debugging error, to show whats wrong
    void writeNewBufferToFile();                //ready for new buffer to be written
    void fileFull();
    void bufferFull(QByteArray array);
    void setDir(QDir dir);

public slots:
    //add new data to buffer
    void writeData(double newdata, double key);
    void writeToFile();

private slots:

private:
    QMutexLocker* mutexLocker;                   //QMutexLocker mutexLocker, can be used to lock or unlock certain
    QReadWriteLock* readWriteLock;              //QReadWriteLock readWriteLock, can be used to lock for read, writing purposes
    //QFile file;                                 //QFile file, used
    QBuffer qbuffer;
    QByteArray qarray;
    QByteArray byteArray;
    QDir dir;                                   //directory used
    int numUsedBytes;
    int dataSize;
    int bufferSize;
};

#endif // BINARYWRITER_H
