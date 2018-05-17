#include "analysisdialog.h"
#include "ui_analysisdialog.h"
#include <QBuffer>
#include <iostream>
#include <fstream>
#include <QMessageBox>
#include <binaryreader.h>
#include <binarywriter.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>      //library crypt32 missing
#include <wincrypt.h>
#include <windows.h>
#include <QLibrary>

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
    TimePointer d1, d2;
    QByteArray fillArray, array;
    QString pathfile = "recording_2.bin";

     //1 - FILE
    char buff[1024];
    FILE * file = fopen(pathfile.toLocal8Bit().constData(), "rb");
    int bytes_read = fread(buff, sizeof(256), 1024, file);

    fwrite(&d1, sizeof(struct TimePointer), 1, file);
    std::cout << " 1 : FILE - " <<bytes_read << " -- " << d1.x << " " << d1.y <<  endl;

    // 2 - std::ifstream
    std::ifstream fin(pathfile.toLocal8Bit().constData(), std::ios_base::in | std::ios_base::binary);
    if(!fin.is_open()){
        std::cout << "File couldnt be found nor opened.";
    }else{
        //get the length of the file
        fin.seekg(0, ios::end);
        size_t fileSize = fin.tellg();
        fin.seekg(0, ios::beg);
        std::vector<byte> vector(fileSize, 0);
        //create  a <vector> to hold all the bytes in the file
        fin.read(reinterpret_cast<char*>(&vector[0]), sizeof(fileSize));
        //read the file
        char temp[fileSize];
        //fin.read(reinterpret_cast<char*>(&data[0]), sizeof(fileSize));
        TimePointer d1;
        d1.x = 0;
        d1.y = 0;
        /*fin.read(temp, 0-128);
        memcpy(&d1, temp, sizeof(TimePointer));
        std::cout << "test d1: " << d1.x << " - " << d1.y << " \n";*/
        std::cout << " 2 : std::ifstream - " << vector.size()<<  endl;
        fin.close();
    }

    // 3 - QFile
    QFile qfile(pathfile);
    qfile.open(QIODevice::ReadOnly);
    fillArray = qfile.readAll();
    std::cout << " 3 : QFile - " << fillArray.size() << " " << endl;
    fillArray.clear();

    // 4
    QDataStream fileStream(&qfile);
    fileStream.setVersion(QDataStream::Qt_5_10);
    fileStream.setByteOrder(QDataStream::LittleEndian);
    char *temp = new char[sizeof(fileStream)];
    fileStream.readRawData((temp),sizeof(fileStream));
    size_t tt = sizeof(fileStream);
    array.append(temp, tt);
    char *buf = (char *)malloc(sizeof(temp) * tt);
    TimePointer *test = (TimePointer *) buf;
    //std::cout << test->x << " - " << test->y << " " <<endl;
    std::cout << " 4 : QDataStream - " << array.size() << endl;

    //TimePointer* tp = reinterpret_cast<TimePointer*>(array.data());
    //memcpy(&d1, temp, sizeof(TimePointer));
    //std::cout << "test d1: " << d1.x << " - " << d1.y << " \n";
    std::cout << "real bytes : " <<  qfile.size() << endl ;
    qfile.close();
}

void AnalysisDialog::on_btnGenerate_clicked()
{ 

}

//write to file << outstream
QDataStream &operator<<(QDataStream &out,const TimePointer &tp){
    out << (quint64)tp.x;
    out << (quint64)tp.y;
    return out;
}

//read from file >> instream
QDataStream &operator>>(QDataStream &in,TimePointer &tp){
    //resetting the stream is required. position is at then at the start
    in.resetStatus();
    //in.device()->reset();
    tp = TimePointer();

    in >> tp.x;
    in >> tp.y;
    std::cout << tp.x << " " << tp.y << " size tp : " << sizeof(TimePointer) << endl;

    char *empt = reinterpret_cast<char *>(&tp);

    //memcpy(newcopy, original, copy sizeof(char*) into newcopy);
    memcpy(&tp, empt, sizeof(TimePointer));

    std::cout <<"|" << tp.x << " " << tp.y << " -> ";

    return in;
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
        QVector<Data> result;

        file.seek(0);
        size_t fileSize = fin.tellg();
        fin.seekg(0, ios::beg);

        std::vector<byte> vector(fileSize, 0);

        //create  a <vector> to hold all the bytes in the file
        fin.read(reinterpret_cast<char*>(&vector[0]), sizeof(fileSize));

        //read the file
        char temp[fileSize];
        //fin.read(reinterpret_cast<char*>(&data[0]), sizeof(fileSize));

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
        fin.read(reinterpret_cast<char*>(&data[0]), sizeof(fileSize));
        //Axis a;
        fin.read((char*)&len, 2);
        std::string str(len, '\o');
        array = reinterpret_cast<QByteArray*>(&len);
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
}

void AnalysisDialog::on_btnPrintResult_clicked(){
    //ui->widget->aadd two new graphs and set their look:
    ui->widget->addGraph();
    ui->widget->graph(0)->setPen(QPen(Qt::blue));
    ui->widget->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->widget->addGraph();

    // generate some points of data (y0 for first, y1 for second graph):
    QVector<double> X(50), Y(50);
    for(double i = 0; i < tpList.count(); i++){
        X[i] = i;//tpList[i].x;
        Y[i] = 50;//tpList[i].y;
    }
    ui->widget->xAxis2->setVisible(true);
    ui->widget->xAxis2->setTickLabels(false);
    ui->widget->yAxis2->setVisible(true);
    ui->widget->yAxis2->setTickLabels(false);
    connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis2, SLOT(setRange(QCPRange)));
    ui->widget->graph(0)->setData(X, Y);
    ui->widget->graph(0)->rescaleAxes(true);
    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

}


void AnalysisDialog::on_btnTest_clicked()
{
    //get QByteArray from file
    QFile file("recording_2.bin");
    if(!file.open(QIODevice::ReadOnly))
        return;
    QByteArray array = file.readAll();

    QDataStream readstream(&file);
    readstream.setVersion(QDataStream::Qt_5_10);
    readstream.setByteOrder(QDataStream::LittleEndian);
    //readstream.setVersion(QDataStream::Qt_5_10);

    int length = sizeof(TimePointer);

    std::cout << "\n recording_2.bin - " << array.size() << endl;

    //create QDataStream and start reading from it to get all TimePointers
    TimePointer tp;

    char *temp = new char[length];
    readstream.readRawData(temp, length);
    array.append(temp, length);

    TimePointer tp1 = TimePointer();
    char tmpChar[100];

    QByteArray nd(QByteArray::fromRawData(array.data(),sizeof(TimePointer)));
    TimePointer tpp;
    memcpy(&tpp, nd.data(), sizeof(TimePointer));
    std::cout << " " << tpp.x << " " << tpp.y;

    QByteArray cop = array.chopped(sizeof(TimePointer));

    TimePointer tp4;
    memcpy(&tp4, array, length);
    std::cout <<  " tp4 " << tp4.x << " " << tp.y << " " << endl;

    memcpy(&tp4, cop, length);
    std::cout <<  " tp4 " << tp4.x << " " << tp.y << " " << endl;

    //takes first 16 of the original array into copy
    //memcpy(&cop, array, sizeof(TimePointer));

    TimePointer tp2;
    memcpy(&tp2, array.chopped(length).data(), length);
    //= reinterpret_cast<TimePointer*>(array.chopped(sizeof(TimePointer)).data());
    std::cout << " tp2 " << tp2.x << " " << tp2.y << "  " << endl;

    TimePointer *tp3 = reinterpret_cast<TimePointer*>(cop.data());
    std::cout << " tp3 " << tp3->x << " " << tp3->y << "  " << endl;

    //loop to gather the info of TimePointer

    //readstream.readBytes(tmp1, sizeof(TimePointer));
    //tp1 = (TimePointer *)tmp1;
    readstream >> tp;

    file.close();
    std::cout << "DONE " << endl;
}
