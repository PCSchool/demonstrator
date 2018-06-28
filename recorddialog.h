#ifndef RECORDDIALOG_H
#define RECORDDIALOG_H

#include <QDialog>
#include <screens/creategraphdialog.h>
#include <QElapsedTimer>
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
    void clear();
    QDir userDir;
    static const QSemaphore semaphore;
    double counter, oldCounter, readySignal;
    QElapsedTimer qTimer, mainTimer;
    qint64 qAccumulator;
    QByteArray *shared_buffer;
    QTime time;
signals:
    void writeNewData(double xAxis, double yAxis);
    void stopTimer();
    void newCounterMax(int max);

private slots:
    void setProperties(double frequency, double amplitude, int yAxisMax, int yAxisMin, int xAxisMax, int xAxisMin, int interval, QString graph, QString sensor);
    void showContextMenu(const QPoint& pos);
    void realtimeDataSlot();
    void on_btnDummyGraph_clicked();
    void on_btnStop_clicked();
    void on_btnChangeSettings_clicked();
    void on_btnPause_clicked();
    void on_btnCancel_clicked();

    void setNewCounterMax(int max);
    void on_sbCounter_valueChanged(int arg1);

    void on_sbCounter_editingFinished();

private:
    void enableButtons(bool enable);
    void stopRecording();
    double lastPointKey;
    Ui::RecordDialog *ui;
    QTime frequencyTime;
    QTimer* dataTimer;
    int index;
    int counterMax, frequency;
    BinaryWriter* writeBuffer;
    BinaryReader* writeFile;
    bool running, pause;
    QThread* threadWriteBuffer;
    Recording recording;
};

#endif // RECORDDIALOG_H
