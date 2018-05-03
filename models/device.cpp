#include "device.h"

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

