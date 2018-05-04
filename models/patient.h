#ifndef PATIENT_H
#define PATIENT_H

#include <models/user.h>
#include <QDir>
#include <QFile>
#include <models/recording.h>
#include <vector>

class Patient : public User
{
public:
    //constructor
    Patient();
    Patient(bool exist, int id, QString email, char gender, QString street, QString housenr, QString zipcode, int homePhone, QString name, QDate date, double weight, double height);

    //methods
    void changeProfile(QString newInfo, QString variable);
    void writeToNote(QString addToNote);
    bool writeProfileToBinary();

    QString pathNotes;
    QString pathPersonalInfo;

    //getters / setters
    bool getPresent();
    void setPresent(bool present);
    double getWeight();
    double getHeight();

private:
    //methods
    void calculateBMI(double weight, double height);
    bool createDirectory();

    //fields
    double weight;
    double height;
    double bmi;
    QDir directory;

    bool present;
    std::map<Recording, int> recordings;
};

#endif // PATIENT_H
