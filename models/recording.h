#ifndef RECORDING_H
#define RECORDING_H

#include <QDialog>
#include <qcustomplot.h>
#include <binarywriter.h>

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

    //public fields
    QTimer* dataTimer;
    BinaryWriter* writerBuffer;
    BinaryWriter* writerFile;
    // getters/setters for properties
    Types getType();
    void setType(QString type);
    Sensors getSensors();
    void setSensors(QString sensors);
    QCustomPlot* getPlot();
    QSize getSize();
    void setSize(QSize size);
    double getAmplitude();
    void setAmplitude(double amplitude);
    double getFrequency();
    void setFrequency(double frequency);
    void setPauze(QString text);
    QString getPauze();

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
