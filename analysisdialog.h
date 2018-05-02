#ifndef ANALYSISDIALOG_H
#define ANALYSISDIALOG_H

#include <QDialog>

namespace Ui {
class AnalysisDialog;
}

class AnalysisDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AnalysisDialog(QWidget *parent = 0);
    ~AnalysisDialog();

private:
    Ui::AnalysisDialog *ui;
};

#endif // ANALYSISDIALOG_H
