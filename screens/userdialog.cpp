#include "userdialog.h"
#include "ui_userdialog.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QMessageBox>
#include <cctype>
#include <regex>
#include <qstandardpaths.h>
#include <qfiledialog.h>
#include <models/system.h>

using namespace std;

UserDialog::UserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog)
{
    ui->setupUi(this);
    gender = 'o';   //gender default is o
}

UserDialog::~UserDialog()
{
    delete ui;
}

void UserDialog::on_btnRegister_clicked()
{
    emptyError = "";
    error = "";
    int id = 0;

    if(!validation(ui->tbName->text(), names)){
        error = "Name invalid. Please re-enter the name.";
    }
    if(!validation(ui->tbStreet->text(), names)){
        error = "Street invalid. Please enter only the streetname.";
    }
    if(!validation(ui->tbHouseNr->text(), characters)){    //nr can be 12a, 13b
        error = "House nr invalid. Please re-enter the house nr.";
    }
    if(!validation(ui->tbHomephone->text(), phone)){
        error = "home phone number invalid. Please enter the phone number in numbrs only.";
    }
    if(!validation(ui->tbZipcode->text(), zipcodes)){
        error = "zipcode invalid. Please re-enter the zipcode.";
    }
    if(!validation(ui->tbEmail->text(), email)){
        error = "email invalid. Please re-enter a valid email."; // example valid email: Hello@email.com
    }

    QMessageBox messageBox; //show results of form with QMessagebox
    messageBox.setFixedSize(500,200);

    if(error == ""){  //geen errors, valid is goed
        // current solution to prevent runtime error caused by the validation?
        int homephone = ui->tbHouseNr->text().toInt();
        Patient* patient = new Patient(id, ui->tbEmail->text(), gender, ui->tbStreet->text(), ui->tbHouseNr->text(), ui->tbZipcode->text(), homephone, ui->tbName->text(), ui->tbBirthDate->date(), ui->spWeight->value(), ui->spHeight->value());
        emit newPatient(patient);
        messageBox.information(0, "Registration succes", "The Patient has succesfully been registered.");
        on_btnCancel_clicked();
    }else{
        if(emptyError != ""){
            messageBox.critical(0, "Error", emptyError);
        }else{
            messageBox.critical(0,"Error",error);
        }
        messageBox.show();
    }
}

bool UserDialog::validation(QString control, controlType type){
    // 1. control if QString is not empty
    if(control.length() < 1 || control.isNull()){
        emptyError = "Please fill in all the fields of the form";
        return false;
    }

    // 2. control if QString contains all necessary characters
    switch (type) {
    case characters:   //all characters allowed
    {
        break;
    }
        break;
    case email:  //must contain @ and one or more .
    {
        QRegExp re("^([a-zA-Z0-9_-])+@([a-zA-Z0-9_-])+(.[a-zA-Z0-9_-])+");
        if(re.exactMatch(control)){
            return true;
        }else{
            return false;
        }
        break;
    }
    case names:  //only non-digit characters included _ wi
    {
        QRegExp re("[A-Za-z]+\\s*");
        QRegExp regexp("^\\s+");

        if(!re.exactMatch(control)){    //when control doesnt match with
            if(regexp.exactMatch(control)){
                std::cout << "White spaces approval";
            }
            return false;
        }
        break;
    }
    case number:     //only digit characters are allowed
    {
        for(int i = 0; i < control.length(); i++){
            if(!control[i].isDigit()){
                return false;
            }
        }
        break;
    }
    case phone:     //only digit characters are allowed + length = 10
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
    case zipcodes:     //first four digits, followed by two char
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

void UserDialog::on_cbO_stateChanged(int arg1)
{    if(arg1 == 2){
        gender = 'o';
        ui->cbV->setChecked(false);
        ui->cbM->setChecked(false);
    }
}

void UserDialog::on_cbV_stateChanged(int arg1)
{
    std::string s = std::to_string(arg1);
    if(arg1 == 2){
        gender = 'v';
        ui->cbM->setChecked(false);
        ui->cbO->setChecked(false);
    }
}

void UserDialog::on_cbM_stateChanged(int arg1){
    if(arg1 == 2){
        gender = 'm';
    }
    ui->cbV->setChecked(false);
    ui->cbO->setChecked(false);
}

void UserDialog::on_btnCancel_clicked()
{
    delete this;
}

void UserDialog::on_btnSelectPatient_clicked()
{
    QString path = QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + "/SignalSleepDemonstrator/patients");
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                path, QFileDialog::ShowDirsOnly);

    cout << dir.toLocal8Bit().constData() << endl;
    QString infopath = dir + "/info.bin";
    std::string s = infopath.toLocal8Bit().constData();
    std::ifstream fin(s.c_str(), ios::out | ios::binary);
    if(!fin.is_open()){
        cout << "opening file failed "<< s.c_str() << "  " << endl;
    }else{
        User user;
        fin.read((char *)&user, sizeof(user));
        ui->btnCancel->setText(user.getEmail());
        fin.close();
    }
}
