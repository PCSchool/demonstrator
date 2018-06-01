/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QGroupBox *gbMenu;
    QPushButton *btnOpenPatientDialog;
    QPushButton *btnOpenDeviceDialog;
    QPushButton *btnOpenRecordingDialog;
    QPushButton *btnOpenAnalysisDialog;
    QPushButton *btnOpenExportDialog;
    QGroupBox *gbInfoPatient;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *lblNamePatient;
    QLabel *label_6;
    QLabel *lblEmail;
    QLabel *label_3;
    QLabel *lblGenderPatient;
    QLabel *label_4;
    QLabel *lblBirthDatePatient;
    QLabel *label_7;
    QLabel *lblPhone;
    QLabel *label_8;
    QLabel *lblHeight;
    QLabel *label_9;
    QLabel *lblWeight;
    QLabel *label_10;
    QLabel *lblBMI;
    QLabel *label_5;
    QFrame *lineInfoPatient;
    QPushButton *btnSelectDirPatient;
    QPushButton *btnnAddNotes;
    QPushButton *btnChangePatient;
    QFrame *lineInfoPatient_2;
    QFrame *line;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(997, 640);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 640));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 941, 81));
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        gbMenu = new QGroupBox(centralWidget);
        gbMenu->setObjectName(QStringLiteral("gbMenu"));
        gbMenu->setEnabled(true);
        gbMenu->setGeometry(QRect(170, 130, 401, 331));
        btnOpenPatientDialog = new QPushButton(gbMenu);
        btnOpenPatientDialog->setObjectName(QStringLiteral("btnOpenPatientDialog"));
        btnOpenPatientDialog->setGeometry(QRect(50, 20, 300, 51));
        btnOpenPatientDialog->setMinimumSize(QSize(300, 50));
        btnOpenDeviceDialog = new QPushButton(gbMenu);
        btnOpenDeviceDialog->setObjectName(QStringLiteral("btnOpenDeviceDialog"));
        btnOpenDeviceDialog->setGeometry(QRect(50, 80, 300, 50));
        btnOpenDeviceDialog->setMinimumSize(QSize(300, 50));
        btnOpenRecordingDialog = new QPushButton(gbMenu);
        btnOpenRecordingDialog->setObjectName(QStringLiteral("btnOpenRecordingDialog"));
        btnOpenRecordingDialog->setGeometry(QRect(50, 140, 300, 50));
        btnOpenRecordingDialog->setMinimumSize(QSize(300, 50));
        btnOpenAnalysisDialog = new QPushButton(gbMenu);
        btnOpenAnalysisDialog->setObjectName(QStringLiteral("btnOpenAnalysisDialog"));
        btnOpenAnalysisDialog->setGeometry(QRect(50, 200, 300, 50));
        btnOpenAnalysisDialog->setMinimumSize(QSize(200, 50));
        btnOpenExportDialog = new QPushButton(gbMenu);
        btnOpenExportDialog->setObjectName(QStringLiteral("btnOpenExportDialog"));
        btnOpenExportDialog->setGeometry(QRect(50, 260, 300, 50));
        btnOpenExportDialog->setMinimumSize(QSize(300, 50));
        gbInfoPatient = new QGroupBox(centralWidget);
        gbInfoPatient->setObjectName(QStringLiteral("gbInfoPatient"));
        gbInfoPatient->setGeometry(QRect(620, 130, 341, 271));
        formLayoutWidget = new QWidget(gbInfoPatient);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 50, 301, 161));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lblNamePatient = new QLabel(formLayoutWidget);
        lblNamePatient->setObjectName(QStringLiteral("lblNamePatient"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lblNamePatient);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        lblEmail = new QLabel(formLayoutWidget);
        lblEmail->setObjectName(QStringLiteral("lblEmail"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lblEmail);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lblGenderPatient = new QLabel(formLayoutWidget);
        lblGenderPatient->setObjectName(QStringLiteral("lblGenderPatient"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lblGenderPatient);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lblBirthDatePatient = new QLabel(formLayoutWidget);
        lblBirthDatePatient->setObjectName(QStringLiteral("lblBirthDatePatient"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lblBirthDatePatient);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        lblPhone = new QLabel(formLayoutWidget);
        lblPhone->setObjectName(QStringLiteral("lblPhone"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lblPhone);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_8);

        lblHeight = new QLabel(formLayoutWidget);
        lblHeight->setObjectName(QStringLiteral("lblHeight"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lblHeight);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_9);

        lblWeight = new QLabel(formLayoutWidget);
        lblWeight->setObjectName(QStringLiteral("lblWeight"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lblWeight);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_10);

        lblBMI = new QLabel(formLayoutWidget);
        lblBMI->setObjectName(QStringLiteral("lblBMI"));

        formLayout->setWidget(7, QFormLayout::FieldRole, lblBMI);

        label_5 = new QLabel(gbInfoPatient);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 10, 171, 21));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_5->setFont(font1);
        lineInfoPatient = new QFrame(gbInfoPatient);
        lineInfoPatient->setObjectName(QStringLiteral("lineInfoPatient"));
        lineInfoPatient->setGeometry(QRect(20, 30, 301, 20));
        lineInfoPatient->setFrameShape(QFrame::HLine);
        lineInfoPatient->setFrameShadow(QFrame::Sunken);
        btnSelectDirPatient = new QPushButton(gbInfoPatient);
        btnSelectDirPatient->setObjectName(QStringLiteral("btnSelectDirPatient"));
        btnSelectDirPatient->setGeometry(QRect(20, 220, 100, 30));
        btnSelectDirPatient->setMinimumSize(QSize(100, 30));
        btnnAddNotes = new QPushButton(gbInfoPatient);
        btnnAddNotes->setObjectName(QStringLiteral("btnnAddNotes"));
        btnnAddNotes->setGeometry(QRect(120, 220, 100, 30));
        btnnAddNotes->setMinimumSize(QSize(100, 30));
        btnnAddNotes->setMaximumSize(QSize(200, 30));
        btnChangePatient = new QPushButton(gbInfoPatient);
        btnChangePatient->setObjectName(QStringLiteral("btnChangePatient"));
        btnChangePatient->setGeometry(QRect(220, 220, 100, 30));
        btnChangePatient->setMinimumSize(QSize(100, 30));
        btnChangePatient->setMaximumSize(QSize(150, 30));
        lineInfoPatient_2 = new QFrame(gbInfoPatient);
        lineInfoPatient_2->setObjectName(QStringLiteral("lineInfoPatient_2"));
        lineInfoPatient_2->setGeometry(QRect(20, 210, 301, 20));
        lineInfoPatient_2->setFrameShape(QFrame::HLine);
        lineInfoPatient_2->setFrameShadow(QFrame::Sunken);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 90, 971, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 997, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "Sleep signal demonstrator", nullptr));
        gbMenu->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        btnOpenPatientDialog->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btnOpenPatientDialog->setText(QApplication::translate("MainWindow", "Select patient", nullptr));
#ifndef QT_NO_TOOLTIP
        btnOpenDeviceDialog->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btnOpenDeviceDialog->setText(QApplication::translate("MainWindow", "Device", nullptr));
#ifndef QT_NO_TOOLTIP
        btnOpenRecordingDialog->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btnOpenRecordingDialog->setText(QApplication::translate("MainWindow", "Recording", nullptr));
#ifndef QT_NO_TOOLTIP
        btnOpenAnalysisDialog->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btnOpenAnalysisDialog->setText(QApplication::translate("MainWindow", "Analysis", nullptr));
#ifndef QT_NO_TOOLTIP
        btnOpenExportDialog->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btnOpenExportDialog->setText(QApplication::translate("MainWindow", "Export", nullptr));
#ifndef QT_NO_TOOLTIP
        gbInfoPatient->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        gbInfoPatient->setTitle(QString());
        label_2->setText(QApplication::translate("MainWindow", "Name:", nullptr));
        lblNamePatient->setText(QApplication::translate("MainWindow", "name patient...", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Email:", nullptr));
        lblEmail->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Gender:", nullptr));
        lblGenderPatient->setText(QApplication::translate("MainWindow", "o", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "BirthDate:", nullptr));
        lblBirthDatePatient->setText(QApplication::translate("MainWindow", "12-12-2012", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Phone:", nullptr));
        lblPhone->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "Height:", nullptr));
        lblHeight->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "Weight:", nullptr));
        lblWeight->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "BMI:", nullptr));
        lblBMI->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Information patient", nullptr));
        btnSelectDirPatient->setText(QApplication::translate("MainWindow", "Directory patient", nullptr));
        btnnAddNotes->setText(QApplication::translate("MainWindow", "Add notes", nullptr));
        btnChangePatient->setText(QApplication::translate("MainWindow", "Change patient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
