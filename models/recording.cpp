#include "recording.h"
#include <stdexcept>
#include <qcustomplot.h>

//default constructor;
Recording::Recording()
{
    xPosLayout = 0;
    yPosLayout = 0;
}

//constructor with parameters
Recording::Recording(QCustomPlot *plot, double frequency, double amplitude, QString type, QString sensor){
    this->plot = plot;
    this->frequency = frequency;
    this->amplitude = amplitude;
    this->type = selectTypes(type.toLocal8Bit().constData());
    this->sensor = selectSensor(sensor.toLocal8Bit().constData());
}

//methods
QString Recording::controlDir(QDir dir){
    //create new directory for new recording
    // directory name contains of recording_date_time
    // - date being the current date
    // - time being the current time of creating the recording
    QString date = QDateTime::currentDateTime().toString("dd-MM-yyyy");
    QString time = QDateTime::currentDateTime().toString("hh-mm-ss");
    QString path = "recording_" + date + "_" + time;
    QString fullPath = dir.path() + "/" + path;
    if(!QDir(path).exists()){
        dir.mkdir(path);
    }

    pathRecording = fullPath;
    return fullPath;
}

void Recording::changePosition(double x, double y){
    this->xPosLayout = x;
    this->yPosLayout = y;
}

void Recording::changeSize(int width, int height){
    size.setHeight(height);
    size.setWidth(width);
}

void Recording::addRecording(QCustomPlot *plot, double frequency, double amplitude, QString type, QString sensor, int duration){
    this->plot = plot;
    this->frequency = frequency;
    this->amplitude = amplitude;
    this->type = selectTypes(type.toLocal8Bit().constData());
    this->sensor = selectSensor(sensor.toLocal8Bit().constData());
    this->duration = duration;
}

Recording::Types Recording::selectTypes(std::string _s){
    transform(_s.begin(), _s.end(), _s.begin(), ::toupper);
    if(_s == "LINE") return line;
    else if(_s == "BAR") return bar;
    else if(_s == "HISTOGRAM") return histogram;
    else if(_s == "SCATTER") return scatter;
    throw std::range_error("Not a valid Types value: " + _s);
    return invalidtype;
}

Recording::Sensors Recording::selectSensor(std::string _s){
    transform(_s.begin(), _s.end(), _s.begin(), ::toupper);
    if(_s == "HEARTRATE") return heartrate;
    else if(_s == "ACCELEROMETER") return accelerometer;
    else if(_s == "MICROPHONE") return microphone;
    else if(_s == "SKINTEMPERATURE") return skintemperature;
    else if(_s == "LIGHTSENSOR") return lightsensor;
    return invalidsensor;
}


