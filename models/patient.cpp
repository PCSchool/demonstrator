#include "patient.h"
#include <fstream>
#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

//constructor
Patient::Patient(int id, QString email, char gender, QString street, QString housenr, QString zipcode, int homePhone, QString name, QDate date, double weight, double height) : User(id, email, gender, street, housenr, zipcode, homePhone, name, date){
    this->weight = weight;
    this->height = height;    
    calculateBMI(weight, height);

    //create new directory for the patient, directory can be recognised with id, since no database connect
    //check if there is already a directory with the id
    while(true){
        this->id++;
        if(!createDirectory()){
            break;
        }
    }
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
    QDir dir(QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + "/SignalSleepDemonstrator/patients/" + QString::number(id)));

    if(dir.exists()){
        return true;  //path exists already
    }else{
        //create directory for user/patient
        dir.mkpath(QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + "/SignalSleepDemonstrator/patients/" + QString::number(id)));//QString::number(id)));
        //create directory for recordings
        QDir dirRecordings(dir.path() + "/recordings");
        dirRecordings.mkpath(dir.path() + "/recordings");
        recordingDir.setPath(dir.path() + "/recordings");

        QString fixpath = QString(dir.path() + "/info.dat");
        pathPersonalInfo = fixpath;
        /*std::ofstream fout(fixpath.toLocal8Bit().constData(), std::ios::out | std::ios::binary);
        fout.write((char *)this, sizeof(this));
        fout.write((char *)&id, sizeof(int));
        std::string sname = name.toLocal8Bit().constData();
        fout.write((char *)&sname, sizeof(std::string));
        fout.write((char *)&gender, sizeof(char));
        std::string sstreet = street.toLocal8Bit().constData();
        fout.write((char *)&sstreet, sizeof(std::string));
        std::string shousenr = housenr.toLocal8Bit().constData();
        fout.write((char *)&shousenr, sizeof(std::string));
        std::string szipcode = zipcode.toLocal8Bit().constData();
        fout.write((char *)&szipcode, sizeof(std::string));
        fout.write((char *)&homePhone, sizeof(int));
        std::string semail = email.toLocal8Bit().constData();
        fout.write((char *)&semail, sizeof(std::string));
        std::string sdate = date.toString("dd.MM.yyyy").toLocal8Bit().constData();
        fout.write((char *)&sdate, sizeof(std::string));
        fout.close();*/

        //create notes.txt
        fixpath = QString(dir.path()) + "/notes.txt";
        std::ofstream fout2(fixpath.toLocal8Bit().constData(), std::ios::out);
        fout2 << "notes: " << endl;
        fout2.close();

        pathNotes = fixpath;
        this->userDir = dir;
    }
    return false; //path doesnt exist
}

//getters / setters properties
bool Patient::getPresent(){
    return present;
}
void Patient::setPresent(bool present){
    this->present = present;
}
