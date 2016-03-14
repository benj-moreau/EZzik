/****************************************************************************
** Meta object code from reading C++ file 'EZnotenames.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/EZnotenames.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EZnotenames.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EzNoteNames[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      52,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EzNoteNames[] = {
    "EzNoteNames\0\0recieveTextNotes(std::vector<EzNote*>)\0"
    "recievePianoKey(std::string)\0"
};

void EzNoteNames::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EzNoteNames *_t = static_cast<EzNoteNames *>(_o);
        switch (_id) {
        case 0: _t->recieveTextNotes((*reinterpret_cast< std::vector<EzNote*>(*)>(_a[1]))); break;
        case 1: _t->recievePianoKey((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EzNoteNames::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EzNoteNames::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_EzNoteNames,
      qt_meta_data_EzNoteNames, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EzNoteNames::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EzNoteNames::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EzNoteNames::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EzNoteNames))
        return static_cast<void*>(const_cast< EzNoteNames*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int EzNoteNames::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
