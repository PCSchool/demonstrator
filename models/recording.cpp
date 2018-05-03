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

Recording::Types Recording::getType(){
    return type;
}


void Recording::setType(QString type){
    this->type = selectTypes(type.toLocal8Bit().constData());
}

Recording::Types Recording::selectTypes(std::string _s){
    transform(_s.begin(), _s.end(), _s.begin(), toupper);
    if(_s == "LINE") return line;
    else if(_s == "BAR") return bar;
    else if(_s == "HISTOGRAM") return histogram;
    else if(_s == "SCATTER") return scatter;
    throw std::range_error("Not a valid Types value: " + _s);
    return invalidtype;
}

Recording::Sensors Recording::selectSensor(std::string _s){
    transform(_s.begin(), _s.end(), _s.begin(), toupper);
    if(_s == "HEARTRATE") return heartrate;
    else if(_s == "ACCELEROMETER") return accelerometer;
    else if(_s == "MICROPHONE") return microphone;
    else if(_s == "SKINTEMPERATURE") return skintemperature;
    else if(_s == "LIGHTSENSOR") return lightsensor;
    return invalidsensor;
}

QString Recording::getPauze(){
    return this->pauze;
}

//getters / setters for properties
void Recording::setPauze(QString text){
    this->pauze = text;
}

Recording::Sensors Recording::getSensors(){
    return sensor;
}

void Recording::setSensors(QString sensors){
    this->sensor = selectSensor(sensors.toLocal8Bit().constData());
}

QCustomPlot* Recording::getPlot(){
    return plot;
}

QSize Recording::getSize(){
    return size;
}
void Recording::setSize(QSize size){
    this->size = size;
}

double Recording::getAmplitude(){
    return amplitude;
}
void Recording::setAmplitude(double amplitude){
    this->amplitude = amplitude;
}

double Recording::getFrequency(){
    return frequency;
}
void Recording::setFrequency(double frequency){
    this->frequency = frequency;
}
