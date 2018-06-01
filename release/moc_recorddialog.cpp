/****************************************************************************
** Meta object code from reading C++ file 'recorddialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../recorddialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recorddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RecordDialog_t {
    QByteArrayData data[24];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RecordDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RecordDialog_t qt_meta_stringdata_RecordDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "RecordDialog"
QT_MOC_LITERAL(1, 13, 12), // "writeNewData"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "xAxis"
QT_MOC_LITERAL(4, 33, 5), // "yAxis"
QT_MOC_LITERAL(5, 39, 9), // "stopTimer"
QT_MOC_LITERAL(6, 49, 13), // "setProperties"
QT_MOC_LITERAL(7, 63, 9), // "frequency"
QT_MOC_LITERAL(8, 73, 9), // "amplitude"
QT_MOC_LITERAL(9, 83, 8), // "yAxisMax"
QT_MOC_LITERAL(10, 92, 8), // "yAxisMin"
QT_MOC_LITERAL(11, 101, 8), // "xAxisMax"
QT_MOC_LITERAL(12, 110, 8), // "xAxisMin"
QT_MOC_LITERAL(13, 119, 8), // "interval"
QT_MOC_LITERAL(14, 128, 5), // "graph"
QT_MOC_LITERAL(15, 134, 6), // "sensor"
QT_MOC_LITERAL(16, 141, 15), // "showContextMenu"
QT_MOC_LITERAL(17, 157, 3), // "pos"
QT_MOC_LITERAL(18, 161, 16), // "realtimeDataSlot"
QT_MOC_LITERAL(19, 178, 24), // "on_btnDummyGraph_clicked"
QT_MOC_LITERAL(20, 203, 18), // "on_btnStop_clicked"
QT_MOC_LITERAL(21, 222, 28), // "on_btnChangeSettings_clicked"
QT_MOC_LITERAL(22, 251, 25), // "on_sbCounter_valueChanged"
QT_MOC_LITERAL(23, 277, 4) // "arg1"

    },
    "RecordDialog\0writeNewData\0\0xAxis\0yAxis\0"
    "stopTimer\0setProperties\0frequency\0"
    "amplitude\0yAxisMax\0yAxisMin\0xAxisMax\0"
    "xAxisMin\0interval\0graph\0sensor\0"
    "showContextMenu\0pos\0realtimeDataSlot\0"
    "on_btnDummyGraph_clicked\0on_btnStop_clicked\0"
    "on_btnChangeSettings_clicked\0"
    "on_sbCounter_valueChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RecordDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       5,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    9,   65,    2, 0x08 /* Private */,
      16,    1,   84,    2, 0x08 /* Private */,
      18,    0,   87,    2, 0x08 /* Private */,
      19,    0,   88,    2, 0x08 /* Private */,
      20,    0,   89,    2, 0x08 /* Private */,
      21,    0,   90,    2, 0x08 /* Private */,
      22,    1,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,    7,    8,    9,   10,   11,   12,   13,   14,   15,
    QMetaType::Void, QMetaType::QPoint,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,

       0        // eod
};

void RecordDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RecordDialog *_t = static_cast<RecordDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->writeNewData((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->stopTimer(); break;
        case 2: _t->setProperties((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9]))); break;
        case 3: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 4: _t->realtimeDataSlot(); break;
        case 5: _t->on_btnDummyGraph_clicked(); break;
        case 6: _t->on_btnStop_clicked(); break;
        case 7: _t->on_btnChangeSettings_clicked(); break;
        case 8: _t->on_sbCounter_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (RecordDialog::*_t)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RecordDialog::writeNewData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RecordDialog::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RecordDialog::stopTimer)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject RecordDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RecordDialog.data,
      qt_meta_data_RecordDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RecordDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RecordDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RecordDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int RecordDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void RecordDialog::writeNewData(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RecordDialog::stopTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
