#include "device.h"
#include <QStandardPaths>
#include <globals.h>
#include <models/system.h>
#include <iostream>
#include <fstream>
#include <string>

//default constructor
Device::Device()
{
}

//constructor with parameters
Device::Device(QString name, QString location){
    this->name = name;
    this->path = location;
    this->dir.setPath(location);
    this->active = false;

    QDir dir(QString(System::getDeviceLocation() + name));
    dir.mkpath(QString(System::getDeviceLocation() + name));

    QString path = QString(System::getDeviceLocation() + name + pathPatientNotesDefault);

    std::ofstream fout(path.toLocal8Bit().constData(), std::ios::out);
    fout << location.toLocal8Bit().constData() << endl;
    fout.close();
}

bool Device::validationCheckExists(QString path){
    if(System::checkDirectoryExists(path)){
        return true;
    }
    return false;
}

//methods

//getters / setters for properties
void Device::setActive(bool activity){
    this->active = activity;
}

bool Device::getActive(){
    return active;
}

QString Device::getName(){
    return name;
}

QDir Device::getDir(){
    return dir;
}

