#include "recording.h"
#include <stdexcept>
#include <qcustomplot.h>

//default constructor;
Recording::Recording()
{

}

//constructor with parameters
Recording::Recording(int width, int height, int x, int y){
    if(width < 0 || height < 0 || x < 0 || y < 0 ){
        //throw exception
    }
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
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

void Recording::changePosition(int x, int y){
    this->x = x;
    this->y = y;
}

void Recording::changeSize(int width, int height){
    size.setHeight(height);
    size.setWidth(width);
}

void Recording::setProperties(double frequency, double amplitude, int yAxisMax, int yAxisMin, int xAxisMax, int xAxisMin, int interval, QString graph, QString sensor){
    this->frequency = frequency;
    this->amplitude = amplitude;
    this->yAxisMax = yAxisMax;
    this->yAxisMin = yAxisMin;
    this->xAxisMax = xAxisMax;
    this->xAxisMin = xAxisMin;
    this->interval = interval;
    this->sensorString = sensor;
    this->typeString = graph;
    this->sensor = selectSensor(sensor.toLocal8Bit().constData());
    this->type = selectTypes(graph.toLocal8Bit().constData());
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

int Recording::getYAxisMax(){
    return this->yAxisMax;
}

int Recording::getYAxisMin(){
    return this->yAxisMin;
}

int Recording::getXAxisMax(){
    return this->xAxisMax;
}

int Recording::getXAxisMin(){
    return this->xAxisMin;
}

QString Recording::getGraphType(){
    return this->typeString;
}

QString Recording::getSensor(){
    return this->sensorString;
}

int Recording::getInterval(){
    return this->interval;
}

