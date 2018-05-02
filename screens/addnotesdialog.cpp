#include "addnotesdialog.h"
#include "ui_addnotesdialog.h"

AddNotesDialog::AddNotesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNotesDialog)
{
    ui->setupUi(this);
}

AddNotesDialog::~AddNotesDialog()
{
    delete ui;
}
