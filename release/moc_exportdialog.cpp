/****************************************************************************
** Meta object code from reading C++ file 'exportdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/exportdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'exportdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ExportDialog_t {
    QByteArrayData data[15];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExportDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExportDialog_t qt_meta_stringdata_ExportDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ExportDialog"
QT_MOC_LITERAL(1, 13, 7), // "prepare"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 4), // "QDir"
QT_MOC_LITERAL(4, 27, 8), // "userPath"
QT_MOC_LITERAL(5, 36, 10), // "exportPath"
QT_MOC_LITERAL(6, 47, 12), // "updateDialog"
QT_MOC_LITERAL(7, 60, 7), // "userDir"
QT_MOC_LITERAL(8, 68, 9), // "exportDir"
QT_MOC_LITERAL(9, 78, 13), // "updateListBox"
QT_MOC_LITERAL(10, 92, 5), // "items"
QT_MOC_LITERAL(11, 98, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(12, 119, 27), // "on_btnSelectPatient_clicked"
QT_MOC_LITERAL(13, 147, 31), // "on_btnSelectExportFiles_clicked"
QT_MOC_LITERAL(14, 179, 20) // "on_btnExport_clicked"

    },
    "ExportDialog\0prepare\0\0QDir\0userPath\0"
    "exportPath\0updateDialog\0userDir\0"
    "exportDir\0updateListBox\0items\0"
    "on_btnCancel_clicked\0on_btnSelectPatient_clicked\0"
    "on_btnSelectExportFiles_clicked\0"
    "on_btnExport_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExportDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x0a /* Public */,
       6,    2,   54,    2, 0x08 /* Private */,
       9,    1,   59,    2, 0x08 /* Private */,
      11,    0,   62,    2, 0x08 /* Private */,
      12,    0,   63,    2, 0x08 /* Private */,
      13,    0,   64,    2, 0x08 /* Private */,
      14,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    7,    8,
    QMetaType::Void, QMetaType::QStringList,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ExportDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExportDialog *_t = static_cast<ExportDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->prepare((*reinterpret_cast< QDir(*)>(_a[1])),(*reinterpret_cast< QDir(*)>(_a[2]))); break;
        case 1: _t->updateDialog((*reinterpret_cast< QDir(*)>(_a[1])),(*reinterpret_cast< QDir(*)>(_a[2]))); break;
        case 2: _t->updateListBox((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 3: _t->on_btnCancel_clicked(); break;
        case 4: _t->on_btnSelectPatient_clicked(); break;
        case 5: _t->on_btnSelectExportFiles_clicked(); break;
        case 6: _t->on_btnExport_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ExportDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ExportDialog.data,
      qt_meta_data_ExportDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ExportDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExportDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExportDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ExportDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
