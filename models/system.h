#ifndef SYSTEM_H
#define SYSTEM_H

#include <QObject>
#include <models/patient.h>
#include <models/device.h>
#include <models/user.h>
#include <vector>

class System
{
public:
    //constructor
    System();
    Patient *selectedPatient;

    //methods
    bool hasPatient();  //returns true if a patient is selected, false otherwise
    bool hasDevice();   //return true if a device is selected, false otherwise
    bool hasDir();      //return true if a directory is selected, false otherwise

    void addDevice(Device device);
    QLinkedList<Device> getDevices();
    void removeDevice(Device device);

    //getters / setters for properties
    QDir getDir();
    void setDir(QString path);
    Patient* getPatient();
    void setPatient(Patient* patient);
    Device getSelectedDevice();
    void setSelectedDevice(const Device device);
    QDir getPatientDir();
    void setPatientDir(QDir dir);
    //static methods
    // 1. createDirectory(const QString path)
    // 2. createFile(const QString path, QString namefile)
    // ** return true if creating directory/file has succesfully been created
    // *** return false if creating directory/file failed or file/directory already existed
    static bool createDirectory(const QString path, QString namedirectory);
    static bool createFile(const QString path, QString namefile);

public slots:

signals:

private:
    //fields
    QDir dir;  // base directory of the sleep signal demonstrator
    QDir patientDir;
    User user;
    QLinkedList<Device> devices;
    Device selectedDevice;
};

#endif // SYSTEM_H
