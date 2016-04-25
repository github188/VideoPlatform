#include "videoplatform.h"
#include <QMenu>
#include <QEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>  
#include <QBitmap>
#include <QStyleOption>
#include <QDir>
#include <qlayout.h>
#include <QResizeEvent>
#include <iconhelper.h>
#include <QMimeData>
#include "xmloperator.h"

VideoPlatform::VideoPlatform(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

     this->InitStyle();   /* ��ʼ���ޱ߿��� */
     this->InitForm();    /* ��ʼ���������� */
     this->InitVideo();   /* ��ʼ����Ƶ������������ */
     this->LoadConfig();  /* ���������ļ����� */     

     CXmlOperator xmlOperator;
      //ui.treeMain->setStyleSheet("background-color: #4B8181;");
//      this->setStyleSheet("background-color: #154848;");
/*      ui.treeMain->setAcceptDrops(true);*/
     setAcceptDrops(true);
}

VideoPlatform::~VideoPlatform()
{

}

/* ��ʼ���������� */
void VideoPlatform::InitForm()
{
    QString szTileName = QString::fromWCharArray(L"��Ƶ���ƽ̨");
    //ui.treeMain->header()->setVisible(false);
    //ui.treeMain->setAcceptDrops(true);
    //ui.treeMain->setDragDropMode(QAbstractItemView::InternalMove);
    ui.lab_Title->setText(szTileName);
    this->setWindowTitle(szTileName);
}

/* ��ʼ���ޱ߿��� */
void VideoPlatform::InitStyle()
{
    this->setStyleSheet("QGroupBox#gboxMain{border-width:0px;}");
    this->setProperty("From", true);

    /* ���ô������������--Qt::WindowStaysOnTopHint | */
    this->setWindowFlags(Qt::FramelessWindowHint |
                         Qt::WindowSystemMenuHint |
                         Qt::WindowMinimizeButtonHint);


//      IconHelper::Instance()->SetIcon(ui.btnMenu_Close, QChar(0xf00d), 10);
//      IconHelper::Instance()->SetIcon(ui.btnMenu_Min, QChar(0xf068), 10);
}

/* ��ʼ����Ƶ������������ */
void VideoPlatform::InitVideo()
{
    m_tempLab = 0;
    m_bVideoMax = false;

    m_VideoLab.append(ui.labVideo1);
    m_VideoLab.append(ui.labVideo2);
    m_VideoLab.append(ui.labVideo3);
    m_VideoLab.append(ui.labVideo4);

    m_VideoLay.append(ui.lay1);
    m_VideoLay.append(ui.lay2);

    /* �ڲ��Ž�����ʾͨ���� */
    for(int i = 0; i < 4; i++)
    {
        /* ע���¼� */
        m_VideoLab[i]->installEventFilter(this);
        m_VideoLab[i]->setAcceptDrops(true);
        m_VideoLab[i]->setProperty("labVideo", true);
        m_VideoLab[i]->setText(QString("Channel_%1").arg(i + 1));
    }

    m_VideoChlmenu = new QMenu(this);
    m_VideoChlmenu->setStyleSheet("font: 10pt \"΢���ź�\";");
    m_VideoChlmenu->addAction("close this video", this, SLOT(deleteVideo_one()));
    m_VideoChlmenu->addAction("close all video", this, SLOT(deleteVideo_all()));
    m_VideoChlmenu->addSeparator(); /* ��һ����� */

    QMenu *menu1 = m_VideoChlmenu->addMenu("switch to 1");
    menu1->addAction("Channel", this, SLOT(show_video_1()));
    menu1->addAction("Channel", this, SLOT(show_video_1()));
    menu1->addAction("Channel", this, SLOT(show_video_1()));
    menu1->addAction("Channel", this, SLOT(show_video_1()));

    QMenu *menu4 = m_VideoChlmenu->addMenu("switch to 4");
    menu4->addAction("switch to 4", this, SLOT(show_video_4()));
}

/* ���������ļ����� */
void VideoPlatform::LoadConfig()
{
    ui.treeMain->clear();
    QString temp("haikang");

    /* ģ�⸸�ڵ������ */
    QTreeWidgetItem *itemNVR = new QTreeWidgetItem(ui.treeMain, QStringList(temp + "[" + "208.208.120.191" + "]"));
    /* ���ظ��ڵ��ͼ�� */
    itemNVR->setIcon(0, QIcon(":/VideoPlatform/Resources/image/nvr.png"));

    /* ģ��Ҷ�ӽڵ������ 1 */
    QString leafIPCName1("haikang_1");
    QString leafIPCIP1("208.208.105.89");
    QTreeWidgetItem *itemIpc = new QTreeWidgetItem(itemNVR, QStringList(QString(leafIPCName1 + "[" + leafIPCIP1 + "]")));
    itemIpc->setIcon(0, QIcon(":/VideoPlatform/Resources/image/ipc_normal.bmp"));
    itemNVR->addChild(itemIpc);

    /* ģ��Ҷ�ӽڵ������ 2 */
    QString leafIPCName2("haikang_2");
    QString leafIPCIP2("208.208.105.100");
    itemIpc = new QTreeWidgetItem(itemNVR, QStringList(QString(leafIPCName2 + "[" + leafIPCIP2 + "]")));
    itemIpc->setIcon(0, QIcon(":/VideoPlatform/Resources/image/ipc_normal.bmp"));
    itemNVR->addChild(itemIpc);

    /* ģ��Ҷ�ӽڵ������3 */
    QString leafIPCName3("haikang_3");
    QString leafIPCIP3("208.208.105.101");
    itemIpc = new QTreeWidgetItem(itemNVR, QStringList(QString(leafIPCName3 + "[" + leafIPCIP3 + "]")));
    itemIpc->setIcon(0, QIcon(":/VideoPlatform/Resources/image/ipc_normal.bmp"));
    itemNVR->addChild(itemIpc);

    /*-----------------------------------*/
    QString temp2("haikang2");
    /* ģ����ڵ������ */
    QTreeWidgetItem *itemNVR1 = new QTreeWidgetItem(ui.treeMain, QStringList(temp2 + "[" + "208.208.120.192" + "]"));
    /* ���ظ��ڵ��ͼ�� */
    itemNVR1->setIcon(0, QIcon(":/VideoPlatform/Resources/image/nvr.png"));

    /* ģ��Ҷ�ӽڵ������ 1 */
    QString leafIPCName21("haikang_1");
    QString leafIPCIP21("208.208.105.89");
    QTreeWidgetItem *itemIpc11 = new QTreeWidgetItem(itemNVR1, QStringList(QString(leafIPCName21 + "[" + leafIPCIP21 + "]")));
    itemNVR1->addChild(itemIpc11);
    /* ����Ҷ�ӽڵ��ͼ�� */
    itemIpc11->setIcon(0, QIcon(":/VideoPlatform/Resources/image/ipc_normal.bmp"));

    /* ģ��Ҷ�ӽڵ������ 2 */
    QString leafIPCName22("haikang_2");
    QString leafIPCIP22("208.208.105.100");
    itemIpc11 = new QTreeWidgetItem(itemNVR1, QStringList(QString(leafIPCName22 + "[" + leafIPCIP22 + "]")));
    itemIpc11->setIcon(0, QIcon(":/VideoPlatform/Resources/image/ipc_normal.bmp"));
    itemNVR1->addChild(itemIpc11);

    /* ģ��Ҷ�ӽڵ������3 */
    QString leafIPCName33("haikang_3");
    QString leafIPCIP33("208.208.105.101");
    itemIpc11 = new QTreeWidgetItem(itemNVR1, QStringList(QString(leafIPCName3 + "[" + leafIPCIP3 + "]")));
    itemIpc11->setIcon(0, QIcon(":/VideoPlatform/Resources/image/ipc_normal.bmp"));
    itemNVR1->addChild(itemIpc11);

    ui.treeMain->expandAll();
}

/* ɾ��һ·ʵ�� */
void VideoPlatform::deleteVideo_one()
{

}

/* ɾ������ʵ�� */
void VideoPlatform::deleteVideo_all()
{

}

/* �л���ʽ */
void VideoPlatform::change_style()
{

}

/* ȫ��ģʽ */
void VideoPlatform::screen_full()
{

}

/* ��ͨģʽ */
void VideoPlatform::screen_normal()
{

}

/* �л���1���� */
void VideoPlatform::show_video_1()
{

}

/* �л���4���� */
void VideoPlatform::show_video_4()
{

}

void VideoPlatform::on_btnMenu_Close_clicked()
{
    /* �˳����� */
    exit(0);
}

void VideoPlatform::on_btnMenu_Min_clicked()
{
    this->showMinimized();
}

void VideoPlatform::on_treeMain_doubleClicked(const QModelIndex &index)
{

}

/* �Ƴ����в��� */
void VideoPlatform::removelayout()
{
    for(int i = 0; i < 2; i++)
    {
        m_VideoLay[0]->removeWidget(m_VideoLab[i]);
        m_VideoLab[i]->setVisible(false);
    }
    for(int i = 2; i < 4; i++)
    {
        m_VideoLay[1]->removeWidget(m_VideoLab[i]);
        m_VideoLab[i]->setVisible(false);
    }
}

/* �ı�1���沼�� */
void VideoPlatform::change_video_1(int index)
{

}

/* �ı�4���沼�� */
void VideoPlatform::change_video_4(int index)
{

}

/* �ı�ͨ������ */
void VideoPlatform::ChangeVideoLayout()
{
    for(int i = 0; i < 2; i++)
    {
        m_VideoLay[0]->addWidget(m_VideoLab[i]);
        m_VideoLab[i]->setVisible(true);
    }
    for(int i = 2; i < 4; i++)
    {
        m_VideoLay[1]->addWidget(m_VideoLab[i]);
        m_VideoLab[i]->setVisible(true);
    }
}

/* ��Ӧ�ı�ͨ��rtsp��ַ */
void VideoPlatform::ChangeRtspAddr(int ch, QString rtspAddr)
{

}

/* ��ȡ�������������������ַ */
void VideoPlatform::GetRtspAddr(QString NVRID, QString IPCIP, QString &IPCRtspAddrMain, QString &IPCRtspAddrSub)
{

}

bool VideoPlatform::eventFilter(QObject *obj, QEvent *event)
{
    QMouseEvent *MouseEvent = static_cast<QMouseEvent *>(event);
    if ((event->type() == QEvent::MouseButtonDblClick) && (MouseEvent->buttons() == Qt::LeftButton))
    {
        QLabel *labDouble = qobject_cast<QLabel *>(obj);
        if (!m_bVideoMax)
        {
            removelayout();
            m_bVideoMax = true;
            m_VideoLay[0]->addWidget(labDouble);
            labDouble->setVisible(true);
        }
        else
        {
            m_bVideoMax = false;
            ChangeVideoLayout();
        }

        labDouble->setFocus();
        return true;
    }
    else if(event->type() == QEvent::MouseButtonPress)
    {
        if (MouseEvent->buttons() == Qt::RightButton)
        {
            m_tempLab = qobject_cast<QLabel *>(obj);
            m_VideoChlmenu->exec(QCursor::pos());
            return true;
        }
        else if(obj == ui.btnMenu_Close)
        {
            /* �����˳������� */
            on_btnMenu_Close_clicked();
        }
        else if(obj == ui.btnMenu_Min)
        {
            /* ������С�����ں��� */
            on_btnMenu_Min_clicked();
        }
    }
    else if(event->type() == QEvent::DragEnter)
    {
        QDragEnterEvent *dee = dynamic_cast<QDragEnterEvent*>(event);
        dee->acceptProposedAction();
    }
    else if(event->type() == QEvent::Drop)
    {
        QLabel *labTemp = qobject_cast<QLabel *>(obj);
        if(obj == ui.labVideo1)
        {
            QDropEvent *event1 = static_cast<QDropEvent *>(event);
            const QMimeData *data = event1->mimeData();
            if(data->hasFormat("text"))
            {
                QByteArray csvData = data->data("text");
                QString csvText = QString::fromUtf8(csvData);

                qDebug("---Success--%s-", qPrintable(csvText));
            }
            qDebug("--labVideo1");
        } 
        else if(obj == ui.labVideo2)
        {
            qDebug("---labVideo2");
        }
        else if(obj == ui.labVideo3)
        {
            qDebug("---labVideo3");
        }
        else if(obj == ui.labVideo4)
        {
            qDebug("---labVideo4");
        }
    }

    return QObject::eventFilter(obj, event);
}


void VideoPlatform::keyPressEvent(QKeyEvent *event)
{

}

/* �Զ���ʵ��������ק���� */
void VideoPlatform::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug("-----VideoPlatform::dragEnterEvent-");
}

/* �Զ���ʵ��������ק���� */
void VideoPlatform::dropEvent(QDropEvent *event)
{
     qDebug("111------");
}

/* �Զ��廭ˢ���� */
void VideoPlatform::paintEvent(QPaintEvent *event)
{
//     QPainter painter(this);
//     QLinearGradient linearGradient(100,150,300,150);
//     //�ӵ㣨100��150����ʼ���㣨300��150��������ȷ��һ��ֱ��
//     linearGradient.setColorAt(0,Qt::red);
//     linearGradient.setColorAt(0.2,Qt::black);
//     linearGradient.setColorAt(0.4,Qt::yellow);
//     linearGradient.setColorAt(0.6,Qt::white);
//     linearGradient.setColorAt(0.8,Qt::green);
//     linearGradient.setColorAt(1,Qt::blue);
//     //��ֱ�߿�ʼ����Ϊ0���յ���Ϊ1��Ȼ��ֶ�������ɫ
//     painter.setBrush(linearGradient);
//     painter.drawRect(100,100,200,100);
//     //���ƾ��Σ����Խ����������ھ��ε�ˮƽ��������

//     QRadialGradient radialGradient(200,100,100,200,100);
//     //���в����ֱ�ΪԲ�ν����Բ�ģ�200��100�����뾶100���ͽ��㣨200��100��
//     //�����ý����Բ���غϣ��Ӷ��γɴ�Բ�����⽥���Ч��
//     radialGradient.setColorAt(0,Qt::black);
//     radialGradient.setColorAt(1,Qt::yellow);
//     //����ӽ���������Բ���У�����Ϊ��ʼ��0��Բ�ı߽�Ϊ1
//     QPainter painter(this);
//     painter.setBrush(radialGradient);
//     painter.drawEllipse(200, 200,100,100);
    //����Բ���������ú������Բ�ν����Բ�غ�
}


