#ifndef ADDNOTESDIALOG_H
#define ADDNOTESDIALOG_H

#include <QDialog>

namespace Ui {
class AddNotesDialog;
}

class AddNotesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNotesDialog(QWidget *parent = 0);
    ~AddNotesDialog();

private:
    Ui::AddNotesDialog *ui;
};

#endif // ADDNOTESDIALOG_H
