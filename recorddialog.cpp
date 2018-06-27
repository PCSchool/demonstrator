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
#include <qcustomplot.h>
#include <models/plot.h>

using namespace std;

CRITICAL_SECTION shared_buffer_lock;

RecordDialog::RecordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecordDialog)
{
    ui->setupUi(this);
    //ui->widget->plotLayout()->clear();
    ui->widget->setContextMenuPolicy(Qt::CustomContextMenu);  //open right click menu
    connect(ui->widget, SIGNAL(customContextMenuRequested(const QPoint&)),this, SLOT(showContextMenu(const QPoint&)));
    connect(this, SIGNAL(newCounterMax(int)), this, SLOT(setNewCounterMax(int)));
    if(time.isValid()){time.restart();}
    if(mainTimer.isValid()){
        mainTimer.restart();
    }
    //default frequency =  1/65'2 = 4,225
    //method to calculate and show freq will be added soon
    counter = 0;index = 0; readySignal = 0; counterMax = 250;
    running = false; pause = false;
    shared_buffer = new QByteArray[bufferSize];
    setProperties(frequencyDefault, amplitudeDefault, yAxisMaxDefault, yAxisMinDefault, xAxisMaxDefault, xAxisMinDefault, intervalDefault, graphDefault, sensorDefault);
    recording.changePosition(ui->widget->pos().x(), ui->widget->pos().y());
    recording.changeSize(ui->widget->size().width(), ui->widget->size().height());
}

void RecordDialog::clear(){
    //ui->widget->clearGraphs();
    for(int g=0; g < ui->widget->graphCount(); g++){
        ui->widget->graph(g)->data().data()->clear();
    }
    ui->widget->clearGraphs();
    lastPointKey = 0; counter = 0; readySignal = 0;

    //empty current recording directory
    this->userDir.setNameFilters(QStringList() << "*.*");
    this->userDir.setFilter(QDir::Files);
    foreach(QString dirfile, this->userDir.entryList()){
        this->userDir.remove(dirfile);
    }

    //clear threads, stop them
    //stopRecording();

    //clear file, delete file and then create again
    ui->widget->replot();
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

void RecordDialog::stopRecording(){
    //stop threads & wait for threads
    dataTimer->stop();
    writeBuffer->finished();   //  --> connected with thread to finish together
    writeFile->finished();
    // delete critical sections, after ending threads
    DeleteCriticalSection(&shared_buffer_lock);
}

RecordDialog::~RecordDialog()
{  
    stopRecording();
    delete ui;
    delete this;
}

void RecordDialog::enableButtons(bool enable){
    ui->btnChangeSettings->setEnabled(enable);
    ui->btnDummyGraph->setEnabled(enable);
}

void RecordDialog::on_btnDummyGraph_clicked()
{
    if(!running){
        //clear current recording


        if(ui->widget->graphCount() != 0){
            clear();
        }
        enableButtons(false);

        int db = ui->widget->graphCount();
        ui->lblGraphType->setText(QString::number(db));

        running = true;
        InitializeCriticalSection(&shared_buffer_lock);

        // Create graph
        index = ui->widget->graphCount();
        ui->lblAmplitude->setText(QString::number(index));
        //QCPGraph *g = new QCPGraph(ui->widget->xAxis, ui->widget->yAxis);

        ui->widget->addGraph();
        ui->widget->graph(index)->setPen(QPen(QColor(40, 140, 80)));
        ui->widget->graph(index)->setName("Recording");

        QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
        timeTicker->setTimeFormat("%h:%m:%s");
        ui->widget->xAxis->setTicker(timeTicker);
        ui->widget->axisRect()->setupFullAxesBox();
        ui->widget->yAxis->setRange(recording.getYAxisMax(), recording.getYAxisMin());
        ui->widget->xAxis->setLabel("Time - format hh:mm::ss");
        ui->widget->yAxis->setLabel("Amount ");
        ui->widget->setMouseTracking(true);
        ui->widget->setBackgroundScaled(true);


        // make left and bottom axes transfer their ranges to right and top axes:
        connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis2, SLOT(setRange(QCPRange)));
        connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis2, SLOT(setRange(QCPRange)));

        // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
        dataTimer = new QTimer();
        connect(dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
        connect(this, SIGNAL(stopTimer()), dataTimer, SLOT(stop()));
        dataTimer->start(recording.getInterval()); // Interval of 25

        qTimer.start();
        mainTimer.start();
        if(time.isValid()){time.restart();}else{time.start();}
        qAccumulator = 0;

        // setup the thread responsible for writing data to the buffer
        threadWriteBuffer = new QThread();
        writeBuffer = new BinaryWriter();
        //writeBuffer->moveToThread(threadWriteBuffer);

        connect(writeBuffer, SIGNAL(finished()), threadWriteBuffer, SLOT(quit()));
        connect(writeBuffer, SIGNAL(finished()), writeBuffer, SLOT(deleteLater()));
        connect(threadWriteBuffer, SIGNAL(finished()), threadWriteBuffer, SLOT(deleteLater()));

        // setup the thread to write data from buffer to file
        QThread* threadWriteFile = new QThread();
        writeFile = new BinaryReader();
        //writeFile->moveToThread(threadWriteFile);

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
    double xAxis;
    if(pause){
        QTime qtime;
        qAccumulator += qTimer.elapsed();
        qtime.addMSecs(qAccumulator);
        xAxis = qtime.elapsed()/1000.0;
    }else{
        //static QTime time(QTime::currentTime());
        xAxis = time.elapsed()/1000.0;
        QTime qtime;
        qtime.addMSecs(qAccumulator);
    }
    //double xAxis = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    if (xAxis-lastPointKey > 0.010 && !pause) // at most add point every 20 ms
    {
      double yAxis = counter;

      //check positive or negative
      if(counterMax < 0){
          counter--;
          if(counter <= counterMax){
              counter =0;
          }
          ui->widget->yAxis->setRange(50, counterMax - 50);
      }else{
          counter++;
          if(counter >= counterMax){
              counter =0;
          }
          ui->widget->yAxis->setRange(-50, counterMax + 50);
      }

      readySignal++;
      if(readySignal >= 5){
          emit writeNewData(xAxis, yAxis);
          readySignal = 0;
      }
      ui->widget->graph(index)->addData(xAxis, yAxis);
      lastPointKey = xAxis;
    }
    // make key axis range scroll with the data (at a constant range size of 20):
    //ui->widget->yAxis->rescale(true);


    ui->widget->xAxis->setRange(xAxis + 5, 20, Qt::AlignRight);

    ui->widget->replot();
}

void RecordDialog::on_btnStop_clicked()
{
    if(running){
        disconnect(dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
        disconnect(this, SIGNAL(stopTimer()), dataTimer, SLOT(stop()));
        disconnect(this, SIGNAL(writeNewData(double, double)), writeBuffer, SLOT(writeData(double, double)));
        //disconnect(writeBuffer, SIGNAL(bufferFull(QByteArray, QVector<TimePointer> vector)), writeFile, SLOT(writeBufferToFile(QByteArray, QVector<TimePointer> vector)));
        running = false;
        pause = false;
        ui->btnPause->setText("pauze: OFF");
        enableButtons(true);
        stopRecording();
    }
}

void RecordDialog::on_btnChangeSettings_clicked()
{
    CreateGraphDialog* graphDialog = new CreateGraphDialog(this);
    connect(graphDialog, SIGNAL(setProperties(double,double,int,int,int,int,int,QString,QString)), this, SLOT(setProperties(double,double,int,int,int,int,int,QString,QString)));
    graphDialog->setProperties(recording.getFrequency(), recording.getAmplitude(), recording.getYAxisMax(), recording.getYAxisMin(), recording.getInterval(), recording.getGraphType(), recording.getSensor());
    graphDialog->setModal(true);
    graphDialog->exec();
}

void RecordDialog::on_btnPause_clicked()
{
    if(running){
        if(pause){
            if(qTimer.isValid()){
                //pauze voorbij , resume graph
                qAccumulator = qTimer.elapsed();
                qTimer.restart();
                connect(dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
                connect(this, SIGNAL(stopTimer()), dataTimer, SLOT(stop()));
                connect(this, SIGNAL(writeNewData(double, double)), writeBuffer, SLOT(writeData(double, double)));
                //connect(writeBuffer, SIGNAL(bufferFull(QByteArray, QVector<TimePointer> vector)), writeFile, SLOT(writeBufferToFile(QByteArray, QVector<TimePointer> vector)));
                pause = false;
                ui->btnPause->setText("pauze: OFF");
            }
        }else if(!pause){
            if(qTimer.isValid()){
                //start pauze, stop graph
                qAccumulator += qTimer.elapsed();
                qTimer.invalidate();
                qTimer.restart();
                disconnect(dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
                disconnect(this, SIGNAL(stopTimer()), dataTimer, SLOT(stop()));
                disconnect(this, SIGNAL(writeNewData(double, double)), writeBuffer, SLOT(writeData(double, double)));
                //disconnect(writeBuffer, SIGNAL(bufferFull(QByteArray, QVector<TimePointer> vector)), writeFile, SLOT(writeBufferToFile(QByteArray, QVector<TimePointer> vector)));
                pause = true;
                ui->btnPause->setText("pauze : ON");
            }
        }
    }
}

void RecordDialog::on_btnCancel_clicked()
{
    this->close();
}

void RecordDialog::on_sbCounter_valueChanged(int arg1)
{
    emit newCounterMax(arg1);
}

void RecordDialog::setNewCounterMax(int max){
    counterMax = max;
}
