/****************************************************************************
** Meta object code from reading C++ file 'exporting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../models/exporting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'exporting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Exporting_t {
    QByteArrayData data[8];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Exporting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Exporting_t qt_meta_stringdata_Exporting = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Exporting"
QT_MOC_LITERAL(1, 10, 11), // "updateReady"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "QDir"
QT_MOC_LITERAL(4, 28, 7), // "userDir"
QT_MOC_LITERAL(5, 36, 9), // "exportDir"
QT_MOC_LITERAL(6, 46, 14), // "readyToListBox"
QT_MOC_LITERAL(7, 61, 10) // "stringlist"

    },
    "Exporting\0updateReady\0\0QDir\0userDir\0"
    "exportDir\0readyToListBox\0stringlist"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Exporting[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       6,    1,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Int, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Int, QMetaType::QStringList,    7,

       0        // eod
};

void Exporting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Exporting *_t = static_cast<Exporting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->updateReady((*reinterpret_cast< QDir(*)>(_a[1])),(*reinterpret_cast< QDir(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->readyToListBox((*reinterpret_cast< QStringList(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef int (Exporting::*_t)(QDir , QDir );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Exporting::updateReady)) {
                *result = 0;
                return;
            }
        }
        {
            typedef int (Exporting::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Exporting::readyToListBox)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Exporting::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Exporting.data,
      qt_meta_data_Exporting,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Exporting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Exporting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Exporting.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Exporting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
int Exporting::updateReady(QDir _t1, QDir _t2)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
int Exporting::readyToListBox(QStringList _t1)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
