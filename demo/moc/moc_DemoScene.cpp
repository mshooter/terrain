/****************************************************************************
** Meta object code from reading C++ file 'DemoScene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/DemoScene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DemoScene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DemoScene_t {
    QByteArrayData data[10];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DemoScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DemoScene_t qt_meta_stringdata_DemoScene = {
    {
QT_MOC_LITERAL(0, 0, 9), // "DemoScene"
QT_MOC_LITERAL(1, 10, 8), // "rotating"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "_rotating"
QT_MOC_LITERAL(4, 30, 19), // "generateNewGeometry"
QT_MOC_LITERAL(5, 50, 12), // "nextMaterial"
QT_MOC_LITERAL(6, 63, 15), // "changeFrequency"
QT_MOC_LITERAL(7, 79, 10), // "_frequency"
QT_MOC_LITERAL(8, 90, 15), // "changeAmplitude"
QT_MOC_LITERAL(9, 106, 10) // "_amplitude"

    },
    "DemoScene\0rotating\0\0_rotating\0"
    "generateNewGeometry\0nextMaterial\0"
    "changeFrequency\0_frequency\0changeAmplitude\0"
    "_amplitude"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DemoScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    0,   42,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,
       6,    1,   44,    2, 0x0a /* Public */,
       8,    1,   47,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void DemoScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DemoScene *_t = static_cast<DemoScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rotating((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->generateNewGeometry(); break;
        case 2: _t->nextMaterial(); break;
        case 3: _t->changeFrequency((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->changeAmplitude((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DemoScene::staticMetaObject = {
    { &Scene::staticMetaObject, qt_meta_stringdata_DemoScene.data,
      qt_meta_data_DemoScene,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DemoScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DemoScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DemoScene.stringdata0))
        return static_cast<void*>(const_cast< DemoScene*>(this));
    return Scene::qt_metacast(_clname);
}

int DemoScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Scene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
