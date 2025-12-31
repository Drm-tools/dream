/****************************************************************************
** Meta object code from reading C++ file 'EPGDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/GUI-QT/EPGDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EPGDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EPGDlg_t {
    QByteArrayData data[6];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EPGDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EPGDlg_t qt_meta_stringdata_EPGDlg = {
    {
QT_MOC_LITERAL(0, 0, 6), // "EPGDlg"
QT_MOC_LITERAL(1, 7, 7), // "NowNext"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 20), // "on_channel_activated"
QT_MOC_LITERAL(4, 37, 23), // "on_dateEdit_dateChanged"
QT_MOC_LITERAL(5, 61, 7) // "OnTimer"

    },
    "EPGDlg\0NowNext\0\0on_channel_activated\0"
    "on_dateEdit_dateChanged\0OnTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EPGDlg[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   37,    2, 0x0a /* Public */,
       4,    1,   40,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void,

       0        // eod
};

void EPGDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EPGDlg *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->NowNext((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_channel_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_dateEdit_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 3: _t->OnTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EPGDlg::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EPGDlg::NowNext)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EPGDlg::staticMetaObject = { {
    QMetaObject::SuperData::link<CWindow::staticMetaObject>(),
    qt_meta_stringdata_EPGDlg.data,
    qt_meta_data_EPGDlg,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EPGDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EPGDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EPGDlg.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui_CEPGDlgbase"))
        return static_cast< Ui_CEPGDlgbase*>(this);
    return CWindow::qt_metacast(_clname);
}

int EPGDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CWindow::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void EPGDlg::NowNext(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
