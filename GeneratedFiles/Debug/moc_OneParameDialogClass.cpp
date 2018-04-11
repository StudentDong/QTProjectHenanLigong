/****************************************************************************
** Meta object code from reading C++ file 'OneParameDialogClass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OneParameDialogClass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OneParameDialogClass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OneParameDialogClass_t {
    QByteArrayData data[4];
    char stringdata[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OneParameDialogClass_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OneParameDialogClass_t qt_meta_stringdata_OneParameDialogClass = {
    {
QT_MOC_LITERAL(0, 0, 20), // "OneParameDialogClass"
QT_MOC_LITERAL(1, 21, 8), // "onEnsure"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 7) // "onClose"

    },
    "OneParameDialogClass\0onEnsure\0\0onClose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OneParameDialogClass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OneParameDialogClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OneParameDialogClass *_t = static_cast<OneParameDialogClass *>(_o);
        switch (_id) {
        case 0: _t->onEnsure(); break;
        case 1: _t->onClose(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject OneParameDialogClass::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_OneParameDialogClass.data,
      qt_meta_data_OneParameDialogClass,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OneParameDialogClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OneParameDialogClass::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OneParameDialogClass.stringdata))
        return static_cast<void*>(const_cast< OneParameDialogClass*>(this));
    return QDialog::qt_metacast(_clname);
}

int OneParameDialogClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
