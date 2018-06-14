#include "device.h"
#include <QStandardPaths>
#include <globals.h>
#include <models/system.h>

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

