/********************************************************************************
** Form generated from reading UI file 'devicedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEDIALOG_H
#define UI_DEVICEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DeviceDialog
{
public:
    QFrame *line;
    QLabel *label_2;
    QPushButton *btnAddDevice;
    QLabel *label;
    QPushButton *btnCancel;
    QPushButton *btnContinue;
    QLabel *label_3;
    QLabel *lblNameDevice;
    QLabel *lblTest;
    QListWidget *lbListDevices;
    QFrame *line_2;

    void setupUi(QDialog *DeviceDialog)
    {
        if (DeviceDialog->objectName().isEmpty())
            DeviceDialog->setObjectName(QStringLiteral("DeviceDialog"));
        DeviceDialog->resize(491, 302);
        line = new QFrame(DeviceDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(230, 40, 20, 231));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(DeviceDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 0, 141, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        btnAddDevice = new QPushButton(DeviceDialog);
        btnAddDevice->setObjectName(QStringLiteral("btnAddDevice"));
        btnAddDevice->setGeometry(QRect(20, 240, 200, 21));
        btnAddDevice->setMinimumSize(QSize(200, 0));
        label = new QLabel(DeviceDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 131, 16));
        btnCancel = new QPushButton(DeviceDialog);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(250, 260, 200, 23));
        btnCancel->setMinimumSize(QSize(200, 0));
        btnContinue = new QPushButton(DeviceDialog);
        btnContinue->setObjectName(QStringLiteral("btnContinue"));
        btnContinue->setGeometry(QRect(250, 240, 200, 23));
        btnContinue->setMinimumSize(QSize(200, 0));
        label_3 = new QLabel(DeviceDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(250, 50, 131, 16));
        lblNameDevice = new QLabel(DeviceDialog);
        lblNameDevice->setObjectName(QStringLiteral("lblNameDevice"));
        lblNameDevice->setGeometry(QRect(250, 70, 361, 131));
        lblTest = new QLabel(DeviceDialog);
        lblTest->setObjectName(QStringLiteral("lblTest"));
        lblTest->setGeometry(QRect(20, 280, 451, 16));
        lbListDevices = new QListWidget(DeviceDialog);
        lbListDevices->setObjectName(QStringLiteral("lbListDevices"));
        lbListDevices->setGeometry(QRect(20, 71, 200, 171));
        lbListDevices->setMinimumSize(QSize(200, 0));
        line_2 = new QFrame(DeviceDialog);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 30, 471, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        retranslateUi(DeviceDialog);

        QMetaObject::connectSlotsByName(DeviceDialog);
    } // setupUi

    void retranslateUi(QDialog *DeviceDialog)
    {
        DeviceDialog->setWindowTitle(QApplication::translate("DeviceDialog", "Dialog", nullptr));
        label_2->setText(QApplication::translate("DeviceDialog", "Select device", nullptr));
        btnAddDevice->setText(QApplication::translate("DeviceDialog", "Add device", nullptr));
        label->setText(QApplication::translate("DeviceDialog", "Available devices:", nullptr));
        btnCancel->setText(QApplication::translate("DeviceDialog", "Cancel", nullptr));
        btnContinue->setText(QApplication::translate("DeviceDialog", "Continue", nullptr));
        label_3->setText(QApplication::translate("DeviceDialog", "Selected device:", nullptr));
        lblNameDevice->setText(QString());
        lblTest->setText(QApplication::translate("DeviceDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceDialog: public Ui_DeviceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEDIALOG_H
