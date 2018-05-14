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
void Analysis::setRecordingFile(QFile file){
    this->recordingFile = file;
}
QFile Analysis::getRecordingFile(){
    return recordingFile;
}
