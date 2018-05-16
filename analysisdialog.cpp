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
    QString pathfile = "recording_1.bin";

     //1 - FILE
    char buff[1024];
    FILE * file = fopen(pathfile.toLocal8Bit().constData(), "rb");
    int bytes_read = fread(buff, sizeof(256), 1024, file);

    std::cout << " 1 : FILE - " <<bytes_read << endl;

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
    QFile file4(pathfile);
    file4.open(QIODevice::ReadOnly);
    fillArray = file4.readAll();
    std::cout << " 3 : QFile - " << fillArray.size() << " " << endl;

    fillArray.clear();

    // 4
    QDataStream fileStream(&file4);
    fileStream.setVersion(QDataStream::Qt_5_10);
    fileStream.setByteOrder(QDataStream::LittleEndian);
    char *temp = new char[sizeof(fileStream)];
    fileStream.readRawData((temp),sizeof(fileStream));
    size_t tt = sizeof(fileStream);
    array.append(temp, tt);
    char *buf = (char *)malloc(sizeof(temp) * tt);
    TimePointer *test = (TimePointer *) buf;
    //std::cout << test->x << " - " << test->y << " " <<endl;
    std::cout << " 4 : QDataStream - " << sizeof(fileStream) << endl;

    //TimePointer* tp = reinterpret_cast<TimePointer*>(array.data());
    //memcpy(&d1, temp, sizeof(TimePointer));
    //std::cout << "test d1: " << d1.x << " - " << d1.y << " \n";

    file4.close();

    std::cout << "real bytes : 577 " <<endl ;
}

void AnalysisDialog::on_btnGenerate_clicked()
{ 
    QString path = "C:/Users/Onera/Documents/SignalSleepDemonstrator/testerFile.bin";
    QByteArray* array = new QByteArray[1024];
    //ensure file gets created
    ofstream myfile;
    myfile.open(path.toLocal8Bit().constData());
    myfile.close();

    qbuffer.setBuffer(array);

    struct Axis{
        double x, y;
    } axis;
    axis.y = counter;
    axis.x = xAxis;

    for(int x = 0; x < 15; x++){

        axis.x = xAxis;
        axis.y = counter;

        //std::cout << "added: " + QString::number(counter) + " - " + QString::number(xAxis) << endl;

        qbuffer.buffer().prepend(reinterpret_cast<char *>(&axis));
        qbuffer.open(QIODevice::ReadWrite | QIODevice::Truncate );
        qbuffer.write(reinterpret_cast<char *>(&axis), std::ios_base::app | std::ios::binary);
        qbuffer.close();

        char b[sizeof(axis)];
        memcpy(b, &axis, sizeof(axis));

        Axis axis2;
        memcpy(&axis2, b, sizeof(axis2));
        cout << "test x = " << axis2.x << " y = " << axis2.y << endl;

        std::cout << "analysisDialog: writing " << xAxis << " " << counter << endl;
        randomize();
    }

    std::ofstream fout(path.toLocal8Bit().constData(), std::ios::binary | std::ios_base::app);
    fout.write(reinterpret_cast<char *>(&qbuffer), sizeof(qbuffer));
    fout.close();

    std::cout << "done writing , start reading" << endl;
}

<<<<<<< HEAD
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
    in.device()->reset();

    QList<TimePointer> tpList;
    tp = TimePointer();
    char tmpChar[100];
    quint64 tmp64;
    quint32 tmp32;
    quint16 tmp16;

    //loop to gather the info of TimePointer
    //in >> tp.x;
    // in >> tp.y;
    //std::cout << tp.x << " " << tp.y << endl;
    //tpList.push_back(tp);

    std::cout << "size  ----  " << tpList.count() << " " << endl;
    std::cout << "info   ---- " << tpList.size() << " " << sizeof(tpList) << endl;
=======
QDataStream &operator >>(QDataStream &in, Data &data){

>>>>>>> 99352342c844220d4eb6fb8227db9ae0e0da1aab
    return in;
}

void AnalysisDialog::on_btnSelectRecording_clicked()
{
<<<<<<< HEAD
    //get QByteArray from file
    QFile file("recording_1.bin");
    if(!file.open(QIODevice::ReadOnly))
        return;
    QByteArray array = file.readAll();

    std::cout << "\n recording_1.bin - " << array.size() << endl;

    //create QDataStream and start reading from it to get all TimePointers
    TimePointer tp;

    QDataStream readstream(&file);
    readstream.setVersion(QDataStream::Qt_5_10);

    readstream >> tp;

    file.close();
    std::cout << "\n DONE";
 }

void AnalysisDialog::setDir(QDir dir){
    this->dir = dir; 
}

void AnalysisDialog::randomize(){
    xAxis++;
    counter++;
}

void AnalysisDialog::on_btnCancel_clicked()
{
    //open file read constantly 16 bytes - 128 bits out
    std::ifstream fin("recording_4.bin", std::ios_base::in | std::ios_base::binary);
    if(!fin.is_open()){
=======
    //recording_0  <-- real recording file, contains 16KB, 16444 bytes
    //testerFile   <-- fake testing file contains 8 bytes
    //std::ifstream fin("recording_0.bin", std::ios_base::in | std::ios_base::binary);
    QFile file("recording_0.bin");

    if(!file.open(QIODevice::ReadOnly)){
>>>>>>> 99352342c844220d4eb6fb8227db9ae0e0da1aab
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
        while(!dataStream.atEnd()){
            Data x;
            dataStream >> x;
            result.append(x);
        }


        //loop through QByteArray

        /*
        file.seek(0);
        size_t fileSize = fin.tellg();
        fin.seekg(0, ios::beg);
<<<<<<< HEAD

        std::vector<byte> vector(fileSize, 0);

        //create  a <vector> to hold all the bytes in the file
        fin.read(reinterpret_cast<char*>(&vector[0]), sizeof(fileSize));

        //read the file
        char temp[fileSize];
        //fin.read(reinterpret_cast<char*>(&data[0]), sizeof(fileSize));

        TimePointer d1;
        d1.x = 0;
        d1.y = 0;

        fin.read(temp, 0-128);
        memcpy(&d1, temp, sizeof(TimePointer));
        std::cout << "test d1: " << d1.x << " - " << d1.y << " \n";

        fin.read(&temp[0-128], (128-256));
        memcpy(&d1, temp, sizeof(TimePointer));
        std::cout << "test d2: " << d1.x << " - " << d1.y << " \n";

        fin.read(&temp[128-256], (256-384));
        memcpy(&d1, temp, sizeof(TimePointer));
        std::cout << "test d3: " << d1.x << " - " << d1.y << " \n";
        //each character pointer on the system in 4-bytes long
=======
        std::vector<byte> data(fileSize, 0);
        //read the file
        fin.read(reinterpret_cast<char*>(&data[0]), sizeof(fileSize));
        Axis a;
        fin.read((char*)&len, 2);
        std::string str(len, '\o');
        array = reinterpret_cast<QByteArray*>(&len);
        //loop in buffer
        fin.close();

        std::cout << " Done reading  \n Bytes readed in file : " << counter << "\n fileSize file : " << fileSize << "\n data size : " << data.size() << endl;
        //fin.close*/

>>>>>>> 99352342c844220d4eb6fb8227db9ae0e0da1aab
    }
}

void AnalysisDialog::on_btnSelectRecording_2_clicked()
{
    const QString path =  QFileDialog::getOpenFileName(
                this,
                "Open Document",
                dir.path(),
                "All files (*.*) ;; Document files (*.doc *.rtf);; PNG files (*.png)");
    analysis.setRecordingDir(QDir(path));
    QFile file;
    analysis.setRecordingFilePath(path);
}

void AnalysisDialog::on_btnPrintResult_clicked()
{


}
