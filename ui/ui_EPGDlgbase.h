/********************************************************************************
** Form generated from reading UI file 'EPGDlgbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EPGDLGBASE_H
#define UI_EPGDLGBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CEPGDlgbase
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *channel;
    QSpacerItem *Spacer4;
    QDateEdit *dateEdit;
    QSpacerItem *Spacer4_2;
    QLabel *TextEPGDisabled;
    QSpacerItem *Spacer3;
    QTabWidget *pages;
    QWidget *GuideTab;
    QGridLayout *gridLayout1;
    QTreeWidget *Data;
    QWidget *BasicTab;
    QGridLayout *gridLayout2;
    QTextBrowser *basic;
    QWidget *AdvancedTab;
    QGridLayout *gridLayout3;
    QTextBrowser *advanced;
    QHBoxLayout *hboxLayout;
    QSpacerItem *Spacer2;
    QPushButton *close;

    void setupUi(QMainWindow *CEPGDlgbase)
    {
        if (CEPGDlgbase->objectName().isEmpty())
            CEPGDlgbase->setObjectName(QString::fromUtf8("CEPGDlgbase"));
        CEPGDlgbase->resize(501, 422);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CEPGDlgbase->sizePolicy().hasHeightForWidth());
        CEPGDlgbase->setSizePolicy(sizePolicy);
        CEPGDlgbase->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/MainIcon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        CEPGDlgbase->setWindowIcon(icon);
        centralwidget = new QWidget(CEPGDlgbase);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        channel = new QComboBox(frame);
        channel->setObjectName(QString::fromUtf8("channel"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(channel->sizePolicy().hasHeightForWidth());
        channel->setSizePolicy(sizePolicy1);
        channel->setMaximumSize(QSize(300, 32767));

        horizontalLayout_2->addWidget(channel);

        Spacer4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(Spacer4);

        dateEdit = new QDateEdit(frame);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        horizontalLayout_2->addWidget(dateEdit);

        Spacer4_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(Spacer4_2);

        TextEPGDisabled = new QLabel(frame);
        TextEPGDisabled->setObjectName(QString::fromUtf8("TextEPGDisabled"));
        TextEPGDisabled->setWordWrap(false);

        horizontalLayout_2->addWidget(TextEPGDisabled);

        Spacer3 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(Spacer3);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        pages = new QTabWidget(centralwidget);
        pages->setObjectName(QString::fromUtf8("pages"));
        GuideTab = new QWidget();
        GuideTab->setObjectName(QString::fromUtf8("GuideTab"));
        gridLayout1 = new QGridLayout(GuideTab);
#ifndef Q_OS_MAC
        gridLayout1->setSpacing(6);
#endif
        gridLayout1->setContentsMargins(6, 6, 6, 6);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        Data = new QTreeWidget(GuideTab);
        Data->setObjectName(QString::fromUtf8("Data"));

        gridLayout1->addWidget(Data, 0, 0, 1, 1);

        pages->addTab(GuideTab, QString());
        BasicTab = new QWidget();
        BasicTab->setObjectName(QString::fromUtf8("BasicTab"));
        gridLayout2 = new QGridLayout(BasicTab);
#ifndef Q_OS_MAC
        gridLayout2->setSpacing(6);
#endif
        gridLayout2->setContentsMargins(6, 6, 6, 6);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        basic = new QTextBrowser(BasicTab);
        basic->setObjectName(QString::fromUtf8("basic"));

        gridLayout2->addWidget(basic, 0, 0, 1, 1);

        pages->addTab(BasicTab, QString());
        AdvancedTab = new QWidget();
        AdvancedTab->setObjectName(QString::fromUtf8("AdvancedTab"));
        gridLayout3 = new QGridLayout(AdvancedTab);
#ifndef Q_OS_MAC
        gridLayout3->setSpacing(6);
#endif
        gridLayout3->setContentsMargins(6, 6, 6, 6);
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        advanced = new QTextBrowser(AdvancedTab);
        advanced->setObjectName(QString::fromUtf8("advanced"));

        gridLayout3->addWidget(advanced, 0, 0, 1, 1);

        pages->addTab(AdvancedTab, QString());

        gridLayout->addWidget(pages, 1, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        Spacer2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(Spacer2);

        close = new QPushButton(centralwidget);
        close->setObjectName(QString::fromUtf8("close"));

        hboxLayout->addWidget(close);


        gridLayout->addLayout(hboxLayout, 2, 0, 1, 1);

        CEPGDlgbase->setCentralWidget(centralwidget);
        QWidget::setTabOrder(pages, close);

        retranslateUi(CEPGDlgbase);
        QObject::connect(close, SIGNAL(clicked()), CEPGDlgbase, SLOT(close()));

        pages->setCurrentIndex(0);
        close->setDefault(false);


        QMetaObject::connectSlotsByName(CEPGDlgbase);
    } // setupUi

    void retranslateUi(QMainWindow *CEPGDlgbase)
    {
        CEPGDlgbase->setWindowTitle(QCoreApplication::translate("CEPGDlgbase", "Programme Guide", nullptr));
        TextEPGDisabled->setText(QCoreApplication::translate("CEPGDlgbase", "EPG decoding is disabled", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = Data->headerItem();
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("CEPGDlgbase", "Description", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("CEPGDlgbase", "Genre", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("CEPGDlgbase", "Name", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("CEPGDlgbase", "Time [UTC]", nullptr));
        pages->setTabText(pages->indexOf(GuideTab), QCoreApplication::translate("CEPGDlgbase", "Guide", nullptr));
        pages->setTabText(pages->indexOf(BasicTab), QCoreApplication::translate("CEPGDlgbase", "Basic Profile Data", nullptr));
        pages->setTabText(pages->indexOf(AdvancedTab), QCoreApplication::translate("CEPGDlgbase", "Advanced Profile Data", nullptr));
        close->setText(QCoreApplication::translate("CEPGDlgbase", "&Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CEPGDlgbase: public Ui_CEPGDlgbase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EPGDLGBASE_H
