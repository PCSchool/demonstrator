#ifndef RECORDING_H
#define RECORDING_H

#include <QDialog>
#include <qcustomplot.h>
#include <binarywriter.h>
#include <QDir>

class Recording{
  public:
    //enums
    enum Types{line = 0, bar, histogram, scatter, invalidtype};
    enum Sensors{heartrate = 0, accelerometer, microphone, skintemperature, lightsensor, invalidsensor};

    //constructors
    Recording();
    Recording(QCustomPlot *plot, double frequency, double amplitude, QString type, QString sensor);

    //methods
    void addRecording(QCustomPlot *plot, double frequency, double amplitude, QString type, QString sensor, int duration);
    void changePosition(double x, double y);
    int controlDir(QDir dir);

    //public fields
    QTimer* dataTimer;
    BinaryWriter* writerBuffer;
    BinaryWriter* writerFile;


  public slots:
    void changeSize(int width, int height);

  private:
    //methods
    static Recording::Sensors selectSensor(std::string _s);
    static Recording::Types selectTypes(std::string _s);

    //field
    QCustomPlot *plot;

    QSize size;
    int width;
    int height;
    int xPosLayout;
    int yPosLayout;
    double frequency;
    double amplitude;
    double duration;
    Types type;
    Sensors sensor;
    int secOnDisplay;
    QString pauze;
};

#endif // RECORDING_H
