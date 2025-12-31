/****************************************************************************
** Meta object code from reading C++ file 'SoundCardSelMenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/GUI-QT/SoundCardSelMenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SoundCardSelMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CSoundCardSelMenu_t {
    QByteArrayData data[25];
    char stringdata0[486];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSoundCardSelMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSoundCardSelMenu_t qt_meta_stringdata_CSoundCardSelMenu = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CSoundCardSelMenu"
QT_MOC_LITERAL(1, 18, 22), // "soundSampleRateChanged"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 20), // "soundInDeviceChanged"
QT_MOC_LITERAL(4, 63, 21), // "soundOutDeviceChanged"
QT_MOC_LITERAL(5, 85, 21), // "soundInChannelChanged"
QT_MOC_LITERAL(6, 107, 22), // "soundOutChannelChanged"
QT_MOC_LITERAL(7, 130, 11), // "EOutChanSel"
QT_MOC_LITERAL(8, 142, 25), // "soundSignalUpscaleChanged"
QT_MOC_LITERAL(9, 168, 16), // "OnSoundInChannel"
QT_MOC_LITERAL(10, 185, 8), // "QAction*"
QT_MOC_LITERAL(11, 194, 17), // "OnSoundOutChannel"
QT_MOC_LITERAL(12, 212, 15), // "OnSoundInDevice"
QT_MOC_LITERAL(13, 228, 16), // "OnSoundOutDevice"
QT_MOC_LITERAL(14, 245, 17), // "OnSoundSampleRate"
QT_MOC_LITERAL(15, 263, 20), // "OnSoundSignalUpscale"
QT_MOC_LITERAL(16, 284, 18), // "OnSoundFileChanged"
QT_MOC_LITERAL(17, 303, 22), // "OnSoundInDeviceChanged"
QT_MOC_LITERAL(18, 326, 23), // "OnSoundOutDeviceChanged"
QT_MOC_LITERAL(19, 350, 26), // "OnSoundInSampleRateChanged"
QT_MOC_LITERAL(20, 377, 27), // "OnSoundOutSampleRateChanged"
QT_MOC_LITERAL(21, 405, 26), // "OnSoundUpscaleRatioChanged"
QT_MOC_LITERAL(22, 432, 23), // "OnSoundInChannelChanged"
QT_MOC_LITERAL(23, 456, 4), // "chan"
QT_MOC_LITERAL(24, 461, 24) // "OnSoundOutChannelChanged"

    },
    "CSoundCardSelMenu\0soundSampleRateChanged\0"
    "\0soundInDeviceChanged\0soundOutDeviceChanged\0"
    "soundInChannelChanged\0soundOutChannelChanged\0"
    "EOutChanSel\0soundSignalUpscaleChanged\0"
    "OnSoundInChannel\0QAction*\0OnSoundOutChannel\0"
    "OnSoundInDevice\0OnSoundOutDevice\0"
    "OnSoundSampleRate\0OnSoundSignalUpscale\0"
    "OnSoundFileChanged\0OnSoundInDeviceChanged\0"
    "OnSoundOutDeviceChanged\0"
    "OnSoundInSampleRateChanged\0"
    "OnSoundOutSampleRateChanged\0"
    "OnSoundUpscaleRatioChanged\0"
    "OnSoundInChannelChanged\0chan\0"
    "OnSoundOutChannelChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSoundCardSelMenu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  114,    2, 0x06 /* Public */,
       3,    1,  117,    2, 0x06 /* Public */,
       4,    1,  120,    2, 0x06 /* Public */,
       5,    1,  123,    2, 0x06 /* Public */,
       6,    1,  126,    2, 0x06 /* Public */,
       8,    1,  129,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,  132,    2, 0x0a /* Public */,
      11,    1,  135,    2, 0x0a /* Public */,
      12,    1,  138,    2, 0x0a /* Public */,
      13,    1,  141,    2, 0x0a /* Public */,
      14,    1,  144,    2, 0x0a /* Public */,
      15,    1,  147,    2, 0x0a /* Public */,
      16,    1,  150,    2, 0x0a /* Public */,
      17,    1,  153,    2, 0x0a /* Public */,
      18,    1,  156,    2, 0x0a /* Public */,
      19,    1,  159,    2, 0x0a /* Public */,
      20,    1,  162,    2, 0x0a /* Public */,
      21,    1,  165,    2, 0x0a /* Public */,
      22,    1,  168,    2, 0x0a /* Public */,
      24,    1,  171,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,

       0        // eod
};

void CSoundCardSelMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CSoundCardSelMenu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->soundSampleRateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->soundInDeviceChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->soundOutDeviceChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->soundInChannelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->soundOutChannelChanged((*reinterpret_cast< EOutChanSel(*)>(_a[1]))); break;
        case 5: _t->soundSignalUpscaleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->OnSoundInChannel((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 7: _t->OnSoundOutChannel((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 8: _t->OnSoundInDevice((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 9: _t->OnSoundOutDevice((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 10: _t->OnSoundSampleRate((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 11: _t->OnSoundSignalUpscale((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->OnSoundFileChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->OnSoundInDeviceChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->OnSoundOutDeviceChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->OnSoundInSampleRateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->OnSoundOutSampleRateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->OnSoundUpscaleRatioChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->OnSoundInChannelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->OnSoundOutChannelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CSoundCardSelMenu::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CSoundCardSelMenu::soundSampleRateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CSoundCardSelMenu::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CSoundCardSelMenu::soundInDeviceChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CSoundCardSelMenu::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CSoundCardSelMenu::soundOutDeviceChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CSoundCardSelMenu::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CSoundCardSelMenu::soundInChannelChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CSoundCardSelMenu::*)(EOutChanSel );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CSoundCardSelMenu::soundOutChannelChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CSoundCardSelMenu::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CSoundCardSelMenu::soundSignalUpscaleChanged)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CSoundCardSelMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QMenu::staticMetaObject>(),
    qt_meta_stringdata_CSoundCardSelMenu.data,
    qt_meta_data_CSoundCardSelMenu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CSoundCardSelMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSoundCardSelMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CSoundCardSelMenu.stringdata0))
        return static_cast<void*>(this);
    return QMenu::qt_metacast(_clname);
}

int CSoundCardSelMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void CSoundCardSelMenu::soundSampleRateChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CSoundCardSelMenu::soundInDeviceChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CSoundCardSelMenu::soundOutDeviceChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CSoundCardSelMenu::soundInChannelChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CSoundCardSelMenu::soundOutChannelChanged(EOutChanSel _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CSoundCardSelMenu::soundSignalUpscaleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
struct qt_meta_stringdata_CFileMenu_t {
    QByteArrayData data[5];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CFileMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CFileMenu_t qt_meta_stringdata_CFileMenu = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CFileMenu"
QT_MOC_LITERAL(1, 10, 16), // "soundFileChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 10), // "OnOpenFile"
QT_MOC_LITERAL(4, 39, 11) // "OnCloseFile"

    },
    "CFileMenu\0soundFileChanged\0\0OnOpenFile\0"
    "OnCloseFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CFileMenu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   32,    2, 0x0a /* Public */,
       4,    0,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CFileMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CFileMenu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->soundFileChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->OnOpenFile(); break;
        case 2: _t->OnCloseFile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CFileMenu::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CFileMenu::soundFileChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CFileMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QMenu::staticMetaObject>(),
    qt_meta_stringdata_CFileMenu.data,
    qt_meta_data_CFileMenu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CFileMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CFileMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CFileMenu.stringdata0))
        return static_cast<void*>(this);
    return QMenu::qt_metacast(_clname);
}

int CFileMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CFileMenu::soundFileChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
