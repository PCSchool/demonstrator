#ifndef EXPORTDIALOG_H
#define EXPORTDIALOG_H

#include <QDialog>
<<<<<<< HEAD
#include <QDir>
#include <models/exporting.h>
=======
>>>>>>> 62ffced7a03b4bcf911f1b212369ade8808337d3

namespace Ui {
class ExportDialog;
}

class ExportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExportDialog(QWidget *parent = 0);
    ~ExportDialog();

<<<<<<< HEAD
public slots:

    void prepare(QDir userPath, QDir exportPath);

private slots:
    void updateDialog(QDir userDir, QDir exportDir);

    void updateListBox(QStringList items);

    void on_btnCancel_clicked();

    void on_btnSelectPatient_clicked();

    void on_btnSelectExportFiles_clicked();

    void on_btnExport_clicked();


private:
    Ui::ExportDialog *ui;
    Exporting* exporting;
=======
private:
    Ui::ExportDialog *ui;
>>>>>>> 62ffced7a03b4bcf911f1b212369ade8808337d3
};

#endif // EXPORTDIALOG_H
