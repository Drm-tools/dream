/****************************************************************************
** Meta object code from reading C++ file 'fmdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/GUI-QT/fmdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fmdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FMDialog_t {
    QByteArrayData data[15];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FMDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FMDialog_t qt_meta_stringdata_FMDialog = {
    {
QT_MOC_LITERAL(0, 0, 8), // "FMDialog"
QT_MOC_LITERAL(1, 9, 10), // "SwitchMode"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 15), // "ViewStationsDlg"
QT_MOC_LITERAL(4, 37, 19), // "ViewLiveScheduleDlg"
QT_MOC_LITERAL(5, 57, 6), // "Closed"
QT_MOC_LITERAL(6, 64, 5), // "About"
QT_MOC_LITERAL(7, 70, 6), // "OnTune"
QT_MOC_LITERAL(8, 77, 7), // "OnTimer"
QT_MOC_LITERAL(9, 85, 12), // "OnTimerClose"
QT_MOC_LITERAL(10, 98, 21), // "OnMenuSetDisplayColor"
QT_MOC_LITERAL(11, 120, 13), // "OnSwitchToDRM"
QT_MOC_LITERAL(12, 134, 12), // "OnSwitchToAM"
QT_MOC_LITERAL(13, 147, 11), // "OnHelpAbout"
QT_MOC_LITERAL(14, 159, 11) // "OnWhatsThis"

    },
    "FMDialog\0SwitchMode\0\0ViewStationsDlg\0"
    "ViewLiveScheduleDlg\0Closed\0About\0"
    "OnTune\0OnTimer\0OnTimerClose\0"
    "OnMenuSetDisplayColor\0OnSwitchToDRM\0"
    "OnSwitchToAM\0OnHelpAbout\0OnWhatsThis"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FMDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    0,   82,    2, 0x06 /* Public */,
       4,    0,   83,    2, 0x06 /* Public */,
       5,    0,   84,    2, 0x06 /* Public */,
       6,    0,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   86,    2, 0x0a /* Public */,
       8,    0,   87,    2, 0x0a /* Public */,
       9,    0,   88,    2, 0x0a /* Public */,
      10,    0,   89,    2, 0x0a /* Public */,
      11,    0,   90,    2, 0x0a /* Public */,
      12,    0,   91,    2, 0x0a /* Public */,
      13,    0,   92,    2, 0x0a /* Public */,
      14,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
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

void FMDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FMDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SwitchMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->ViewStationsDlg(); break;
        case 2: _t->ViewLiveScheduleDlg(); break;
        case 3: _t->Closed(); break;
        case 4: _t->About(); break;
        case 5: _t->OnTune(); break;
        case 6: _t->OnTimer(); break;
        case 7: _t->OnTimerClose(); break;
        case 8: _t->OnMenuSetDisplayColor(); break;
        case 9: _t->OnSwitchToDRM(); break;
        case 10: _t->OnSwitchToAM(); break;
        case 11: _t->OnHelpAbout(); break;
        case 12: _t->OnWhatsThis(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FMDialog::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FMDialog::SwitchMode)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FMDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FMDialog::ViewStationsDlg)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FMDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FMDialog::ViewLiveScheduleDlg)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FMDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FMDialog::Closed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FMDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FMDialog::About)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FMDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<CWindow::staticMetaObject>(),
    qt_meta_stringdata_FMDialog.data,
    qt_meta_data_FMDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FMDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FMDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FMDialog.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui_FMMainWindow"))
        return static_cast< Ui_FMMainWindow*>(this);
    return CWindow::qt_metacast(_clname);
}

int FMDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CWindow::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void FMDialog::SwitchMode(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FMDialog::ViewStationsDlg()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FMDialog::ViewLiveScheduleDlg()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void FMDialog::Closed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void FMDialog::About()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
