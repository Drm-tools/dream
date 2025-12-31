/****************************************************************************
** Meta object code from reading C++ file 'ReceiverQt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/main-Qt/ReceiverQt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ReceiverQt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CReceiverQt_t {
    QByteArrayData data[94];
    char stringdata0[1881];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CReceiverQt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CReceiverQt_t qt_meta_stringdata_CReceiverQt = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CReceiverQt"
QT_MOC_LITERAL(1, 12, 22), // "inputSampleRateChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 23), // "outputSampleRateChanged"
QT_MOC_LITERAL(4, 60, 24), // "soundUpscaleRatioChanged"
QT_MOC_LITERAL(5, 85, 16), // "soundFileChanged"
QT_MOC_LITERAL(6, 102, 18), // "InputDeviceChanged"
QT_MOC_LITERAL(7, 121, 19), // "OutputDeviceChanged"
QT_MOC_LITERAL(8, 141, 21), // "AMBWParametersChanged"
QT_MOC_LITERAL(9, 163, 11), // "rCenterFreq"
QT_MOC_LITERAL(10, 175, 3), // "rBW"
QT_MOC_LITERAL(11, 179, 28), // "AMNoiseReductionLevelChanged"
QT_MOC_LITERAL(12, 208, 27), // "AMNoiseReductionTypeChanged"
QT_MOC_LITERAL(13, 236, 11), // "ENoiRedType"
QT_MOC_LITERAL(14, 248, 25), // "AMDemodulationTypeChanged"
QT_MOC_LITERAL(15, 274, 10), // "EDemodType"
QT_MOC_LITERAL(16, 285, 16), // "AMAGCTypeChanged"
QT_MOC_LITERAL(17, 302, 10), // "EAmAgcType"
QT_MOC_LITERAL(18, 313, 17), // "AMFilterBWChanged"
QT_MOC_LITERAL(19, 331, 29), // "AMMixerFrequencyOffsetChanged"
QT_MOC_LITERAL(20, 361, 17), // "AMPLLPhaseChanged"
QT_MOC_LITERAL(21, 379, 5), // "_REAL"
QT_MOC_LITERAL(22, 385, 19), // "ReceiverModeChanged"
QT_MOC_LITERAL(23, 405, 8), // "ERecMode"
QT_MOC_LITERAL(24, 414, 19), // "InputChannelChanged"
QT_MOC_LITERAL(25, 434, 20), // "OutputChannelChanged"
QT_MOC_LITERAL(26, 455, 29), // "MSCMLInitNumIterationsChanged"
QT_MOC_LITERAL(27, 485, 18), // "isInputRSCIChanged"
QT_MOC_LITERAL(28, 504, 22), // "isWriteWaveFileChanged"
QT_MOC_LITERAL(29, 527, 19), // "isAudioMutedChanged"
QT_MOC_LITERAL(30, 547, 38), // "isIntefererConsiderationEnabl..."
QT_MOC_LITERAL(31, 586, 46), // "isFrequencySyncAcquisitionFil..."
QT_MOC_LITERAL(32, 633, 24), // "isSpectrumFlippedChanged"
QT_MOC_LITERAL(33, 658, 42), // "isAMAutoFrequencyAcquisitionE..."
QT_MOC_LITERAL(34, 701, 21), // "isAMPLLEnabledChanged"
QT_MOC_LITERAL(35, 723, 19), // "AMSSPLLPhaseChanged"
QT_MOC_LITERAL(36, 743, 44), // "AMSSPercentageDataEntityGroup..."
QT_MOC_LITERAL(37, 788, 32), // "AMSSDataEntityGroupStatusChanged"
QT_MOC_LITERAL(38, 821, 23), // "AMSSCurrentBlockChanged"
QT_MOC_LITERAL(39, 845, 27), // "AMSSCurrentBlockBitsChanged"
QT_MOC_LITERAL(40, 873, 23), // "AMSSBlock1StatusChanged"
QT_MOC_LITERAL(41, 897, 21), // "AMSSLockStatusChanged"
QT_MOC_LITERAL(42, 919, 18), // "EAMSSBlockLockStat"
QT_MOC_LITERAL(43, 938, 16), // "canDecodeChanged"
QT_MOC_LITERAL(44, 955, 33), // "TimeInterpolationAlgorithmCha..."
QT_MOC_LITERAL(45, 989, 12), // "ETypeIntTime"
QT_MOC_LITERAL(46, 1002, 38), // "FrequencyInterpolationAlgorit..."
QT_MOC_LITERAL(47, 1041, 12), // "ETypeIntFreq"
QT_MOC_LITERAL(48, 1054, 27), // "TimeSyncTrackingTypeChanged"
QT_MOC_LITERAL(49, 1082, 15), // "ETypeTiSyncTrac"
QT_MOC_LITERAL(50, 1098, 19), // "ReverbEffectChanged"
QT_MOC_LITERAL(51, 1118, 23), // "AcquisitionStateChanged"
QT_MOC_LITERAL(52, 1142, 8), // "EAcqStat"
QT_MOC_LITERAL(53, 1151, 16), // "FrequencyChanged"
QT_MOC_LITERAL(54, 1168, 14), // "drmModeStarted"
QT_MOC_LITERAL(55, 1183, 13), // "amModeStarted"
QT_MOC_LITERAL(56, 1197, 13), // "fmModeStarted"
QT_MOC_LITERAL(57, 1211, 12), // "LoadSettings"
QT_MOC_LITERAL(58, 1224, 12), // "SaveSettings"
QT_MOC_LITERAL(59, 1237, 14), // "SetInputDevice"
QT_MOC_LITERAL(60, 1252, 11), // "std::string"
QT_MOC_LITERAL(61, 1264, 15), // "SetOutputDevice"
QT_MOC_LITERAL(62, 1280, 5), // "Start"
QT_MOC_LITERAL(63, 1286, 4), // "Stop"
QT_MOC_LITERAL(64, 1291, 7), // "Restart"
QT_MOC_LITERAL(65, 1299, 11), // "SetSettings"
QT_MOC_LITERAL(66, 1311, 10), // "CSettings*"
QT_MOC_LITERAL(67, 1322, 12), // "pNewSettings"
QT_MOC_LITERAL(68, 1335, 18), // "StartWriteWaveFile"
QT_MOC_LITERAL(69, 1354, 17), // "StopWriteWaveFile"
QT_MOC_LITERAL(70, 1372, 29), // "SetTimeInterpolationAlgorithm"
QT_MOC_LITERAL(71, 1402, 34), // "SetFrequencyInterpolationAlgo..."
QT_MOC_LITERAL(72, 1437, 23), // "SetTimeSyncTrackingType"
QT_MOC_LITERAL(73, 1461, 22), // "SetNumMSCMLCIterations"
QT_MOC_LITERAL(74, 1484, 15), // "SetFlipSpectrum"
QT_MOC_LITERAL(75, 1500, 33), // "SetFrequencySyncAcquisitionFi..."
QT_MOC_LITERAL(76, 1534, 21), // "SetConsiderInterferer"
QT_MOC_LITERAL(77, 1556, 9), // "MuteAudio"
QT_MOC_LITERAL(78, 1566, 22), // "SetReverberationEffect"
QT_MOC_LITERAL(79, 1589, 15), // "SetReceiverMode"
QT_MOC_LITERAL(80, 1605, 21), // "SetAMDemodulationType"
QT_MOC_LITERAL(81, 1627, 13), // "SetAMFilterBW"
QT_MOC_LITERAL(82, 1641, 12), // "SetAMAGCType"
QT_MOC_LITERAL(83, 1654, 23), // "SetAMNoiseReductionType"
QT_MOC_LITERAL(84, 1678, 24), // "SetAMNoiseReductionLevel"
QT_MOC_LITERAL(85, 1703, 12), // "SetFrequency"
QT_MOC_LITERAL(86, 1716, 13), // "SetAMDemodAcq"
QT_MOC_LITERAL(87, 1730, 11), // "EnableAMPLL"
QT_MOC_LITERAL(88, 1742, 30), // "EnableAutoFrequenctAcquisition"
QT_MOC_LITERAL(89, 1773, 23), // "onSoundInChannelChanged"
QT_MOC_LITERAL(90, 1797, 24), // "onSoundOutChannelChanged"
QT_MOC_LITERAL(91, 1822, 11), // "EOutChanSel"
QT_MOC_LITERAL(92, 1834, 24), // "onSoundSampleRateChanged"
QT_MOC_LITERAL(93, 1859, 21) // "SetSoundSignalUpscale"

    },
    "CReceiverQt\0inputSampleRateChanged\0\0"
    "outputSampleRateChanged\0"
    "soundUpscaleRatioChanged\0soundFileChanged\0"
    "InputDeviceChanged\0OutputDeviceChanged\0"
    "AMBWParametersChanged\0rCenterFreq\0rBW\0"
    "AMNoiseReductionLevelChanged\0"
    "AMNoiseReductionTypeChanged\0ENoiRedType\0"
    "AMDemodulationTypeChanged\0EDemodType\0"
    "AMAGCTypeChanged\0EAmAgcType\0"
    "AMFilterBWChanged\0AMMixerFrequencyOffsetChanged\0"
    "AMPLLPhaseChanged\0_REAL\0ReceiverModeChanged\0"
    "ERecMode\0InputChannelChanged\0"
    "OutputChannelChanged\0MSCMLInitNumIterationsChanged\0"
    "isInputRSCIChanged\0isWriteWaveFileChanged\0"
    "isAudioMutedChanged\0"
    "isIntefererConsiderationEnabledChanged\0"
    "isFrequencySyncAcquisitionFilterEnabledChanged\0"
    "isSpectrumFlippedChanged\0"
    "isAMAutoFrequencyAcquisitionEnabledChanged\0"
    "isAMPLLEnabledChanged\0AMSSPLLPhaseChanged\0"
    "AMSSPercentageDataEntityGroupCompleteChanged\0"
    "AMSSDataEntityGroupStatusChanged\0"
    "AMSSCurrentBlockChanged\0"
    "AMSSCurrentBlockBitsChanged\0"
    "AMSSBlock1StatusChanged\0AMSSLockStatusChanged\0"
    "EAMSSBlockLockStat\0canDecodeChanged\0"
    "TimeInterpolationAlgorithmChanged\0"
    "ETypeIntTime\0FrequencyInterpolationAlgorithmChanged\0"
    "ETypeIntFreq\0TimeSyncTrackingTypeChanged\0"
    "ETypeTiSyncTrac\0ReverbEffectChanged\0"
    "AcquisitionStateChanged\0EAcqStat\0"
    "FrequencyChanged\0drmModeStarted\0"
    "amModeStarted\0fmModeStarted\0LoadSettings\0"
    "SaveSettings\0SetInputDevice\0std::string\0"
    "SetOutputDevice\0Start\0Stop\0Restart\0"
    "SetSettings\0CSettings*\0pNewSettings\0"
    "StartWriteWaveFile\0StopWriteWaveFile\0"
    "SetTimeInterpolationAlgorithm\0"
    "SetFrequencyInterpolationAlgorithm\0"
    "SetTimeSyncTrackingType\0SetNumMSCMLCIterations\0"
    "SetFlipSpectrum\0SetFrequencySyncAcquisitionFilter\0"
    "SetConsiderInterferer\0MuteAudio\0"
    "SetReverberationEffect\0SetReceiverMode\0"
    "SetAMDemodulationType\0SetAMFilterBW\0"
    "SetAMAGCType\0SetAMNoiseReductionType\0"
    "SetAMNoiseReductionLevel\0SetFrequency\0"
    "SetAMDemodAcq\0EnableAMPLL\0"
    "EnableAutoFrequenctAcquisition\0"
    "onSoundInChannelChanged\0"
    "onSoundOutChannelChanged\0EOutChanSel\0"
    "onSoundSampleRateChanged\0SetSoundSignalUpscale"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CReceiverQt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      78,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      43,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  404,    2, 0x06 /* Public */,
       3,    1,  407,    2, 0x06 /* Public */,
       4,    1,  410,    2, 0x06 /* Public */,
       5,    1,  413,    2, 0x06 /* Public */,
       6,    1,  416,    2, 0x06 /* Public */,
       7,    1,  419,    2, 0x06 /* Public */,
       8,    2,  422,    2, 0x06 /* Public */,
      11,    1,  427,    2, 0x06 /* Public */,
      12,    1,  430,    2, 0x06 /* Public */,
      14,    1,  433,    2, 0x06 /* Public */,
      16,    1,  436,    2, 0x06 /* Public */,
      18,    1,  439,    2, 0x06 /* Public */,
      19,    1,  442,    2, 0x06 /* Public */,
      20,    1,  445,    2, 0x06 /* Public */,
      22,    1,  448,    2, 0x06 /* Public */,
      24,    1,  451,    2, 0x06 /* Public */,
      25,    1,  454,    2, 0x06 /* Public */,
      26,    1,  457,    2, 0x06 /* Public */,
      27,    1,  460,    2, 0x06 /* Public */,
      28,    1,  463,    2, 0x06 /* Public */,
      29,    1,  466,    2, 0x06 /* Public */,
      30,    1,  469,    2, 0x06 /* Public */,
      31,    1,  472,    2, 0x06 /* Public */,
      32,    1,  475,    2, 0x06 /* Public */,
      33,    1,  478,    2, 0x06 /* Public */,
      34,    1,  481,    2, 0x06 /* Public */,
      35,    1,  484,    2, 0x06 /* Public */,
      36,    1,  487,    2, 0x06 /* Public */,
      37,    1,  490,    2, 0x06 /* Public */,
      38,    1,  493,    2, 0x06 /* Public */,
      39,    1,  496,    2, 0x06 /* Public */,
      40,    1,  499,    2, 0x06 /* Public */,
      41,    1,  502,    2, 0x06 /* Public */,
      43,    1,  505,    2, 0x06 /* Public */,
      44,    1,  508,    2, 0x06 /* Public */,
      46,    1,  511,    2, 0x06 /* Public */,
      48,    1,  514,    2, 0x06 /* Public */,
      50,    1,  517,    2, 0x06 /* Public */,
      51,    1,  520,    2, 0x06 /* Public */,
      53,    1,  523,    2, 0x06 /* Public */,
      54,    0,  526,    2, 0x06 /* Public */,
      55,    0,  527,    2, 0x06 /* Public */,
      56,    0,  528,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      57,    0,  529,    2, 0x0a /* Public */,
      58,    0,  530,    2, 0x0a /* Public */,
      59,    1,  531,    2, 0x0a /* Public */,
      61,    1,  534,    2, 0x0a /* Public */,
      59,    1,  537,    2, 0x0a /* Public */,
      61,    1,  540,    2, 0x0a /* Public */,
      62,    0,  543,    2, 0x0a /* Public */,
      63,    0,  544,    2, 0x0a /* Public */,
      64,    0,  545,    2, 0x0a /* Public */,
      65,    1,  546,    2, 0x0a /* Public */,
      68,    1,  549,    2, 0x0a /* Public */,
      69,    0,  552,    2, 0x0a /* Public */,
      70,    1,  553,    2, 0x0a /* Public */,
      71,    1,  556,    2, 0x0a /* Public */,
      72,    1,  559,    2, 0x0a /* Public */,
      73,    1,  562,    2, 0x0a /* Public */,
      74,    1,  565,    2, 0x0a /* Public */,
      75,    1,  568,    2, 0x0a /* Public */,
      76,    1,  571,    2, 0x0a /* Public */,
      77,    1,  574,    2, 0x0a /* Public */,
      78,    1,  577,    2, 0x0a /* Public */,
      79,    1,  580,    2, 0x0a /* Public */,
      80,    1,  583,    2, 0x0a /* Public */,
      81,    1,  586,    2, 0x0a /* Public */,
      82,    1,  589,    2, 0x0a /* Public */,
      83,    1,  592,    2, 0x0a /* Public */,
      84,    1,  595,    2, 0x0a /* Public */,
      85,    1,  598,    2, 0x0a /* Public */,
      86,    1,  601,    2, 0x0a /* Public */,
      87,    1,  604,    2, 0x0a /* Public */,
      88,    1,  607,    2, 0x0a /* Public */,
      89,    1,  610,    2, 0x0a /* Public */,
      90,    1,  613,    2, 0x0a /* Public */,
      92,    1,  616,    2, 0x0a /* Public */,
      93,    1,  619,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    9,   10,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void, 0x80000000 | 23,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 42,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 45,    2,
    QMetaType::Void, 0x80000000 | 47,    2,
    QMetaType::Void, 0x80000000 | 49,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 52,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 60,    2,
    QMetaType::Void, 0x80000000 | 60,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 66,   67,
    QMetaType::Void, 0x80000000 | 60,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 45,    2,
    QMetaType::Void, 0x80000000 | 47,    2,
    QMetaType::Void, 0x80000000 | 49,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 23,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 91,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void CReceiverQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CReceiverQt *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->inputSampleRateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->outputSampleRateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->soundUpscaleRatioChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->soundFileChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->InputDeviceChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->OutputDeviceChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->AMBWParametersChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 7: _t->AMNoiseReductionLevelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->AMNoiseReductionTypeChanged((*reinterpret_cast< ENoiRedType(*)>(_a[1]))); break;
        case 9: _t->AMDemodulationTypeChanged((*reinterpret_cast< EDemodType(*)>(_a[1]))); break;
        case 10: _t->AMAGCTypeChanged((*reinterpret_cast< EAmAgcType(*)>(_a[1]))); break;
        case 11: _t->AMFilterBWChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->AMMixerFrequencyOffsetChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->AMPLLPhaseChanged((*reinterpret_cast< _REAL(*)>(_a[1]))); break;
        case 14: _t->ReceiverModeChanged((*reinterpret_cast< ERecMode(*)>(_a[1]))); break;
        case 15: _t->InputChannelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->OutputChannelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->MSCMLInitNumIterationsChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->isInputRSCIChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->isWriteWaveFileChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->isAudioMutedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->isIntefererConsiderationEnabledChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->isFrequencySyncAcquisitionFilterEnabledChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->isSpectrumFlippedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->isAMAutoFrequencyAcquisitionEnabledChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->isAMPLLEnabledChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->AMSSPLLPhaseChanged((*reinterpret_cast< _REAL(*)>(_a[1]))); break;
        case 27: _t->AMSSPercentageDataEntityGroupCompleteChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->AMSSDataEntityGroupStatusChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: _t->AMSSCurrentBlockChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->AMSSCurrentBlockBitsChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 31: _t->AMSSBlock1StatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->AMSSLockStatusChanged((*reinterpret_cast< EAMSSBlockLockStat(*)>(_a[1]))); break;
        case 33: _t->canDecodeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->TimeInterpolationAlgorithmChanged((*reinterpret_cast< ETypeIntTime(*)>(_a[1]))); break;
        case 35: _t->FrequencyInterpolationAlgorithmChanged((*reinterpret_cast< ETypeIntFreq(*)>(_a[1]))); break;
        case 36: _t->TimeSyncTrackingTypeChanged((*reinterpret_cast< ETypeTiSyncTrac(*)>(_a[1]))); break;
        case 37: _t->ReverbEffectChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->AcquisitionStateChanged((*reinterpret_cast< EAcqStat(*)>(_a[1]))); break;
        case 39: _t->FrequencyChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->drmModeStarted(); break;
        case 41: _t->amModeStarted(); break;
        case 42: _t->fmModeStarted(); break;
        case 43: _t->LoadSettings(); break;
        case 44: _t->SaveSettings(); break;
        case 45: _t->SetInputDevice((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 46: _t->SetOutputDevice((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 47: _t->SetInputDevice((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 48: _t->SetOutputDevice((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 49: _t->Start(); break;
        case 50: _t->Stop(); break;
        case 51: _t->Restart(); break;
        case 52: _t->SetSettings((*reinterpret_cast< CSettings*(*)>(_a[1]))); break;
        case 53: _t->StartWriteWaveFile((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 54: _t->StopWriteWaveFile(); break;
        case 55: _t->SetTimeInterpolationAlgorithm((*reinterpret_cast< ETypeIntTime(*)>(_a[1]))); break;
        case 56: _t->SetFrequencyInterpolationAlgorithm((*reinterpret_cast< ETypeIntFreq(*)>(_a[1]))); break;
        case 57: _t->SetTimeSyncTrackingType((*reinterpret_cast< ETypeTiSyncTrac(*)>(_a[1]))); break;
        case 58: _t->SetNumMSCMLCIterations((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 59: _t->SetFlipSpectrum((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 60: _t->SetFrequencySyncAcquisitionFilter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 61: _t->SetConsiderInterferer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 62: _t->MuteAudio((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 63: _t->SetReverberationEffect((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 64: _t->SetReceiverMode((*reinterpret_cast< ERecMode(*)>(_a[1]))); break;
        case 65: _t->SetAMDemodulationType((*reinterpret_cast< EDemodType(*)>(_a[1]))); break;
        case 66: _t->SetAMFilterBW((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 67: _t->SetAMAGCType((*reinterpret_cast< EAmAgcType(*)>(_a[1]))); break;
        case 68: _t->SetAMNoiseReductionType((*reinterpret_cast< ENoiRedType(*)>(_a[1]))); break;
        case 69: _t->SetAMNoiseReductionLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 70: _t->SetFrequency((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 71: _t->SetAMDemodAcq((*reinterpret_cast< _REAL(*)>(_a[1]))); break;
        case 72: _t->EnableAMPLL((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 73: _t->EnableAutoFrequenctAcquisition((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 74: _t->onSoundInChannelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 75: _t->onSoundOutChannelChanged((*reinterpret_cast< EOutChanSel(*)>(_a[1]))); break;
        case 76: _t->onSoundSampleRateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 77: _t->SetSoundSignalUpscale((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CReceiverQt::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::inputSampleRateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::outputSampleRateChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::soundUpscaleRatioChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::soundFileChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::InputDeviceChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::OutputDeviceChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::AMBWParametersChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::AMNoiseReductionLevelChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(ENoiRedType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::AMNoiseReductionTypeChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(EDemodType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::AMDemodulationTypeChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(EAmAgcType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::AMAGCTypeChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::AMFilterBWChanged)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::AMMixerFrequencyOffsetChanged)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(_REAL );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::AMPLLPhaseChanged)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(ERecMode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::ReceiverModeChanged)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::InputChannelChanged)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::OutputChannelChanged)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::MSCMLInitNumIterationsChanged)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::isInputRSCIChanged)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::isWriteWaveFileChanged)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::isAudioMutedChanged)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::isIntefererConsiderationEnabledChanged)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::isFrequencySyncAcquisitionFilterEnabledChanged)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::isSpectrumFlippedChanged)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::isAMAutoFrequencyAcquisitionEnabledChanged)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::isAMPLLEnabledChanged)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(_REAL );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::AMSSPLLPhaseChanged)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::AMSSPercentageDataEntityGroupCompleteChanged)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::AMSSDataEntityGroupStatusChanged)) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::AMSSCurrentBlockChanged)) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::AMSSCurrentBlockBitsChanged)) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::AMSSBlock1StatusChanged)) {
                *result = 31;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(EAMSSBlockLockStat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::AMSSLockStatusChanged)) {
                *result = 32;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::canDecodeChanged)) {
                *result = 33;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(ETypeIntTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::TimeInterpolationAlgorithmChanged)) {
                *result = 34;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(ETypeIntFreq );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::FrequencyInterpolationAlgorithmChanged)) {
                *result = 35;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(ETypeTiSyncTrac );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::TimeSyncTrackingTypeChanged)) {
                *result = 36;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::ReverbEffectChanged)) {
                *result = 37;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(EAcqStat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::AcquisitionStateChanged)) {
                *result = 38;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::FrequencyChanged)) {
                *result = 39;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::drmModeStarted)) {
                *result = 40;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::amModeStarted)) {
                *result = 41;
                return;
            }
        }
        {
            using _t = void (CReceiverQt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CReceiverQt::fmModeStarted)) {
                *result = 42;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CReceiverQt::staticMetaObject = { {
    QMetaObject::SuperData::link<CTransceiverQt::staticMetaObject>(),
    qt_meta_stringdata_CReceiverQt.data,
    qt_meta_data_CReceiverQt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CReceiverQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CReceiverQt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CReceiverQt.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "CDRMReceiver"))
        return static_cast< CDRMReceiver*>(this);
    return CTransceiverQt::qt_metacast(_clname);
}

int CReceiverQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CTransceiverQt::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 78)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 78;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 78)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 78;
    }
    return _id;
}

// SIGNAL 0
void CReceiverQt::inputSampleRateChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CReceiverQt::outputSampleRateChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CReceiverQt::soundUpscaleRatioChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CReceiverQt::soundFileChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CReceiverQt::InputDeviceChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CReceiverQt::OutputDeviceChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CReceiverQt::AMBWParametersChanged(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CReceiverQt::AMNoiseReductionLevelChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CReceiverQt::AMNoiseReductionTypeChanged(ENoiRedType _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void CReceiverQt::AMDemodulationTypeChanged(EDemodType _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void CReceiverQt::AMAGCTypeChanged(EAmAgcType _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void CReceiverQt::AMFilterBWChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void CReceiverQt::AMMixerFrequencyOffsetChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void CReceiverQt::AMPLLPhaseChanged(_REAL _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void CReceiverQt::ReceiverModeChanged(ERecMode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void CReceiverQt::InputChannelChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void CReceiverQt::OutputChannelChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void CReceiverQt::MSCMLInitNumIterationsChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void CReceiverQt::isInputRSCIChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void CReceiverQt::isWriteWaveFileChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void CReceiverQt::isAudioMutedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void CReceiverQt::isIntefererConsiderationEnabledChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void CReceiverQt::isFrequencySyncAcquisitionFilterEnabledChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void CReceiverQt::isSpectrumFlippedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void CReceiverQt::isAMAutoFrequencyAcquisitionEnabledChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void CReceiverQt::isAMPLLEnabledChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void CReceiverQt::AMSSPLLPhaseChanged(_REAL _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void CReceiverQt::AMSSPercentageDataEntityGroupCompleteChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void CReceiverQt::AMSSDataEntityGroupStatusChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void CReceiverQt::AMSSCurrentBlockChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void CReceiverQt::AMSSCurrentBlockBitsChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void CReceiverQt::AMSSBlock1StatusChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void CReceiverQt::AMSSLockStatusChanged(EAMSSBlockLockStat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 33
void CReceiverQt::canDecodeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 33, _a);
}

// SIGNAL 34
void CReceiverQt::TimeInterpolationAlgorithmChanged(ETypeIntTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 34, _a);
}

// SIGNAL 35
void CReceiverQt::FrequencyInterpolationAlgorithmChanged(ETypeIntFreq _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 35, _a);
}

// SIGNAL 36
void CReceiverQt::TimeSyncTrackingTypeChanged(ETypeTiSyncTrac _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 36, _a);
}

// SIGNAL 37
void CReceiverQt::ReverbEffectChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 37, _a);
}

// SIGNAL 38
void CReceiverQt::AcquisitionStateChanged(EAcqStat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 38, _a);
}

// SIGNAL 39
void CReceiverQt::FrequencyChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 39, _a);
}

// SIGNAL 40
void CReceiverQt::drmModeStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 40, nullptr);
}

// SIGNAL 41
void CReceiverQt::amModeStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 41, nullptr);
}

// SIGNAL 42
void CReceiverQt::fmModeStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 42, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
