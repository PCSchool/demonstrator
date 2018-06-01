/****************************************************************************
** Meta object code from reading C++ file 'userdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../screens/userdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserDialog_t {
    QByteArrayData data[17];
    char stringdata0[250];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserDialog_t qt_meta_stringdata_UserDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "UserDialog"
QT_MOC_LITERAL(1, 11, 17), // "newPatientCreated"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "Patient*"
QT_MOC_LITERAL(4, 39, 7), // "patient"
QT_MOC_LITERAL(5, 47, 10), // "newPatient"
QT_MOC_LITERAL(6, 58, 7), // "Patient"
QT_MOC_LITERAL(7, 66, 13), // "removePatient"
QT_MOC_LITERAL(8, 80, 4), // "path"
QT_MOC_LITERAL(9, 85, 22), // "on_btnRegister_clicked"
QT_MOC_LITERAL(10, 108, 19), // "on_cbO_stateChanged"
QT_MOC_LITERAL(11, 128, 4), // "arg1"
QT_MOC_LITERAL(12, 133, 19), // "on_cbV_stateChanged"
QT_MOC_LITERAL(13, 153, 19), // "on_cbM_stateChanged"
QT_MOC_LITERAL(14, 173, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(15, 194, 27), // "on_btnSelectPatient_clicked"
QT_MOC_LITERAL(16, 222, 27) // "on_btnDeletePatient_clicked"

    },
    "UserDialog\0newPatientCreated\0\0Patient*\0"
    "patient\0newPatient\0Patient\0removePatient\0"
    "path\0on_btnRegister_clicked\0"
    "on_cbO_stateChanged\0arg1\0on_cbV_stateChanged\0"
    "on_cbM_stateChanged\0on_btnCancel_clicked\0"
    "on_btnSelectPatient_clicked\0"
    "on_btnDeletePatient_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,
       7,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   73,    2, 0x08 /* Private */,
      10,    1,   74,    2, 0x08 /* Private */,
      12,    1,   77,    2, 0x08 /* Private */,
      13,    1,   80,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,
      15,    0,   84,    2, 0x08 /* Private */,
      16,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UserDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserDialog *_t = static_cast<UserDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newPatientCreated((*reinterpret_cast< Patient*(*)>(_a[1]))); break;
        case 1: _t->newPatient((*reinterpret_cast< Patient*(*)>(_a[1]))); break;
        case 2: _t->removePatient((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_btnRegister_clicked(); break;
        case 4: _t->on_cbO_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_cbV_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_cbM_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_btnCancel_clicked(); break;
        case 8: _t->on_btnSelectPatient_clicked(); break;
        case 9: _t->on_btnDeletePatient_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (UserDialog::*_t)(Patient * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserDialog::newPatientCreated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (UserDialog::*_t)(Patient * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserDialog::newPatient)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (UserDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserDialog::removePatient)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject UserDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_UserDialog.data,
      qt_meta_data_UserDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UserDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int UserDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void UserDialog::newPatientCreated(Patient * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UserDialog::newPatient(Patient * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UserDialog::removePatient(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
