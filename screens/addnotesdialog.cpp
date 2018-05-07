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

void AddNotesDialog::on_buttonBox_accepted()
{
    emit(textToNotes(ui->tbText->text()));
}

void AddNotesDialog::on_buttonBox_rejected()
{
    delete ui;
}


void AddNotesDialog::on_btnOpenNotes_clicked()
{
    emit(openNotes());
}
