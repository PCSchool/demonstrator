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

Ui::ExportDialog::ExportDialog(QWidget *parent) : QDialog(parent),
    ui(new Ui::ExportDialog)
{
    ui->setupUi(this);
    exporting = new Exporting();
    connect(exporting, SIGNAL(updateReady(QDir, QDir)), this, SLOT(updateDialog(QDir,QDir)));
    connect(exporting, SIGNAL(readyToListBox(QStringList)), this, SLOT(updateListBox(QStringList)));
}

Ui::ExportDialog::~ExportDialog()
{
    delete ui;
}

//public slots
void Ui::ExportDialog::updateDialog(QDir userDir, QDir exportDir){
    ui->lblPathPatient->setText(userDir.path());
    ui->lblPathFile->setText(exportDir.path());
}

void Ui::ExportDialog::updateListBox(QStringList items){
    ui->lbListItems->clear();
    ui->lbListItems->addItems(items);
}

//private slots
void Ui::ExportDialog::on_btnCancel_clicked()
{
    delete this;
}

void Ui::ExportDialog::on_btnSelectPatient_clicked()
{
    const QString dir =  QFileDialog::getOpenFileName(
                this,
                "Open Document",
                this->exporting->getUserDir().path(),
                "All files (*.*) ;; Document files (*.doc *.rtf);; PNG files (*.png)");
    exporting->cleanUserDir(dir, dir);
    exporting->cleanListbox();
}

void Ui::ExportDialog::on_btnSelectExportFiles_clicked()
{
    //copy of on_btnselectpatient, will later be turned into a method probably
    const QString path =  QFileDialog::getOpenFileName(
                this,
                "Open Document",
                exporting->getExportDir().path(),
                "All files (*.*) ;; Document files (*.doc *.rtf);; PNG files (*.png)");
    exporting->cleanExportDir(path, path);
}

void Ui::ExportDialog::on_btnExport_clicked()
{
    //export selected files to exportDir
    ui->lbListItems->clear();
    //if export results are successfull
    QString result = "All files have been succesfully been transported.";
    QMessageBox messageBox;
    messageBox.setFixedSize(500,200);
    messageBox.information(0, "Export succes", "The files have succesfully been exported.");
    messageBox.show();
}

void Ui::ExportDialog::prepare(QDir userPath, QDir exportPath){
    exporting->setExportDir(exportPath);
    exporting->setUserDir(userPath);
    ui->lblPathFile->setText(userPath.path());
    ui->lblPathPatient->setText(exportPath.path());
}
