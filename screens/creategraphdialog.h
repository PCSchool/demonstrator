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
    setProperties(double frequency, double amplitude, int yAxisMax, int yAxisMin, int interval, QString graph, QString sensor);
signals:
    void properties(double frequency, double amplitude, int yAxisMax, int yAxisMin, int xAxisMax,int xAxisMin, int interval, QString graph, QString sensor);

private slots:
    void on_btnCreateGraph_clicked();
    void on_btnCancel_clicked();

private:
    Ui::CreateGraphDialog *ui;
};

#endif // CREATEGRAPHDIALOG_H
