#include "system.h"
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <stdlib.h>
#include <globals.h>
#include <exceptions/exceptioninvalidparameters.h>
#include <mainwindow.h>

typedef int (__cdecl *MYPROC)(LPWSTR);
using namespace std;

System::System()
{
    hasDevice = false;
    hasPatient = false;
    hasDir = false;

    QString path = QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + "/SignalSleepDemonstrator");
    QDir makedir(path);
    if(!makedir.exists()){
        makedir.mkpath(path); 
        makedir.mkpath(path+ "/devices/");
        makedir.mkpath(path + "/patients/");
    }
    this->setDir(path);
    this->setPatientDir(QDir(path + "/patients/"));
    hasDir = true;

    /*QList<const QMetaObject*> metaObjectList;
    metaObjectList << &TimePointer::staticMetaObject;

    QMap<QString, const QMetaObject*> metaObjectLookup;
    foreach(const QMetaObject *mo, metaObjectList){
        metaObjectLookup.insert(mo->className(), mo);
    }
    qRegisterMetaType<TimePointer>("TimePointer");*/
}

//static methods
bool System::createDirectory(QString path){
    if(!checkDirectoryExists(path)){
        QDir thisDir = QDir(path);
        thisDir.mkdir(path);
        return true;
    }
    return false;
}

bool System::checkDirectoryExists(QString path){
    QDir thisDir = QDir(path);
    if(thisDir.exists()){
       return true;
    }
    return false;
}

QString System::getHomeLocation(){
    return QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + pathHome);
}

QString System::getPatientLocation(){
    return QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + pathPatient);
}

QString System::getDeviceLocation(){
    return QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + pathDevices);
}

//methods
void System::addDevice(Device device){
    devices << device;
}

void System::removeDevice(Device device){
    QLinkedList<Device>::iterator i;
    for(i = devices.begin(); i != devices.end(); i++){
        if((*i).getName() == device.getName()){
            i = devices.erase(i);
        }
    }
}

QLinkedList<Device> System::getDevices(){
    return this->devices;
}

//getters / setters voor properties
void System::setPatientDir(QDir dir){
    if(dir.path().isEmpty()){ throw ExceptionInvalidParameters();}
    this->patientDir  = dir;
}

QDir System::getPatientDir(){
    return this->patientDir;
}

QDir System::getDir(){
    return dir;
}
void System::setDir(const QString path){
    if(path.isEmpty()){throw ExceptionInvalidParameters();}
    this->dir.setPath(path);
    hasDir = true;
}

Patient* System::getPatient(){
    return selectedPatient;
}
void System::setPatient(Patient* patient){
    if(patient->getEmail().isEmpty()){throw ExceptionInvalidParameters();}
    selectedPatient = patient;
    hasPatient = true;
}

Device System::getDevice(){
    return selectedDevice;
}

void System::setDevice(Device device){
    selectedDevice = device;
    hasDevice = true;
}

void System::removePatient(QString path){
    QDir removeDir(path);
    if(hasPatient){
        if(selectedPatient->userDir.path() != path){
            removeDir.removeRecursively();
        }
    }else{
        removeDir.removeRecursively();
    }
}
