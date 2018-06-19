#include "userdialog.h"
#include "ui_userdialog.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QMessageBox>
#include <cctype>
#include <regex>
#include <qstandardpaths.h>
#include <models/binarypatient.h>
#include <models/system.h>
#include <globals.h>
#include <exceptions/exceptionemptyform.h>

using namespace std;

UserDialog::UserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog)
{
    ui->setupUi(this);
    gender = 'o';   //gender default is o
    dir = System::getPatientLocation();

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

    try{
        if(!Patient::validationFormCheck(ui->tbName->text(), controlType::names)){
            error = "Name invalid. Please re-enter the name. ";
        }
        if(!Patient::validationFormCheck(ui->tbStreet->text(), controlType::names )){
            error = "Street invalid. Please enter only the streetname.";
        }
        if(!Patient::validationFormCheck(ui->tbHouseNr->text(), controlType::housenr)){    //nr can be 12a, 13b
            error = "House nr invalid. Please re-enter the house nr.";
        }
        if(!Patient::validationFormCheck(ui->tbHomephone->text(), controlType::phone)){
            error = "phone number invalid. Please enter the phone number. \nThe phone number only allows numbers";
        }
        if(!Patient::validationFormCheck(ui->tbZipcode->text(), controlType::zipcodes)){
            error = "zipcode invalid. Please re-enter the zipcode. \nThe zipcode is built up as follows: \n-first four are numbers \n-the other two are charachters \nFor example:'6671JK' or '9102KL'.";
        }
        if(!Patient::validationFormCheck(ui->tbEmail->text(), controlType::email)){
            error = "email invalid. Please re-enter a valid email. \nA valid email contains: \n-One '@' char \n-One '.' \nFor example: 'HenryV@outlook.com'." ;  // example valid email: Hello@email.com
        }
    }catch(ExceptionEmptyForm &e){
        emptyError = "Not all fields are correctly filled in, please try again.";
    }

    QMessageBox messageBox; //show results of form with QMessagebox
    messageBox.setFixedSize(500,200);

    if(error == "" && emptyError == ""){  //geen errors, valid is goed
        QString newPath = dir.path() + "/" + ui->tbEmail->text();
        QDir dirCheckExists(newPath);
        if(!dirCheckExists.exists()){
            //directory does not exist -> ready to make new account for that directory
            // current solution to prevent runtime error caused by the validation?
            int homephone = ui->tbHouseNr->text().toInt();
            Patient* patient = new Patient(false, id, ui->tbEmail->text(), gender, ui->tbStreet->text(), ui->tbHouseNr->text(), ui->tbZipcode->text(), homephone, ui->tbName->text(), ui->tbBirthDate->date(), ui->spWeight->value(), ui->spHeight->value());

            if(patient->writeProfileToBinary())
                messageBox.information(0, "Registration succes", "The Patient has succesfully been registered.");
                emit newPatient(patient);
            on_btnCancel_clicked();
        }else{
            messageBox.critical(0, "Error", "There already exists an account with this email addres.");
        }
    }else{
        if(emptyError != ""){
            messageBox.critical(0, "Error", emptyError);
        }else{
            messageBox.critical(0,"Error",error);
        }
    }
    messageBox.show();
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
        ui->cbV->setChecked(false);
        ui->cbO->setChecked(false);
    }
}

void UserDialog::on_btnCancel_clicked()
{
    delete this;
}

void UserDialog::on_btnSelectPatient_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select patient file"),
                                                System::getPatientLocation(), QFileDialog::DontUseNativeDialog);
    int index = dir.lastIndexOf("/");
    QString control = dir.mid(index);

    if(!dir.isEmpty() && !dir.isNull() && !control.contains("patients")){
        std::string pathInfo = dir.toLocal8Bit().constData();
        pathInfo = pathInfo + "/info.dat";
        std::ifstream fin(pathInfo, ios::out | ios::binary);
        if(!fin.is_open()){
            cout << "opening file failed "<< pathInfo.c_str() << "  " << endl;
            int ret = QMessageBox::warning(this, "Error", "The personal information of the patient is missing. Would u like to delete this patient?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
            if(ret == 16384){
                emit removePatient(dir);
            }
        }else{
            BinaryPatient bpatient;
            fin.read((char *)&bpatient, sizeof(bpatient));
            QDate date = QDate::fromString(QString::fromUtf8(bpatient.birthDate), "dd/MM/yyyy");
            Patient* patient = new Patient(true, bpatient.id, QString::fromUtf8(bpatient.email), bpatient.gender, QString::fromUtf8(bpatient.street), QString::fromUtf8(bpatient.housenr), QString::fromUtf8(bpatient.zipcode), bpatient.homePhone, QString::fromUtf8(bpatient.name), date, bpatient.weight, bpatient.height);
            patient->setDirectory(dir, "","","");
            emit newPatient(patient);
            on_btnCancel_clicked();
        }
    }

}

void UserDialog::on_btnDeletePatient_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select patient file"),
                                                System::getPatientLocation(), QFileDialog::DontUseNativeDialog);
    QString control = dir.mid(dir.lastIndexOf("/"));

    if(!dir.isEmpty() && !dir.isNull() && !control.contains("patients") && control.contains("@")){
        emit removePatient(dir);
    }

}
