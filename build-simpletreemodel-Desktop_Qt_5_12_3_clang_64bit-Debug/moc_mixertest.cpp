/****************************************************************************
** Meta object code from reading C++ file 'mixertest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TreeView/mixertest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mixertest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MixerTest_t {
    QByteArrayData data[11];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MixerTest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MixerTest_t qt_meta_stringdata_MixerTest = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MixerTest"
QT_MOC_LITERAL(1, 10, 10), // "showDetail"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "verticalToggle"
QT_MOC_LITERAL(4, 37, 12), // "qTextChanged"
QT_MOC_LITERAL(5, 50, 18), // "adjustHeaderWidths"
QT_MOC_LITERAL(6, 69, 13), // "columnToggled"
QT_MOC_LITERAL(7, 83, 11), // "itemChanged"
QT_MOC_LITERAL(8, 95, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(9, 112, 16), // "limitSliderMoved"
QT_MOC_LITERAL(10, 129, 24) // "secondaryCheckBoxClicked"

    },
    "MixerTest\0showDetail\0\0verticalToggle\0"
    "qTextChanged\0adjustHeaderWidths\0"
    "columnToggled\0itemChanged\0QTreeWidgetItem*\0"
    "limitSliderMoved\0secondaryCheckBoxClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MixerTest[] = {

 // content:
       8,       // revision
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
       4,    1,   56,    2, 0x0a /* Public */,
       5,    0,   59,    2, 0x0a /* Public */,
       6,    0,   60,    2, 0x0a /* Public */,
       7,    2,   61,    2, 0x0a /* Public */,
       9,    1,   66,    2, 0x0a /* Public */,
      10,    0,   69,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void MixerTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MixerTest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showDetail(); break;
        case 1: _t->verticalToggle(); break;
        case 2: _t->qTextChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->adjustHeaderWidths(); break;
        case 4: _t->columnToggled(); break;
        case 5: _t->itemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->limitSliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->secondaryCheckBoxClicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MixerTest::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_MixerTest.data,
    qt_meta_data_MixerTest,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MixerTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MixerTest::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MixerTest.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::MixerTest"))
        return static_cast< Ui::MixerTest*>(this);
    return QDialog::qt_metacast(_clname);
}

int MixerTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
