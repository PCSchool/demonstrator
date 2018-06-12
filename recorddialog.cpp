#include "recorddialog.h"
#include "ui_recorddialog.h";
#include <binarywriter.h>
#include <stdio.h>
#include <iostream>
#include <QMessageBox>
#include <QDir>
#include <QTime>
#include <QTextStream>
#include <globals.h>

using namespace std;

CRITICAL_SECTION shared_buffer_lock;

RecordDialog::RecordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecordDialog)
{
    ui->setupUi(this);
    ui->widget->setContextMenuPolicy(Qt::CustomContextMenu);  //open right click menu
    connect(ui->widget, SIGNAL(customContextMenuRequested(const QPoint&)),this, SLOT(showContextMenu(const QPoint&)));

    counter = 0;
    readySignal = 0;
    running = false;
    shared_buffer = new QByteArray[bufferSize];
    setProperties(frequencyDefault, amplitudeDefault, yAxisMaxDefault, yAxisMinDefault, xAxisMaxDefault, xAxisMinDefault, intervalDefault, graphDefault, sensorDefault);
    recording.changePosition(ui->widget->pos().x(), ui->widget->pos().y());
    recording.changeSize(ui->widget->size().width(), ui->widget->size().height());
}

//show right-click context menu + handles selection of the selecteditem of the menu
void RecordDialog::showContextMenu(const QPoint& pos){
    QPoint globalPos = ui->widget->mapToGlobal(pos);
    QMenu qmenu;
    qmenu.addAction("create graph");
    qmenu.addAction("exit");

    QAction* selectedItem = qmenu.exec(globalPos);
    if(selectedItem){
        CreateGraphDialog* graphDialog = new CreateGraphDialog(this);
        connect(graphDialog, SIGNAL(properties(double,double,int,int,int,int,int,QString,QString)), this, SLOT(setProperties(double,double,int,int,int,int,int,QString,QString)));
        graphDialog->setModal(true);
        graphDialog->exec();
    }
}

void RecordDialog::setProperties(double frequency, double amplitude, int yAxisMax, int yAxisMin, int xAxisMax, int xAxisMin, int interval, QString graph, QString sensor){
    recording.setProperties(frequency, amplitude, yAxisMax, yAxisMin, xAxisMax, xAxisMin, interval, graph, sensor);
    //connect(recording, SIGNAL(setProperties(frequency, amplitude, yAxisMax, yAxisMin, xAxisMax, xAxisMin, interval, graph, sensor)), this, SLOT());
    this->ui->lblAmplitude->setText(QString::number(amplitude));
    this->ui->lblFrequency->setText(QString::number(frequency));
    this->ui->lblInterval->setText(QString::number(interval));
    this->ui->lblSensor->setText(QString(sensor).toLower());
    this->ui->lblGraphType->setText(QString(graph).toLower());
    this->ui->lblYAxis->setText(("(" + QString::number(yAxisMin) + "," + QString::number(yAxisMax) + ")"));
}

void RecordDialog::setUserDir(QDir dir){
    userDir = recording.controlDir(dir);
    ui->lblTest->setText(userDir.path());
}

RecordDialog::~RecordDialog()
{
    //stop threads & wait for threads
    dataTimer->stop();
    writeBuffer->finished();   //  --> connected with thread to finish together
    while(threadWriteBuffer->isRunning()){
    }
    threadWriteBuffer->terminate();

    // delete critical sections, after ending threads
    DeleteCriticalSection(&shared_buffer_lock);
    delete ui;
}

void RecordDialog::on_btnDummyGraph_clicked()
{
    if(!running){
        ui->btnChangeSettings->setEnabled(false);
        ui->widget->clearGraphs();

        running = true;
        InitializeCriticalSection(&shared_buffer_lock);

        // Create graph
        ui->widget->addGraph(); // blue line
        ui->widget->graph(0)->setPen(QPen(QColor(40, 110, 255)));
        QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
        timeTicker->setTimeFormat("%h:%m:%s");
        ui->widget->xAxis->setTicker(timeTicker);
        ui->widget->axisRect()->setupFullAxesBox();
        ui->widget->yAxis->setRange(recording.getYAxisMax(), recording.getYAxisMin());

        // make left and bottom axes transfer their ranges to right and top axes:
        connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis2, SLOT(setRange(QCPRange)));
        connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis2, SLOT(setRange(QCPRange)));

        // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
        dataTimer = new QTimer();
        connect(dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
        connect(this, SIGNAL(stopTimer()), dataTimer, SLOT(stop()));
        dataTimer->start(recording.getInterval()); // Interval of 25

        // setup the thread responsible for writing data to the buffer
        threadWriteBuffer = new QThread();
        writeBuffer = new BinaryWriter();
        connect(writeBuffer, SIGNAL(finished()), threadWriteBuffer, SLOT(quit()));
        connect(writeBuffer, SIGNAL(finished()), writeBuffer, SLOT(deleteLater()));
        connect(threadWriteBuffer, SIGNAL(finished()), threadWriteBuffer, SLOT(deleteLater()));

        // setup the thread to write data from buffer to file
        QThread* threadWriteFile = new QThread();
        writeFile = new BinaryReader();

        //connect the threads with eachother and the plot
        connect(writeFile,SIGNAL(finished()), threadWriteFile, SLOT(quit()));
        connect(writeFile, SIGNAL(finished()), writeFile, SLOT(deleteLater()));
        connect(threadWriteFile, SIGNAL(finished()), threadWriteFile, SLOT(deleteLater()));
        connect(this, SIGNAL(writeNewData(double, double)), writeBuffer, SLOT(writeData(double, double)));
        connect(writeBuffer, SIGNAL(bufferFull(QByteArray, QVector<TimePointer>)), writeFile, SLOT(writeBufferToFile(QByteArray, QVector<TimePointer>)));

        //ensure the recording file gets written to the right directory
        writeBuffer->setUserDir(this->userDir);
        writeFile->setUserDir(this->userDir);

        //start threads
        threadWriteBuffer->start();
        threadWriteFile->start();

        //delete CriticalSection at end, when graph gets stopped -> ~RecordDialog
    }
}

void RecordDialog::realtimeDataSlot(){
    static QTime time(QTime::currentTime());
    double xAxis = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds

    static double lastPointKey = 0;
    if (xAxis-lastPointKey > 0.010) // at most add point every 20 ms
    {
      double yAxis = counter;
      counter++;
      if(counter >= 250){
          counter =0;
      }
      readySignal++;
      if(readySignal >= 5){
          emit writeNewData(xAxis, yAxis);
          readySignal = 0;
      }
      ui->widget->graph(0)->addData(xAxis, yAxis);
      lastPointKey = xAxis;
    }
    // make key axis range scroll with the data (at a constant range size of 20):
    ui->widget->xAxis->setRange(xAxis + 5, 20, Qt::AlignRight);
    ui->widget->replot();
}

void RecordDialog::on_btnStop_clicked()
{
    if(running){
        disconnect(dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
        disconnect(this, SIGNAL(stopTimer()), dataTimer, SLOT(stop()));
        disconnect(this, SIGNAL(writeNewData(double, double)), writeBuffer, SLOT(writeData(double, double)));
        disconnect(writeBuffer, SIGNAL(bufferFull(QByteArray)), writeFile, SLOT(writeBufferToFile(QByteArray)));
        running = false;
        ui->btnChangeSettings->setEnabled(true);
    }
}

void RecordDialog::on_btnChangeSettings_clicked()
{
    CreateGraphDialog* graphDialog = new CreateGraphDialog(this);
    connect(graphDialog, SIGNAL(properties(double,double,int,int,int,int,int,QString,QString)), this, SLOT(setProperties(double,double,int,int,int,int,int,QString,QString)));
    graphDialog->setProperties(recording.getFrequency(), recording.getAmplitude(), recording.getYAxisMax(), recording.getYAxisMin(), recording.getInterval(), recording.getGraphType(), recording.getSensor());
    graphDialog->setModal(true);
    graphDialog->exec();
}

void RecordDialog::on_sbCounter_valueChanged(const QString &arg1)
{
    int counterx = ui->sbCounter->value();
}
