#ifndef __FRMCONFIG__H_
#define __FRMCONFIG__H_

#include <QtWidgets/QDialog>
#include "ui_frmConfig.h"

// namespace Ui
// {
//     class frmConfig;
// }

class frmConfig : public QDialog
{
    Q_OBJECT

public:
    explicit frmConfig(QWidget *parent = 0);
    ~frmConfig();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_btnOk_clicked();
    void on_btnClearNVR_clicked();
    void on_btnClearIPC_clicked();
    void on_btnClearPoll_clicked();
    void on_btnClearAll_clicked();

private:
    Ui::Config ui;

    QPoint mousePoint;  //����϶��Զ��������ʱ������
    bool mousePressed;  //����Ƿ���
    void InitStyle();   //��ʼ���ޱ߿򴰿�
    void InitForm();    //��ʼ����������
};

#endif