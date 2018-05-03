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
    Patient(int id, QString email, char gender, QString street, QString housenr, QString zipcode, int homePhone, QString name, QDate date, double weight, double height);

    //methods
    void changeProfile(QString newInfo, QString variable);
    void writeToNote(QString addToNote);

    //getters / setters
    bool getPresent();
    void setPresent(bool present);

private:
    //methods
    void calculateBMI(double weight, double height);
    bool createDirectory();

    //fields
    double weight;
    double height;
    double bmi;
    QDir directory;
    QString pathNotes;
    QString pathPersonalInfo;
    bool present;
    std::map<Recording, int> recordings;
};

#endif // PATIENT_H
