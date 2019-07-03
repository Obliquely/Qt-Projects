/****************************************************************************
** Meta object code from reading C++ file 'mixeroptionsbutton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TreeView/mixeroptionsbutton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mixeroptionsbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MixerOptionsButton_t {
    QByteArrayData data[7];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MixerOptionsButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MixerOptionsButton_t qt_meta_stringdata_MixerOptionsButton = {
    {
QT_MOC_LITERAL(0, 0, 18), // "MixerOptionsButton"
QT_MOC_LITERAL(1, 19, 15), // "overrideChecked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "state"
QT_MOC_LITERAL(4, 42, 15), // "panSliderOption"
QT_MOC_LITERAL(5, 58, 18), // "reverbSliderOption"
QT_MOC_LITERAL(6, 77, 18) // "chorusSliderOption"

    },
    "MixerOptionsButton\0overrideChecked\0\0"
    "state\0panSliderOption\0reverbSliderOption\0"
    "chorusSliderOption"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MixerOptionsButton[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       5,    1,   40,    2, 0x0a /* Public */,
       6,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void MixerOptionsButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MixerOptionsButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->overrideChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->panSliderOption((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->reverbSliderOption((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->chorusSliderOption((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MixerOptionsButton::staticMetaObject = { {
    &QToolButton::staticMetaObject,
    qt_meta_stringdata_MixerOptionsButton.data,
    qt_meta_data_MixerOptionsButton,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MixerOptionsButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MixerOptionsButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MixerOptionsButton.stringdata0))
        return static_cast<void*>(this);
    return QToolButton::qt_metacast(_clname);
}

int MixerOptionsButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
