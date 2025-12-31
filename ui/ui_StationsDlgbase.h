/********************************************************************************
** Form generated from reading UI file 'StationsDlgbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATIONSDLGBASE_H
#define UI_STATIONSDLGBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qwt_counter.h"
#include "qwt_thermo.h"

QT_BEGIN_NAMESPACE

class Ui_StationsDlgbase
{
public:
    QAction *actionShowOnlyActiveStations;
    QAction *actionShowAllStations;
    QAction *action5minutes;
    QAction *action15minutes;
    QAction *action30minutes;
    QAction *actionGetUpdate;
    QAction *actionChooseRig;
    QAction *actionDisabled;
    QAction *actionEnable_S_Meter;
    QAction *actionClose;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTreeWidget *ListViewStations;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *TextLabelTarget;
    QComboBox *ComboBoxFilterTarget;
    QLabel *TextLabelCountry;
    QComboBox *ComboBoxFilterCountry;
    QLabel *TextLabelLanguage;
    QComboBox *ComboBoxFilterLanguage;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *TextLabelUTCTime;
    QwtCounter *QwtCounterFrequency;
    QLabel *TextLabel1;
    QSpacerItem *horizontalSpacer_2;
    QLabel *TextLabelSMeter;
    QwtThermo *ProgrSigStrength;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_1;
    QWidget *widget;
    QPushButton *buttonOk;
    QMenuBar *menubar;
    QMenu *menuView;
    QMenu *menuStations_preview;
    QMenu *menuRemote;
    QMenu *menuUpdate;

    void setupUi(QMainWindow *StationsDlgbase)
    {
        if (StationsDlgbase->objectName().isEmpty())
            StationsDlgbase->setObjectName(QString::fromUtf8("StationsDlgbase"));
        StationsDlgbase->resize(621, 427);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/MainIcon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        StationsDlgbase->setWindowIcon(icon);
        actionShowOnlyActiveStations = new QAction(StationsDlgbase);
        actionShowOnlyActiveStations->setObjectName(QString::fromUtf8("actionShowOnlyActiveStations"));
        actionShowOnlyActiveStations->setCheckable(true);
        actionShowAllStations = new QAction(StationsDlgbase);
        actionShowAllStations->setObjectName(QString::fromUtf8("actionShowAllStations"));
        actionShowAllStations->setCheckable(true);
        action5minutes = new QAction(StationsDlgbase);
        action5minutes->setObjectName(QString::fromUtf8("action5minutes"));
        action5minutes->setCheckable(true);
        action15minutes = new QAction(StationsDlgbase);
        action15minutes->setObjectName(QString::fromUtf8("action15minutes"));
        action15minutes->setCheckable(true);
        action30minutes = new QAction(StationsDlgbase);
        action30minutes->setObjectName(QString::fromUtf8("action30minutes"));
        action30minutes->setCheckable(true);
        actionGetUpdate = new QAction(StationsDlgbase);
        actionGetUpdate->setObjectName(QString::fromUtf8("actionGetUpdate"));
        actionChooseRig = new QAction(StationsDlgbase);
        actionChooseRig->setObjectName(QString::fromUtf8("actionChooseRig"));
        actionDisabled = new QAction(StationsDlgbase);
        actionDisabled->setObjectName(QString::fromUtf8("actionDisabled"));
        actionDisabled->setCheckable(true);
        actionEnable_S_Meter = new QAction(StationsDlgbase);
        actionEnable_S_Meter->setObjectName(QString::fromUtf8("actionEnable_S_Meter"));
        actionEnable_S_Meter->setCheckable(true);
        actionClose = new QAction(StationsDlgbase);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        centralwidget = new QWidget(StationsDlgbase);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ListViewStations = new QTreeWidget(centralwidget);
        ListViewStations->headerItem()->setText(0, QString());
        ListViewStations->setObjectName(QString::fromUtf8("ListViewStations"));
        ListViewStations->setRootIsDecorated(false);
        ListViewStations->setUniformRowHeights(true);

        verticalLayout->addWidget(ListViewStations);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        TextLabelTarget = new QLabel(groupBox);
        TextLabelTarget->setObjectName(QString::fromUtf8("TextLabelTarget"));
        TextLabelTarget->setWordWrap(false);

        horizontalLayout->addWidget(TextLabelTarget);

        ComboBoxFilterTarget = new QComboBox(groupBox);
        ComboBoxFilterTarget->setObjectName(QString::fromUtf8("ComboBoxFilterTarget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ComboBoxFilterTarget->sizePolicy().hasHeightForWidth());
        ComboBoxFilterTarget->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(ComboBoxFilterTarget);

        TextLabelCountry = new QLabel(groupBox);
        TextLabelCountry->setObjectName(QString::fromUtf8("TextLabelCountry"));
        TextLabelCountry->setWordWrap(false);

        horizontalLayout->addWidget(TextLabelCountry);

        ComboBoxFilterCountry = new QComboBox(groupBox);
        ComboBoxFilterCountry->setObjectName(QString::fromUtf8("ComboBoxFilterCountry"));
        sizePolicy.setHeightForWidth(ComboBoxFilterCountry->sizePolicy().hasHeightForWidth());
        ComboBoxFilterCountry->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(ComboBoxFilterCountry);

        TextLabelLanguage = new QLabel(groupBox);
        TextLabelLanguage->setObjectName(QString::fromUtf8("TextLabelLanguage"));
        TextLabelLanguage->setWordWrap(false);

        horizontalLayout->addWidget(TextLabelLanguage);

        ComboBoxFilterLanguage = new QComboBox(groupBox);
        ComboBoxFilterLanguage->setObjectName(QString::fromUtf8("ComboBoxFilterLanguage"));
        sizePolicy.setHeightForWidth(ComboBoxFilterLanguage->sizePolicy().hasHeightForWidth());
        ComboBoxFilterLanguage->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(ComboBoxFilterLanguage);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(widget_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        TextLabelUTCTime = new QLabel(centralwidget);
        TextLabelUTCTime->setObjectName(QString::fromUtf8("TextLabelUTCTime"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(TextLabelUTCTime->sizePolicy().hasHeightForWidth());
        TextLabelUTCTime->setSizePolicy(sizePolicy2);
        TextLabelUTCTime->setMinimumSize(QSize(0, 23));
        TextLabelUTCTime->setFrameShape(QFrame::Panel);
        TextLabelUTCTime->setFrameShadow(QFrame::Sunken);
        TextLabelUTCTime->setWordWrap(false);

        horizontalLayout_2->addWidget(TextLabelUTCTime);

        QwtCounterFrequency = new QwtCounter(centralwidget);
        QwtCounterFrequency->setObjectName(QString::fromUtf8("QwtCounterFrequency"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(QwtCounterFrequency->sizePolicy().hasHeightForWidth());
        QwtCounterFrequency->setSizePolicy(sizePolicy3);
        QwtCounterFrequency->setMinimumSize(QSize(168, 0));

        horizontalLayout_2->addWidget(QwtCounterFrequency);

        TextLabel1 = new QLabel(centralwidget);
        TextLabel1->setObjectName(QString::fromUtf8("TextLabel1"));
        sizePolicy1.setHeightForWidth(TextLabel1->sizePolicy().hasHeightForWidth());
        TextLabel1->setSizePolicy(sizePolicy1);
        TextLabel1->setWordWrap(false);

        horizontalLayout_2->addWidget(TextLabel1);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        TextLabelSMeter = new QLabel(centralwidget);
        TextLabelSMeter->setObjectName(QString::fromUtf8("TextLabelSMeter"));
        sizePolicy1.setHeightForWidth(TextLabelSMeter->sizePolicy().hasHeightForWidth());
        TextLabelSMeter->setSizePolicy(sizePolicy1);
        TextLabelSMeter->setWordWrap(false);

        horizontalLayout_3->addWidget(TextLabelSMeter);

        ProgrSigStrength = new QwtThermo(centralwidget);
        ProgrSigStrength->setObjectName(QString::fromUtf8("ProgrSigStrength"));
        sizePolicy3.setHeightForWidth(ProgrSigStrength->sizePolicy().hasHeightForWidth());
        ProgrSigStrength->setSizePolicy(sizePolicy3);
        ProgrSigStrength->setMinimumSize(QSize(150, 0));

        horizontalLayout_3->addWidget(ProgrSigStrength);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_1 = new QVBoxLayout();
        verticalLayout_1->setSpacing(0);
        verticalLayout_1->setObjectName(QString::fromUtf8("verticalLayout_1"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);

        verticalLayout_1->addWidget(widget);

        buttonOk = new QPushButton(centralwidget);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
        sizePolicy2.setHeightForWidth(buttonOk->sizePolicy().hasHeightForWidth());
        buttonOk->setSizePolicy(sizePolicy2);
        buttonOk->setAutoDefault(true);

        verticalLayout_1->addWidget(buttonOk);


        horizontalLayout_3->addLayout(verticalLayout_1);


        verticalLayout->addLayout(horizontalLayout_3);

        StationsDlgbase->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StationsDlgbase);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuStations_preview = new QMenu(menuView);
        menuStations_preview->setObjectName(QString::fromUtf8("menuStations_preview"));
        menuRemote = new QMenu(menubar);
        menuRemote->setObjectName(QString::fromUtf8("menuRemote"));
        menuUpdate = new QMenu(menubar);
        menuUpdate->setObjectName(QString::fromUtf8("menuUpdate"));
        StationsDlgbase->setMenuBar(menubar);
#if QT_CONFIG(shortcut)
        TextLabel1->setBuddy(QwtCounterFrequency);
#endif // QT_CONFIG(shortcut)

        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuRemote->menuAction());
        menubar->addAction(menuUpdate->menuAction());
        menuView->addAction(actionShowOnlyActiveStations);
        menuView->addAction(actionShowAllStations);
        menuView->addAction(menuStations_preview->menuAction());
        menuView->addSeparator();
        menuView->addAction(actionClose);
        menuStations_preview->addAction(actionDisabled);
        menuStations_preview->addAction(action5minutes);
        menuStations_preview->addAction(action15minutes);
        menuStations_preview->addAction(action30minutes);
        menuRemote->addAction(actionChooseRig);
        menuRemote->addAction(actionEnable_S_Meter);
        menuUpdate->addAction(actionGetUpdate);

        retranslateUi(StationsDlgbase);

        buttonOk->setDefault(true);


        QMetaObject::connectSlotsByName(StationsDlgbase);
    } // setupUi

    void retranslateUi(QMainWindow *StationsDlgbase)
    {
        StationsDlgbase->setWindowTitle(QCoreApplication::translate("StationsDlgbase", "Stations", nullptr));
        actionShowOnlyActiveStations->setText(QCoreApplication::translate("StationsDlgbase", "Show only active stations", nullptr));
        actionShowAllStations->setText(QCoreApplication::translate("StationsDlgbase", "Show all stations", nullptr));
        action5minutes->setText(QCoreApplication::translate("StationsDlgbase", "5 minutes", nullptr));
        action15minutes->setText(QCoreApplication::translate("StationsDlgbase", "15 minutes", nullptr));
        action30minutes->setText(QCoreApplication::translate("StationsDlgbase", "30 minutes", nullptr));
        actionGetUpdate->setText(QCoreApplication::translate("StationsDlgbase", "Get &Update...", nullptr));
        actionChooseRig->setText(QCoreApplication::translate("StationsDlgbase", "&Rig Settings...", nullptr));
        actionDisabled->setText(QCoreApplication::translate("StationsDlgbase", "&Disabled", nullptr));
        actionEnable_S_Meter->setText(QCoreApplication::translate("StationsDlgbase", "Enable &S-Meter", nullptr));
        actionClose->setText(QCoreApplication::translate("StationsDlgbase", "&Close", nullptr));
        groupBox->setTitle(QCoreApplication::translate("StationsDlgbase", "Filters", nullptr));
        TextLabelTarget->setText(QCoreApplication::translate("StationsDlgbase", "Target", nullptr));
        TextLabelCountry->setText(QCoreApplication::translate("StationsDlgbase", "Country", nullptr));
        TextLabelLanguage->setText(QCoreApplication::translate("StationsDlgbase", "Language", nullptr));
        TextLabelUTCTime->setText(QCoreApplication::translate("StationsDlgbase", "UTC", nullptr));
        TextLabel1->setText(QCoreApplication::translate("StationsDlgbase", "kHz", nullptr));
        TextLabelSMeter->setText(QCoreApplication::translate("StationsDlgbase", "S-Meter [dB]\n"
"(relative to S9):", nullptr));
        buttonOk->setText(QCoreApplication::translate("StationsDlgbase", "&Close", nullptr));
        menuView->setTitle(QCoreApplication::translate("StationsDlgbase", "&View", nullptr));
        menuStations_preview->setTitle(QCoreApplication::translate("StationsDlgbase", "Stations &preview", nullptr));
        menuRemote->setTitle(QCoreApplication::translate("StationsDlgbase", "&Remote", nullptr));
        menuUpdate->setTitle(QCoreApplication::translate("StationsDlgbase", "&Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StationsDlgbase: public Ui_StationsDlgbase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATIONSDLGBASE_H
