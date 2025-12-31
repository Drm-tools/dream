/********************************************************************************
** Form generated from reading UI file 'systemevalDlgbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMEVALDLGBASE_H
#define UI_SYSTEMEVALDLGBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MultColorLED.h"
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_SystemEvaluationWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *hboxLayout;
    QFrame *FrameParamStatusLEDs;
    QHBoxLayout *_2;
    QVBoxLayout *_3;
    QLabel *TextSNRText;
    QLabel *TextMERWMER;
    QLabel *TextFreqOffset;
    QLabel *TextSampFreqOffset;
    QLabel *TextWiener;
    QVBoxLayout *_4;
    QLabel *ValueSNR;
    QLabel *ValueMERWMER;
    QLabel *ValueFreqOffset;
    QLabel *ValueSampFreqOffset;
    QLabel *ValueWiener;
    QFrame *FrameParamStatusLEDs_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *_7;
    QLabel *TextLabelLEDMSCCRC;
    CMultColorLED *LEDMSC;
    QHBoxLayout *_8;
    QLabel *TextLabelLEDSDCCRC;
    CMultColorLED *LEDSDC;
    QHBoxLayout *_9;
    QLabel *TextLabelLEDFACCRC;
    CMultColorLED *LEDFAC;
    QHBoxLayout *_10;
    QLabel *TextLabelLEDFrameSync;
    CMultColorLED *LEDFrameSync;
    QHBoxLayout *_11;
    QLabel *TextLabelLEDTimeSyncAcq;
    CMultColorLED *LEDTimeSync;
    QHBoxLayout *_12;
    QLabel *TextLabelLEDIOInterface;
    CMultColorLED *LEDIOInterface;
    QFrame *FrameFACParams;
    QHBoxLayout *_13;
    QVBoxLayout *_14;
    QLabel *FACDRMModeBWL;
    QLabel *FACInterleaverDepthL;
    QLabel *FACSDCMSCModeL;
    QLabel *FACCodeRateL;
    QLabel *FACNumServicesL;
    QLabel *FACTimeDateL;
    QVBoxLayout *_15;
    QLabel *FACDRMModeBWV;
    QLabel *FACInterleaverDepthV;
    QLabel *FACSDCMSCModeV;
    QLabel *FACCodeRateV;
    QLabel *FACNumServicesV;
    QLabel *FACTimeDateV;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *chartSelector;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QwtPlot *plot;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *_18;
    QGroupBox *ButtonGroupChanEstFreqInt;
    QHBoxLayout *_19;
    QRadioButton *RadioButtonFreqWiener;
    QRadioButton *RadioButtonFreqLinear;
    QRadioButton *RadioButtonFreqDFT;
    QGroupBox *ButtonGroupChanEstTimeInt;
    QHBoxLayout *_20;
    QRadioButton *RadioButtonTiWiener;
    QRadioButton *RadioButtonTiLinear;
    QGroupBox *ButtonGroupTimeSyncTrack;
    QHBoxLayout *_21;
    QRadioButton *RadioButtonTiSyncEnergy;
    QRadioButton *RadioButtonTiSyncFirstPeak;
    QVBoxLayout *_22;
    QGroupBox *GroupBoxMiscSettings;
    QHBoxLayout *_23;
    QVBoxLayout *_24;
    QCheckBox *CheckBoxFlipSpec;
    QCheckBox *CheckBoxWriteLog;
    QVBoxLayout *_25;
    QLabel *TextNumOfIterations;
    QSlider *SliderNoOfIterations;
    QGroupBox *GroupBoxLogFileSaveData;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *CheckBoxMuteAudio;
    QCheckBox *CheckBoxReverb;
    QHBoxLayout *_28;
    QCheckBox *CheckBoxSaveAudioWave;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *_29;
    QGroupBox *GroupBoxInterfRej;
    QHBoxLayout *_30;
    QCheckBox *CheckBoxRecFilter;
    QCheckBox *CheckBoxModiMetric;
    QGroupBox *GroupBoxGPSStatus;
    QVBoxLayout *_31;
    QHBoxLayout *_32;
    QVBoxLayout *_33;
    QLabel *TextLabelGPSPosition;
    QLabel *TextLabelGPSTime;
    QLabel *TextLabelGPSSpeedHeading;
    QSpacerItem *Spacer18;
    QVBoxLayout *_34;
    QSpacerItem *Spacer21;
    CMultColorLED *LEDGPS;
    QHBoxLayout *_35;
    QSpacerItem *Spacer3;
    QPushButton *buttonOk;

    void setupUi(QMainWindow *SystemEvaluationWindow)
    {
        if (SystemEvaluationWindow->objectName().isEmpty())
            SystemEvaluationWindow->setObjectName(QString::fromUtf8("SystemEvaluationWindow"));
        SystemEvaluationWindow->resize(968, 539);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/MainIcon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        SystemEvaluationWindow->setWindowIcon(icon);
        centralwidget = new QWidget(SystemEvaluationWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        FrameParamStatusLEDs = new QFrame(centralwidget);
        FrameParamStatusLEDs->setObjectName(QString::fromUtf8("FrameParamStatusLEDs"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FrameParamStatusLEDs->sizePolicy().hasHeightForWidth());
        FrameParamStatusLEDs->setSizePolicy(sizePolicy);
        FrameParamStatusLEDs->setFrameShape(QFrame::Box);
        FrameParamStatusLEDs->setFrameShadow(QFrame::Sunken);
        _2 = new QHBoxLayout(FrameParamStatusLEDs);
        _2->setSpacing(6);
        _2->setObjectName(QString::fromUtf8("_2"));
        _2->setContentsMargins(6, 4, 6, 4);
        _3 = new QVBoxLayout();
#ifndef Q_OS_MAC
        _3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        _3->setContentsMargins(0, 0, 0, 0);
#endif
        _3->setObjectName(QString::fromUtf8("_3"));
        TextSNRText = new QLabel(FrameParamStatusLEDs);
        TextSNRText->setObjectName(QString::fromUtf8("TextSNRText"));
        sizePolicy.setHeightForWidth(TextSNRText->sizePolicy().hasHeightForWidth());
        TextSNRText->setSizePolicy(sizePolicy);
        TextSNRText->setMinimumSize(QSize(0, 0));
        TextSNRText->setWordWrap(false);

        _3->addWidget(TextSNRText);

        TextMERWMER = new QLabel(FrameParamStatusLEDs);
        TextMERWMER->setObjectName(QString::fromUtf8("TextMERWMER"));
        sizePolicy.setHeightForWidth(TextMERWMER->sizePolicy().hasHeightForWidth());
        TextMERWMER->setSizePolicy(sizePolicy);
        TextMERWMER->setMinimumSize(QSize(0, 0));
        TextMERWMER->setWordWrap(false);

        _3->addWidget(TextMERWMER);

        TextFreqOffset = new QLabel(FrameParamStatusLEDs);
        TextFreqOffset->setObjectName(QString::fromUtf8("TextFreqOffset"));
        sizePolicy.setHeightForWidth(TextFreqOffset->sizePolicy().hasHeightForWidth());
        TextFreqOffset->setSizePolicy(sizePolicy);
        TextFreqOffset->setMinimumSize(QSize(0, 0));
        TextFreqOffset->setWordWrap(false);

        _3->addWidget(TextFreqOffset);

        TextSampFreqOffset = new QLabel(FrameParamStatusLEDs);
        TextSampFreqOffset->setObjectName(QString::fromUtf8("TextSampFreqOffset"));
        sizePolicy.setHeightForWidth(TextSampFreqOffset->sizePolicy().hasHeightForWidth());
        TextSampFreqOffset->setSizePolicy(sizePolicy);
        TextSampFreqOffset->setWordWrap(false);

        _3->addWidget(TextSampFreqOffset);

        TextWiener = new QLabel(FrameParamStatusLEDs);
        TextWiener->setObjectName(QString::fromUtf8("TextWiener"));
        sizePolicy.setHeightForWidth(TextWiener->sizePolicy().hasHeightForWidth());
        TextWiener->setSizePolicy(sizePolicy);
        TextWiener->setMinimumSize(QSize(0, 0));
        TextWiener->setWordWrap(false);

        _3->addWidget(TextWiener);


        _2->addLayout(_3);

        _4 = new QVBoxLayout();
#ifndef Q_OS_MAC
        _4->setSpacing(6);
#endif
        _4->setContentsMargins(0, 0, 0, 0);
        _4->setObjectName(QString::fromUtf8("_4"));
        ValueSNR = new QLabel(FrameParamStatusLEDs);
        ValueSNR->setObjectName(QString::fromUtf8("ValueSNR"));
        sizePolicy.setHeightForWidth(ValueSNR->sizePolicy().hasHeightForWidth());
        ValueSNR->setSizePolicy(sizePolicy);
        ValueSNR->setMinimumSize(QSize(0, 0));
        ValueSNR->setWordWrap(false);

        _4->addWidget(ValueSNR);

        ValueMERWMER = new QLabel(FrameParamStatusLEDs);
        ValueMERWMER->setObjectName(QString::fromUtf8("ValueMERWMER"));
        sizePolicy.setHeightForWidth(ValueMERWMER->sizePolicy().hasHeightForWidth());
        ValueMERWMER->setSizePolicy(sizePolicy);
        ValueMERWMER->setMinimumSize(QSize(0, 0));
        ValueMERWMER->setWordWrap(false);

        _4->addWidget(ValueMERWMER);

        ValueFreqOffset = new QLabel(FrameParamStatusLEDs);
        ValueFreqOffset->setObjectName(QString::fromUtf8("ValueFreqOffset"));
        sizePolicy.setHeightForWidth(ValueFreqOffset->sizePolicy().hasHeightForWidth());
        ValueFreqOffset->setSizePolicy(sizePolicy);
        ValueFreqOffset->setMinimumSize(QSize(0, 0));
        ValueFreqOffset->setWordWrap(false);

        _4->addWidget(ValueFreqOffset);

        ValueSampFreqOffset = new QLabel(FrameParamStatusLEDs);
        ValueSampFreqOffset->setObjectName(QString::fromUtf8("ValueSampFreqOffset"));
        sizePolicy.setHeightForWidth(ValueSampFreqOffset->sizePolicy().hasHeightForWidth());
        ValueSampFreqOffset->setSizePolicy(sizePolicy);
        ValueSampFreqOffset->setWordWrap(false);

        _4->addWidget(ValueSampFreqOffset);

        ValueWiener = new QLabel(FrameParamStatusLEDs);
        ValueWiener->setObjectName(QString::fromUtf8("ValueWiener"));
        sizePolicy.setHeightForWidth(ValueWiener->sizePolicy().hasHeightForWidth());
        ValueWiener->setSizePolicy(sizePolicy);
        ValueWiener->setMinimumSize(QSize(100, 0));
        ValueWiener->setWordWrap(false);

        _4->addWidget(ValueWiener);


        _2->addLayout(_4);


        hboxLayout->addWidget(FrameParamStatusLEDs);

        FrameParamStatusLEDs_2 = new QFrame(centralwidget);
        FrameParamStatusLEDs_2->setObjectName(QString::fromUtf8("FrameParamStatusLEDs_2"));
        sizePolicy.setHeightForWidth(FrameParamStatusLEDs_2->sizePolicy().hasHeightForWidth());
        FrameParamStatusLEDs_2->setSizePolicy(sizePolicy);
        FrameParamStatusLEDs_2->setFrameShape(QFrame::Box);
        FrameParamStatusLEDs_2->setFrameShadow(QFrame::Sunken);
        verticalLayout_3 = new QVBoxLayout(FrameParamStatusLEDs_2);
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setContentsMargins(6, 6, 6, 6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        _7 = new QHBoxLayout();
#ifndef Q_OS_MAC
        _7->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        _7->setContentsMargins(0, 0, 0, 0);
#endif
        _7->setObjectName(QString::fromUtf8("_7"));
        TextLabelLEDMSCCRC = new QLabel(FrameParamStatusLEDs_2);
        TextLabelLEDMSCCRC->setObjectName(QString::fromUtf8("TextLabelLEDMSCCRC"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TextLabelLEDMSCCRC->sizePolicy().hasHeightForWidth());
        TextLabelLEDMSCCRC->setSizePolicy(sizePolicy1);
        TextLabelLEDMSCCRC->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        TextLabelLEDMSCCRC->setWordWrap(false);

        _7->addWidget(TextLabelLEDMSCCRC);

        LEDMSC = new CMultColorLED(FrameParamStatusLEDs_2);
        LEDMSC->setObjectName(QString::fromUtf8("LEDMSC"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(LEDMSC->sizePolicy().hasHeightForWidth());
        LEDMSC->setSizePolicy(sizePolicy2);
        LEDMSC->setMinimumSize(QSize(13, 13));
        LEDMSC->setMaximumSize(QSize(13, 13));

        _7->addWidget(LEDMSC);


        verticalLayout_3->addLayout(_7);

        _8 = new QHBoxLayout();
#ifndef Q_OS_MAC
        _8->setSpacing(6);
#endif
        _8->setContentsMargins(0, 0, 0, 0);
        _8->setObjectName(QString::fromUtf8("_8"));
        TextLabelLEDSDCCRC = new QLabel(FrameParamStatusLEDs_2);
        TextLabelLEDSDCCRC->setObjectName(QString::fromUtf8("TextLabelLEDSDCCRC"));
        sizePolicy1.setHeightForWidth(TextLabelLEDSDCCRC->sizePolicy().hasHeightForWidth());
        TextLabelLEDSDCCRC->setSizePolicy(sizePolicy1);
        TextLabelLEDSDCCRC->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        TextLabelLEDSDCCRC->setWordWrap(false);

        _8->addWidget(TextLabelLEDSDCCRC);

        LEDSDC = new CMultColorLED(FrameParamStatusLEDs_2);
        LEDSDC->setObjectName(QString::fromUtf8("LEDSDC"));
        sizePolicy2.setHeightForWidth(LEDSDC->sizePolicy().hasHeightForWidth());
        LEDSDC->setSizePolicy(sizePolicy2);
        LEDSDC->setMinimumSize(QSize(13, 13));
        LEDSDC->setMaximumSize(QSize(13, 13));

        _8->addWidget(LEDSDC);


        verticalLayout_3->addLayout(_8);

        _9 = new QHBoxLayout();
#ifndef Q_OS_MAC
        _9->setSpacing(6);
#endif
        _9->setContentsMargins(0, 0, 0, 0);
        _9->setObjectName(QString::fromUtf8("_9"));
        TextLabelLEDFACCRC = new QLabel(FrameParamStatusLEDs_2);
        TextLabelLEDFACCRC->setObjectName(QString::fromUtf8("TextLabelLEDFACCRC"));
        sizePolicy1.setHeightForWidth(TextLabelLEDFACCRC->sizePolicy().hasHeightForWidth());
        TextLabelLEDFACCRC->setSizePolicy(sizePolicy1);
        TextLabelLEDFACCRC->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        TextLabelLEDFACCRC->setWordWrap(false);

        _9->addWidget(TextLabelLEDFACCRC);

        LEDFAC = new CMultColorLED(FrameParamStatusLEDs_2);
        LEDFAC->setObjectName(QString::fromUtf8("LEDFAC"));
        sizePolicy2.setHeightForWidth(LEDFAC->sizePolicy().hasHeightForWidth());
        LEDFAC->setSizePolicy(sizePolicy2);
        LEDFAC->setMinimumSize(QSize(13, 13));
        LEDFAC->setMaximumSize(QSize(13, 13));

        _9->addWidget(LEDFAC);


        verticalLayout_3->addLayout(_9);

        _10 = new QHBoxLayout();
#ifndef Q_OS_MAC
        _10->setSpacing(6);
#endif
        _10->setContentsMargins(0, 0, 0, 0);
        _10->setObjectName(QString::fromUtf8("_10"));
        TextLabelLEDFrameSync = new QLabel(FrameParamStatusLEDs_2);
        TextLabelLEDFrameSync->setObjectName(QString::fromUtf8("TextLabelLEDFrameSync"));
        sizePolicy1.setHeightForWidth(TextLabelLEDFrameSync->sizePolicy().hasHeightForWidth());
        TextLabelLEDFrameSync->setSizePolicy(sizePolicy1);
        TextLabelLEDFrameSync->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        TextLabelLEDFrameSync->setWordWrap(false);

        _10->addWidget(TextLabelLEDFrameSync);

        LEDFrameSync = new CMultColorLED(FrameParamStatusLEDs_2);
        LEDFrameSync->setObjectName(QString::fromUtf8("LEDFrameSync"));
        sizePolicy2.setHeightForWidth(LEDFrameSync->sizePolicy().hasHeightForWidth());
        LEDFrameSync->setSizePolicy(sizePolicy2);
        LEDFrameSync->setMinimumSize(QSize(13, 13));
        LEDFrameSync->setMaximumSize(QSize(13, 13));

        _10->addWidget(LEDFrameSync);


        verticalLayout_3->addLayout(_10);

        _11 = new QHBoxLayout();
#ifndef Q_OS_MAC
        _11->setSpacing(6);
#endif
        _11->setContentsMargins(0, 0, 0, 0);
        _11->setObjectName(QString::fromUtf8("_11"));
        TextLabelLEDTimeSyncAcq = new QLabel(FrameParamStatusLEDs_2);
        TextLabelLEDTimeSyncAcq->setObjectName(QString::fromUtf8("TextLabelLEDTimeSyncAcq"));
        sizePolicy1.setHeightForWidth(TextLabelLEDTimeSyncAcq->sizePolicy().hasHeightForWidth());
        TextLabelLEDTimeSyncAcq->setSizePolicy(sizePolicy1);
        TextLabelLEDTimeSyncAcq->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        TextLabelLEDTimeSyncAcq->setWordWrap(false);

        _11->addWidget(TextLabelLEDTimeSyncAcq);

        LEDTimeSync = new CMultColorLED(FrameParamStatusLEDs_2);
        LEDTimeSync->setObjectName(QString::fromUtf8("LEDTimeSync"));
        sizePolicy2.setHeightForWidth(LEDTimeSync->sizePolicy().hasHeightForWidth());
        LEDTimeSync->setSizePolicy(sizePolicy2);
        LEDTimeSync->setMinimumSize(QSize(13, 13));
        LEDTimeSync->setMaximumSize(QSize(13, 13));

        _11->addWidget(LEDTimeSync);


        verticalLayout_3->addLayout(_11);

        _12 = new QHBoxLayout();
#ifndef Q_OS_MAC
        _12->setSpacing(6);
#endif
        _12->setContentsMargins(0, 0, 0, 0);
        _12->setObjectName(QString::fromUtf8("_12"));
        TextLabelLEDIOInterface = new QLabel(FrameParamStatusLEDs_2);
        TextLabelLEDIOInterface->setObjectName(QString::fromUtf8("TextLabelLEDIOInterface"));
        sizePolicy1.setHeightForWidth(TextLabelLEDIOInterface->sizePolicy().hasHeightForWidth());
        TextLabelLEDIOInterface->setSizePolicy(sizePolicy1);
        TextLabelLEDIOInterface->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        TextLabelLEDIOInterface->setWordWrap(false);

        _12->addWidget(TextLabelLEDIOInterface);

        LEDIOInterface = new CMultColorLED(FrameParamStatusLEDs_2);
        LEDIOInterface->setObjectName(QString::fromUtf8("LEDIOInterface"));
        sizePolicy2.setHeightForWidth(LEDIOInterface->sizePolicy().hasHeightForWidth());
        LEDIOInterface->setSizePolicy(sizePolicy2);
        LEDIOInterface->setMinimumSize(QSize(13, 13));
        LEDIOInterface->setMaximumSize(QSize(13, 13));

        _12->addWidget(LEDIOInterface);


        verticalLayout_3->addLayout(_12);


        hboxLayout->addWidget(FrameParamStatusLEDs_2);

        FrameFACParams = new QFrame(centralwidget);
        FrameFACParams->setObjectName(QString::fromUtf8("FrameFACParams"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(FrameFACParams->sizePolicy().hasHeightForWidth());
        FrameFACParams->setSizePolicy(sizePolicy3);
        FrameFACParams->setFrameShape(QFrame::Box);
        FrameFACParams->setFrameShadow(QFrame::Sunken);
        _13 = new QHBoxLayout(FrameFACParams);
        _13->setSpacing(6);
        _13->setObjectName(QString::fromUtf8("_13"));
        _13->setContentsMargins(6, 4, 6, 4);
        _14 = new QVBoxLayout();
        _14->setSpacing(0);
#ifndef Q_OS_MAC
        _14->setContentsMargins(0, 0, 0, 0);
#endif
        _14->setObjectName(QString::fromUtf8("_14"));
        FACDRMModeBWL = new QLabel(FrameFACParams);
        FACDRMModeBWL->setObjectName(QString::fromUtf8("FACDRMModeBWL"));
        sizePolicy.setHeightForWidth(FACDRMModeBWL->sizePolicy().hasHeightForWidth());
        FACDRMModeBWL->setSizePolicy(sizePolicy);
        FACDRMModeBWL->setWordWrap(false);
        FACDRMModeBWL->setIndent(-1);

        _14->addWidget(FACDRMModeBWL);

        FACInterleaverDepthL = new QLabel(FrameFACParams);
        FACInterleaverDepthL->setObjectName(QString::fromUtf8("FACInterleaverDepthL"));
        sizePolicy.setHeightForWidth(FACInterleaverDepthL->sizePolicy().hasHeightForWidth());
        FACInterleaverDepthL->setSizePolicy(sizePolicy);
        FACInterleaverDepthL->setWordWrap(false);

        _14->addWidget(FACInterleaverDepthL);

        FACSDCMSCModeL = new QLabel(FrameFACParams);
        FACSDCMSCModeL->setObjectName(QString::fromUtf8("FACSDCMSCModeL"));
        sizePolicy.setHeightForWidth(FACSDCMSCModeL->sizePolicy().hasHeightForWidth());
        FACSDCMSCModeL->setSizePolicy(sizePolicy);
        FACSDCMSCModeL->setWordWrap(false);

        _14->addWidget(FACSDCMSCModeL);

        FACCodeRateL = new QLabel(FrameFACParams);
        FACCodeRateL->setObjectName(QString::fromUtf8("FACCodeRateL"));
        sizePolicy.setHeightForWidth(FACCodeRateL->sizePolicy().hasHeightForWidth());
        FACCodeRateL->setSizePolicy(sizePolicy);
        FACCodeRateL->setWordWrap(false);

        _14->addWidget(FACCodeRateL);

        FACNumServicesL = new QLabel(FrameFACParams);
        FACNumServicesL->setObjectName(QString::fromUtf8("FACNumServicesL"));
        sizePolicy.setHeightForWidth(FACNumServicesL->sizePolicy().hasHeightForWidth());
        FACNumServicesL->setSizePolicy(sizePolicy);
        FACNumServicesL->setWordWrap(false);

        _14->addWidget(FACNumServicesL);

        FACTimeDateL = new QLabel(FrameFACParams);
        FACTimeDateL->setObjectName(QString::fromUtf8("FACTimeDateL"));
        sizePolicy.setHeightForWidth(FACTimeDateL->sizePolicy().hasHeightForWidth());
        FACTimeDateL->setSizePolicy(sizePolicy);
        FACTimeDateL->setWordWrap(false);

        _14->addWidget(FACTimeDateL);


        _13->addLayout(_14);

        _15 = new QVBoxLayout();
        _15->setSpacing(0);
        _15->setContentsMargins(0, 0, 0, 0);
        _15->setObjectName(QString::fromUtf8("_15"));
        FACDRMModeBWV = new QLabel(FrameFACParams);
        FACDRMModeBWV->setObjectName(QString::fromUtf8("FACDRMModeBWV"));
        sizePolicy.setHeightForWidth(FACDRMModeBWV->sizePolicy().hasHeightForWidth());
        FACDRMModeBWV->setSizePolicy(sizePolicy);
        FACDRMModeBWV->setWordWrap(false);
        FACDRMModeBWV->setIndent(-1);

        _15->addWidget(FACDRMModeBWV);

        FACInterleaverDepthV = new QLabel(FrameFACParams);
        FACInterleaverDepthV->setObjectName(QString::fromUtf8("FACInterleaverDepthV"));
        sizePolicy.setHeightForWidth(FACInterleaverDepthV->sizePolicy().hasHeightForWidth());
        FACInterleaverDepthV->setSizePolicy(sizePolicy);
        FACInterleaverDepthV->setWordWrap(false);

        _15->addWidget(FACInterleaverDepthV);

        FACSDCMSCModeV = new QLabel(FrameFACParams);
        FACSDCMSCModeV->setObjectName(QString::fromUtf8("FACSDCMSCModeV"));
        sizePolicy.setHeightForWidth(FACSDCMSCModeV->sizePolicy().hasHeightForWidth());
        FACSDCMSCModeV->setSizePolicy(sizePolicy);
        FACSDCMSCModeV->setWordWrap(false);

        _15->addWidget(FACSDCMSCModeV);

        FACCodeRateV = new QLabel(FrameFACParams);
        FACCodeRateV->setObjectName(QString::fromUtf8("FACCodeRateV"));
        sizePolicy.setHeightForWidth(FACCodeRateV->sizePolicy().hasHeightForWidth());
        FACCodeRateV->setSizePolicy(sizePolicy);
        FACCodeRateV->setWordWrap(false);

        _15->addWidget(FACCodeRateV);

        FACNumServicesV = new QLabel(FrameFACParams);
        FACNumServicesV->setObjectName(QString::fromUtf8("FACNumServicesV"));
        sizePolicy.setHeightForWidth(FACNumServicesV->sizePolicy().hasHeightForWidth());
        FACNumServicesV->setSizePolicy(sizePolicy);
        FACNumServicesV->setWordWrap(false);

        _15->addWidget(FACNumServicesV);

        FACTimeDateV = new QLabel(FrameFACParams);
        FACTimeDateV->setObjectName(QString::fromUtf8("FACTimeDateV"));
        sizePolicy.setHeightForWidth(FACTimeDateV->sizePolicy().hasHeightForWidth());
        FACTimeDateV->setSizePolicy(sizePolicy);
        FACTimeDateV->setMinimumSize(QSize(200, 0));
        FACTimeDateV->setWordWrap(false);

        _15->addWidget(FACTimeDateV);


        _13->addLayout(_15);


        hboxLayout->addWidget(FrameFACParams);


        verticalLayout->addLayout(hboxLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        chartSelector = new QTreeWidget(centralwidget);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/CSSpectrumInpPSD.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/CSSpectrumInpSpectr.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/CSSpectrumWaterf.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/CSSpectrumShiftedPSD.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/CSSpectrumAudio.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/CSSpectrumSNR.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/CSChannel.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/CSTF.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/CSConstellation.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/CSFAC.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/CSSDC.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/CSMSC.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/CSAudSNRHist.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/CSHistoryDelDopp.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icons/CSHistoryFreqSam.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(chartSelector);
        __qtreewidgetitem->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem1->setIcon(0, icon1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem2->setIcon(0, icon2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem3->setIcon(0, icon3);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem4->setIcon(0, icon4);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem5->setIcon(0, icon5);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem6->setIcon(0, icon6);
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(chartSelector);
        __qtreewidgetitem7->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem8 = new QTreeWidgetItem(__qtreewidgetitem7);
        __qtreewidgetitem8->setIcon(0, icon7);
        QTreeWidgetItem *__qtreewidgetitem9 = new QTreeWidgetItem(__qtreewidgetitem7);
        __qtreewidgetitem9->setIcon(0, icon8);
        QTreeWidgetItem *__qtreewidgetitem10 = new QTreeWidgetItem(chartSelector);
        __qtreewidgetitem10->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem11 = new QTreeWidgetItem(__qtreewidgetitem10);
        __qtreewidgetitem11->setIcon(0, icon9);
        QTreeWidgetItem *__qtreewidgetitem12 = new QTreeWidgetItem(__qtreewidgetitem10);
        __qtreewidgetitem12->setIcon(0, icon10);
        QTreeWidgetItem *__qtreewidgetitem13 = new QTreeWidgetItem(__qtreewidgetitem10);
        __qtreewidgetitem13->setIcon(0, icon11);
        QTreeWidgetItem *__qtreewidgetitem14 = new QTreeWidgetItem(__qtreewidgetitem10);
        __qtreewidgetitem14->setIcon(0, icon12);
        QTreeWidgetItem *__qtreewidgetitem15 = new QTreeWidgetItem(chartSelector);
        __qtreewidgetitem15->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QTreeWidgetItem *__qtreewidgetitem16 = new QTreeWidgetItem(__qtreewidgetitem15);
        __qtreewidgetitem16->setIcon(0, icon13);
        QTreeWidgetItem *__qtreewidgetitem17 = new QTreeWidgetItem(__qtreewidgetitem15);
        __qtreewidgetitem17->setIcon(0, icon14);
        QTreeWidgetItem *__qtreewidgetitem18 = new QTreeWidgetItem(__qtreewidgetitem15);
        __qtreewidgetitem18->setIcon(0, icon15);
        chartSelector->setObjectName(QString::fromUtf8("chartSelector"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(chartSelector->sizePolicy().hasHeightForWidth());
        chartSelector->setSizePolicy(sizePolicy4);
        chartSelector->setIconSize(QSize(16, 16));
        chartSelector->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        chartSelector->setRootIsDecorated(true);

        horizontalLayout->addWidget(chartSelector);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy5);
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        plot = new QwtPlot(frame);
        plot->setObjectName(QString::fromUtf8("plot"));
        sizePolicy.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy);
        plot->setLineWidth(0);

        verticalLayout_2->addWidget(plot);


        horizontalLayout->addWidget(frame);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        _18 = new QVBoxLayout();
        _18->setSpacing(4);
#ifndef Q_OS_MAC
        _18->setContentsMargins(0, 0, 0, 0);
#endif
        _18->setObjectName(QString::fromUtf8("_18"));
        ButtonGroupChanEstFreqInt = new QGroupBox(centralwidget);
        ButtonGroupChanEstFreqInt->setObjectName(QString::fromUtf8("ButtonGroupChanEstFreqInt"));
        sizePolicy.setHeightForWidth(ButtonGroupChanEstFreqInt->sizePolicy().hasHeightForWidth());
        ButtonGroupChanEstFreqInt->setSizePolicy(sizePolicy);
        ButtonGroupChanEstFreqInt->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        _19 = new QHBoxLayout(ButtonGroupChanEstFreqInt);
#ifndef Q_OS_MAC
        _19->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        _19->setContentsMargins(9, 9, 9, 9);
#endif
        _19->setObjectName(QString::fromUtf8("_19"));
        RadioButtonFreqWiener = new QRadioButton(ButtonGroupChanEstFreqInt);
        RadioButtonFreqWiener->setObjectName(QString::fromUtf8("RadioButtonFreqWiener"));
        sizePolicy.setHeightForWidth(RadioButtonFreqWiener->sizePolicy().hasHeightForWidth());
        RadioButtonFreqWiener->setSizePolicy(sizePolicy);

        _19->addWidget(RadioButtonFreqWiener);

        RadioButtonFreqLinear = new QRadioButton(ButtonGroupChanEstFreqInt);
        RadioButtonFreqLinear->setObjectName(QString::fromUtf8("RadioButtonFreqLinear"));
        sizePolicy.setHeightForWidth(RadioButtonFreqLinear->sizePolicy().hasHeightForWidth());
        RadioButtonFreqLinear->setSizePolicy(sizePolicy);

        _19->addWidget(RadioButtonFreqLinear);

        RadioButtonFreqDFT = new QRadioButton(ButtonGroupChanEstFreqInt);
        RadioButtonFreqDFT->setObjectName(QString::fromUtf8("RadioButtonFreqDFT"));
        sizePolicy.setHeightForWidth(RadioButtonFreqDFT->sizePolicy().hasHeightForWidth());
        RadioButtonFreqDFT->setSizePolicy(sizePolicy);

        _19->addWidget(RadioButtonFreqDFT);


        _18->addWidget(ButtonGroupChanEstFreqInt);

        ButtonGroupChanEstTimeInt = new QGroupBox(centralwidget);
        ButtonGroupChanEstTimeInt->setObjectName(QString::fromUtf8("ButtonGroupChanEstTimeInt"));
        sizePolicy.setHeightForWidth(ButtonGroupChanEstTimeInt->sizePolicy().hasHeightForWidth());
        ButtonGroupChanEstTimeInt->setSizePolicy(sizePolicy);
        ButtonGroupChanEstTimeInt->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        _20 = new QHBoxLayout(ButtonGroupChanEstTimeInt);
#ifndef Q_OS_MAC
        _20->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        _20->setContentsMargins(9, 9, 9, 9);
#endif
        _20->setObjectName(QString::fromUtf8("_20"));
        RadioButtonTiWiener = new QRadioButton(ButtonGroupChanEstTimeInt);
        RadioButtonTiWiener->setObjectName(QString::fromUtf8("RadioButtonTiWiener"));
        sizePolicy.setHeightForWidth(RadioButtonTiWiener->sizePolicy().hasHeightForWidth());
        RadioButtonTiWiener->setSizePolicy(sizePolicy);

        _20->addWidget(RadioButtonTiWiener);

        RadioButtonTiLinear = new QRadioButton(ButtonGroupChanEstTimeInt);
        RadioButtonTiLinear->setObjectName(QString::fromUtf8("RadioButtonTiLinear"));
        sizePolicy.setHeightForWidth(RadioButtonTiLinear->sizePolicy().hasHeightForWidth());
        RadioButtonTiLinear->setSizePolicy(sizePolicy);

        _20->addWidget(RadioButtonTiLinear);


        _18->addWidget(ButtonGroupChanEstTimeInt);

        ButtonGroupTimeSyncTrack = new QGroupBox(centralwidget);
        ButtonGroupTimeSyncTrack->setObjectName(QString::fromUtf8("ButtonGroupTimeSyncTrack"));
        sizePolicy.setHeightForWidth(ButtonGroupTimeSyncTrack->sizePolicy().hasHeightForWidth());
        ButtonGroupTimeSyncTrack->setSizePolicy(sizePolicy);
        ButtonGroupTimeSyncTrack->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        _21 = new QHBoxLayout(ButtonGroupTimeSyncTrack);
#ifndef Q_OS_MAC
        _21->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        _21->setContentsMargins(9, 9, 9, 9);
#endif
        _21->setObjectName(QString::fromUtf8("_21"));
        RadioButtonTiSyncEnergy = new QRadioButton(ButtonGroupTimeSyncTrack);
        RadioButtonTiSyncEnergy->setObjectName(QString::fromUtf8("RadioButtonTiSyncEnergy"));
        sizePolicy.setHeightForWidth(RadioButtonTiSyncEnergy->sizePolicy().hasHeightForWidth());
        RadioButtonTiSyncEnergy->setSizePolicy(sizePolicy);

        _21->addWidget(RadioButtonTiSyncEnergy);

        RadioButtonTiSyncFirstPeak = new QRadioButton(ButtonGroupTimeSyncTrack);
        RadioButtonTiSyncFirstPeak->setObjectName(QString::fromUtf8("RadioButtonTiSyncFirstPeak"));
        sizePolicy.setHeightForWidth(RadioButtonTiSyncFirstPeak->sizePolicy().hasHeightForWidth());
        RadioButtonTiSyncFirstPeak->setSizePolicy(sizePolicy);

        _21->addWidget(RadioButtonTiSyncFirstPeak);


        _18->addWidget(ButtonGroupTimeSyncTrack);


        horizontalLayout_2->addLayout(_18);

        _22 = new QVBoxLayout();
#ifndef Q_OS_MAC
        _22->setSpacing(6);
#endif
        _22->setContentsMargins(0, 0, 0, 0);
        _22->setObjectName(QString::fromUtf8("_22"));
        GroupBoxMiscSettings = new QGroupBox(centralwidget);
        GroupBoxMiscSettings->setObjectName(QString::fromUtf8("GroupBoxMiscSettings"));
        sizePolicy.setHeightForWidth(GroupBoxMiscSettings->sizePolicy().hasHeightForWidth());
        GroupBoxMiscSettings->setSizePolicy(sizePolicy);
        GroupBoxMiscSettings->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        _23 = new QHBoxLayout(GroupBoxMiscSettings);
        _23->setSpacing(30);
#ifndef Q_OS_MAC
        _23->setContentsMargins(9, 9, 9, 9);
#endif
        _23->setObjectName(QString::fromUtf8("_23"));
        _24 = new QVBoxLayout();
#ifndef Q_OS_MAC
        _24->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        _24->setContentsMargins(0, 0, 0, 0);
#endif
        _24->setObjectName(QString::fromUtf8("_24"));
        CheckBoxFlipSpec = new QCheckBox(GroupBoxMiscSettings);
        CheckBoxFlipSpec->setObjectName(QString::fromUtf8("CheckBoxFlipSpec"));
        sizePolicy.setHeightForWidth(CheckBoxFlipSpec->sizePolicy().hasHeightForWidth());
        CheckBoxFlipSpec->setSizePolicy(sizePolicy);

        _24->addWidget(CheckBoxFlipSpec);

        CheckBoxWriteLog = new QCheckBox(GroupBoxMiscSettings);
        CheckBoxWriteLog->setObjectName(QString::fromUtf8("CheckBoxWriteLog"));
        sizePolicy.setHeightForWidth(CheckBoxWriteLog->sizePolicy().hasHeightForWidth());
        CheckBoxWriteLog->setSizePolicy(sizePolicy);

        _24->addWidget(CheckBoxWriteLog);


        _23->addLayout(_24);

        _25 = new QVBoxLayout();
#ifndef Q_OS_MAC
        _25->setSpacing(6);
#endif
        _25->setContentsMargins(0, 0, 0, 0);
        _25->setObjectName(QString::fromUtf8("_25"));
        TextNumOfIterations = new QLabel(GroupBoxMiscSettings);
        TextNumOfIterations->setObjectName(QString::fromUtf8("TextNumOfIterations"));
        sizePolicy.setHeightForWidth(TextNumOfIterations->sizePolicy().hasHeightForWidth());
        TextNumOfIterations->setSizePolicy(sizePolicy);
        TextNumOfIterations->setAlignment(Qt::AlignCenter);
        TextNumOfIterations->setWordWrap(false);

        _25->addWidget(TextNumOfIterations);

        SliderNoOfIterations = new QSlider(GroupBoxMiscSettings);
        SliderNoOfIterations->setObjectName(QString::fromUtf8("SliderNoOfIterations"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(SliderNoOfIterations->sizePolicy().hasHeightForWidth());
        SliderNoOfIterations->setSizePolicy(sizePolicy6);
        SliderNoOfIterations->setMinimumSize(QSize(100, 0));
        SliderNoOfIterations->setMaximum(6);
        SliderNoOfIterations->setPageStep(1);
        SliderNoOfIterations->setOrientation(Qt::Horizontal);
        SliderNoOfIterations->setTickPosition(QSlider::TicksBothSides);

        _25->addWidget(SliderNoOfIterations);


        _23->addLayout(_25);


        _22->addWidget(GroupBoxMiscSettings);

        GroupBoxLogFileSaveData = new QGroupBox(centralwidget);
        GroupBoxLogFileSaveData->setObjectName(QString::fromUtf8("GroupBoxLogFileSaveData"));
        sizePolicy.setHeightForWidth(GroupBoxLogFileSaveData->sizePolicy().hasHeightForWidth());
        GroupBoxLogFileSaveData->setSizePolicy(sizePolicy);
        GroupBoxLogFileSaveData->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        verticalLayout_4 = new QVBoxLayout(GroupBoxLogFileSaveData);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        CheckBoxMuteAudio = new QCheckBox(GroupBoxLogFileSaveData);
        CheckBoxMuteAudio->setObjectName(QString::fromUtf8("CheckBoxMuteAudio"));
        sizePolicy.setHeightForWidth(CheckBoxMuteAudio->sizePolicy().hasHeightForWidth());
        CheckBoxMuteAudio->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(CheckBoxMuteAudio);

        CheckBoxReverb = new QCheckBox(GroupBoxLogFileSaveData);
        CheckBoxReverb->setObjectName(QString::fromUtf8("CheckBoxReverb"));
        sizePolicy.setHeightForWidth(CheckBoxReverb->sizePolicy().hasHeightForWidth());
        CheckBoxReverb->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(CheckBoxReverb);


        verticalLayout_4->addLayout(horizontalLayout_3);

        _28 = new QHBoxLayout();
#ifndef Q_OS_MAC
        _28->setSpacing(6);
#endif
        _28->setContentsMargins(0, 0, 0, 0);
        _28->setObjectName(QString::fromUtf8("_28"));
        CheckBoxSaveAudioWave = new QCheckBox(GroupBoxLogFileSaveData);
        CheckBoxSaveAudioWave->setObjectName(QString::fromUtf8("CheckBoxSaveAudioWave"));
        sizePolicy.setHeightForWidth(CheckBoxSaveAudioWave->sizePolicy().hasHeightForWidth());
        CheckBoxSaveAudioWave->setSizePolicy(sizePolicy);

        _28->addWidget(CheckBoxSaveAudioWave);

        horizontalSpacer = new QSpacerItem(13, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _28->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(_28);


        _22->addWidget(GroupBoxLogFileSaveData);


        horizontalLayout_2->addLayout(_22);

        _29 = new QVBoxLayout();
#ifndef Q_OS_MAC
        _29->setSpacing(6);
#endif
        _29->setContentsMargins(0, 0, 0, 0);
        _29->setObjectName(QString::fromUtf8("_29"));
        GroupBoxInterfRej = new QGroupBox(centralwidget);
        GroupBoxInterfRej->setObjectName(QString::fromUtf8("GroupBoxInterfRej"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(GroupBoxInterfRej->sizePolicy().hasHeightForWidth());
        GroupBoxInterfRej->setSizePolicy(sizePolicy7);
        GroupBoxInterfRej->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        _30 = new QHBoxLayout(GroupBoxInterfRej);
#ifndef Q_OS_MAC
        _30->setSpacing(6);
#endif
        _30->setContentsMargins(11, 11, 11, 11);
        _30->setObjectName(QString::fromUtf8("_30"));
        CheckBoxRecFilter = new QCheckBox(GroupBoxInterfRej);
        CheckBoxRecFilter->setObjectName(QString::fromUtf8("CheckBoxRecFilter"));

        _30->addWidget(CheckBoxRecFilter);

        CheckBoxModiMetric = new QCheckBox(GroupBoxInterfRej);
        CheckBoxModiMetric->setObjectName(QString::fromUtf8("CheckBoxModiMetric"));

        _30->addWidget(CheckBoxModiMetric);


        _29->addWidget(GroupBoxInterfRej);

        GroupBoxGPSStatus = new QGroupBox(centralwidget);
        GroupBoxGPSStatus->setObjectName(QString::fromUtf8("GroupBoxGPSStatus"));
        sizePolicy7.setHeightForWidth(GroupBoxGPSStatus->sizePolicy().hasHeightForWidth());
        GroupBoxGPSStatus->setSizePolicy(sizePolicy7);
        _31 = new QVBoxLayout(GroupBoxGPSStatus);
#ifndef Q_OS_MAC
        _31->setSpacing(6);
#endif
        _31->setContentsMargins(11, 11, 11, 11);
        _31->setObjectName(QString::fromUtf8("_31"));
        _32 = new QHBoxLayout();
#ifndef Q_OS_MAC
        _32->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        _32->setContentsMargins(0, 0, 0, 0);
#endif
        _32->setObjectName(QString::fromUtf8("_32"));
        _33 = new QVBoxLayout();
#ifndef Q_OS_MAC
        _33->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        _33->setContentsMargins(0, 0, 0, 0);
#endif
        _33->setObjectName(QString::fromUtf8("_33"));
        TextLabelGPSPosition = new QLabel(GroupBoxGPSStatus);
        TextLabelGPSPosition->setObjectName(QString::fromUtf8("TextLabelGPSPosition"));
        TextLabelGPSPosition->setWordWrap(false);

        _33->addWidget(TextLabelGPSPosition);

        TextLabelGPSTime = new QLabel(GroupBoxGPSStatus);
        TextLabelGPSTime->setObjectName(QString::fromUtf8("TextLabelGPSTime"));
        TextLabelGPSTime->setWordWrap(false);

        _33->addWidget(TextLabelGPSTime);

        TextLabelGPSSpeedHeading = new QLabel(GroupBoxGPSStatus);
        TextLabelGPSSpeedHeading->setObjectName(QString::fromUtf8("TextLabelGPSSpeedHeading"));
        TextLabelGPSSpeedHeading->setWordWrap(false);

        _33->addWidget(TextLabelGPSSpeedHeading);


        _32->addLayout(_33);

        Spacer18 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _32->addItem(Spacer18);

        _34 = new QVBoxLayout();
#ifndef Q_OS_MAC
        _34->setSpacing(6);
#endif
        _34->setContentsMargins(0, 0, 0, 0);
        _34->setObjectName(QString::fromUtf8("_34"));
        Spacer21 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        _34->addItem(Spacer21);

        LEDGPS = new CMultColorLED(GroupBoxGPSStatus);
        LEDGPS->setObjectName(QString::fromUtf8("LEDGPS"));
        LEDGPS->setMinimumSize(QSize(13, 13));
        LEDGPS->setMaximumSize(QSize(13, 13));

        _34->addWidget(LEDGPS);


        _32->addLayout(_34);


        _31->addLayout(_32);


        _29->addWidget(GroupBoxGPSStatus);

        _35 = new QHBoxLayout();
#ifndef Q_OS_MAC
        _35->setSpacing(6);
#endif
        _35->setContentsMargins(0, 0, 0, 0);
        _35->setObjectName(QString::fromUtf8("_35"));
        Spacer3 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _35->addItem(Spacer3);

        buttonOk = new QPushButton(centralwidget);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
        sizePolicy1.setHeightForWidth(buttonOk->sizePolicy().hasHeightForWidth());
        buttonOk->setSizePolicy(sizePolicy1);
        buttonOk->setAutoDefault(true);

        _35->addWidget(buttonOk);


        _29->addLayout(_35);


        horizontalLayout_2->addLayout(_29);


        verticalLayout->addLayout(horizontalLayout_2);

        SystemEvaluationWindow->setCentralWidget(centralwidget);

        retranslateUi(SystemEvaluationWindow);

        buttonOk->setDefault(true);


        QMetaObject::connectSlotsByName(SystemEvaluationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SystemEvaluationWindow)
    {
        SystemEvaluationWindow->setWindowTitle(QCoreApplication::translate("SystemEvaluationWindow", "System Evaluation", nullptr));
        TextSNRText->setText(QCoreApplication::translate("SystemEvaluationWindow", "SNR:", nullptr));
        TextMERWMER->setText(QCoreApplication::translate("SystemEvaluationWindow", "MSC WMER / MSC MER:", nullptr));
        TextFreqOffset->setText(QCoreApplication::translate("SystemEvaluationWindow", "DC Frequency of DRM Signal:", nullptr));
        TextSampFreqOffset->setText(QCoreApplication::translate("SystemEvaluationWindow", "Sample Frequency Offset:", nullptr));
        TextWiener->setText(QCoreApplication::translate("SystemEvaluationWindow", "Doppler / Delay:", nullptr));
        ValueSNR->setText(QCoreApplication::translate("SystemEvaluationWindow", "SNR", nullptr));
        ValueMERWMER->setText(QCoreApplication::translate("SystemEvaluationWindow", "MER", nullptr));
        ValueFreqOffset->setText(QCoreApplication::translate("SystemEvaluationWindow", "FreqOffset", nullptr));
        ValueSampFreqOffset->setText(QCoreApplication::translate("SystemEvaluationWindow", "SampFreqOffset", nullptr));
        ValueWiener->setText(QCoreApplication::translate("SystemEvaluationWindow", "Wiener", nullptr));
        TextLabelLEDMSCCRC->setText(QCoreApplication::translate("SystemEvaluationWindow", "MSC CRC:", nullptr));
        TextLabelLEDSDCCRC->setText(QCoreApplication::translate("SystemEvaluationWindow", "SDC CRC:", nullptr));
        TextLabelLEDFACCRC->setText(QCoreApplication::translate("SystemEvaluationWindow", "FAC CRC:", nullptr));
        TextLabelLEDFrameSync->setText(QCoreApplication::translate("SystemEvaluationWindow", "Frame Sync:", nullptr));
        TextLabelLEDTimeSyncAcq->setText(QCoreApplication::translate("SystemEvaluationWindow", "Time Sync Acq:", nullptr));
        TextLabelLEDIOInterface->setText(QCoreApplication::translate("SystemEvaluationWindow", "I/O Interface:", nullptr));
        FACDRMModeBWL->setText(QCoreApplication::translate("SystemEvaluationWindow", "DRM Mode / Bandwidth:", nullptr));
        FACInterleaverDepthL->setText(QCoreApplication::translate("SystemEvaluationWindow", "Interleaver Depth:", nullptr));
        FACSDCMSCModeL->setText(QCoreApplication::translate("SystemEvaluationWindow", "SDC / MSC Mode:", nullptr));
        FACCodeRateL->setText(QCoreApplication::translate("SystemEvaluationWindow", "Prot. Level (B / A):", nullptr));
        FACNumServicesL->setText(QCoreApplication::translate("SystemEvaluationWindow", "Number of Services:", nullptr));
        FACTimeDateL->setText(QCoreApplication::translate("SystemEvaluationWindow", "Received time - date:", nullptr));
        FACDRMModeBWV->setText(QCoreApplication::translate("SystemEvaluationWindow", "FACDRMModeBWV", nullptr));
        FACInterleaverDepthV->setText(QCoreApplication::translate("SystemEvaluationWindow", "FACInterleaverDepthV", nullptr));
        FACSDCMSCModeV->setText(QCoreApplication::translate("SystemEvaluationWindow", "FACSDCMSCModeV", nullptr));
        FACCodeRateV->setText(QCoreApplication::translate("SystemEvaluationWindow", "FACCodeRateV", nullptr));
        FACNumServicesV->setText(QCoreApplication::translate("SystemEvaluationWindow", "FACNumServicesV", nullptr));
        FACTimeDateV->setText(QCoreApplication::translate("SystemEvaluationWindow", "FACTimeDateV", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = chartSelector->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "Chart Selector", nullptr));

        const bool __sortingEnabled = chartSelector->isSortingEnabled();
        chartSelector->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = chartSelector->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "Spectrum", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "Input PSD", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "Input Spectrum", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "Waterfall Input Spectrum", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem1->child(3);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "Shifted PSD", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem1->child(4);
        ___qtreewidgetitem6->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "Audio Spectrum", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem1->child(5);
        ___qtreewidgetitem7->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "SNR Spectrum", nullptr));
        QTreeWidgetItem *___qtreewidgetitem8 = chartSelector->topLevelItem(1);
        ___qtreewidgetitem8->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "Channel", nullptr));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem8->child(0);
        ___qtreewidgetitem9->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "Impulse Response", nullptr));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem8->child(1);
        ___qtreewidgetitem10->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "Transfer Function", nullptr));
        QTreeWidgetItem *___qtreewidgetitem11 = chartSelector->topLevelItem(2);
        ___qtreewidgetitem11->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "Constellation", nullptr));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem11->child(0);
        ___qtreewidgetitem12->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "FAC / SDC / MSC", nullptr));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem11->child(1);
        ___qtreewidgetitem13->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "FAC", nullptr));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem11->child(2);
        ___qtreewidgetitem14->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "SDC", nullptr));
        QTreeWidgetItem *___qtreewidgetitem15 = ___qtreewidgetitem11->child(3);
        ___qtreewidgetitem15->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "MSC", nullptr));
        QTreeWidgetItem *___qtreewidgetitem16 = chartSelector->topLevelItem(3);
        ___qtreewidgetitem16->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "History", nullptr));
        QTreeWidgetItem *___qtreewidgetitem17 = ___qtreewidgetitem16->child(0);
        ___qtreewidgetitem17->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "SNR / Audio", nullptr));
        QTreeWidgetItem *___qtreewidgetitem18 = ___qtreewidgetitem16->child(1);
        ___qtreewidgetitem18->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "Delay / Doppler", nullptr));
        QTreeWidgetItem *___qtreewidgetitem19 = ___qtreewidgetitem16->child(2);
        ___qtreewidgetitem19->setText(0, QCoreApplication::translate("SystemEvaluationWindow", "Frequency / Sample Rate", nullptr));
        chartSelector->setSortingEnabled(__sortingEnabled);

        ButtonGroupChanEstFreqInt->setTitle(QCoreApplication::translate("SystemEvaluationWindow", "Channel Estimation: Frequency Interpolation", nullptr));
        RadioButtonFreqWiener->setText(QCoreApplication::translate("SystemEvaluationWindow", "Wiener", nullptr));
        RadioButtonFreqLinear->setText(QCoreApplication::translate("SystemEvaluationWindow", "Linear", nullptr));
        RadioButtonFreqDFT->setText(QCoreApplication::translate("SystemEvaluationWindow", "DFT Zero Pad.", nullptr));
        ButtonGroupChanEstTimeInt->setTitle(QCoreApplication::translate("SystemEvaluationWindow", "Channel Estimation: Time Interpolation", nullptr));
        RadioButtonTiWiener->setText(QCoreApplication::translate("SystemEvaluationWindow", "Wiener", nullptr));
        RadioButtonTiLinear->setText(QCoreApplication::translate("SystemEvaluationWindow", "Linear", nullptr));
        ButtonGroupTimeSyncTrack->setTitle(QCoreApplication::translate("SystemEvaluationWindow", "Time Sync Tracking", nullptr));
        RadioButtonTiSyncEnergy->setText(QCoreApplication::translate("SystemEvaluationWindow", "Guard Energy", nullptr));
        RadioButtonTiSyncFirstPeak->setText(QCoreApplication::translate("SystemEvaluationWindow", "First Peak", nullptr));
        GroupBoxMiscSettings->setTitle(QCoreApplication::translate("SystemEvaluationWindow", "Misc Settings", nullptr));
        CheckBoxFlipSpec->setText(QCoreApplication::translate("SystemEvaluationWindow", "&Flip Input Spectrum", nullptr));
        CheckBoxWriteLog->setText(QCoreApplication::translate("SystemEvaluationWindow", "&Log to file", nullptr));
        TextNumOfIterations->setText(QCoreApplication::translate("SystemEvaluationWindow", "TextNumOfIterations", nullptr));
        GroupBoxLogFileSaveData->setTitle(QCoreApplication::translate("SystemEvaluationWindow", "Audio", nullptr));
        CheckBoxMuteAudio->setText(QCoreApplication::translate("SystemEvaluationWindow", "Mute &Audio", nullptr));
        CheckBoxReverb->setText(QCoreApplication::translate("SystemEvaluationWindow", "&Reverberation", nullptr));
        CheckBoxSaveAudioWave->setText(QCoreApplication::translate("SystemEvaluationWindow", "&Save Audio as WAV", nullptr));
        GroupBoxInterfRej->setTitle(QCoreApplication::translate("SystemEvaluationWindow", "Interferer Rejection", nullptr));
        CheckBoxRecFilter->setText(QCoreApplication::translate("SystemEvaluationWindow", "&Bandpass Filter", nullptr));
        CheckBoxModiMetric->setText(QCoreApplication::translate("SystemEvaluationWindow", "Modified &Metrics", nullptr));
        GroupBoxGPSStatus->setTitle(QCoreApplication::translate("SystemEvaluationWindow", "GPS", nullptr));
        TextLabelGPSPosition->setText(QCoreApplication::translate("SystemEvaluationWindow", "Lat: 53.123\302\260   Long: 00.456\302\260", nullptr));
        TextLabelGPSTime->setText(QCoreApplication::translate("SystemEvaluationWindow", "24/01/2007 15:14.33 UTC", nullptr));
        TextLabelGPSSpeedHeading->setText(QCoreApplication::translate("SystemEvaluationWindow", "10.0 m/s  151\302\260", nullptr));
        buttonOk->setWindowTitle(QString());
        buttonOk->setText(QCoreApplication::translate("SystemEvaluationWindow", "&Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemEvaluationWindow: public Ui_SystemEvaluationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMEVALDLGBASE_H
