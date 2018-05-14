#-------------------------------------------------
#
# Project created by QtCreator 2018-04-11T11:06:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = signalSleepDemonstrator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += /usr/include/c++/5.10.0/

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    screens/userdialog.cpp \
    screens/creategraphdialog.cpp \
    models/user.cpp \
    models/patient.cpp \
    models/system.cpp \
    models/device.cpp \
    models/plot.cpp \
    qcustomplot.cpp \
    recorddialog.cpp \
    binarywriter.cpp \
    screens/exportdialog.cpp \
    screens/devicedialog.cpp \
    models/recording.cpp \
    analysisdialog.cpp \
    models/exporting.cpp \
    binaryreader.cpp \
    screens/addnotesdialog.cpp \
    models/analysis.cpp

HEADERS += \
    screens/creategraphdialog.h \
    mainwindow.h \
    screens/userdialog.h \
    models/user.h \
    models/patient.h \
    models/system.h \
    models/device.h \
    models/plot.h \
    qcustomplot.h \
    recorddialog.h \
    binarywriter.h \
    screens/exportdialog.h \
    screens/devicedialog.h \
    models/recording.h \
    analysisdialog.h \
    models/exporting.h \
    binaryreader.h \
    globals.h \
    screens/addnotesdialog.h \
    models/binarypatient.h \
    models/analysis.h

FORMS += \
        mainwindow.ui \
    screens/userdialog.ui \
    screens/creategraphdialog.ui \
    recorddialog.ui \
    screens/exportdialog.ui \
    screens/devicedialog.ui \
    analysisdialog.ui \
    screens/addnotesdialog.ui

DISTFILES += \
    demonstratorSources.pri

include(../signalSleepDemonstrator/Other_files/demonstratorSources.pri)
