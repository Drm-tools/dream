/********************************************************************************
** Form generated from reading UI file 'SlideShowViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLIDESHOWVIEWER_H
#define UI_SLIDESHOWVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
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

QT_BEGIN_NAMESPACE

class Ui_SlideShowViewer
{
public:
    QAction *actionClear_All;
    QAction *actionSave;
    QAction *actionSave_All;
    QAction *actionClose;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *LabelTitle;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *Image;
    QHBoxLayout *horizontalLayout;
    QLabel *TextLabel1;
    CMultColorLED *LEDStatus;
    QSpacerItem *Spacer5;
    QToolButton *ButtonJumpBegin;
    QToolButton *ButtonStepBack;
    QLabel *LabelCurPicNum;
    QToolButton *ButtonStepForward;
    QToolButton *ButtonJumpEnd;
    QSpacerItem *Spacer5_2;
    QPushButton *buttonOk;
    QMenuBar *menubar;
    QMenu *menuFile;

    void setupUi(QMainWindow *SlideShowViewer)
    {
        if (SlideShowViewer->objectName().isEmpty())
            SlideShowViewer->setObjectName(QString::fromUtf8("SlideShowViewer"));
        SlideShowViewer->resize(399, 338);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/MainIcon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        SlideShowViewer->setWindowIcon(icon);
        actionClear_All = new QAction(SlideShowViewer);
        actionClear_All->setObjectName(QString::fromUtf8("actionClear_All"));
        actionSave = new QAction(SlideShowViewer);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_All = new QAction(SlideShowViewer);
        actionSave_All->setObjectName(QString::fromUtf8("actionSave_All"));
        actionClose = new QAction(SlideShowViewer);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        centralwidget = new QWidget(SlideShowViewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        LabelTitle = new QLabel(centralwidget);
        LabelTitle->setObjectName(QString::fromUtf8("LabelTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LabelTitle->sizePolicy().hasHeightForWidth());
        LabelTitle->setSizePolicy(sizePolicy);
        LabelTitle->setLineWidth(0);
        LabelTitle->setTextFormat(Qt::RichText);
        LabelTitle->setAlignment(Qt::AlignCenter);
        LabelTitle->setWordWrap(true);
        LabelTitle->setOpenExternalLinks(true);
        LabelTitle->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        verticalLayout->addWidget(LabelTitle);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Image = new QLabel(frame);
        Image->setObjectName(QString::fromUtf8("Image"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Image->sizePolicy().hasHeightForWidth());
        Image->setSizePolicy(sizePolicy2);
        Image->setMinimumSize(QSize(320, 240));
        Image->setBaseSize(QSize(320, 240));
        Image->setAutoFillBackground(false);
        Image->setStyleSheet(QString::fromUtf8("background: white"));
        Image->setFrameShadow(QFrame::Plain);
        Image->setLineWidth(0);
        Image->setTextFormat(Qt::RichText);
        Image->setAlignment(Qt::AlignCenter);
        Image->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_2->addWidget(Image);


        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        TextLabel1 = new QLabel(centralwidget);
        TextLabel1->setObjectName(QString::fromUtf8("TextLabel1"));
        sizePolicy.setHeightForWidth(TextLabel1->sizePolicy().hasHeightForWidth());
        TextLabel1->setSizePolicy(sizePolicy);
        TextLabel1->setWordWrap(false);

        horizontalLayout->addWidget(TextLabel1);

        LEDStatus = new CMultColorLED(centralwidget);
        LEDStatus->setObjectName(QString::fromUtf8("LEDStatus"));
        LEDStatus->setMinimumSize(QSize(13, 13));
        LEDStatus->setMaximumSize(QSize(13, 13));

        horizontalLayout->addWidget(LEDStatus);

        Spacer5 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(Spacer5);

        ButtonJumpBegin = new QToolButton(centralwidget);
        ButtonJumpBegin->setObjectName(QString::fromUtf8("ButtonJumpBegin"));
        sizePolicy.setHeightForWidth(ButtonJumpBegin->sizePolicy().hasHeightForWidth());
        ButtonJumpBegin->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/JumpBegin.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonJumpBegin->setIcon(icon1);
        ButtonJumpBegin->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(ButtonJumpBegin);

        ButtonStepBack = new QToolButton(centralwidget);
        ButtonStepBack->setObjectName(QString::fromUtf8("ButtonStepBack"));
        sizePolicy.setHeightForWidth(ButtonStepBack->sizePolicy().hasHeightForWidth());
        ButtonStepBack->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/StepBack.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonStepBack->setIcon(icon2);
        ButtonStepBack->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(ButtonStepBack);

        LabelCurPicNum = new QLabel(centralwidget);
        LabelCurPicNum->setObjectName(QString::fromUtf8("LabelCurPicNum"));
        sizePolicy.setHeightForWidth(LabelCurPicNum->sizePolicy().hasHeightForWidth());
        LabelCurPicNum->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(14);
        LabelCurPicNum->setFont(font);
        LabelCurPicNum->setFrameShadow(QFrame::Sunken);
        LabelCurPicNum->setAlignment(Qt::AlignCenter);
        LabelCurPicNum->setWordWrap(false);

        horizontalLayout->addWidget(LabelCurPicNum);

        ButtonStepForward = new QToolButton(centralwidget);
        ButtonStepForward->setObjectName(QString::fromUtf8("ButtonStepForward"));
        sizePolicy.setHeightForWidth(ButtonStepForward->sizePolicy().hasHeightForWidth());
        ButtonStepForward->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/StepForw.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonStepForward->setIcon(icon3);
        ButtonStepForward->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(ButtonStepForward);

        ButtonJumpEnd = new QToolButton(centralwidget);
        ButtonJumpEnd->setObjectName(QString::fromUtf8("ButtonJumpEnd"));
        sizePolicy.setHeightForWidth(ButtonJumpEnd->sizePolicy().hasHeightForWidth());
        ButtonJumpEnd->setSizePolicy(sizePolicy);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/JumpEnd.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonJumpEnd->setIcon(icon4);
        ButtonJumpEnd->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(ButtonJumpEnd);

        Spacer5_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(Spacer5_2);

        buttonOk = new QPushButton(centralwidget);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(buttonOk->sizePolicy().hasHeightForWidth());
        buttonOk->setSizePolicy(sizePolicy3);
        buttonOk->setAutoDefault(true);

        horizontalLayout->addWidget(buttonOk);


        verticalLayout->addLayout(horizontalLayout);

        SlideShowViewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SlideShowViewer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        SlideShowViewer->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionClear_All);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_All);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);

        retranslateUi(SlideShowViewer);

        buttonOk->setDefault(true);


        QMetaObject::connectSlotsByName(SlideShowViewer);
    } // setupUi

    void retranslateUi(QMainWindow *SlideShowViewer)
    {
        SlideShowViewer->setWindowTitle(QCoreApplication::translate("SlideShowViewer", "MainWindow", nullptr));
        actionClear_All->setText(QCoreApplication::translate("SlideShowViewer", "Cl&ear All", nullptr));
        actionSave->setText(QCoreApplication::translate("SlideShowViewer", "&Save...", nullptr));
        actionSave_All->setText(QCoreApplication::translate("SlideShowViewer", "Save &All...", nullptr));
        actionClose->setText(QCoreApplication::translate("SlideShowViewer", "&Close", nullptr));
        LabelTitle->setText(QCoreApplication::translate("SlideShowViewer", "<b>Title</b>", nullptr));
        Image->setText(QCoreApplication::translate("SlideShowViewer", "MOT Slideshow Viewer", nullptr));
        TextLabel1->setText(QCoreApplication::translate("SlideShowViewer", "Receiving Status:", nullptr));
        ButtonJumpBegin->setText(QString());
        ButtonStepBack->setText(QString());
        LabelCurPicNum->setText(QCoreApplication::translate("SlideShowViewer", "0/0", nullptr));
        ButtonStepForward->setText(QString());
        ButtonJumpEnd->setText(QString());
        buttonOk->setText(QCoreApplication::translate("SlideShowViewer", "&Close", nullptr));
        menuFile->setTitle(QCoreApplication::translate("SlideShowViewer", "&File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SlideShowViewer: public Ui_SlideShowViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLIDESHOWVIEWER_H
