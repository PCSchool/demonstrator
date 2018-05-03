#include "user.h"
#include <qcustomplot.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <QDir>
#include <QStandardPaths>

//constructor 1 default
User::User()
{
}

//constructor 2
User::User(int id, QString email){
    this->id = id;
    this->name = email;
}

//constructor 3
User::User(int id, QString email, char gender, QString street, QString housenr, QString zipcode, int homePhone, QString name, QDate date){
    this->id = id;
    this->name = name;
    this->gender = gender;
    this->street = street;
    this->housenr = housenr;
    this->zipcode = zipcode;
    this->homePhone = homePhone;
    this->email = email;
    this->date = date;
}

//getters / setters for properties
int User::getId() {
    return id;
}
QDir User::getUserDir(){
    return userDir;
}
QDir User::getRecordingDir(){
    return recordingDir;
}

QString User::getName() {
    return name;
}
char User::getGender(){
    return this->gender;
}
QString User::getStreet(){return this->street;
                         }
QString User::getHousenr(){
    return this->housenr;
}
QString User::getZipcode(){
    return this->zipcode;
}
int User::getHomePhone(){
    return this->homePhone;
}
QString User::getEmail(){
    return this->email;
}
QDate User::getBirthDate(){
    return date;
}
