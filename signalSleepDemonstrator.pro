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
    analysisdialog.cpp \
    binaryreader.cpp \
    binarywriter.cpp \
    qcustomplot.cpp \
    recorddialog.cpp \
    screens/addnotesdialog.cpp \
    screens/creategraphdialog.cpp \
    screens/devicedialog.cpp \
    screens/exportdialog.cpp \
    screens/userdialog.cpp \
    models/analysis.cpp \
    models/device.cpp \
    models/exporting.cpp \
    models/graph.cpp \
    models/patient.cpp \
    models/plot.cpp \
    models/recording.cpp \
    models/system.cpp \
    models/user.cpp \
    dsp_filters/filters/Bessel.cpp \
    dsp_filters/filters/Biquad.cpp \
    dsp_filters/filters/Butterworth.cpp \
    dsp_filters/filters/Cascade.cpp \
    dsp_filters/filters/ChebyshevI.cpp \
    dsp_filters/filters/ChebyshevII.cpp \
    dsp_filters/filters/Custom.cpp \
    dsp_filters/filters/Design.cpp \
    dsp_filters/filters/Documentation.cpp \
    dsp_filters/filters/Elliptic.cpp \
    dsp_filters/filters/Filter.cpp \
    dsp_filters/filters/Legendre.cpp \
    dsp_filters/filters/Param.cpp \
    dsp_filters/filters/PoleFilter.cpp \
    dsp_filters/filters/RBJ.cpp \
    dsp_filters/filters/RootFinder.cpp \
    dsp_filters/filters/State.cpp \
    dsp_filters/dsp_filters.cpp \
    design/demonstratorstyle.cpp

HEADERS += \
    analysisdialog.h \
    binaryreader.h \
    binarywriter.h \
    globals.h \
    mainwindow.h \
    qcustomplot.h \
    recorddialog.h \
    analysisdialog.h \
    screens/addnotesdialog.h \
    screens/creategraphdialog.h \
    screens/devicedialog.h \
    screens/exportdialog.h \
    screens/userdialog.h \
    models/analysis.h \
    models/binarypatient.h \
    models/device.h \
    models/exporting.h \
    models/graph.h \
    models/patient.h \
    models/plot.h \
    models/recording.h \
    models/system.h \
    models/user.h \
    exceptions/exceptionemptyform.h \
    exceptions/exceptionfilenotfound.h \
    exceptions/exceptioninvalidenumtype.h \
    exceptions/exceptioninvalidparameters.h \
    dsp_filters/filters/Bessel.h \
    dsp_filters/filters/Biquad.h \
    dsp_filters/filters/Butterworth.h \
    dsp_filters/filters/Cascade.h \
    dsp_filters/filters/ChebyshevI.h \
    dsp_filters/filters/ChebyshevII.h \
    dsp_filters/filters/Custom.h \
    dsp_filters/filters/Design.h \
    dsp_filters/filters/Elliptic.h \
    dsp_filters/filters/Filter.h \
    dsp_filters/filters/Layout.h \
    dsp_filters/filters/Legendre.h \
    dsp_filters/filters/MathSupplement.h \
    dsp_filters/filters/Params.h \
    dsp_filters/filters/PoleFilter.h \
    dsp_filters/filters/RBJ.h \
    dsp_filters/filters/RootFinder.h \
    dsp_filters/filters/SmoothedFilter.h \
    dsp_filters/filters/State.h \
    dsp_filters/filters/Types.h \
    dsp_filters/filters/Utilities.h \
    dsp_filters/dsp_filters.h \
    design/demonstratorstyle.h \
    exceptions/exceptioninvalidpathchosen.h

FORMS += \
        mainwindow.ui \
    analysisdialog.ui \
    screens/addnotesdialog.ui \
    screens/creategraphdialog.ui \
    screens/devicedialog.ui \
    screens/exportdialog.ui \
    screens/userdialog.ui \
    recorddialog.ui

#DISTFILES += \
#    demonstratorSources.pri

#include(../signalSleepDemonstrator/Other_files/demonstratorSources.pri)

DISTFILES += \
    F:/texture_1.png \
    F:/texture_2.jpg
