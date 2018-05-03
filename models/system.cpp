#include "system.h"
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <stdlib.h>
#include <mainwindow.h>

using namespace std;

System::System()
{
    QString path = QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + "/SignalSleepDemonstrator");
    QDir makedir(path);
    if(!makedir.exists()){
        makedir.mkpath(path); 
        makedir.mkpath(path+ "/devices");
        makedir.mkpath(path + "/patients");
    }
    this->setDir(path);
    this->setPatientDir(QDir(path + "/patients"));
}

//methods
//returns true if a patient is selected, false otherwise
bool System::hasPatient(){
    if(selectedPatient->getName().isEmpty()){
        return false;
    }
    return true;
}

//return true if a device is selected, false otherwise
bool System::hasDevice(){
    if(selectedDevice.getName().isEmpty()){
        return false;
    }
    return true;
}
//return true if a directory is selected, false otherwise
bool System::hasDir(){
    if(dir.path().isEmpty()){
        return false;
    }
    return true;
}

void System::addDevice(Device device){
    devices << device;
}

void System::removeDevice(Device device){
    QLinkedList<Device>::iterator i;
    for (i = devices.begin(); i != devices.end(); i++){}

}

QLinkedList<Device> System::getDevices(){
    return this->devices;
}

//create new directory
bool System::createDirectory(const QString path, QString namedirectory){
    QString newpath =  QString(path + "/" + namedirectory);
    QDir makedir(newpath);
    if(!makedir.exists()){
        makedir.mkpath(newpath);
        return true;
    }
    return false;
}

//create new file
bool System::createFile(const QString path, QString namefile){
    QString newpath = QString(path + "/" + namefile);
    QDir makedir(newpath);
    if(!makedir.exists()){
        makedir.mkpath(newpath);
        return true;
    }
    return false;
}


//getters / setters voor properties
void System::setPatientDir(QDir dir){
    this->patientDir  = dir;
}

QDir System::getPatientDir(){
    return this->patientDir;
}

QDir System::getDir(){
    return dir;
}
void System::setDir(const QString path){
    this->dir.setPath(path);
}

Patient* System::getPatient(){
    return selectedPatient;
}
void System::setPatient(Patient* patient){
    selectedPatient = patient;
}

Device System::getSelectedDevice(){
    return selectedDevice;
}

void System::setSelectedDevice(Device device){
    selectedDevice = device;
}

