#include "mainwindow.h"
#include <QApplication>
#include <QPalette>
#include <design/demonstratorstyle.h>
#include <QLatin1String>

int main(int argc, char *argv[])
{
    //clear memory before start

    QApplication a(argc, argv);
    //a.setStyle(new DemonstratorStyle);
    MainWindow w;
    //w.setStyle(new DemonstratorStyle);
    w.show();

    return a.exec();
}
