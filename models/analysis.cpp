#include "analysis.h"
#include <globals.h>

//constructor
Analysis::Analysis()
{

}

//methods
void Analysis::addPointerList(TimePointer pointer){
    pointerList.push_back(pointer);
}

QList<TimePointer> Analysis::getPointerList(){
    return pointerList;
}

void Analysis::clearPointerList(){
    pointerList.clear();
}

QVector<double> Analysis::getXaxis(){
    return this->Xaxis;
}

QVector<double> Analysis::getYaxis(){
    return this->yaxis;
}

void Analysis::addToVector(double x, double y){
     Xaxis.push_back(x);
     yaxis.push_back(y);
}

void Analysis::setRecordingDir(QDir dir){
    this->recordingDir = dir;
}

QDir Analysis::getRecordingDir(){
    return this->recordingDir;
}

void Analysis::setRecordingFilePath(QString filepath){
    recordingFilePath = filepath;
    recordingFile.setFileName(filepath);
}

QString Analysis::getRecordingFilePath(){
    return recordingFilePath;
}

