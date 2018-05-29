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
#include <stdio.h>      //library crypt32 missing
#include <wincrypt.h>
#include <windows.h>
#include <QLibrary>
#include <QDebug>
#include <windows.h>
#include <models/graph.h>

using namespace std;

AnalysisDialog::AnalysisDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnalysisDialog)
{
    ui->setupUi(this);
    xAxis = 0;
    counter = 0;
}

AnalysisDialog::~AnalysisDialog()
{
    delete ui;
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
    QString dir = QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + "/SignalSleepDemonstrator/patients");
    QString path = QFileDialog::getExistingDirectory(this, tr("Select patient file"),
                                                dir, QFileDialog::DontUseNativeDialog);
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
            ui->widget->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
            ui->widget->addGraph();
            QVector<double> X(vector.count() + 1), Y(vector.count() + 1);
            for(double i = 0; i < vector.count() + 1; i++){
                X[i] = vector[i].x;
                Y[i] = vector[i].y;
            }
            ui->widget->xAxis2->setVisible(true);
            ui->widget->yAxis2->setVisible(true);
            connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis2, SLOT(setRange(QCPRange)));
            connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis2, SLOT(setRange(QCPRange)));
            ui->widget->graph(0)->setData(X, Y);
            ui->widget->graph(0)->rescaleAxes(true);
            ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables | QCP::iSelectAxes);
        }
    } catch(...){
        qFatal("Error occured within method AnalysDialog::drawGraph(QVector<TimePointer> vector");
    }


}

void AnalysisDialog::on_btnFilterRecording_clicked()
{

}
