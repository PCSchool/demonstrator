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

using namespace std;

AnalysisDialog::AnalysisDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnalysisDialog)
{
    ui->setupUi(this);
    xAxis = 0;
    counter = 0;
    int bufferSize = 1024;
    QByteArray* array = new QByteArray[bufferSize];
    qbuffer.setBuffer(array);
}

AnalysisDialog::~AnalysisDialog()
{
    delete ui;
}

//read out binary file
void AnalysisDialog::on_btnReadBinaryFile_clicked()
{
    //FILE * fp = fopen("recordFinal.bin", "rb");
    std::cout << endl << analysis.getRecordingFilePath().toLocal8Bit().constData() << " end file";
    FILE * fp = fopen(analysis.getRecordingFilePath().toLocal8Bit().constData(), "rb");
    int i, j;
    int swap = 0;
    tpList.clear();
    QMap<double, double> xyMap;
    QList<TimePointer> xyList;
    double x,y;
    char buffer[9];
    if(fp != NULL){
        int read = 0;
        while((read = fread(buffer, 1, 8, fp)) > 0){
            for(i=0; i < read; i++){
                //qDebug("%X ", buffer[i]);
            }
            for(j=0; j < read; j++){
                //qDebug("%c", buffer[j]);
            }
            QByteArray test(buffer, 8);
            if(test.size() == 8){
                if(swap == 1){
                    memcpy(&y, test, 8);
                    TimePointer tp;
                    tp.x = x;
                    tp.y = y;
                    xyList.append(tp);
                    swap = 0;
                }else{
                    memcpy(&x, test, 8);
                    swap++;
                }
            }
        }
        fclose(fp);
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

void AnalysisDialog::randomize(){
    xAxis++;
    counter++;
}

void AnalysisDialog::on_btnCancel_clicked(){
    //open file read constantly 16 bytes - 128 bits out
    std::ifstream fin("recording_2.bin", std::ios_base::in | std::ios_base::binary);
    if(!fin.is_open()){
        return;
    }
    //recording_0  <-- real recording file, contains 16KB, 16444 bytes
    //testerFile   <-- fake testing file contains 8 bytes
    //std::ifstream fin("recording_0.bin", std::ios_base::in | std::ios_base::binary);
    QFile file("recording_2.bin");

    if(!file.open(QIODevice::ReadOnly)){
        std::cout << "File couldnt be found nor opened.";
        return;
    }else{
        int counter = 0;
        QByteArray *array;
        char b[sizeof(array)];
        uint_fast16_t len;

        file.seek(0);
        QByteArray bytes = file.readAll();

        QDataStream dataStream(&file);
        dataStream.setByteOrder(QDataStream::LittleEndian);
        QVector<TimePointer> result;

        file.seek(0);
        size_t fileSize = fin.tellg();
        fin.seekg(0, ios::beg);

        std::vector<byte> vector(fileSize, 0);

        //.write(static_cast<char*>(static_cast<void*>(&data)), std::ios_base::app | std::ios::binary);
        //create  a <vector> to hold all the bytes in the file
        //fin.read(reinterpret_cast<char*>(&vector[0]), sizeof(fileSize));
        //fin.read(static_cast<char*>(static_cast<void*>(&vector[0])), sizeof(fileSize));

        //read the file
        char temp[fileSize];
        //fin.read(reinterpret_cast<char*>(&data[0]), sizeof(fileSize));
        fin.read(static_cast<char*>(static_cast<void*>(&vector[0])), sizeof(fileSize));

        TimePointer d1;
        d1.x = 0;
        d1.y = 0;

        fin.read(temp, 0-16);
        memcpy(&d1, temp, sizeof(TimePointer));
        std::cout << "test d1: " << d1.x << " - " << d1.y << " \n";

        fin.read(&temp[0-16], (16-32));
        memcpy(&d1, temp, sizeof(TimePointer));
        std::cout << "test d2: " << d1.x << " - " << d1.y << " \n";

        fin.read(&temp[32-48], (48-56));
        memcpy(&d1, temp, sizeof(TimePointer));
        std::cout << "test d3: " << d1.x << " - " << d1.y << " \n";
        //each character pointer on the system in 4-bytes long

        std::vector<byte> data(fileSize, 0);
        //read the file
        //fin.read(reinterpret_cast<char*>(&data[0]), sizeof(fileSize));
        fin.read(static_cast<char*>(static_cast<void*>(&data[0])), sizeof(fileSize));
        //Axis a;
        fin.read((char*)&len, 2);
        std::string str(len, '\o');
        //array = static_cast<QByteArray*>(&len);
        //array = reinterpret_cast<QByteArray*>(&len);
        array = static_cast<QByteArray*>(static_cast<void*>(&len));
        //loop in buffer

        std::cout << " Done reading  \n Bytes readed in file : " << counter << "\n fileSize file : " << fileSize << "\n data size : " << data.size() << endl;
        fin.close();
    }
}

void AnalysisDialog::on_btnSelectRecording_clicked()
{
    const QString path =  QFileDialog::getOpenFileName(
                this,
                "Open Document",
                dir.path(),
                "All files (*.*) ;; Document files (*.doc *.rtf);; PNG files (*.png)");
    analysis.setRecordingDir(QDir(path));
    analysis.setRecordingFilePath(path);

    // below for reading multiple files
    /*QString path = QString(QString(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first()) + "/SignalSleepDemonstrator/patients");
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select patient file"),
                                                path, QFileDialog::DontUseNativeDialog);
    analysis.setRecordingDir(QDir(dir)); //path if using file
    analysis.setRecordingFilePath(dir);*/
}

void AnalysisDialog::on_btnPrintResult_clicked(){
    if(tpList.count() > 10){
        ui->widget->addGraph();
        ui->widget->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
        ui->widget->addGraph();
        QVector<double> X(tpList.count() + 1), Y(tpList.count() + 1);
        int amount = tpList.count();
        for(double i = 0; i < amount; i++){
            X[i] = tpList[i].x;
            Y[i] = tpList[i].y;
        }
        ui->widget->xAxis2->setVisible(true);
        ui->widget->yAxis2->setVisible(true);
        connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis2, SLOT(setRange(QCPRange)));
        connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis2, SLOT(setRange(QCPRange)));
        ui->widget->graph(0)->setData(X, Y);
        ui->widget->graph(0)->rescaleAxes(true);
        ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    }
}
/*void QCustomPlot::showPointToolTip(QMouseEvent *event){
    int x = this->xAxis->pixelToCoord(event->pos().x());
    int y = this->yAxis->pixelToCoord(event->pos().y());
    setToolTip(QString("%1 , %2").arg(x).arg(y));
}*/

