/********************************************************************************
** Form generated from reading UI file 'RigDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RIGDLG_H
#define UI_RIGDLG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include "qwt_thermo.h"

QT_BEGIN_NAMESPACE

class Ui_RigDlg
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *rigTypes;
    QLabel *label_2;
    QLineEdit *selectedRigType;
    QCheckBox *modified;
    QLabel *labelPort;
    QComboBox *comboBoxPort;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout_3;
    QwtThermo *sMeter;
    QPushButton *testRig;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RigDlg)
    {
        if (RigDlg->objectName().isEmpty())
            RigDlg->setObjectName(QString::fromUtf8("RigDlg"));
        RigDlg->setWindowModality(Qt::ApplicationModal);
        RigDlg->resize(404, 465);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/MainIcon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        RigDlg->setWindowIcon(icon);
        RigDlg->setSizeGripEnabled(true);
        gridLayout = new QGridLayout(RigDlg);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        rigTypes = new QTreeWidget(RigDlg);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("Rig Types"));
        rigTypes->setHeaderItem(__qtreewidgetitem);
        rigTypes->setObjectName(QString::fromUtf8("rigTypes"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rigTypes->sizePolicy().hasHeightForWidth());
        rigTypes->setSizePolicy(sizePolicy);

        gridLayout->addWidget(rigTypes, 0, 0, 1, 3);

        label_2 = new QLabel(RigDlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        selectedRigType = new QLineEdit(RigDlg);
        selectedRigType->setObjectName(QString::fromUtf8("selectedRigType"));
        selectedRigType->setReadOnly(true);

        gridLayout->addWidget(selectedRigType, 1, 1, 1, 1);

        modified = new QCheckBox(RigDlg);
        modified->setObjectName(QString::fromUtf8("modified"));

        gridLayout->addWidget(modified, 1, 2, 1, 1);

        labelPort = new QLabel(RigDlg);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));

        gridLayout->addWidget(labelPort, 2, 0, 1, 1);

        comboBoxPort = new QComboBox(RigDlg);
        comboBoxPort->setObjectName(QString::fromUtf8("comboBoxPort"));
        comboBoxPort->setEditable(true);

        gridLayout->addWidget(comboBoxPort, 2, 1, 1, 1);

        groupBox_8 = new QGroupBox(RigDlg);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_8);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        sMeter = new QwtThermo(groupBox_8);
        sMeter->setObjectName(QString::fromUtf8("sMeter"));

        horizontalLayout_3->addWidget(sMeter);


        gridLayout->addWidget(groupBox_8, 3, 0, 1, 2);

        testRig = new QPushButton(RigDlg);
        testRig->setObjectName(QString::fromUtf8("testRig"));

        gridLayout->addWidget(testRig, 3, 2, 1, 1);

        buttonBox = new QDialogButtonBox(RigDlg);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        gridLayout->addWidget(buttonBox, 4, 2, 1, 1);


        retranslateUi(RigDlg);

        QMetaObject::connectSlotsByName(RigDlg);
    } // setupUi

    void retranslateUi(QDialog *RigDlg)
    {
        RigDlg->setWindowTitle(QCoreApplication::translate("RigDlg", "Rig Settings", nullptr));
        label_2->setText(QCoreApplication::translate("RigDlg", "Connected Rig", nullptr));
        modified->setText(QCoreApplication::translate("RigDlg", "Modified for DRM", nullptr));
        labelPort->setText(QCoreApplication::translate("RigDlg", "Com Port", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("RigDlg", "S-Meter", nullptr));
        testRig->setText(QCoreApplication::translate("RigDlg", "Test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RigDlg: public Ui_RigDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RIGDLG_H
