/****************************************************************************
** Meta object code from reading C++ file 'ide.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Kel-morian-IDE/ide.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ide.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IDE_t {
    QByteArrayData data[7];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IDE_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IDE_t qt_meta_stringdata_IDE = {
    {
QT_MOC_LITERAL(0, 0, 3), // "IDE"
QT_MOC_LITERAL(1, 4, 15), // "getSelectedItem"
QT_MOC_LITERAL(2, 20, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(3, 35, 0), // ""
QT_MOC_LITERAL(4, 36, 14), // "initWidgetList"
QT_MOC_LITERAL(5, 51, 10), // "initCanvas"
QT_MOC_LITERAL(6, 62, 4) // "init"

    },
    "IDE\0getSelectedItem\0QGraphicsItem*\0\0"
    "initWidgetList\0initCanvas\0init"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IDE[] = {

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
       1,    0,   34,    3, 0x08 /* Private */,
       4,    0,   35,    3, 0x08 /* Private */,
       5,    0,   36,    3, 0x08 /* Private */,
       6,    0,   37,    3, 0x08 /* Private */,

 // slots: parameters
    0x80000000 | 2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void IDE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IDE *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QGraphicsItem* _r = _t->getSelectedItem();
            if (_a[0]) *reinterpret_cast< QGraphicsItem**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->initWidgetList(); break;
        case 2: _t->initCanvas(); break;
        case 3: _t->init(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject IDE::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_IDE.data,
    qt_meta_data_IDE,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IDE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IDE::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IDE.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int IDE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
