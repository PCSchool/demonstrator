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
#include <globals.h>
<<<<<<< HEAD
=======
#include <vector>
>>>>>>> 99352342c844220d4eb6fb8227db9ae0e0da1aab

class BinaryWriter : public QObject
{
    Q_OBJECT
public:
    BinaryWriter();  //default constructor, set up values for most attributes

    void convertDoubleToBinary(double d);       //convertDoubleToBinary
    void setUserDir(QDir dir);                  //set directory where the recording files will be stored

    QBuffer qbuffer;
    QArrayData tester;                          //test QArrayData
    int numberFile;                             //default 0
    std::vector<Data> vectorData;

signals:
    void start();                               //start thread
    void finished();                            //finishes thread
    void error(QString error);                  //debugging error, to show whats wrong
    void writeNewBufferToFile();                //ready for new buffer to be written
    void fileFull();
    void bufferFull(QByteArray array, vector vectorData);
    void setDir(QDir dir);

public slots:
    //add new data to buffer
    void writeData(double xAxis, double yAxis);
<<<<<<< HEAD
    void readBuffer();
=======
    void writeToFile();
    void testRead();
>>>>>>> 99352342c844220d4eb6fb8227db9ae0e0da1aab

private slots:

private:
    QByteArray qarray;
    QByteArray byteArray;
    QDir dir;                                   //directory used
    int numUsedBytes;
    int dataSize;
    int bufferSize;
};

#endif // BINARYWRITER_H
