#ifndef RECORDDIALOG_H
#define RECORDDIALOG_H

#include <QDialog>
#include <screens/creategraphdialog.h>
#include <binarywriter.h>
#include <QString>
#include <models/recording.h>
#include <binaryreader.h>
#include <globals.h>

extern CRITICAL_SECTION shared_buffer_lock;

namespace Ui {
class RecordDialog;
}

class RecordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RecordDialog(QWidget *parent = 0);
    ~RecordDialog();
    void setUserDir(QDir dir);
    QDir userDir;
    static const QSemaphore semaphore;
    double counter, readySignal;
    QByteArray *shared_buffer;
    void setProperties(double frequency, double amplitude, int yAxisMax, int yAxisMin, int xAxisMax, int xAxisMin, int interval, QString graph, QString sensor);

signals:
    void writeNewData(double xAxis, double yAxis);
    void stopTimer();

private slots:
    void showContextMenu(const QPoint& pos);
    void realtimeDataSlot();
    void on_btnDummyGraph_clicked();
    void on_btnStop_clicked();
    void on_btnChangeSettings_clicked();
    void on_sbCounter_valueChanged(const QString &arg1);

private:
    Ui::RecordDialog *ui;
    QTimer* dataTimer;
    BinaryWriter* writeBuffer;
    BinaryReader* writeFile;
    bool running;
    QThread* threadWriteBuffer;
    Recording recording;
};

#endif // RECORDDIALOG_H
