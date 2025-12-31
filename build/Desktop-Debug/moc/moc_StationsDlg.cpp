/****************************************************************************
** Meta object code from reading C++ file 'StationsDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/GUI-QT/StationsDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StationsDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StationsDlg_t {
    QByteArrayData data[21];
    char stringdata0[357];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StationsDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StationsDlg_t qt_meta_stringdata_StationsDlg = {
    {
QT_MOC_LITERAL(0, 0, 11), // "StationsDlg"
QT_MOC_LITERAL(1, 12, 12), // "subscribeRig"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "unsubscribeRig"
QT_MOC_LITERAL(4, 41, 8), // "OnSigStr"
QT_MOC_LITERAL(5, 50, 7), // "OnTimer"
QT_MOC_LITERAL(6, 58, 12), // "OnSMeterMenu"
QT_MOC_LITERAL(7, 71, 3), // "iID"
QT_MOC_LITERAL(8, 75, 13), // "OnUrlFinished"
QT_MOC_LITERAL(9, 89, 14), // "QNetworkReply*"
QT_MOC_LITERAL(10, 104, 18), // "OnShowStationsMenu"
QT_MOC_LITERAL(11, 123, 17), // "OnShowPreviewMenu"
QT_MOC_LITERAL(12, 141, 17), // "OnFreqCntNewValue"
QT_MOC_LITERAL(13, 159, 4), // "dVal"
QT_MOC_LITERAL(14, 164, 15), // "OnHeaderClicked"
QT_MOC_LITERAL(15, 180, 1), // "c"
QT_MOC_LITERAL(16, 182, 28), // "on_actionGetUpdate_triggered"
QT_MOC_LITERAL(17, 211, 40), // "on_ListViewStations_itemSelec..."
QT_MOC_LITERAL(18, 252, 33), // "on_ComboBoxFilterTarget_activ..."
QT_MOC_LITERAL(19, 286, 34), // "on_ComboBoxFilterCountry_acti..."
QT_MOC_LITERAL(20, 321, 35) // "on_ComboBoxFilterLanguage_act..."

    },
    "StationsDlg\0subscribeRig\0\0unsubscribeRig\0"
    "OnSigStr\0OnTimer\0OnSMeterMenu\0iID\0"
    "OnUrlFinished\0QNetworkReply*\0"
    "OnShowStationsMenu\0OnShowPreviewMenu\0"
    "OnFreqCntNewValue\0dVal\0OnHeaderClicked\0"
    "c\0on_actionGetUpdate_triggered\0"
    "on_ListViewStations_itemSelectionChanged\0"
    "on_ComboBoxFilterTarget_activated\0"
    "on_ComboBoxFilterCountry_activated\0"
    "on_ComboBoxFilterLanguage_activated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StationsDlg[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   96,    2, 0x0a /* Public */,
       5,    0,   99,    2, 0x0a /* Public */,
       6,    1,  100,    2, 0x0a /* Public */,
       6,    0,  103,    2, 0x0a /* Public */,
       8,    1,  104,    2, 0x0a /* Public */,
      10,    1,  107,    2, 0x0a /* Public */,
      11,    1,  110,    2, 0x0a /* Public */,
      12,    1,  113,    2, 0x0a /* Public */,
      14,    1,  116,    2, 0x0a /* Public */,
      16,    0,  119,    2, 0x0a /* Public */,
      17,    0,  120,    2, 0x0a /* Public */,
      18,    1,  121,    2, 0x0a /* Public */,
      19,    1,  124,    2, 0x0a /* Public */,
      20,    1,  127,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void StationsDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StationsDlg *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->subscribeRig(); break;
        case 1: _t->unsubscribeRig(); break;
        case 2: _t->OnSigStr((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->OnTimer(); break;
        case 4: _t->OnSMeterMenu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->OnSMeterMenu(); break;
        case 6: _t->OnUrlFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 7: _t->OnShowStationsMenu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->OnShowPreviewMenu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->OnFreqCntNewValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->OnHeaderClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_actionGetUpdate_triggered(); break;
        case 12: _t->on_ListViewStations_itemSelectionChanged(); break;
        case 13: _t->on_ComboBoxFilterTarget_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_ComboBoxFilterCountry_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->on_ComboBoxFilterLanguage_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StationsDlg::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StationsDlg::subscribeRig)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (StationsDlg::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StationsDlg::unsubscribeRig)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject StationsDlg::staticMetaObject = { {
    QMetaObject::SuperData::link<CWindow::staticMetaObject>(),
    qt_meta_stringdata_StationsDlg.data,
    qt_meta_data_StationsDlg,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *StationsDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StationsDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StationsDlg.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui_StationsDlgbase"))
        return static_cast< Ui_StationsDlgbase*>(this);
    return CWindow::qt_metacast(_clname);
}

int StationsDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void StationsDlg::subscribeRig()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void StationsDlg::unsubscribeRig()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
