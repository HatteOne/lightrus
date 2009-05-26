/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created: Mon May 25 21:50:31 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/controller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Controller[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      24,   11,   11,   11, 0x08,
      55,   50,   11,   11, 0x08,
      87,   11,   11,   11, 0x08,
     104,   11,   11,   11, 0x08,
     131,   11,   11,   11, 0x08,
     147,   11,   11,   11, 0x08,
     171,   11,   11,   11, 0x08,
     202,   11,   11,   11, 0x08,
     239,  234,   11,   11, 0x08,
     272,  264,   11,   11, 0x08,
     305,  234,   11,   11, 0x08,
     327,  234,   11,   11, 0x08,
     350,  234,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Controller[] = {
    "Controller\0\0Translate()\0"
    "SetDefaultLightroomPath()\0path\0"
    "ChangeLightroomDirPath(QString)\0"
    "OpenReadmeFile()\0ToggleLanguageToSelected()\0"
    "ExecLightroom()\0CollectUnknownPhrases()\0"
    "StartNewFileTranslate(QString)\0"
    "CurrentFileProgressChanged(int)\0text\0"
    "CopyToClipboard(QString)\0is_need\0"
    "IsPageNotTranslatedNeeded(bool&)\0"
    "OnLogMessage(QString)\0OnInfoMessage(QString)\0"
    "OnErrorMessage(QString)\0"
};

const QMetaObject Controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Controller,
      qt_meta_data_Controller, 0 }
};

const QMetaObject *Controller::metaObject() const
{
    return &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Controller))
        return static_cast<void*>(const_cast< Controller*>(this));
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Translate(); break;
        case 1: SetDefaultLightroomPath(); break;
        case 2: ChangeLightroomDirPath((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: OpenReadmeFile(); break;
        case 4: ToggleLanguageToSelected(); break;
        case 5: ExecLightroom(); break;
        case 6: CollectUnknownPhrases(); break;
        case 7: StartNewFileTranslate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: CurrentFileProgressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: CopyToClipboard((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: IsPageNotTranslatedNeeded((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: OnLogMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: OnInfoMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: OnErrorMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
