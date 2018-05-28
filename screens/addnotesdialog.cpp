#include "addnotesdialog.h"
#include "ui_addnotesdialog.h"
#include <QTextStream>
#include <QFile>
#include <QProcess>
#include <iostream>
#include <fstream>
#include <string>

AddNotesDialog::AddNotesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNotesDialog)
{
    ui->setupUi(this);
}

AddNotesDialog::~AddNotesDialog()
{
    delete ui;
}

void AddNotesDialog::on_buttonBox_accepted()
{
    emit(textToNotes(ui->tbText->text()));
}

void AddNotesDialog::on_buttonBox_rejected()
{
    delete ui;
}

void AddNotesDialog::setFile(QString path){
    QFile file(path);
    if(QFile(path).open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        while(!in.atEnd()){
            QString line = in.readLine();
        }
    }
    file.close();
}
