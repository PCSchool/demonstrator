/********************************************************************************
** Form generated from reading UI file 'recorddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDDIALOG_H
#define UI_RECORDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_RecordDialog
{
public:
    QCustomPlot *widget;
    QGroupBox *gbButtons;
    QPushButton *btnDummyGraph;
    QPushButton *btnStop;
    QPushButton *btnChangeSettings;
    QPushButton *btnCancel;
    QLabel *label;
    QFrame *line_2;
    QFrame *lineCloseSettings;
    QSpinBox *sbCounter;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *lblYAxis;
    QLabel *lblInterval;
    QLabel *label_5;
    QLabel *lblGraphType;
    QLabel *label_6;
    QLabel *lblSensor;
    QLabel *label_7;
    QLabel *lblFrequency;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *lblAmplitude;
    QLabel *lblTest;

    void setupUi(QDialog *RecordDialog)
    {
        if (RecordDialog->objectName().isEmpty())
            RecordDialog->setObjectName(QStringLiteral("RecordDialog"));
        RecordDialog->resize(1135, 608);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RecordDialog->sizePolicy().hasHeightForWidth());
        RecordDialog->setSizePolicy(sizePolicy);
        RecordDialog->setMinimumSize(QSize(850, 0));
        widget = new QCustomPlot(RecordDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(260, 10, 861, 581));
        gbButtons = new QGroupBox(RecordDialog);
        gbButtons->setObjectName(QStringLiteral("gbButtons"));
        gbButtons->setGeometry(QRect(0, 10, 250, 571));
        gbButtons->setMinimumSize(QSize(250, 400));
        btnDummyGraph = new QPushButton(gbButtons);
        btnDummyGraph->setObjectName(QStringLiteral("btnDummyGraph"));
        btnDummyGraph->setGeometry(QRect(30, 230, 200, 50));
        btnDummyGraph->setMinimumSize(QSize(200, 50));
        btnStop = new QPushButton(gbButtons);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setGeometry(QRect(30, 350, 200, 50));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnStop->sizePolicy().hasHeightForWidth());
        btnStop->setSizePolicy(sizePolicy1);
        btnStop->setMinimumSize(QSize(200, 50));
        btnChangeSettings = new QPushButton(gbButtons);
        btnChangeSettings->setObjectName(QStringLiteral("btnChangeSettings"));
        btnChangeSettings->setGeometry(QRect(30, 290, 200, 50));
        btnChangeSettings->setMinimumSize(QSize(200, 50));
        btnCancel = new QPushButton(gbButtons);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(30, 410, 200, 50));
        sizePolicy1.setHeightForWidth(btnCancel->sizePolicy().hasHeightForWidth());
        btnCancel->setSizePolicy(sizePolicy1);
        btnCancel->setMinimumSize(QSize(200, 50));
        label = new QLabel(gbButtons);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 121, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        line_2 = new QFrame(gbButtons);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(30, 210, 201, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        lineCloseSettings = new QFrame(gbButtons);
        lineCloseSettings->setObjectName(QStringLiteral("lineCloseSettings"));
        lineCloseSettings->setGeometry(QRect(30, 40, 201, 16));
        lineCloseSettings->setFrameShape(QFrame::HLine);
        lineCloseSettings->setFrameShadow(QFrame::Sunken);
        sbCounter = new QSpinBox(gbButtons);
        sbCounter->setObjectName(QStringLiteral("sbCounter"));
        sbCounter->setGeometry(QRect(130, 180, 61, 22));
        sbCounter->setMinimum(-150);
        sbCounter->setMaximum(250);
        sbCounter->setValue(250);
        label_2 = new QLabel(gbButtons);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 180, 51, 21));
        label_4 = new QLabel(gbButtons);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 60, 47, 13));
        lblYAxis = new QLabel(gbButtons);
        lblYAxis->setObjectName(QStringLiteral("lblYAxis"));
        lblYAxis->setGeometry(QRect(130, 60, 91, 16));
        lblInterval = new QLabel(gbButtons);
        lblInterval->setObjectName(QStringLiteral("lblInterval"));
        lblInterval->setGeometry(QRect(130, 80, 91, 16));
        label_5 = new QLabel(gbButtons);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 80, 47, 13));
        lblGraphType = new QLabel(gbButtons);
        lblGraphType->setObjectName(QStringLiteral("lblGraphType"));
        lblGraphType->setGeometry(QRect(130, 100, 91, 16));
        label_6 = new QLabel(gbButtons);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 100, 47, 13));
        lblSensor = new QLabel(gbButtons);
        lblSensor->setObjectName(QStringLiteral("lblSensor"));
        lblSensor->setGeometry(QRect(130, 120, 91, 16));
        label_7 = new QLabel(gbButtons);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 120, 47, 13));
        lblFrequency = new QLabel(gbButtons);
        lblFrequency->setObjectName(QStringLiteral("lblFrequency"));
        lblFrequency->setGeometry(QRect(130, 140, 91, 16));
        label_8 = new QLabel(gbButtons);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 140, 51, 16));
        label_9 = new QLabel(gbButtons);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(40, 160, 51, 16));
        lblAmplitude = new QLabel(gbButtons);
        lblAmplitude->setObjectName(QStringLiteral("lblAmplitude"));
        lblAmplitude->setGeometry(QRect(130, 160, 91, 16));
        lblTest = new QLabel(RecordDialog);
        lblTest->setObjectName(QStringLiteral("lblTest"));
        lblTest->setGeometry(QRect(10, 590, 831, 16));

        retranslateUi(RecordDialog);

        QMetaObject::connectSlotsByName(RecordDialog);
    } // setupUi

    void retranslateUi(QDialog *RecordDialog)
    {
        RecordDialog->setWindowTitle(QApplication::translate("RecordDialog", "Dialog", nullptr));
        gbButtons->setTitle(QString());
        btnDummyGraph->setText(QApplication::translate("RecordDialog", "Start dummy data", nullptr));
        btnStop->setText(QApplication::translate("RecordDialog", "Stop recording", nullptr));
        btnChangeSettings->setText(QApplication::translate("RecordDialog", "Change settings", nullptr));
        btnCancel->setText(QApplication::translate("RecordDialog", "Back", nullptr));
        label->setText(QApplication::translate("RecordDialog", "Settings:", nullptr));
        label_2->setText(QApplication::translate("RecordDialog", "Counter", nullptr));
        label_4->setText(QApplication::translate("RecordDialog", "Y-Axis", nullptr));
        lblYAxis->setText(QApplication::translate("RecordDialog", "X-Axis", nullptr));
        lblInterval->setText(QApplication::translate("RecordDialog", "Interval", nullptr));
        label_5->setText(QApplication::translate("RecordDialog", "Interval", nullptr));
        lblGraphType->setText(QApplication::translate("RecordDialog", "Interval", nullptr));
        label_6->setText(QApplication::translate("RecordDialog", "Graph", nullptr));
        lblSensor->setText(QApplication::translate("RecordDialog", "Interval", nullptr));
        label_7->setText(QApplication::translate("RecordDialog", "Sensor", nullptr));
        lblFrequency->setText(QApplication::translate("RecordDialog", "Interval", nullptr));
        label_8->setText(QApplication::translate("RecordDialog", "Frequency", nullptr));
        label_9->setText(QApplication::translate("RecordDialog", "Amplitude", nullptr));
        lblAmplitude->setText(QApplication::translate("RecordDialog", "Amplitude", nullptr));
        lblTest->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RecordDialog: public Ui_RecordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDDIALOG_H
