/****************************************************************************
** Meta object code from reading C++ file 'SlideShowViewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/GUI-QT/SlideShowViewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SlideShowViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SlideShowViewer_t {
    QByteArrayData data[10];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SlideShowViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SlideShowViewer_t qt_meta_stringdata_SlideShowViewer = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SlideShowViewer"
QT_MOC_LITERAL(1, 16, 7), // "OnTimer"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 16), // "OnButtonStepBack"
QT_MOC_LITERAL(4, 42, 19), // "OnButtonStepForward"
QT_MOC_LITERAL(5, 62, 17), // "OnButtonJumpBegin"
QT_MOC_LITERAL(6, 80, 15), // "OnButtonJumpEnd"
QT_MOC_LITERAL(7, 96, 6), // "OnSave"
QT_MOC_LITERAL(8, 103, 9), // "OnSaveAll"
QT_MOC_LITERAL(9, 113, 10) // "OnClearAll"

    },
    "SlideShowViewer\0OnTimer\0\0OnButtonStepBack\0"
    "OnButtonStepForward\0OnButtonJumpBegin\0"
    "OnButtonJumpEnd\0OnSave\0OnSaveAll\0"
    "OnClearAll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SlideShowViewer[] = {

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
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

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

void SlideShowViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SlideShowViewer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->OnTimer(); break;
        case 1: _t->OnButtonStepBack(); break;
        case 2: _t->OnButtonStepForward(); break;
        case 3: _t->OnButtonJumpBegin(); break;
        case 4: _t->OnButtonJumpEnd(); break;
        case 5: _t->OnSave(); break;
        case 6: _t->OnSaveAll(); break;
        case 7: _t->OnClearAll(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject SlideShowViewer::staticMetaObject = { {
    QMetaObject::SuperData::link<CWindow::staticMetaObject>(),
    qt_meta_stringdata_SlideShowViewer.data,
    qt_meta_data_SlideShowViewer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SlideShowViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SlideShowViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SlideShowViewer.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui_SlideShowViewer"))
        return static_cast< Ui_SlideShowViewer*>(this);
    return CWindow::qt_metacast(_clname);
}

int SlideShowViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CWindow::qt_metacall(_c, _id, _a);
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
