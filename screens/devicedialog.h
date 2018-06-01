#ifndef DEVICEDIALOG_H
#define DEVICEDIALOG_H

#include <QDialog>
<<<<<<< HEAD
#include <models/device.h>
#include <mainwindow.h>
#include <models/system.h>
=======
>>>>>>> 62ffced7a03b4bcf911f1b212369ade8808337d3

namespace Ui {
class DeviceDialog;
}

class DeviceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeviceDialog(QWidget *parent = 0);
    ~DeviceDialog();

<<<<<<< HEAD
signals:
    void setSelectedDevice(Device d);

public slots:

private slots:
    void on_btnAddDevice_clicked();

    void on_btnContinue_clicked();

    void on_btnCancel_clicked();

private:
    Device device;
    QDir dir; //directory of
=======
private:
>>>>>>> 62ffced7a03b4bcf911f1b212369ade8808337d3
    Ui::DeviceDialog *ui;
};

#endif // DEVICEDIALOG_H
