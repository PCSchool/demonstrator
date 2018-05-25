#ifndef ANALYSISDIALOG_H
#define ANALYSISDIALOG_H

#include <QDialog>
#include <QBuffer>
#include <QDir>
#include <globals.h>
#include <models/analysis.h>
#include <qdatastream.h>
#include <QDataStream>

namespace Ui {
class AnalysisDialog;
}

class AnalysisDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AnalysisDialog(QWidget *parent = 0);
    ~AnalysisDialog();
    Analysis analysis;
    double transfer(quint64 number);
    QList<TimePointer> tpList;
    void setDir(QDir dir);
    friend QDataStream &operator<<(QDataStream &out,const TimePointer &tp);
    friend QDataStream &operator>>(QDataStream &in,TimePointer &tp);

signals:

public slots:
    void drawGraph(QVector<TimePointer> vector);

private slots:
    void on_btnReadBinaryFile_clicked();

    void on_btnCancel_clicked();

    void on_btnSelectRecording_clicked();

    void on_btnReadSpecificFile_clicked();

private:
    //for testing data reading
    QBuffer qbuffer;
    QTimer* timer;
    int counter;
    int xAxis;
    QThread* threadWriteBuffer;
    QThread* threadWriteFile;
    void randomize();
    QDir dir;
    Ui::AnalysisDialog *ui;
};

#endif // ANALYSISDIALOG_H
