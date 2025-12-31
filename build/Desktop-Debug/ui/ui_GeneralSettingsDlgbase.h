/********************************************************************************
** Form generated from reading UI file 'GeneralSettingsDlgbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALSETTINGSDLGBASE_H
#define UI_GENERALSETTINGSDLGBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CGeneralSettingsDlgBase
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *GroupReceiverCoord;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *hboxLayout;
    QLabel *TextLatitude;
    QLineEdit *EdtLatitudeDegrees;
    QLabel *TextDegLat;
    QLineEdit *EdtLatitudeMinutes;
    QLabel *TextMinutesLat;
    QLineEdit *EdtLatitudeNS;
    QLabel *TextNS;
    QSpacerItem *Spacer10_2;
    QHBoxLayout *hboxLayout1;
    QLabel *TextLongitude;
    QLineEdit *EdtLongitudeDegrees;
    QLabel *TextDegLong;
    QLineEdit *EdtLongitudeMinutes;
    QLabel *TextMinutesLong;
    QLineEdit *EdtLongitudeEW;
    QLabel *TextEW;
    QSpacerItem *Spacer10;
    QSpacerItem *verticalSpacer;
    QGroupBox *GroupGPS;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QCheckBox *CheckBoxUseGPS;
    QLineEdit *LineEditGPSPort;
    QLineEdit *LineEditGPSHost;
    QSpacerItem *Spacer6;
    QSpacerItem *Spacer4;
    QSpacerItem *Spacer5_2;
    QLabel *GPSHost;
    QLabel *GPSPort;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *Spacer5;
    QPushButton *buttonOk;

    void setupUi(QDialog *CGeneralSettingsDlgBase)
    {
        if (CGeneralSettingsDlgBase->objectName().isEmpty())
            CGeneralSettingsDlgBase->setObjectName(QString::fromUtf8("CGeneralSettingsDlgBase"));
        CGeneralSettingsDlgBase->setWindowModality(Qt::ApplicationModal);
        CGeneralSettingsDlgBase->resize(269, 261);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CGeneralSettingsDlgBase->sizePolicy().hasHeightForWidth());
        CGeneralSettingsDlgBase->setSizePolicy(sizePolicy);
        CGeneralSettingsDlgBase->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/MainIcon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        CGeneralSettingsDlgBase->setWindowIcon(icon);
        CGeneralSettingsDlgBase->setSizeGripEnabled(true);
        verticalLayout_3 = new QVBoxLayout(CGeneralSettingsDlgBase);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        GroupReceiverCoord = new QGroupBox(CGeneralSettingsDlgBase);
        GroupReceiverCoord->setObjectName(QString::fromUtf8("GroupReceiverCoord"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(GroupReceiverCoord->sizePolicy().hasHeightForWidth());
        GroupReceiverCoord->setSizePolicy(sizePolicy1);
        GroupReceiverCoord->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(GroupReceiverCoord);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        TextLatitude = new QLabel(GroupReceiverCoord);
        TextLatitude->setObjectName(QString::fromUtf8("TextLatitude"));
        TextLatitude->setMinimumSize(QSize(64, 0));
        TextLatitude->setWordWrap(false);

        hboxLayout->addWidget(TextLatitude);

        EdtLatitudeDegrees = new QLineEdit(GroupReceiverCoord);
        EdtLatitudeDegrees->setObjectName(QString::fromUtf8("EdtLatitudeDegrees"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(EdtLatitudeDegrees->sizePolicy().hasHeightForWidth());
        EdtLatitudeDegrees->setSizePolicy(sizePolicy2);
        EdtLatitudeDegrees->setMaximumSize(QSize(30, 32767));
        EdtLatitudeDegrees->setMaxLength(2);

        hboxLayout->addWidget(EdtLatitudeDegrees);

        TextDegLat = new QLabel(GroupReceiverCoord);
        TextDegLat->setObjectName(QString::fromUtf8("TextDegLat"));
        QFont font;
        font.setPointSize(12);
        TextDegLat->setFont(font);
        TextDegLat->setWordWrap(false);

        hboxLayout->addWidget(TextDegLat);

        EdtLatitudeMinutes = new QLineEdit(GroupReceiverCoord);
        EdtLatitudeMinutes->setObjectName(QString::fromUtf8("EdtLatitudeMinutes"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(EdtLatitudeMinutes->sizePolicy().hasHeightForWidth());
        EdtLatitudeMinutes->setSizePolicy(sizePolicy3);
        EdtLatitudeMinutes->setMaximumSize(QSize(30, 32767));
        EdtLatitudeMinutes->setMaxLength(2);

        hboxLayout->addWidget(EdtLatitudeMinutes);

        TextMinutesLat = new QLabel(GroupReceiverCoord);
        TextMinutesLat->setObjectName(QString::fromUtf8("TextMinutesLat"));
        TextMinutesLat->setFont(font);
        TextMinutesLat->setWordWrap(false);

        hboxLayout->addWidget(TextMinutesLat);

        EdtLatitudeNS = new QLineEdit(GroupReceiverCoord);
        EdtLatitudeNS->setObjectName(QString::fromUtf8("EdtLatitudeNS"));
        sizePolicy3.setHeightForWidth(EdtLatitudeNS->sizePolicy().hasHeightForWidth());
        EdtLatitudeNS->setSizePolicy(sizePolicy3);
        EdtLatitudeNS->setMaximumSize(QSize(20, 32767));
        EdtLatitudeNS->setMaxLength(1);

        hboxLayout->addWidget(EdtLatitudeNS);

        TextNS = new QLabel(GroupReceiverCoord);
        TextNS->setObjectName(QString::fromUtf8("TextNS"));
        TextNS->setMinimumSize(QSize(0, 0));
        TextNS->setWordWrap(false);

        hboxLayout->addWidget(TextNS);

        Spacer10_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(Spacer10_2);


        verticalLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        TextLongitude = new QLabel(GroupReceiverCoord);
        TextLongitude->setObjectName(QString::fromUtf8("TextLongitude"));
        TextLongitude->setMinimumSize(QSize(64, 0));
        TextLongitude->setWordWrap(false);

        hboxLayout1->addWidget(TextLongitude);

        EdtLongitudeDegrees = new QLineEdit(GroupReceiverCoord);
        EdtLongitudeDegrees->setObjectName(QString::fromUtf8("EdtLongitudeDegrees"));
        sizePolicy3.setHeightForWidth(EdtLongitudeDegrees->sizePolicy().hasHeightForWidth());
        EdtLongitudeDegrees->setSizePolicy(sizePolicy3);
        EdtLongitudeDegrees->setMaximumSize(QSize(30, 32767));
        EdtLongitudeDegrees->setMaxLength(3);

        hboxLayout1->addWidget(EdtLongitudeDegrees);

        TextDegLong = new QLabel(GroupReceiverCoord);
        TextDegLong->setObjectName(QString::fromUtf8("TextDegLong"));
        TextDegLong->setFont(font);
        TextDegLong->setWordWrap(false);

        hboxLayout1->addWidget(TextDegLong);

        EdtLongitudeMinutes = new QLineEdit(GroupReceiverCoord);
        EdtLongitudeMinutes->setObjectName(QString::fromUtf8("EdtLongitudeMinutes"));
        sizePolicy3.setHeightForWidth(EdtLongitudeMinutes->sizePolicy().hasHeightForWidth());
        EdtLongitudeMinutes->setSizePolicy(sizePolicy3);
        EdtLongitudeMinutes->setMaximumSize(QSize(30, 32767));
        EdtLongitudeMinutes->setMaxLength(2);

        hboxLayout1->addWidget(EdtLongitudeMinutes);

        TextMinutesLong = new QLabel(GroupReceiverCoord);
        TextMinutesLong->setObjectName(QString::fromUtf8("TextMinutesLong"));
        TextMinutesLong->setFont(font);
        TextMinutesLong->setWordWrap(false);

        hboxLayout1->addWidget(TextMinutesLong);

        EdtLongitudeEW = new QLineEdit(GroupReceiverCoord);
        EdtLongitudeEW->setObjectName(QString::fromUtf8("EdtLongitudeEW"));
        sizePolicy3.setHeightForWidth(EdtLongitudeEW->sizePolicy().hasHeightForWidth());
        EdtLongitudeEW->setSizePolicy(sizePolicy3);
        EdtLongitudeEW->setMaximumSize(QSize(20, 32767));
        EdtLongitudeEW->setMaxLength(1);

        hboxLayout1->addWidget(EdtLongitudeEW);

        TextEW = new QLabel(GroupReceiverCoord);
        TextEW->setObjectName(QString::fromUtf8("TextEW"));
        TextEW->setMinimumSize(QSize(0, 0));
        TextEW->setWordWrap(false);

        hboxLayout1->addWidget(TextEW);

        Spacer10 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(Spacer10);


        verticalLayout->addLayout(hboxLayout1);

        verticalSpacer = new QSpacerItem(20, 3, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_3->addWidget(GroupReceiverCoord);

        GroupGPS = new QGroupBox(CGeneralSettingsDlgBase);
        GroupGPS->setObjectName(QString::fromUtf8("GroupGPS"));
        verticalLayout_2 = new QVBoxLayout(GroupGPS);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        CheckBoxUseGPS = new QCheckBox(GroupGPS);
        CheckBoxUseGPS->setObjectName(QString::fromUtf8("CheckBoxUseGPS"));

        gridLayout->addWidget(CheckBoxUseGPS, 0, 0, 1, 1);

        LineEditGPSPort = new QLineEdit(GroupGPS);
        LineEditGPSPort->setObjectName(QString::fromUtf8("LineEditGPSPort"));

        gridLayout->addWidget(LineEditGPSPort, 1, 2, 1, 1);

        LineEditGPSHost = new QLineEdit(GroupGPS);
        LineEditGPSHost->setObjectName(QString::fromUtf8("LineEditGPSHost"));

        gridLayout->addWidget(LineEditGPSHost, 0, 2, 1, 1);

        Spacer6 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(Spacer6, 1, 3, 1, 1);

        Spacer4 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(Spacer4, 1, 0, 1, 1);

        Spacer5_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(Spacer5_2, 0, 3, 1, 1);

        GPSHost = new QLabel(GroupGPS);
        GPSHost->setObjectName(QString::fromUtf8("GPSHost"));
        GPSHost->setWordWrap(false);

        gridLayout->addWidget(GPSHost, 0, 1, 1, 1);

        GPSPort = new QLabel(GroupGPS);
        GPSPort->setObjectName(QString::fromUtf8("GPSPort"));
        GPSPort->setWordWrap(false);

        gridLayout->addWidget(GPSPort, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer_2 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        verticalLayout_3->addWidget(GroupGPS);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Spacer5 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(Spacer5);

        buttonOk = new QPushButton(CGeneralSettingsDlgBase);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
        buttonOk->setAutoDefault(false);

        horizontalLayout->addWidget(buttonOk);


        verticalLayout_3->addLayout(horizontalLayout);

        QWidget::setTabOrder(EdtLatitudeDegrees, EdtLatitudeMinutes);
        QWidget::setTabOrder(EdtLatitudeMinutes, EdtLatitudeNS);
        QWidget::setTabOrder(EdtLatitudeNS, EdtLongitudeDegrees);
        QWidget::setTabOrder(EdtLongitudeDegrees, EdtLongitudeMinutes);
        QWidget::setTabOrder(EdtLongitudeMinutes, EdtLongitudeEW);
        QWidget::setTabOrder(EdtLongitudeEW, buttonOk);

        retranslateUi(CGeneralSettingsDlgBase);

        buttonOk->setDefault(true);


        QMetaObject::connectSlotsByName(CGeneralSettingsDlgBase);
    } // setupUi

    void retranslateUi(QDialog *CGeneralSettingsDlgBase)
    {
        CGeneralSettingsDlgBase->setWindowTitle(QCoreApplication::translate("CGeneralSettingsDlgBase", "General settings", nullptr));
        GroupReceiverCoord->setTitle(QCoreApplication::translate("CGeneralSettingsDlgBase", "Default Receiver coordinates", nullptr));
        TextLatitude->setText(QCoreApplication::translate("CGeneralSettingsDlgBase", "Latitude", nullptr));
        EdtLatitudeDegrees->setText(QString());
        TextDegLat->setText(QCoreApplication::translate("CGeneralSettingsDlgBase", "\302\260", nullptr));
        EdtLatitudeMinutes->setText(QString());
        TextMinutesLat->setText(QCoreApplication::translate("CGeneralSettingsDlgBase", "'", nullptr));
        EdtLatitudeNS->setText(QString());
        TextNS->setText(QCoreApplication::translate("CGeneralSettingsDlgBase", "N/S", nullptr));
        TextLongitude->setText(QCoreApplication::translate("CGeneralSettingsDlgBase", "Longitude", nullptr));
        EdtLongitudeDegrees->setText(QString());
        TextDegLong->setText(QCoreApplication::translate("CGeneralSettingsDlgBase", "\302\260", nullptr));
        EdtLongitudeMinutes->setText(QString());
        TextMinutesLong->setText(QCoreApplication::translate("CGeneralSettingsDlgBase", "'", nullptr));
        EdtLongitudeEW->setText(QString());
        TextEW->setText(QCoreApplication::translate("CGeneralSettingsDlgBase", "E/W", nullptr));
        GroupGPS->setTitle(QCoreApplication::translate("CGeneralSettingsDlgBase", "GPS", nullptr));
        CheckBoxUseGPS->setText(QCoreApplication::translate("CGeneralSettingsDlgBase", "Use GPS", nullptr));
        GPSHost->setText(QCoreApplication::translate("CGeneralSettingsDlgBase", "Host", nullptr));
        GPSPort->setText(QCoreApplication::translate("CGeneralSettingsDlgBase", "Port", nullptr));
        buttonOk->setText(QCoreApplication::translate("CGeneralSettingsDlgBase", "&OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CGeneralSettingsDlgBase: public Ui_CGeneralSettingsDlgBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALSETTINGSDLGBASE_H
