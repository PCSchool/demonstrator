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

private:
    QDir recordingDir;
    QString recordingFilePath;
    QFile recordingFile;
    QList<TimePointer> pointerList;
    QVector<double> Xaxis, yaxis;

signals:

};

#endif // ANALYSIS_H
