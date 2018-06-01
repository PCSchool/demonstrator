#ifndef DEVICEDIALOG_H
#define DEVICEDIALOG_H

#include <QDialog>
#include <models/device.h>

namespace Ui {
class DeviceDialog : public QDialog{
    Q_OBJECT

public:
    explicit DeviceDialog(QWidget *parent = 0);
    ~DeviceDialog();

signals:
    void setSelectedDevice(Device d);

private slots:
    void on_btnAddDevice_clicked();

    void on_btnContinue_clicked();

    void on_btnCancel_clicked();

private:
    Device device;
    QDir dir; //directory of
    Ui::DeviceDialog *ui;

};

#endif // DEVICEDIALOG_H
