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
    QByteArrayData data[12];
    char stringdata0[277];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IDE_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IDE_t qt_meta_stringdata_IDE = {
    {
QT_MOC_LITERAL(0, 0, 3), // "IDE"
QT_MOC_LITERAL(1, 4, 30), // "on_actionNew_Project_triggered"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 31), // "on_actionOpen_Project_triggered"
QT_MOC_LITERAL(4, 68, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(5, 92, 22), // "on_actionRun_triggered"
QT_MOC_LITERAL(6, 115, 33), // "on_actionExit_program_2_trigg..."
QT_MOC_LITERAL(7, 149, 23), // "on_actionCopy_triggered"
QT_MOC_LITERAL(8, 173, 22), // "on_actionCut_triggered"
QT_MOC_LITERAL(9, 196, 24), // "on_actionPaste_triggered"
QT_MOC_LITERAL(10, 221, 29), // "on_actionSelect_all_triggered"
QT_MOC_LITERAL(11, 251, 25) // "on_actionDeploy_triggered"

    },
    "IDE\0on_actionNew_Project_triggered\0\0"
    "on_actionOpen_Project_triggered\0"
    "on_actionSave_triggered\0on_actionRun_triggered\0"
    "on_actionExit_program_2_triggered\0"
    "on_actionCopy_triggered\0on_actionCut_triggered\0"
    "on_actionPaste_triggered\0"
    "on_actionSelect_all_triggered\0"
    "on_actionDeploy_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IDE[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 0: _t->on_actionNew_Project_triggered(); break;
        case 1: _t->on_actionOpen_Project_triggered(); break;
        case 2: _t->on_actionSave_triggered(); break;
        case 3: _t->on_actionRun_triggered(); break;
        case 4: _t->on_actionExit_program_2_triggered(); break;
        case 5: _t->on_actionCopy_triggered(); break;
        case 6: _t->on_actionCut_triggered(); break;
        case 7: _t->on_actionPaste_triggered(); break;
        case 8: _t->on_actionSelect_all_triggered(); break;
        case 9: _t->on_actionDeploy_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
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
