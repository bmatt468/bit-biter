/****************************************************************************
** Meta object code from reading C++ file 'gameform.h'
**
** Created: Sun Mar 25 23:48:11 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gameform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameForm[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      19,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GameForm[] = {
    "GameForm\0\0closed()\0refreshBoard()\0"
};

const QMetaObject GameForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GameForm,
      qt_meta_data_GameForm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameForm))
        return static_cast<void*>(const_cast< GameForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int GameForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: closed(); break;
        case 1: refreshBoard(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GameForm::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
