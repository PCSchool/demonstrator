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
#include <dsp_filters/dsp_filters.h>
#include <dsp_filters/filters/ChebyshevI.h>
#include <dsp_filters/filters/Filter.h>
#include <exception>
#include <models/system.h>

using namespace std;

AnalysisDialog::AnalysisDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnalysisDialog)
{
    ui->setupUi(this);
    ui->widget->setContextMenuPolicy(Qt::CustomContextMenu);  //open right click menu
    connect(ui->widget, SIGNAL(customContextMenuRequested(const QPoint&)),this, SLOT(showContextMenu(const QPoint&)));

    xAxis = 0;
    counter = 0;
    index = 0;
}

AnalysisDialog::~AnalysisDialog()
{
    delete ui;
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

//read out binary file
void AnalysisDialog::on_btnReadBinaryFile_clicked()
{
    //USE QDirIterator to loop through directory

    //FILE * fp = fopen("recordFinal.bin", "rb");
    std::cout << endl << analysis.getRecordingFilePath().toLocal8Bit().constData() << " end file";
    //FILE * fp = fopen(analysis.getRecordingFilePath().toLocal8Bit().constData(), "rb");
    FILE * fp;
    int i, j;
    int next = 0;
    tpList.clear();
    QMap<double, double> xyMap;
    QList<TimePointer> xyList;
    TimePointer *tp;
    double x,y;
    char buffer[9];

    if(!analysis.getRecordingFilePath().length() < 1){
        QDirIterator it(analysis.getRecordingDir(), QDirIterator::NoIteratorFlags);
        QString itDirname = analysis.getRecordingFilePath();
        while(it.hasNext()) {
            QFile file(it.next());
            file.open(QIODevice::ReadOnly);
            while(!file.atEnd()){
                file.read(buffer, 8);
                QByteArray save(buffer, 8);
                memcpy(&x, save, 8);
                int size = save.size();
                QByteArray ss(buffer, 8);
                if(save.size() == 8){
                    if(next == 1){
                        next++;
                        memcpy(&x, save, 8);
                        TimePointer tp;
                        tp.x = x;
                        tp.y = y;
                        //graph.addPoints(tp);
                        xyList.append(tp);
                    }else{
                        memcpy(&y, save, 8);
                        next = 0;
                    }
                }
                QByteArray sss(buffer, 8);
            }
            file.close();
        }
    }
    /*for (auto const& i : xyList){
        std::cout << endl << " TimePointer: (" << i.x << "," << i.y << ")";
    }*/

    tpList = xyList;
}

double AnalysisDialog::transfer(quint64 number){
    int integer = number;
    return static_cast<double>(integer);
}

void AnalysisDialog::setDir(QDir dir){
    this->dir = dir;
}

void AnalysisDialog::on_btnCancel_clicked(){
    this->deleteLater();
}

void AnalysisDialog::on_btnSelectRecording_clicked()
{
    //select one directory
    QString path = QFileDialog::getExistingDirectory(this, tr("Select patient file"),
                                                System::getPatientLocation(), QFileDialog::DontUseNativeDialog);
    drawGraph(analysis.readDir(path));
}
/*void QCustomPlot::showPointToolTip(QMouseEvent *event){
    int x = this->xAxis->pixelToCoord(event->pos().x());
    int y = this->yAxis->pixelToCoord(event->pos().y());
    setToolTip(QString("%1 , %2").arg(x).arg(y));
}*/


void AnalysisDialog::on_btnReadSpecificFile_clicked()
{
    //select one file
    drawGraph(analysis.readFile(QFileDialog::getOpenFileName(
                                    this,
                                    "Open Document",
                                    dir.path(),
                                    "All files (*.*) ;; Document files (*.doc *.rtf);; PNG files (*.png)")));
}

void AnalysisDialog::drawGraph(QVector<TimePointer> vector){
    ui->widget->clearGraphs();
    try{
        if(vector.count() != 0){
            ui->widget->addGraph();
            ui->widget->graph(index)->setPen(QPen(Qt::blue)); // line color blue for first graph
            QVector<double> X(vector.count() + 1), Y(vector.count() + 1);
            for(double i = 0; i < vector.count() + 1; i++){
                X[i] = vector[i].x;
                Y[i] = vector[i].y;
            }
            ui->widget->xAxis2->setVisible(true);
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

void AnalysisDialog::mouseMoveEvent(QMouseEvent *event){
    QString string = QString::number(event->x()) + " " + QString::number(event->y());
    QToolTip::showText(QPoint(event->x(), event->y()), string, ui->widget);
}

void AnalysisDialog::on_btnFilterRecording_clicked()
{
    int selectedPass = 0;
    //int selectedFilter = ui->cbFilter->currentIndex();

    ui->btnFilterRecording->setText(QString::number(selectedPass));

    QVector<TimePointer> vector = analysis.readFile(QFileDialog::getOpenFileName(
                                                                this,
                                                                "Open Document",
                                                                dir.path(),
                                                                "All files (*.*) ;; Document files (*.doc *.rtf);; PNG files (*.png)"));
    double pepoles[1000];
    int zz = 1;
    for(int z = 0; z < 999; z++){
        pepoles[z] = zz;
        if(z % 10 == 0){
            zz=1;

        }
        zz++;
    }
    QVector<double> doubleAxis = analysis.splitXY(vector, false);
    int amount = doubleAxis.count();
    std::vector<double> vectorAxis = doubleAxis.toStdVector();
    double* a = &vectorAxis[0];

    if(selectedPass == 0){  //low pass
         drawGraph(analysis.castToLowPass(vector));
    }else if(selectedPass == 1){  //high pass
        drawGraph(analysis.castToHighPass(vector));
    }else if(selectedPass == 2){  //band pass

        Dsp::SimpleFilter <Dsp::ChebyshevI::BandStop <3>, 2> f;
        f.setup(3,
                44100,
                4000,
                880,
                1);

    }else if(selectedPass = 3){ // band stop

    }
}

void AnalysisDialog::on_cbMouseTrack_stateChanged(int arg1){
    if(arg1 == 2){
        connect(ui->widget, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMoveEvent(QMouseEvent*)));
    }else{
        disconnect(ui->widget, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseMoveEvent(QMouseEvent*)));
    }
    ui->widget->replot();
}

void AnalysisDialog::on_cbShowScale_stateChanged(int arg1)
{
    if(arg1 == 2){
        ui->widget->rescaleAxes(true);
    }
    ui->widget->replot();
}

void AnalysisDialog::on_cbShowLegend_stateChanged(int arg1)
{
    if(arg1 == 2){
        ui->widget->legend->setVisible(true);
        ui->widget->legend->setBrush(QBrush(QColor(255,255,255,150)));
        ui->widget->axisRect()->insetLayout()->setInsetAlignment(index, Qt::AlignLeft|Qt::AlignTop);
    }else{
        ui->widget->legend->setVisible(false);
    }
    ui->widget->replot();
}

void AnalysisDialog::on_btnSaveFile_clicked()
{
    QSettings settings;
    QString filename = QFileDialog::getSaveFileName(this, tr("Save graph"), settings.value("Plot Image Export Directory").toString(), "PNG (*.png);;PDF (*.PDF");
    if(!filename.isEmpty()){
        try{
            settings.setValue("Plot Image Export Directory", QFileInfo(filename).absolutePath());
            if(filename.right(3)=="png"){
                ui->widget->savePng(filename, 500, 500, 1.0, -1);
            }else if(filename.right(3)=="jpg"){
                ui->widget->saveJpg(filename, 500, 500, 1.0, -1);
            }else if(filename.right(3)=="PDF"){

            }else{
                //ui->widget->saveRastered(filename, 500, 500, 1.0, );
            }
        }
        catch(...){
            QMessageBox messageBox;
            messageBox.warning(0, "Error", "The selected file couldnt be found.");
            messageBox.show();
        }
    }
}
