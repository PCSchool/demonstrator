#ifndef EXPORTDIALOG_H
#define EXPORTDIALOG_H

#include <QDialog>
#include <QDir>
#include <models/exporting.h>

namespace Ui {
class ExportDialog;
}

class ExportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExportDialog(QWidget *parent = 0);
    ~ExportDialog();

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
};

#endif // EXPORTDIALOG_H
