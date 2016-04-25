#include <QtGui>
#include <QtWidgets/QApplication>
#include <qmenu.h>
#include "userTreeWidget.h"

/* 构造函数 */
CUserTreeWidget::CUserTreeWidget(QWidget *parent):QTreeWidget(parent)
{
    /* 允许拖拽 */
    setAcceptDrops(true);
    setDragDropMode(QAbstractItemView::InternalMove);

    /* 构建槽函数 */
    connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(onItemClicked(const QPoint&)));
}

/* 自定义press事件 */
void CUserTreeWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        /* 保存当前鼠标的位置 */
        m_startPos = event->pos();
    }
    else if (event->button() == Qt::RightButton)
    {
        QTreeWidgetItem *treeItem = this->currentItem();
        if(NULL == treeItem)
        {
            qDebug("空白处");
        }
        else if(treeItem->childCount() > 0)
        {
            qDebug("----123123123");
        }
        else if(treeItem->childCount() == 0)
        {
            qDebug("niaho");
        }

        if(treeItem->parent() == NULL)
        {
            qDebug("no parent");
        }
//         qDebug("rightButton pressed!");
//         QMenu *menu = new QMenu(this);
//         QAction *addAction = new QAction("add", this);
//         QAction *delAction = new QAction("del", this);
//         QAction *modAction = new QAction("mod", this);
// 
//         menu->addAction(addAction);
//         menu->addAction(delAction);
//         menu->addAction(modAction);
//         menu->exec(QCursor::pos());
    }

    QTreeWidget::mouseMoveEvent(event);
}

/* 自定义Move事件 */
void CUserTreeWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        /* 计算鼠标当前所在位置是否大于曼哈顿距离，即不处理鼠标抖动所产生的事件 */
        int distance = (event->pos() - m_startPos).manhattanLength();
        if(distance >= QApplication::startDragDistance())
        {
            /* 调用响应的处理函数 */
            performDrag();
        }
    }

    QTreeWidget::mouseMoveEvent(event);
}

/* 自定义drag事件 */
void CUserTreeWidget::dragEnterEvent(QDragEnterEvent *event)
{

}

/* 自定义dragMove事件 */
void CUserTreeWidget::dragMoveEvent(QDragMoveEvent *event)
{

}

/* 自定义drop事件 */
void CUserTreeWidget::dropEvent(QDropEvent *event)
{
     qDebug("-----2222-");
     QTreeWidget::dropEvent(event);
}

/* 拖动过程中显示函数 */
void CUserTreeWidget::performDrag()
{
    /* 获取当前点击的是哪一个条目 */
    QTreeWidgetItem *item = currentItem();
    QString strName("nihao");
    if(item)
    {
        QMimeData *mimeData = new QMimeData;
        mimeData->setText(strName);
        mimeData->setData("text", strName.toUtf8());

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        QPixmap drag_img(":/VideoPlatform/Resources/image/ipc_normal.bmp");  
        QPainter painter(this);
        painter.drawPixmap(100, 10, drag_img);
        drag->setPixmap(drag_img); 
        /* 设置跟随图片的中心 */
        drag->setHotSpot(QPoint(15, 5));
        if(drag->exec(Qt::MoveAction) == Qt::MoveAction)
        {
            delete item;
        }
    }
}

/* 重构contextMenuEvent函数 */
void CUserTreeWidget::contextMemuEvent(QContextMenuEvent *event)
{
    QTreeWidgetItem *treeItem = this->currentItem();
    if(NULL == treeItem)
    {
        qDebug("空白处");
    }
    else if(treeItem->childCount() > 0)
    {
        qDebug("----123123123");
    }
    else if(treeItem->childCount() == 0)
    {
        qDebug("niaho");
    }

    event->accept();

    return ;
}

void CUserTreeWidget::onItemClicked(const QPoint&)
{
    return ;
}





