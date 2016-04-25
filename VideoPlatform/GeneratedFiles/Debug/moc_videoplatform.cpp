/****************************************************************************
** Meta object code from reading C++ file 'videoplatform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../videoplatform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videoplatform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VideoPlatform_t {
    QByteArrayData data[11];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoPlatform_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoPlatform_t qt_meta_stringdata_VideoPlatform = {
    {
QT_MOC_LITERAL(0, 0, 13), // "VideoPlatform"
QT_MOC_LITERAL(1, 14, 12), // "change_style"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "screen_full"
QT_MOC_LITERAL(4, 40, 13), // "screen_normal"
QT_MOC_LITERAL(5, 54, 12), // "show_video_1"
QT_MOC_LITERAL(6, 67, 12), // "show_video_4"
QT_MOC_LITERAL(7, 80, 24), // "on_btnMenu_Close_clicked"
QT_MOC_LITERAL(8, 105, 22), // "on_btnMenu_Min_clicked"
QT_MOC_LITERAL(9, 128, 25), // "on_treeMain_doubleClicked"
QT_MOC_LITERAL(10, 154, 5) // "index"

    },
    "VideoPlatform\0change_style\0\0screen_full\0"
    "screen_normal\0show_video_1\0show_video_4\0"
    "on_btnMenu_Close_clicked\0"
    "on_btnMenu_Min_clicked\0on_treeMain_doubleClicked\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoPlatform[] = {

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
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    1,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   10,

       0        // eod
};

void VideoPlatform::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoPlatform *_t = static_cast<VideoPlatform *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->change_style(); break;
        case 1: _t->screen_full(); break;
        case 2: _t->screen_normal(); break;
        case 3: _t->show_video_1(); break;
        case 4: _t->show_video_4(); break;
        case 5: _t->on_btnMenu_Close_clicked(); break;
        case 6: _t->on_btnMenu_Min_clicked(); break;
        case 7: _t->on_treeMain_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject VideoPlatform::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VideoPlatform.data,
      qt_meta_data_VideoPlatform,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VideoPlatform::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoPlatform::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VideoPlatform.stringdata0))
        return static_cast<void*>(const_cast< VideoPlatform*>(this));
    return QDialog::qt_metacast(_clname);
}

int VideoPlatform::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
