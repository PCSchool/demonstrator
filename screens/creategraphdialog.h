#ifndef CREATEGRAPHDIALOG_H
#define CREATEGRAPHDIALOG_H

#include <QDialog>

namespace Ui {
class CreateGraphDialog;
}

class CreateGraphDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateGraphDialog(QWidget *parent = 0);
    ~CreateGraphDialog();
signals:
    void createGraphSignal(double frequency, double amplitude, QString graph, QString sensor, int duration);

private slots:
    void on_btnCreateGraph_clicked();
    void on_btnCancel_clicked();

private:
    Ui::CreateGraphDialog *ui;
};

#endif // CREATEGRAPHDIALOG_H
