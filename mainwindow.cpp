#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <recorddialog.h>
#include <models/user.h>
#include <models/system.h>
#include <screens/exportdialog.h>
#include <screens/devicedialog.h>
#include <screens/addnotesdialog.h>
#include <analysisdialog.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gbInfoPatient->setVisible(false);
    system = new System();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::patientSelected(Patient *patient){
    ui->gbInfoPatient->setVisible(true);
    ui->lblNamePatient->setText(patient->getName());
    ui->lblGenderPatient->setText(QString(patient->getGender()));
    ui->lblBirthDatePatient->setText(patient->getBirthDate().toString("dd.MM.yyyy"));
    ui->lblTest->setText(patient->getRecordingDir().path());
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
    userDialog->setModal(true);
    userDialog->exec();
}

void MainWindow::on_btnOpenDeviceDialog_clicked()
{
    DeviceDialog* deviceDialog = new DeviceDialog(this);
    connect(deviceDialog, SIGNAL(setSelectedDevice(Device)), this, SLOT(deviceSelected(Device)));
    deviceDialog->setModal(true);
    deviceDialog->exec();
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
    AnalysisDialog* analysisDialog = new AnalysisDialog(this);
    analysisDialog->setModal(true);
    analysisDialog->exec();
}

void MainWindow::on_btnOpenExportDialog_clicked()
{
    ExportDialog* exportDialog = new ExportDialog(this);
    exportDialog->setModal(true);
    exportDialog->exec();
}

void MainWindow::deviceSelected(Device device){
    system->setSelectedDevice(device);
}

QDir MainWindow::getHomeDirectory(){
    return system->getDir();
}

void MainWindow::on_btnSelectDirPatient_clicked()
{
    QString path = system->getPatient()->getUserDir().path();
}

void MainWindow::on_btnnAddNotes_clicked()
{
    if(!system->selectedPatient->getName().isNull()){
        AddNotesDialog* addNoteDialog = new AddNotesDialog(this);
        connect(addNoteDialog, SIGNAL(textToNotes(QString)), this, SLOT(addTextToNotes(QString)));
        addNoteDialog->setModal(true);
        addNoteDialog->exec();
    }
}

void MainWindow::addTextToNotes(QString text){
    system->selectedPatient->writeToNote(text);
}
