/****************************************************************************
** Meta object code from reading C++ file 'sampleeditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/templates/sample/sampleeditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sampleeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SampleEditor_t {
    QByteArrayData data[19];
    char stringdata[241];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SampleEditor_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SampleEditor_t qt_meta_stringdata_SampleEditor = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SampleEditor"
QT_MOC_LITERAL(1, 13, 19), // "updateQuestionCount"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 11), // "addQuestion"
QT_MOC_LITERAL(4, 46, 8), // "question"
QT_MOC_LITERAL(5, 55, 6), // "answer"
QT_MOC_LITERAL(6, 62, 12), // "loadQuestion"
QT_MOC_LITERAL(7, 75, 5), // "index"
QT_MOC_LITERAL(8, 81, 14), // "removeQuestion"
QT_MOC_LITERAL(9, 96, 12), // "saveQuestion"
QT_MOC_LITERAL(10, 109, 14), // "moveQuestionUp"
QT_MOC_LITERAL(11, 124, 16), // "moveQuestionDown"
QT_MOC_LITERAL(12, 141, 15), // "configureUpDown"
QT_MOC_LITERAL(13, 157, 17), // "setEditorsEnabled"
QT_MOC_LITERAL(14, 175, 7), // "enabled"
QT_MOC_LITERAL(15, 183, 9), // "checkName"
QT_MOC_LITERAL(16, 193, 11), // "checkAuthor"
QT_MOC_LITERAL(17, 205, 16), // "updateNameStatus"
QT_MOC_LITERAL(18, 222, 18) // "updateAuthorStatus"

    },
    "SampleEditor\0updateQuestionCount\0\0"
    "addQuestion\0question\0answer\0loadQuestion\0"
    "index\0removeQuestion\0saveQuestion\0"
    "moveQuestionUp\0moveQuestionDown\0"
    "configureUpDown\0setEditorsEnabled\0"
    "enabled\0checkName\0checkAuthor\0"
    "updateNameStatus\0updateAuthorStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SampleEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    2,   80,    2, 0x08 /* Private */,
       6,    1,   85,    2, 0x08 /* Private */,
       8,    0,   88,    2, 0x08 /* Private */,
       9,    0,   89,    2, 0x08 /* Private */,
      10,    0,   90,    2, 0x08 /* Private */,
      11,    0,   91,    2, 0x08 /* Private */,
      12,    0,   92,    2, 0x08 /* Private */,
      13,    1,   93,    2, 0x08 /* Private */,
      15,    0,   96,    2, 0x08 /* Private */,
      16,    0,   97,    2, 0x08 /* Private */,
      17,    0,   98,    2, 0x08 /* Private */,
      18,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SampleEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SampleEditor *_t = static_cast<SampleEditor *>(_o);
        switch (_id) {
        case 0: _t->updateQuestionCount(); break;
        case 1: _t->addQuestion((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->loadQuestion((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->removeQuestion(); break;
        case 4: _t->saveQuestion(); break;
        case 5: _t->moveQuestionUp(); break;
        case 6: _t->moveQuestionDown(); break;
        case 7: _t->configureUpDown(); break;
        case 8: _t->setEditorsEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->checkName(); break;
        case 10: _t->checkAuthor(); break;
        case 11: _t->updateNameStatus(); break;
        case 12: _t->updateAuthorStatus(); break;
        default: ;
        }
    }
}

const QMetaObject SampleEditor::staticMetaObject = {
    { &TemplateEditor::staticMetaObject, qt_meta_stringdata_SampleEditor.data,
      qt_meta_data_SampleEditor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SampleEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SampleEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SampleEditor.stringdata))
        return static_cast<void*>(const_cast< SampleEditor*>(this));
    return TemplateEditor::qt_metacast(_clname);
}

int SampleEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TemplateEditor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
