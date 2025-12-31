/****************************************************************************
** Meta object code from reading C++ file 'crx.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/main-Qt/crx.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'crx.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CRx_t {
    QByteArrayData data[99];
    char stringdata0[1924];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CRx_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CRx_t qt_meta_stringdata_CRx = {
    {
QT_MOC_LITERAL(0, 0, 3), // "CRx"
QT_MOC_LITERAL(1, 4, 22), // "inputSampleRateChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 23), // "outputSampleRateChanged"
QT_MOC_LITERAL(4, 52, 24), // "soundUpscaleRatioChanged"
QT_MOC_LITERAL(5, 77, 16), // "soundFileChanged"
QT_MOC_LITERAL(6, 94, 18), // "InputDeviceChanged"
QT_MOC_LITERAL(7, 113, 19), // "OutputDeviceChanged"
QT_MOC_LITERAL(8, 133, 21), // "AMBWParametersChanged"
QT_MOC_LITERAL(9, 155, 11), // "rCenterFreq"
QT_MOC_LITERAL(10, 167, 3), // "rBW"
QT_MOC_LITERAL(11, 171, 28), // "AMNoiseReductionLevelChanged"
QT_MOC_LITERAL(12, 200, 27), // "AMNoiseReductionTypeChanged"
QT_MOC_LITERAL(13, 228, 11), // "ENoiRedType"
QT_MOC_LITERAL(14, 240, 25), // "AMDemodulationTypeChanged"
QT_MOC_LITERAL(15, 266, 10), // "EDemodType"
QT_MOC_LITERAL(16, 277, 16), // "AMAGCTypeChanged"
QT_MOC_LITERAL(17, 294, 10), // "EAmAgcType"
QT_MOC_LITERAL(18, 305, 17), // "AMFilterBWChanged"
QT_MOC_LITERAL(19, 323, 29), // "AMMixerFrequencyOffsetChanged"
QT_MOC_LITERAL(20, 353, 17), // "AMPLLPhaseChanged"
QT_MOC_LITERAL(21, 371, 5), // "_REAL"
QT_MOC_LITERAL(22, 377, 19), // "ReceiverModeChanged"
QT_MOC_LITERAL(23, 397, 8), // "ERecMode"
QT_MOC_LITERAL(24, 406, 19), // "InputChannelChanged"
QT_MOC_LITERAL(25, 426, 20), // "OutputChannelChanged"
QT_MOC_LITERAL(26, 447, 29), // "MSCMLInitNumIterationsChanged"
QT_MOC_LITERAL(27, 477, 18), // "isInputRSCIChanged"
QT_MOC_LITERAL(28, 496, 22), // "isWriteWaveFileChanged"
QT_MOC_LITERAL(29, 519, 19), // "isAudioMutedChanged"
QT_MOC_LITERAL(30, 539, 38), // "isIntefererConsiderationEnabl..."
QT_MOC_LITERAL(31, 578, 46), // "isFrequencySyncAcquisitionFil..."
QT_MOC_LITERAL(32, 625, 24), // "isSpectrumFlippedChanged"
QT_MOC_LITERAL(33, 650, 42), // "isAMAutoFrequencyAcquisitionE..."
QT_MOC_LITERAL(34, 693, 21), // "isAMPLLEnabledChanged"
QT_MOC_LITERAL(35, 715, 19), // "AMSSPLLPhaseChanged"
QT_MOC_LITERAL(36, 735, 44), // "AMSSPercentageDataEntityGroup..."
QT_MOC_LITERAL(37, 780, 32), // "AMSSDataEntityGroupStatusChanged"
QT_MOC_LITERAL(38, 813, 23), // "AMSSCurrentBlockChanged"
QT_MOC_LITERAL(39, 837, 27), // "AMSSCurrentBlockBitsChanged"
QT_MOC_LITERAL(40, 865, 23), // "AMSSBlock1StatusChanged"
QT_MOC_LITERAL(41, 889, 21), // "AMSSLockStatusChanged"
QT_MOC_LITERAL(42, 911, 18), // "EAMSSBlockLockStat"
QT_MOC_LITERAL(43, 930, 16), // "canDecodeChanged"
QT_MOC_LITERAL(44, 947, 33), // "TimeInterpolationAlgorithmCha..."
QT_MOC_LITERAL(45, 981, 12), // "ETypeIntTime"
QT_MOC_LITERAL(46, 994, 38), // "FrequencyInterpolationAlgorit..."
QT_MOC_LITERAL(47, 1033, 12), // "ETypeIntFreq"
QT_MOC_LITERAL(48, 1046, 27), // "TimeSyncTrackingTypeChanged"
QT_MOC_LITERAL(49, 1074, 15), // "ETypeTiSyncTrac"
QT_MOC_LITERAL(50, 1090, 19), // "ReverbEffectChanged"
QT_MOC_LITERAL(51, 1110, 23), // "AcquisitionStateChanged"
QT_MOC_LITERAL(52, 1134, 8), // "EAcqStat"
QT_MOC_LITERAL(53, 1143, 16), // "FrequencyChanged"
QT_MOC_LITERAL(54, 1160, 14), // "drmModeStarted"
QT_MOC_LITERAL(55, 1175, 13), // "amModeStarted"
QT_MOC_LITERAL(56, 1189, 13), // "fmModeStarted"
QT_MOC_LITERAL(57, 1203, 8), // "finished"
QT_MOC_LITERAL(58, 1212, 12), // "LoadSettings"
QT_MOC_LITERAL(59, 1225, 12), // "SaveSettings"
QT_MOC_LITERAL(60, 1238, 14), // "SetInputDevice"
QT_MOC_LITERAL(61, 1253, 11), // "std::string"
QT_MOC_LITERAL(62, 1265, 15), // "SetOutputDevice"
QT_MOC_LITERAL(63, 1281, 5), // "Start"
QT_MOC_LITERAL(64, 1287, 4), // "Stop"
QT_MOC_LITERAL(65, 1292, 7), // "Restart"
QT_MOC_LITERAL(66, 1300, 11), // "SetSettings"
QT_MOC_LITERAL(67, 1312, 10), // "CSettings*"
QT_MOC_LITERAL(68, 1323, 12), // "pNewSettings"
QT_MOC_LITERAL(69, 1336, 10), // "IsReceiver"
QT_MOC_LITERAL(70, 1347, 13), // "IsTransmitter"
QT_MOC_LITERAL(71, 1361, 18), // "StartWriteWaveFile"
QT_MOC_LITERAL(72, 1380, 17), // "StopWriteWaveFile"
QT_MOC_LITERAL(73, 1398, 29), // "SetTimeInterpolationAlgorithm"
QT_MOC_LITERAL(74, 1428, 34), // "SetFrequencyInterpolationAlgo..."
QT_MOC_LITERAL(75, 1463, 23), // "SetTimeSyncTrackingType"
QT_MOC_LITERAL(76, 1487, 22), // "SetNumMSCMLCIterations"
QT_MOC_LITERAL(77, 1510, 15), // "SetFlipSpectrum"
QT_MOC_LITERAL(78, 1526, 33), // "SetFrequencySyncAcquisitionFi..."
QT_MOC_LITERAL(79, 1560, 21), // "SetConsiderInterferer"
QT_MOC_LITERAL(80, 1582, 9), // "MuteAudio"
QT_MOC_LITERAL(81, 1592, 22), // "SetReverberationEffect"
QT_MOC_LITERAL(82, 1615, 15), // "SetReceiverMode"
QT_MOC_LITERAL(83, 1631, 21), // "SetAMDemodulationType"
QT_MOC_LITERAL(84, 1653, 13), // "SetAMFilterBW"
QT_MOC_LITERAL(85, 1667, 12), // "SetAMAGCType"
QT_MOC_LITERAL(86, 1680, 23), // "SetAMNoiseReductionType"
QT_MOC_LITERAL(87, 1704, 24), // "SetAMNoiseReductionLevel"
QT_MOC_LITERAL(88, 1729, 12), // "SetFrequency"
QT_MOC_LITERAL(89, 1742, 13), // "SetAMDemodAcq"
QT_MOC_LITERAL(90, 1756, 11), // "EnableAMPLL"
QT_MOC_LITERAL(91, 1768, 30), // "EnableAutoFrequenctAcquisition"
QT_MOC_LITERAL(92, 1799, 23), // "onSoundInChannelChanged"
QT_MOC_LITERAL(93, 1823, 24), // "onSoundOutChannelChanged"
QT_MOC_LITERAL(94, 1848, 11), // "EOutChanSel"
QT_MOC_LITERAL(95, 1860, 24), // "onSoundSampleRateChanged"
QT_MOC_LITERAL(96, 1885, 21), // "SetSoundSignalUpscale"
QT_MOC_LITERAL(97, 1907, 6), // "doWork"
QT_MOC_LITERAL(98, 1914, 9) // "doRestart"

    },
    "CRx\0inputSampleRateChanged\0\0"
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
    "amModeStarted\0fmModeStarted\0finished\0"
    "LoadSettings\0SaveSettings\0SetInputDevice\0"
    "std::string\0SetOutputDevice\0Start\0"
    "Stop\0Restart\0SetSettings\0CSettings*\0"
    "pNewSettings\0IsReceiver\0IsTransmitter\0"
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
    "onSoundSampleRateChanged\0SetSoundSignalUpscale\0"
    "doWork\0doRestart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CRx[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      83,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      44,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  429,    2, 0x06 /* Public */,
       3,    1,  432,    2, 0x06 /* Public */,
       4,    1,  435,    2, 0x06 /* Public */,
       5,    1,  438,    2, 0x06 /* Public */,
       6,    1,  441,    2, 0x06 /* Public */,
       7,    1,  444,    2, 0x06 /* Public */,
       8,    2,  447,    2, 0x06 /* Public */,
      11,    1,  452,    2, 0x06 /* Public */,
      12,    1,  455,    2, 0x06 /* Public */,
      14,    1,  458,    2, 0x06 /* Public */,
      16,    1,  461,    2, 0x06 /* Public */,
      18,    1,  464,    2, 0x06 /* Public */,
      19,    1,  467,    2, 0x06 /* Public */,
      20,    1,  470,    2, 0x06 /* Public */,
      22,    1,  473,    2, 0x06 /* Public */,
      24,    1,  476,    2, 0x06 /* Public */,
      25,    1,  479,    2, 0x06 /* Public */,
      26,    1,  482,    2, 0x06 /* Public */,
      27,    1,  485,    2, 0x06 /* Public */,
      28,    1,  488,    2, 0x06 /* Public */,
      29,    1,  491,    2, 0x06 /* Public */,
      30,    1,  494,    2, 0x06 /* Public */,
      31,    1,  497,    2, 0x06 /* Public */,
      32,    1,  500,    2, 0x06 /* Public */,
      33,    1,  503,    2, 0x06 /* Public */,
      34,    1,  506,    2, 0x06 /* Public */,
      35,    1,  509,    2, 0x06 /* Public */,
      36,    1,  512,    2, 0x06 /* Public */,
      37,    1,  515,    2, 0x06 /* Public */,
      38,    1,  518,    2, 0x06 /* Public */,
      39,    1,  521,    2, 0x06 /* Public */,
      40,    1,  524,    2, 0x06 /* Public */,
      41,    1,  527,    2, 0x06 /* Public */,
      43,    1,  530,    2, 0x06 /* Public */,
      44,    1,  533,    2, 0x06 /* Public */,
      46,    1,  536,    2, 0x06 /* Public */,
      48,    1,  539,    2, 0x06 /* Public */,
      50,    1,  542,    2, 0x06 /* Public */,
      51,    1,  545,    2, 0x06 /* Public */,
      53,    1,  548,    2, 0x06 /* Public */,
      54,    0,  551,    2, 0x06 /* Public */,
      55,    0,  552,    2, 0x06 /* Public */,
      56,    0,  553,    2, 0x06 /* Public */,
      57,    0,  554,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      58,    0,  555,    2, 0x0a /* Public */,
      59,    0,  556,    2, 0x0a /* Public */,
      60,    1,  557,    2, 0x0a /* Public */,
      62,    1,  560,    2, 0x0a /* Public */,
      60,    1,  563,    2, 0x0a /* Public */,
      62,    1,  566,    2, 0x0a /* Public */,
      63,    0,  569,    2, 0x0a /* Public */,
      64,    0,  570,    2, 0x0a /* Public */,
      65,    0,  571,    2, 0x0a /* Public */,
      66,    1,  572,    2, 0x0a /* Public */,
      69,    0,  575,    2, 0x0a /* Public */,
      70,    0,  576,    2, 0x0a /* Public */,
      71,    1,  577,    2, 0x0a /* Public */,
      72,    0,  580,    2, 0x0a /* Public */,
      73,    1,  581,    2, 0x0a /* Public */,
      74,    1,  584,    2, 0x0a /* Public */,
      75,    1,  587,    2, 0x0a /* Public */,
      76,    1,  590,    2, 0x0a /* Public */,
      77,    1,  593,    2, 0x0a /* Public */,
      78,    1,  596,    2, 0x0a /* Public */,
      79,    1,  599,    2, 0x0a /* Public */,
      80,    1,  602,    2, 0x0a /* Public */,
      81,    1,  605,    2, 0x0a /* Public */,
      82,    1,  608,    2, 0x0a /* Public */,
      83,    1,  611,    2, 0x0a /* Public */,
      84,    1,  614,    2, 0x0a /* Public */,
      85,    1,  617,    2, 0x0a /* Public */,
      86,    1,  620,    2, 0x0a /* Public */,
      87,    1,  623,    2, 0x0a /* Public */,
      88,    1,  626,    2, 0x0a /* Public */,
      89,    1,  629,    2, 0x0a /* Public */,
      90,    1,  632,    2, 0x0a /* Public */,
      91,    1,  635,    2, 0x0a /* Public */,
      92,    1,  638,    2, 0x0a /* Public */,
      93,    1,  641,    2, 0x0a /* Public */,
      95,    1,  644,    2, 0x0a /* Public */,
      96,    1,  647,    2, 0x0a /* Public */,
      97,    0,  650,    2, 0x0a /* Public */,
      98,    0,  651,    2, 0x0a /* Public */,

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
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 61,    2,
    QMetaType::Void, 0x80000000 | 61,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 67,   68,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, 0x80000000 | 61,    2,
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
    QMetaType::Void, 0x80000000 | 94,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CRx::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CRx *>(_o);
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
        case 43: _t->finished(); break;
        case 44: _t->LoadSettings(); break;
        case 45: _t->SaveSettings(); break;
        case 46: _t->SetInputDevice((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 47: _t->SetOutputDevice((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 48: _t->SetInputDevice((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 49: _t->SetOutputDevice((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 50: _t->Start(); break;
        case 51: _t->Stop(); break;
        case 52: _t->Restart(); break;
        case 53: _t->SetSettings((*reinterpret_cast< CSettings*(*)>(_a[1]))); break;
        case 54: { bool _r = _t->IsReceiver();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 55: { bool _r = _t->IsTransmitter();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 56: _t->StartWriteWaveFile((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 57: _t->StopWriteWaveFile(); break;
        case 58: _t->SetTimeInterpolationAlgorithm((*reinterpret_cast< ETypeIntTime(*)>(_a[1]))); break;
        case 59: _t->SetFrequencyInterpolationAlgorithm((*reinterpret_cast< ETypeIntFreq(*)>(_a[1]))); break;
        case 60: _t->SetTimeSyncTrackingType((*reinterpret_cast< ETypeTiSyncTrac(*)>(_a[1]))); break;
        case 61: _t->SetNumMSCMLCIterations((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 62: _t->SetFlipSpectrum((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 63: _t->SetFrequencySyncAcquisitionFilter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 64: _t->SetConsiderInterferer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 65: _t->MuteAudio((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 66: _t->SetReverberationEffect((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 67: _t->SetReceiverMode((*reinterpret_cast< ERecMode(*)>(_a[1]))); break;
        case 68: _t->SetAMDemodulationType((*reinterpret_cast< EDemodType(*)>(_a[1]))); break;
        case 69: _t->SetAMFilterBW((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 70: _t->SetAMAGCType((*reinterpret_cast< EAmAgcType(*)>(_a[1]))); break;
        case 71: _t->SetAMNoiseReductionType((*reinterpret_cast< ENoiRedType(*)>(_a[1]))); break;
        case 72: _t->SetAMNoiseReductionLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 73: _t->SetFrequency((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 74: _t->SetAMDemodAcq((*reinterpret_cast< _REAL(*)>(_a[1]))); break;
        case 75: _t->EnableAMPLL((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 76: _t->EnableAutoFrequenctAcquisition((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 77: _t->onSoundInChannelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 78: _t->onSoundOutChannelChanged((*reinterpret_cast< EOutChanSel(*)>(_a[1]))); break;
        case 79: _t->onSoundSampleRateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 80: _t->SetSoundSignalUpscale((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 81: _t->doWork(); break;
        case 82: _t->doRestart(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CRx::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::inputSampleRateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CRx::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::outputSampleRateChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CRx::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::soundUpscaleRatioChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CRx::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::soundFileChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CRx::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::InputDeviceChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CRx::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::OutputDeviceChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CRx::*)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::AMBWParametersChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CRx::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::AMNoiseReductionLevelChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (CRx::*)(ENoiRedType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::AMNoiseReductionTypeChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (CRx::*)(EDemodType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::AMDemodulationTypeChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (CRx::*)(EAmAgcType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::AMAGCTypeChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (CRx::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::AMFilterBWChanged)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (CRx::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::AMMixerFrequencyOffsetChanged)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (CRx::*)(_REAL );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::AMPLLPhaseChanged)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (CRx::*)(ERecMode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::ReceiverModeChanged)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (CRx::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::InputChannelChanged)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (CRx::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::OutputChannelChanged)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (CRx::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::MSCMLInitNumIterationsChanged)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (CRx::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::isInputRSCIChanged)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (CRx::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::isWriteWaveFileChanged)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (CRx::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::isAudioMutedChanged)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (CRx::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::isIntefererConsiderationEnabledChanged)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (CRx::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::isFrequencySyncAcquisitionFilterEnabledChanged)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (CRx::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::isSpectrumFlippedChanged)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (CRx::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::isAMAutoFrequencyAcquisitionEnabledChanged)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (CRx::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::isAMPLLEnabledChanged)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (CRx::*)(_REAL );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::AMSSPLLPhaseChanged)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (CRx::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::AMSSPercentageDataEntityGroupCompleteChanged)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (CRx::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::AMSSDataEntityGroupStatusChanged)) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (CRx::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::AMSSCurrentBlockChanged)) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (CRx::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::AMSSCurrentBlockBitsChanged)) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (CRx::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::AMSSBlock1StatusChanged)) {
                *result = 31;
                return;
            }
        }
        {
            using _t = void (CRx::*)(EAMSSBlockLockStat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::AMSSLockStatusChanged)) {
                *result = 32;
                return;
            }
        }
        {
            using _t = void (CRx::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::canDecodeChanged)) {
                *result = 33;
                return;
            }
        }
        {
            using _t = void (CRx::*)(ETypeIntTime );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::TimeInterpolationAlgorithmChanged)) {
                *result = 34;
                return;
            }
        }
        {
            using _t = void (CRx::*)(ETypeIntFreq );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::FrequencyInterpolationAlgorithmChanged)) {
                *result = 35;
                return;
            }
        }
        {
            using _t = void (CRx::*)(ETypeTiSyncTrac );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::TimeSyncTrackingTypeChanged)) {
                *result = 36;
                return;
            }
        }
        {
            using _t = void (CRx::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::ReverbEffectChanged)) {
                *result = 37;
                return;
            }
        }
        {
            using _t = void (CRx::*)(EAcqStat );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::AcquisitionStateChanged)) {
                *result = 38;
                return;
            }
        }
        {
            using _t = void (CRx::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::FrequencyChanged)) {
                *result = 39;
                return;
            }
        }
        {
            using _t = void (CRx::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::drmModeStarted)) {
                *result = 40;
                return;
            }
        }
        {
            using _t = void (CRx::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::amModeStarted)) {
                *result = 41;
                return;
            }
        }
        {
            using _t = void (CRx::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::fmModeStarted)) {
                *result = 42;
                return;
            }
        }
        {
            using _t = void (CRx::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CRx::finished)) {
                *result = 43;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CRx::staticMetaObject = { {
    QMetaObject::SuperData::link<CTRx::staticMetaObject>(),
    qt_meta_stringdata_CRx.data,
    qt_meta_data_CRx,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CRx::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CRx::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CRx.stringdata0))
        return static_cast<void*>(this);
    return CTRx::qt_metacast(_clname);
}

int CRx::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CTRx::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 83)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 83;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 83)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 83;
    }
    return _id;
}

// SIGNAL 0
void CRx::inputSampleRateChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CRx::outputSampleRateChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CRx::soundUpscaleRatioChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CRx::soundFileChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CRx::InputDeviceChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CRx::OutputDeviceChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CRx::AMBWParametersChanged(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CRx::AMNoiseReductionLevelChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CRx::AMNoiseReductionTypeChanged(ENoiRedType _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void CRx::AMDemodulationTypeChanged(EDemodType _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void CRx::AMAGCTypeChanged(EAmAgcType _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void CRx::AMFilterBWChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void CRx::AMMixerFrequencyOffsetChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void CRx::AMPLLPhaseChanged(_REAL _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void CRx::ReceiverModeChanged(ERecMode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void CRx::InputChannelChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void CRx::OutputChannelChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void CRx::MSCMLInitNumIterationsChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void CRx::isInputRSCIChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void CRx::isWriteWaveFileChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void CRx::isAudioMutedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void CRx::isIntefererConsiderationEnabledChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void CRx::isFrequencySyncAcquisitionFilterEnabledChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void CRx::isSpectrumFlippedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void CRx::isAMAutoFrequencyAcquisitionEnabledChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void CRx::isAMPLLEnabledChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void CRx::AMSSPLLPhaseChanged(_REAL _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void CRx::AMSSPercentageDataEntityGroupCompleteChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void CRx::AMSSDataEntityGroupStatusChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void CRx::AMSSCurrentBlockChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void CRx::AMSSCurrentBlockBitsChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void CRx::AMSSBlock1StatusChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void CRx::AMSSLockStatusChanged(EAMSSBlockLockStat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 33
void CRx::canDecodeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 33, _a);
}

// SIGNAL 34
void CRx::TimeInterpolationAlgorithmChanged(ETypeIntTime _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 34, _a);
}

// SIGNAL 35
void CRx::FrequencyInterpolationAlgorithmChanged(ETypeIntFreq _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 35, _a);
}

// SIGNAL 36
void CRx::TimeSyncTrackingTypeChanged(ETypeTiSyncTrac _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 36, _a);
}

// SIGNAL 37
void CRx::ReverbEffectChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 37, _a);
}

// SIGNAL 38
void CRx::AcquisitionStateChanged(EAcqStat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 38, _a);
}

// SIGNAL 39
void CRx::FrequencyChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 39, _a);
}

// SIGNAL 40
void CRx::drmModeStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 40, nullptr);
}

// SIGNAL 41
void CRx::amModeStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 41, nullptr);
}

// SIGNAL 42
void CRx::fmModeStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 42, nullptr);
}

// SIGNAL 43
void CRx::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 43, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
