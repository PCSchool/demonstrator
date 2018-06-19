#include "devicedialog.h"
#include "ui_devicedialog.h"
#include <QFileDialog>
#include <QStandardPaths>
#include <models/system.h>
using namespace std;

DeviceDialog::DeviceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeviceDialog)
{
    ui->setupUi(this);
    QDirIterator it(System::getDeviceLocation(), QDirIterator::Subdirectories | QDirIterator::FollowSymlinks);
    while(it.hasNext()){
        qDebug() << it.next();

    }

}

DeviceDialog::~DeviceDialog()
{
    delete ui;
}

void DeviceDialog::on_btnAddDevice_clicked()
{
    QMessageBox messageBox;
    messageBox.setFixedSize(500,200);
    QString text = "";
    bool ok;
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()))
                                                    , QFileDialog::ShowDirsOnly);
    while(text == ""){
        text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                                     tr("Device name:"), QLineEdit::Normal,
                                                     QDir::home().dirName(), &ok);
        if(!ok){
            break;
        }
    }

    if(ok && !text.isEmpty()){
        if(!System::checkDirectoryExists(System::getDeviceLocation() + text)){
            Device device(text, dir);
            emit setSelectedDevice(device);
            ui->lblTest->setText(dir);
            ui->lbListDevices->addItem(text);
            devices.push_back(device);
        }else{
            messageBox.warning(0, "Error", "There already exists a device with this name. \n Select the device again and enter a new name.");
            messageBox.show();
        }
    }

}


void DeviceDialog::on_btnCancel_clicked()
{
    delete ui;
}

void DeviceDialog::on_lbListDevices_itemClicked(QListWidgetItem *item)
{
    ui->lblSelectedDeviceName->setText(item->text());
}
