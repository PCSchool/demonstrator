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
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()))
                                                    , QFileDialog::ShowDirsOnly);
    QMessageBox messageBox;
    messageBox.setFixedSize(500,200);
    messageBox.warning(0, "Error", "There already exists a device with this name.");
    bool ok;
    QString text = "";
    while(text == ""){
        text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                                     tr("Device name:"), QLineEdit::Normal,
                                                     QDir::home().dirName(), &ok);
        if(!ok){
            break;
        }
    }

    if(ok && !text.isEmpty()){
        if(!Device::validationCheckExists(text)){
            Device device(text, dir);
            emit setSelectedDevice(device);
            ui->lblTest->setText(text + " - " + dir);
        }else{
            messageBox.show();
        }
    }
}

void DeviceDialog::on_btnContinue_clicked()
{

}

void DeviceDialog::on_btnCancel_clicked()
{
    delete ui;
}
