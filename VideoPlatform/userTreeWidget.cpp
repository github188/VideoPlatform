#include <QtGui>
#include <QtWidgets/QApplication>
#include <qmenu.h>
#include "userTreeWidget.h"
#include <QContextMenuEvent> 

/* 构造函数 */
CUserTreeWidget::CUserTreeWidget(QWidget *parent):QTreeWidget(parent)
{
    /* 允许拖拽 */
    setAcceptDrops(false);
    setDragDropMode(QAbstractItemView::InternalMove);
    setContextMenuPolicy(Qt::CustomContextMenu);
//    setEditTriggers(QAbstractItemView::NoEditTriggers);

    /* 构建槽函数 */
    connect(this, SIGNAL(itemPressed(QTreeWidgetItem*, int)), this, SLOT(onItemClicked(QTreeWidgetItem*, int)));
//    connect(this, &CUserTreeWidget::itemPressed, this, &CUserTreeWidget::onItemClicked);
}

/* 自定义press事件 */
// void CUserTreeWidget::mousePressEvent(QMouseEvent *event)
// {
//     if(event->button() == Qt::LeftButton)
//     {
//         /* 保存当前鼠标的位置 */
//         m_startPos = event->pos();
//     }
//     else if (event->button() == Qt::RightButton)
//     {
//         QTreeWidgetItem *treeItem = this->currentItem();
//         if(NULL == treeItem)
//         {
//             qDebug("空白处");
//         }
//         else if(treeItem->childCount() > 0)
//         {
//             int itemCount;/*= treeItem->childCount();*/
//             itemCount = treeItem->columnCount();
// 
//             qDebug("----itemCount = %d", qPrintable(itemCount));
//             qDebug("rightButton pressed!");
//             QMenu *menu = new QMenu(this);
//             QAction *addAction = new QAction("add", this);
//             QAction *delAction = new QAction("del", this);
//             QAction *modAction = new QAction("mod", this);
// 
//             menu->addAction(addAction);
//             menu->addAction(delAction);
//             menu->addAction(modAction);
//             menu->exec(QCursor::pos());
//         }
//         else if(treeItem->childCount() == 0)
//         {
//             qDebug("niaho");
//         }
// 
//         if(treeItem->parent() == NULL)
//         {
//             qDebug("no parent");
//         }
//     }
// 
//     QTreeWidget::mouseMoveEvent(event);
// }

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

/* 自定义鼠标点击事件 */
void CUserTreeWidget::mouseReleaseEvent(QMouseEvent *event)
{
    return;
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
     QTreeWidget::dropEvent(event);
}

/* 拖动过程中显示函数 */
void CUserTreeWidget::performDrag()
{
    /* 获取当前点击的是哪一个条目 */
    QTreeWidgetItem *item = currentItem();
    QString strItemData = item->text(0);
    QByteArray itemByteArray = strItemData.toLocal8Bit();
    if(item)
    {
        QMimeData *mimeData = new QMimeData;
        mimeData->setText(itemByteArray.data());
        mimeData->setData("text", itemByteArray.data());

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);

        QPixmap drag_img(":/VideoPlatform/Resources/image/ipc_normal.png");  
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
    return ;
}

void CUserTreeWidget::onItemClicked(QTreeWidgetItem *item, int column)
{
    return ;
}





