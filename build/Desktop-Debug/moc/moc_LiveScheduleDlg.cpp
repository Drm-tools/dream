/****************************************************************************
** Meta object code from reading C++ file 'LiveScheduleDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/GUI-QT/LiveScheduleDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LiveScheduleDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LiveScheduleDlg_t {
    QByteArrayData data[11];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LiveScheduleDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LiveScheduleDlg_t qt_meta_stringdata_LiveScheduleDlg = {
    {
QT_MOC_LITERAL(0, 0, 15), // "LiveScheduleDlg"
QT_MOC_LITERAL(1, 16, 11), // "OnTimerList"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 15), // "OnTimerUTCLabel"
QT_MOC_LITERAL(4, 45, 18), // "OnShowStationsMenu"
QT_MOC_LITERAL(5, 64, 3), // "iID"
QT_MOC_LITERAL(6, 68, 17), // "OnShowPreviewMenu"
QT_MOC_LITERAL(7, 86, 15), // "OnHeaderClicked"
QT_MOC_LITERAL(8, 102, 1), // "c"
QT_MOC_LITERAL(9, 104, 6), // "OnSave"
QT_MOC_LITERAL(10, 111, 13) // "OnCheckFreeze"

    },
    "LiveScheduleDlg\0OnTimerList\0\0"
    "OnTimerUTCLabel\0OnShowStationsMenu\0"
    "iID\0OnShowPreviewMenu\0OnHeaderClicked\0"
    "c\0OnSave\0OnCheckFreeze"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LiveScheduleDlg[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    1,   51,    2, 0x0a /* Public */,
       6,    1,   54,    2, 0x0a /* Public */,
       7,    1,   57,    2, 0x0a /* Public */,
       9,    0,   60,    2, 0x0a /* Public */,
      10,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LiveScheduleDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LiveScheduleDlg *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->OnTimerList(); break;
        case 1: _t->OnTimerUTCLabel(); break;
        case 2: _t->OnShowStationsMenu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->OnShowPreviewMenu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->OnHeaderClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->OnSave(); break;
        case 6: _t->OnCheckFreeze(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LiveScheduleDlg::staticMetaObject = { {
    QMetaObject::SuperData::link<CWindow::staticMetaObject>(),
    qt_meta_stringdata_LiveScheduleDlg.data,
    qt_meta_data_LiveScheduleDlg,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LiveScheduleDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LiveScheduleDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LiveScheduleDlg.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui_LiveScheduleWindow"))
        return static_cast< Ui_LiveScheduleWindow*>(this);
    return CWindow::qt_metacast(_clname);
}

int LiveScheduleDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
