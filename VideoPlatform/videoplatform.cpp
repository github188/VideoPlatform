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

     this->InitStyle();   /* 初始化无边框窗体 */
     this->InitForm();    /* 初始化窗体数据 */
     this->InitVideo();   /* 初始化视频布局载体数据 */
     this->LoadConfig();  /* 加载配置文件数据 */     

     CXmlOperator xmlOperator;
      //ui.treeMain->setStyleSheet("background-color: #4B8181;");
//      this->setStyleSheet("background-color: #154848;");
/*      ui.treeMain->setAcceptDrops(true);*/
     setAcceptDrops(true);
}

VideoPlatform::~VideoPlatform()
{

}

/* 初始化窗体数据 */
void VideoPlatform::InitForm()
{
    QString szTileName = QString::fromWCharArray(L"视频监控平台");
    //ui.treeMain->header()->setVisible(false);
    //ui.treeMain->setAcceptDrops(true);
    //ui.treeMain->setDragDropMode(QAbstractItemView::InternalMove);
    ui.lab_Title->setText(szTileName);
    this->setWindowTitle(szTileName);
}

/* 初始化无边框窗体 */
void VideoPlatform::InitStyle()
{
    this->setStyleSheet("QGroupBox#gboxMain{border-width:0px;}");
    this->setProperty("From", true);

    /* 设置窗体标题栏隐藏--Qt::WindowStaysOnTopHint | */
    this->setWindowFlags(Qt::FramelessWindowHint |
                         Qt::WindowSystemMenuHint |
                         Qt::WindowMinimizeButtonHint);


//      IconHelper::Instance()->SetIcon(ui.btnMenu_Close, QChar(0xf00d), 10);
//      IconHelper::Instance()->SetIcon(ui.btnMenu_Min, QChar(0xf068), 10);
}

/* 初始化视频布局载体数据 */
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

    /* 在播放界面显示通道号 */
    for(int i = 0; i < 4; i++)
    {
        /* 注册事件 */
        m_VideoLab[i]->installEventFilter(this);
        m_VideoLab[i]->setAcceptDrops(true);
        m_VideoLab[i]->setProperty("labVideo", true);
        m_VideoLab[i]->setText(QString("Channel_%1").arg(i + 1));
    }

    m_VideoChlmenu = new QMenu(this);
    m_VideoChlmenu->setStyleSheet("font: 10pt \"微软雅黑\";");
    m_VideoChlmenu->addAction("close this video", this, SLOT(deleteVideo_one()));
    m_VideoChlmenu->addAction("close all video", this, SLOT(deleteVideo_all()));
    m_VideoChlmenu->addSeparator(); /* 加一条横杠 */

    QMenu *menu1 = m_VideoChlmenu->addMenu("switch to 1");
    menu1->addAction("Channel", this, SLOT(show_video_1()));
    menu1->addAction("Channel", this, SLOT(show_video_1()));
    menu1->addAction("Channel", this, SLOT(show_video_1()));
    menu1->addAction("Channel", this, SLOT(show_video_1()));

    QMenu *menu4 = m_VideoChlmenu->addMenu("switch to 4");
    menu4->addAction("switch to 4", this, SLOT(show_video_4()));
}

/* 加载配置文件数据 */
void VideoPlatform::LoadConfig()
{
    ui.treeMain->clear();
    QString temp("haikang");

    /* 模拟父节点的数据 */
    QTreeWidgetItem *itemNVR = new QTreeWidgetItem(ui.treeMain, QStringList(temp + "[" + "208.208.120.191" + "]"));
    /* 加载父节点的图标 */
    itemNVR->setIcon(0, QIcon(":/VideoPlatform/Resources/image/nvr.png"));

    /* 模拟叶子节点的数据 1 */
    QString leafIPCName1("haikang_1");
    QString leafIPCIP1("208.208.105.89");
    QTreeWidgetItem *itemIpc = new QTreeWidgetItem(itemNVR, QStringList(QString(leafIPCName1 + "[" + leafIPCIP1 + "]")));
    itemIpc->setIcon(0, QIcon(":/VideoPlatform/Resources/image/ipc_normal.bmp"));
    itemNVR->addChild(itemIpc);

    /* 模拟叶子节点的数据 2 */
    QString leafIPCName2("haikang_2");
    QString leafIPCIP2("208.208.105.100");
    itemIpc = new QTreeWidgetItem(itemNVR, QStringList(QString(leafIPCName2 + "[" + leafIPCIP2 + "]")));
    itemIpc->setIcon(0, QIcon(":/VideoPlatform/Resources/image/ipc_normal.bmp"));
    itemNVR->addChild(itemIpc);

    /* 模拟叶子节点的数据3 */
    QString leafIPCName3("haikang_3");
    QString leafIPCIP3("208.208.105.101");
    itemIpc = new QTreeWidgetItem(itemNVR, QStringList(QString(leafIPCName3 + "[" + leafIPCIP3 + "]")));
    itemIpc->setIcon(0, QIcon(":/VideoPlatform/Resources/image/ipc_normal.bmp"));
    itemNVR->addChild(itemIpc);

    /*-----------------------------------*/
    QString temp2("haikang2");
    /* 模拟根节点的数据 */
    QTreeWidgetItem *itemNVR1 = new QTreeWidgetItem(ui.treeMain, QStringList(temp2 + "[" + "208.208.120.192" + "]"));
    /* 加载父节点的图标 */
    itemNVR1->setIcon(0, QIcon(":/VideoPlatform/Resources/image/nvr.png"));

    /* 模拟叶子节点的数据 1 */
    QString leafIPCName21("haikang_1");
    QString leafIPCIP21("208.208.105.89");
    QTreeWidgetItem *itemIpc11 = new QTreeWidgetItem(itemNVR1, QStringList(QString(leafIPCName21 + "[" + leafIPCIP21 + "]")));
    itemNVR1->addChild(itemIpc11);
    /* 加载叶子节点的图标 */
    itemIpc11->setIcon(0, QIcon(":/VideoPlatform/Resources/image/ipc_normal.bmp"));

    /* 模拟叶子节点的数据 2 */
    QString leafIPCName22("haikang_2");
    QString leafIPCIP22("208.208.105.100");
    itemIpc11 = new QTreeWidgetItem(itemNVR1, QStringList(QString(leafIPCName22 + "[" + leafIPCIP22 + "]")));
    itemIpc11->setIcon(0, QIcon(":/VideoPlatform/Resources/image/ipc_normal.bmp"));
    itemNVR1->addChild(itemIpc11);

    /* 模拟叶子节点的数据3 */
    QString leafIPCName33("haikang_3");
    QString leafIPCIP33("208.208.105.101");
    itemIpc11 = new QTreeWidgetItem(itemNVR1, QStringList(QString(leafIPCName3 + "[" + leafIPCIP3 + "]")));
    itemIpc11->setIcon(0, QIcon(":/VideoPlatform/Resources/image/ipc_normal.bmp"));
    itemNVR1->addChild(itemIpc11);

    ui.treeMain->expandAll();
}

/* 删除一路实况 */
void VideoPlatform::deleteVideo_one()
{

}

/* 删除所有实况 */
void VideoPlatform::deleteVideo_all()
{

}

/* 切换样式 */
void VideoPlatform::change_style()
{

}

/* 全屏模式 */
void VideoPlatform::screen_full()
{

}

/* 普通模式 */
void VideoPlatform::screen_normal()
{

}

/* 切换到1画面 */
void VideoPlatform::show_video_1()
{

}

/* 切换到4画面 */
void VideoPlatform::show_video_4()
{

}

void VideoPlatform::on_btnMenu_Close_clicked()
{
    /* 退出程序 */
    exit(0);
}

void VideoPlatform::on_btnMenu_Min_clicked()
{
    this->showMinimized();
}

void VideoPlatform::on_treeMain_doubleClicked(const QModelIndex &index)
{

}

/* 移除所有布局 */
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

/* 改变1画面布局 */
void VideoPlatform::change_video_1(int index)
{

}

/* 改变4画面布局 */
void VideoPlatform::change_video_4(int index)
{

}

/* 改变通道布局 */
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

/* 对应改变通道rtsp地址 */
void VideoPlatform::ChangeRtspAddr(int ch, QString rtspAddr)
{

}

/* 获取摄像机主码流子码流地址 */
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
            /* 调用退出程序函数 */
            on_btnMenu_Close_clicked();
        }
        else if(obj == ui.btnMenu_Min)
        {
            /* 调用最小化窗口函数 */
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

/* 自定义实现鼠标的拖拽功能 */
void VideoPlatform::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug("-----VideoPlatform::dragEnterEvent-");
}

/* 自定义实现鼠标的拖拽功能 */
void VideoPlatform::dropEvent(QDropEvent *event)
{
     qDebug("111------");
}

/* 自定义画刷功能 */
void VideoPlatform::paintEvent(QPaintEvent *event)
{
//     QPainter painter(this);
//     QLinearGradient linearGradient(100,150,300,150);
//     //从点（100，150）开始到点（300，150）结束，确定一条直线
//     linearGradient.setColorAt(0,Qt::red);
//     linearGradient.setColorAt(0.2,Qt::black);
//     linearGradient.setColorAt(0.4,Qt::yellow);
//     linearGradient.setColorAt(0.6,Qt::white);
//     linearGradient.setColorAt(0.8,Qt::green);
//     linearGradient.setColorAt(1,Qt::blue);
//     //将直线开始点设为0，终点设为1，然后分段设置颜色
//     painter.setBrush(linearGradient);
//     painter.drawRect(100,100,200,100);
//     //绘制矩形，线性渐变线正好在矩形的水平中心线上

//     QRadialGradient radialGradient(200,100,100,200,100);
//     //其中参数分别为圆形渐变的圆心（200，100），半径100，和焦点（200，100）
//     //这里让焦点和圆心重合，从而形成从圆心向外渐变的效果
//     radialGradient.setColorAt(0,Qt::black);
//     radialGradient.setColorAt(1,Qt::yellow);
//     //渐变从焦点向整个圆进行，焦点为起始点0，圆的边界为1
//     QPainter painter(this);
//     painter.setBrush(radialGradient);
//     painter.drawEllipse(200, 200,100,100);
    //绘制圆，让它正好和上面的圆形渐变的圆重合
}


