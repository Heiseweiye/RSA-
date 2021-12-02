/****************************************************************************
** Meta object code from reading C++ file 'RSA_DE.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Src/RSA_DE.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RSA_DE.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RSA_DE_t {
    QByteArrayData data[10];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RSA_DE_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RSA_DE_t qt_meta_stringdata_RSA_DE = {
    {
QT_MOC_LITERAL(0, 0, 6), // "RSA_DE"
QT_MOC_LITERAL(1, 7, 8), // "OnbtnGen"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 7), // "OnbtnEn"
QT_MOC_LITERAL(4, 25, 9), // "OnbtnOpen"
QT_MOC_LITERAL(5, 35, 9), // "OnbtnSave"
QT_MOC_LITERAL(6, 45, 12), // "GennarateKey"
QT_MOC_LITERAL(7, 58, 6), // "Encode"
QT_MOC_LITERAL(8, 65, 6), // "Decode"
QT_MOC_LITERAL(9, 72, 6) // "Sel_DE"

    },
    "RSA_DE\0OnbtnGen\0\0OnbtnEn\0OnbtnOpen\0"
    "OnbtnSave\0GennarateKey\0Encode\0Decode\0"
    "Sel_DE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RSA_DE[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RSA_DE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RSA_DE *_t = static_cast<RSA_DE *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->OnbtnGen();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->OnbtnEn();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { int _r = _t->OnbtnOpen();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->OnbtnSave();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: _t->GennarateKey(); break;
        case 5: _t->Encode(); break;
        case 6: _t->Decode(); break;
        case 7: _t->Sel_DE(); break;
        default: ;
        }
    }
}

const QMetaObject RSA_DE::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RSA_DE.data,
      qt_meta_data_RSA_DE,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RSA_DE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RSA_DE::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RSA_DE.stringdata0))
        return static_cast<void*>(const_cast< RSA_DE*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int RSA_DE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
