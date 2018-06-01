/****************************************************************************
** Meta object code from reading C++ file 'analysisdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/analysisdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'analysisdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AnalysisDialog_t {
    QByteArrayData data[10];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnalysisDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnalysisDialog_t qt_meta_stringdata_AnalysisDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "AnalysisDialog"
QT_MOC_LITERAL(1, 15, 9), // "drawGraph"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 20), // "QVector<TimePointer>"
QT_MOC_LITERAL(4, 47, 6), // "vector"
QT_MOC_LITERAL(5, 54, 28), // "on_btnReadBinaryFile_clicked"
QT_MOC_LITERAL(6, 83, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(7, 104, 29), // "on_btnSelectRecording_clicked"
QT_MOC_LITERAL(8, 134, 30), // "on_btnReadSpecificFile_clicked"
QT_MOC_LITERAL(9, 165, 29) // "on_btnFilterRecording_clicked"

    },
    "AnalysisDialog\0drawGraph\0\0"
    "QVector<TimePointer>\0vector\0"
    "on_btnReadBinaryFile_clicked\0"
    "on_btnCancel_clicked\0on_btnSelectRecording_clicked\0"
    "on_btnReadSpecificFile_clicked\0"
    "on_btnFilterRecording_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnalysisDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AnalysisDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AnalysisDialog *_t = static_cast<AnalysisDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->drawGraph((*reinterpret_cast< QVector<TimePointer>(*)>(_a[1]))); break;
        case 1: _t->on_btnReadBinaryFile_clicked(); break;
        case 2: _t->on_btnCancel_clicked(); break;
        case 3: _t->on_btnSelectRecording_clicked(); break;
        case 4: _t->on_btnReadSpecificFile_clicked(); break;
        case 5: _t->on_btnFilterRecording_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject AnalysisDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AnalysisDialog.data,
      qt_meta_data_AnalysisDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AnalysisDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnalysisDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AnalysisDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AnalysisDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
