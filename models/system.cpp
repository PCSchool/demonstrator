#include "system.h"
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <stdlib.h>
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
        makedir.mkpath(path+ "/devices");
        makedir.mkpath(path + "/patients");
    }
    this->setDir(path);
    this->setPatientDir(QDir(path + "/patients/"));

}

//methods
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

//dynamically linke crypt32.dll --> doing this using Win32 API functions LoadLibrary + GetProcAddress
void System::loadCrypt32(){
    HINSTANCE hinstLib;
    MYPROC procAdd;
    BOOL fFreeResult, fRunTimeLinkSucces = FALSE;
    //C:\Users\Onera\Documents\SignalSleepDemonstrator
    hinstLib = LoadLibrary(TEXT("crypt32.dll"));
    if (hinstLib != NULL){
        procAdd = (MYPROC) GetProcAddress(hinstLib, "crypt32.dll");

        if(procAdd != NULL){
            fRunTimeLinkSucces = TRUE;
            (procAdd) (L"Message sent to the DLL function\n");
        }

        fFreeResult = FreeLibrary(hinstLib);

    }

    if(! fRunTimeLinkSucces)
        printf("Message printed from executable\n");

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
    hasDir = true;
}

Patient* System::getPatient(){
    return selectedPatient;
}
void System::setPatient(Patient* patient){
    selectedPatient = patient;
    hasPatient = true;
}

Device System::getSelectedDevice(){
    return selectedDevice;
}

void System::setSelectedDevice(Device device){
    selectedDevice = device;
    hasDevice = true;
}

