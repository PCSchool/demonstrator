#include "device.h"
#include <QStandardPaths>
#include <globals.h>
#include <exceptions/exceptioninvalidparameters.h>

Device::Device()
{

}

//constructor with parameters
Device::Device(QString name, QString location){
    if(name.isEmpty() || location.isEmpty()){throw ExceptionInvalidParameters();}
    this->name = name;
    this->path = location;
    this->dir.setPath(location);
    this->active = false;

    QDir dir(QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + pathDevices + name)); //QString::number(id)

    dir.mkpath(QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + pathDevices + name));
}

bool Device::validationCheckExists(QString path){
    if(path.isEmpty()){ throw ExceptionInvalidParameters(); }
    if(QDir(QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + pathDevices + path)).exists()){
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
