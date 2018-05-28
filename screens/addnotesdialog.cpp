#include "addnotesdialog.h"
#include "ui_addnotesdialog.h"
#include <QTextStream>
#include <QFile>
#include <QProcess>
#include <fstream>
#include <sstream>
#include <string>
#include <QDebug>

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
    QString line;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while(!stream.atEnd()){

            qDebug(stream.readLine().toLocal8Bit().constData());
            QString ss = stream.readLine().toLocal8Bit().constData();
            ui->tbTextRead->setText(ui->tbTextRead->toPlainText()+ss+" ");
        }

    }
    file.close();
}
