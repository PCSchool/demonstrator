#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <QObject>
#include <QDir>
#include <globals.h>
#include <QVector>;

class Analysis
{
public:
    Analysis();

public:
    void setRecordingDir(QDir dir);
    void setRecordingFilePath(QString filepath);
    QDir getRecordingDir();
    QString getRecordingFilePath();
    void addPointerList(TimePointer pointer);
    QList<TimePointer> getPointerList();
    void clearPointerList();
    QVector<double> getXaxis();
    QVector<double> getYaxis();
    void addToVector(double x, double y);
    void addRecordingDirList(QString path);
    QList<QString> getRecordingList();
    QVector<TimePointer> readFile(QString path);
    QVector<TimePointer> readDir(QString path);
    
    //for signal processing
    QVector<double> splitXY(QVector<TimePointer> points, bool xAxis);
    QVector<TimePointer> castToLowPass(QVector<TimePointer> points);
    double simpleLowPass(double *x, double *y, int M, double xm1);

    QVector<TimePointer> castToHighPass(QVector<TimePointer> points);
    QVector<TimePointer> castToBandPass(QVector<TimePointer> points);
    QVector<TimePointer> castToBandStop(QVector<TimePointer> points);

private:
    QDir recordingDir;
    QString recordingFilePath;
    QFile recordingFile;
    QList<TimePointer> pointerList;
    QVector<double> Xaxis, yaxis;
    QList<QString> recordingPathList;

};

#endif // ANALYSIS_H
