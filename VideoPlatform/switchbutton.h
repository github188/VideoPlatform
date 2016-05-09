#ifndef __SWITCHBUTTON__H_
#define __SWITCHBUTTON__H_

#include <QPushButton>

class SwitchButton : public QPushButton
{
    Q_OBJECT
public:
    explicit SwitchButton(QWidget *parent = 0);

    /* 获取当前选中的状态 */
    bool GetCheck() const
    {
        return isCheck;
    }

    /* 设置当前选中的状态 */
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