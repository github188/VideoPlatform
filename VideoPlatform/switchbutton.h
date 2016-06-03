#ifndef __SWITCHBUTTON__H_
#define __SWITCHBUTTON__H_

#include <QPushButton>

class SwitchButton : public QPushButton
{
    Q_OBJECT
public:
    explicit SwitchButton(QWidget *parent = 0);

    /* ��ȡ��ǰѡ�е�״̬ */
    bool GetCheck() const
    {
        return isCheck;
    }

    /* ���õ�ǰѡ�е�״̬ */
    void SetCheck(bool isCheck);

protected:

private:
    bool isCheck;
    QString styleOn;
    QString styleOff;

private slots:
    void ChangeOnOff();

};

#endif