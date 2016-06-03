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
//    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);

private slots:
    void onItemClicked(QTreeWidgetItem*, int);
    void contextMemuEvent(QContextMenuEvent *event);

private:
    /* �϶���������ʾ���� */
    void performDrag();

    /* ������ʵλ�� */
    QPoint m_startPos;
};

#endif
