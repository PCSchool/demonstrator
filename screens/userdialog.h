#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>
#include <iostream>
#include <string>
#include <models/User.h>
#include <models/patient.h>
#include <screens/userdialog.h>
#include <globals.h>

namespace Ui {
class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT

public:
    //enum

    //constructor
    explicit UserDialog(QWidget *parent = 0);
    ~UserDialog();
    bool fileFull;

signals:
    void newPatientCreated(Patient* patient);
    void newPatient(Patient* Patient);
    void removePatient(QString path);

private slots:
    void on_btnRegister_clicked();

    void on_cbO_stateChanged(int arg1);

    void on_cbV_stateChanged(int arg1);

    void on_cbM_stateChanged(int arg1);

    void on_btnCancel_clicked();

    void on_btnSelectPatient_clicked();

    void on_btnDeletePatient_clicked();

private:
    Ui::UserDialog *ui;
    QString error;
    QString emptyError;
    QDir dir;
    char gender;
};

#endif // USERDIALOG_H
