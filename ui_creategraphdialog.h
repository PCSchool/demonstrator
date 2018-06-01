/********************************************************************************
** Form generated from reading UI file 'creategraphdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGRAPHDIALOG_H
#define UI_CREATEGRAPHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateGraphDialog
{
public:
    QPushButton *btnCreateGraph;
    QPushButton *btnCancel;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_3;
    QLabel *label_5;
    QLabel *label_2;
    QDoubleSpinBox *cbYAxisMax;
    QDoubleSpinBox *cbYAxisMin;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *cbInterval;
    QLabel *label_8;
    QComboBox *cbTypeGraph;
    QComboBox *cbTypeSensor;
    QLabel *label_9;
    QLabel *label_10;
    QDoubleSpinBox *cbAmplitude;
    QDoubleSpinBox *cbFrequency;
    QLabel *label;

    void setupUi(QDialog *CreateGraphDialog)
    {
        if (CreateGraphDialog->objectName().isEmpty())
            CreateGraphDialog->setObjectName(QStringLiteral("CreateGraphDialog"));
        CreateGraphDialog->resize(425, 304);
        CreateGraphDialog->setMinimumSize(QSize(220, 260));
        btnCreateGraph = new QPushButton(CreateGraphDialog);
        btnCreateGraph->setObjectName(QStringLiteral("btnCreateGraph"));
        btnCreateGraph->setGeometry(QRect(190, 260, 101, 23));
        btnCancel = new QPushButton(CreateGraphDialog);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(300, 260, 91, 23));
        formLayoutWidget = new QWidget(CreateGraphDialog);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 50, 371, 201));
        formLayout_3 = new QFormLayout(formLayoutWidget);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setPointSize(10);
        label_5->setFont(font);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_5);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_2);

        cbYAxisMax = new QDoubleSpinBox(formLayoutWidget);
        cbYAxisMax->setObjectName(QStringLiteral("cbYAxisMax"));
        cbYAxisMax->setDecimals(0);
        cbYAxisMax->setMinimum(-500);
        cbYAxisMax->setMaximum(500);
        cbYAxisMax->setValue(250);

        formLayout_3->setWidget(4, QFormLayout::FieldRole, cbYAxisMax);

        cbYAxisMin = new QDoubleSpinBox(formLayoutWidget);
        cbYAxisMin->setObjectName(QStringLiteral("cbYAxisMin"));
        cbYAxisMin->setDecimals(0);
        cbYAxisMin->setMinimum(-500);
        cbYAxisMin->setMaximum(500);
        cbYAxisMin->setValue(-100);

        formLayout_3->setWidget(5, QFormLayout::FieldRole, cbYAxisMin);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        formLayout_3->setWidget(5, QFormLayout::LabelRole, label_7);

        cbInterval = new QSpinBox(formLayoutWidget);
        cbInterval->setObjectName(QStringLiteral("cbInterval"));
        cbInterval->setMaximum(100);
        cbInterval->setValue(20);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, cbInterval);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_8);

        cbTypeGraph = new QComboBox(formLayoutWidget);
        cbTypeGraph->addItem(QString());
        cbTypeGraph->addItem(QString());
        cbTypeGraph->addItem(QString());
        cbTypeGraph->addItem(QString());
        cbTypeGraph->setObjectName(QStringLiteral("cbTypeGraph"));

        formLayout_3->setWidget(6, QFormLayout::FieldRole, cbTypeGraph);

        cbTypeSensor = new QComboBox(formLayoutWidget);
        cbTypeSensor->addItem(QString());
        cbTypeSensor->addItem(QString());
        cbTypeSensor->addItem(QString());
        cbTypeSensor->addItem(QString());
        cbTypeSensor->setObjectName(QStringLiteral("cbTypeSensor"));

        formLayout_3->setWidget(7, QFormLayout::FieldRole, cbTypeSensor);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        formLayout_3->setWidget(6, QFormLayout::LabelRole, label_9);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        formLayout_3->setWidget(7, QFormLayout::LabelRole, label_10);

        cbAmplitude = new QDoubleSpinBox(formLayoutWidget);
        cbAmplitude->setObjectName(QStringLiteral("cbAmplitude"));
        cbAmplitude->setValue(20);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, cbAmplitude);

        cbFrequency = new QDoubleSpinBox(formLayoutWidget);
        cbFrequency->setObjectName(QStringLiteral("cbFrequency"));
        cbFrequency->setDecimals(1);
        cbFrequency->setMaximum(50);
        cbFrequency->setSingleStep(0.1);
        cbFrequency->setValue(1);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, cbFrequency);

        label = new QLabel(CreateGraphDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 301, 21));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        QWidget::setTabOrder(btnCreateGraph, btnCancel);

        retranslateUi(CreateGraphDialog);

        QMetaObject::connectSlotsByName(CreateGraphDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateGraphDialog)
    {
        CreateGraphDialog->setWindowTitle(QApplication::translate("CreateGraphDialog", "Dialog", nullptr));
        btnCreateGraph->setText(QApplication::translate("CreateGraphDialog", "create graph", nullptr));
        btnCancel->setText(QApplication::translate("CreateGraphDialog", "cancel", nullptr));
        label_5->setText(QApplication::translate("CreateGraphDialog", "frequency (hertz)", nullptr));
        label_2->setText(QApplication::translate("CreateGraphDialog", "amplitude ", nullptr));
        label_6->setText(QApplication::translate("CreateGraphDialog", "y-axis maximum", nullptr));
        label_7->setText(QApplication::translate("CreateGraphDialog", "y-axis minimum", nullptr));
        label_8->setText(QApplication::translate("CreateGraphDialog", "Interval", nullptr));
        cbTypeGraph->setItemText(0, QApplication::translate("CreateGraphDialog", "line", nullptr));
        cbTypeGraph->setItemText(1, QApplication::translate("CreateGraphDialog", "scatterplot", nullptr));
        cbTypeGraph->setItemText(2, QApplication::translate("CreateGraphDialog", "histogram", nullptr));
        cbTypeGraph->setItemText(3, QApplication::translate("CreateGraphDialog", "bargraph", nullptr));

        cbTypeSensor->setItemText(0, QApplication::translate("CreateGraphDialog", "heartrate", nullptr));
        cbTypeSensor->setItemText(1, QApplication::translate("CreateGraphDialog", "accelerometer", nullptr));
        cbTypeSensor->setItemText(2, QApplication::translate("CreateGraphDialog", "skintemperature", nullptr));
        cbTypeSensor->setItemText(3, QApplication::translate("CreateGraphDialog", "lightsensor", nullptr));

        label_9->setText(QApplication::translate("CreateGraphDialog", "select graph", nullptr));
        label_10->setText(QApplication::translate("CreateGraphDialog", "select sensor", nullptr));
        label->setText(QApplication::translate("CreateGraphDialog", "Properties for QCustomPlot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateGraphDialog: public Ui_CreateGraphDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGRAPHDIALOG_H
