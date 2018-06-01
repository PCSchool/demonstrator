#ifndef ADDNOTESDIALOG_H
#define ADDNOTESDIALOG_H

#include <QDialog>
<<<<<<< HEAD
#include <QFile>
=======
>>>>>>> 62ffced7a03b4bcf911f1b212369ade8808337d3

namespace Ui {
class AddNotesDialog;
}

class AddNotesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNotesDialog(QWidget *parent = 0);
    ~AddNotesDialog();
<<<<<<< HEAD
    void setFile(QString path);
    QFile file;
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

signals:
    void textToNotes(QString text);
    void openNotes();

private:
    Ui::AddNotesDialog *ui;

=======

private:
    Ui::AddNotesDialog *ui;
>>>>>>> 62ffced7a03b4bcf911f1b212369ade8808337d3
};

#endif // ADDNOTESDIALOG_H
