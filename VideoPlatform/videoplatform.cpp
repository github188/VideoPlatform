#include <QMenu>
#include <QEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>  
#include <QBitmap>
#include <QStyleOption>
#include <QDir>
#include <QMimeData>
#include <QWindow>
#include <QResizeEvent>
#include <QMessageBox>
#include <QApplication>
#include <QDesktopWidget>
#include <qlayout.h>
#include <iconhelper.h>
#include "videoplatform.h"
#include "xmlConfigOperator.h"
#include "frmconfig.h"
#include "myapp.h"
#include "alarm.h"
//#pragma comment(lib, "NetDEVSDK.lib")
#include "NetDEVSDK.h"

VideoPlatform::VideoPlatform(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    this->InitStyle();   /* 初始化无边框窗体 */
    this->InitForm();    /* 初始化窗体数据 */
    this->InitVideo();   /* 初始化视频布局载体数据 */
    this->LoadConfig();  /* 加载配置文件数据 */

     setAcceptDrops(true);

     /* 启动通信消息模块 */
    m_sipthread.start();
    m_sip.sip_init();
    m_sip.sip_listen_addr(IPPROTO_UDP, NULL, 15060, AF_INET, 0);

#if 0
    /*---------------------------------------------------*/
    int ret = NETDEV_Init();
    if(0 == ret)
    {
        qDebug("call NETDEV_Init failed!");
        //         break;
    }
    // http://39.189.195.31:50080/
    NETDEV_DEVICE_INFO_S stDevInfo = {0};
    LPVOID lpDevHandle;

    m_lpDevHandle = NETDEV_Login("192.168.1.160", 80, "admin", "admin", &stDevInfo);
    if(NULL == m_lpDevHandle)
    {
        qDebug("call NETDEV_Login failed");
    }

    NETDEV_PREVIEWINFO_S stNetInfo = {0};
    //LPVOID lpPlayHandle;
    stNetInfo.dwChannelID = 1;
    ui.labVideo1->windowHandle()->winId();
    WId pWndHanle = ui.labVideo1->windowHandle()->winId();
    if(pWndHanle == NULL)
    {
        QMessageBox::information(this, "this", "pWndHandle == NULL");
        return ;
    }

    stNetInfo.hPlayWnd = (LPVOID)ui.labVideo1->windowHandle()->winId();
    if(stNetInfo.hPlayWnd == NULL)
    {
        QMessageBox::information(this, "this", "hPlayWnd == NULL.");
        return ;
    }
    stNetInfo.dwStreamType = NETDEV_LIVE_STREAM_INDEX_MAIN;
    stNetInfo.dwLinkMode = NETDEV_TRANSPROTOCAL_RTPTCP;
    m_lpPlayHandle = NETDEV_RealPlay(m_lpDevHandle, &stNetInfo, NULL, 0);
    if(NULL == m_lpPlayHandle)
    {
        qDebug("call NETDEV_RealPlay failed");
        QMessageBox::information(this, "this", "failed to palyview.");
    }
#endif
    /*---------------------------------------------------*/
}

VideoPlatform::~VideoPlatform()
{

}

/* 初始化窗体数据 */
void VideoPlatform::InitForm()
{
    QString szTileName = QString::fromWCharArray(L"视频监控平台");
     ui.treeMain->header()->setVisible(false);
//     ui.treeMain->setAcceptDrops(false);
//     ui.treeMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
//     ui.treeMain->installEventFilter(this);

    ui.lab_Title->setText(szTileName);

    ui.labConfig->installEventFilter(this);
    ui.labConfig->setProperty("labForm", true);

    ui.labAlarm->installEventFilter(this);
    ui.labAlarm->setProperty("labForm", true);

    ui.btnMenu_Close->installEventFilter(this);

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

    m_VideoChlmenu->addAction("fullScreen", this, SLOT(screen_full()));
}

/* 加载配置文件数据 */
void VideoPlatform::LoadConfig()
{
    CXmlConfigOperator xmlConfig;
    IPCINFO stIpcInfo;
    QString strTemp;
    QString strDeviceName;   //设备名称
    QString strDeviceIP;     //设备IP
    int nDeviceID;          //设备ID(ID唯一)
    int nDevicePort;        //设备端口
    int nDeviceChlNum;      //设备通道数，IPC只有一个通道
    ENUMDEVICETYPE enDeviceType;   //设备类型

    /* 从配置文件中读取设备数据 */
    xmlConfig.readxml("config", m_listConfigInfo);

    ui.treeMain->clear();
    QString temp("haikang");

    for(int i = 0; i < m_listConfigInfo.count(); i++)
    {
        strDeviceName = m_listConfigInfo[i].strDeviceName;
        strDeviceIP   = m_listConfigInfo[i].strDeviceIP;
        nDeviceID     = m_listConfigInfo[i].nDeviceID;
        nDevicePort   = m_listConfigInfo[i].nDevicePort;
        nDeviceChlNum = m_listConfigInfo[i].nDeviceChlNum;
        enDeviceType  = m_listConfigInfo[i].enDeviceType;

        switch(enDeviceType)
        {
            case IPC :
                {
                    QTreeWidgetItem *itemIpc = new QTreeWidgetItem(ui.treeMain, QStringList(strDeviceName + " [" + strDeviceIP +"]"));
                    itemIpc->setIcon(0, QIcon(":/VideoPlatform/Resources/image/ipc_normal.png"));

                    /* 将可以拖放播放视频的节点信息保存起来 */
                    stIpcInfo.enDeviceType = ENUMDEVICETYPE::IPC;
                    stIpcInfo.ishasParent = false;
                    stIpcInfo.nDeviceID = 0;
                    stIpcInfo.nDevicePort = nDevicePort;
                    stIpcInfo.nParentID = 0;
                    stIpcInfo.nParentPort = 0;
                    stIpcInfo.strDeviceIP = strDeviceIP;
                    stIpcInfo.strDeviceName = strDeviceName;
                    stIpcInfo.strParentIP = "";
                    stIpcInfo.strParentName = "";
                    stIpcInfo.nChlIndex = 0;
                    m_listEnabledIPCInfo.append(stIpcInfo);

                    break;
                }
            case NVR :
            case DVR :
            case PLAT :
                {
                    QTreeWidgetItem *itemNVR = new QTreeWidgetItem(ui.treeMain, QStringList(strDeviceName + " [" + strDeviceIP +"]"));
                    itemNVR->setIcon(0, QIcon(":/VideoPlatform/Resources/image/nvr.png"));
                    /* 加载子节点 */
                    for(int j = 0; j < nDeviceChlNum; j++)
                    {
                        //strTemp.number(j);
                        QTreeWidgetItem *itemChildIpc = new QTreeWidgetItem(itemNVR, QStringList(strDeviceName + "_" + QString::number(j)));
                        itemChildIpc->setIcon(0, QIcon(":/VideoPlatform/Resources/image/ipc_normal.png"));
                        itemNVR->addChild(itemChildIpc);

                        /* 将可以拖放播放视频的节点信息保存起来 */
                        stIpcInfo.enDeviceType = ENUMDEVICETYPE::IPC;
                        stIpcInfo.ishasParent = true;
                        stIpcInfo.nDeviceID = 0;
                        stIpcInfo.nDevicePort = 0;
                        stIpcInfo.nParentID = 0;
                        stIpcInfo.nParentPort = nDevicePort;
                        stIpcInfo.strDeviceIP = "";
                        stIpcInfo.strDeviceName = strDeviceName + "_" + QString::number(j);
                        stIpcInfo.strParentIP = strDeviceIP;
                        stIpcInfo.strParentName = strDeviceName;
                        stIpcInfo.nChlIndex = j;
                        m_listEnabledIPCInfo.append(stIpcInfo);

                    }
                    break;
                }
            default:
                break;
        }
    }

    ui.treeMain->expandAll();
}

/* 初始化第三方SDK */
void VideoPlatform::InitSDK()
{

    return;
}

/* 删除一路实况 */
void VideoPlatform::deleteVideo_one()
{
    int ret = 0;

    /* 判断当前操作界面是否有视频数据*/
    if(m_tempLab == ui.labVideo1)
    {
        QMap<QString, SIPCOMMINFO>::iterator iter = m_mapLabelManage.find("labVideo1");
        if(iter != m_mapLabelManage.end())
        {
            /* 发送停止请求数据消息 */
            ret = sendSipMessageToServer(SIPMSGTYPE::ClosePriview, (void*)&iter->stDeviceInfo);
            if(ret != 1)    /* 关闭视频请求失败 */
            {

            }
            else    /* 关闭视频请求成功 */
            {

            }
            /* ------------------------------------- */
            NETDEV_StopRealPlay(m_lpPlayHandle);
            /* ------------------------------------- */
            /* 删除该数据 */
            m_mapLabelManage.erase(iter);
        }
        else
        {
            /* 该Label没有播放视频 */
        }
    }
    else if(m_tempLab == ui.labVideo2)
    {
        QMap<QString, SIPCOMMINFO>::iterator iter = m_mapLabelManage.find("labVideo2");
        if(iter != m_mapLabelManage.end())
        {
            /* 发送停止请求数据消息 */
            ret = sendSipMessageToServer(SIPMSGTYPE::ClosePriview, (void*)&iter->stDeviceInfo);
            if(ret != 1)    /* 关闭视频请求失败 */
            {

            }
            else    /* 关闭视频请求成功 */
            {

            }
            /* 删除该数据 */
            m_mapLabelManage.erase(iter);
        }
        else
        {
            /* 该Label没有播放视频 */
        }
    }
    else if(m_tempLab == ui.labVideo3)
    {
        QMap<QString, SIPCOMMINFO>::iterator iter = m_mapLabelManage.find("labVideo3");
        if(iter != m_mapLabelManage.end())
        {
            /* 发送停止请求数据消息 */
            ret = sendSipMessageToServer(SIPMSGTYPE::ClosePriview, (void*)&iter->stDeviceInfo);
            if(ret != 1)    /* 关闭视频请求失败 */
            {

            }
            else    /* 关闭视频请求成功 */
            {

            }
            /* 删除该数据 */
            m_mapLabelManage.erase(iter);
        }
        else
        {
            /* 该Label没有播放视频 */
        }
    }
    else if(m_tempLab == ui.labVideo4)
    {
        QMap<QString, SIPCOMMINFO>::iterator iter = m_mapLabelManage.find("labVideo4");
        if(iter != m_mapLabelManage.end())
        {
            /* 发送停止请求数据消息 */
            ret = sendSipMessageToServer(SIPMSGTYPE::ClosePriview, (void*)&m_mapLabelManage["labVideo4"].stDeviceInfo);
            if(ret != 1)    /* 关闭视频请求失败 */
            {

            }
            else    /* 关闭视频请求成功 */
            {

            }
            /* 删除该数据 */
            m_mapLabelManage.erase(iter);
        }
        else
        {
            /* 该Label没有播放视频 */
        }
    }

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
    for(int i = 0; i < 4; i++)
    {
        if(m_tempLab == m_VideoLab[i])
        {
            QDialog *dialog = new QDialog;
            dialog->showFullScreen();
        }
    }
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

void VideoPlatform::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        /* 实现esc键退出全屏 */
        case Qt::Key_Escape:
            screen_normal();
        default:
            QDialog::keyPressEvent(event);
    }
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
    int ret = 0;
    QMouseEvent *MouseEvent = static_cast<QMouseEvent *>(event);
    QMap<QString, SIPCOMMINFO>::iterator iter;

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
        else if (obj == ui.labConfig)
        {
            frmConfig config;
            config.exec();
            return true;
        }
        else if (obj == ui.labAlarm)
        {
            alarm alarmDialog;
            alarmDialog.exec();

        }
        else if (obj == ui.labVideo1)
        {
            qDebug("---pushButton--pressed");
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
        if((obj == ui.labVideo1)| (obj == ui.labVideo2) || (obj == ui.labVideo3) || (obj == ui.labVideo4))
        {
            QDropEvent *event1 = static_cast<QDropEvent *>(event);
            const QMimeData *data = event1->mimeData();
            if(data->hasFormat("text"))
            {
                QByteArray csvData = data->data("text");
                QString csvText = QString::fromUtf8(csvData);

                /* 判断该窗口是否已经在播放视频 */
                if(obj == ui.labVideo1)
                {
                    iter = m_mapLabelManage.find("labVideo1");
                    if(iter != m_mapLabelManage.end())  /* 该窗口已经有视频在播放，需要先关闭原先的视频才能继续播放 */
                    {
                        QMessageBox::information(this, QString::fromLocal8Bit("警告！"), QStringLiteral("该窗口已经有视频在播放！"));
                    }
                    else    /* 该窗口没有播放视频，则播放视频 */
                    {
                        /* 获取需要播放视频的设备信息 */
                        for(int i = 0; i < m_listEnabledIPCInfo.count(); i++)
                        {
                            if(m_listEnabledIPCInfo.at(i).strDeviceName == csvText)
                            {
                                /* 保存窗口信息和设备信息 */
                                //memcpy(&m_mapLabelManage["labVideo1"].stDeviceInfo, &m_listEnabledIPCInfo.at(i), sizeof(IPCINFO));
                                m_mapLabelManage["labVideo1"].stDeviceInfo.enDeviceType = m_listEnabledIPCInfo.at(i).enDeviceType;
                                m_mapLabelManage["labVideo1"].stDeviceInfo.ishasParent = m_listEnabledIPCInfo.at(i).ishasParent;
                                m_mapLabelManage["labVideo1"].stDeviceInfo.nChlIndex  = m_listEnabledIPCInfo.at(i).nChlIndex;
                                m_mapLabelManage["labVideo1"].stDeviceInfo.nDeviceID = m_listEnabledIPCInfo.at(i).nDeviceID;
                                m_mapLabelManage["labVideo1"].stDeviceInfo.nDevicePort = m_listEnabledIPCInfo.at(i).nDevicePort;
                                m_mapLabelManage["labVideo1"].stDeviceInfo.nParentID = m_listEnabledIPCInfo.at(i).nParentID;
                                m_mapLabelManage["labVideo1"].stDeviceInfo.nParentPort = m_listEnabledIPCInfo.at(i).nDevicePort;
                                m_mapLabelManage["labVideo1"].stDeviceInfo.strDeviceIP = m_listEnabledIPCInfo.at(i).strDeviceIP;
                                m_mapLabelManage["labVideo1"].stDeviceInfo.strDeviceName = m_listEnabledIPCInfo.at(i).strDeviceName;
                                m_mapLabelManage["labVideo1"].stDeviceInfo.strParentIP = m_listEnabledIPCInfo.at(i).strParentIP;
                                m_mapLabelManage["labVideo1"].stDeviceInfo.strParentName = m_listEnabledIPCInfo.at(i).strParentName;
                                m_mapLabelManage["labVideo1"].hWndHandle = (HWND)ui.labVideo1->winId();;
                                m_mapLabelManage["labVideo1"].nWndNum = 1;

                                /* 向服务器发送请求视频消息 */
                                ret = this->sendSipMessageToServer(SIPMSGTYPE::InvitePriview, &m_mapLabelManage["labVideo1"]);
                                if(1 != ret)
                                {
                                    QMessageBox::information(this, QString::fromLocal8Bit("警告！"), QStringLiteral("请求播放视频失败！"));
                                    QMap<QString, SIPCOMMINFO>::iterator iter = m_mapLabelManage.find("labVideo1");
                                    if(iter != m_mapLabelManage.end())
                                    {
                                        m_mapLabelManage.erase(iter);
                                    }
                                }
                                else
                                {

                                }
#if 1
                                /*---------------------------------------------------*/
                                int ret = NETDEV_Init();
                                if(0 == ret)
                                {
                                    qDebug("call NETDEV_Init failed!");
                                    break;
                                }
                                // http://39.189.195.31:50080/
                                NETDEV_DEVICE_INFO_S stDevInfo = {0};
                                LPVOID lpDevHandle;

                               m_lpDevHandle = NETDEV_Login("192.168.1.160", 80, "admin", "admin", &stDevInfo);
                                if(NULL == m_lpDevHandle)
                                {
                                    qDebug("call NETDEV_Login failed");
                                }

                                NETDEV_PREVIEWINFO_S stNetInfo = {0};
                                //LPVOID lpPlayHandle;
                                stNetInfo.dwChannelID = 1;
                                stNetInfo.hPlayWnd = (LPVOID)m_mapLabelManage["labVideo1"].hWndHandle;
                                stNetInfo.dwStreamType = NETDEV_LIVE_STREAM_INDEX_MAIN;
                                stNetInfo.dwLinkMode = NETDEV_TRANSPROTOCAL_RTPTCP;
                                m_lpPlayHandle = NETDEV_RealPlay(m_lpDevHandle, &stNetInfo, NULL, 0);
                                if(NULL == m_lpPlayHandle)
                                {
                                    qDebug("call NETDEV_RealPlay failed");
                                    QMessageBox::information(this, "this", "failed to palyview.");
                                }
                                /*---------------------------------------------------*/
#endif
                            }
                        }
                    }
                }
                else if(obj == ui.labVideo2)
                {
                    iter = m_mapLabelManage.find("labVideo2");
                    if(iter != m_mapLabelManage.end())  /* 该窗口已经有视频在播放，需要先关闭原先的视频才能继续播放 */
                    {
                        QMessageBox::information(this, QString::fromLocal8Bit("警告！"), QStringLiteral("该窗口已经有视频在播放！"));
                    }
                    else    /* 该窗口没有播放视频，则播放视频 */
                    {
                        /* 获取需要播放视频的设备信息 */
                        for(int i = 0; i < m_listEnabledIPCInfo.count(); i++)
                        {
                            if(m_listEnabledIPCInfo.at(i).strDeviceName == csvText)
                            {
                                /* 保存窗口信息和设备信息 */
                                //memcpy(&m_mapLabelManage["labVideo2"].stDeviceInfo, &m_listEnabledIPCInfo.at(i), sizeof(IPCINFO));
                                m_mapLabelManage["labVideo2"].stDeviceInfo.enDeviceType = m_listEnabledIPCInfo.at(i).enDeviceType;
                                m_mapLabelManage["labVideo2"].stDeviceInfo.ishasParent = m_listEnabledIPCInfo.at(i).ishasParent;
                                m_mapLabelManage["labVideo2"].stDeviceInfo.nChlIndex  = m_listEnabledIPCInfo.at(i).nChlIndex;
                                m_mapLabelManage["labVideo2"].stDeviceInfo.nDeviceID = m_listEnabledIPCInfo.at(i).nDeviceID;
                                m_mapLabelManage["labVideo2"].stDeviceInfo.nDevicePort = m_listEnabledIPCInfo.at(i).nDevicePort;
                                m_mapLabelManage["labVideo2"].stDeviceInfo.nParentID = m_listEnabledIPCInfo.at(i).nParentID;
                                m_mapLabelManage["labVideo2"].stDeviceInfo.nParentPort = m_listEnabledIPCInfo.at(i).nDevicePort;
                                m_mapLabelManage["labVideo2"].stDeviceInfo.strDeviceIP = m_listEnabledIPCInfo.at(i).strDeviceIP;
                                m_mapLabelManage["labVideo2"].stDeviceInfo.strDeviceName = m_listEnabledIPCInfo.at(i).strDeviceName;
                                m_mapLabelManage["labVideo2"].stDeviceInfo.strParentIP = m_listEnabledIPCInfo.at(i).strParentIP;
                                m_mapLabelManage["labVideo2"].stDeviceInfo.strParentName = m_listEnabledIPCInfo.at(i).strParentName;
                                m_mapLabelManage["labVideo2"].hWndHandle = (HWND)ui.labVideo2->winId();
                                m_mapLabelManage["labVideo2"].nWndNum = 2;

                                /* 向服务器发送请求视频消息 */
                                ret = this->sendSipMessageToServer(SIPMSGTYPE::InvitePriview, &m_mapLabelManage["labVideo2"]);
                                if(1 != ret)
                                {
                                    QMessageBox::information(this, QString::fromLocal8Bit("警告！"), QStringLiteral("请求播放视频失败！"));
                                    QMap<QString, SIPCOMMINFO>::iterator iter = m_mapLabelManage.find("labVideo2");
                                    if(iter != m_mapLabelManage.end())
                                    {
                                        m_mapLabelManage.erase(iter);
                                    }
                                }
                                else
                                {

                                }
                            }
                        }
                    }
                }
                else if(obj == ui.labVideo3)
                {
                    iter = m_mapLabelManage.find("labVideo3");
                    if(iter != m_mapLabelManage.end())  /* 该窗口已经有视频在播放，需要先关闭原先的视频才能继续播放 */
                    {
                        QMessageBox::information(this, QString::fromLocal8Bit("警告！"), QStringLiteral("该窗口已经有视频在播放！"));
                    }
                    else    /* 该窗口没有播放视频，则播放视频 */
                    {
                        /* 获取需要播放视频的设备信息 */
                        for(int i = 0; i < m_listEnabledIPCInfo.count(); i++)
                        {
                            if(m_listEnabledIPCInfo.at(i).strDeviceName == csvText)
                            {
                                /* 保存窗口信息和设备信息 */
                                //memcpy(&m_mapLabelManage["labVideo3"].stDeviceInfo, &m_listEnabledIPCInfo.at(i), sizeof(IPCINFO));
                                m_mapLabelManage["labVideo3"].stDeviceInfo.enDeviceType = m_listEnabledIPCInfo.at(i).enDeviceType;
                                m_mapLabelManage["labVideo3"].stDeviceInfo.ishasParent = m_listEnabledIPCInfo.at(i).ishasParent;
                                m_mapLabelManage["labVideo3"].stDeviceInfo.nChlIndex  = m_listEnabledIPCInfo.at(i).nChlIndex;
                                m_mapLabelManage["labVideo3"].stDeviceInfo.nDeviceID = m_listEnabledIPCInfo.at(i).nDeviceID;
                                m_mapLabelManage["labVideo3"].stDeviceInfo.nDevicePort = m_listEnabledIPCInfo.at(i).nDevicePort;
                                m_mapLabelManage["labVideo3"].stDeviceInfo.nParentID = m_listEnabledIPCInfo.at(i).nParentID;
                                m_mapLabelManage["labVideo3"].stDeviceInfo.nParentPort = m_listEnabledIPCInfo.at(i).nDevicePort;
                                m_mapLabelManage["labVideo3"].stDeviceInfo.strDeviceIP = m_listEnabledIPCInfo.at(i).strDeviceIP;
                                m_mapLabelManage["labVideo3"].stDeviceInfo.strDeviceName = m_listEnabledIPCInfo.at(i).strDeviceName;
                                m_mapLabelManage["labVideo3"].stDeviceInfo.strParentIP = m_listEnabledIPCInfo.at(i).strParentIP;
                                m_mapLabelManage["labVideo3"].stDeviceInfo.strParentName = m_listEnabledIPCInfo.at(i).strParentName;
                                m_mapLabelManage["labVideo3"].hWndHandle = (HWND)ui.labVideo3->winId();
                                m_mapLabelManage["labVideo3"].nWndNum = 3;

                                /* 向服务器发送请求视频消息 */
                                ret = this->sendSipMessageToServer(SIPMSGTYPE::InvitePriview, &m_mapLabelManage["labVideo3"]);
                                if(1 != ret)
                                {
                                    QMessageBox::information(this, QString::fromLocal8Bit("警告！"), QStringLiteral("请求播放视频失败！"));
                                    QMap<QString, SIPCOMMINFO>::iterator iter = m_mapLabelManage.find("labVideo3");
                                    if(iter != m_mapLabelManage.end())
                                    {
                                        m_mapLabelManage.erase(iter);
                                    }
                                }
                                else
                                {

                                }
                            }
                        }
                    }
                }
                else 
                {
                    iter = m_mapLabelManage.find("labVideo4");
                    if(iter != m_mapLabelManage.end())  /* 该窗口已经有视频在播放，需要先关闭原先的视频才能继续播放 */
                    {
                        QMessageBox::information(this, QString::fromLocal8Bit("警告！"), QStringLiteral("该窗口已经有视频在播放！"));
                    }
                    else    /* 该窗口没有播放视频，则播放视频 */
                    {
                        /* 获取需要播放视频的设备信息 */
                        for(int i = 0; i < m_listEnabledIPCInfo.count(); i++)
                        {
                            if(m_listEnabledIPCInfo.at(i).strDeviceName == csvText)
                            {
                                /* 保存窗口信息和设备信息 这么memcpy存在问题，需要以后定位一下*/
                                //memcpy(&m_mapLabelManage["labVideo4"].stDeviceInfo, &m_listEnabledIPCInfo.at(i), sizeof(IPCINFO));
                                m_mapLabelManage["labVideo4"].stDeviceInfo.enDeviceType = m_listEnabledIPCInfo.at(i).enDeviceType;
                                m_mapLabelManage["labVideo4"].stDeviceInfo.ishasParent = m_listEnabledIPCInfo.at(i).ishasParent;
                                m_mapLabelManage["labVideo4"].stDeviceInfo.nChlIndex  = m_listEnabledIPCInfo.at(i).nChlIndex;
                                m_mapLabelManage["labVideo4"].stDeviceInfo.nDeviceID = m_listEnabledIPCInfo.at(i).nDeviceID;
                                m_mapLabelManage["labVideo4"].stDeviceInfo.nDevicePort = m_listEnabledIPCInfo.at(i).nDevicePort;
                                m_mapLabelManage["labVideo4"].stDeviceInfo.nParentID = m_listEnabledIPCInfo.at(i).nParentID;
                                m_mapLabelManage["labVideo4"].stDeviceInfo.nParentPort = m_listEnabledIPCInfo.at(i).nDevicePort;
                                m_mapLabelManage["labVideo4"].stDeviceInfo.strDeviceIP = m_listEnabledIPCInfo.at(i).strDeviceIP;
                                m_mapLabelManage["labVideo4"].stDeviceInfo.strDeviceName = m_listEnabledIPCInfo.at(i).strDeviceName;
                                m_mapLabelManage["labVideo4"].stDeviceInfo.strParentIP = m_listEnabledIPCInfo.at(i).strParentIP;
                                m_mapLabelManage["labVideo4"].stDeviceInfo.strParentName = m_listEnabledIPCInfo.at(i).strParentName;
                                m_mapLabelManage["labVideo4"].hWndHandle = (HWND)ui.labVideo4->winId();
                                m_mapLabelManage["labVideo4"].nWndNum = 4;

                                /* 向服务器发送请求视频消息 */
                                ret = this->sendSipMessageToServer(SIPMSGTYPE::InvitePriview, &m_mapLabelManage["labVideo4"]);
                                if(1 != ret)
                                {
                                    QMessageBox::information(this, QString::fromLocal8Bit("警告！"), QStringLiteral("请求播放视频失败！"));
                                    /* 删除m_mapLabelManage中的数据 */
                                    QMap<QString, SIPCOMMINFO>::iterator iter = m_mapLabelManage.find("labVideo4");
                                    if(iter != m_mapLabelManage.end())
                                    {
                                        m_mapLabelManage.erase(iter);
                                    }
                                }
                                else
                                {

                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return QObject::eventFilter(obj, event);
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

int VideoPlatform::sendSipMessageToServer(SIPMSGTYPE enMsgType, void *param)
{
    QString strSendInfo;
    QByteArray byteArrayTemp;

    switch(enMsgType)
    {
        case InvitePriview :
        {
            SIPCOMMINFO *pstSipSendInfo = (SIPCOMMINFO *)param;

            /* 发起invite请求 */
            m_sip.sip_call_build_initial_invite("nihao");
            strSendInfo.append("v=0\r\n");
            strSendInfo.append("o=anonymous 0 0 IN IP4 0.0.0.0\r\n");
            strSendInfo.append("t=1 10\r\n");
            strSendInfo.append("a=DeviceName:");
            strSendInfo = strSendInfo + pstSipSendInfo->stDeviceInfo.strDeviceName;
            strSendInfo.append("\r\n");
            strSendInfo.append("a=DeviceID:");
            strSendInfo = strSendInfo + QString::number(pstSipSendInfo->stDeviceInfo.nDeviceID);
            strSendInfo.append("\r\n");

            byteArrayTemp = strSendInfo.toLatin1();
            m_sip.sip_message_set_body(byteArrayTemp.data(), byteArrayTemp.length());
            m_sip.sip_message_set_content_type("application/sdp");
            m_sip.sip_call_send_initial_invite();

            m_sip.sip_client_receivemsg();

//            QMessageBox::information(this, QString::fromLocal8Bit("警告!"), QStringLiteral("设备不在线！   "));
            break;
        }
        case ClosePriview :
        {
            IPCINFO *pstSipByeInfo = (IPCINFO*)param;
            

            break;
        }
        case ReceiveAlarm:
        {
            break;
        }
        case InvitePlayBack:
        {
            break;
        }
        case SearchVideo:
        {
            break;
        }
        case OpenDevice:
        {
            break;
        }
        case CloseDevice:
        {
            break;
        }
        default:
        {
        }
    }

    return 1; 
}