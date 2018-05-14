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
    void setRecordingFile(QFile file);
    QDir getRecordingDir();
    QFile getRecordingFile();

private:
    QDir recordingDir;
    QFile recordingFile;

signals:

};

#endif // ANALYSIS_H
