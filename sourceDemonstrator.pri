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
    screens/addnotesdialog.cpp

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
    models/binarypatient.h

FORMS += \
        mainwindow.ui \
    screens/userdialog.ui \
    screens/creategraphdialog.ui \
    recorddialog.ui \
    screens/exportdialog.ui \
    screens/devicedialog.ui \
    analysisdialog.ui \
    screens/addnotesdialog.ui
