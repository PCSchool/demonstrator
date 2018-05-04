#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>
#include <iostream>
#include <string>
#include <models/User.h>
#include <models/patient.h>
#include <screens/userdialog.h>

namespace Ui {
class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT

public:
    //enum
    enum controlType{email, number, names, zipcodes, phone, housenr};

    //constructor
    explicit UserDialog(QWidget *parent = 0);
    ~UserDialog();
    bool validation(QString control, controlType type);

signals:
    void newPatientCreated(Patient* patient);
    void newPatient(Patient* Patient);

private slots:
    void on_btnRegister_clicked();

    void on_cbO_stateChanged(int arg1);

    void on_cbV_stateChanged(int arg1);

    void on_cbM_stateChanged(int arg1);

    void on_btnCancel_clicked();

    void on_btnSelectPatient_clicked();

private:
    Ui::UserDialog *ui;
    QString error;
    QString emptyError;
    char gender;
};

#endif // USERDIALOG_H
