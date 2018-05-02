#ifndef EXPORTING_H
#define EXPORTING_H

#include <QObject>

class Exporting : public QObject
{
    Q_OBJECT
public:
    explicit Exporting(QObject *parent = nullptr);

signals:

public slots:
};

#endif // EXPORTING_H