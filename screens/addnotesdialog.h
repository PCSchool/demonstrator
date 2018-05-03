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

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

signals:
    void textToNotes(QString text);

private:
    Ui::AddNotesDialog *ui;
};

#endif // ADDNOTESDIALOG_H
