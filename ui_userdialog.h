/********************************************************************************
** Form generated from reading UI file 'userdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDIALOG_H
#define UI_USERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserDialog
{
public:
    QGroupBox *groupBox_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *lbl_name;
    QLineEdit *tbName;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QCheckBox *cbM;
    QCheckBox *cbV;
    QCheckBox *cbO;
    QLabel *label_13;
    QDateEdit *tbBirthDate;
    QLabel *label_8;
    QLineEdit *tbEmail;
    QLabel *label_3;
    QLineEdit *tbStreet;
    QLabel *label_4;
    QLineEdit *tbHouseNr;
    QLabel *label_5;
    QLineEdit *tbZipcode;
    QLabel *label_6;
    QLineEdit *tbHomephone;
    QLabel *label_11;
    QDoubleSpinBox *spHeight;
    QLabel *label_10;
    QDoubleSpinBox *spWeight;
    QLabel *label_2;
    QFrame *line;
    QPushButton *btnRegister;
    QPushButton *btnSelectPatient;
    QPushButton *btnCancel;
    QPushButton *btnDeletePatient;

    void setupUi(QDialog *UserDialog)
    {
        if (UserDialog->objectName().isEmpty())
            UserDialog->setObjectName(QStringLiteral("UserDialog"));
        UserDialog->resize(572, 424);
        UserDialog->setMinimumSize(QSize(440, 350));
        groupBox_2 = new QGroupBox(UserDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 561, 411));
        formLayoutWidget = new QWidget(groupBox_2);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 60, 551, 271));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        lbl_name = new QLabel(formLayoutWidget);
        lbl_name->setObjectName(QStringLiteral("lbl_name"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lbl_name);

        tbName = new QLineEdit(formLayoutWidget);
        tbName->setObjectName(QStringLiteral("tbName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, tbName);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cbM = new QCheckBox(formLayoutWidget);
        cbM->setObjectName(QStringLiteral("cbM"));
        cbM->setChecked(false);

        horizontalLayout->addWidget(cbM);

        cbV = new QCheckBox(formLayoutWidget);
        cbV->setObjectName(QStringLiteral("cbV"));

        horizontalLayout->addWidget(cbV);

        cbO = new QCheckBox(formLayoutWidget);
        cbO->setObjectName(QStringLiteral("cbO"));
        cbO->setChecked(true);

        horizontalLayout->addWidget(cbO);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout);

        label_13 = new QLabel(formLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_13);

        tbBirthDate = new QDateEdit(formLayoutWidget);
        tbBirthDate->setObjectName(QStringLiteral("tbBirthDate"));

        formLayout->setWidget(2, QFormLayout::FieldRole, tbBirthDate);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_8);

        tbEmail = new QLineEdit(formLayoutWidget);
        tbEmail->setObjectName(QStringLiteral("tbEmail"));

        formLayout->setWidget(3, QFormLayout::FieldRole, tbEmail);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        tbStreet = new QLineEdit(formLayoutWidget);
        tbStreet->setObjectName(QStringLiteral("tbStreet"));

        formLayout->setWidget(4, QFormLayout::FieldRole, tbStreet);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_4);

        tbHouseNr = new QLineEdit(formLayoutWidget);
        tbHouseNr->setObjectName(QStringLiteral("tbHouseNr"));

        formLayout->setWidget(5, QFormLayout::FieldRole, tbHouseNr);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_5);

        tbZipcode = new QLineEdit(formLayoutWidget);
        tbZipcode->setObjectName(QStringLiteral("tbZipcode"));

        formLayout->setWidget(6, QFormLayout::FieldRole, tbZipcode);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_6);

        tbHomephone = new QLineEdit(formLayoutWidget);
        tbHomephone->setObjectName(QStringLiteral("tbHomephone"));

        formLayout->setWidget(7, QFormLayout::FieldRole, tbHomephone);

        label_11 = new QLabel(formLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_11);

        spHeight = new QDoubleSpinBox(formLayoutWidget);
        spHeight->setObjectName(QStringLiteral("spHeight"));
        spHeight->setDecimals(0);
        spHeight->setMaximum(250);
        spHeight->setSingleStep(0.1);
        spHeight->setValue(150);

        formLayout->setWidget(8, QFormLayout::FieldRole, spHeight);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_10);

        spWeight = new QDoubleSpinBox(formLayoutWidget);
        spWeight->setObjectName(QStringLiteral("spWeight"));
        spWeight->setDecimals(0);
        spWeight->setMaximum(500);
        spWeight->setSingleStep(0.1);
        spWeight->setValue(50);

        formLayout->setWidget(9, QFormLayout::FieldRole, spWeight);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 681, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        line = new QFrame(groupBox_2);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(7, 40, 531, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        btnRegister = new QPushButton(groupBox_2);
        btnRegister->setObjectName(QStringLiteral("btnRegister"));
        btnRegister->setGeometry(QRect(10, 340, 191, 31));
        btnRegister->setMinimumSize(QSize(0, 0));
        btnSelectPatient = new QPushButton(groupBox_2);
        btnSelectPatient->setObjectName(QStringLiteral("btnSelectPatient"));
        btnSelectPatient->setGeometry(QRect(210, 340, 191, 31));
        btnSelectPatient->setMinimumSize(QSize(0, 0));
        btnCancel = new QPushButton(groupBox_2);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(10, 370, 191, 31));
        btnCancel->setMinimumSize(QSize(0, 0));
        btnDeletePatient = new QPushButton(groupBox_2);
        btnDeletePatient->setObjectName(QStringLiteral("btnDeletePatient"));
        btnDeletePatient->setGeometry(QRect(210, 370, 191, 31));
        btnDeletePatient->setMinimumSize(QSize(0, 0));
        QWidget::setTabOrder(tbName, cbM);
        QWidget::setTabOrder(cbM, cbV);
        QWidget::setTabOrder(cbV, cbO);
        QWidget::setTabOrder(cbO, tbBirthDate);
        QWidget::setTabOrder(tbBirthDate, tbEmail);
        QWidget::setTabOrder(tbEmail, tbStreet);
        QWidget::setTabOrder(tbStreet, tbHouseNr);
        QWidget::setTabOrder(tbHouseNr, tbZipcode);
        QWidget::setTabOrder(tbZipcode, tbHomephone);
        QWidget::setTabOrder(tbHomephone, spHeight);
        QWidget::setTabOrder(spHeight, spWeight);
        QWidget::setTabOrder(spWeight, btnRegister);
        QWidget::setTabOrder(btnRegister, btnSelectPatient);
        QWidget::setTabOrder(btnSelectPatient, btnCancel);

        retranslateUi(UserDialog);

        QMetaObject::connectSlotsByName(UserDialog);
    } // setupUi

    void retranslateUi(QDialog *UserDialog)
    {
        UserDialog->setWindowTitle(QApplication::translate("UserDialog", "Dialog", nullptr));
        groupBox_2->setTitle(QString());
        lbl_name->setText(QApplication::translate("UserDialog", "name", nullptr));
        label->setText(QApplication::translate("UserDialog", "gender", nullptr));
        cbM->setText(QApplication::translate("UserDialog", "Male", nullptr));
        cbV->setText(QApplication::translate("UserDialog", "Female", nullptr));
        cbO->setText(QApplication::translate("UserDialog", "Unknown", nullptr));
        label_13->setText(QApplication::translate("UserDialog", "birthdate", nullptr));
        label_8->setText(QApplication::translate("UserDialog", "email", nullptr));
        label_3->setText(QApplication::translate("UserDialog", "street", nullptr));
        label_4->setText(QApplication::translate("UserDialog", "nr", nullptr));
        tbHouseNr->setText(QString());
        label_5->setText(QApplication::translate("UserDialog", "zipcode", nullptr));
        label_6->setText(QApplication::translate("UserDialog", "home phone", nullptr));
        label_11->setText(QApplication::translate("UserDialog", "height in cm", nullptr));
        label_10->setText(QApplication::translate("UserDialog", "weight in kg", nullptr));
        label_2->setText(QApplication::translate("UserDialog", "Register form", nullptr));
        btnRegister->setText(QApplication::translate("UserDialog", "Register", nullptr));
        btnSelectPatient->setText(QApplication::translate("UserDialog", "Select patient", nullptr));
        btnCancel->setText(QApplication::translate("UserDialog", "Back", nullptr));
        btnDeletePatient->setText(QApplication::translate("UserDialog", "Delete patient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserDialog: public Ui_UserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDIALOG_H
