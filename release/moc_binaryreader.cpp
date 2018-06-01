/****************************************************************************
** Meta object code from reading C++ file 'binaryreader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../binaryreader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'binaryreader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BinaryReader_t {
    QByteArrayData data[15];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BinaryReader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BinaryReader_t qt_meta_stringdata_BinaryReader = {
    {
QT_MOC_LITERAL(0, 0, 12), // "BinaryReader"
QT_MOC_LITERAL(1, 13, 5), // "start"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 8), // "finished"
QT_MOC_LITERAL(4, 29, 5), // "error"
QT_MOC_LITERAL(5, 35, 20), // "writeNewBufferToFile"
QT_MOC_LITERAL(6, 56, 8), // "fileFull"
QT_MOC_LITERAL(7, 65, 10), // "bufferFull"
QT_MOC_LITERAL(8, 76, 5), // "array"
QT_MOC_LITERAL(9, 82, 20), // "QVector<TimePointer>"
QT_MOC_LITERAL(10, 103, 6), // "vector"
QT_MOC_LITERAL(11, 110, 6), // "setDir"
QT_MOC_LITERAL(12, 117, 4), // "QDir"
QT_MOC_LITERAL(13, 122, 3), // "dir"
QT_MOC_LITERAL(14, 126, 17) // "writeBufferToFile"

    },
    "BinaryReader\0start\0\0finished\0error\0"
    "writeNewBufferToFile\0fileFull\0bufferFull\0"
    "array\0QVector<TimePointer>\0vector\0"
    "setDir\0QDir\0dir\0writeBufferToFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BinaryReader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    1,   56,    2, 0x06 /* Public */,
       5,    0,   59,    2, 0x06 /* Public */,
       6,    0,   60,    2, 0x06 /* Public */,
       7,    2,   61,    2, 0x06 /* Public */,
      11,    1,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    2,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 9,    8,   10,
    QMetaType::Void, 0x80000000 | 12,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 9,    8,   10,

       0        // eod
};

void BinaryReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BinaryReader *_t = static_cast<BinaryReader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->start(); break;
        case 1: _t->finished(); break;
        case 2: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->writeNewBufferToFile(); break;
        case 4: _t->fileFull(); break;
        case 5: _t->bufferFull((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QVector<TimePointer>(*)>(_a[2]))); break;
        case 6: _t->setDir((*reinterpret_cast< QDir(*)>(_a[1]))); break;
        case 7: _t->writeBufferToFile((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QVector<TimePointer>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (BinaryReader::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BinaryReader::start)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BinaryReader::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BinaryReader::finished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (BinaryReader::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BinaryReader::error)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (BinaryReader::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BinaryReader::writeNewBufferToFile)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (BinaryReader::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BinaryReader::fileFull)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (BinaryReader::*_t)(QByteArray , QVector<TimePointer> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BinaryReader::bufferFull)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (BinaryReader::*_t)(QDir );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BinaryReader::setDir)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject BinaryReader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BinaryReader.data,
      qt_meta_data_BinaryReader,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BinaryReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BinaryReader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BinaryReader.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BinaryReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void BinaryReader::start()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BinaryReader::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BinaryReader::error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BinaryReader::writeNewBufferToFile()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void BinaryReader::fileFull()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void BinaryReader::bufferFull(QByteArray _t1, QVector<TimePointer> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void BinaryReader::setDir(QDir _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
