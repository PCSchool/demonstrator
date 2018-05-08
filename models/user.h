#ifndef USER_H
#define USER_H

#include <QDialog>
#include <iostream>
#include <string>
#include <QDate>
#include <QDir>

class User{
public:
    //constructors
    User();   //default constructor
    User(int id, QString email);
    User(int id, QString email, char gender, QString street, QString housenr, QString zipcode, int homePhone, QString name, QDate date);

    //methods

    //fields
    int id;
    QDir userDir;
    QDir recordingDir;

    //getters / setters
    int getId();
    QDir getUserDir();
    QDir getRecordingDir();
    QString getName();
    char getGender();
    QString getStreet();
    QString getHousenr();
    QString getZipcode();
    int getHomePhone();
    QString getEmail();
    QDate getBirthDate();

protected:
    //methods

    //fields
    QString name;
    char gender;
    QString street;
    QString housenr;  // <-- QString due to possibility of housenr like 12a, 221b
    QString zipcode;
    int homePhone;
    QString email;
    QDate date;

private:

};
#endif // USER_H
