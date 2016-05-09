/********************************************************************************
** Form generated from reading UI file 'videoplatform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPLATFORM_H
#define UI_VIDEOPLATFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "userTreeWidget.h"

QT_BEGIN_NAMESPACE

class Ui_VideoPlatformClass
{
public:
    QWidget *widget_main;
    CUserTreeWidget *treeMain;
    QGroupBox *gboxMain;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *lay1;
    QLabel *labVideo2;
    QLabel *labVideo1;
    QHBoxLayout *lay2;
    QLabel *labVideo4;
    QLabel *labVideo3;
    QWidget *widget_title;
    QLabel *lab_Icon;
    QWidget *widget_menu;
    QPushButton *btnMenu_Min;
    QPushButton *btnMenu_Close;
    QLabel *labConfig;
    QLabel *labAlarm;
    QLabel *lab_Title;

    void setupUi(QDialog *VideoPlatformClass)
    {
        if (VideoPlatformClass->objectName().isEmpty())
            VideoPlatformClass->setObjectName(QStringLiteral("VideoPlatformClass"));
        VideoPlatformClass->resize(1145, 724);
        widget_main = new QWidget(VideoPlatformClass);
        widget_main->setObjectName(QStringLiteral("widget_main"));
        widget_main->setGeometry(QRect(1, 29, 1143, 691));
        treeMain = new CUserTreeWidget(widget_main);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeMain->setHeaderItem(__qtreewidgetitem);
        treeMain->setObjectName(QStringLiteral("treeMain"));
        treeMain->setGeometry(QRect(5, 5, 256, 681));
        treeMain->setContextMenuPolicy(Qt::CustomContextMenu);
        treeMain->setAcceptDrops(false);
        gboxMain = new QGroupBox(widget_main);
        gboxMain->setObjectName(QStringLiteral("gboxMain"));
        gboxMain->setGeometry(QRect(266, 5, 881, 691));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gboxMain->sizePolicy().hasHeightForWidth());
        gboxMain->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(gboxMain);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 5, 8);
        lay1 = new QHBoxLayout();
        lay1->setSpacing(0);
        lay1->setObjectName(QStringLiteral("lay1"));
        labVideo2 = new QLabel(gboxMain);
        labVideo2->setObjectName(QStringLiteral("labVideo2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labVideo2->sizePolicy().hasHeightForWidth());
        labVideo2->setSizePolicy(sizePolicy1);
        labVideo2->setFocusPolicy(Qt::StrongFocus);
        labVideo2->setFrameShape(QFrame::Panel);
        labVideo2->setAlignment(Qt::AlignCenter);

        lay1->addWidget(labVideo2);

        labVideo1 = new QLabel(gboxMain);
        labVideo1->setObjectName(QStringLiteral("labVideo1"));
        sizePolicy1.setHeightForWidth(labVideo1->sizePolicy().hasHeightForWidth());
        labVideo1->setSizePolicy(sizePolicy1);
        labVideo1->setFrameShape(QFrame::Panel);
        labVideo1->setAlignment(Qt::AlignCenter);
        labVideo1->setMargin(3);

        lay1->addWidget(labVideo1);


        verticalLayout->addLayout(lay1);

        lay2 = new QHBoxLayout();
        lay2->setSpacing(0);
        lay2->setObjectName(QStringLiteral("lay2"));
        labVideo4 = new QLabel(gboxMain);
        labVideo4->setObjectName(QStringLiteral("labVideo4"));
        sizePolicy1.setHeightForWidth(labVideo4->sizePolicy().hasHeightForWidth());
        labVideo4->setSizePolicy(sizePolicy1);
        labVideo4->setFrameShape(QFrame::Panel);
        labVideo4->setAlignment(Qt::AlignCenter);

        lay2->addWidget(labVideo4);

        labVideo3 = new QLabel(gboxMain);
        labVideo3->setObjectName(QStringLiteral("labVideo3"));
        labVideo3->setEnabled(true);
        sizePolicy1.setHeightForWidth(labVideo3->sizePolicy().hasHeightForWidth());
        labVideo3->setSizePolicy(sizePolicy1);
        labVideo3->setContextMenuPolicy(Qt::CustomContextMenu);
        labVideo3->setFrameShape(QFrame::Panel);
        labVideo3->setAlignment(Qt::AlignCenter);
        labVideo3->setIndent(-3);

        lay2->addWidget(labVideo3);


        verticalLayout->addLayout(lay2);

        widget_title = new QWidget(VideoPlatformClass);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        widget_title->setGeometry(QRect(1, 1, 1143, 28));
        lab_Icon = new QLabel(widget_title);
        lab_Icon->setObjectName(QStringLiteral("lab_Icon"));
        lab_Icon->setGeometry(QRect(0, 0, 30, 28));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lab_Icon->sizePolicy().hasHeightForWidth());
        lab_Icon->setSizePolicy(sizePolicy2);
        lab_Icon->setMinimumSize(QSize(30, 0));
        widget_menu = new QWidget(widget_title);
        widget_menu->setObjectName(QStringLiteral("widget_menu"));
        widget_menu->setGeometry(QRect(670, 0, 471, 28));
        btnMenu_Min = new QPushButton(widget_menu);
        btnMenu_Min->setObjectName(QStringLiteral("btnMenu_Min"));
        btnMenu_Min->setGeometry(QRect(390, 0, 40, 28));
        btnMenu_Close = new QPushButton(widget_menu);
        btnMenu_Close->setObjectName(QStringLiteral("btnMenu_Close"));
        btnMenu_Close->setGeometry(QRect(430, 0, 40, 28));
        btnMenu_Close->setFocusPolicy(Qt::NoFocus);
        labConfig = new QLabel(widget_menu);
        labConfig->setObjectName(QStringLiteral("labConfig"));
        labConfig->setGeometry(QRect(330, 0, 52, 28));
        labConfig->setAlignment(Qt::AlignCenter);
        labAlarm = new QLabel(widget_menu);
        labAlarm->setObjectName(QStringLiteral("labAlarm"));
        labAlarm->setGeometry(QRect(270, 0, 52, 28));
        labAlarm->setAlignment(Qt::AlignCenter);
        lab_Title = new QLabel(widget_title);
        lab_Title->setObjectName(QStringLiteral("lab_Title"));
        lab_Title->setGeometry(QRect(30, 0, 438, 28));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lab_Title->sizePolicy().hasHeightForWidth());
        lab_Title->setSizePolicy(sizePolicy3);

        retranslateUi(VideoPlatformClass);

        QMetaObject::connectSlotsByName(VideoPlatformClass);
    } // setupUi

    void retranslateUi(QDialog *VideoPlatformClass)
    {
        VideoPlatformClass->setWindowTitle(QApplication::translate("VideoPlatformClass", "frmMain", 0));
        labVideo2->setText(QString());
        labVideo1->setText(QString());
        labVideo4->setText(QString());
#ifndef QT_NO_TOOLTIP
        labVideo3->setToolTip(QApplication::translate("VideoPlatformClass", "<html><head/><body><p>???</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        labVideo3->setText(QString());
        lab_Icon->setText(QString());
        btnMenu_Min->setText(QApplication::translate("VideoPlatformClass", "Min", 0));
        btnMenu_Close->setText(QApplication::translate("VideoPlatformClass", "close", 0));
        labConfig->setText(QApplication::translate("VideoPlatformClass", "\347\263\273\347\273\237\350\256\276\347\275\256", 0));
        labAlarm->setText(QApplication::translate("VideoPlatformClass", "\345\221\212\350\255\246", 0));
        lab_Title->setText(QApplication::translate("VideoPlatformClass", "??????", 0));
    } // retranslateUi

};

namespace Ui {
    class VideoPlatformClass: public Ui_VideoPlatformClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPLATFORM_H
