#ifndef __USERTREEWIDGET__
#define __USERTREEWIDGET__

#include <QTreeWidget>

class CUserTreeWidget:public QTreeWidget
{
    Q_OBJECT
public:
    /* ���캯�� */
    CUserTreeWidget(QWidget *parent = 0);
    ~CUserTreeWidget(){};

protected:
    /* �Զ�����ק���� */
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void contextMemuEvent(QContextMenuEvent *event);

private slots:
    void onItemClicked(const QPoint&);

private:
    /* �϶���������ʾ���� */
    void performDrag();

    /* ������ʵλ�� */
    QPoint m_startPos;
};

#endif
