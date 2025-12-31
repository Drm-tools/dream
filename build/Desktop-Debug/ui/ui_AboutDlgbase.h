/********************************************************************************
** Form generated from reading UI file 'AboutDlgbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDLGBASE_H
#define UI_ABOUTDLGBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CAboutDlgBase
{
public:
    QVBoxLayout *vboxLayout;
    QLabel *TextLabelVersion;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout1;
    QLabel *TextLabelAuthorNames;
    QLabel *TextLabelCopyright;
    QSpacerItem *Spacer10;
    QLabel *PixmapLabelDreamLogo;
    QTextBrowser *TextViewCredits;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *Spacer12;
    QPushButton *buttonOk;

    void setupUi(QDialog *CAboutDlgBase)
    {
        if (CAboutDlgBase->objectName().isEmpty())
            CAboutDlgBase->setObjectName(QString::fromUtf8("CAboutDlgBase"));
        CAboutDlgBase->setWindowModality(Qt::ApplicationModal);
        CAboutDlgBase->resize(588, 480);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CAboutDlgBase->sizePolicy().hasHeightForWidth());
        CAboutDlgBase->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/MainIcon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        CAboutDlgBase->setWindowIcon(icon);
        CAboutDlgBase->setSizeGripEnabled(true);
        vboxLayout = new QVBoxLayout(CAboutDlgBase);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        TextLabelVersion = new QLabel(CAboutDlgBase);
        TextLabelVersion->setObjectName(QString::fromUtf8("TextLabelVersion"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TextLabelVersion->sizePolicy().hasHeightForWidth());
        TextLabelVersion->setSizePolicy(sizePolicy1);
        TextLabelVersion->setWordWrap(false);

        vboxLayout->addWidget(TextLabelVersion);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        vboxLayout1 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        TextLabelAuthorNames = new QLabel(CAboutDlgBase);
        TextLabelAuthorNames->setObjectName(QString::fromUtf8("TextLabelAuthorNames"));
        TextLabelAuthorNames->setWordWrap(false);

        vboxLayout1->addWidget(TextLabelAuthorNames);

        TextLabelCopyright = new QLabel(CAboutDlgBase);
        TextLabelCopyright->setObjectName(QString::fromUtf8("TextLabelCopyright"));
        TextLabelCopyright->setWordWrap(false);

        vboxLayout1->addWidget(TextLabelCopyright);


        hboxLayout->addLayout(vboxLayout1);

        Spacer10 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(Spacer10);

        PixmapLabelDreamLogo = new QLabel(CAboutDlgBase);
        PixmapLabelDreamLogo->setObjectName(QString::fromUtf8("PixmapLabelDreamLogo"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(PixmapLabelDreamLogo->sizePolicy().hasHeightForWidth());
        PixmapLabelDreamLogo->setSizePolicy(sizePolicy2);
        PixmapLabelDreamLogo->setPixmap(QPixmap(QString::fromUtf8(":/icons/LogoSmall.png")));
        PixmapLabelDreamLogo->setScaledContents(false);
        PixmapLabelDreamLogo->setWordWrap(false);

        hboxLayout->addWidget(PixmapLabelDreamLogo);


        vboxLayout->addLayout(hboxLayout);

        TextViewCredits = new QTextBrowser(CAboutDlgBase);
        TextViewCredits->setObjectName(QString::fromUtf8("TextViewCredits"));
        TextViewCredits->setOpenExternalLinks(true);
        TextViewCredits->setOpenLinks(true);

        vboxLayout->addWidget(TextViewCredits);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        Spacer12 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(Spacer12);

        buttonOk = new QPushButton(CAboutDlgBase);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
        buttonOk->setAutoDefault(true);

        hboxLayout1->addWidget(buttonOk);


        vboxLayout->addLayout(hboxLayout1);


        retranslateUi(CAboutDlgBase);
        QObject::connect(buttonOk, SIGNAL(clicked()), CAboutDlgBase, SLOT(accept()));

        buttonOk->setDefault(true);


        QMetaObject::connectSlotsByName(CAboutDlgBase);
    } // setupUi

    void retranslateUi(QDialog *CAboutDlgBase)
    {
        CAboutDlgBase->setWindowTitle(QCoreApplication::translate("CAboutDlgBase", "About Dream", nullptr));
        TextLabelVersion->setText(QCoreApplication::translate("CAboutDlgBase", "TextLabelVersion", nullptr));
        TextLabelAuthorNames->setText(QCoreApplication::translate("CAboutDlgBase", "TextLabelAuthorNames", nullptr));
        TextLabelCopyright->setText(QCoreApplication::translate("CAboutDlgBase", "TextLabelCopyright", nullptr));
        buttonOk->setText(QCoreApplication::translate("CAboutDlgBase", "&OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CAboutDlgBase: public Ui_CAboutDlgBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDLGBASE_H
