#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <QObject>
#include <QDir>
#include <globals.h>

class Analysis
{
public:
    Analysis();

public:


    void setRecordingDir(QDir dir);
    void setRecordingFilePath(QString filepath);
    QDir getRecordingDir();
    QString getRecordingFilePath();

private:
    QDir recordingDir;
    QString recordingFilePath;
    QFile recordingFile;

signals:

};

#endif // ANALYSIS_H
