/********************************************************************************
** Form generated from reading UI file 'MultSettingsDlgbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTSETTINGSDLGBASE_H
#define UI_MULTSETTINGSDLGBASE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CMultSettingsDlgBase
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *DirGroup;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *hboxLayout;
    QLabel *TextLabelDir;
    QPushButton *PushButtonChooseDir;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *MOTGroup;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *Spacer9;
    QPushButton *buttonClearCacheMOT;
    QHBoxLayout *Refresh;
    QSpacerItem *horizontalSpacer;
    QCheckBox *CheckBoxAddRefresh;
    QLineEdit *EdtSecRefresh;
    QSpacerItem *verticalSpacer;
    QGroupBox *EPGGroup;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *Spacer2;
    QPushButton *buttonClearCacheEPG;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *Spacer5;
    QPushButton *buttonOk;

    void setupUi(QDialog *CMultSettingsDlgBase)
    {
        if (CMultSettingsDlgBase->objectName().isEmpty())
            CMultSettingsDlgBase->setObjectName(QString::fromUtf8("CMultSettingsDlgBase"));
        CMultSettingsDlgBase->setWindowModality(Qt::ApplicationModal);
        CMultSettingsDlgBase->resize(402, 311);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CMultSettingsDlgBase->sizePolicy().hasHeightForWidth());
        CMultSettingsDlgBase->setSizePolicy(sizePolicy);
        CMultSettingsDlgBase->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/MainIcon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        CMultSettingsDlgBase->setWindowIcon(icon);
        CMultSettingsDlgBase->setSizeGripEnabled(true);
        verticalLayout_4 = new QVBoxLayout(CMultSettingsDlgBase);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        DirGroup = new QGroupBox(CMultSettingsDlgBase);
        DirGroup->setObjectName(QString::fromUtf8("DirGroup"));
        verticalLayout_3 = new QVBoxLayout(DirGroup);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        TextLabelDir = new QLabel(DirGroup);
        TextLabelDir->setObjectName(QString::fromUtf8("TextLabelDir"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TextLabelDir->sizePolicy().hasHeightForWidth());
        TextLabelDir->setSizePolicy(sizePolicy1);
        TextLabelDir->setWordWrap(false);

        hboxLayout->addWidget(TextLabelDir);

        PushButtonChooseDir = new QPushButton(DirGroup);
        PushButtonChooseDir->setObjectName(QString::fromUtf8("PushButtonChooseDir"));

        hboxLayout->addWidget(PushButtonChooseDir);


        verticalLayout_3->addLayout(hboxLayout);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        verticalLayout_4->addWidget(DirGroup);

        MOTGroup = new QGroupBox(CMultSettingsDlgBase);
        MOTGroup->setObjectName(QString::fromUtf8("MOTGroup"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(MOTGroup->sizePolicy().hasHeightForWidth());
        MOTGroup->setSizePolicy(sizePolicy2);
        MOTGroup->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(MOTGroup);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        Spacer9 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(Spacer9);

        buttonClearCacheMOT = new QPushButton(MOTGroup);
        buttonClearCacheMOT->setObjectName(QString::fromUtf8("buttonClearCacheMOT"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(buttonClearCacheMOT->sizePolicy().hasHeightForWidth());
        buttonClearCacheMOT->setSizePolicy(sizePolicy3);

        hboxLayout1->addWidget(buttonClearCacheMOT);


        verticalLayout->addLayout(hboxLayout1);

        Refresh = new QHBoxLayout();
#ifndef Q_OS_MAC
        Refresh->setSpacing(6);
#endif
        Refresh->setContentsMargins(0, 0, 0, 0);
        Refresh->setObjectName(QString::fromUtf8("Refresh"));
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Refresh->addItem(horizontalSpacer);

        CheckBoxAddRefresh = new QCheckBox(MOTGroup);
        CheckBoxAddRefresh->setObjectName(QString::fromUtf8("CheckBoxAddRefresh"));
        sizePolicy3.setHeightForWidth(CheckBoxAddRefresh->sizePolicy().hasHeightForWidth());
        CheckBoxAddRefresh->setSizePolicy(sizePolicy3);

        Refresh->addWidget(CheckBoxAddRefresh);

        EdtSecRefresh = new QLineEdit(MOTGroup);
        EdtSecRefresh->setObjectName(QString::fromUtf8("EdtSecRefresh"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(EdtSecRefresh->sizePolicy().hasHeightForWidth());
        EdtSecRefresh->setSizePolicy(sizePolicy4);
        EdtSecRefresh->setMaxLength(4);

        Refresh->addWidget(EdtSecRefresh);


        verticalLayout->addLayout(Refresh);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_4->addWidget(MOTGroup);

        EPGGroup = new QGroupBox(CMultSettingsDlgBase);
        EPGGroup->setObjectName(QString::fromUtf8("EPGGroup"));
        sizePolicy2.setHeightForWidth(EPGGroup->sizePolicy().hasHeightForWidth());
        EPGGroup->setSizePolicy(sizePolicy2);
        EPGGroup->setMinimumSize(QSize(0, 0));
        verticalLayout_2 = new QVBoxLayout(EPGGroup);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        Spacer2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(Spacer2);

        buttonClearCacheEPG = new QPushButton(EPGGroup);
        buttonClearCacheEPG->setObjectName(QString::fromUtf8("buttonClearCacheEPG"));
        sizePolicy3.setHeightForWidth(buttonClearCacheEPG->sizePolicy().hasHeightForWidth());
        buttonClearCacheEPG->setSizePolicy(sizePolicy3);

        hboxLayout2->addWidget(buttonClearCacheEPG);


        verticalLayout_2->addLayout(hboxLayout2);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        verticalLayout_4->addWidget(EPGGroup);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Spacer5 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(Spacer5);

        buttonOk = new QPushButton(CMultSettingsDlgBase);
        buttonOk->setObjectName(QString::fromUtf8("buttonOk"));
        buttonOk->setAutoDefault(true);

        horizontalLayout->addWidget(buttonOk);


        verticalLayout_4->addLayout(horizontalLayout);

        QWidget::setTabOrder(CheckBoxAddRefresh, EdtSecRefresh);
        QWidget::setTabOrder(EdtSecRefresh, buttonClearCacheMOT);
        QWidget::setTabOrder(buttonClearCacheMOT, buttonClearCacheEPG);
        QWidget::setTabOrder(buttonClearCacheEPG, buttonOk);

        retranslateUi(CMultSettingsDlgBase);
        QObject::connect(buttonOk, SIGNAL(clicked()), CMultSettingsDlgBase, SLOT(accept()));

        buttonOk->setDefault(true);


        QMetaObject::connectSlotsByName(CMultSettingsDlgBase);
    } // setupUi

    void retranslateUi(QDialog *CMultSettingsDlgBase)
    {
        CMultSettingsDlgBase->setWindowTitle(QCoreApplication::translate("CMultSettingsDlgBase", "Multimedia settings", nullptr));
        DirGroup->setTitle(QCoreApplication::translate("CMultSettingsDlgBase", "Data Directory", nullptr));
        TextLabelDir->setText(QCoreApplication::translate("CMultSettingsDlgBase", "TextLabelDir", nullptr));
        PushButtonChooseDir->setText(QCoreApplication::translate("CMultSettingsDlgBase", "Choose", nullptr));
        MOTGroup->setTitle(QCoreApplication::translate("CMultSettingsDlgBase", "MOT Broadcast Web Site", nullptr));
        buttonClearCacheMOT->setText(QCoreApplication::translate("CMultSettingsDlgBase", "Clear cache", nullptr));
        CheckBoxAddRefresh->setText(QCoreApplication::translate("CMultSettingsDlgBase", "Add refresh header of seconds", nullptr));
        EdtSecRefresh->setText(QString());
        EPGGroup->setTitle(QCoreApplication::translate("CMultSettingsDlgBase", "EPG - Electronic Programme Guide", nullptr));
        buttonClearCacheEPG->setText(QCoreApplication::translate("CMultSettingsDlgBase", "Clear cache", nullptr));
        buttonOk->setText(QCoreApplication::translate("CMultSettingsDlgBase", "&OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CMultSettingsDlgBase: public Ui_CMultSettingsDlgBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTSETTINGSDLGBASE_H
