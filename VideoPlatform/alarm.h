#ifndef __ALARM__H_
#define __ALARM__H_

#include <QtWidgets/QDialog>
#include "ui_alarm.h"

// namespace Ui
// {
//     class alarm;
// }

class alarm : public QDialog
{
    Q_OBJECT

public:
    explicit alarm(QWidget *parent = 0);
    ~alarm();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    private slots:
//         void on_btnOk_clicked();
//         void on_btnClearNVR_clicked();
//         void on_btnClearIPC_clicked();
//         void on_btnClearPoll_clicked();
//         void on_btnClearAll_clicked();

private:
    Ui::alarm ui;

    QPoint mousePoint;  //����϶��Զ��������ʱ������
    bool mousePressed;  //����Ƿ���
    void InitStyle();   //��ʼ���ޱ߿򴰿�
    void InitForm();    //��ʼ����������
};

#endif