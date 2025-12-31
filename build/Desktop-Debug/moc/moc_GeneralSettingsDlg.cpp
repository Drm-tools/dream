/****************************************************************************
** Meta object code from reading C++ file 'GeneralSettingsDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/GUI-QT/GeneralSettingsDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GeneralSettingsDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GeneralSettingsDlg_t {
    QByteArrayData data[7];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GeneralSettingsDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GeneralSettingsDlg_t qt_meta_stringdata_GeneralSettingsDlg = {
    {
QT_MOC_LITERAL(0, 0, 18), // "GeneralSettingsDlg"
QT_MOC_LITERAL(1, 19, 7), // "CheckSN"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "NewText"
QT_MOC_LITERAL(4, 36, 7), // "CheckEW"
QT_MOC_LITERAL(5, 44, 15), // "ButtonOkClicked"
QT_MOC_LITERAL(6, 60, 16) // "OnCheckBoxUseGPS"

    },
    "GeneralSettingsDlg\0CheckSN\0\0NewText\0"
    "CheckEW\0ButtonOkClicked\0OnCheckBoxUseGPS"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeneralSettingsDlg[] = {

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
       5,    0,   40,    2, 0x0a /* Public */,
       6,    0,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GeneralSettingsDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GeneralSettingsDlg *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->CheckSN((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->CheckEW((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->ButtonOkClicked(); break;
        case 3: _t->OnCheckBoxUseGPS(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GeneralSettingsDlg::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_GeneralSettingsDlg.data,
    qt_meta_data_GeneralSettingsDlg,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GeneralSettingsDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeneralSettingsDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GeneralSettingsDlg.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui_CGeneralSettingsDlgBase"))
        return static_cast< Ui_CGeneralSettingsDlgBase*>(this);
    return QDialog::qt_metacast(_clname);
}

int GeneralSettingsDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
