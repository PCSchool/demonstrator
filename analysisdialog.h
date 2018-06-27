#ifndef ANALYSISDIALOG_H
#define ANALYSISDIALOG_H

#include <QDialog>
#include <QBuffer>
#include <QDir>
#include <globals.h>
#include <models/analysis.h>
#include <qdatastream.h>
#include <QDataStream>
#include <models/graph.h>

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
    Graph graph;
    double convert(double *x, double y);

signals:

public slots:
    void drawGraph(QVector<TimePointer> vector);

private slots:
    void showContextMenu(const QPoint& pos);
    void on_btnCancel_clicked();
    void on_btnSelectRecording_clicked();
    void on_btnReadSpecificFile_clicked();
    void on_cbShowScale_stateChanged(int arg1);
    void on_cbShowLegend_stateChanged(int arg1);
    void on_cbMouseTrack_stateChanged(int arg1);
    void mouseMoveEvent(QMouseEvent *event);
    void on_cbDesign_currentIndexChanged(const QString &arg1);
    void on_cbFilter_currentIndexChanged(const QString &arg1);
    void on_btnScaleGraph_clicked();
    void on_btnFilterRecording_clicked();
    void on_btnAverage_clicked();

private:
    void enableButtons(bool active);
    //for testing data reading
    void showPointToolTip(QMouseEvent *event);
    QBuffer qbuffer;
    QTimer* timer;
    QString filter, design;
    QVector<TimePointer> points;
    int counter, index;
    int xAxis;
    QThread* threadWriteBuffer;
    QThread* threadWriteFile;
    QDir dir;
    Ui::AnalysisDialog *ui;
};

#endif // ANALYSISDIALOG_H
