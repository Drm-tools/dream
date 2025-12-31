/********************************************************************************
** Form generated from reading UI file 'OpusCodecParams.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPUSCODECPARAMS_H
#define UI_OPUSCODECPARAMS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OpusCodecParams
{
public:
    QGridLayout *gridLayout;
    QGroupBox *GroupBoxInfo;
    QHBoxLayout *hboxLayout;
    QLabel *Logo;
    QSpacerItem *spacer1;
    QVBoxLayout *vboxLayout;
    QLabel *LabelInfoDescription;
    QHBoxLayout *hboxLayout1;
    QLabel *LabelVersion;
    QLabel *LabelInfoVersion;
    QLabel *LabelInfoWebSite;
    QVBoxLayout *vboxLayout1;
    QGroupBox *GroupBoxApplication;
    QHBoxLayout *hboxLayout2;
    QRadioButton *RadioButtonAppVOIP;
    QRadioButton *RadioButtonAppAudio;
    QGroupBox *GroupBoxSignal;
    QHBoxLayout *hboxLayout3;
    QRadioButton *RadioButtonSignalVoice;
    QRadioButton *RadioButtonSignalMusic;
    QGroupBox *GroupBoxFEC;
    QHBoxLayout *hboxLayout4;
    QRadioButton *RadioButtonFECOff;
    QRadioButton *RadioButtonFECOn;
    QVBoxLayout *vboxLayout2;
    QGroupBox *GroupBoxChannels;
    QHBoxLayout *hboxLayout5;
    QRadioButton *RadioButtonChannelsMono;
    QRadioButton *RadioButtonChannelsStereo;
    QGroupBox *GroupBoxBandwidth;
    QVBoxLayout *vboxLayout3;
    QRadioButton *RadioButtonBandwidthNB;
    QRadioButton *RadioButtonBandwidthMB;
    QRadioButton *RadioButtonBandwidthWB;
    QRadioButton *RadioButtonBandwidthSWB;
    QRadioButton *RadioButtonBandwidthFB;
    QButtonGroup *ButtonGroupChannels;
    QButtonGroup *ButtonGroupSignal;
    QButtonGroup *ButtonGroupFEC;
    QButtonGroup *ButtonGroupBandwidth;
    QButtonGroup *ButtonGroupApplication;

    void setupUi(QDialog *OpusCodecParams)
    {
        if (OpusCodecParams->objectName().isEmpty())
            OpusCodecParams->setObjectName(QString::fromUtf8("OpusCodecParams"));
        OpusCodecParams->resize(447, 345);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OpusCodecParams->sizePolicy().hasHeightForWidth());
        OpusCodecParams->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/MainIconTx.svg"), QSize(), QIcon::Normal, QIcon::Off);
        OpusCodecParams->setWindowIcon(icon);
        gridLayout = new QGridLayout(OpusCodecParams);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        GroupBoxInfo = new QGroupBox(OpusCodecParams);
        GroupBoxInfo->setObjectName(QString::fromUtf8("GroupBoxInfo"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(GroupBoxInfo->sizePolicy().hasHeightForWidth());
        GroupBoxInfo->setSizePolicy(sizePolicy1);
        hboxLayout = new QHBoxLayout(GroupBoxInfo);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        Logo = new QLabel(GroupBoxInfo);
        Logo->setObjectName(QString::fromUtf8("Logo"));
        sizePolicy.setHeightForWidth(Logo->sizePolicy().hasHeightForWidth());
        Logo->setSizePolicy(sizePolicy);
        Logo->setPixmap(QPixmap(QString::fromUtf8(":/icons/LogoOpus.png")));
        Logo->setScaledContents(false);
        Logo->setWordWrap(false);

        hboxLayout->addWidget(Logo);

        spacer1 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer1);

        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(0);
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        LabelInfoDescription = new QLabel(GroupBoxInfo);
        LabelInfoDescription->setObjectName(QString::fromUtf8("LabelInfoDescription"));
        sizePolicy1.setHeightForWidth(LabelInfoDescription->sizePolicy().hasHeightForWidth());
        LabelInfoDescription->setSizePolicy(sizePolicy1);
        LabelInfoDescription->setWordWrap(false);

        vboxLayout->addWidget(LabelInfoDescription);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(0);
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        LabelVersion = new QLabel(GroupBoxInfo);
        LabelVersion->setObjectName(QString::fromUtf8("LabelVersion"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(LabelVersion->sizePolicy().hasHeightForWidth());
        LabelVersion->setSizePolicy(sizePolicy2);
        LabelVersion->setAlignment(Qt::AlignVCenter);
        LabelVersion->setWordWrap(false);

        hboxLayout1->addWidget(LabelVersion);

        LabelInfoVersion = new QLabel(GroupBoxInfo);
        LabelInfoVersion->setObjectName(QString::fromUtf8("LabelInfoVersion"));
        sizePolicy1.setHeightForWidth(LabelInfoVersion->sizePolicy().hasHeightForWidth());
        LabelInfoVersion->setSizePolicy(sizePolicy1);
        LabelInfoVersion->setWordWrap(false);

        hboxLayout1->addWidget(LabelInfoVersion);


        vboxLayout->addLayout(hboxLayout1);

        LabelInfoWebSite = new QLabel(GroupBoxInfo);
        LabelInfoWebSite->setObjectName(QString::fromUtf8("LabelInfoWebSite"));
        sizePolicy1.setHeightForWidth(LabelInfoWebSite->sizePolicy().hasHeightForWidth());
        LabelInfoWebSite->setSizePolicy(sizePolicy1);
        LabelInfoWebSite->setAcceptDrops(false);
        LabelInfoWebSite->setWordWrap(false);
        LabelInfoWebSite->setOpenExternalLinks(true);
        LabelInfoWebSite->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        vboxLayout->addWidget(LabelInfoWebSite);


        hboxLayout->addLayout(vboxLayout);


        gridLayout->addWidget(GroupBoxInfo, 0, 0, 1, 2);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        GroupBoxApplication = new QGroupBox(OpusCodecParams);
        GroupBoxApplication->setObjectName(QString::fromUtf8("GroupBoxApplication"));
        sizePolicy2.setHeightForWidth(GroupBoxApplication->sizePolicy().hasHeightForWidth());
        GroupBoxApplication->setSizePolicy(sizePolicy2);
        hboxLayout2 = new QHBoxLayout(GroupBoxApplication);
        hboxLayout2->setSpacing(6);
        hboxLayout2->setContentsMargins(11, 11, 11, 11);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        RadioButtonAppVOIP = new QRadioButton(GroupBoxApplication);
        ButtonGroupApplication = new QButtonGroup(OpusCodecParams);
        ButtonGroupApplication->setObjectName(QString::fromUtf8("ButtonGroupApplication"));
        ButtonGroupApplication->addButton(RadioButtonAppVOIP);
        RadioButtonAppVOIP->setObjectName(QString::fromUtf8("RadioButtonAppVOIP"));
        sizePolicy2.setHeightForWidth(RadioButtonAppVOIP->sizePolicy().hasHeightForWidth());
        RadioButtonAppVOIP->setSizePolicy(sizePolicy2);

        hboxLayout2->addWidget(RadioButtonAppVOIP);

        RadioButtonAppAudio = new QRadioButton(GroupBoxApplication);
        ButtonGroupApplication->addButton(RadioButtonAppAudio);
        RadioButtonAppAudio->setObjectName(QString::fromUtf8("RadioButtonAppAudio"));
        sizePolicy2.setHeightForWidth(RadioButtonAppAudio->sizePolicy().hasHeightForWidth());
        RadioButtonAppAudio->setSizePolicy(sizePolicy2);

        hboxLayout2->addWidget(RadioButtonAppAudio);


        vboxLayout1->addWidget(GroupBoxApplication);

        GroupBoxSignal = new QGroupBox(OpusCodecParams);
        GroupBoxSignal->setObjectName(QString::fromUtf8("GroupBoxSignal"));
        sizePolicy2.setHeightForWidth(GroupBoxSignal->sizePolicy().hasHeightForWidth());
        GroupBoxSignal->setSizePolicy(sizePolicy2);
        hboxLayout3 = new QHBoxLayout(GroupBoxSignal);
        hboxLayout3->setSpacing(6);
        hboxLayout3->setContentsMargins(11, 11, 11, 11);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        RadioButtonSignalVoice = new QRadioButton(GroupBoxSignal);
        ButtonGroupSignal = new QButtonGroup(OpusCodecParams);
        ButtonGroupSignal->setObjectName(QString::fromUtf8("ButtonGroupSignal"));
        ButtonGroupSignal->addButton(RadioButtonSignalVoice);
        RadioButtonSignalVoice->setObjectName(QString::fromUtf8("RadioButtonSignalVoice"));
        sizePolicy2.setHeightForWidth(RadioButtonSignalVoice->sizePolicy().hasHeightForWidth());
        RadioButtonSignalVoice->setSizePolicy(sizePolicy2);

        hboxLayout3->addWidget(RadioButtonSignalVoice);

        RadioButtonSignalMusic = new QRadioButton(GroupBoxSignal);
        ButtonGroupSignal->addButton(RadioButtonSignalMusic);
        RadioButtonSignalMusic->setObjectName(QString::fromUtf8("RadioButtonSignalMusic"));
        sizePolicy2.setHeightForWidth(RadioButtonSignalMusic->sizePolicy().hasHeightForWidth());
        RadioButtonSignalMusic->setSizePolicy(sizePolicy2);

        hboxLayout3->addWidget(RadioButtonSignalMusic);


        vboxLayout1->addWidget(GroupBoxSignal);

        GroupBoxFEC = new QGroupBox(OpusCodecParams);
        GroupBoxFEC->setObjectName(QString::fromUtf8("GroupBoxFEC"));
        sizePolicy2.setHeightForWidth(GroupBoxFEC->sizePolicy().hasHeightForWidth());
        GroupBoxFEC->setSizePolicy(sizePolicy2);
        hboxLayout4 = new QHBoxLayout(GroupBoxFEC);
        hboxLayout4->setSpacing(6);
        hboxLayout4->setContentsMargins(11, 11, 11, 11);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        RadioButtonFECOff = new QRadioButton(GroupBoxFEC);
        ButtonGroupFEC = new QButtonGroup(OpusCodecParams);
        ButtonGroupFEC->setObjectName(QString::fromUtf8("ButtonGroupFEC"));
        ButtonGroupFEC->addButton(RadioButtonFECOff);
        RadioButtonFECOff->setObjectName(QString::fromUtf8("RadioButtonFECOff"));
        sizePolicy2.setHeightForWidth(RadioButtonFECOff->sizePolicy().hasHeightForWidth());
        RadioButtonFECOff->setSizePolicy(sizePolicy2);

        hboxLayout4->addWidget(RadioButtonFECOff);

        RadioButtonFECOn = new QRadioButton(GroupBoxFEC);
        ButtonGroupFEC->addButton(RadioButtonFECOn);
        RadioButtonFECOn->setObjectName(QString::fromUtf8("RadioButtonFECOn"));
        sizePolicy2.setHeightForWidth(RadioButtonFECOn->sizePolicy().hasHeightForWidth());
        RadioButtonFECOn->setSizePolicy(sizePolicy2);

        hboxLayout4->addWidget(RadioButtonFECOn);


        vboxLayout1->addWidget(GroupBoxFEC);


        gridLayout->addLayout(vboxLayout1, 1, 1, 1, 1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(6);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        GroupBoxChannels = new QGroupBox(OpusCodecParams);
        GroupBoxChannels->setObjectName(QString::fromUtf8("GroupBoxChannels"));
        sizePolicy2.setHeightForWidth(GroupBoxChannels->sizePolicy().hasHeightForWidth());
        GroupBoxChannels->setSizePolicy(sizePolicy2);
        hboxLayout5 = new QHBoxLayout(GroupBoxChannels);
        hboxLayout5->setSpacing(6);
        hboxLayout5->setContentsMargins(11, 11, 11, 11);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        RadioButtonChannelsMono = new QRadioButton(GroupBoxChannels);
        ButtonGroupChannels = new QButtonGroup(OpusCodecParams);
        ButtonGroupChannels->setObjectName(QString::fromUtf8("ButtonGroupChannels"));
        ButtonGroupChannels->addButton(RadioButtonChannelsMono);
        RadioButtonChannelsMono->setObjectName(QString::fromUtf8("RadioButtonChannelsMono"));
        sizePolicy2.setHeightForWidth(RadioButtonChannelsMono->sizePolicy().hasHeightForWidth());
        RadioButtonChannelsMono->setSizePolicy(sizePolicy2);

        hboxLayout5->addWidget(RadioButtonChannelsMono);

        RadioButtonChannelsStereo = new QRadioButton(GroupBoxChannels);
        ButtonGroupChannels->addButton(RadioButtonChannelsStereo);
        RadioButtonChannelsStereo->setObjectName(QString::fromUtf8("RadioButtonChannelsStereo"));
        sizePolicy2.setHeightForWidth(RadioButtonChannelsStereo->sizePolicy().hasHeightForWidth());
        RadioButtonChannelsStereo->setSizePolicy(sizePolicy2);

        hboxLayout5->addWidget(RadioButtonChannelsStereo);


        vboxLayout2->addWidget(GroupBoxChannels);

        GroupBoxBandwidth = new QGroupBox(OpusCodecParams);
        GroupBoxBandwidth->setObjectName(QString::fromUtf8("GroupBoxBandwidth"));
        sizePolicy2.setHeightForWidth(GroupBoxBandwidth->sizePolicy().hasHeightForWidth());
        GroupBoxBandwidth->setSizePolicy(sizePolicy2);
        vboxLayout3 = new QVBoxLayout(GroupBoxBandwidth);
        vboxLayout3->setSpacing(6);
        vboxLayout3->setContentsMargins(11, 11, 11, 11);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        RadioButtonBandwidthNB = new QRadioButton(GroupBoxBandwidth);
        ButtonGroupBandwidth = new QButtonGroup(OpusCodecParams);
        ButtonGroupBandwidth->setObjectName(QString::fromUtf8("ButtonGroupBandwidth"));
        ButtonGroupBandwidth->addButton(RadioButtonBandwidthNB);
        RadioButtonBandwidthNB->setObjectName(QString::fromUtf8("RadioButtonBandwidthNB"));
        sizePolicy2.setHeightForWidth(RadioButtonBandwidthNB->sizePolicy().hasHeightForWidth());
        RadioButtonBandwidthNB->setSizePolicy(sizePolicy2);

        vboxLayout3->addWidget(RadioButtonBandwidthNB);

        RadioButtonBandwidthMB = new QRadioButton(GroupBoxBandwidth);
        ButtonGroupBandwidth->addButton(RadioButtonBandwidthMB);
        RadioButtonBandwidthMB->setObjectName(QString::fromUtf8("RadioButtonBandwidthMB"));
        sizePolicy2.setHeightForWidth(RadioButtonBandwidthMB->sizePolicy().hasHeightForWidth());
        RadioButtonBandwidthMB->setSizePolicy(sizePolicy2);

        vboxLayout3->addWidget(RadioButtonBandwidthMB);

        RadioButtonBandwidthWB = new QRadioButton(GroupBoxBandwidth);
        ButtonGroupBandwidth->addButton(RadioButtonBandwidthWB);
        RadioButtonBandwidthWB->setObjectName(QString::fromUtf8("RadioButtonBandwidthWB"));
        sizePolicy2.setHeightForWidth(RadioButtonBandwidthWB->sizePolicy().hasHeightForWidth());
        RadioButtonBandwidthWB->setSizePolicy(sizePolicy2);

        vboxLayout3->addWidget(RadioButtonBandwidthWB);

        RadioButtonBandwidthSWB = new QRadioButton(GroupBoxBandwidth);
        ButtonGroupBandwidth->addButton(RadioButtonBandwidthSWB);
        RadioButtonBandwidthSWB->setObjectName(QString::fromUtf8("RadioButtonBandwidthSWB"));
        sizePolicy2.setHeightForWidth(RadioButtonBandwidthSWB->sizePolicy().hasHeightForWidth());
        RadioButtonBandwidthSWB->setSizePolicy(sizePolicy2);

        vboxLayout3->addWidget(RadioButtonBandwidthSWB);

        RadioButtonBandwidthFB = new QRadioButton(GroupBoxBandwidth);
        ButtonGroupBandwidth->addButton(RadioButtonBandwidthFB);
        RadioButtonBandwidthFB->setObjectName(QString::fromUtf8("RadioButtonBandwidthFB"));
        sizePolicy.setHeightForWidth(RadioButtonBandwidthFB->sizePolicy().hasHeightForWidth());
        RadioButtonBandwidthFB->setSizePolicy(sizePolicy);

        vboxLayout3->addWidget(RadioButtonBandwidthFB);


        vboxLayout2->addWidget(GroupBoxBandwidth);


        gridLayout->addLayout(vboxLayout2, 1, 0, 1, 1);

        QWidget::setTabOrder(RadioButtonChannelsMono, RadioButtonChannelsStereo);
        QWidget::setTabOrder(RadioButtonChannelsStereo, RadioButtonBandwidthNB);
        QWidget::setTabOrder(RadioButtonBandwidthNB, RadioButtonBandwidthMB);
        QWidget::setTabOrder(RadioButtonBandwidthMB, RadioButtonBandwidthWB);
        QWidget::setTabOrder(RadioButtonBandwidthWB, RadioButtonBandwidthSWB);
        QWidget::setTabOrder(RadioButtonBandwidthSWB, RadioButtonBandwidthFB);
        QWidget::setTabOrder(RadioButtonBandwidthFB, RadioButtonAppVOIP);
        QWidget::setTabOrder(RadioButtonAppVOIP, RadioButtonAppAudio);
        QWidget::setTabOrder(RadioButtonAppAudio, RadioButtonSignalVoice);
        QWidget::setTabOrder(RadioButtonSignalVoice, RadioButtonSignalMusic);
        QWidget::setTabOrder(RadioButtonSignalMusic, RadioButtonFECOff);
        QWidget::setTabOrder(RadioButtonFECOff, RadioButtonFECOn);

        retranslateUi(OpusCodecParams);

        QMetaObject::connectSlotsByName(OpusCodecParams);
    } // setupUi

    void retranslateUi(QDialog *OpusCodecParams)
    {
        OpusCodecParams->setWindowTitle(QCoreApplication::translate("OpusCodecParams", "Codec Parameters", nullptr));
        GroupBoxInfo->setTitle(QCoreApplication::translate("OpusCodecParams", "Codec Information", nullptr));
        LabelInfoDescription->setText(QCoreApplication::translate("OpusCodecParams", "Description", nullptr));
        LabelVersion->setText(QCoreApplication::translate("OpusCodecParams", "Version: ", nullptr));
        LabelInfoVersion->setText(QCoreApplication::translate("OpusCodecParams", "_ver_", nullptr));
        LabelInfoWebSite->setText(QCoreApplication::translate("OpusCodecParams", "Website", nullptr));
        GroupBoxApplication->setTitle(QCoreApplication::translate("OpusCodecParams", "Application", nullptr));
        RadioButtonAppVOIP->setText(QCoreApplication::translate("OpusCodecParams", "VoIP", nullptr));
        RadioButtonAppAudio->setText(QCoreApplication::translate("OpusCodecParams", "Audio", nullptr));
        GroupBoxSignal->setTitle(QCoreApplication::translate("OpusCodecParams", "Signal", nullptr));
        RadioButtonSignalVoice->setText(QCoreApplication::translate("OpusCodecParams", "Voice", nullptr));
        RadioButtonSignalMusic->setText(QCoreApplication::translate("OpusCodecParams", "Music", nullptr));
        GroupBoxFEC->setTitle(QCoreApplication::translate("OpusCodecParams", "Forward Error Correction", nullptr));
        RadioButtonFECOff->setText(QCoreApplication::translate("OpusCodecParams", "Off", nullptr));
        RadioButtonFECOn->setText(QCoreApplication::translate("OpusCodecParams", "On", nullptr));
        GroupBoxChannels->setTitle(QCoreApplication::translate("OpusCodecParams", "Channels", nullptr));
        RadioButtonChannelsMono->setText(QCoreApplication::translate("OpusCodecParams", "Mono", nullptr));
        RadioButtonChannelsStereo->setText(QCoreApplication::translate("OpusCodecParams", "Stereo", nullptr));
        GroupBoxBandwidth->setTitle(QCoreApplication::translate("OpusCodecParams", "Bandwidth", nullptr));
        RadioButtonBandwidthNB->setText(QCoreApplication::translate("OpusCodecParams", "Narrow Band (4 kHz)", nullptr));
        RadioButtonBandwidthMB->setText(QCoreApplication::translate("OpusCodecParams", "Medium Band (6 kHz)", nullptr));
        RadioButtonBandwidthWB->setText(QCoreApplication::translate("OpusCodecParams", "Wide Band (8 kHz)", nullptr));
        RadioButtonBandwidthSWB->setText(QCoreApplication::translate("OpusCodecParams", "Super Wide Band (12 kHz)", nullptr));
        RadioButtonBandwidthFB->setText(QCoreApplication::translate("OpusCodecParams", "Full Band (20 kHz)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpusCodecParams: public Ui_OpusCodecParams {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPUSCODECPARAMS_H
