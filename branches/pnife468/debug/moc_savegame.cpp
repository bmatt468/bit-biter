/****************************************************************************
** Meta object code from reading C++ file 'savegame.h'
**
** Created: Sun Apr 1 17:50:19 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../savegame.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'savegame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SaveGame[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,    9,    9,    9, 0x08,
      55,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SaveGame[] = {
    "SaveGame\0\0ans\0responseGiven(bool)\0"
    "on_save_no_clicked()\0on_save_yes_clicked()\0"
};

const QMetaObject SaveGame::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SaveGame,
      qt_meta_data_SaveGame, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SaveGame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SaveGame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SaveGame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SaveGame))
        return static_cast<void*>(const_cast< SaveGame*>(this));
    return QDialog::qt_metacast(_clname);
}

int SaveGame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: responseGiven((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: on_save_no_clicked(); break;
        case 2: on_save_yes_clicked(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SaveGame::responseGiven(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
