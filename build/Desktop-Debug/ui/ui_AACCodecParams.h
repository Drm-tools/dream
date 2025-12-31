/********************************************************************************
** Form generated from reading UI file 'AACCodecParams.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AACCODECPARAMS_H
#define UI_AACCODECPARAMS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AACCodecParams
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
    QGroupBox *GroupBoxChannels;
    QHBoxLayout *horizontalLayout;
    QRadioButton *RadioButtonChannelsMono;
    QRadioButton *RadioButtonChannelsParametricStereo;
    QRadioButton *RadioButtonChannelsStereo;
    QRadioButton *RadioButtonChannelsSurround;
    QGroupBox *GroupBoxSampleRate;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *RadioButton12kHz;
    QRadioButton *RadioButton24kHz;
    QGroupBox *GroupBoxOptions;
    QVBoxLayout *verticalLayout;
    QCheckBox *CheckBoxSBR;
    QButtonGroup *ButtonGroupChannels;
    QButtonGroup *ButtonGroupSampleRate;

    void setupUi(QDialog *AACCodecParams)
    {
        if (AACCodecParams->objectName().isEmpty())
            AACCodecParams->setObjectName(QString::fromUtf8("AACCodecParams"));
        AACCodecParams->resize(550, 436);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AACCodecParams->sizePolicy().hasHeightForWidth());
        AACCodecParams->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/MainIconTx.svg"), QSize(), QIcon::Normal, QIcon::Off);
        AACCodecParams->setWindowIcon(icon);
        gridLayout = new QGridLayout(AACCodecParams);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        GroupBoxInfo = new QGroupBox(AACCodecParams);
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
        Logo->setPixmap(QPixmap(QString::fromUtf8(":/icons/aac.png")));
        Logo->setScaledContents(true);
        Logo->setWordWrap(false);

        hboxLayout->addWidget(Logo);

        spacer1 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout->addItem(spacer1);

        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        LabelInfoDescription = new QLabel(GroupBoxInfo);
        LabelInfoDescription->setObjectName(QString::fromUtf8("LabelInfoDescription"));
        sizePolicy1.setHeightForWidth(LabelInfoDescription->sizePolicy().hasHeightForWidth());
        LabelInfoDescription->setSizePolicy(sizePolicy1);
        LabelInfoDescription->setWordWrap(false);

        vboxLayout->addWidget(LabelInfoDescription);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(0);
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

        GroupBoxChannels = new QGroupBox(AACCodecParams);
        GroupBoxChannels->setObjectName(QString::fromUtf8("GroupBoxChannels"));
        sizePolicy2.setHeightForWidth(GroupBoxChannels->sizePolicy().hasHeightForWidth());
        GroupBoxChannels->setSizePolicy(sizePolicy2);
        horizontalLayout = new QHBoxLayout(GroupBoxChannels);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        RadioButtonChannelsMono = new QRadioButton(GroupBoxChannels);
        ButtonGroupChannels = new QButtonGroup(AACCodecParams);
        ButtonGroupChannels->setObjectName(QString::fromUtf8("ButtonGroupChannels"));
        ButtonGroupChannels->addButton(RadioButtonChannelsMono);
        RadioButtonChannelsMono->setObjectName(QString::fromUtf8("RadioButtonChannelsMono"));
        sizePolicy2.setHeightForWidth(RadioButtonChannelsMono->sizePolicy().hasHeightForWidth());
        RadioButtonChannelsMono->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(RadioButtonChannelsMono);

        RadioButtonChannelsParametricStereo = new QRadioButton(GroupBoxChannels);
        RadioButtonChannelsParametricStereo->setObjectName(QString::fromUtf8("RadioButtonChannelsParametricStereo"));

        horizontalLayout->addWidget(RadioButtonChannelsParametricStereo);

        RadioButtonChannelsStereo = new QRadioButton(GroupBoxChannels);
        ButtonGroupChannels->addButton(RadioButtonChannelsStereo);
        RadioButtonChannelsStereo->setObjectName(QString::fromUtf8("RadioButtonChannelsStereo"));
        sizePolicy2.setHeightForWidth(RadioButtonChannelsStereo->sizePolicy().hasHeightForWidth());
        RadioButtonChannelsStereo->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(RadioButtonChannelsStereo);

        RadioButtonChannelsSurround = new QRadioButton(GroupBoxChannels);
        RadioButtonChannelsSurround->setObjectName(QString::fromUtf8("RadioButtonChannelsSurround"));

        horizontalLayout->addWidget(RadioButtonChannelsSurround);


        gridLayout->addWidget(GroupBoxChannels, 1, 0, 1, 2);

        GroupBoxSampleRate = new QGroupBox(AACCodecParams);
        GroupBoxSampleRate->setObjectName(QString::fromUtf8("GroupBoxSampleRate"));
        sizePolicy2.setHeightForWidth(GroupBoxSampleRate->sizePolicy().hasHeightForWidth());
        GroupBoxSampleRate->setSizePolicy(sizePolicy2);
        verticalLayout_2 = new QVBoxLayout(GroupBoxSampleRate);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        RadioButton12kHz = new QRadioButton(GroupBoxSampleRate);
        ButtonGroupSampleRate = new QButtonGroup(AACCodecParams);
        ButtonGroupSampleRate->setObjectName(QString::fromUtf8("ButtonGroupSampleRate"));
        ButtonGroupSampleRate->addButton(RadioButton12kHz);
        RadioButton12kHz->setObjectName(QString::fromUtf8("RadioButton12kHz"));
        sizePolicy.setHeightForWidth(RadioButton12kHz->sizePolicy().hasHeightForWidth());
        RadioButton12kHz->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(RadioButton12kHz);

        RadioButton24kHz = new QRadioButton(GroupBoxSampleRate);
        ButtonGroupSampleRate->addButton(RadioButton24kHz);
        RadioButton24kHz->setObjectName(QString::fromUtf8("RadioButton24kHz"));
        sizePolicy2.setHeightForWidth(RadioButton24kHz->sizePolicy().hasHeightForWidth());
        RadioButton24kHz->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(RadioButton24kHz);


        gridLayout->addWidget(GroupBoxSampleRate, 2, 0, 1, 1);

        GroupBoxOptions = new QGroupBox(AACCodecParams);
        GroupBoxOptions->setObjectName(QString::fromUtf8("GroupBoxOptions"));
        verticalLayout = new QVBoxLayout(GroupBoxOptions);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        CheckBoxSBR = new QCheckBox(GroupBoxOptions);
        CheckBoxSBR->setObjectName(QString::fromUtf8("CheckBoxSBR"));

        verticalLayout->addWidget(CheckBoxSBR);


        gridLayout->addWidget(GroupBoxOptions, 2, 1, 1, 1);

        QWidget::setTabOrder(RadioButtonChannelsMono, RadioButtonChannelsStereo);
        QWidget::setTabOrder(RadioButtonChannelsStereo, RadioButton24kHz);
        QWidget::setTabOrder(RadioButton24kHz, RadioButton12kHz);

        retranslateUi(AACCodecParams);

        QMetaObject::connectSlotsByName(AACCodecParams);
    } // setupUi

    void retranslateUi(QDialog *AACCodecParams)
    {
        AACCodecParams->setWindowTitle(QCoreApplication::translate("AACCodecParams", "Codec Parameters", nullptr));
        GroupBoxInfo->setTitle(QCoreApplication::translate("AACCodecParams", "Codec Information", nullptr));
        LabelInfoDescription->setText(QCoreApplication::translate("AACCodecParams", "Description", nullptr));
        LabelVersion->setText(QCoreApplication::translate("AACCodecParams", "Version: ", nullptr));
        LabelInfoVersion->setText(QCoreApplication::translate("AACCodecParams", "_ver_", nullptr));
        LabelInfoWebSite->setText(QCoreApplication::translate("AACCodecParams", "Website", nullptr));
        GroupBoxChannels->setTitle(QCoreApplication::translate("AACCodecParams", "Channels", nullptr));
        RadioButtonChannelsMono->setText(QCoreApplication::translate("AACCodecParams", "Mono", nullptr));
        RadioButtonChannelsParametricStereo->setText(QCoreApplication::translate("AACCodecParams", "Parametric Stereo", nullptr));
        RadioButtonChannelsStereo->setText(QCoreApplication::translate("AACCodecParams", "Stereo", nullptr));
        RadioButtonChannelsSurround->setText(QCoreApplication::translate("AACCodecParams", "Surround", nullptr));
        GroupBoxSampleRate->setTitle(QCoreApplication::translate("AACCodecParams", "Sample Rate", nullptr));
        RadioButton12kHz->setText(QCoreApplication::translate("AACCodecParams", "12 kHz", nullptr));
        RadioButton24kHz->setText(QCoreApplication::translate("AACCodecParams", "24 kHz", nullptr));
        GroupBoxOptions->setTitle(QCoreApplication::translate("AACCodecParams", "Options", nullptr));
        CheckBoxSBR->setText(QCoreApplication::translate("AACCodecParams", "SBR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AACCodecParams: public Ui_AACCodecParams {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AACCODECPARAMS_H
