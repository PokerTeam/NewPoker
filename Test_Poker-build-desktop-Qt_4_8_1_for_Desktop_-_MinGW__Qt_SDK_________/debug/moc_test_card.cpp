/****************************************************************************
** Meta object code from reading C++ file 'test_card.h'
**
** Created: Wed 5. Jun 23:16:36 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Test_Poker_Bloov/test_card.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'test_card.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Test_Card[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      26,   10,   10,   10, 0x08,
      36,   10,   10,   10, 0x08,
      57,   10,   10,   10, 0x08,
      73,   10,   10,   10, 0x08,
      93,   10,   10,   10, 0x08,
     108,   10,   10,   10, 0x08,
     124,   10,   10,   10, 0x08,
     135,   10,   10,   10, 0x08,
     150,   10,   10,   10, 0x08,
     160,   10,   10,   10, 0x08,
     177,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Test_Card[] = {
    "Test_Card\0\0getSuit_data()\0getSuit()\0"
    "getCardNumber_data()\0getCardNumber()\0"
    "getCardImage_data()\0getCardImage()\0"
    "isEquals_data()\0isEquals()\0compare_data()\0"
    "compare()\0isOrdered_data()\0isOrdered()\0"
};

void Test_Card::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Test_Card *_t = static_cast<Test_Card *>(_o);
        switch (_id) {
        case 0: _t->getSuit_data(); break;
        case 1: _t->getSuit(); break;
        case 2: _t->getCardNumber_data(); break;
        case 3: _t->getCardNumber(); break;
        case 4: _t->getCardImage_data(); break;
        case 5: _t->getCardImage(); break;
        case 6: _t->isEquals_data(); break;
        case 7: _t->isEquals(); break;
        case 8: _t->compare_data(); break;
        case 9: _t->compare(); break;
        case 10: _t->isOrdered_data(); break;
        case 11: _t->isOrdered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Test_Card::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Test_Card::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Test_Card,
      qt_meta_data_Test_Card, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Test_Card::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Test_Card::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Test_Card::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Test_Card))
        return static_cast<void*>(const_cast< Test_Card*>(this));
    return QObject::qt_metacast(_clname);
}

int Test_Card::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
