#include "analysis.h"
#include <globals.h>
#include <QDir>
#include <QDirIterator>
#include <exceptions/exceptioninvalidparameters.h>

//constructor
Analysis::Analysis()
{

}

//methods
QVector<TimePointer> Analysis::readFile(QString path){
    if(path.isEmpty()){
        throw ExceptionInvalidParameters();
    }
    QVector<TimePointer> vector;
    try{
        FILE * fp = fopen(path.toLocal8Bit().constData(), "rb");
        int next = 0;
        double x,y;
        char buffer[9];
        if(fp != NULL){
            int read = 0;
            while((read = fread(buffer, 1, 8, fp)) > 0){
                QByteArray test(buffer, 8);
                if(test.size() == 8){
                    if(next == 1){
                        memcpy(&y, test, 8);
                        TimePointer tp;
                        tp.x = x;
                        tp.y = y;
                        vector.append(tp);
                        next = 0;
                    }else{
                        memcpy(&x, test, 8);
                        next++;
                    }
                }
            }
            fclose(fp);
        }
    } catch(...){
        qFatal("Error occured within method Analysis::readDir(QString path)");
    }
    return vector;
}

QVector<TimePointer> Analysis::castToLowPass(QVector<TimePointer> points){
    double xm1 = 0;
    int M = 10/2;
    QVector<TimePointer> returnVector;

    for(int i = 0; i < points.count() + 1; i++){
        TimePointer tp;
        tp.y = simpleLowPass(&points[i].x, &points[i].y, M, xm1);
        tp.x = points[i].x;
        returnVector.append(tp);
    }

    return returnVector;
}

double Analysis::simpleLowPass(double *x, double *y, int M, double xm1){
    int n;
    y[0] = x[0] + xm1;
    for(n=1; n < M; n++){
        y[n] = x[n]+ x[n-1];
    }
    return x[M-1];
}

QVector<TimePointer> Analysis::castToHighPass(QVector<TimePointer> points){
    QVector<TimePointer> returnVector;
    double freq = 0.1;
    double b = 0.08;
    int N = 2;
    return returnVector;
}
QVector<TimePointer> Analysis::castToBandPass(QVector<TimePointer> points){
    return points;
}
QVector<TimePointer> Analysis::castToBandStop(QVector<TimePointer> points){
    return points;
}

QVector<TimePointer> Analysis::readDir(QString path){
    if(path.isEmpty()){
        throw ExceptionInvalidParameters();
    }
    setRecordingDir(QDir(path));
    setRecordingFilePath(path);

    QVector<TimePointer> vector;
    try{
        FILE * fp;
        TimePointer tp;
        int next = 0;
        double x,y;
        char buffer[9];
        if(!path.length() < 1){
            QDir dir(path);
            QDirIterator it(recordingDir, QDirIterator::NoIteratorFlags);

            while(it.hasNext()) {
                QString filename = it.next();
                QFile file(filename.toLocal8Bit().constData());
                file.open(QIODevice::ReadOnly);
                while(!file.atEnd()){
                    file.read(buffer, 8);
                    QByteArray save(buffer, 8);
                    memcpy(&x, save, 8);
                    std::cout << x << " - ";
                    int size = save.size();
                    QByteArray ss(buffer, 8);
                    if(save.size() == 8){
                        if(next == 0){
                            next++;
                            memcpy(&x, save, 8);
                            TimePointer tp;
                            tp.x = x;
                            tp.y = y;
                            vector.append(tp);
                        }else{
                            memcpy(&y, save, 8);
                        }
                    }
                    //int size = save.size();
                    QByteArray ss(buffer, 8);
                    if(save.size() == 8){
                        if(next == 1){
                            next++;
                            memcpy(&x, save, 8);
                            tp.x = x;
                        }else{
                            memcpy(&y, save, 8);
                            tp.y = y;
                            vector.append(tp);
                            next = 0;
                        }
                    }
                    QByteArray sss(buffer, 8);
                }
                file.close();
            }
        }
    } catch(...){
        qFatal("Error occured within method Analysis::readDir(QString path)");
    }
    std::cout << endl << " final : " << vector.count();
    return vector;
}

void Analysis::addRecordingDirList(QString path){
    if(path.isEmpty()){throw ExceptionInvalidParameters();}
    recordingPathList.append(path);
}

QList<QString> Analysis::getRecordingList(){
    return recordingPathList;
}

void Analysis::addPointerList(TimePointer pointer){
    pointerList.push_back(pointer);
}

QList<TimePointer> Analysis::getPointerList(){
    return pointerList;
}

void Analysis::clearPointerList(){
    pointerList.clear();
}

QVector<double> Analysis::getXaxis(){
    return this->Xaxis;
}

QVector<double> Analysis::getYaxis(){
    return this->yaxis;
}

void Analysis::addToVector(double x, double y){
     Xaxis.push_back(x);
     yaxis.push_back(y);
}

void Analysis::setRecordingDir(QDir dir){
    if(dir.path().isEmpty()){throw ExceptionInvalidParameters();}
    this->recordingDir = dir;
}

QDir Analysis::getRecordingDir(){
    return this->recordingDir;
}

void Analysis::setRecordingFilePath(QString filepath){
    if(filepath.isEmpty()){throw ExceptionInvalidParameters();}
    recordingFilePath = filepath;
    recordingFile.setFileName(filepath);
}

QString Analysis::getRecordingFilePath(){
    return recordingFilePath;
}

