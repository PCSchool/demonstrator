#include "exportdialog.h"
#include "ui_exportdialog.h"
#include <QFileDialog>
#include <QStandardPaths>
#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <QDialog>
#include <QDirIterator> // <-- to loop through a QDir
#include <QDebug>
#include <models/exporting.h>
#include <qmessagebox.h>

using namespace std;

ExportDialog::ExportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExportDialog)
{
    ui->setupUi(this);
    exporting = new Exporting();
    connect(exporting, SIGNAL(updateReady(QDir, QDir)), this, SLOT(updateDialog(QDir,QDir)));
    connect(exporting, SIGNAL(readyToListBox(QStringList)), this, SLOT(updateListBox(QStringList)));
}

ExportDialog::~ExportDialog()
{
    delete ui;
}

//public slots
void ExportDialog::updateDialog(QDir userDir, QDir exportDir){
    ui->lblPathPatient->setText(userDir.path());
    ui->lblPathFile->setText(exportDir.path());
}

void ExportDialog::updateListBox(QStringList items){
    ui->lbListItems->addItems(items);
}

//private slots
void ExportDialog::on_btnCancel_clicked()
{
    delete this;
}

void ExportDialog::on_btnSelectPatient_clicked()
{
    QString path = QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + "/patients");
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), path, QFileDialog::ShowDirsOnly);
    exporting->cleanUserDir(path, dir);
    exporting->cleanListbox();
}

void ExportDialog::on_btnSelectExportFiles_clicked()
{
    //copy of on_btnselectpatient, will later be turned into a method probably
    QString path = QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()));
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),path, QFileDialog::ShowDirsOnly);
    exporting->cleanExportDir(dir, path);
}

void ExportDialog::on_btnExport_clicked()
{
    //export selected files to exportDir

    //if export results are successfull
    QString result = "All files have been succesfully been transported.";
    QMessageBox messageBox;
    messageBox.setFixedSize(500,200);
    messageBox.information(0, "Export succes", "The files have succesfully been exported.");
    messageBox.show();
}
