/********************************************************************************
** Form generated from reading UI file 'LiveScheduleWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIVESCHEDULEWINDOW_H
#define UI_LIVESCHEDULEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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

QT_BEGIN_NAMESPACE

class Ui_LiveScheduleWindow
{
public:
    QAction *actionShowOnlyActiveStations;
    QAction *actionShowAllStations;
    QAction *action5minutes;
    QAction *action15minutes;
    QAction *action30minutes;
    QAction *actionDisabled;
    QAction *actionSave;
    QAction *actionClose;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTreeWidget *ListViewStations;
    QHBoxLayout *horizontalLayout;
    QLabel *TextLabelUTCTime;
    QCheckBox *CheckBoxFreeze;
    QSpacerItem *Spacer4;
    QPushButton *buttonOk;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menu_View;
    QMenu *menuStations_preview;

    void setupUi(QMainWindow *LiveScheduleWindow)
    {
        if (LiveScheduleWindow->objectName().isEmpty())
            LiveScheduleWindow->setObjectName(QString::fromUtf8("LiveScheduleWindow"));
        LiveScheduleWindow->resize(622, 392);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/MainIcon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        LiveScheduleWindow->setWindowIcon(icon);
        actionShowOnlyActiveStations = new QAction(LiveScheduleWindow);
        actionShowOnlyActiveStations->setObjectName(QString::fromUtf8("actionShowOnlyActiveStations"));
        actionShowOnlyActiveStations->setCheckable(true);
        actionShowAllStations = new QAction(LiveScheduleWindow);
        actionShowAllStations->setObjectName(QString::fromUtf8("actionShowAllStations"));
        actionShowAllStations->setCheckable(true);
        action5minutes = new QAction(LiveScheduleWindow);
        action5minutes->setObjectName(QString::fromUtf8("action5minutes"));
        action5minutes->setCheckable(true);
        action15minutes = new QAction(LiveScheduleWindow);
        action15minutes->setObjectName(QString::fromUtf8("action15minutes"));
        action15minutes->setCheckable(true);
        action30minutes = new QAction(LiveScheduleWindow);
        action30minutes->setObjectName(QString::fromUtf8("action30minutes"));
        action30minutes->setCheckable(true);
        actionDisabled = new QAction(LiveScheduleWindow);
        actionDisabled->setObjectName(QString::fromUtf8("actionDisabled"));
        actionDisabled->setCheckable(true);
        actionSave = new QAction(LiveScheduleWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionClose = new QAction(LiveScheduleWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        centralwidget = new QWidget(LiveScheduleWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ListViewStations = new QTreeWidget(centralwidget);
        ListViewStations->setObjectName(QString::fromUtf8("ListViewStations"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ListViewStations->sizePolicy().hasHeightForWidth());
        ListViewStations->setSizePolicy(sizePolicy);
        ListViewStations->setRootIsDecorated(false);
        ListViewStations->setUniformRowHeights(true);

        verticalLayout->addWidget(ListViewStations);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        TextLabelUTCTime = new QLabel(centralwidget);
        TextLabelUTCTime->setObjectName(QString::fromUtf8("TextLabelUTCTime"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TextLabelUTCTime->sizePolicy().hasHeightForWidth());
        TextLabelUTCTime->setSizePolicy(sizePolicy1);
        TextLabelUTCTime->setMinimumSize(QSize(0, 23));
        TextLabelUTCTime->setFrameShape(QFrame::Panel);
        TextLabelUTCTime->setFrameShadow(QFrame::Sunken);
        TextLabelUTCTime->setWordWrap(false);

        horizontalLayout->addWidget(TextLabelUTCTime);

        CheckBoxFreeze = new QCheckBox(centralwidget);
        CheckBoxFreeze->setObjectName(QString::fromUtf8("CheckBoxFreeze"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(CheckBoxFreeze->sizePolicy().hasHeightForWidth());
        CheckBoxFreeze->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(CheckBoxFreeze);

        Spacer4 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(Spacer4);

        buttonOk = new QPushButton(centralwidget);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
        sizePolicy1.setHeightForWidth(buttonOk->sizePolicy().hasHeightForWidth());
        buttonOk->setSizePolicy(sizePolicy1);
        buttonOk->setAutoDefault(true);

        horizontalLayout->addWidget(buttonOk);


        verticalLayout->addLayout(horizontalLayout);

        LiveScheduleWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LiveScheduleWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menu_View = new QMenu(menubar);
        menu_View->setObjectName(QString::fromUtf8("menu_View"));
        menuStations_preview = new QMenu(menu_View);
        menuStations_preview->setObjectName(QString::fromUtf8("menuStations_preview"));
        LiveScheduleWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menu_View->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menu_View->addAction(actionShowOnlyActiveStations);
        menu_View->addAction(actionShowAllStations);
        menu_View->addAction(menuStations_preview->menuAction());
        menuStations_preview->addAction(actionDisabled);
        menuStations_preview->addAction(action5minutes);
        menuStations_preview->addAction(action15minutes);
        menuStations_preview->addAction(action30minutes);

        retranslateUi(LiveScheduleWindow);

        buttonOk->setDefault(true);


        QMetaObject::connectSlotsByName(LiveScheduleWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LiveScheduleWindow)
    {
        LiveScheduleWindow->setWindowTitle(QCoreApplication::translate("LiveScheduleWindow", "Live Schedule", nullptr));
        actionShowOnlyActiveStations->setText(QCoreApplication::translate("LiveScheduleWindow", "Show only active stations", nullptr));
        actionShowAllStations->setText(QCoreApplication::translate("LiveScheduleWindow", "Show all stations", nullptr));
        action5minutes->setText(QCoreApplication::translate("LiveScheduleWindow", "5 minutes", nullptr));
        action15minutes->setText(QCoreApplication::translate("LiveScheduleWindow", "15 minutes", nullptr));
        action30minutes->setText(QCoreApplication::translate("LiveScheduleWindow", "30 minutes", nullptr));
        actionDisabled->setText(QCoreApplication::translate("LiveScheduleWindow", "&Disabled", nullptr));
        actionSave->setText(QCoreApplication::translate("LiveScheduleWindow", "&Save...", nullptr));
        actionClose->setText(QCoreApplication::translate("LiveScheduleWindow", "&Close", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = ListViewStations->headerItem();
        ___qtreewidgetitem->setText(5, QCoreApplication::translate("LiveScheduleWindow", "Start Day", nullptr));
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("LiveScheduleWindow", "Target", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("LiveScheduleWindow", "Time [UTC]", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("LiveScheduleWindow", "System", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("LiveScheduleWindow", "Station Name/Id", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("LiveScheduleWindow", "Frequency [kHz/MHz]", nullptr));
        TextLabelUTCTime->setText(QCoreApplication::translate("LiveScheduleWindow", "UTC", nullptr));
        CheckBoxFreeze->setText(QCoreApplication::translate("LiveScheduleWindow", "F&reeze", nullptr));
        buttonOk->setText(QCoreApplication::translate("LiveScheduleWindow", "&Close", nullptr));
        menuFile->setTitle(QCoreApplication::translate("LiveScheduleWindow", "&File", nullptr));
        menu_View->setTitle(QCoreApplication::translate("LiveScheduleWindow", "&View", nullptr));
        menuStations_preview->setTitle(QCoreApplication::translate("LiveScheduleWindow", "Stations &preview", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LiveScheduleWindow: public Ui_LiveScheduleWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIVESCHEDULEWINDOW_H
