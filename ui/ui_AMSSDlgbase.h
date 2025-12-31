/********************************************************************************
** Form generated from reading UI file 'AMSSDlgbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AMSSDLGBASE_H
#define UI_AMSSDLGBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qwt_dial.h"

QT_BEGIN_NAMESPACE

class Ui_CAMSSDlgBase
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *GroupBoxAMSS;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QFrame *FrameMainDisplay;
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout1;
    QLabel *TextAMSSAMCarrierMode;
    QLabel *TextAMSSInfo;
    QLabel *TextAMSSServiceID;
    QHBoxLayout *hboxLayout2;
    QLabel *TextAMSSLanguage;
    QLabel *TextAMSSCountryCode;
    QLabel *TextAMSSTimeDate;
    QLabel *TextAMSSServiceLabel;
    QHBoxLayout *hboxLayout3;
    QHBoxLayout *hboxLayout4;
    QLabel *TextLabelCurrentBlock;
    QLabel *TextCurrentBlock;
    QSpacerItem *Spacer10;
    QHBoxLayout *hboxLayout5;
    QLabel *TextLabelBlockBits;
    QLabel *TextBlockBits;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout6;
    QLabel *TextLabelStaticSDCPercentage;
    QProgressBar *ProgressBarAMSS;
    QLabel *TextDataEntityGroupStatus;
    QHBoxLayout *hboxLayout7;
    QLabel *TextLabelAMSSAFSList;
    QListWidget *ListBoxAMSSAFSList;
    QVBoxLayout *vboxLayout2;
    QLabel *TextLabelPhaseOffsetAMSS;
    QwtDial *PhaseDialAMSS;

    void setupUi(QMainWindow *CAMSSDlgBase)
    {
        if (CAMSSDlgBase->objectName().isEmpty())
            CAMSSDlgBase->setObjectName(QString::fromUtf8("CAMSSDlgBase"));
        CAMSSDlgBase->resize(724, 305);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CAMSSDlgBase->sizePolicy().hasHeightForWidth());
        CAMSSDlgBase->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/MainIcon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        CAMSSDlgBase->setWindowIcon(icon);
        centralwidget = new QWidget(CAMSSDlgBase);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        GroupBoxAMSS = new QGroupBox(centralwidget);
        GroupBoxAMSS->setObjectName(QString::fromUtf8("GroupBoxAMSS"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(GroupBoxAMSS->sizePolicy().hasHeightForWidth());
        GroupBoxAMSS->setSizePolicy(sizePolicy1);
        hboxLayout = new QHBoxLayout(GroupBoxAMSS);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(3);
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        FrameMainDisplay = new QFrame(GroupBoxAMSS);
        FrameMainDisplay->setObjectName(QString::fromUtf8("FrameMainDisplay"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(FrameMainDisplay->sizePolicy().hasHeightForWidth());
        FrameMainDisplay->setSizePolicy(sizePolicy2);
        FrameMainDisplay->setMinimumSize(QSize(380, 0));
        FrameMainDisplay->setMaximumSize(QSize(32767, 32767));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(169, 134, 107, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(253, 200, 160, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(211, 167, 133, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(84, 66, 53, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(112, 89, 71, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(0, 0, 128, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        QBrush brush8(QColor(194, 153, 122, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush6);
        QBrush brush9(QColor(128, 128, 128, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush6);
        FrameMainDisplay->setPalette(palette);
        FrameMainDisplay->setAutoFillBackground(true);
        FrameMainDisplay->setFrameShape(QFrame::StyledPanel);
        FrameMainDisplay->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(FrameMainDisplay);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(6, 6, 6, 6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        TextAMSSAMCarrierMode = new QLabel(FrameMainDisplay);
        TextAMSSAMCarrierMode->setObjectName(QString::fromUtf8("TextAMSSAMCarrierMode"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(TextAMSSAMCarrierMode->sizePolicy().hasHeightForWidth());
        TextAMSSAMCarrierMode->setSizePolicy(sizePolicy3);
        QPalette palette1;
        QBrush brush10(QColor(255, 0, 0, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush10);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush6);
        TextAMSSAMCarrierMode->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        TextAMSSAMCarrierMode->setFont(font);
        TextAMSSAMCarrierMode->setScaledContents(false);
        TextAMSSAMCarrierMode->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        TextAMSSAMCarrierMode->setWordWrap(false);

        hboxLayout1->addWidget(TextAMSSAMCarrierMode);

        TextAMSSInfo = new QLabel(FrameMainDisplay);
        TextAMSSInfo->setObjectName(QString::fromUtf8("TextAMSSInfo"));
        sizePolicy3.setHeightForWidth(TextAMSSInfo->sizePolicy().hasHeightForWidth());
        TextAMSSInfo->setSizePolicy(sizePolicy3);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush10);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        palette2.setBrush(QPalette::Active, QPalette::HighlightedText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush6);
        TextAMSSInfo->setPalette(palette2);
        TextAMSSInfo->setFont(font);
        TextAMSSInfo->setScaledContents(false);
        TextAMSSInfo->setAlignment(Qt::AlignCenter);
        TextAMSSInfo->setWordWrap(false);

        hboxLayout1->addWidget(TextAMSSInfo);

        TextAMSSServiceID = new QLabel(FrameMainDisplay);
        TextAMSSServiceID->setObjectName(QString::fromUtf8("TextAMSSServiceID"));
        sizePolicy3.setHeightForWidth(TextAMSSServiceID->sizePolicy().hasHeightForWidth());
        TextAMSSServiceID->setSizePolicy(sizePolicy3);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush10);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        palette3.setBrush(QPalette::Active, QPalette::HighlightedText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Highlight, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush6);
        TextAMSSServiceID->setPalette(palette3);
        TextAMSSServiceID->setFont(font);
        TextAMSSServiceID->setScaledContents(false);
        TextAMSSServiceID->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        TextAMSSServiceID->setWordWrap(false);

        hboxLayout1->addWidget(TextAMSSServiceID);


        gridLayout->addLayout(hboxLayout1, 3, 0, 1, 1);

        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        TextAMSSLanguage = new QLabel(FrameMainDisplay);
        TextAMSSLanguage->setObjectName(QString::fromUtf8("TextAMSSLanguage"));
        sizePolicy3.setHeightForWidth(TextAMSSLanguage->sizePolicy().hasHeightForWidth());
        TextAMSSLanguage->setSizePolicy(sizePolicy3);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush10);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        palette4.setBrush(QPalette::Active, QPalette::HighlightedText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush10);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Highlight, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush6);
        TextAMSSLanguage->setPalette(palette4);
        TextAMSSLanguage->setFont(font);
        TextAMSSLanguage->setScaledContents(false);
        TextAMSSLanguage->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        TextAMSSLanguage->setWordWrap(false);

        hboxLayout2->addWidget(TextAMSSLanguage);

        TextAMSSCountryCode = new QLabel(FrameMainDisplay);
        TextAMSSCountryCode->setObjectName(QString::fromUtf8("TextAMSSCountryCode"));
        sizePolicy3.setHeightForWidth(TextAMSSCountryCode->sizePolicy().hasHeightForWidth());
        TextAMSSCountryCode->setSizePolicy(sizePolicy3);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush10);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        palette5.setBrush(QPalette::Active, QPalette::HighlightedText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush10);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Highlight, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush6);
        TextAMSSCountryCode->setPalette(palette5);
        TextAMSSCountryCode->setFont(font);
        TextAMSSCountryCode->setScaledContents(false);
        TextAMSSCountryCode->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        TextAMSSCountryCode->setWordWrap(false);

        hboxLayout2->addWidget(TextAMSSCountryCode);


        gridLayout->addLayout(hboxLayout2, 2, 0, 1, 1);

        TextAMSSTimeDate = new QLabel(FrameMainDisplay);
        TextAMSSTimeDate->setObjectName(QString::fromUtf8("TextAMSSTimeDate"));
        sizePolicy3.setHeightForWidth(TextAMSSTimeDate->sizePolicy().hasHeightForWidth());
        TextAMSSTimeDate->setSizePolicy(sizePolicy3);
        QPalette palette6;
        QBrush brush11(QColor(170, 170, 127, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush11);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        palette6.setBrush(QPalette::Active, QPalette::HighlightedText, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush11);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Highlight, brush7);
        palette6.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        palette6.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush6);
        TextAMSSTimeDate->setPalette(palette6);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setBold(true);
        font1.setWeight(75);
        TextAMSSTimeDate->setFont(font1);
        TextAMSSTimeDate->setScaledContents(false);
        TextAMSSTimeDate->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        TextAMSSTimeDate->setWordWrap(false);

        gridLayout->addWidget(TextAMSSTimeDate, 0, 0, 1, 1);

        TextAMSSServiceLabel = new QLabel(FrameMainDisplay);
        TextAMSSServiceLabel->setObjectName(QString::fromUtf8("TextAMSSServiceLabel"));
        sizePolicy3.setHeightForWidth(TextAMSSServiceLabel->sizePolicy().hasHeightForWidth());
        TextAMSSServiceLabel->setSizePolicy(sizePolicy3);
        QPalette palette7;
        QBrush brush12(QColor(85, 255, 255, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        palette7.setBrush(QPalette::Active, QPalette::HighlightedText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush8);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Highlight, brush7);
        palette7.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush6);
        TextAMSSServiceLabel->setPalette(palette7);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        TextAMSSServiceLabel->setFont(font2);
        TextAMSSServiceLabel->setAlignment(Qt::AlignCenter);
        TextAMSSServiceLabel->setWordWrap(false);

        gridLayout->addWidget(TextAMSSServiceLabel, 1, 0, 1, 1);


        vboxLayout->addWidget(FrameMainDisplay);

        hboxLayout3 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout3->setSpacing(6);
#endif
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        hboxLayout4 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout4->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        TextLabelCurrentBlock = new QLabel(GroupBoxAMSS);
        TextLabelCurrentBlock->setObjectName(QString::fromUtf8("TextLabelCurrentBlock"));
        sizePolicy3.setHeightForWidth(TextLabelCurrentBlock->sizePolicy().hasHeightForWidth());
        TextLabelCurrentBlock->setSizePolicy(sizePolicy3);
        TextLabelCurrentBlock->setMinimumSize(QSize(0, 0));
        TextLabelCurrentBlock->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        TextLabelCurrentBlock->setWordWrap(false);

        hboxLayout4->addWidget(TextLabelCurrentBlock);

        TextCurrentBlock = new QLabel(GroupBoxAMSS);
        TextCurrentBlock->setObjectName(QString::fromUtf8("TextCurrentBlock"));
        TextCurrentBlock->setWordWrap(false);

        hboxLayout4->addWidget(TextCurrentBlock);


        hboxLayout3->addLayout(hboxLayout4);

        Spacer10 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        hboxLayout3->addItem(Spacer10);

        hboxLayout5 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout5->setSpacing(6);
#endif
        hboxLayout5->setContentsMargins(0, 0, 0, 0);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        TextLabelBlockBits = new QLabel(GroupBoxAMSS);
        TextLabelBlockBits->setObjectName(QString::fromUtf8("TextLabelBlockBits"));
        TextLabelBlockBits->setWordWrap(false);

        hboxLayout5->addWidget(TextLabelBlockBits);

        TextBlockBits = new QLabel(GroupBoxAMSS);
        TextBlockBits->setObjectName(QString::fromUtf8("TextBlockBits"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(TextBlockBits->sizePolicy().hasHeightForWidth());
        TextBlockBits->setSizePolicy(sizePolicy4);
        TextBlockBits->setScaledContents(false);
        TextBlockBits->setWordWrap(false);

        hboxLayout5->addWidget(TextBlockBits);


        hboxLayout3->addLayout(hboxLayout5);


        vboxLayout->addLayout(hboxLayout3);


        hboxLayout->addLayout(vboxLayout);

        vboxLayout1 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        hboxLayout6 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout6->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout6->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
        TextLabelStaticSDCPercentage = new QLabel(GroupBoxAMSS);
        TextLabelStaticSDCPercentage->setObjectName(QString::fromUtf8("TextLabelStaticSDCPercentage"));
        TextLabelStaticSDCPercentage->setEnabled(true);
        sizePolicy3.setHeightForWidth(TextLabelStaticSDCPercentage->sizePolicy().hasHeightForWidth());
        TextLabelStaticSDCPercentage->setSizePolicy(sizePolicy3);
        TextLabelStaticSDCPercentage->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        TextLabelStaticSDCPercentage->setWordWrap(false);

        hboxLayout6->addWidget(TextLabelStaticSDCPercentage);

        ProgressBarAMSS = new QProgressBar(GroupBoxAMSS);
        ProgressBarAMSS->setObjectName(QString::fromUtf8("ProgressBarAMSS"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(ProgressBarAMSS->sizePolicy().hasHeightForWidth());
        ProgressBarAMSS->setSizePolicy(sizePolicy5);
        ProgressBarAMSS->setMinimumSize(QSize(50, 0));
        ProgressBarAMSS->setMaximumSize(QSize(32767, 32767));

        hboxLayout6->addWidget(ProgressBarAMSS);

        TextDataEntityGroupStatus = new QLabel(GroupBoxAMSS);
        TextDataEntityGroupStatus->setObjectName(QString::fromUtf8("TextDataEntityGroupStatus"));
        sizePolicy3.setHeightForWidth(TextDataEntityGroupStatus->sizePolicy().hasHeightForWidth());
        TextDataEntityGroupStatus->setSizePolicy(sizePolicy3);
        TextDataEntityGroupStatus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        TextDataEntityGroupStatus->setWordWrap(false);

        hboxLayout6->addWidget(TextDataEntityGroupStatus);


        vboxLayout1->addLayout(hboxLayout6);

        hboxLayout7 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout7->setSpacing(6);
#endif
        hboxLayout7->setContentsMargins(0, 0, 0, 0);
        hboxLayout7->setObjectName(QString::fromUtf8("hboxLayout7"));
        TextLabelAMSSAFSList = new QLabel(GroupBoxAMSS);
        TextLabelAMSSAFSList->setObjectName(QString::fromUtf8("TextLabelAMSSAFSList"));
        sizePolicy2.setHeightForWidth(TextLabelAMSSAFSList->sizePolicy().hasHeightForWidth());
        TextLabelAMSSAFSList->setSizePolicy(sizePolicy2);
        TextLabelAMSSAFSList->setWordWrap(false);

        hboxLayout7->addWidget(TextLabelAMSSAFSList);

        ListBoxAMSSAFSList = new QListWidget(GroupBoxAMSS);
        ListBoxAMSSAFSList->setObjectName(QString::fromUtf8("ListBoxAMSSAFSList"));

        hboxLayout7->addWidget(ListBoxAMSSAFSList);


        vboxLayout1->addLayout(hboxLayout7);


        hboxLayout->addLayout(vboxLayout1);

        vboxLayout2 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout2->setSpacing(6);
#endif
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        TextLabelPhaseOffsetAMSS = new QLabel(GroupBoxAMSS);
        TextLabelPhaseOffsetAMSS->setObjectName(QString::fromUtf8("TextLabelPhaseOffsetAMSS"));
        TextLabelPhaseOffsetAMSS->setAlignment(Qt::AlignCenter);
        TextLabelPhaseOffsetAMSS->setWordWrap(false);

        vboxLayout2->addWidget(TextLabelPhaseOffsetAMSS);

        PhaseDialAMSS = new QwtDial(GroupBoxAMSS);
        PhaseDialAMSS->setObjectName(QString::fromUtf8("PhaseDialAMSS"));
        PhaseDialAMSS->setMinimumSize(QSize(0, 70));
        PhaseDialAMSS->setFocusPolicy(Qt::NoFocus);
        PhaseDialAMSS->setLineWidth(4);

        vboxLayout2->addWidget(PhaseDialAMSS);


        hboxLayout->addLayout(vboxLayout2);


        verticalLayout->addWidget(GroupBoxAMSS);

        CAMSSDlgBase->setCentralWidget(centralwidget);

        retranslateUi(CAMSSDlgBase);

        QMetaObject::connectSlotsByName(CAMSSDlgBase);
    } // setupUi

    void retranslateUi(QMainWindow *CAMSSDlgBase)
    {
        CAMSSDlgBase->setWindowTitle(QCoreApplication::translate("CAMSSDlgBase", "AMSS", nullptr));
        GroupBoxAMSS->setTitle(QCoreApplication::translate("CAMSSDlgBase", "AMSS Decoding", nullptr));
        TextAMSSAMCarrierMode->setText(QCoreApplication::translate("CAMSSDlgBase", "AMSSAMCarrierMode", nullptr));
        TextAMSSInfo->setText(QCoreApplication::translate("CAMSSDlgBase", "AMSSInfo", nullptr));
        TextAMSSServiceID->setText(QCoreApplication::translate("CAMSSDlgBase", "AMSSServiceID", nullptr));
        TextAMSSLanguage->setText(QCoreApplication::translate("CAMSSDlgBase", "AMSSLanguage", nullptr));
        TextAMSSCountryCode->setText(QCoreApplication::translate("CAMSSDlgBase", "AMSSCountryCode", nullptr));
        TextAMSSTimeDate->setText(QCoreApplication::translate("CAMSSDlgBase", "AMSSTimeDate", nullptr));
        TextAMSSServiceLabel->setText(QCoreApplication::translate("CAMSSDlgBase", "ServiceLabelAMSS", nullptr));
        TextLabelCurrentBlock->setText(QCoreApplication::translate("CAMSSDlgBase", "Block:", nullptr));
        TextCurrentBlock->setText(QString());
        TextLabelBlockBits->setText(QCoreApplication::translate("CAMSSDlgBase", "Bits:", nullptr));
        TextBlockBits->setText(QString());
        TextLabelStaticSDCPercentage->setText(QCoreApplication::translate("CAMSSDlgBase", "SDC:  ", nullptr));
        TextDataEntityGroupStatus->setText(QCoreApplication::translate("CAMSSDlgBase", "................", nullptr));
        TextLabelAMSSAFSList->setText(QCoreApplication::translate("CAMSSDlgBase", "AFS:  ", nullptr));
        TextLabelPhaseOffsetAMSS->setText(QCoreApplication::translate("CAMSSDlgBase", "AMSS Offset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CAMSSDlgBase: public Ui_CAMSSDlgBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AMSSDLGBASE_H
