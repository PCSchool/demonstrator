/********************************************************************************
** Form generated from reading UI file 'exportdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTDIALOG_H
#define UI_EXPORTDIALOG_H

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

class Ui_ExportDialog
{
public:
    QLabel *label;
    QLabel *lblPathPatient;
    QLabel *lblPathFile;
    QListWidget *lbListItems;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *line;
    QLabel *label_4;
    QPushButton *btnCancel;
    QPushButton *btnExport;
    QPushButton *btnSelectExportFiles;
    QPushButton *btnSelectPatient;

    void setupUi(QDialog *ExportDialog)
    {
        if (ExportDialog->objectName().isEmpty())
            ExportDialog->setObjectName(QStringLiteral("ExportDialog"));
        ExportDialog->resize(693, 410);
        ExportDialog->setMinimumSize(QSize(450, 0));
        label = new QLabel(ExportDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 231, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        lblPathPatient = new QLabel(ExportDialog);
        lblPathPatient->setObjectName(QStringLiteral("lblPathPatient"));
        lblPathPatient->setGeometry(QRect(30, 320, 371, 16));
        lblPathFile = new QLabel(ExportDialog);
        lblPathFile->setObjectName(QStringLiteral("lblPathFile"));
        lblPathFile->setGeometry(QRect(30, 280, 671, 20));
        lbListItems = new QListWidget(ExportDialog);
        lbListItems->setObjectName(QStringLiteral("lbListItems"));
        lbListItems->setGeometry(QRect(20, 70, 551, 191));
        label_2 = new QLabel(ExportDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 50, 191, 16));
        label_3 = new QLabel(ExportDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 260, 61, 16));
        line = new QFrame(ExportDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 40, 801, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(ExportDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 300, 61, 16));
        btnCancel = new QPushButton(ExportDialog);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(320, 360, 141, 21));
        btnCancel->setMinimumSize(QSize(0, 0));
        btnExport = new QPushButton(ExportDialog);
        btnExport->setObjectName(QStringLiteral("btnExport"));
        btnExport->setGeometry(QRect(170, 360, 141, 21));
        btnExport->setMinimumSize(QSize(0, 0));
        btnSelectExportFiles = new QPushButton(ExportDialog);
        btnSelectExportFiles->setObjectName(QStringLiteral("btnSelectExportFiles"));
        btnSelectExportFiles->setGeometry(QRect(20, 360, 141, 21));
        btnSelectExportFiles->setMinimumSize(QSize(0, 0));
        btnSelectPatient = new QPushButton(ExportDialog);
        btnSelectPatient->setObjectName(QStringLiteral("btnSelectPatient"));
        btnSelectPatient->setGeometry(QRect(20, 340, 141, 21));
        btnSelectPatient->setMinimumSize(QSize(0, 0));

        retranslateUi(ExportDialog);

        QMetaObject::connectSlotsByName(ExportDialog);
    } // setupUi

    void retranslateUi(QDialog *ExportDialog)
    {
        ExportDialog->setWindowTitle(QApplication::translate("ExportDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("ExportDialog", "Export", nullptr));
        lblPathPatient->setText(QApplication::translate("ExportDialog", "C:/", nullptr));
        lblPathFile->setText(QApplication::translate("ExportDialog", "C:/", nullptr));
        label_2->setText(QApplication::translate("ExportDialog", "Recordings of patient", nullptr));
        label_3->setText(QApplication::translate("ExportDialog", "Export file:", nullptr));
        label_4->setText(QApplication::translate("ExportDialog", "Patient file:", nullptr));
        btnCancel->setText(QApplication::translate("ExportDialog", "Cancel", nullptr));
        btnExport->setText(QApplication::translate("ExportDialog", "export files", nullptr));
        btnSelectExportFiles->setText(QApplication::translate("ExportDialog", "Select export file", nullptr));
        btnSelectPatient->setText(QApplication::translate("ExportDialog", "select patient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExportDialog: public Ui_ExportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTDIALOG_H
