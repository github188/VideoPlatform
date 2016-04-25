#include <QtGui>
#include <QtWidgets/QApplication>
#include <qmenu.h>
#include "userTreeWidget.h"

/* ���캯�� */
CUserTreeWidget::CUserTreeWidget(QWidget *parent):QTreeWidget(parent)
{
    /* ������ק */
    setAcceptDrops(true);
    setDragDropMode(QAbstractItemView::InternalMove);

    /* �����ۺ��� */
    connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(onItemClicked(const QPoint&)));
}

/* �Զ���press�¼� */
void CUserTreeWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        /* ���浱ǰ����λ�� */
        m_startPos = event->pos();
    }
    else if (event->button() == Qt::RightButton)
    {
        QTreeWidgetItem *treeItem = this->currentItem();
        if(NULL == treeItem)
        {
            qDebug("�հ״�");
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
     qDebug("-----2222-");
     QTreeWidget::dropEvent(event);
}

/* �϶���������ʾ���� */
void CUserTreeWidget::performDrag()
{
    /* ��ȡ��ǰ���������һ����Ŀ */
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
    QTreeWidgetItem *treeItem = this->currentItem();
    if(NULL == treeItem)
    {
        qDebug("�հ״�");
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





