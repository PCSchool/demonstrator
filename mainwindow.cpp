#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <recorddialog.h>
#include <models/user.h>
#include <models/system.h>
#include <screens/exportdialog.h>
#include <screens/devicedialog.h>
#include <screens/addnotesdialog.h>
#include <screens/analysisdialog.h>
#include <iostream>
#include <fstream>
#include <exception>
#include <models/binarypatient.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gbInfoPatient->setVisible(false);
    system = new System();
    system->loadCrypt32();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::patientSelected(Patient *patient){
    ui->gbInfoPatient->setVisible(true);
    ui->lblNamePatient->setText(patient->getName());
    ui->lblGenderPatient->setText(patient->getGender());
    ui->lblBirthDatePatient->setText(patient->getBirthDate().toString("dd.MM.yyyy"));
    ui->lblBMI->setText(QString::number(patient->getBMI()));
    ui->lblHeight->setText(QString::number(patient->getHeight()));
    ui->lblPhone->setText(QString::number(patient->getHomePhone()));
    ui->lblWeight->setText(QString::number(patient->getWeight()));
    ui->lblEmail->setText(patient->getEmail());
    this->system->setDir(patient->getRecordingDir().path());
    this->system->setPatient(patient);
}

void MainWindow::userDeselected(){
    ui->gbInfoPatient->setVisible(false);
    ui->lblNamePatient->setText(" ");
}

void MainWindow::on_btnOpenPatientDialog_clicked()
{
    UserDialog* userDialog = new UserDialog(this);
    connect(userDialog, SIGNAL(newPatient(Patient*)), this, SLOT(patientSelected(Patient*)));
    connect(userDialog, SIGNAL(removePatient(QString)), this, SLOT(removePatientSlot(QString)));
    userDialog->setModal(true);
    userDialog->exec();
}

void MainWindow::on_btnOpenDeviceDialog_clicked()
{
    if(system->hasPatient){
        DeviceDialog* deviceDialog = new DeviceDialog(this);
        connect(deviceDialog, SIGNAL(setSelectedDevice(Device)), this, SLOT(deviceSelected(Device)));
        deviceDialog->setModal(true);
        deviceDialog->exec();
    }else{
        QMessageBox msgBox(QMessageBox::Warning, "Warning: not available", "To start the analysis, a patient must be selected.");
        msgBox.exec();
    }
}

void MainWindow::on_btnOpenRecordingDialog_clicked()
{
    RecordDialog* recordDialog = new RecordDialog(this);
    recordDialog->setUserDir(this->system->getDir());
    recordDialog->setModal(true);
    recordDialog->exec();
}

void MainWindow::on_btnOpenAnalysisDialog_clicked()
{
    if(system->hasPatient){
        AnalysisDialog* analysisDialog = new AnalysisDialog(this);
        analysisDialog->setDir(system->selectedPatient->getRecordingDir());
        analysisDialog->setModal(true);
        analysisDialog->exec();
    }else{
        QMessageBox msgBox(QMessageBox::Warning, "Warning: not available", "To start the analysis, a patient must be selected.");
        msgBox.exec();
    }
}

void MainWindow::on_btnOpenExportDialog_clicked()
{
    if(system->hasPatient){
        ExportDialog* exportDialog = new ExportDialog(this);
        exportDialog->prepare(system->getPatientDir(), system->selectedPatient->getUserDir());
        exportDialog->setModal(true);
        exportDialog->exec();
    }else{
        QMessageBox msgBox(QMessageBox::Warning, "Warning: not available", "To start the analysis, a patient must be selected.");
        msgBox.exec();
    }
}

void MainWindow::deviceSelected(Device device){
    system->setSelectedDevice(device);
}

QDir MainWindow::getHomeDirectory(){
    return system->getDir();
}

//open directory of current selectedPatient
void MainWindow::on_btnSelectDirPatient_clicked(){
    const QString path =  QFileDialog::getOpenFileName(
                    this,
                    "Open Document",
                    system->selectedPatient->userDir.path(),
                    "All files (*.*) ;; Document files (*.doc *.rtf);; PNG files (*.png)");
}

void MainWindow::on_btnnAddNotes_clicked(){
    if(!system->selectedPatient->getName().isNull()){
        AddNotesDialog* addNoteDialog = new AddNotesDialog(this);
        connect(addNoteDialog, SIGNAL(textToNotes(QString)), this, SLOT(addTextToNotes(QString)));
        addNoteDialog->setFile(system->selectedPatient->getPathNotes());
        addNoteDialog->setModal(true);
        addNoteDialog->exec();
    }
}

void MainWindow::addTextToNotes(QString text){
    system->selectedPatient->writeToNote(text);
}

void MainWindow::openNotes(){
    std::ifstream fin;
    fin.open(system->selectedPatient->pathNotes.toLocal8Bit().constData());
}

void MainWindow::on_btnChangePatient_clicked()
{
    QString path = QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + "/SignalSleepDemonstrator/patients");
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select patient file"),
                                                path, QFileDialog::DontUseNativeDialog);

    std::string pathInfo = dir.toLocal8Bit().constData();
    pathInfo = pathInfo + "/info.dat";

    std::ifstream fin(pathInfo, ios::out | ios::binary);
    if(!fin.is_open()){
        cout << "opening file failed "<< pathInfo.c_str() << "  " << endl;
    }else{
        BinaryPatient two;
        fin.read((char *)&two, sizeof(two));
        QDate date = QDate::fromString(QString::fromUtf8(two.birthDate), "dd/MM/yyyy");
        Patient* pp = new Patient(true, two.id, QString::fromUtf8(two.email), two.gender, QString::fromUtf8(two.street), QString::fromUtf8(two.housenr), QString::fromUtf8(two.zipcode), two.homePhone, QString::fromUtf8(two.name), date, two.weight, two.height);
        patientSelected(pp);
    }
}

void MainWindow::removePatientSlot(QString thispath){
    system->removePatient(thispath);
}
