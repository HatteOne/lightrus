/****************************************************************************
** Meta object code from reading C++ file 'maindialog.h'
**
** Created: Mon May 25 21:50:31 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/maindialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maindialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainDialog[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      24,   11,   11,   11, 0x05,
      50,   11,   11,   11, 0x05,
      82,   11,   11,   11, 0x05,
     106,   11,   11,   11, 0x05,
     123,   11,   11,   11, 0x05,
     150,   11,   11,   11, 0x05,
     166,   11,   11,   11, 0x05,
     204,  199,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     229,   11,   11,   11, 0x08,
     242,   11,   11,   11, 0x08,
     255,   11,   11,   11, 0x08,
     281,  270,   11,   11, 0x08,
     302,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainDialog[] = {
    "MainDialog\0\0Translate()\0"
    "SetDefaultLightroomPath()\0"
    "ChangeLightroomDirPath(QString)\0"
    "CollectUnknownPhrases()\0OpenReadmeFile()\0"
    "ToggleLanguageToSelected()\0ExecLightroom()\0"
    "IsPageNotTranslatedNeeded(bool&)\0text\0"
    "CopyToClipboard(QString)\0ToNextPage()\0"
    "ToPrevPage()\0BrowseFolder()\0page_index\0"
    "OnPageActivated(int)\0CopyMailTextToClipboard()\0"
};

const QMetaObject MainDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MainDialog,
      qt_meta_data_MainDialog, 0 }
};

const QMetaObject *MainDialog::metaObject() const
{
    return &staticMetaObject;
}

void *MainDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainDialog))
        return static_cast<void*>(const_cast< MainDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MainDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Translate(); break;
        case 1: SetDefaultLightroomPath(); break;
        case 2: ChangeLightroomDirPath((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: CollectUnknownPhrases(); break;
        case 4: OpenReadmeFile(); break;
        case 5: ToggleLanguageToSelected(); break;
        case 6: ExecLightroom(); break;
        case 7: IsPageNotTranslatedNeeded((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: CopyToClipboard((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: ToNextPage(); break;
        case 10: ToPrevPage(); break;
        case 11: BrowseFolder(); break;
        case 12: OnPageActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: CopyMailTextToClipboard(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MainDialog::Translate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MainDialog::SetDefaultLightroomPath()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainDialog::ChangeLightroomDirPath(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainDialog::CollectUnknownPhrases()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MainDialog::OpenReadmeFile()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void MainDialog::ToggleLanguageToSelected()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MainDialog::ExecLightroom()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void MainDialog::IsPageNotTranslatedNeeded(bool & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainDialog::CopyToClipboard(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
