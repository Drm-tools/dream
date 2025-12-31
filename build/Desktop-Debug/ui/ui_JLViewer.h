/********************************************************************************
** Form generated from reading UI file 'JLViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JLVIEWER_H
#define UI_JLVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MultColorLED.h"
#include "jlbrowser.h"

QT_BEGIN_NAMESPACE

class Ui_JLViewer
{
public:
    QAction *actionSet_Font;
    QAction *actionClear_All;
    QAction *actionSave;
    QAction *actionSave_All;
    QAction *actionClose;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    JLBrowser *textBrowser;
    QHBoxLayout *_2;
    QLabel *TextLabel1;
    CMultColorLED *LEDStatus;
    QSpacerItem *horizontalSpacer;
    QToolButton *ButtonStepBack;
    QSpacerItem *Spacer5_2;
    QPushButton *pushButtonClearCache;
    QPushButton *buttonOk;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSettings;

    void setupUi(QMainWindow *JLViewer)
    {
        if (JLViewer->objectName().isEmpty())
            JLViewer->setObjectName(QString::fromUtf8("JLViewer"));
        JLViewer->resize(531, 485);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/MainIcon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        JLViewer->setWindowIcon(icon);
        actionSet_Font = new QAction(JLViewer);
        actionSet_Font->setObjectName(QString::fromUtf8("actionSet_Font"));
        actionClear_All = new QAction(JLViewer);
        actionClear_All->setObjectName(QString::fromUtf8("actionClear_All"));
        actionSave = new QAction(JLViewer);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_All = new QAction(JLViewer);
        actionSave_All->setObjectName(QString::fromUtf8("actionSave_All"));
        actionClose = new QAction(JLViewer);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        centralwidget = new QWidget(JLViewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new JLBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        _2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        _2->setSpacing(6);
#endif
        _2->setContentsMargins(0, 0, 0, 0);
        _2->setObjectName(QString::fromUtf8("_2"));
        TextLabel1 = new QLabel(centralwidget);
        TextLabel1->setObjectName(QString::fromUtf8("TextLabel1"));
        TextLabel1->setWordWrap(false);

        _2->addWidget(TextLabel1);

        LEDStatus = new CMultColorLED(centralwidget);
        LEDStatus->setObjectName(QString::fromUtf8("LEDStatus"));
        LEDStatus->setMinimumSize(QSize(13, 13));
        LEDStatus->setMaximumSize(QSize(13, 13));

        _2->addWidget(LEDStatus);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _2->addItem(horizontalSpacer);

        ButtonStepBack = new QToolButton(centralwidget);
        ButtonStepBack->setObjectName(QString::fromUtf8("ButtonStepBack"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/StepBack.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonStepBack->setIcon(icon1);

        _2->addWidget(ButtonStepBack);

        Spacer5_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _2->addItem(Spacer5_2);

        pushButtonClearCache = new QPushButton(centralwidget);
        pushButtonClearCache->setObjectName(QString::fromUtf8("pushButtonClearCache"));

        _2->addWidget(pushButtonClearCache);

        buttonOk = new QPushButton(centralwidget);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
        buttonOk->setAutoDefault(true);

        _2->addWidget(buttonOk);


        verticalLayout->addLayout(_2);

        JLViewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(JLViewer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        JLViewer->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menuFile->addAction(actionClear_All);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_All);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuSettings->addAction(actionSet_Font);

        retranslateUi(JLViewer);

        buttonOk->setDefault(true);


        QMetaObject::connectSlotsByName(JLViewer);
    } // setupUi

    void retranslateUi(QMainWindow *JLViewer)
    {
        JLViewer->setWindowTitle(QCoreApplication::translate("JLViewer", "MainWindow", nullptr));
        actionSet_Font->setText(QCoreApplication::translate("JLViewer", "Set  &Font...", nullptr));
        actionClear_All->setText(QCoreApplication::translate("JLViewer", "Cl&ear Cache", nullptr));
        actionSave->setText(QCoreApplication::translate("JLViewer", "Save...", nullptr));
        actionSave_All->setText(QCoreApplication::translate("JLViewer", "Save All...", nullptr));
        actionClose->setText(QCoreApplication::translate("JLViewer", "&Close", nullptr));
        TextLabel1->setText(QCoreApplication::translate("JLViewer", "Receiving Status:", nullptr));
        ButtonStepBack->setText(QString());
        pushButtonClearCache->setText(QCoreApplication::translate("JLViewer", "Cl&ear Cache", nullptr));
        buttonOk->setText(QCoreApplication::translate("JLViewer", "&Close", nullptr));
        menuFile->setTitle(QCoreApplication::translate("JLViewer", "&File", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("JLViewer", "&Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JLViewer: public Ui_JLViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JLVIEWER_H
