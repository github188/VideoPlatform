/********************************************************************************
** Form generated from reading UI file 'alarm.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARM_H
#define UI_ALARM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_alarm
{
public:
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QComboBox *comboBox_5;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox_6;
    QComboBox *comboBox_7;
    QPushButton *pushButton_2;

    void setupUi(QDialog *alarm)
    {
        if (alarm->objectName().isEmpty())
            alarm->setObjectName(QStringLiteral("alarm"));
        alarm->resize(654, 404);
        tableWidget = new QTableWidget(alarm);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 10, 361, 391));
        groupBox = new QGroupBox(alarm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(370, 10, 281, 161));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(100, 30, 121, 31));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 81, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 80, 81, 31));
        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(100, 80, 121, 31));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 120, 81, 31));
        groupBox_2 = new QGroupBox(alarm);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(370, 180, 281, 201));
        comboBox_3 = new QComboBox(groupBox_2);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(20, 60, 69, 22));
        comboBox_4 = new QComboBox(groupBox_2);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(90, 60, 69, 22));
        comboBox_5 = new QComboBox(groupBox_2);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        comboBox_5->setGeometry(QRect(160, 60, 69, 22));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 30, 121, 21));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 90, 61, 31));
        comboBox_6 = new QComboBox(groupBox_2);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));
        comboBox_6->setGeometry(QRect(20, 120, 69, 22));
        comboBox_7 = new QComboBox(groupBox_2);
        comboBox_7->setObjectName(QStringLiteral("comboBox_7"));
        comboBox_7->setGeometry(QRect(90, 120, 69, 22));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 160, 81, 31));

        retranslateUi(alarm);

        QMetaObject::connectSlotsByName(alarm);
    } // setupUi

    void retranslateUi(QDialog *alarm)
    {
        alarm->setWindowTitle(QApplication::translate("alarm", "Alarm", 0));
        groupBox->setTitle(QApplication::translate("alarm", "\345\221\212\350\255\246\350\256\242\351\230\205", 0));
        label->setText(QApplication::translate("alarm", "\351\200\211\346\213\251\350\256\276\345\244\207", 0));
        label_2->setText(QApplication::translate("alarm", "\345\221\212\350\255\246\347\261\273\345\236\213", 0));
        pushButton->setText(QApplication::translate("alarm", "\350\256\242\351\230\205", 0));
        groupBox_2->setTitle(QApplication::translate("alarm", "\345\221\212\350\255\246\350\201\224\345\212\250", 0));
        label_3->setText(QApplication::translate("alarm", "\351\200\211\346\213\251\350\256\276\345\244\207\345\222\214\345\221\212\350\255\246\347\261\273\345\236\213", 0));
        label_4->setText(QApplication::translate("alarm", "\350\201\224\345\212\250\345\210\260", 0));
        pushButton_2->setText(QApplication::translate("alarm", "\345\221\212\350\255\246\350\201\224\345\212\250", 0));
    } // retranslateUi

};

namespace Ui {
    class alarm: public Ui_alarm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARM_H
