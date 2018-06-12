#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <models/User.h>
#include <screens/userdialog.h>
#include <recorddialog.h>
#include <models/system.h>
#include <models/device.h>
#include <design/demonstratorstyle.h>
#include <QPalette>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:


public slots:
    QDir getHomeDirectory();

private slots:
    void patientSelected(Patient* patient);
    void removePatientSlot(QString thispath);
    void userDeselected();
    void deviceSelected(Device device);
    void addTextToNotes(QString text);
    void openNotes();

    void on_btnOpenPatientDialog_clicked();
    void on_btnOpenDeviceDialog_clicked();
    void on_btnOpenRecordingDialog_clicked();
    void on_btnOpenAnalysisDialog_clicked();
    void on_btnOpenExportDialog_clicked();
    void on_btnSelectDirPatient_clicked();
    void on_btnAddNotes_clicked();
    void on_btnChangePatient_clicked();

private:
    Ui::MainWindow *ui;
    User *user;
    Patient *patient;
    System *system;
};

#endif // MAINWINDOW_H
