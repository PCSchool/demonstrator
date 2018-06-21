#include "analysisdialog.h"
#include "ui_analysisdialog.h"
#include <QBuffer>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QMessageBox>
#include <binaryreader.h>
#include <binarywriter.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <wincrypt.h>
#include <windows.h>
#include <QLibrary>
#include <QDebug>
#include <windows.h>
#include <models/graph.h>
#include <qcustomplot.h>
#include <dsp_filters/dsp_filters.h>
#include <dsp_filters/filters/ChebyshevI.h>
#include <dsp_filters/filters/Filter.h>
#include <exception>
#include <globals.h>
#include <models/system.h>
#include <exceptions/exceptioninvalidpathchosen.h>

using namespace std;

AnalysisDialog::AnalysisDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnalysisDialog)
{
    ui->setupUi(this);
    design = "";
    filter = "";
    xAxis = 0;
    counter = 0;
    index = 0;
    enableButtons(false);
    ui->widget->setContextMenuPolicy(Qt::CustomContextMenu);  //open right click menu
    connect(ui->widget, SIGNAL(customContextMenuRequested(const QPoint&)),this, SLOT(showContextMenu(const QPoint&)));
    ui->widget->installEventFilter(this);  //for mouseEvent

    for(int g = 0; g < itemsDesignDefault.size(); ++g){
        ui->cbDesign->addItem(itemsDesignDefault.at(g));
    }
    for(int g = 0; g < itemsFilterDefault.size(); ++g){
        ui->cbFilter->addItem(itemsFilterDefault.at(g));
    }
}

AnalysisDialog::~AnalysisDialog()
{
    delete ui;
}

double AnalysisDialog::transfer(quint64 number){
    int integer = number;
    return static_cast<double>(integer);
}

void AnalysisDialog::setDir(QDir dir){
    this->dir = dir;
    ui->lblTest->setText(dir.path());
}

void AnalysisDialog::drawGraph(QVector<TimePointer> vector){
    ui->widget->clearGraphs();
    try{
        ui->lblTest->setText(dir.path());
        if(vector.count() != 0){
            ui->widget->addGraph();
            ui->widget->graph(index)->setPen(QPen(Qt::blue)); // line color blue for first graph
            //QVector<double> X(vector.count() + 1), Y(vector.count() + 1);
            int size = vector.count();
            QVector<double> X(size);
            QVector<double> Y(size);
            for(double i = 0; i < vector.count(); i++){
                X[i] = vector[i].x;
                Y[i] = vector[i].y;
                QString t2 = QString::number(vector[i].y);
                QString t1 = QString::number(vector[i].x);
            }
            QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
            timeTicker->setTimeFormat("%h:%m:%s");
            ui->widget->xAxis2->setTicker(timeTicker);
            ui->widget->yAxis2->setVisible(true);
            connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis2, SLOT(setRange(QCPRange)));
            connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis2, SLOT(setRange(QCPRange)));
            ui->widget->graph(index)->setData(X, Y);
            ui->widget->graph(index)->rescaleAxes(true);
            ui->widget->graph(index)->setName("Analysis graph " + QString::number(index));
            ui->widget->xAxis->setLabel("Time(hh:mm::ss)");
            ui->widget->yAxis->setLabel("Amount");
            ui->widget->setMouseTracking(true);
            ui->widget->setAutoAddPlottableToLegend(true);
            ui->widget->rescaleAxes();

            ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables | QCP::iSelectAxes);
            ui->widget->replot();
        }
    } catch(...){
        qFatal("Error occured within method AnalysDialog::drawGraph(QVector<TimePointer> vector");
    }
}

void AnalysisDialog::on_btnSaveFile_clicked()
{
    QSettings settings;
    QString filename = QFileDialog::getSaveFileName(this, tr("Save graph"), settings.value("Plot Image Export Directory").toString(), "PNG (*.png);;PDF (*.PDF");
    if(!filename.isEmpty()){
        try{
            settings.setValue("Plot Image Export Directory", QFileInfo(filename).absolutePath());
            QString control = filename.right(filename.lastIndexOf('/'));
            QString control2 = dir.path().right(dir.path().lastIndexOf('/'));
            if(control == control2){
                throw ExceptionInvalidPathChosen();
            }
            ui->widget->savePng(filename, 500, 500, 1.0, -1);
        }
        catch(ExceptionInvalidPathChosen e){
            QMessageBox messageBox;
            messageBox.warning(0, "Error", e.error);
            messageBox.show();
        }
        catch(...){
            QMessageBox messageBox;
            messageBox.warning(0, "Error", "Exception: The selected path isnt available. Please try something another, available directory.");
            messageBox.show();
        }
    }
}

void AnalysisDialog::on_btnCancel_clicked(){
    this->deleteLater();
}

void AnalysisDialog::on_btnSelectRecording_clicked()
{
    //select one directory
    QString path = QFileDialog::getExistingDirectory(this, tr("Select patient file"),
                                                System::getPatientLocation(), QFileDialog::DontUseNativeDialog);
    points = analysis.readDir(path);
    drawGraph(points);
    enableButtons(true);
}

void AnalysisDialog::on_btnReadSpecificFile_clicked()
{
    //select one file
    points = analysis.readFile(QFileDialog::getOpenFileName(this, "Open Document",
                                    dir.path(), "All files (*.*) ;; Document files (*.doc *.rtf);; PNG files (*.png)"));

    drawGraph(points);
    enableButtons(true);
}

void AnalysisDialog::on_btnScaleGraph_clicked()
{
    double dividedBy = 100.0;
    if(points.size() > 5000){dividedBy = 1000;}

    QVector<TimePointer> newvalues;
    TimePointer tpMax, tpMin;
    tpMax.x = 0;
    tpMax.y = 0;
    newvalues.append(tpMax);
    tpMax.x = 10;
    tpMax.y = 10;

    double count = 0;
    for(int z = 0; z < points.size(); z++){
        count++;
        if(count < dividedBy){
            if(points.at(z).y > tpMax.y){
                tpMax.x = points.at(z).x;
                tpMax.y = points.at(z).y;
            }
            if(points.at(z).y < tpMin.y){
                tpMin.x = points.at(z).x;
                tpMin.y = points.at(z).y;
            }
        }else{
            if(tpMin.x > tpMax.x){
                newvalues.push_back(tpMin);
                newvalues.push_back(tpMax);
            }else{
                newvalues.push_back(tpMax);
                newvalues.push_back(tpMin);
            }
            count = 0;
            tpMin.y = 10;
            tpMax.y = 10;
        }
    }
    /*for(int k = 0; k < newvalues.count(); k++){
        std::cout << newvalues.at(k).x << " " << newvalues.at(k).y << " points " <<endl;
    }*/
    ui->widget->clearGraphs();
    drawGraph(newvalues);
}

void AnalysisDialog::on_btnFilterRecording_clicked()
{
    //frequency 64Hz -> 15.625 ms in 5.000 ms  -> 0.2 Hz
   int numSamples = points.size();
   double* info[numSamples];
   for(int z = 0; z < numSamples; z++){
       int d = static_cast<int>(points.at(z).y);
       info[z] = new double[d];
   }

   Dsp::Filter* f = new Dsp::SmoothedFilterDesign <Dsp::RBJ::Design::LowPass, 2>(1024);
   Dsp::Params params;
   params[0] = 44100;
   params[1] = 4000;
   params[2] = 1.25;
   f->setParams(params);
   f->process(numSamples, info);
}

void AnalysisDialog::on_cbDesign_currentIndexChanged(const QString &arg1)
{
    design = arg1;
    analysis.designDefault = design;
    ui->btnFilterRecording->setText(QString("Filter \n %1 - %2").arg(design).arg(filter));
}

void AnalysisDialog::on_cbFilter_currentIndexChanged(const QString &arg1)
{
    filter = arg1;
    analysis.filterDefault = filter;
    ui->btnFilterRecording->setText(QString("Filter \n %1 - %2").arg(design).arg(filter));
}

void AnalysisDialog::on_cbShowLegend_stateChanged(int arg1)
{
    if(arg1 == 2){
        ui->widget->legend->setVisible(true);
        ui->widget->legend->setBrush(QBrush(QColor(255,255,255,150)));
        ui->widget->axisRect()->insetLayout()->setInsetAlignment(index, Qt::AlignLeft|Qt::AlignTop);
        ui->cbShowLegend->setText("On");
    }else{
        ui->widget->legend->setVisible(false);
        ui->cbShowLegend->setText("Off");
    }
    ui->widget->replot();
}

void AnalysisDialog::on_cbMouseTrack_stateChanged(int arg1){
    if(arg1 == 2){
        connect(ui->widget, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMoveEvent(QMouseEvent*)));
        ui->cbMouseTrack->setText("On");
    }else{
        disconnect(ui->widget, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMoveEvent(QMouseEvent*)));
        ui->cbMouseTrack->setText("Off");
    }
    ui->widget->replot();
}

void AnalysisDialog::on_cbShowScale_stateChanged(int arg1)
{
    if(arg1 == 2){
        ui->widget->rescaleAxes(true);
        ui->cbShowScale->setText("On");
    }else{
        ui->cbShowScale->setText("Off");
    }
    ui->widget->replot();
}

void AnalysisDialog::enableButtons(bool active){
    ui->btnSaveFile->setEnabled(active);
    ui->btnScaleGraph->setEnabled(active);
    ui->btnFilterRecording->setEnabled(active);
}

void AnalysisDialog::mouseMoveEvent(QMouseEvent *event){
    double x = ui->widget->xAxis->pixelToCoord(event->pos().x());
    double y = ui->widget->yAxis->pixelToCoord(event->pos().y());

    QToolTip::showText(QPoint(x, y), QString("%1, %2").arg(x).arg(y), ui->widget);
}

//show right-click context menu + handles selection of the selecteditem of the menu
void AnalysisDialog::showContextMenu(const QPoint& pos){
    QPoint globalPos = ui->widget->mapToGlobal(pos);
    QMenu qmenu;
    qmenu.addAction("create graph");
    qmenu.addAction("exit");

    QAction* selectedItem = qmenu.exec(globalPos);
    if(selectedItem){
        std::cout << "click menu";
    }
}
