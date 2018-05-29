#include "patient.h"
#include <fstream>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <models/binarypatient.h>
#include <exceptions/exceptionemptyform.h>

using namespace std;

//constructor - for new patients
Patient::Patient(bool exist, int id, QString email, char gender, QString street, QString housenr, QString zipcode, int homePhone, QString name, QDate date, double weight, double height) : User(id, email, gender, street, housenr, zipcode, homePhone, name, date){
    this->weight = weight;
    this->height = height;    
    calculateBMI(weight, height);

    //create new directory for the patient, directory can be recognised with id, since no database connect
    //check if there is already a directory with the id
    if(!exist){
        if(createDirectory()){

        }
    }else{
        QDir dir(QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + "/SignalSleepDemonstrator/patients/" + email));
        dir.mkpath(QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + "/SignalSleepDemonstrator/patients/" + email));
        QString fixpath = QString(dir.path() + "/info.dat");
        pathPersonalInfo = fixpath;
        fixpath = QString(dir.path()) + "/notes.txt";
        pathNotes = fixpath;
        this->userDir = dir;
        this->recordingDir = QString(dir.path()) + "/recordings/";
    }
}

bool Patient::validationFormCheck(QString control, controlType type){
    // 1. control if QString is not empty
    if(control.length() < 1 || control.isNull()){
        throw ExceptionEmptyForm();
    }

    // 2. control if QString contains all necessary characters
    switch (type) {
    case controlType::housenr:   //example 135a, 14b, 123c, last letter is allowed to be char
    {
        for(int i = 0; i < control.length() -1; i++){
            if(!control[i].isDigit()){
                return false;
            }
        }
        //if(control[control.length() - 1].isLetter()){
        //    return false;
        //}
        break;
    }
        break;
    case controlType::email:  //must contain @ and one or more .
    {
        QRegExp re("^([a-zA-Z0-9_-])+@([a-zA-Z0-9_-])+(.[a-zA-Z0-9_-])+");
        if(re.exactMatch(control)){
            return true;
        }else{
            return false;
        }
        break;
    }
    case controlType::names:  //only non-digit characters included _ wi
    {
        QRegExp re("[A-Za-z ]*$");
        if(!re.exactMatch(control)){    //when control doesnt match with
            return false;
        }
        break;
    }
    case controlType::number:     //only digit characters are allowed
    {
        for(int i = 0; i < control.length(); i++){
            if(!control[i].isDigit()){
                return false;
            }
        }
        break;
    }
    case controlType::phone:     //only digit characters are allowed + length = 10
    {
        if(control.length() < 10){
            return false;
        }
        for(int i = 0; i < control.length(); i++){
            if(!control[i].isDigit()){
                return false;
            }
        }
        break;
    }
    case controlType::zipcodes:     //first four digits, followed by two char
    {
        if(!control.length() == 6 && !control[0].isDigit() && !control[1].isDigit() && !control[2].isDigit()
                && !control[3].isDigit() && !control[4].isLetter() && !control[5].isLetter())
            return false;
        break;
    }
    default:
        break;
    }
    return true;
}

/*  persoon weight 90 kg and length 173 cm -> Qi de queteletiindex (in kg/m2), m massa in kg, h lengte persoon in m ==  Qi = m /h2
 *  Qi = 90 kg kg / 1.73m * 1,73m = 90/29929 ~= 30 kg/m2*/
void Patient::calculateBMI(double weight, double height){
    //formula bmi = weight(kg) / (height(cm) x height(m)
    bmi = weight / ((height/100) * (height/100));
    std::cout << bmi;
}

//methods
void Patient::writeToNote(QString addToNote){
    //each patient owns simple .txt file within patients directory
    //write to .txt file in patients directory
    time_t raw;
    time (&raw);

    ofstream file;
    file.open(pathNotes.toLocal8Bit().constData(), std::ofstream::out | std::ofstream::app);
    file << endl;
    file << ctime(&raw) << " : ";
    file << addToNote.toLocal8Bit().constData() << endl;
    file.close();
}

void Patient::changeProfile(QString newInfo, QString variable){
    //change profile information
}

//create directory must be in user due to possible changes to the id
//return true when directory already exists, return false if directory is succesfully created
bool Patient::createDirectory(){
    QString ss = "afdadsfa";

    QDir dir(QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + "/SignalSleepDemonstrator/patients/" + email)); //QString::number(id)

    //create directory for user/patient
    dir.mkpath(QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + "/SignalSleepDemonstrator/patients/" + email));//QString::number(id)));
    //create directory for recordings
    QDir dirRecordings(dir.path() + "/recordings");
    dirRecordings.mkpath(dir.path() + "/recordings");
    recordingDir.setPath(dir.path() + "/recordings");

    QString fixpath = QString(dir.path() + "/info.dat");
    pathPersonalInfo = fixpath;

    //create notes.txt
    fixpath = QString(dir.path()) + "/notes.txt";
    std::ofstream fout2(fixpath.toLocal8Bit().constData(), std::ios::out);
    fout2 << "notes: " << endl;
    fout2.close();

    pathNotes = fixpath;
    this->userDir = dir;

    return false; //path doesnt exist
}

bool Patient::writeProfileToBinary(){
    BinaryPatient one;
    one.id = id;
    one.gender = gender;
    strcpy(one.name, name.toLocal8Bit().constData());
    strcpy(one.email, email.toLocal8Bit().constData());
    strcpy(one.street, street.toLocal8Bit().constData());
    strcpy(one.housenr, housenr.toLocal8Bit().constData());
    strcpy(one.zipcode, zipcode.toLocal8Bit().constData());
    strcpy(one.birthDate, date.toString("dd/MM/yyyy").toLocal8Bit().constData());
    one.weight = weight;
    one.height = height;

    std::string path = pathPersonalInfo.toLocal8Bit().constData();
    std::ofstream ofs(path.c_str(), ios::binary);
    ofs.write((char *)&one, sizeof(one));
    ofs.close();
}

//getters / setters properties
QString Patient::getPathNotes(){
    return this->pathNotes;
}

QString Patient::getPathPersonalInfo(){
    return this->pathPersonalInfo;
}

bool Patient::getPresent(){
    return present;
}
void Patient::setPresent(bool present){
    this->present = present;
}

double Patient::getBMI(){
    return this->bmi;
}

double Patient::getWeight(){
    return this->weight;
}

double Patient::getHeight(){
    return this->height;
}
