/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata0[412];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "getHomeDirectory"
QT_MOC_LITERAL(2, 28, 4), // "QDir"
QT_MOC_LITERAL(3, 33, 0), // ""
QT_MOC_LITERAL(4, 34, 15), // "patientSelected"
QT_MOC_LITERAL(5, 50, 8), // "Patient*"
QT_MOC_LITERAL(6, 59, 7), // "patient"
QT_MOC_LITERAL(7, 67, 14), // "userDeselected"
QT_MOC_LITERAL(8, 82, 14), // "deviceSelected"
QT_MOC_LITERAL(9, 97, 6), // "Device"
QT_MOC_LITERAL(10, 104, 6), // "device"
QT_MOC_LITERAL(11, 111, 14), // "addTextToNotes"
QT_MOC_LITERAL(12, 126, 4), // "text"
QT_MOC_LITERAL(13, 131, 17), // "removePatientSlot"
QT_MOC_LITERAL(14, 149, 8), // "thispath"
QT_MOC_LITERAL(15, 158, 9), // "openNotes"
QT_MOC_LITERAL(16, 168, 31), // "on_btnOpenPatientDialog_clicked"
QT_MOC_LITERAL(17, 200, 30), // "on_btnOpenDeviceDialog_clicked"
QT_MOC_LITERAL(18, 231, 33), // "on_btnOpenRecordingDialog_cli..."
QT_MOC_LITERAL(19, 265, 32), // "on_btnOpenAnalysisDialog_clicked"
QT_MOC_LITERAL(20, 298, 30), // "on_btnOpenExportDialog_clicked"
QT_MOC_LITERAL(21, 329, 30), // "on_btnSelectDirPatient_clicked"
QT_MOC_LITERAL(22, 360, 23), // "on_btnnAddNotes_clicked"
QT_MOC_LITERAL(23, 384, 27) // "on_btnChangePatient_clicked"

    },
    "MainWindow\0getHomeDirectory\0QDir\0\0"
    "patientSelected\0Patient*\0patient\0"
    "userDeselected\0deviceSelected\0Device\0"
    "device\0addTextToNotes\0text\0removePatientSlot\0"
    "thispath\0openNotes\0on_btnOpenPatientDialog_clicked\0"
    "on_btnOpenDeviceDialog_clicked\0"
    "on_btnOpenRecordingDialog_clicked\0"
    "on_btnOpenAnalysisDialog_clicked\0"
    "on_btnOpenExportDialog_clicked\0"
    "on_btnSelectDirPatient_clicked\0"
    "on_btnnAddNotes_clicked\0"
    "on_btnChangePatient_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    3, 0x0a /* Public */,
       4,    1,   90,    3, 0x08 /* Private */,
       7,    0,   93,    3, 0x08 /* Private */,
       8,    1,   94,    3, 0x08 /* Private */,
      11,    1,   97,    3, 0x08 /* Private */,
      13,    1,  100,    3, 0x08 /* Private */,
      15,    0,  103,    3, 0x08 /* Private */,
      16,    0,  104,    3, 0x08 /* Private */,
      17,    0,  105,    3, 0x08 /* Private */,
      18,    0,  106,    3, 0x08 /* Private */,
      19,    0,  107,    3, 0x08 /* Private */,
      20,    0,  108,    3, 0x08 /* Private */,
      21,    0,  109,    3, 0x08 /* Private */,
      22,    0,  110,    3, 0x08 /* Private */,
      23,    0,  111,    3, 0x08 /* Private */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QDir _r = _t->getHomeDirectory();
            if (_a[0]) *reinterpret_cast< QDir*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->patientSelected((*reinterpret_cast< Patient*(*)>(_a[1]))); break;
        case 2: _t->userDeselected(); break;
        case 3: _t->deviceSelected((*reinterpret_cast< Device(*)>(_a[1]))); break;
        case 4: _t->addTextToNotes((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->removePatientSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->openNotes(); break;
        case 7: _t->on_btnOpenPatientDialog_clicked(); break;
        case 8: _t->on_btnOpenDeviceDialog_clicked(); break;
        case 9: _t->on_btnOpenRecordingDialog_clicked(); break;
        case 10: _t->on_btnOpenAnalysisDialog_clicked(); break;
        case 11: _t->on_btnOpenExportDialog_clicked(); break;
        case 12: _t->on_btnSelectDirPatient_clicked(); break;
        case 13: _t->on_btnnAddNotes_clicked(); break;
        case 14: _t->on_btnChangePatient_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
