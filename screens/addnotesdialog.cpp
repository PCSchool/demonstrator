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
    QList<QString> list;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        list.append(stream.readAll());
    }
    file.close();

    QListIterator<QString> it(list);
    while(it.hasNext()){
        ui->tbTextRead->setText(ui->tbTextRead->toPlainText()+it.next()+" ");
    }
}
