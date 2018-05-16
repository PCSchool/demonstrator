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
    void setDir(QDir dir);

    /*QDataStream &operator<<(QDataStream &out,const TimePointer &tp){
        out << (quint64)tp.x;
        out << (quint64)tp.y;
        return out;
    }

    QDataStream &operator>>(QDataStream &in,TimePointer &tp){
        tp = TimePointer;
        in >> (quint64)tp.x;
        in >> (quint64)tp.y;
        return in;
    }*/

    friend QDataStream &operator<<(QDataStream &out,const TimePointer &tp);
    //read from file >> instream
    friend QDataStream &operator>>(QDataStream &in,TimePointer &tp);

signals:
    writeNewData(double newdata, double key);

private slots:
    void on_btnReadBinaryFile_clicked();

    void on_btnGenerate_clicked();

    void on_btnSelectRecording_clicked();


    void on_btnCancel_clicked();

    void on_btnSelectRecording_2_clicked();

    void on_btnPrintResult_clicked();

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
