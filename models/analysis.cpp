#include "analysis.h"

//constructor
Analysis::Analysis()
{

}

//methods
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
    recordingFilePath;
}
