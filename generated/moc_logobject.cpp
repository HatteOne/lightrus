/****************************************************************************
** Meta object code from reading C++ file 'logobject.h'
**
** Created: Mon May 25 21:50:31 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/logobject.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LogObject[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      19,   11,   10,   10, 0x05,
      43,   11,   10,   10, 0x05,
      68,   11,   10,   10, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_LogObject[] = {
    "LogObject\0\0message\0SendLogMessage(QString)\0"
    "SendInfoMessage(QString)\0"
    "SendErrorMessage(QString)\0"
};

const QMetaObject LogObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LogObject,
      qt_meta_data_LogObject, 0 }
};

const QMetaObject *LogObject::metaObject() const
{
    return &staticMetaObject;
}

void *LogObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LogObject))
        return static_cast<void*>(const_cast< LogObject*>(this));
    return QObject::qt_metacast(_clname);
}

int LogObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: SendLogMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: SendInfoMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: SendErrorMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void LogObject::SendLogMessage(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LogObject::SendInfoMessage(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LogObject::SendErrorMessage(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
