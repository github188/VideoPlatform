#ifndef __USERTREEWIDGET__
#define __USERTREEWIDGET__

#include <QTreeWidget>

class CUserTreeWidget:public QTreeWidget
{
    Q_OBJECT
public:
    /* 构造函数 */
    CUserTreeWidget(QWidget *parent = 0);
    ~CUserTreeWidget(){};

protected:
    /* 自定义拖拽功能 */
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void contextMemuEvent(QContextMenuEvent *event);

private slots:
    void onItemClicked(const QPoint&);

private:
    /* 拖动过程中显示函数 */
    void performDrag();

    /* 保存其实位置 */
    QPoint m_startPos;
};

#endif
