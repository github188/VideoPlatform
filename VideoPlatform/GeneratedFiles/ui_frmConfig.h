/********************************************************************************
** Form generated from reading UI file 'frmConfig.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMCONFIG_H
#define UI_FRMCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <switchbutton.h>

QT_BEGIN_NAMESPACE

class Ui_Config
{
public:
    QWidget *widget_main;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QGroupBox *groupBox;
    QLabel *labAppTitle;
    QLineEdit *txtAppTitle;
    QLineEdit *txtIPCType;
    QLineEdit *txtNVRType;
    QLabel *labNVRType;
    QLabel *labIPCType;
    QLabel *labUseVideoOffLineCheck;
    QComboBox *cboxVideoOffLineCheckInterval;
    QLabel *labPollType;
    QComboBox *cboxDelayTime;
    QPushButton *btnClearIPC;
    QLabel *labVideoOffLineCheckInterval;
    QLabel *labSec;
    QLabel *labDelayTime;
    QLabel *labSec1;
    QComboBox *cboxRtspType;
    QPushButton *btnClearAll;
    QLabel *labRtspType;
    QComboBox *cboxPollSleep;
    QComboBox *cboxPollType;
    QComboBox *cboxPollInterval;
    QPushButton *btnClearPoll;
    QLabel *labSec2;
    QLabel *labPollInterval;
    SwitchButton *btnAutoPoll;
    QPushButton *btnClearNVR;
    QLabel *labPollSleep;
    QLabel *labAutoPoll;
    SwitchButton *btnAutoRun;
    SwitchButton *btnUseVideoOffLineCheck;
    QLabel *labAutoRun;
    QLabel *labMsec;
    QWidget *widget_title;
    QLabel *lab_Ico;
    QLabel *lab_Title;

    void setupUi(QDialog *Config)
    {
        if (Config->objectName().isEmpty())
            Config->setObjectName(QStringLiteral("Config"));
        Config->resize(654, 404);
        widget_main = new QWidget(Config);
        widget_main->setObjectName(QStringLiteral("widget_main"));
        widget_main->setGeometry(QRect(1, 29, 652, 373));
        btnOk = new QPushButton(widget_main);
        btnOk->setObjectName(QStringLiteral("btnOk"));
        btnOk->setGeometry(QRect(450, 330, 91, 32));
        btnOk->setMinimumSize(QSize(0, 28));
        QIcon icon;
        QString iconThemeName = QStringLiteral("update.png");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        btnOk->setIcon(icon);
        btnOk->setIconSize(QSize(20, 20));
        btnCancel = new QPushButton(widget_main);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(550, 330, 91, 32));
        btnCancel->setMinimumSize(QSize(0, 28));
        groupBox = new QGroupBox(widget_main);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 631, 311));
        labAppTitle = new QLabel(groupBox);
        labAppTitle->setObjectName(QStringLiteral("labAppTitle"));
        labAppTitle->setGeometry(QRect(20, 20, 71, 31));
        txtAppTitle = new QLineEdit(groupBox);
        txtAppTitle->setObjectName(QStringLiteral("txtAppTitle"));
        txtAppTitle->setGeometry(QRect(100, 20, 511, 28));
        txtIPCType = new QLineEdit(groupBox);
        txtIPCType->setObjectName(QStringLiteral("txtIPCType"));
        txtIPCType->setGeometry(QRect(100, 100, 511, 28));
        txtNVRType = new QLineEdit(groupBox);
        txtNVRType->setObjectName(QStringLiteral("txtNVRType"));
        txtNVRType->setGeometry(QRect(100, 60, 511, 28));
        labNVRType = new QLabel(groupBox);
        labNVRType->setObjectName(QStringLiteral("labNVRType"));
        labNVRType->setGeometry(QRect(20, 60, 71, 31));
        labIPCType = new QLabel(groupBox);
        labIPCType->setObjectName(QStringLiteral("labIPCType"));
        labIPCType->setGeometry(QRect(20, 100, 71, 31));
        labUseVideoOffLineCheck = new QLabel(groupBox);
        labUseVideoOffLineCheck->setObjectName(QStringLiteral("labUseVideoOffLineCheck"));
        labUseVideoOffLineCheck->setGeometry(QRect(20, 220, 71, 31));
        cboxVideoOffLineCheckInterval = new QComboBox(groupBox);
        cboxVideoOffLineCheckInterval->setObjectName(QStringLiteral("cboxVideoOffLineCheckInterval"));
        cboxVideoOffLineCheckInterval->setGeometry(QRect(290, 220, 71, 28));
        labPollType = new QLabel(groupBox);
        labPollType->setObjectName(QStringLiteral("labPollType"));
        labPollType->setGeometry(QRect(210, 180, 71, 31));
        cboxDelayTime = new QComboBox(groupBox);
        cboxDelayTime->setObjectName(QStringLiteral("cboxDelayTime"));
        cboxDelayTime->setGeometry(QRect(490, 220, 71, 28));
        btnClearIPC = new QPushButton(groupBox);
        btnClearIPC->setObjectName(QStringLiteral("btnClearIPC"));
        btnClearIPC->setGeometry(QRect(170, 260, 141, 32));
        btnClearIPC->setCursor(QCursor(Qt::PointingHandCursor));
        labVideoOffLineCheckInterval = new QLabel(groupBox);
        labVideoOffLineCheckInterval->setObjectName(QStringLiteral("labVideoOffLineCheckInterval"));
        labVideoOffLineCheckInterval->setGeometry(QRect(210, 220, 71, 31));
        labSec = new QLabel(groupBox);
        labSec->setObjectName(QStringLiteral("labSec"));
        labSec->setGeometry(QRect(370, 220, 21, 31));
        labDelayTime = new QLabel(groupBox);
        labDelayTime->setObjectName(QStringLiteral("labDelayTime"));
        labDelayTime->setGeometry(QRect(410, 220, 71, 31));
        labSec1 = new QLabel(groupBox);
        labSec1->setObjectName(QStringLiteral("labSec1"));
        labSec1->setGeometry(QRect(570, 140, 31, 31));
        cboxRtspType = new QComboBox(groupBox);
        cboxRtspType->setObjectName(QStringLiteral("cboxRtspType"));
        cboxRtspType->setGeometry(QRect(290, 140, 101, 28));
        btnClearAll = new QPushButton(groupBox);
        btnClearAll->setObjectName(QStringLiteral("btnClearAll"));
        btnClearAll->setGeometry(QRect(470, 260, 141, 32));
        btnClearAll->setCursor(QCursor(Qt::PointingHandCursor));
        labRtspType = new QLabel(groupBox);
        labRtspType->setObjectName(QStringLiteral("labRtspType"));
        labRtspType->setGeometry(QRect(210, 140, 71, 31));
        cboxPollSleep = new QComboBox(groupBox);
        cboxPollSleep->setObjectName(QStringLiteral("cboxPollSleep"));
        cboxPollSleep->setGeometry(QRect(490, 140, 71, 28));
        cboxPollType = new QComboBox(groupBox);
        cboxPollType->setObjectName(QStringLiteral("cboxPollType"));
        cboxPollType->setGeometry(QRect(290, 180, 101, 28));
        cboxPollInterval = new QComboBox(groupBox);
        cboxPollInterval->setObjectName(QStringLiteral("cboxPollInterval"));
        cboxPollInterval->setGeometry(QRect(490, 180, 71, 28));
        btnClearPoll = new QPushButton(groupBox);
        btnClearPoll->setObjectName(QStringLiteral("btnClearPoll"));
        btnClearPoll->setGeometry(QRect(320, 260, 141, 32));
        btnClearPoll->setCursor(QCursor(Qt::PointingHandCursor));
        labSec2 = new QLabel(groupBox);
        labSec2->setObjectName(QStringLiteral("labSec2"));
        labSec2->setGeometry(QRect(570, 180, 21, 31));
        labPollInterval = new QLabel(groupBox);
        labPollInterval->setObjectName(QStringLiteral("labPollInterval"));
        labPollInterval->setGeometry(QRect(410, 180, 71, 31));
        btnAutoPoll = new SwitchButton(groupBox);
        btnAutoPoll->setObjectName(QStringLiteral("btnAutoPoll"));
        btnAutoPoll->setGeometry(QRect(100, 180, 87, 28));
        btnClearNVR = new QPushButton(groupBox);
        btnClearNVR->setObjectName(QStringLiteral("btnClearNVR"));
        btnClearNVR->setGeometry(QRect(20, 260, 141, 32));
        btnClearNVR->setCursor(QCursor(Qt::PointingHandCursor));
        labPollSleep = new QLabel(groupBox);
        labPollSleep->setObjectName(QStringLiteral("labPollSleep"));
        labPollSleep->setGeometry(QRect(410, 140, 71, 31));
        labAutoPoll = new QLabel(groupBox);
        labAutoPoll->setObjectName(QStringLiteral("labAutoPoll"));
        labAutoPoll->setGeometry(QRect(20, 180, 71, 31));
        btnAutoRun = new SwitchButton(groupBox);
        btnAutoRun->setObjectName(QStringLiteral("btnAutoRun"));
        btnAutoRun->setGeometry(QRect(100, 140, 87, 28));
        btnUseVideoOffLineCheck = new SwitchButton(groupBox);
        btnUseVideoOffLineCheck->setObjectName(QStringLiteral("btnUseVideoOffLineCheck"));
        btnUseVideoOffLineCheck->setGeometry(QRect(100, 220, 87, 28));
        labAutoRun = new QLabel(groupBox);
        labAutoRun->setObjectName(QStringLiteral("labAutoRun"));
        labAutoRun->setGeometry(QRect(20, 140, 71, 31));
        labMsec = new QLabel(groupBox);
        labMsec->setObjectName(QStringLiteral("labMsec"));
        labMsec->setGeometry(QRect(570, 220, 31, 31));
        widget_title = new QWidget(Config);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        widget_title->setGeometry(QRect(1, 1, 652, 28));
        widget_title->setMinimumSize(QSize(100, 28));
        lab_Ico = new QLabel(widget_title);
        lab_Ico->setObjectName(QStringLiteral("lab_Ico"));
        lab_Ico->setGeometry(QRect(0, 0, 31, 28));
        lab_Ico->setMinimumSize(QSize(31, 0));
        lab_Title = new QLabel(widget_title);
        lab_Title->setObjectName(QStringLiteral("lab_Title"));
        lab_Title->setGeometry(QRect(31, 0, 581, 28));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lab_Title->sizePolicy().hasHeightForWidth());
        lab_Title->setSizePolicy(sizePolicy);

        retranslateUi(Config);

        QMetaObject::connectSlotsByName(Config);
    } // setupUi

    void retranslateUi(QDialog *Config)
    {
        Config->setWindowTitle(QApplication::translate("Config", "Dialog", 0));
        btnOk->setText(QApplication::translate("Config", "Ok", 0));
        btnCancel->setText(QApplication::translate("Config", "Cancle", 0));
        groupBox->setTitle(QString());
        labAppTitle->setText(QApplication::translate("Config", "\350\275\257\344\273\266\346\240\207\351\242\230", 0));
        labNVRType->setText(QApplication::translate("Config", "NVR\345\216\202\345\225\206", 0));
        labIPCType->setText(QApplication::translate("Config", "IPC\345\216\202\345\225\206", 0));
        labUseVideoOffLineCheck->setText(QApplication::translate("Config", "\347\246\273\347\272\277\346\243\200\346\265\213", 0));
        labPollType->setText(QApplication::translate("Config", "\350\275\256\350\257\242\347\224\273\351\235\242", 0));
        btnClearIPC->setText(QApplication::translate("Config", "\346\270\205\347\251\272IPC\344\277\241\346\201\257", 0));
        labVideoOffLineCheckInterval->setText(QApplication::translate("Config", "\346\243\200\346\265\213\351\227\264\351\232\224", 0));
        labSec->setText(QApplication::translate("Config", "\347\247\222", 0));
        labDelayTime->setText(QApplication::translate("Config", "\347\274\223\345\255\230\346\227\266\351\227\264", 0));
        labSec1->setText(QApplication::translate("Config", "\346\257\253\347\247\222", 0));
        cboxRtspType->clear();
        cboxRtspType->insertItems(0, QStringList()
         << QApplication::translate("Config", "\344\270\273\347\240\201\346\265\201", 0)
         << QApplication::translate("Config", "\345\255\220\347\240\201\346\265\201", 0)
        );
        btnClearAll->setText(QApplication::translate("Config", "\346\201\242\345\244\215\345\207\272\345\216\202\345\200\274", 0));
        labRtspType->setText(QApplication::translate("Config", "\347\240\201\346\265\201\347\261\273\345\236\213", 0));
        cboxPollType->clear();
        cboxPollType->insertItems(0, QStringList()
         << QApplication::translate("Config", "1\347\224\273\351\235\242", 0)
         << QApplication::translate("Config", "4\347\224\273\351\235\242", 0)
         << QApplication::translate("Config", "9\347\224\273\351\235\242", 0)
         << QApplication::translate("Config", "16\347\224\273\351\235\242", 0)
        );
        btnClearPoll->setText(QApplication::translate("Config", "\346\270\205\347\251\272\350\275\256\350\257\242\344\277\241\346\201\257", 0));
        labSec2->setText(QApplication::translate("Config", "\347\247\222", 0));
        labPollInterval->setText(QApplication::translate("Config", "\350\275\256\350\257\242\351\227\264\351\232\224", 0));
        btnAutoPoll->setText(QString());
        btnClearNVR->setText(QApplication::translate("Config", "\346\270\205\347\251\272NVR\344\277\241\346\201\257", 0));
        labPollSleep->setText(QApplication::translate("Config", "\350\275\256\350\257\242\345\273\266\346\227\266", 0));
        labAutoPoll->setText(QApplication::translate("Config", "\350\207\252\345\212\250\350\275\256\350\257\242", 0));
        btnAutoRun->setText(QString());
        btnUseVideoOffLineCheck->setText(QString());
        labAutoRun->setText(QApplication::translate("Config", "\345\274\200\346\234\272\345\220\257\345\212\250", 0));
        labMsec->setText(QApplication::translate("Config", "\346\257\253\347\247\222", 0));
        lab_Ico->setText(QString());
        lab_Title->setText(QApplication::translate("Config", "\347\263\273\347\273\237\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class Config: public Ui_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMCONFIG_H
