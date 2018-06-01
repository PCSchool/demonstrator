/********************************************************************************
** Form generated from reading UI file 'analysisdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYSISDIALOG_H
#define UI_ANALYSISDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_AnalysisDialog
{
public:
    QCustomPlot *widget;
    QGroupBox *groupBox;
    QPushButton *btnCancel;
    QPushButton *btnReadBinaryFile;
    QPushButton *btnSelectRecording;
    QPushButton *btnReadSpecificFile;
    QFrame *line;
    QLabel *label;
    QFrame *line_2;
    QRadioButton *rbtnPrintResults;
    QPushButton *btnReadBinaryFile_2;
    QPushButton *btnFilterRecording;
    QComboBox *cbFilter;
    QComboBox *cbPass;

    void setupUi(QDialog *AnalysisDialog)
    {
        if (AnalysisDialog->objectName().isEmpty())
            AnalysisDialog->setObjectName(QStringLiteral("AnalysisDialog"));
        AnalysisDialog->resize(1091, 604);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AnalysisDialog->sizePolicy().hasHeightForWidth());
        AnalysisDialog->setSizePolicy(sizePolicy);
        AnalysisDialog->setMinimumSize(QSize(200, 75));
        widget = new QCustomPlot(AnalysisDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(260, 10, 821, 441));
        groupBox = new QGroupBox(AnalysisDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 250, 600));
        groupBox->setMinimumSize(QSize(250, 600));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        btnCancel = new QPushButton(groupBox);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(20, 460, 200, 50));
        btnCancel->setMinimumSize(QSize(200, 50));
        btnCancel->setFont(font);
        btnReadBinaryFile = new QPushButton(groupBox);
        btnReadBinaryFile->setObjectName(QStringLiteral("btnReadBinaryFile"));
        btnReadBinaryFile->setGeometry(QRect(20, 220, 200, 50));
        btnReadBinaryFile->setMinimumSize(QSize(200, 50));
        btnReadBinaryFile->setFont(font);
        btnSelectRecording = new QPushButton(groupBox);
        btnSelectRecording->setObjectName(QStringLiteral("btnSelectRecording"));
        btnSelectRecording->setGeometry(QRect(20, 340, 201, 51));
        btnSelectRecording->setMinimumSize(QSize(200, 50));
        btnSelectRecording->setFont(font);
        btnReadSpecificFile = new QPushButton(groupBox);
        btnReadSpecificFile->setObjectName(QStringLiteral("btnReadSpecificFile"));
        btnReadSpecificFile->setGeometry(QRect(20, 280, 201, 51));
        btnReadSpecificFile->setMinimumSize(QSize(200, 50));
        btnReadSpecificFile->setFont(font);
        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 140, 201, 16));
        line->setFont(font);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 131, 16));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(20, 30, 201, 16));
        line_2->setFont(font);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        rbtnPrintResults = new QRadioButton(groupBox);
        rbtnPrintResults->setObjectName(QStringLiteral("rbtnPrintResults"));
        rbtnPrintResults->setGeometry(QRect(20, 50, 191, 17));
        btnReadBinaryFile_2 = new QPushButton(groupBox);
        btnReadBinaryFile_2->setObjectName(QStringLiteral("btnReadBinaryFile_2"));
        btnReadBinaryFile_2->setGeometry(QRect(20, 160, 200, 50));
        btnReadBinaryFile_2->setMinimumSize(QSize(200, 50));
        btnReadBinaryFile_2->setFont(font);
        btnFilterRecording = new QPushButton(groupBox);
        btnFilterRecording->setObjectName(QStringLiteral("btnFilterRecording"));
        btnFilterRecording->setGeometry(QRect(20, 400, 201, 51));
        btnFilterRecording->setMinimumSize(QSize(200, 50));
        btnFilterRecording->setFont(font);
        cbFilter = new QComboBox(groupBox);
        cbFilter->addItem(QString());
        cbFilter->addItem(QString());
        cbFilter->addItem(QString());
        cbFilter->setObjectName(QStringLiteral("cbFilter"));
        cbFilter->setGeometry(QRect(20, 70, 201, 22));
        cbPass = new QComboBox(groupBox);
        cbPass->addItem(QString());
        cbPass->addItem(QString());
        cbPass->addItem(QString());
        cbPass->addItem(QString());
        cbPass->setObjectName(QStringLiteral("cbPass"));
        cbPass->setGeometry(QRect(20, 100, 201, 22));

        retranslateUi(AnalysisDialog);

        QMetaObject::connectSlotsByName(AnalysisDialog);
    } // setupUi

    void retranslateUi(QDialog *AnalysisDialog)
    {
        AnalysisDialog->setWindowTitle(QApplication::translate("AnalysisDialog", "Dialog", nullptr));
        groupBox->setTitle(QString());
        btnCancel->setText(QApplication::translate("AnalysisDialog", "Back", nullptr));
        btnReadBinaryFile->setText(QApplication::translate("AnalysisDialog", "Read recording", nullptr));
        btnSelectRecording->setText(QApplication::translate("AnalysisDialog", "Read whole recording", nullptr));
        btnReadSpecificFile->setText(QApplication::translate("AnalysisDialog", "Read specific file", nullptr));
        label->setText(QApplication::translate("AnalysisDialog", "Controls:", nullptr));
        rbtnPrintResults->setText(QApplication::translate("AnalysisDialog", "Print points", nullptr));
        btnReadBinaryFile_2->setText(QApplication::translate("AnalysisDialog", "Clear graph", nullptr));
        btnFilterRecording->setText(QApplication::translate("AnalysisDialog", "Filter recording", nullptr));
        cbFilter->setItemText(0, QApplication::translate("AnalysisDialog", "butterworth", nullptr));
        cbFilter->setItemText(1, QApplication::translate("AnalysisDialog", "bessel", nullptr));
        cbFilter->setItemText(2, QApplication::translate("AnalysisDialog", "chebyshev", nullptr));

        cbPass->setItemText(0, QApplication::translate("AnalysisDialog", "low-pass", nullptr));
        cbPass->setItemText(1, QApplication::translate("AnalysisDialog", "high-pass", nullptr));
        cbPass->setItemText(2, QApplication::translate("AnalysisDialog", "band-pass", nullptr));
        cbPass->setItemText(3, QApplication::translate("AnalysisDialog", "band-stop", nullptr));

    } // retranslateUi

};

namespace Ui {
    class AnalysisDialog: public Ui_AnalysisDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYSISDIALOG_H
