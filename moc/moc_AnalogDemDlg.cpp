/****************************************************************************
** Meta object code from reading C++ file 'AnalogDemDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/GUI-QT/AnalogDemDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AnalogDemDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CAMSSDlg_t {
    QByteArrayData data[4];
    char stringdata0[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CAMSSDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CAMSSDlg_t qt_meta_stringdata_CAMSSDlg = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CAMSSDlg"
QT_MOC_LITERAL(1, 9, 7), // "OnTimer"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 19) // "OnTimerPLLPhaseDial"

    },
    "CAMSSDlg\0OnTimer\0\0OnTimerPLLPhaseDial"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CAMSSDlg[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    0,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CAMSSDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CAMSSDlg *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->OnTimer(); break;
        case 1: _t->OnTimerPLLPhaseDial(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject CAMSSDlg::staticMetaObject = { {
    QMetaObject::SuperData::link<CWindow::staticMetaObject>(),
    qt_meta_stringdata_CAMSSDlg.data,
    qt_meta_data_CAMSSDlg,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CAMSSDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CAMSSDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CAMSSDlg.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui_CAMSSDlgBase"))
        return static_cast< Ui_CAMSSDlgBase*>(this);
    return CWindow::qt_metacast(_clname);
}

int CAMSSDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_AnalogDemDlg_t {
    QByteArrayData data[33];
    char stringdata0[485];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnalogDemDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnalogDemDlg_t qt_meta_stringdata_AnalogDemDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "AnalogDemDlg"
QT_MOC_LITERAL(1, 13, 10), // "SwitchMode"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 16), // "NewAMAcquisition"
QT_MOC_LITERAL(4, 42, 15), // "ViewStationsDlg"
QT_MOC_LITERAL(5, 58, 19), // "ViewLiveScheduleDlg"
QT_MOC_LITERAL(6, 78, 6), // "Closed"
QT_MOC_LITERAL(7, 85, 5), // "About"
QT_MOC_LITERAL(8, 91, 15), // "UpdatePlotStyle"
QT_MOC_LITERAL(9, 107, 19), // "OnSampleRateChanged"
QT_MOC_LITERAL(10, 127, 18), // "OnSoundFileChanged"
QT_MOC_LITERAL(11, 146, 7), // "OnTimer"
QT_MOC_LITERAL(12, 154, 19), // "OnTimerPLLPhaseDial"
QT_MOC_LITERAL(13, 174, 12), // "OnTimerClose"
QT_MOC_LITERAL(14, 187, 19), // "OnRadioDemodulation"
QT_MOC_LITERAL(15, 207, 3), // "iID"
QT_MOC_LITERAL(16, 211, 10), // "OnRadioAGC"
QT_MOC_LITERAL(17, 222, 19), // "OnCheckBoxMuteAudio"
QT_MOC_LITERAL(18, 242, 19), // "OnCheckSaveAudioWAV"
QT_MOC_LITERAL(19, 262, 18), // "OnCheckAutoFreqAcq"
QT_MOC_LITERAL(20, 281, 10), // "OnCheckPLL"
QT_MOC_LITERAL(21, 292, 18), // "OnChartxAxisValSet"
QT_MOC_LITERAL(22, 311, 4), // "dVal"
QT_MOC_LITERAL(23, 316, 16), // "OnSliderBWChange"
QT_MOC_LITERAL(24, 333, 5), // "value"
QT_MOC_LITERAL(25, 339, 13), // "OnRadioNoiRed"
QT_MOC_LITERAL(26, 353, 17), // "OnButtonWaterfall"
QT_MOC_LITERAL(27, 371, 27), // "on_ButtonFreqOffset_clicked"
QT_MOC_LITERAL(28, 399, 34), // "on_SpinBoxNoiRedLevel_valueCh..."
QT_MOC_LITERAL(29, 434, 13), // "OnSwitchToDRM"
QT_MOC_LITERAL(30, 448, 12), // "OnSwitchToFM"
QT_MOC_LITERAL(31, 461, 11), // "OnHelpAbout"
QT_MOC_LITERAL(32, 473, 11) // "OnWhatsThis"

    },
    "AnalogDemDlg\0SwitchMode\0\0NewAMAcquisition\0"
    "ViewStationsDlg\0ViewLiveScheduleDlg\0"
    "Closed\0About\0UpdatePlotStyle\0"
    "OnSampleRateChanged\0OnSoundFileChanged\0"
    "OnTimer\0OnTimerPLLPhaseDial\0OnTimerClose\0"
    "OnRadioDemodulation\0iID\0OnRadioAGC\0"
    "OnCheckBoxMuteAudio\0OnCheckSaveAudioWAV\0"
    "OnCheckAutoFreqAcq\0OnCheckPLL\0"
    "OnChartxAxisValSet\0dVal\0OnSliderBWChange\0"
    "value\0OnRadioNoiRed\0OnButtonWaterfall\0"
    "on_ButtonFreqOffset_clicked\0"
    "on_SpinBoxNoiRedLevel_valueChanged\0"
    "OnSwitchToDRM\0OnSwitchToFM\0OnHelpAbout\0"
    "OnWhatsThis"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnalogDemDlg[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  154,    2, 0x06 /* Public */,
       3,    0,  157,    2, 0x06 /* Public */,
       4,    0,  158,    2, 0x06 /* Public */,
       5,    0,  159,    2, 0x06 /* Public */,
       6,    0,  160,    2, 0x06 /* Public */,
       7,    0,  161,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,  162,    2, 0x0a /* Public */,
       9,    1,  165,    2, 0x0a /* Public */,
      10,    1,  168,    2, 0x0a /* Public */,
      11,    0,  171,    2, 0x0a /* Public */,
      12,    0,  172,    2, 0x0a /* Public */,
      13,    0,  173,    2, 0x0a /* Public */,
      14,    1,  174,    2, 0x0a /* Public */,
      16,    1,  177,    2, 0x0a /* Public */,
      17,    0,  180,    2, 0x0a /* Public */,
      18,    0,  181,    2, 0x0a /* Public */,
      19,    0,  182,    2, 0x0a /* Public */,
      20,    0,  183,    2, 0x0a /* Public */,
      21,    1,  184,    2, 0x0a /* Public */,
      23,    1,  187,    2, 0x0a /* Public */,
      25,    1,  190,    2, 0x0a /* Public */,
      26,    0,  193,    2, 0x0a /* Public */,
      27,    1,  194,    2, 0x0a /* Public */,
      28,    1,  197,    2, 0x0a /* Public */,
      29,    0,  200,    2, 0x0a /* Public */,
      30,    0,  201,    2, 0x0a /* Public */,
      31,    0,  202,    2, 0x0a /* Public */,
      32,    0,  203,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   22,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AnalogDemDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AnalogDemDlg *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SwitchMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->NewAMAcquisition(); break;
        case 2: _t->ViewStationsDlg(); break;
        case 3: _t->ViewLiveScheduleDlg(); break;
        case 4: _t->Closed(); break;
        case 5: _t->About(); break;
        case 6: _t->UpdatePlotStyle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->OnSampleRateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->OnSoundFileChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->OnTimer(); break;
        case 10: _t->OnTimerPLLPhaseDial(); break;
        case 11: _t->OnTimerClose(); break;
        case 12: _t->OnRadioDemodulation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->OnRadioAGC((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->OnCheckBoxMuteAudio(); break;
        case 15: _t->OnCheckSaveAudioWAV(); break;
        case 16: _t->OnCheckAutoFreqAcq(); break;
        case 17: _t->OnCheckPLL(); break;
        case 18: _t->OnChartxAxisValSet((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: _t->OnSliderBWChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->OnRadioNoiRed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->OnButtonWaterfall(); break;
        case 22: _t->on_ButtonFreqOffset_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->on_SpinBoxNoiRedLevel_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->OnSwitchToDRM(); break;
        case 25: _t->OnSwitchToFM(); break;
        case 26: _t->OnHelpAbout(); break;
        case 27: _t->OnWhatsThis(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AnalogDemDlg::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AnalogDemDlg::SwitchMode)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AnalogDemDlg::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AnalogDemDlg::NewAMAcquisition)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AnalogDemDlg::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AnalogDemDlg::ViewStationsDlg)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AnalogDemDlg::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AnalogDemDlg::ViewLiveScheduleDlg)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (AnalogDemDlg::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AnalogDemDlg::Closed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (AnalogDemDlg::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AnalogDemDlg::About)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AnalogDemDlg::staticMetaObject = { {
    QMetaObject::SuperData::link<CWindow::staticMetaObject>(),
    qt_meta_stringdata_AnalogDemDlg.data,
    qt_meta_data_AnalogDemDlg,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AnalogDemDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnalogDemDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AnalogDemDlg.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui_AMMainWindow"))
        return static_cast< Ui_AMMainWindow*>(this);
    return CWindow::qt_metacast(_clname);
}

int AnalogDemDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void AnalogDemDlg::SwitchMode(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AnalogDemDlg::NewAMAcquisition()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AnalogDemDlg::ViewStationsDlg()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AnalogDemDlg::ViewLiveScheduleDlg()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void AnalogDemDlg::Closed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void AnalogDemDlg::About()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
