#include "creategraphdialog.h"
#include "ui_creategraphdialog.h"
#include <iostream>
#include <string>
#include <QDialog>

//connect creategraphdialog to parent plotdialog
/* 1. user open right-click diagram in plotdialog
 * 2. creategraph opens(right-click context menu) & user selects graph of choice
 * 3. creategraph closes, sends plotdialog info over selected graph
 */
CreateGraphDialog::CreateGraphDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateGraphDialog)
{
    ui->setupUi(this);
}

CreateGraphDialog::~CreateGraphDialog()
{
    delete ui;
}

void CreateGraphDialog::on_btnCreateGraph_clicked()
{
    double amplitude = ui->cbAmplitude->value();
    double frequency = ui->cbFrequency->value();
    int yAxisMax = static_cast<int>(ui->cbYAxisMax->value());
    int yAxisMin = static_cast<int>(ui->cbYAxisMin->value());
    int xAxisMax = 25;
    int xAxisMin = 0;
    int interval = ui->cbInterval->value();
    QString type = ui->cbTypeGraph->currentText();
    QString sensor = ui->cbTypeSensor->currentText();

    emit properties(frequency, amplitude, yAxisMax, yAxisMin, xAxisMax, xAxisMin, interval, type, sensor);
    on_btnCancel_clicked();
}

void CreateGraphDialog::on_btnCancel_clicked()
{
    //delete everything to keep memory clear :3
    delete ui;
}
