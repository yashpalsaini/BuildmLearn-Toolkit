/****************************************************************************
** Meta object code from reading C++ file 'samplesimulator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/templates/sample/samplesimulator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'samplesimulator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SampleSimulator_t {
    QByteArrayData data[10];
    char stringdata[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SampleSimulator_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SampleSimulator_t qt_meta_stringdata_SampleSimulator = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SampleSimulator"
QT_MOC_LITERAL(1, 16, 15), // "startSimulation"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 14), // "stopSimulation"
QT_MOC_LITERAL(4, 48, 6), // "goBack"
QT_MOC_LITERAL(5, 55, 5), // "start"
QT_MOC_LITERAL(6, 61, 7), // "restart"
QT_MOC_LITERAL(7, 69, 4), // "exit"
QT_MOC_LITERAL(8, 74, 14), // "prepareSummary"
QT_MOC_LITERAL(9, 89, 17) // "questionSubmitted"

    },
    "SampleSimulator\0startSimulation\0\0"
    "stopSimulation\0goBack\0start\0restart\0"
    "exit\0prepareSummary\0questionSubmitted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SampleSimulator[] = {

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
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SampleSimulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SampleSimulator *_t = static_cast<SampleSimulator *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->startSimulation();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->stopSimulation();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->goBack();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->start(); break;
        case 4: _t->restart(); break;
        case 5: _t->exit(); break;
        case 6: _t->prepareSummary(); break;
        case 7: _t->questionSubmitted(); break;
        default: ;
        }
    }
}

const QMetaObject SampleSimulator::staticMetaObject = {
    { &TemplateSimulator::staticMetaObject, qt_meta_stringdata_SampleSimulator.data,
      qt_meta_data_SampleSimulator,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SampleSimulator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SampleSimulator::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SampleSimulator.stringdata))
        return static_cast<void*>(const_cast< SampleSimulator*>(this));
    return TemplateSimulator::qt_metacast(_clname);
}

int SampleSimulator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TemplateSimulator::qt_metacall(_c, _id, _a);
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
