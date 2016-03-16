/****************************************************************************
** Meta object code from reading C++ file 'EZscore.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/EZscore.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EZscore.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EzScore[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,    8,    8,    8, 0x0a,
      84,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EzScore[] = {
    "EzScore\0\0sendTextNotes(std::vector<EzNote*>)\0"
    "recieveNotes(std::vector<std::string>)\0"
    "drawBar(int)\0"
};

void EzScore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EzScore *_t = static_cast<EzScore *>(_o);
        switch (_id) {
        case 0: _t->sendTextNotes((*reinterpret_cast< std::vector<EzNote*>(*)>(_a[1]))); break;
        case 1: _t->recieveNotes((*reinterpret_cast< std::vector<std::string>(*)>(_a[1]))); break;
        case 2: _t->drawBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EzScore::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EzScore::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_EzScore,
      qt_meta_data_EzScore, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EzScore::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EzScore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EzScore::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EzScore))
        return static_cast<void*>(const_cast< EzScore*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int EzScore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void EzScore::sendTextNotes(std::vector<EzNote*> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
