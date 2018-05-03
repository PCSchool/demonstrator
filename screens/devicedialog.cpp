#include "devicedialog.h"
#include "ui_devicedialog.h"
#include <QFileDialog>
#include <QStandardPaths>
using namespace std;

DeviceDialog::DeviceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeviceDialog)
{
    ui->setupUi(this);

}

DeviceDialog::~DeviceDialog()
{
    delete ui;
}

void DeviceDialog::on_btnAddDevice_clicked()
{
    QString path = QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()));
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                path, QFileDialog::ShowDirsOnly);
    Device device("dummy", dir);
    emit setSelectedDevice(device);
    ui->lblTest->setText(dir);
}

void DeviceDialog::on_btnContinue_clicked()
{

}

void DeviceDialog::on_btnCancel_clicked()
{
    delete ui;
}
