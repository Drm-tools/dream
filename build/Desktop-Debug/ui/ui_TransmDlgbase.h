/********************************************************************************
** Form generated from reading UI file 'TransmDlgbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSMDLGBASE_H
#define UI_TRANSMDLGBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qwt_thermo.h"

QT_BEGIN_NAMESPACE

class Ui_TransmDlgBase
{
public:
    QAction *actionWhats_This;
    QAction *actionAbout_Dream;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *hboxLayout;
    QLabel *PixmapLabelDreamLogo;
    QVBoxLayout *vboxLayout;
    QLabel *TextLabelMainAuthors;
    QLabel *TextLabelCompany;
    QSpacerItem *Spacer4;
    QGroupBox *GroupInput;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout1;
    QLabel *TextLabelAudioLevel;
    QwtThermo *ProgrInputLevel;
    QSpacerItem *verticalSpacer;
    QLabel *TextLabelCurPict;
    QProgressBar *ProgressBarCurPict;
    QSpacerItem *Spacer6;
    QTabWidget *TabWidgetParam;
    QWidget *tabChannelParameters;
    QVBoxLayout *verticalLayout;
    QGroupBox *GroupBoxRobustnessMode;
    QHBoxLayout *hboxLayout2;
    QRadioButton *RadioButtonRMA;
    QRadioButton *RadioButtonRMB;
    QRadioButton *RadioButtonRMC;
    QRadioButton *RadioButtonRMD;
    QGroupBox *GroupBoxBandwidth;
    QVBoxLayout *vboxLayout2;
    QHBoxLayout *hboxLayout3;
    QRadioButton *RadioButtonBandwidth45;
    QRadioButton *RadioButtonBandwidth9;
    QRadioButton *RadioButtonBandwidth18;
    QHBoxLayout *hboxLayout4;
    QRadioButton *RadioButtonBandwidth5;
    QRadioButton *RadioButtonBandwidth10;
    QRadioButton *RadioButtonBandwidth20;
    QHBoxLayout *hboxLayout5;
    QHBoxLayout *hboxLayout6;
    QLabel *TextLabelMSCConst;
    QComboBox *ComboBoxMSCConstellation;
    QHBoxLayout *hboxLayout7;
    QLabel *TextLabelProtLev;
    QComboBox *ComboBoxMSCProtLev;
    QHBoxLayout *hboxLayout8;
    QHBoxLayout *hboxLayout9;
    QLabel *TextLabelSDCConst;
    QComboBox *ComboBoxSDCConstellation;
    QHBoxLayout *hboxLayout10;
    QLabel *TextLabelInterleaver;
    QComboBox *ComboBoxMSCInterleaver;
    QWidget *tabOutput;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *ButtonGroupIF;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *LineEditSndCrdIF;
    QLabel *TextLabelIFUnit;
    QGroupBox *GroupBoxOutput;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *RadioButtonOutReal;
    QRadioButton *RadioButtonOutIQPos;
    QRadioButton *RadioButtonOutIQNeg;
    QRadioButton *RadioButtonOutEP;
    QGroupBox *GroupBoxOutputOption;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *CheckBoxAmplifiedOutput;
    QCheckBox *CheckBoxHighQualityIQ;
    QSpacerItem *verticalSpacer_3;
    QWidget *tabMiscellaneous;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *GroupBoxCurrentTime;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *RadioButtonCurTimeOff;
    QRadioButton *RadioButtonCurTimeLocal;
    QRadioButton *RadioButtonCurTimeUTC;
    QRadioButton *RadioButtonCurTimeUTCOffset;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *ButtonStartStop;
    QPushButton *ButtonCodec;
    QPushButton *ButtonClose;
    QTabWidget *TabWidgetServices;
    QWidget *tabService1;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *CheckBoxEnableService;
    QVBoxLayout *vboxLayout3;
    QHBoxLayout *hboxLayout11;
    QLabel *TextLabelServiceLabel;
    QLineEdit *LineEditServiceLabel;
    QHBoxLayout *hboxLayout12;
    QLabel *TextLabelServiceID;
    QLineEdit *LineEditServiceID;
    QHBoxLayout *hboxLayout13;
    QLabel *TextLabelServiceLanguage;
    QComboBox *ComboBoxLanguage;
    QSpacerItem *Spacer3;
    QGroupBox *GroupBoxAudio;
    QVBoxLayout *vboxLayout4;
    QCheckBox *CheckBoxEnableAudio;
    QHBoxLayout *hboxLayout14;
    QLabel *TextLabelProgramType;
    QComboBox *ComboBoxProgramType;
    QGroupBox *GroupBoxCodec;
    QHBoxLayout *hboxLayout15;
    QRadioButton *RadioButtonAAC;
    QRadioButton *RadioButtonOPUS;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *GroupBoxTextMessage;
    QVBoxLayout *vboxLayout5;
    QCheckBox *CheckBoxEnableTextMessage;
    QComboBox *ComboBoxTextMessage;
    QTextEdit *MultiLineEditTextMessage;
    QHBoxLayout *hboxLayout16;
    QPushButton *PushButtonClearAllText;
    QSpacerItem *Spacer2;
    QPushButton *PushButtonAddText;
    QGroupBox *GroupBoxData;
    QVBoxLayout *vboxLayout6;
    QCheckBox *CheckBoxEnableData;
    QCheckBox *CheckBoxRemovePath;
    QTreeWidget *TreeWidgetFileNames;
    QHBoxLayout *hboxLayout17;
    QPushButton *PushButtonClearAllFileNames;
    QSpacerItem *Spacer2_2;
    QPushButton *PushButtonAddFile;
    QWidget *tabService2;
    QWidget *tabService3;
    QWidget *tabService4;
    QMenuBar *menubar;
    QMenu *menu_Settings;
    QMenu *menuHelp;
    QButtonGroup *ButtonGroupBandwidth;
    QButtonGroup *ButtonGroupCodec;
    QButtonGroup *ButtonGroupCurrentTime;
    QButtonGroup *ButtonGroupOutput;
    QButtonGroup *ButtonGroupRobustnessMode;

    void setupUi(QMainWindow *TransmDlgBase)
    {
        if (TransmDlgBase->objectName().isEmpty())
            TransmDlgBase->setObjectName(QString::fromUtf8("TransmDlgBase"));
        TransmDlgBase->resize(967, 803);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/MainIconTx.svg"), QSize(), QIcon::Normal, QIcon::Off);
        TransmDlgBase->setWindowIcon(icon);
        actionWhats_This = new QAction(TransmDlgBase);
        actionWhats_This->setObjectName(QString::fromUtf8("actionWhats_This"));
        actionAbout_Dream = new QAction(TransmDlgBase);
        actionAbout_Dream->setObjectName(QString::fromUtf8("actionAbout_Dream"));
        centralwidget = new QWidget(TransmDlgBase);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        PixmapLabelDreamLogo = new QLabel(centralwidget);
        PixmapLabelDreamLogo->setObjectName(QString::fromUtf8("PixmapLabelDreamLogo"));
        PixmapLabelDreamLogo->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PixmapLabelDreamLogo->sizePolicy().hasHeightForWidth());
        PixmapLabelDreamLogo->setSizePolicy(sizePolicy);
        PixmapLabelDreamLogo->setPixmap(QPixmap(QString::fromUtf8(":/icons/LogoSmall.png")));
        PixmapLabelDreamLogo->setScaledContents(false);
        PixmapLabelDreamLogo->setWordWrap(false);

        hboxLayout->addWidget(PixmapLabelDreamLogo);

        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        TextLabelMainAuthors = new QLabel(centralwidget);
        TextLabelMainAuthors->setObjectName(QString::fromUtf8("TextLabelMainAuthors"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TextLabelMainAuthors->sizePolicy().hasHeightForWidth());
        TextLabelMainAuthors->setSizePolicy(sizePolicy1);
        TextLabelMainAuthors->setWordWrap(false);

        vboxLayout->addWidget(TextLabelMainAuthors);

        TextLabelCompany = new QLabel(centralwidget);
        TextLabelCompany->setObjectName(QString::fromUtf8("TextLabelCompany"));
        sizePolicy1.setHeightForWidth(TextLabelCompany->sizePolicy().hasHeightForWidth());
        TextLabelCompany->setSizePolicy(sizePolicy1);
        TextLabelCompany->setWordWrap(false);

        vboxLayout->addWidget(TextLabelCompany);


        hboxLayout->addLayout(vboxLayout);


        verticalLayout_2->addLayout(hboxLayout);

        Spacer4 = new QSpacerItem(20, 24, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_2->addItem(Spacer4);

        GroupInput = new QGroupBox(centralwidget);
        GroupInput->setObjectName(QString::fromUtf8("GroupInput"));
        vboxLayout1 = new QVBoxLayout(GroupInput);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        vboxLayout1->setContentsMargins(11, 11, 11, 11);
        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        TextLabelAudioLevel = new QLabel(GroupInput);
        TextLabelAudioLevel->setObjectName(QString::fromUtf8("TextLabelAudioLevel"));
        TextLabelAudioLevel->setWordWrap(false);

        hboxLayout1->addWidget(TextLabelAudioLevel);

        ProgrInputLevel = new QwtThermo(GroupInput);
        ProgrInputLevel->setObjectName(QString::fromUtf8("ProgrInputLevel"));

        hboxLayout1->addWidget(ProgrInputLevel);


        vboxLayout1->addLayout(hboxLayout1);

        verticalSpacer = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout1->addItem(verticalSpacer);

        TextLabelCurPict = new QLabel(GroupInput);
        TextLabelCurPict->setObjectName(QString::fromUtf8("TextLabelCurPict"));
        TextLabelCurPict->setWordWrap(false);

        vboxLayout1->addWidget(TextLabelCurPict);

        ProgressBarCurPict = new QProgressBar(GroupInput);
        ProgressBarCurPict->setObjectName(QString::fromUtf8("ProgressBarCurPict"));

        vboxLayout1->addWidget(ProgressBarCurPict);


        verticalLayout_2->addWidget(GroupInput);


        horizontalLayout->addLayout(verticalLayout_2);

        Spacer6 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(Spacer6);

        TabWidgetParam = new QTabWidget(centralwidget);
        TabWidgetParam->setObjectName(QString::fromUtf8("TabWidgetParam"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(TabWidgetParam->sizePolicy().hasHeightForWidth());
        TabWidgetParam->setSizePolicy(sizePolicy2);
        tabChannelParameters = new QWidget();
        tabChannelParameters->setObjectName(QString::fromUtf8("tabChannelParameters"));
        verticalLayout = new QVBoxLayout(tabChannelParameters);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        GroupBoxRobustnessMode = new QGroupBox(tabChannelParameters);
        GroupBoxRobustnessMode->setObjectName(QString::fromUtf8("GroupBoxRobustnessMode"));
        GroupBoxRobustnessMode->setProperty("radioButtonExclusive", QVariant(true));
        hboxLayout2 = new QHBoxLayout(GroupBoxRobustnessMode);
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        hboxLayout2->setContentsMargins(11, 11, 11, 11);
        RadioButtonRMA = new QRadioButton(GroupBoxRobustnessMode);
        ButtonGroupRobustnessMode = new QButtonGroup(TransmDlgBase);
        ButtonGroupRobustnessMode->setObjectName(QString::fromUtf8("ButtonGroupRobustnessMode"));
        ButtonGroupRobustnessMode->addButton(RadioButtonRMA);
        RadioButtonRMA->setObjectName(QString::fromUtf8("RadioButtonRMA"));

        hboxLayout2->addWidget(RadioButtonRMA);

        RadioButtonRMB = new QRadioButton(GroupBoxRobustnessMode);
        ButtonGroupRobustnessMode->addButton(RadioButtonRMB);
        RadioButtonRMB->setObjectName(QString::fromUtf8("RadioButtonRMB"));

        hboxLayout2->addWidget(RadioButtonRMB);

        RadioButtonRMC = new QRadioButton(GroupBoxRobustnessMode);
        ButtonGroupRobustnessMode->addButton(RadioButtonRMC);
        RadioButtonRMC->setObjectName(QString::fromUtf8("RadioButtonRMC"));

        hboxLayout2->addWidget(RadioButtonRMC);

        RadioButtonRMD = new QRadioButton(GroupBoxRobustnessMode);
        ButtonGroupRobustnessMode->addButton(RadioButtonRMD);
        RadioButtonRMD->setObjectName(QString::fromUtf8("RadioButtonRMD"));

        hboxLayout2->addWidget(RadioButtonRMD);


        verticalLayout->addWidget(GroupBoxRobustnessMode);

        GroupBoxBandwidth = new QGroupBox(tabChannelParameters);
        GroupBoxBandwidth->setObjectName(QString::fromUtf8("GroupBoxBandwidth"));
        GroupBoxBandwidth->setProperty("radioButtonExclusive", QVariant(true));
        vboxLayout2 = new QVBoxLayout(GroupBoxBandwidth);
        vboxLayout2->setSpacing(6);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        vboxLayout2->setContentsMargins(11, 11, 11, 11);
        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        RadioButtonBandwidth45 = new QRadioButton(GroupBoxBandwidth);
        ButtonGroupBandwidth = new QButtonGroup(TransmDlgBase);
        ButtonGroupBandwidth->setObjectName(QString::fromUtf8("ButtonGroupBandwidth"));
        ButtonGroupBandwidth->addButton(RadioButtonBandwidth45);
        RadioButtonBandwidth45->setObjectName(QString::fromUtf8("RadioButtonBandwidth45"));

        hboxLayout3->addWidget(RadioButtonBandwidth45);

        RadioButtonBandwidth9 = new QRadioButton(GroupBoxBandwidth);
        ButtonGroupBandwidth->addButton(RadioButtonBandwidth9);
        RadioButtonBandwidth9->setObjectName(QString::fromUtf8("RadioButtonBandwidth9"));

        hboxLayout3->addWidget(RadioButtonBandwidth9);

        RadioButtonBandwidth18 = new QRadioButton(GroupBoxBandwidth);
        ButtonGroupBandwidth->addButton(RadioButtonBandwidth18);
        RadioButtonBandwidth18->setObjectName(QString::fromUtf8("RadioButtonBandwidth18"));

        hboxLayout3->addWidget(RadioButtonBandwidth18);


        vboxLayout2->addLayout(hboxLayout3);

        hboxLayout4 = new QHBoxLayout();
        hboxLayout4->setSpacing(6);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        RadioButtonBandwidth5 = new QRadioButton(GroupBoxBandwidth);
        ButtonGroupBandwidth->addButton(RadioButtonBandwidth5);
        RadioButtonBandwidth5->setObjectName(QString::fromUtf8("RadioButtonBandwidth5"));

        hboxLayout4->addWidget(RadioButtonBandwidth5);

        RadioButtonBandwidth10 = new QRadioButton(GroupBoxBandwidth);
        ButtonGroupBandwidth->addButton(RadioButtonBandwidth10);
        RadioButtonBandwidth10->setObjectName(QString::fromUtf8("RadioButtonBandwidth10"));

        hboxLayout4->addWidget(RadioButtonBandwidth10);

        RadioButtonBandwidth20 = new QRadioButton(GroupBoxBandwidth);
        ButtonGroupBandwidth->addButton(RadioButtonBandwidth20);
        RadioButtonBandwidth20->setObjectName(QString::fromUtf8("RadioButtonBandwidth20"));

        hboxLayout4->addWidget(RadioButtonBandwidth20);


        vboxLayout2->addLayout(hboxLayout4);


        verticalLayout->addWidget(GroupBoxBandwidth);

        hboxLayout5 = new QHBoxLayout();
        hboxLayout5->setSpacing(6);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        hboxLayout5->setContentsMargins(0, 0, 0, 0);
        hboxLayout6 = new QHBoxLayout();
        hboxLayout6->setSpacing(6);
        hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
        hboxLayout6->setContentsMargins(0, 0, 0, 0);
        TextLabelMSCConst = new QLabel(tabChannelParameters);
        TextLabelMSCConst->setObjectName(QString::fromUtf8("TextLabelMSCConst"));
        TextLabelMSCConst->setWordWrap(false);

        hboxLayout6->addWidget(TextLabelMSCConst);

        ComboBoxMSCConstellation = new QComboBox(tabChannelParameters);
        ComboBoxMSCConstellation->setObjectName(QString::fromUtf8("ComboBoxMSCConstellation"));

        hboxLayout6->addWidget(ComboBoxMSCConstellation);


        hboxLayout5->addLayout(hboxLayout6);

        hboxLayout7 = new QHBoxLayout();
        hboxLayout7->setSpacing(6);
        hboxLayout7->setObjectName(QString::fromUtf8("hboxLayout7"));
        hboxLayout7->setContentsMargins(0, 0, 0, 0);
        TextLabelProtLev = new QLabel(tabChannelParameters);
        TextLabelProtLev->setObjectName(QString::fromUtf8("TextLabelProtLev"));
        TextLabelProtLev->setWordWrap(false);

        hboxLayout7->addWidget(TextLabelProtLev);

        ComboBoxMSCProtLev = new QComboBox(tabChannelParameters);
        ComboBoxMSCProtLev->setObjectName(QString::fromUtf8("ComboBoxMSCProtLev"));

        hboxLayout7->addWidget(ComboBoxMSCProtLev);


        hboxLayout5->addLayout(hboxLayout7);


        verticalLayout->addLayout(hboxLayout5);

        hboxLayout8 = new QHBoxLayout();
        hboxLayout8->setSpacing(6);
        hboxLayout8->setObjectName(QString::fromUtf8("hboxLayout8"));
        hboxLayout8->setContentsMargins(0, 0, 0, 0);
        hboxLayout9 = new QHBoxLayout();
        hboxLayout9->setSpacing(6);
        hboxLayout9->setObjectName(QString::fromUtf8("hboxLayout9"));
        hboxLayout9->setContentsMargins(0, 0, 0, 0);
        TextLabelSDCConst = new QLabel(tabChannelParameters);
        TextLabelSDCConst->setObjectName(QString::fromUtf8("TextLabelSDCConst"));
        TextLabelSDCConst->setWordWrap(false);

        hboxLayout9->addWidget(TextLabelSDCConst);

        ComboBoxSDCConstellation = new QComboBox(tabChannelParameters);
        ComboBoxSDCConstellation->setObjectName(QString::fromUtf8("ComboBoxSDCConstellation"));

        hboxLayout9->addWidget(ComboBoxSDCConstellation);


        hboxLayout8->addLayout(hboxLayout9);

        hboxLayout10 = new QHBoxLayout();
        hboxLayout10->setSpacing(6);
        hboxLayout10->setObjectName(QString::fromUtf8("hboxLayout10"));
        hboxLayout10->setContentsMargins(0, 0, 0, 0);
        TextLabelInterleaver = new QLabel(tabChannelParameters);
        TextLabelInterleaver->setObjectName(QString::fromUtf8("TextLabelInterleaver"));
        TextLabelInterleaver->setWordWrap(false);

        hboxLayout10->addWidget(TextLabelInterleaver);

        ComboBoxMSCInterleaver = new QComboBox(tabChannelParameters);
        ComboBoxMSCInterleaver->setObjectName(QString::fromUtf8("ComboBoxMSCInterleaver"));

        hboxLayout10->addWidget(ComboBoxMSCInterleaver);


        hboxLayout8->addLayout(hboxLayout10);


        verticalLayout->addLayout(hboxLayout8);

        TabWidgetParam->addTab(tabChannelParameters, QString());
        tabOutput = new QWidget();
        tabOutput->setObjectName(QString::fromUtf8("tabOutput"));
        verticalLayout_3 = new QVBoxLayout(tabOutput);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        ButtonGroupIF = new QGroupBox(tabOutput);
        ButtonGroupIF->setObjectName(QString::fromUtf8("ButtonGroupIF"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ButtonGroupIF->sizePolicy().hasHeightForWidth());
        ButtonGroupIF->setSizePolicy(sizePolicy3);
        horizontalLayout_2 = new QHBoxLayout(ButtonGroupIF);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        LineEditSndCrdIF = new QLineEdit(ButtonGroupIF);
        LineEditSndCrdIF->setObjectName(QString::fromUtf8("LineEditSndCrdIF"));
        sizePolicy3.setHeightForWidth(LineEditSndCrdIF->sizePolicy().hasHeightForWidth());
        LineEditSndCrdIF->setSizePolicy(sizePolicy3);
        LineEditSndCrdIF->setMinimumSize(QSize(90, 0));
        LineEditSndCrdIF->setMaxLength(24);

        horizontalLayout_2->addWidget(LineEditSndCrdIF);

        TextLabelIFUnit = new QLabel(ButtonGroupIF);
        TextLabelIFUnit->setObjectName(QString::fromUtf8("TextLabelIFUnit"));
        sizePolicy3.setHeightForWidth(TextLabelIFUnit->sizePolicy().hasHeightForWidth());
        TextLabelIFUnit->setSizePolicy(sizePolicy3);
        TextLabelIFUnit->setWordWrap(false);
        TextLabelIFUnit->setIndent(-1);

        horizontalLayout_2->addWidget(TextLabelIFUnit);


        verticalLayout_3->addWidget(ButtonGroupIF);

        GroupBoxOutput = new QGroupBox(tabOutput);
        GroupBoxOutput->setObjectName(QString::fromUtf8("GroupBoxOutput"));
        sizePolicy3.setHeightForWidth(GroupBoxOutput->sizePolicy().hasHeightForWidth());
        GroupBoxOutput->setSizePolicy(sizePolicy3);
        GroupBoxOutput->setProperty("radioButtonExclusive", QVariant(true));
        verticalLayout_7 = new QVBoxLayout(GroupBoxOutput);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        RadioButtonOutReal = new QRadioButton(GroupBoxOutput);
        ButtonGroupOutput = new QButtonGroup(TransmDlgBase);
        ButtonGroupOutput->setObjectName(QString::fromUtf8("ButtonGroupOutput"));
        ButtonGroupOutput->addButton(RadioButtonOutReal);
        RadioButtonOutReal->setObjectName(QString::fromUtf8("RadioButtonOutReal"));
        sizePolicy3.setHeightForWidth(RadioButtonOutReal->sizePolicy().hasHeightForWidth());
        RadioButtonOutReal->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(RadioButtonOutReal);

        RadioButtonOutIQPos = new QRadioButton(GroupBoxOutput);
        ButtonGroupOutput->addButton(RadioButtonOutIQPos);
        RadioButtonOutIQPos->setObjectName(QString::fromUtf8("RadioButtonOutIQPos"));
        sizePolicy3.setHeightForWidth(RadioButtonOutIQPos->sizePolicy().hasHeightForWidth());
        RadioButtonOutIQPos->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(RadioButtonOutIQPos);

        RadioButtonOutIQNeg = new QRadioButton(GroupBoxOutput);
        ButtonGroupOutput->addButton(RadioButtonOutIQNeg);
        RadioButtonOutIQNeg->setObjectName(QString::fromUtf8("RadioButtonOutIQNeg"));
        sizePolicy3.setHeightForWidth(RadioButtonOutIQNeg->sizePolicy().hasHeightForWidth());
        RadioButtonOutIQNeg->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(RadioButtonOutIQNeg);

        RadioButtonOutEP = new QRadioButton(GroupBoxOutput);
        ButtonGroupOutput->addButton(RadioButtonOutEP);
        RadioButtonOutEP->setObjectName(QString::fromUtf8("RadioButtonOutEP"));
        sizePolicy3.setHeightForWidth(RadioButtonOutEP->sizePolicy().hasHeightForWidth());
        RadioButtonOutEP->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(RadioButtonOutEP);


        verticalLayout_7->addLayout(horizontalLayout_3);


        verticalLayout_3->addWidget(GroupBoxOutput);

        GroupBoxOutputOption = new QGroupBox(tabOutput);
        GroupBoxOutputOption->setObjectName(QString::fromUtf8("GroupBoxOutputOption"));
        sizePolicy3.setHeightForWidth(GroupBoxOutputOption->sizePolicy().hasHeightForWidth());
        GroupBoxOutputOption->setSizePolicy(sizePolicy3);
        horizontalLayout_7 = new QHBoxLayout(GroupBoxOutputOption);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        CheckBoxAmplifiedOutput = new QCheckBox(GroupBoxOutputOption);
        CheckBoxAmplifiedOutput->setObjectName(QString::fromUtf8("CheckBoxAmplifiedOutput"));
        sizePolicy3.setHeightForWidth(CheckBoxAmplifiedOutput->sizePolicy().hasHeightForWidth());
        CheckBoxAmplifiedOutput->setSizePolicy(sizePolicy3);

        horizontalLayout_7->addWidget(CheckBoxAmplifiedOutput);

        CheckBoxHighQualityIQ = new QCheckBox(GroupBoxOutputOption);
        CheckBoxHighQualityIQ->setObjectName(QString::fromUtf8("CheckBoxHighQualityIQ"));
        sizePolicy3.setHeightForWidth(CheckBoxHighQualityIQ->sizePolicy().hasHeightForWidth());
        CheckBoxHighQualityIQ->setSizePolicy(sizePolicy3);

        horizontalLayout_7->addWidget(CheckBoxHighQualityIQ);


        verticalLayout_3->addWidget(GroupBoxOutputOption);

        verticalSpacer_3 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        TabWidgetParam->addTab(tabOutput, QString());
        tabMiscellaneous = new QWidget();
        tabMiscellaneous->setObjectName(QString::fromUtf8("tabMiscellaneous"));
        verticalLayout_4 = new QVBoxLayout(tabMiscellaneous);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        GroupBoxCurrentTime = new QGroupBox(tabMiscellaneous);
        GroupBoxCurrentTime->setObjectName(QString::fromUtf8("GroupBoxCurrentTime"));
        sizePolicy3.setHeightForWidth(GroupBoxCurrentTime->sizePolicy().hasHeightForWidth());
        GroupBoxCurrentTime->setSizePolicy(sizePolicy3);
        horizontalLayout_4 = new QHBoxLayout(GroupBoxCurrentTime);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        RadioButtonCurTimeOff = new QRadioButton(GroupBoxCurrentTime);
        ButtonGroupCurrentTime = new QButtonGroup(TransmDlgBase);
        ButtonGroupCurrentTime->setObjectName(QString::fromUtf8("ButtonGroupCurrentTime"));
        ButtonGroupCurrentTime->addButton(RadioButtonCurTimeOff);
        RadioButtonCurTimeOff->setObjectName(QString::fromUtf8("RadioButtonCurTimeOff"));
        sizePolicy3.setHeightForWidth(RadioButtonCurTimeOff->sizePolicy().hasHeightForWidth());
        RadioButtonCurTimeOff->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(RadioButtonCurTimeOff);

        RadioButtonCurTimeLocal = new QRadioButton(GroupBoxCurrentTime);
        ButtonGroupCurrentTime->addButton(RadioButtonCurTimeLocal);
        RadioButtonCurTimeLocal->setObjectName(QString::fromUtf8("RadioButtonCurTimeLocal"));
        sizePolicy3.setHeightForWidth(RadioButtonCurTimeLocal->sizePolicy().hasHeightForWidth());
        RadioButtonCurTimeLocal->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(RadioButtonCurTimeLocal);

        RadioButtonCurTimeUTC = new QRadioButton(GroupBoxCurrentTime);
        ButtonGroupCurrentTime->addButton(RadioButtonCurTimeUTC);
        RadioButtonCurTimeUTC->setObjectName(QString::fromUtf8("RadioButtonCurTimeUTC"));
        sizePolicy3.setHeightForWidth(RadioButtonCurTimeUTC->sizePolicy().hasHeightForWidth());
        RadioButtonCurTimeUTC->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(RadioButtonCurTimeUTC);

        RadioButtonCurTimeUTCOffset = new QRadioButton(GroupBoxCurrentTime);
        ButtonGroupCurrentTime->addButton(RadioButtonCurTimeUTCOffset);
        RadioButtonCurTimeUTCOffset->setObjectName(QString::fromUtf8("RadioButtonCurTimeUTCOffset"));
        sizePolicy3.setHeightForWidth(RadioButtonCurTimeUTCOffset->sizePolicy().hasHeightForWidth());
        RadioButtonCurTimeUTCOffset->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(RadioButtonCurTimeUTCOffset);


        verticalLayout_4->addWidget(GroupBoxCurrentTime);

        verticalSpacer_4 = new QSpacerItem(20, 162, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        TabWidgetParam->addTab(tabMiscellaneous, QString());

        horizontalLayout->addWidget(TabWidgetParam);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        ButtonStartStop = new QPushButton(centralwidget);
        ButtonStartStop->setObjectName(QString::fromUtf8("ButtonStartStop"));
        ButtonStartStop->setAutoDefault(true);

        horizontalLayout_8->addWidget(ButtonStartStop);

        ButtonCodec = new QPushButton(centralwidget);
        ButtonCodec->setObjectName(QString::fromUtf8("ButtonCodec"));

        horizontalLayout_8->addWidget(ButtonCodec);

        ButtonClose = new QPushButton(centralwidget);
        ButtonClose->setObjectName(QString::fromUtf8("ButtonClose"));
        ButtonClose->setAutoDefault(true);

        horizontalLayout_8->addWidget(ButtonClose);


        gridLayout->addLayout(horizontalLayout_8, 1, 0, 1, 1);

        TabWidgetServices = new QTabWidget(centralwidget);
        TabWidgetServices->setObjectName(QString::fromUtf8("TabWidgetServices"));
        TabWidgetServices->setEnabled(true);
        TabWidgetServices->setTabPosition(QTabWidget::North);
        tabService1 = new QWidget();
        tabService1->setObjectName(QString::fromUtf8("tabService1"));
        horizontalLayout_5 = new QHBoxLayout(tabService1);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        CheckBoxEnableService = new QCheckBox(tabService1);
        CheckBoxEnableService->setObjectName(QString::fromUtf8("CheckBoxEnableService"));
        CheckBoxEnableService->setEnabled(true);
        sizePolicy3.setHeightForWidth(CheckBoxEnableService->sizePolicy().hasHeightForWidth());
        CheckBoxEnableService->setSizePolicy(sizePolicy3);
        CheckBoxEnableService->setChecked(false);
        CheckBoxEnableService->setTristate(false);

        verticalLayout_6->addWidget(CheckBoxEnableService);

        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setSpacing(6);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        vboxLayout3->setContentsMargins(11, 11, 11, 11);
        hboxLayout11 = new QHBoxLayout();
        hboxLayout11->setSpacing(6);
        hboxLayout11->setObjectName(QString::fromUtf8("hboxLayout11"));
        hboxLayout11->setContentsMargins(0, 0, 0, 0);
        TextLabelServiceLabel = new QLabel(tabService1);
        TextLabelServiceLabel->setObjectName(QString::fromUtf8("TextLabelServiceLabel"));
        TextLabelServiceLabel->setWordWrap(false);

        hboxLayout11->addWidget(TextLabelServiceLabel);

        LineEditServiceLabel = new QLineEdit(tabService1);
        LineEditServiceLabel->setObjectName(QString::fromUtf8("LineEditServiceLabel"));
        sizePolicy1.setHeightForWidth(LineEditServiceLabel->sizePolicy().hasHeightForWidth());
        LineEditServiceLabel->setSizePolicy(sizePolicy1);

        hboxLayout11->addWidget(LineEditServiceLabel);


        vboxLayout3->addLayout(hboxLayout11);

        hboxLayout12 = new QHBoxLayout();
        hboxLayout12->setSpacing(6);
        hboxLayout12->setObjectName(QString::fromUtf8("hboxLayout12"));
        hboxLayout12->setContentsMargins(0, 0, 0, 0);
        TextLabelServiceID = new QLabel(tabService1);
        TextLabelServiceID->setObjectName(QString::fromUtf8("TextLabelServiceID"));
        TextLabelServiceID->setWordWrap(false);

        hboxLayout12->addWidget(TextLabelServiceID);

        LineEditServiceID = new QLineEdit(tabService1);
        LineEditServiceID->setObjectName(QString::fromUtf8("LineEditServiceID"));
        sizePolicy1.setHeightForWidth(LineEditServiceID->sizePolicy().hasHeightForWidth());
        LineEditServiceID->setSizePolicy(sizePolicy1);

        hboxLayout12->addWidget(LineEditServiceID);


        vboxLayout3->addLayout(hboxLayout12);

        hboxLayout13 = new QHBoxLayout();
        hboxLayout13->setSpacing(6);
        hboxLayout13->setObjectName(QString::fromUtf8("hboxLayout13"));
        hboxLayout13->setContentsMargins(0, 0, 0, 0);
        TextLabelServiceLanguage = new QLabel(tabService1);
        TextLabelServiceLanguage->setObjectName(QString::fromUtf8("TextLabelServiceLanguage"));
        TextLabelServiceLanguage->setWordWrap(false);

        hboxLayout13->addWidget(TextLabelServiceLanguage);

        ComboBoxLanguage = new QComboBox(tabService1);
        ComboBoxLanguage->setObjectName(QString::fromUtf8("ComboBoxLanguage"));

        hboxLayout13->addWidget(ComboBoxLanguage);


        vboxLayout3->addLayout(hboxLayout13);

        Spacer3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        vboxLayout3->addItem(Spacer3);


        verticalLayout_6->addLayout(vboxLayout3);


        horizontalLayout_5->addLayout(verticalLayout_6);

        GroupBoxAudio = new QGroupBox(tabService1);
        GroupBoxAudio->setObjectName(QString::fromUtf8("GroupBoxAudio"));
        vboxLayout4 = new QVBoxLayout(GroupBoxAudio);
        vboxLayout4->setSpacing(6);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        vboxLayout4->setContentsMargins(11, 11, 11, 11);
        CheckBoxEnableAudio = new QCheckBox(GroupBoxAudio);
        CheckBoxEnableAudio->setObjectName(QString::fromUtf8("CheckBoxEnableAudio"));
        CheckBoxEnableAudio->setEnabled(true);
        CheckBoxEnableAudio->setChecked(false);

        vboxLayout4->addWidget(CheckBoxEnableAudio);

        hboxLayout14 = new QHBoxLayout();
        hboxLayout14->setSpacing(6);
        hboxLayout14->setObjectName(QString::fromUtf8("hboxLayout14"));
        hboxLayout14->setContentsMargins(0, 0, 0, 0);
        TextLabelProgramType = new QLabel(GroupBoxAudio);
        TextLabelProgramType->setObjectName(QString::fromUtf8("TextLabelProgramType"));
        TextLabelProgramType->setWordWrap(false);

        hboxLayout14->addWidget(TextLabelProgramType);

        ComboBoxProgramType = new QComboBox(GroupBoxAudio);
        ComboBoxProgramType->setObjectName(QString::fromUtf8("ComboBoxProgramType"));

        hboxLayout14->addWidget(ComboBoxProgramType);


        vboxLayout4->addLayout(hboxLayout14);

        GroupBoxCodec = new QGroupBox(GroupBoxAudio);
        GroupBoxCodec->setObjectName(QString::fromUtf8("GroupBoxCodec"));
        hboxLayout15 = new QHBoxLayout(GroupBoxCodec);
        hboxLayout15->setObjectName(QString::fromUtf8("hboxLayout15"));
        RadioButtonAAC = new QRadioButton(GroupBoxCodec);
        ButtonGroupCodec = new QButtonGroup(TransmDlgBase);
        ButtonGroupCodec->setObjectName(QString::fromUtf8("ButtonGroupCodec"));
        ButtonGroupCodec->addButton(RadioButtonAAC);
        RadioButtonAAC->setObjectName(QString::fromUtf8("RadioButtonAAC"));

        hboxLayout15->addWidget(RadioButtonAAC);

        RadioButtonOPUS = new QRadioButton(GroupBoxCodec);
        ButtonGroupCodec->addButton(RadioButtonOPUS);
        RadioButtonOPUS->setObjectName(QString::fromUtf8("RadioButtonOPUS"));

        hboxLayout15->addWidget(RadioButtonOPUS);

        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        hboxLayout15->addItem(horizontalSpacer_2);


        vboxLayout4->addWidget(GroupBoxCodec);

        GroupBoxTextMessage = new QGroupBox(GroupBoxAudio);
        GroupBoxTextMessage->setObjectName(QString::fromUtf8("GroupBoxTextMessage"));
        vboxLayout5 = new QVBoxLayout(GroupBoxTextMessage);
        vboxLayout5->setSpacing(6);
        vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
        vboxLayout5->setContentsMargins(11, 11, 11, 11);
        CheckBoxEnableTextMessage = new QCheckBox(GroupBoxTextMessage);
        CheckBoxEnableTextMessage->setObjectName(QString::fromUtf8("CheckBoxEnableTextMessage"));
        CheckBoxEnableTextMessage->setEnabled(true);
        CheckBoxEnableTextMessage->setChecked(false);

        vboxLayout5->addWidget(CheckBoxEnableTextMessage);

        ComboBoxTextMessage = new QComboBox(GroupBoxTextMessage);
        ComboBoxTextMessage->setObjectName(QString::fromUtf8("ComboBoxTextMessage"));

        vboxLayout5->addWidget(ComboBoxTextMessage);

        MultiLineEditTextMessage = new QTextEdit(GroupBoxTextMessage);
        MultiLineEditTextMessage->setObjectName(QString::fromUtf8("MultiLineEditTextMessage"));
        MultiLineEditTextMessage->setTabChangesFocus(true);
        MultiLineEditTextMessage->setAcceptRichText(false);

        vboxLayout5->addWidget(MultiLineEditTextMessage);

        hboxLayout16 = new QHBoxLayout();
        hboxLayout16->setSpacing(6);
        hboxLayout16->setObjectName(QString::fromUtf8("hboxLayout16"));
        hboxLayout16->setContentsMargins(0, 0, 0, 0);
        PushButtonClearAllText = new QPushButton(GroupBoxTextMessage);
        PushButtonClearAllText->setObjectName(QString::fromUtf8("PushButtonClearAllText"));

        hboxLayout16->addWidget(PushButtonClearAllText);

        Spacer2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout16->addItem(Spacer2);

        PushButtonAddText = new QPushButton(GroupBoxTextMessage);
        PushButtonAddText->setObjectName(QString::fromUtf8("PushButtonAddText"));

        hboxLayout16->addWidget(PushButtonAddText);


        vboxLayout5->addLayout(hboxLayout16);


        vboxLayout4->addWidget(GroupBoxTextMessage);


        horizontalLayout_5->addWidget(GroupBoxAudio);

        GroupBoxData = new QGroupBox(tabService1);
        GroupBoxData->setObjectName(QString::fromUtf8("GroupBoxData"));
        vboxLayout6 = new QVBoxLayout(GroupBoxData);
        vboxLayout6->setSpacing(6);
        vboxLayout6->setObjectName(QString::fromUtf8("vboxLayout6"));
        vboxLayout6->setContentsMargins(11, 11, 11, 11);
        CheckBoxEnableData = new QCheckBox(GroupBoxData);
        CheckBoxEnableData->setObjectName(QString::fromUtf8("CheckBoxEnableData"));
        CheckBoxEnableData->setEnabled(true);
        CheckBoxEnableData->setChecked(false);

        vboxLayout6->addWidget(CheckBoxEnableData);

        CheckBoxRemovePath = new QCheckBox(GroupBoxData);
        CheckBoxRemovePath->setObjectName(QString::fromUtf8("CheckBoxRemovePath"));

        vboxLayout6->addWidget(CheckBoxRemovePath);

        TreeWidgetFileNames = new QTreeWidget(GroupBoxData);
        TreeWidgetFileNames->setObjectName(QString::fromUtf8("TreeWidgetFileNames"));
        TreeWidgetFileNames->setAutoScroll(false);
        TreeWidgetFileNames->setEditTriggers(QAbstractItemView::NoEditTriggers);
        TreeWidgetFileNames->setAlternatingRowColors(true);
        TreeWidgetFileNames->setSelectionMode(QAbstractItemView::NoSelection);
        TreeWidgetFileNames->setSelectionBehavior(QAbstractItemView::SelectRows);
        TreeWidgetFileNames->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        TreeWidgetFileNames->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        TreeWidgetFileNames->setIndentation(0);
        TreeWidgetFileNames->setRootIsDecorated(false);
        TreeWidgetFileNames->setUniformRowHeights(true);
        TreeWidgetFileNames->header()->setVisible(true);
        TreeWidgetFileNames->header()->setStretchLastSection(false);

        vboxLayout6->addWidget(TreeWidgetFileNames);

        hboxLayout17 = new QHBoxLayout();
        hboxLayout17->setSpacing(6);
        hboxLayout17->setObjectName(QString::fromUtf8("hboxLayout17"));
        hboxLayout17->setContentsMargins(0, 0, 0, 0);
        PushButtonClearAllFileNames = new QPushButton(GroupBoxData);
        PushButtonClearAllFileNames->setObjectName(QString::fromUtf8("PushButtonClearAllFileNames"));

        hboxLayout17->addWidget(PushButtonClearAllFileNames);

        Spacer2_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout17->addItem(Spacer2_2);

        PushButtonAddFile = new QPushButton(GroupBoxData);
        PushButtonAddFile->setObjectName(QString::fromUtf8("PushButtonAddFile"));

        hboxLayout17->addWidget(PushButtonAddFile);


        vboxLayout6->addLayout(hboxLayout17);


        horizontalLayout_5->addWidget(GroupBoxData);

        TabWidgetServices->addTab(tabService1, QString());
        tabService2 = new QWidget();
        tabService2->setObjectName(QString::fromUtf8("tabService2"));
        TabWidgetServices->addTab(tabService2, QString());
        tabService3 = new QWidget();
        tabService3->setObjectName(QString::fromUtf8("tabService3"));
        TabWidgetServices->addTab(tabService3, QString());
        tabService4 = new QWidget();
        tabService4->setObjectName(QString::fromUtf8("tabService4"));
        TabWidgetServices->addTab(tabService4, QString());

        gridLayout->addWidget(TabWidgetServices, 2, 0, 1, 1);

        TransmDlgBase->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TransmDlgBase);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 967, 20));
        menu_Settings = new QMenu(menubar);
        menu_Settings->setObjectName(QString::fromUtf8("menu_Settings"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        TransmDlgBase->setMenuBar(menubar);
        QWidget::setTabOrder(TabWidgetParam, RadioButtonRMA);
        QWidget::setTabOrder(RadioButtonRMA, RadioButtonRMB);
        QWidget::setTabOrder(RadioButtonRMB, RadioButtonRMC);
        QWidget::setTabOrder(RadioButtonRMC, RadioButtonRMD);
        QWidget::setTabOrder(RadioButtonRMD, RadioButtonBandwidth45);
        QWidget::setTabOrder(RadioButtonBandwidth45, RadioButtonBandwidth5);
        QWidget::setTabOrder(RadioButtonBandwidth5, RadioButtonBandwidth9);
        QWidget::setTabOrder(RadioButtonBandwidth9, RadioButtonBandwidth10);
        QWidget::setTabOrder(RadioButtonBandwidth10, RadioButtonBandwidth18);
        QWidget::setTabOrder(RadioButtonBandwidth18, RadioButtonBandwidth20);
        QWidget::setTabOrder(RadioButtonBandwidth20, ComboBoxMSCConstellation);
        QWidget::setTabOrder(ComboBoxMSCConstellation, ComboBoxMSCProtLev);
        QWidget::setTabOrder(ComboBoxMSCProtLev, ComboBoxSDCConstellation);
        QWidget::setTabOrder(ComboBoxSDCConstellation, ComboBoxMSCInterleaver);
        QWidget::setTabOrder(ComboBoxMSCInterleaver, LineEditSndCrdIF);
        QWidget::setTabOrder(LineEditSndCrdIF, RadioButtonOutReal);
        QWidget::setTabOrder(RadioButtonOutReal, RadioButtonOutIQPos);
        QWidget::setTabOrder(RadioButtonOutIQPos, RadioButtonOutIQNeg);
        QWidget::setTabOrder(RadioButtonOutIQNeg, RadioButtonOutEP);
        QWidget::setTabOrder(RadioButtonOutEP, RadioButtonCurTimeOff);
        QWidget::setTabOrder(RadioButtonCurTimeOff, RadioButtonCurTimeLocal);
        QWidget::setTabOrder(RadioButtonCurTimeLocal, RadioButtonCurTimeUTC);
        QWidget::setTabOrder(RadioButtonCurTimeUTC, RadioButtonCurTimeUTCOffset);
        QWidget::setTabOrder(RadioButtonCurTimeUTCOffset, TabWidgetServices);
        QWidget::setTabOrder(TabWidgetServices, LineEditServiceLabel);
        QWidget::setTabOrder(LineEditServiceLabel, LineEditServiceID);
        QWidget::setTabOrder(LineEditServiceID, ComboBoxLanguage);
        QWidget::setTabOrder(ComboBoxLanguage, CheckBoxEnableAudio);
        QWidget::setTabOrder(CheckBoxEnableAudio, ComboBoxProgramType);
        QWidget::setTabOrder(ComboBoxProgramType, RadioButtonAAC);
        QWidget::setTabOrder(RadioButtonAAC, RadioButtonOPUS);
        QWidget::setTabOrder(RadioButtonOPUS, CheckBoxEnableTextMessage);
        QWidget::setTabOrder(CheckBoxEnableTextMessage, ComboBoxTextMessage);
        QWidget::setTabOrder(ComboBoxTextMessage, MultiLineEditTextMessage);
        QWidget::setTabOrder(MultiLineEditTextMessage, PushButtonClearAllText);
        QWidget::setTabOrder(PushButtonClearAllText, PushButtonAddText);
        QWidget::setTabOrder(PushButtonAddText, CheckBoxEnableData);
        QWidget::setTabOrder(CheckBoxEnableData, CheckBoxRemovePath);
        QWidget::setTabOrder(CheckBoxRemovePath, TreeWidgetFileNames);
        QWidget::setTabOrder(TreeWidgetFileNames, PushButtonClearAllFileNames);
        QWidget::setTabOrder(PushButtonClearAllFileNames, PushButtonAddFile);

        menubar->addAction(menu_Settings->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionWhats_This);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout_Dream);

        retranslateUi(TransmDlgBase);
        QObject::connect(ButtonClose, SIGNAL(clicked()), TransmDlgBase, SLOT(close()));

        TabWidgetParam->setCurrentIndex(0);
        ButtonStartStop->setDefault(true);
        ButtonClose->setDefault(false);
        TabWidgetServices->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TransmDlgBase);
    } // setupUi

    void retranslateUi(QMainWindow *TransmDlgBase)
    {
        TransmDlgBase->setWindowTitle(QCoreApplication::translate("TransmDlgBase", "Dream DRM Transmitter", nullptr));
        actionWhats_This->setText(QCoreApplication::translate("TransmDlgBase", "Whats This", nullptr));
#if QT_CONFIG(shortcut)
        actionWhats_This->setShortcut(QCoreApplication::translate("TransmDlgBase", "Shift+F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout_Dream->setText(QCoreApplication::translate("TransmDlgBase", "About Dream...", nullptr));
        TextLabelMainAuthors->setText(QCoreApplication::translate("TransmDlgBase", "Volker Fischer, Alexander Kurpiers", nullptr));
        TextLabelCompany->setText(QCoreApplication::translate("TransmDlgBase", "Darmstadt University of Technology\n"
"Institute for Communication Technology", nullptr));
        GroupInput->setTitle(QCoreApplication::translate("TransmDlgBase", "Indicators", nullptr));
        TextLabelAudioLevel->setText(QCoreApplication::translate("TransmDlgBase", "Audio Level [dB]:", nullptr));
        TextLabelCurPict->setText(QCoreApplication::translate("TransmDlgBase", "TextLabelCurPict", nullptr));
        GroupBoxRobustnessMode->setTitle(QCoreApplication::translate("TransmDlgBase", "Robustness Mode", nullptr));
        RadioButtonRMA->setText(QCoreApplication::translate("TransmDlgBase", "A", nullptr));
        RadioButtonRMB->setText(QCoreApplication::translate("TransmDlgBase", "B", nullptr));
        RadioButtonRMC->setText(QCoreApplication::translate("TransmDlgBase", "C", nullptr));
        RadioButtonRMD->setText(QCoreApplication::translate("TransmDlgBase", "D", nullptr));
        GroupBoxBandwidth->setTitle(QCoreApplication::translate("TransmDlgBase", "Bandwidth", nullptr));
        RadioButtonBandwidth45->setText(QCoreApplication::translate("TransmDlgBase", "4.5 kHz", nullptr));
        RadioButtonBandwidth9->setText(QCoreApplication::translate("TransmDlgBase", "9 kHz", nullptr));
        RadioButtonBandwidth18->setText(QCoreApplication::translate("TransmDlgBase", "18 kHz", nullptr));
        RadioButtonBandwidth5->setText(QCoreApplication::translate("TransmDlgBase", "5 kHz", nullptr));
        RadioButtonBandwidth10->setText(QCoreApplication::translate("TransmDlgBase", "10 kHz", nullptr));
        RadioButtonBandwidth20->setText(QCoreApplication::translate("TransmDlgBase", "20 kHz", nullptr));
        TextLabelMSCConst->setText(QCoreApplication::translate("TransmDlgBase", "MSC Constellation Scheme:", nullptr));
        TextLabelProtLev->setText(QCoreApplication::translate("TransmDlgBase", "MSC Protection Level:", nullptr));
        TextLabelSDCConst->setText(QCoreApplication::translate("TransmDlgBase", "SDC Constellation Scheme:", nullptr));
        TextLabelInterleaver->setText(QCoreApplication::translate("TransmDlgBase", "MSC Interleaver Mode:", nullptr));
        TabWidgetParam->setTabText(TabWidgetParam->indexOf(tabChannelParameters), QCoreApplication::translate("TransmDlgBase", "Channel Parameters", nullptr));
        ButtonGroupIF->setTitle(QCoreApplication::translate("TransmDlgBase", "Intermediate Frequency", nullptr));
        TextLabelIFUnit->setText(QCoreApplication::translate("TransmDlgBase", " Hz", nullptr));
        GroupBoxOutput->setTitle(QCoreApplication::translate("TransmDlgBase", "Format", nullptr));
        RadioButtonOutReal->setText(QCoreApplication::translate("TransmDlgBase", "Real val.", nullptr));
        RadioButtonOutIQPos->setText(QCoreApplication::translate("TransmDlgBase", "I / Q (pos)", nullptr));
        RadioButtonOutIQNeg->setText(QCoreApplication::translate("TransmDlgBase", "I / Q (neg)", nullptr));
        RadioButtonOutEP->setText(QCoreApplication::translate("TransmDlgBase", "E / P", nullptr));
        GroupBoxOutputOption->setTitle(QCoreApplication::translate("TransmDlgBase", "Options", nullptr));
        CheckBoxAmplifiedOutput->setText(QCoreApplication::translate("TransmDlgBase", "+12 dB", nullptr));
        CheckBoxHighQualityIQ->setText(QCoreApplication::translate("TransmDlgBase", "High quality I / Q", nullptr));
        TabWidgetParam->setTabText(TabWidgetParam->indexOf(tabOutput), QCoreApplication::translate("TransmDlgBase", "Output", nullptr));
        GroupBoxCurrentTime->setTitle(QCoreApplication::translate("TransmDlgBase", "Current Time Transmission", nullptr));
        RadioButtonCurTimeOff->setText(QCoreApplication::translate("TransmDlgBase", "Off", nullptr));
        RadioButtonCurTimeLocal->setText(QCoreApplication::translate("TransmDlgBase", "Local", nullptr));
        RadioButtonCurTimeUTC->setText(QCoreApplication::translate("TransmDlgBase", "UTC", nullptr));
        RadioButtonCurTimeUTCOffset->setText(QCoreApplication::translate("TransmDlgBase", "UTC+Offset", nullptr));
        TabWidgetParam->setTabText(TabWidgetParam->indexOf(tabMiscellaneous), QCoreApplication::translate("TransmDlgBase", "Miscellaneous", nullptr));
        ButtonStartStop->setText(QCoreApplication::translate("TransmDlgBase", "&Start", nullptr));
        ButtonCodec->setText(QCoreApplication::translate("TransmDlgBase", "Codec &Parameters", nullptr));
        ButtonClose->setText(QCoreApplication::translate("TransmDlgBase", "&Close", nullptr));
        CheckBoxEnableService->setText(QCoreApplication::translate("TransmDlgBase", "Enable", nullptr));
        TextLabelServiceLabel->setText(QCoreApplication::translate("TransmDlgBase", "Label:", nullptr));
        TextLabelServiceID->setText(QCoreApplication::translate("TransmDlgBase", "Service ID:", nullptr));
        TextLabelServiceLanguage->setText(QCoreApplication::translate("TransmDlgBase", "Language:", nullptr));
        GroupBoxAudio->setTitle(QCoreApplication::translate("TransmDlgBase", "Audio", nullptr));
        CheckBoxEnableAudio->setText(QCoreApplication::translate("TransmDlgBase", "Enable", nullptr));
        TextLabelProgramType->setText(QCoreApplication::translate("TransmDlgBase", "Program Type:", nullptr));
        GroupBoxCodec->setTitle(QCoreApplication::translate("TransmDlgBase", "Codec", nullptr));
        RadioButtonAAC->setText(QCoreApplication::translate("TransmDlgBase", "AAC", nullptr));
        RadioButtonOPUS->setText(QCoreApplication::translate("TransmDlgBase", "Opus", nullptr));
        GroupBoxTextMessage->setTitle(QCoreApplication::translate("TransmDlgBase", "Text Message", nullptr));
        CheckBoxEnableTextMessage->setText(QCoreApplication::translate("TransmDlgBase", "Enable", nullptr));
        PushButtonClearAllText->setText(QCoreApplication::translate("TransmDlgBase", "&Clear All", nullptr));
        PushButtonAddText->setText(QCoreApplication::translate("TransmDlgBase", "&Add / Modify", nullptr));
        GroupBoxData->setTitle(QCoreApplication::translate("TransmDlgBase", "Data (SlideShow Application)", nullptr));
        CheckBoxEnableData->setText(QCoreApplication::translate("TransmDlgBase", "Enable", nullptr));
        CheckBoxRemovePath->setText(QCoreApplication::translate("TransmDlgBase", "Remove path from filename", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = TreeWidgetFileNames->headerItem();
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("TransmDlgBase", "Full Path", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("TransmDlgBase", "Size [KB]", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("TransmDlgBase", "File Name", nullptr));
        PushButtonClearAllFileNames->setText(QCoreApplication::translate("TransmDlgBase", "&Clear All", nullptr));
        PushButtonAddFile->setText(QCoreApplication::translate("TransmDlgBase", "&Add", nullptr));
        TabWidgetServices->setTabText(TabWidgetServices->indexOf(tabService1), QCoreApplication::translate("TransmDlgBase", "Service 1", nullptr));
        TabWidgetServices->setTabText(TabWidgetServices->indexOf(tabService2), QCoreApplication::translate("TransmDlgBase", "Service 2", nullptr));
        TabWidgetServices->setTabText(TabWidgetServices->indexOf(tabService3), QCoreApplication::translate("TransmDlgBase", "Service 3", nullptr));
        TabWidgetServices->setTabText(TabWidgetServices->indexOf(tabService4), QCoreApplication::translate("TransmDlgBase", "Service 4", nullptr));
        menu_Settings->setTitle(QCoreApplication::translate("TransmDlgBase", "&Settings", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("TransmDlgBase", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransmDlgBase: public Ui_TransmDlgBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSMDLGBASE_H
