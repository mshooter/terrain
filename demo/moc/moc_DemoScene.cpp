/****************************************************************************
** Meta object code from reading C++ file 'DemoScene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/DemoScene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DemoScene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DemoScene_t {
    QByteArrayData data[21];
    char stringdata0[236];
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
QT_MOC_LITERAL(4, 30, 12), // "nextMaterial"
QT_MOC_LITERAL(5, 43, 15), // "changeFrequency"
QT_MOC_LITERAL(6, 59, 10), // "_frequency"
QT_MOC_LITERAL(7, 70, 15), // "changeAmplitude"
QT_MOC_LITERAL(8, 86, 10), // "_amplitude"
QT_MOC_LITERAL(9, 97, 10), // "changeSeed"
QT_MOC_LITERAL(10, 108, 5), // "_seed"
QT_MOC_LITERAL(11, 114, 16), // "changeResolution"
QT_MOC_LITERAL(12, 131, 11), // "_resolution"
QT_MOC_LITERAL(13, 143, 13), // "changeOctaves"
QT_MOC_LITERAL(14, 157, 8), // "_octaves"
QT_MOC_LITERAL(15, 166, 17), // "changePersistence"
QT_MOC_LITERAL(16, 184, 12), // "_persistence"
QT_MOC_LITERAL(17, 197, 13), // "changeTerrain"
QT_MOC_LITERAL(18, 211, 6), // "_model"
QT_MOC_LITERAL(19, 218, 9), // "exporting"
QT_MOC_LITERAL(20, 228, 7) // "_export"

    },
    "DemoScene\0rotating\0\0_rotating\0"
    "nextMaterial\0changeFrequency\0_frequency\0"
    "changeAmplitude\0_amplitude\0changeSeed\0"
    "_seed\0changeResolution\0_resolution\0"
    "changeOctaves\0_octaves\0changePersistence\0"
    "_persistence\0changeTerrain\0_model\0"
    "exporting\0_export"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DemoScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x0a /* Public */,
       4,    0,   67,    2, 0x0a /* Public */,
       5,    1,   68,    2, 0x0a /* Public */,
       7,    1,   71,    2, 0x0a /* Public */,
       9,    1,   74,    2, 0x0a /* Public */,
      11,    1,   77,    2, 0x0a /* Public */,
      13,    1,   80,    2, 0x0a /* Public */,
      15,    1,   83,    2, 0x0a /* Public */,
      17,    1,   86,    2, 0x0a /* Public */,
      19,    1,   89,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Bool,   20,

       0        // eod
};

void DemoScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DemoScene *_t = static_cast<DemoScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rotating((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->nextMaterial(); break;
        case 2: _t->changeFrequency((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->changeAmplitude((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->changeSeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->changeResolution((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->changeOctaves((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->changePersistence((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->changeTerrain((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->exporting((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DemoScene::staticMetaObject = {
    { &Scene::staticMetaObject, qt_meta_stringdata_DemoScene.data,
      qt_meta_data_DemoScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DemoScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DemoScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
