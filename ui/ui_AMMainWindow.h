/********************************************************************************
** Form generated from reading UI file 'AMMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AMMAINWINDOW_H
#define UI_AMMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qwt_dial.h"
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_AMMainWindow
{
public:
    QAction *action_Stations_Dialog;
    QAction *action_Live_Schedule_Dialog;
    QAction *actionExit;
    QAction *actionAM;
    QAction *actionFM;
    QAction *actionDRM;
    QAction *actionWhats_This;
    QAction *actionAbout_Dream;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QwtPlot *plot;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QPushButton *ButtonWaterfall;
    QVBoxLayout *verticalLayout_2;
    QLabel *LabelFreqOffset;
    QPushButton *ButtonFreqOffset;
    QLabel *TextLabelPhaseOffset;
    QwtDial *PhaseDial;
    QGroupBox *groupBoxBW;
    QHBoxLayout *horizontalLayout_5;
    QLabel *TextLabelBandWidth;
    QSlider *SliderBandwidth;
    QHBoxLayout *_9;
    QGroupBox *groupBoxDemodulation;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *RadioButtonDemAM;
    QRadioButton *RadioButtonDemLSB;
    QRadioButton *RadioButtonDemUSB;
    QRadioButton *RadioButtonDemCW;
    QRadioButton *RadioButtonDemFM;
    QGroupBox *groupBoxAGC;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *RadioButtonAGCOff;
    QRadioButton *RadioButtonAGCSlow;
    QRadioButton *RadioButtonAGCMed;
    QRadioButton *RadioButtonAGCFast;
    QGroupBox *groupBoxNoiseReduction;
    QGridLayout *gridLayout_4;
    QRadioButton *RadioButtonNoiRedOff;
    QRadioButton *RadioButtonNoiRedLow;
    QRadioButton *RadioButtonNoiRedMed;
    QRadioButton *RadioButtonNoiRedHigh;
    QRadioButton *RadioButtonNoiRedSpeex;
    QSpinBox *SpinBoxNoiRedLevel;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBoxAudio;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *CheckBoxMuteAudio;
    QCheckBox *CheckBoxSaveAudioWave;
    QGroupBox *GroupBoxPLL;
    QGridLayout *gridLayout;
    QCheckBox *CheckBoxPLL;
    QGroupBox *GroupBoxAutoFreqAcq;
    QGridLayout *gridLayout_2;
    QCheckBox *CheckBoxAutoFreqAcq;
    QSpacerItem *Spacer6;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *ButtonAMSS;
    QPushButton *ButtonDRM;
    QMenuBar *menubar;
    QMenu *menu_View;
    QMenu *menu_Settings;
    QMenu *menuHelp;
    QButtonGroup *ButtonGroupNoiseReduction;
    QButtonGroup *ButtonGroupAGC;
    QButtonGroup *ButtonGroupDemodulation;

    void setupUi(QMainWindow *AMMainWindow)
    {
        if (AMMainWindow->objectName().isEmpty())
            AMMainWindow->setObjectName(QString::fromUtf8("AMMainWindow"));
        AMMainWindow->resize(899, 498);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/MainIcon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        AMMainWindow->setWindowIcon(icon);
        action_Stations_Dialog = new QAction(AMMainWindow);
        action_Stations_Dialog->setObjectName(QString::fromUtf8("action_Stations_Dialog"));
        action_Live_Schedule_Dialog = new QAction(AMMainWindow);
        action_Live_Schedule_Dialog->setObjectName(QString::fromUtf8("action_Live_Schedule_Dialog"));
        actionExit = new QAction(AMMainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAM = new QAction(AMMainWindow);
        actionAM->setObjectName(QString::fromUtf8("actionAM"));
        actionFM = new QAction(AMMainWindow);
        actionFM->setObjectName(QString::fromUtf8("actionFM"));
        actionDRM = new QAction(AMMainWindow);
        actionDRM->setObjectName(QString::fromUtf8("actionDRM"));
        actionWhats_This = new QAction(AMMainWindow);
        actionWhats_This->setObjectName(QString::fromUtf8("actionWhats_This"));
        actionAbout_Dream = new QAction(AMMainWindow);
        actionAbout_Dream->setObjectName(QString::fromUtf8("actionAbout_Dream"));
        centralwidget = new QWidget(AMMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        plot = new QwtPlot(frame);
        plot->setObjectName(QString::fromUtf8("plot"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(plot);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        ButtonWaterfall = new QPushButton(frame_2);
        ButtonWaterfall->setObjectName(QString::fromUtf8("ButtonWaterfall"));
        ButtonWaterfall->setCheckable(true);
        ButtonWaterfall->setAutoDefault(true);

        gridLayout_3->addWidget(ButtonWaterfall, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        LabelFreqOffset = new QLabel(frame_2);
        LabelFreqOffset->setObjectName(QString::fromUtf8("LabelFreqOffset"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(LabelFreqOffset->sizePolicy().hasHeightForWidth());
        LabelFreqOffset->setSizePolicy(sizePolicy2);
        LabelFreqOffset->setTextFormat(Qt::PlainText);
        LabelFreqOffset->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        LabelFreqOffset->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_2->addWidget(LabelFreqOffset);

        ButtonFreqOffset = new QPushButton(frame_2);
        ButtonFreqOffset->setObjectName(QString::fromUtf8("ButtonFreqOffset"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        ButtonFreqOffset->setFont(font);
        ButtonFreqOffset->setFlat(true);

        verticalLayout_2->addWidget(ButtonFreqOffset);


        gridLayout_3->addLayout(verticalLayout_2, 1, 0, 1, 1);

        TextLabelPhaseOffset = new QLabel(frame_2);
        TextLabelPhaseOffset->setObjectName(QString::fromUtf8("TextLabelPhaseOffset"));
        sizePolicy.setHeightForWidth(TextLabelPhaseOffset->sizePolicy().hasHeightForWidth());
        TextLabelPhaseOffset->setSizePolicy(sizePolicy);
        TextLabelPhaseOffset->setAlignment(Qt::AlignCenter);
        TextLabelPhaseOffset->setWordWrap(false);

        gridLayout_3->addWidget(TextLabelPhaseOffset, 2, 0, 1, 1);

        PhaseDial = new QwtDial(frame_2);
        PhaseDial->setObjectName(QString::fromUtf8("PhaseDial"));
        PhaseDial->setMinimumSize(QSize(0, 70));
        PhaseDial->setFocusPolicy(Qt::NoFocus);
        PhaseDial->setProperty("lineWidth", QVariant(4));

        gridLayout_3->addWidget(PhaseDial, 3, 0, 1, 1);


        horizontalLayout->addWidget(frame_2);


        verticalLayout_3->addWidget(frame);

        groupBoxBW = new QGroupBox(centralwidget);
        groupBoxBW->setObjectName(QString::fromUtf8("groupBoxBW"));
        horizontalLayout_5 = new QHBoxLayout(groupBoxBW);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        TextLabelBandWidth = new QLabel(groupBoxBW);
        TextLabelBandWidth->setObjectName(QString::fromUtf8("TextLabelBandWidth"));
        TextLabelBandWidth->setMinimumSize(QSize(70, 0));
        TextLabelBandWidth->setWordWrap(false);

        horizontalLayout_5->addWidget(TextLabelBandWidth);

        SliderBandwidth = new QSlider(groupBoxBW);
        SliderBandwidth->setObjectName(QString::fromUtf8("SliderBandwidth"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(SliderBandwidth->sizePolicy().hasHeightForWidth());
        SliderBandwidth->setSizePolicy(sizePolicy3);
        SliderBandwidth->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(SliderBandwidth);


        verticalLayout_3->addWidget(groupBoxBW);

        _9 = new QHBoxLayout();
        _9->setSpacing(6);
        _9->setObjectName(QString::fromUtf8("_9"));
        _9->setContentsMargins(0, 0, 0, 0);
        groupBoxDemodulation = new QGroupBox(centralwidget);
        groupBoxDemodulation->setObjectName(QString::fromUtf8("groupBoxDemodulation"));
        sizePolicy2.setHeightForWidth(groupBoxDemodulation->sizePolicy().hasHeightForWidth());
        groupBoxDemodulation->setSizePolicy(sizePolicy2);
        horizontalLayout_2 = new QHBoxLayout(groupBoxDemodulation);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        RadioButtonDemAM = new QRadioButton(groupBoxDemodulation);
        ButtonGroupDemodulation = new QButtonGroup(AMMainWindow);
        ButtonGroupDemodulation->setObjectName(QString::fromUtf8("ButtonGroupDemodulation"));
        ButtonGroupDemodulation->addButton(RadioButtonDemAM);
        RadioButtonDemAM->setObjectName(QString::fromUtf8("RadioButtonDemAM"));

        horizontalLayout_2->addWidget(RadioButtonDemAM);

        RadioButtonDemLSB = new QRadioButton(groupBoxDemodulation);
        ButtonGroupDemodulation->addButton(RadioButtonDemLSB);
        RadioButtonDemLSB->setObjectName(QString::fromUtf8("RadioButtonDemLSB"));

        horizontalLayout_2->addWidget(RadioButtonDemLSB);

        RadioButtonDemUSB = new QRadioButton(groupBoxDemodulation);
        ButtonGroupDemodulation->addButton(RadioButtonDemUSB);
        RadioButtonDemUSB->setObjectName(QString::fromUtf8("RadioButtonDemUSB"));

        horizontalLayout_2->addWidget(RadioButtonDemUSB);

        RadioButtonDemCW = new QRadioButton(groupBoxDemodulation);
        ButtonGroupDemodulation->addButton(RadioButtonDemCW);
        RadioButtonDemCW->setObjectName(QString::fromUtf8("RadioButtonDemCW"));

        horizontalLayout_2->addWidget(RadioButtonDemCW);

        RadioButtonDemFM = new QRadioButton(groupBoxDemodulation);
        ButtonGroupDemodulation->addButton(RadioButtonDemFM);
        RadioButtonDemFM->setObjectName(QString::fromUtf8("RadioButtonDemFM"));

        horizontalLayout_2->addWidget(RadioButtonDemFM);


        _9->addWidget(groupBoxDemodulation);

        groupBoxAGC = new QGroupBox(centralwidget);
        groupBoxAGC->setObjectName(QString::fromUtf8("groupBoxAGC"));
        sizePolicy2.setHeightForWidth(groupBoxAGC->sizePolicy().hasHeightForWidth());
        groupBoxAGC->setSizePolicy(sizePolicy2);
        horizontalLayout_3 = new QHBoxLayout(groupBoxAGC);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        RadioButtonAGCOff = new QRadioButton(groupBoxAGC);
        ButtonGroupAGC = new QButtonGroup(AMMainWindow);
        ButtonGroupAGC->setObjectName(QString::fromUtf8("ButtonGroupAGC"));
        ButtonGroupAGC->addButton(RadioButtonAGCOff);
        RadioButtonAGCOff->setObjectName(QString::fromUtf8("RadioButtonAGCOff"));

        horizontalLayout_3->addWidget(RadioButtonAGCOff);

        RadioButtonAGCSlow = new QRadioButton(groupBoxAGC);
        ButtonGroupAGC->addButton(RadioButtonAGCSlow);
        RadioButtonAGCSlow->setObjectName(QString::fromUtf8("RadioButtonAGCSlow"));

        horizontalLayout_3->addWidget(RadioButtonAGCSlow);

        RadioButtonAGCMed = new QRadioButton(groupBoxAGC);
        ButtonGroupAGC->addButton(RadioButtonAGCMed);
        RadioButtonAGCMed->setObjectName(QString::fromUtf8("RadioButtonAGCMed"));

        horizontalLayout_3->addWidget(RadioButtonAGCMed);

        RadioButtonAGCFast = new QRadioButton(groupBoxAGC);
        ButtonGroupAGC->addButton(RadioButtonAGCFast);
        RadioButtonAGCFast->setObjectName(QString::fromUtf8("RadioButtonAGCFast"));

        horizontalLayout_3->addWidget(RadioButtonAGCFast);


        _9->addWidget(groupBoxAGC);

        groupBoxNoiseReduction = new QGroupBox(centralwidget);
        groupBoxNoiseReduction->setObjectName(QString::fromUtf8("groupBoxNoiseReduction"));
        sizePolicy2.setHeightForWidth(groupBoxNoiseReduction->sizePolicy().hasHeightForWidth());
        groupBoxNoiseReduction->setSizePolicy(sizePolicy2);
        gridLayout_4 = new QGridLayout(groupBoxNoiseReduction);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        RadioButtonNoiRedOff = new QRadioButton(groupBoxNoiseReduction);
        ButtonGroupNoiseReduction = new QButtonGroup(AMMainWindow);
        ButtonGroupNoiseReduction->setObjectName(QString::fromUtf8("ButtonGroupNoiseReduction"));
        ButtonGroupNoiseReduction->addButton(RadioButtonNoiRedOff);
        RadioButtonNoiRedOff->setObjectName(QString::fromUtf8("RadioButtonNoiRedOff"));

        gridLayout_4->addWidget(RadioButtonNoiRedOff, 0, 0, 1, 1);

        RadioButtonNoiRedLow = new QRadioButton(groupBoxNoiseReduction);
        ButtonGroupNoiseReduction->addButton(RadioButtonNoiRedLow);
        RadioButtonNoiRedLow->setObjectName(QString::fromUtf8("RadioButtonNoiRedLow"));

        gridLayout_4->addWidget(RadioButtonNoiRedLow, 0, 1, 1, 1);

        RadioButtonNoiRedMed = new QRadioButton(groupBoxNoiseReduction);
        ButtonGroupNoiseReduction->addButton(RadioButtonNoiRedMed);
        RadioButtonNoiRedMed->setObjectName(QString::fromUtf8("RadioButtonNoiRedMed"));

        gridLayout_4->addWidget(RadioButtonNoiRedMed, 0, 2, 1, 1);

        RadioButtonNoiRedHigh = new QRadioButton(groupBoxNoiseReduction);
        ButtonGroupNoiseReduction->addButton(RadioButtonNoiRedHigh);
        RadioButtonNoiRedHigh->setObjectName(QString::fromUtf8("RadioButtonNoiRedHigh"));

        gridLayout_4->addWidget(RadioButtonNoiRedHigh, 0, 3, 1, 1);

        RadioButtonNoiRedSpeex = new QRadioButton(groupBoxNoiseReduction);
        ButtonGroupNoiseReduction->addButton(RadioButtonNoiRedSpeex);
        RadioButtonNoiRedSpeex->setObjectName(QString::fromUtf8("RadioButtonNoiRedSpeex"));

        gridLayout_4->addWidget(RadioButtonNoiRedSpeex, 1, 0, 1, 1);

        SpinBoxNoiRedLevel = new QSpinBox(groupBoxNoiseReduction);
        SpinBoxNoiRedLevel->setObjectName(QString::fromUtf8("SpinBoxNoiRedLevel"));
        SpinBoxNoiRedLevel->setMinimum(-96);
        SpinBoxNoiRedLevel->setMaximum(-1);
        SpinBoxNoiRedLevel->setValue(-1);

        gridLayout_4->addWidget(SpinBoxNoiRedLevel, 1, 1, 1, 1);


        _9->addWidget(groupBoxNoiseReduction);


        verticalLayout_3->addLayout(_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        groupBoxAudio = new QGroupBox(centralwidget);
        groupBoxAudio->setObjectName(QString::fromUtf8("groupBoxAudio"));
        sizePolicy2.setHeightForWidth(groupBoxAudio->sizePolicy().hasHeightForWidth());
        groupBoxAudio->setSizePolicy(sizePolicy2);
        horizontalLayout_8 = new QHBoxLayout(groupBoxAudio);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        CheckBoxMuteAudio = new QCheckBox(groupBoxAudio);
        CheckBoxMuteAudio->setObjectName(QString::fromUtf8("CheckBoxMuteAudio"));

        horizontalLayout_8->addWidget(CheckBoxMuteAudio);

        CheckBoxSaveAudioWave = new QCheckBox(groupBoxAudio);
        CheckBoxSaveAudioWave->setObjectName(QString::fromUtf8("CheckBoxSaveAudioWave"));

        horizontalLayout_8->addWidget(CheckBoxSaveAudioWave);


        horizontalLayout_7->addWidget(groupBoxAudio);

        GroupBoxPLL = new QGroupBox(centralwidget);
        GroupBoxPLL->setObjectName(QString::fromUtf8("GroupBoxPLL"));
        sizePolicy2.setHeightForWidth(GroupBoxPLL->sizePolicy().hasHeightForWidth());
        GroupBoxPLL->setSizePolicy(sizePolicy2);
        gridLayout = new QGridLayout(GroupBoxPLL);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        CheckBoxPLL = new QCheckBox(GroupBoxPLL);
        CheckBoxPLL->setObjectName(QString::fromUtf8("CheckBoxPLL"));

        gridLayout->addWidget(CheckBoxPLL, 0, 0, 1, 1);


        horizontalLayout_7->addWidget(GroupBoxPLL);

        GroupBoxAutoFreqAcq = new QGroupBox(centralwidget);
        GroupBoxAutoFreqAcq->setObjectName(QString::fromUtf8("GroupBoxAutoFreqAcq"));
        sizePolicy2.setHeightForWidth(GroupBoxAutoFreqAcq->sizePolicy().hasHeightForWidth());
        GroupBoxAutoFreqAcq->setSizePolicy(sizePolicy2);
        gridLayout_2 = new QGridLayout(GroupBoxAutoFreqAcq);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        CheckBoxAutoFreqAcq = new QCheckBox(GroupBoxAutoFreqAcq);
        CheckBoxAutoFreqAcq->setObjectName(QString::fromUtf8("CheckBoxAutoFreqAcq"));

        gridLayout_2->addWidget(CheckBoxAutoFreqAcq, 0, 0, 1, 1);


        horizontalLayout_7->addWidget(GroupBoxAutoFreqAcq);

        Spacer6 = new QSpacerItem(20, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(Spacer6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(widget);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, -1, -1, 0);
        ButtonAMSS = new QPushButton(centralwidget);
        ButtonAMSS->setObjectName(QString::fromUtf8("ButtonAMSS"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(ButtonAMSS->sizePolicy().hasHeightForWidth());
        ButtonAMSS->setSizePolicy(sizePolicy4);
        ButtonAMSS->setAutoDefault(true);

        horizontalLayout_6->addWidget(ButtonAMSS);

        ButtonDRM = new QPushButton(centralwidget);
        ButtonDRM->setObjectName(QString::fromUtf8("ButtonDRM"));
        sizePolicy4.setHeightForWidth(ButtonDRM->sizePolicy().hasHeightForWidth());
        ButtonDRM->setSizePolicy(sizePolicy4);
        ButtonDRM->setAutoDefault(true);

        horizontalLayout_6->addWidget(ButtonDRM);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_7->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_7);

        AMMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AMMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 899, 21));
        menu_View = new QMenu(menubar);
        menu_View->setObjectName(QString::fromUtf8("menu_View"));
        menu_Settings = new QMenu(menubar);
        menu_Settings->setObjectName(QString::fromUtf8("menu_Settings"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        AMMainWindow->setMenuBar(menubar);

        menubar->addAction(menu_View->menuAction());
        menubar->addAction(menu_Settings->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menu_View->addAction(action_Stations_Dialog);
        menu_View->addAction(action_Live_Schedule_Dialog);
        menu_Settings->addAction(actionDRM);
        menu_Settings->addAction(actionFM);
        menu_Settings->addAction(actionAM);
        menuHelp->addAction(actionWhats_This);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout_Dream);

        retranslateUi(AMMainWindow);

        ButtonWaterfall->setDefault(true);
        ButtonAMSS->setDefault(true);
        ButtonDRM->setDefault(true);


        QMetaObject::connectSlotsByName(AMMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AMMainWindow)
    {
        AMMainWindow->setWindowTitle(QCoreApplication::translate("AMMainWindow", "Analog Demodulation", nullptr));
        action_Stations_Dialog->setText(QCoreApplication::translate("AMMainWindow", "S&tations Dialog...", nullptr));
#if QT_CONFIG(shortcut)
        action_Stations_Dialog->setShortcut(QCoreApplication::translate("AMMainWindow", "Alt+T", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Live_Schedule_Dialog->setText(QCoreApplication::translate("AMMainWindow", "&Live Schedule Dialog...", nullptr));
#if QT_CONFIG(shortcut)
        action_Live_Schedule_Dialog->setShortcut(QCoreApplication::translate("AMMainWindow", "Alt+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("AMMainWindow", "E&xit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("AMMainWindow", "Alt+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAM->setText(QCoreApplication::translate("AMMainWindow", "New AM Acquisition", nullptr));
#if QT_CONFIG(shortcut)
        actionAM->setShortcut(QCoreApplication::translate("AMMainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFM->setText(QCoreApplication::translate("AMMainWindow", "FM (analog)", nullptr));
#if QT_CONFIG(shortcut)
        actionFM->setShortcut(QCoreApplication::translate("AMMainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDRM->setText(QCoreApplication::translate("AMMainWindow", "DRM (digital)", nullptr));
#if QT_CONFIG(shortcut)
        actionDRM->setShortcut(QCoreApplication::translate("AMMainWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        actionWhats_This->setText(QCoreApplication::translate("AMMainWindow", "Whats This...", nullptr));
#if QT_CONFIG(shortcut)
        actionWhats_This->setShortcut(QCoreApplication::translate("AMMainWindow", "Shift+F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout_Dream->setText(QCoreApplication::translate("AMMainWindow", "About Dream...", nullptr));
        ButtonWaterfall->setWindowTitle(QString());
        ButtonWaterfall->setText(QCoreApplication::translate("AMMainWindow", "&Waterfall", nullptr));
        LabelFreqOffset->setText(QCoreApplication::translate("AMMainWindow", "Carrier Frequency:", nullptr));
        ButtonFreqOffset->setText(QCoreApplication::translate("AMMainWindow", "TextFreqOffset", nullptr));
        TextLabelPhaseOffset->setText(QCoreApplication::translate("AMMainWindow", "PLL\n"
"Phase Offset", nullptr));
        groupBoxBW->setTitle(QCoreApplication::translate("AMMainWindow", "Filter Bandwidth", nullptr));
        TextLabelBandWidth->setText(QCoreApplication::translate("AMMainWindow", "TextLabelBandWidth", nullptr));
        groupBoxDemodulation->setTitle(QCoreApplication::translate("AMMainWindow", "Demodulation", nullptr));
        RadioButtonDemAM->setText(QCoreApplication::translate("AMMainWindow", "AM", nullptr));
        RadioButtonDemLSB->setText(QCoreApplication::translate("AMMainWindow", "LSB", nullptr));
        RadioButtonDemUSB->setText(QCoreApplication::translate("AMMainWindow", "USB", nullptr));
        RadioButtonDemCW->setText(QCoreApplication::translate("AMMainWindow", "CW", nullptr));
        RadioButtonDemFM->setText(QCoreApplication::translate("AMMainWindow", "FM", nullptr));
        groupBoxAGC->setTitle(QCoreApplication::translate("AMMainWindow", "AGC", nullptr));
        RadioButtonAGCOff->setText(QCoreApplication::translate("AMMainWindow", "Off", nullptr));
        RadioButtonAGCSlow->setText(QCoreApplication::translate("AMMainWindow", "Slow", nullptr));
        RadioButtonAGCMed->setText(QCoreApplication::translate("AMMainWindow", "Med", nullptr));
        RadioButtonAGCFast->setText(QCoreApplication::translate("AMMainWindow", "Fast", nullptr));
        groupBoxNoiseReduction->setTitle(QCoreApplication::translate("AMMainWindow", "Noise Reduction", nullptr));
        RadioButtonNoiRedOff->setText(QCoreApplication::translate("AMMainWindow", "Off", nullptr));
        RadioButtonNoiRedLow->setText(QCoreApplication::translate("AMMainWindow", "Low", nullptr));
        RadioButtonNoiRedMed->setText(QCoreApplication::translate("AMMainWindow", "Med", nullptr));
        RadioButtonNoiRedHigh->setText(QCoreApplication::translate("AMMainWindow", "High", nullptr));
        RadioButtonNoiRedSpeex->setText(QCoreApplication::translate("AMMainWindow", "Speex", nullptr));
        SpinBoxNoiRedLevel->setSuffix(QCoreApplication::translate("AMMainWindow", " dB", nullptr));
        groupBoxAudio->setTitle(QCoreApplication::translate("AMMainWindow", "Audio", nullptr));
        CheckBoxMuteAudio->setText(QCoreApplication::translate("AMMainWindow", "Mute", nullptr));
        CheckBoxSaveAudioWave->setText(QCoreApplication::translate("AMMainWindow", "Save", nullptr));
        GroupBoxPLL->setTitle(QCoreApplication::translate("AMMainWindow", "PLL", nullptr));
        CheckBoxPLL->setText(QCoreApplication::translate("AMMainWindow", "Enable", nullptr));
        GroupBoxAutoFreqAcq->setTitle(QCoreApplication::translate("AMMainWindow", "Auto Frequency Acquisition", nullptr));
        CheckBoxAutoFreqAcq->setText(QCoreApplication::translate("AMMainWindow", "Enable", nullptr));
        ButtonAMSS->setWindowTitle(QString());
        ButtonAMSS->setText(QCoreApplication::translate("AMMainWindow", "&AMSS", nullptr));
        ButtonDRM->setWindowTitle(QString());
        ButtonDRM->setText(QCoreApplication::translate("AMMainWindow", "&DRM", nullptr));
        menu_View->setTitle(QCoreApplication::translate("AMMainWindow", "View", nullptr));
        menu_Settings->setTitle(QCoreApplication::translate("AMMainWindow", "Settings", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("AMMainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AMMainWindow: public Ui_AMMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AMMAINWINDOW_H
