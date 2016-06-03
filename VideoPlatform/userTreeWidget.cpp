#include <QtGui>
#include <QtWidgets/QApplication>
#include <qmenu.h>
#include "userTreeWidget.h"
#include <QContextMenuEvent> 

/* ���캯�� */
CUserTreeWidget::CUserTreeWidget(QWidget *parent):QTreeWidget(parent)
{
    /* ������ק */
    setAcceptDrops(false);
    setDragDropMode(QAbstractItemView::InternalMove);
    setContextMenuPolicy(Qt::CustomContextMenu);
//    setEditTriggers(QAbstractItemView::NoEditTriggers);

    /* �����ۺ��� */
    connect(this, SIGNAL(itemPressed(QTreeWidgetItem*, int)), this, SLOT(onItemClicked(QTreeWidgetItem*, int)));
//    connect(this, &CUserTreeWidget::itemPressed, this, &CUserTreeWidget::onItemClicked);
}

/* �Զ���press�¼� */
// void CUserTreeWidget::mousePressEvent(QMouseEvent *event)
// {
//     if(event->button() == Qt::LeftButton)
//     {
//         /* ���浱ǰ����λ�� */
//         m_startPos = event->pos();
//     }
//     else if (event->button() == Qt::RightButton)
//     {
//         QTreeWidgetItem *treeItem = this->currentItem();
//         if(NULL == treeItem)
//         {
//             qDebug("�հ״�");
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

/* �Զ���Move�¼� */
void CUserTreeWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        /* ������굱ǰ����λ���Ƿ���������پ��룬����������궶�����������¼� */
        int distance = (event->pos() - m_startPos).manhattanLength();
        if(distance >= QApplication::startDragDistance())
        {
            /* ������Ӧ�Ĵ����� */
            performDrag();
        }
    }

    QTreeWidget::mouseMoveEvent(event);
}

/* �Զ���������¼� */
void CUserTreeWidget::mouseReleaseEvent(QMouseEvent *event)
{
    return;
}

/* �Զ���drag�¼� */
void CUserTreeWidget::dragEnterEvent(QDragEnterEvent *event)
{

}

/* �Զ���dragMove�¼� */
void CUserTreeWidget::dragMoveEvent(QDragMoveEvent *event)
{

}

/* �Զ���drop�¼� */
void CUserTreeWidget::dropEvent(QDropEvent *event)
{
     QTreeWidget::dropEvent(event);
}

/* �϶���������ʾ���� */
void CUserTreeWidget::performDrag()
{
    /* ��ȡ��ǰ���������һ����Ŀ */
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
        /* ���ø���ͼƬ������ */
        drag->setHotSpot(QPoint(15, 5));
        if(drag->exec(Qt::MoveAction) == Qt::MoveAction)
        {
            delete item;
        }
    }
}

/* �ع�contextMenuEvent���� */
void CUserTreeWidget::contextMemuEvent(QContextMenuEvent *event)
{
    return ;
}

void CUserTreeWidget::onItemClicked(QTreeWidgetItem *item, int column)
{
    return ;
}





