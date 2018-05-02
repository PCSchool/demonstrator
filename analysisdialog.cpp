#include "analysisdialog.h"
#include "ui_analysisdialog.h"

AnalysisDialog::AnalysisDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnalysisDialog)
{
    ui->setupUi(this);
}

AnalysisDialog::~AnalysisDialog()
{
    delete ui;
}
