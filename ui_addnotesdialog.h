/********************************************************************************
** Form generated from reading UI file 'addnotesdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNOTESDIALOG_H
#define UI_ADDNOTESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddNotesDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QTextEdit *tbTextRead;
    QLineEdit *tbText;

    void setupUi(QDialog *AddNotesDialog)
    {
        if (AddNotesDialog->objectName().isEmpty())
            AddNotesDialog->setObjectName(QStringLiteral("AddNotesDialog"));
        AddNotesDialog->resize(382, 267);
        buttonBox = new QDialogButtonBox(AddNotesDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(170, 220, 191, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(AddNotesDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 0, 371, 21));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        tbTextRead = new QTextEdit(AddNotesDialog);
        tbTextRead->setObjectName(QStringLiteral("tbTextRead"));
        tbTextRead->setGeometry(QRect(10, 30, 351, 131));
        tbText = new QLineEdit(AddNotesDialog);
        tbText->setObjectName(QStringLiteral("tbText"));
        tbText->setGeometry(QRect(10, 170, 351, 41));

        retranslateUi(AddNotesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddNotesDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddNotesDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddNotesDialog);
    } // setupUi

    void retranslateUi(QDialog *AddNotesDialog)
    {
        AddNotesDialog->setWindowTitle(QApplication::translate("AddNotesDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("AddNotesDialog", "Add text to notes of patient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddNotesDialog: public Ui_AddNotesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNOTESDIALOG_H
