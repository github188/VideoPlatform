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

    this->InitStyle();   /* ��ʼ���ޱ߿��� */
    this->InitForm();    /* ��ʼ���������� */
    this->InitVideo();   /* ��ʼ����Ƶ������������ */
    this->LoadConfig();  /* ���������ļ����� */
    this->InitSDK();     /* ��ʼ���������豸SDK���ſ� */

    setAcceptDrops(true);

     /* ����ͨ����Ϣģ�� */
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

/* ��ʼ���������� */
void VideoPlatform::InitForm()
{
    QString szTileName = QString::fromWCharArray(L"��Ƶ���ƽ̨");
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

    m_VideoChlmenu->addAction("fullScreen", this, SLOT(screen_full()));
}

/* ���������ļ����� */
void VideoPlatform::LoadConfig()
{
    CXmlConfigOperator xmlConfig;
    IPCINFO stIpcInfo;
    QString strTemp;
    QString strDeviceName;   //�豸����
    QString strDeviceIP;     //�豸IP
    int nDeviceID;          //�豸ID(IDΨһ)
    int nDevicePort;        //�豸�˿�
    int nDeviceChlNum;      //�豸ͨ������IPCֻ��һ��ͨ��
    ENUMDEVICETYPE enDeviceType;   //�豸����

    /* �������ļ��ж�ȡ�豸���� */
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

                    /* �������ϷŲ�����Ƶ�Ľڵ���Ϣ�������� */
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
                    /* �����ӽڵ� */
                    for(int j = 0; j < nDeviceChlNum; j++)
                    {
                        //strTemp.number(j);
                        QTreeWidgetItem *itemChildIpc = new QTreeWidgetItem(itemNVR, QStringList(strDeviceName + "_" + QString::number(j)));
                        itemChildIpc->setIcon(0, QIcon(":/VideoPlatform/Resources/image/ipc_normal.png"));
                        itemNVR->addChild(itemChildIpc);

                        /* �������ϷŲ�����Ƶ�Ľڵ���Ϣ�������� */
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

//////////////////////////////////////////////////////////////
// void STDCALL AlarmCallBack_PF(IN LPVOID  dwUserID,
//     IN INT32 dwChannelID,
//     IN NETDEV_ALARM_INFO_S stAlarmInfo,
//     IN LPVOID lpBuf,
//     IN INT32  dwBufLen,
//     IN LPVOID dwUserData
//     )
// {
//     int i = 0;
//     i = i + dwChannelID;
//     qDebug("-----has alarms-------");
// }


/* ��ʼ��������SDK */
void VideoPlatform::InitSDK()
{
    int ret = NETDEV_Init();
    if(0 == ret)
    {
        qDebug("call NETDEV_Init failed!");
    }
    NETDEV_DEVICE_INFO_S stDevInfo = {0};
    LPVOID lpDevHandle;

    m_lpDevHandle = NETDEV_Login("192.168.1.160", 80, "admin", "admin", &stDevInfo);
    if(NULL == m_lpDevHandle)
    {
        qDebug("call NETDEV_Login failed");
    }

//     /* ���ø澯�ص����� */
//     int ret1 = NETDEV_SetAlarmCallBack(m_lpDevHandle, AlarmCallBack_PF, this);
//     if( TRUE != ret1)
//     {
//         qDebug("---set AlarmCallBack failed---");
//     }

    return;
}

/* ɾ��һ·ʵ�� */
void VideoPlatform::deleteVideo_one()
{
    int ret = 0;

    /* �жϵ�ǰ���������Ƿ�����Ƶ����*/
    if(m_tempLab == ui.labVideo1)
    {
        QMap<QString, SIPCOMMINFO>::iterator iter = m_mapLabelManage.find("labVideo1");
        if(iter != m_mapLabelManage.end())
        {
            /* ����ֹͣ����������Ϣ */
            ret = sendSipMessageToServer(SIPMSGTYPE::ClosePriview, (void*)&iter->stDeviceInfo);
            if(ret != 1)    /* �ر���Ƶ����ʧ�� */
            {

            }
            else    /* �ر���Ƶ����ɹ� */
            {

            }

            if(iter->lPlayHandle != NULL)
            {
                NETDEV_StopRealPlay(iter->lPlayHandle);
            }

            /* ɾ�������� */
            m_mapLabelManage.erase(iter);
        }
        else
        {
            /* ��Labelû�в�����Ƶ */
            QMessageBox::information(this, QString::fromLocal8Bit("���棡"), QStringLiteral("�ô���û�в�����Ƶ���޷����йرղ�����"));
        }
    }
    else if(m_tempLab == ui.labVideo2)
    {
        QMap<QString, SIPCOMMINFO>::iterator iter = m_mapLabelManage.find("labVideo2");
        if(iter != m_mapLabelManage.end())
        {
            /* ����ֹͣ����������Ϣ */
            ret = sendSipMessageToServer(SIPMSGTYPE::ClosePriview, (void*)&iter->stDeviceInfo);
            if(ret != 1)    /* �ر���Ƶ����ʧ�� */
            {

            }
            else    /* �ر���Ƶ����ɹ� */
            {

            }
            if(iter->lPlayHandle != NULL)
            {
                NETDEV_StopRealPlay(iter->lPlayHandle);
            }
            /* ɾ�������� */
            m_mapLabelManage.erase(iter);
        }
        else
        {
            /* ��Labelû�в�����Ƶ */
            QMessageBox::information(this, QString::fromLocal8Bit("���棡"), QStringLiteral("�ô���û�в�����Ƶ���޷����йرղ�����"));
        }
    }
    else if(m_tempLab == ui.labVideo3)
    {
        QMap<QString, SIPCOMMINFO>::iterator iter = m_mapLabelManage.find("labVideo3");
        if(iter != m_mapLabelManage.end())
        {
            /* ����ֹͣ����������Ϣ */
            ret = sendSipMessageToServer(SIPMSGTYPE::ClosePriview, (void*)&iter->stDeviceInfo);
            if(ret != 1)    /* �ر���Ƶ����ʧ�� */
            {

            }
            else    /* �ر���Ƶ����ɹ� */
            {

            }
            if(iter->lPlayHandle != NULL)
            {
                NETDEV_StopRealPlay(iter->lPlayHandle);
            }
            /* ɾ�������� */
            m_mapLabelManage.erase(iter);
        }
        else
        {
            /* ��Labelû�в�����Ƶ */
            QMessageBox::information(this, QString::fromLocal8Bit("���棡"), QStringLiteral("�ô���û�в�����Ƶ���޷����йرղ�����"));
        }
    }
    else if(m_tempLab == ui.labVideo4)
    {
        QMap<QString, SIPCOMMINFO>::iterator iter = m_mapLabelManage.find("labVideo4");
        if(iter != m_mapLabelManage.end())
        {
            /* ����ֹͣ����������Ϣ */
            ret = sendSipMessageToServer(SIPMSGTYPE::ClosePriview, (void*)&m_mapLabelManage["labVideo4"].stDeviceInfo);
            if(ret != 1)    /* �ر���Ƶ����ʧ�� */
            {

            }
            else    /* �ر���Ƶ����ɹ� */
            {

            }
            if(iter->lPlayHandle != NULL)
            {
                NETDEV_StopRealPlay(iter->lPlayHandle);
            }
            /* ɾ�������� */
            m_mapLabelManage.erase(iter);
        }
        else
        {
            /* ��Labelû�в�����Ƶ */
            QMessageBox::information(this, QString::fromLocal8Bit("���棡"), QStringLiteral("�ô���û�в�����Ƶ���޷����йرղ�����"));
        }
    }

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
    for(int i = 0; i < 4; i++)
    {
        if(m_tempLab == m_VideoLab[i])
        {
            QDialog *dialog = new QDialog;
            dialog->showFullScreen();
        }
    }
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

void VideoPlatform::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        /* ʵ��esc���˳�ȫ�� */
        case Qt::Key_Escape:
            screen_normal();
        default:
            QDialog::keyPressEvent(event);
    }
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
    int ret = 0;
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
        if((obj == ui.labVideo1) || (obj == ui.labVideo2) || (obj == ui.labVideo3) || (obj == ui.labVideo4))
        {
            QDropEvent *event1 = static_cast<QDropEvent *>(event);
            const QMimeData *data = event1->mimeData();
            if(data->hasFormat("text"))
            {
                QByteArray csvData = data->data("text");
                QString csvText = QString::fromUtf8(csvData);

                ret = this->startPlayVideo(csvText, obj);
                if(TRUE != ret)
                {
                    QMessageBox::information(this, QString::fromLocal8Bit("���棡"), QStringLiteral("������Ƶʧ�ܣ�"));
                }
            }
        }
    }

    return QObject::eventFilter(obj, event);
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

int VideoPlatform::sendSipMessageToServer(SIPMSGTYPE enMsgType, void *param)
{
    QString strSendInfo;
    QByteArray byteArrayTemp;
    int ret = TRUE;
    int ret1 = TRUE;

    switch(enMsgType)
    {
        case InvitePriview :
        {
            SIPCOMMINFO *pstSipSendInfo = (SIPCOMMINFO *)param;

            /* ����invite���� */
            m_sip.sip_call_build_initial_invite("nihao");
            strSendInfo.append("v=0\r\n");
            strSendInfo.append("o=anonymous 0 0 IN IP4 127.0.0.1\r\n");
            strSendInfo.append("t=1 10\r\n");
            strSendInfo.append("a=DeviceName:");
            strSendInfo = strSendInfo + pstSipSendInfo->stDeviceInfo.strDeviceName;
            strSendInfo.append("\r\n");
            strSendInfo.append("a=DeviceID:");
            strSendInfo = strSendInfo + QString::number(pstSipSendInfo->stDeviceInfo.nDeviceID);
            strSendInfo.append("\r\n");
            strSendInfo.append("a=ChannelNum:");
            strSendInfo = strSendInfo + QString::number(pstSipSendInfo->stDeviceInfo.nChlIndex);
            strSendInfo.append("\r\n");

            byteArrayTemp = strSendInfo.toLatin1();
            m_sip.sip_message_set_body(byteArrayTemp.data(), byteArrayTemp.length());
            m_sip.sip_message_set_content_type("application/sdp");
            m_sip.sip_call_send_initial_invite();

            ret = m_sip.sip_client_receivemsg();
            if(TRUE != ret)
            {
                ret1 = FALSE;
            }
            else
            {
                ret1 = TRUE;
            }

//            QMessageBox::information(this, QString::fromLocal8Bit("����!"), QStringLiteral("�豸�����ߣ�   "));
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

    return ret; 
}

bool VideoPlatform::isLabelHasVideo(QObject *objIn)
{
    return TRUE;
}

/**
 @brief ������Ƶ
 @parma[IN] QString strChlName
 @param[IN] QObject *objIn
 @return 
 - �ɹ� TRUE
 - ʧ�� FALSE
*/
bool VideoPlatform::startPlayVideo(QString strChlName, QObject *objIn)
{
    QMap<QString, SIPCOMMINFO>::iterator iter;
    SIPCOMMINFO stRealDataInfo;

    int ret = 0;

    /* �жϸô����Ƿ��Ѿ��ڲ�����Ƶ */
    if(objIn == ui.labVideo1)
    {
        iter = m_mapLabelManage.find("labVideo1");
        if(iter != m_mapLabelManage.end())  /* �ô����Ѿ�����Ƶ�ڲ��ţ���Ҫ�ȹر�ԭ�ȵ���Ƶ���ܼ������� */
        {
            QMessageBox::information(this, QString::fromLocal8Bit("���棡"), QStringLiteral("�ô����Ѿ�����Ƶ�ڲ��ţ�"));
        }
        else    /* �ô���û�в�����Ƶ���򲥷���Ƶ */
        {
            /* ��ȡ��Ҫ������Ƶ���豸��Ϣ */
            for(int i = 0; i < m_listEnabledIPCInfo.count(); i++)
            {
                if(m_listEnabledIPCInfo.at(i).strDeviceName == strChlName)
                {
                    /* ���洰����Ϣ���豸��Ϣ */
                    /* test */
                    stRealDataInfo.stDeviceInfo.enDeviceType = m_listEnabledIPCInfo.at(i).enDeviceType;
                    stRealDataInfo.stDeviceInfo.ishasParent = m_listEnabledIPCInfo.at(i).ishasParent;
                    stRealDataInfo.stDeviceInfo.nChlIndex  = m_listEnabledIPCInfo.at(i).nChlIndex;
                    stRealDataInfo.stDeviceInfo.nDeviceID = m_listEnabledIPCInfo.at(i).nDeviceID;
                    stRealDataInfo.stDeviceInfo.nDevicePort = m_listEnabledIPCInfo.at(i).nDevicePort;
                    stRealDataInfo.stDeviceInfo.nParentID = m_listEnabledIPCInfo.at(i).nParentID;
                    stRealDataInfo.stDeviceInfo.nParentPort = m_listEnabledIPCInfo.at(i).nDevicePort;
                    stRealDataInfo.stDeviceInfo.strDeviceIP = m_listEnabledIPCInfo.at(i).strDeviceIP;
                    stRealDataInfo.stDeviceInfo.strDeviceName = m_listEnabledIPCInfo.at(i).strDeviceName;
                    stRealDataInfo.stDeviceInfo.strParentIP = m_listEnabledIPCInfo.at(i).strParentIP;
                    stRealDataInfo.stDeviceInfo.strParentName = m_listEnabledIPCInfo.at(i).strParentName;
                    stRealDataInfo.hWndHandle = (HWND)ui.labVideo1->winId();
                    stRealDataInfo.nWndNum = 1;

                    /* �����������������Ƶ��Ϣ */
                    ret = this->sendSipMessageToServer(SIPMSGTYPE::InvitePriview, &stRealDataInfo);
                    /*-------------test------------*/
                    ret = TRUE;
                    if(TRUE != ret)
                    {
                        QMessageBox::information(this, QString::fromLocal8Bit("���棡"), QStringLiteral("���󲥷���Ƶʧ�ܣ�"));
                    }
                    else
                    {
                        QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ��"), QStringLiteral("����ʵ���ɹ���"));
//                         NETDEV_PREVIEWINFO_S stNetInfo = {0};
//                         stNetInfo.dwChannelID = 1;
//                         stNetInfo.hPlayWnd = (LPVOID)stRealDataInfo.hWndHandle;
//                         stNetInfo.dwStreamType = NETDEV_LIVE_STREAM_INDEX_MAIN;
//                         stNetInfo.dwLinkMode = NETDEV_TRANSPROTOCAL_RTPTCP;
//                         stRealDataInfo.lPlayHandle = (LPVOID)NETDEV_RealPlay(m_lpDevHandle, &stNetInfo, NULL, 0);

                        startRealData(stRealDataInfo);
                        /* ���沥�Ŵ�����Ϣ */
                        m_mapLabelManage["labVideo1"] = stRealDataInfo;
                    }
                }
            }
        }
    }
    else if(objIn == ui.labVideo2)
    {
        iter = m_mapLabelManage.find("labVideo2");
        if(iter != m_mapLabelManage.end())  /* �ô����Ѿ�����Ƶ�ڲ��ţ���Ҫ�ȹر�ԭ�ȵ���Ƶ���ܼ������� */
        {
            QMessageBox::information(this, QString::fromLocal8Bit("���棡"), QStringLiteral("�ô����Ѿ�����Ƶ�ڲ��ţ�"));
        }
        else    /* �ô���û�в�����Ƶ���򲥷���Ƶ */
        {
            /* ��ȡ��Ҫ������Ƶ���豸��Ϣ */
            for(int i = 0; i < m_listEnabledIPCInfo.count(); i++)
            {
                if(m_listEnabledIPCInfo.at(i).strDeviceName == strChlName)
                {
                    /* ���洰����Ϣ���豸��Ϣ */
                    /* test */
                    stRealDataInfo.stDeviceInfo.enDeviceType = m_listEnabledIPCInfo.at(i).enDeviceType;
                    stRealDataInfo.stDeviceInfo.ishasParent = m_listEnabledIPCInfo.at(i).ishasParent;
                    stRealDataInfo.stDeviceInfo.nChlIndex  = m_listEnabledIPCInfo.at(i).nChlIndex;
                    stRealDataInfo.stDeviceInfo.nDeviceID = m_listEnabledIPCInfo.at(i).nDeviceID;
                    stRealDataInfo.stDeviceInfo.nDevicePort = m_listEnabledIPCInfo.at(i).nDevicePort;
                    stRealDataInfo.stDeviceInfo.nParentID = m_listEnabledIPCInfo.at(i).nParentID;
                    stRealDataInfo.stDeviceInfo.nParentPort = m_listEnabledIPCInfo.at(i).nDevicePort;
                    stRealDataInfo.stDeviceInfo.strDeviceIP = m_listEnabledIPCInfo.at(i).strDeviceIP;
                    stRealDataInfo.stDeviceInfo.strDeviceName = m_listEnabledIPCInfo.at(i).strDeviceName;
                    stRealDataInfo.stDeviceInfo.strParentIP = m_listEnabledIPCInfo.at(i).strParentIP;
                    stRealDataInfo.stDeviceInfo.strParentName = m_listEnabledIPCInfo.at(i).strParentName;
                    stRealDataInfo.hWndHandle = (HWND)ui.labVideo2->winId();
                    stRealDataInfo.nWndNum = 2;

                    /* �����������������Ƶ��Ϣ */
                    ret = this->sendSipMessageToServer(SIPMSGTYPE::InvitePriview, &stRealDataInfo);
                    /*-------------test------------*/
                    ret = TRUE;
                    if(TRUE != ret)
                    {
                        QMessageBox::information(this, QString::fromLocal8Bit("���棡"), QStringLiteral("���󲥷���Ƶʧ�ܣ�"));
                    }
                    else
                    {
                        QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ��"), QStringLiteral("����ʵ���ɹ���"));

                        startRealData(stRealDataInfo);
                        /* ���沥�Ŵ�����Ϣ */
                        m_mapLabelManage["labVideo2"] = stRealDataInfo;
                    }
                }
            }
        }
    }
    else if(objIn == ui.labVideo3)
    {
        iter = m_mapLabelManage.find("labVideo3");
        if(iter != m_mapLabelManage.end())  /* �ô����Ѿ�����Ƶ�ڲ��ţ���Ҫ�ȹر�ԭ�ȵ���Ƶ���ܼ������� */
        {
            QMessageBox::information(this, QString::fromLocal8Bit("���棡"), QStringLiteral("�ô����Ѿ�����Ƶ�ڲ��ţ�"));
        }
        else    /* �ô���û�в�����Ƶ���򲥷���Ƶ */
        {
            /* ��ȡ��Ҫ������Ƶ���豸��Ϣ */
            for(int i = 0; i < m_listEnabledIPCInfo.count(); i++)
            {
                if(m_listEnabledIPCInfo.at(i).strDeviceName == strChlName)
                {
                    /* ���洰����Ϣ���豸��Ϣ */
                    /* test */
                    stRealDataInfo.stDeviceInfo.enDeviceType = m_listEnabledIPCInfo.at(i).enDeviceType;
                    stRealDataInfo.stDeviceInfo.ishasParent = m_listEnabledIPCInfo.at(i).ishasParent;
                    stRealDataInfo.stDeviceInfo.nChlIndex  = m_listEnabledIPCInfo.at(i).nChlIndex;
                    stRealDataInfo.stDeviceInfo.nDeviceID = m_listEnabledIPCInfo.at(i).nDeviceID;
                    stRealDataInfo.stDeviceInfo.nDevicePort = m_listEnabledIPCInfo.at(i).nDevicePort;
                    stRealDataInfo.stDeviceInfo.nParentID = m_listEnabledIPCInfo.at(i).nParentID;
                    stRealDataInfo.stDeviceInfo.nParentPort = m_listEnabledIPCInfo.at(i).nDevicePort;
                    stRealDataInfo.stDeviceInfo.strDeviceIP = m_listEnabledIPCInfo.at(i).strDeviceIP;
                    stRealDataInfo.stDeviceInfo.strDeviceName = m_listEnabledIPCInfo.at(i).strDeviceName;
                    stRealDataInfo.stDeviceInfo.strParentIP = m_listEnabledIPCInfo.at(i).strParentIP;
                    stRealDataInfo.stDeviceInfo.strParentName = m_listEnabledIPCInfo.at(i).strParentName;
                    stRealDataInfo.hWndHandle = (HWND)ui.labVideo3->winId();
                    stRealDataInfo.nWndNum = 3;

                    /* �����������������Ƶ��Ϣ */
                    ret = this->sendSipMessageToServer(SIPMSGTYPE::InvitePriview, &stRealDataInfo);
                    if(TRUE != ret)
                    {
                        QMessageBox::information(this, QString::fromLocal8Bit("���棡"), QStringLiteral("���󲥷���Ƶʧ�ܣ�"));
                    }
                    else
                    {
                        QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ��"), QStringLiteral("����ʵ���ɹ���"));
                        startRealData(stRealDataInfo);
                        /* ���沥�Ŵ�����Ϣ */
                        m_mapLabelManage["labVideo3"] = stRealDataInfo;
                    }
                }
            }
        }
    }
    else 
    {
        iter = m_mapLabelManage.find("labVideo4");
        if(iter != m_mapLabelManage.end())  /* �ô����Ѿ�����Ƶ�ڲ��ţ���Ҫ�ȹر�ԭ�ȵ���Ƶ���ܼ������� */
        {
            QMessageBox::information(this, QString::fromLocal8Bit("���棡"), QStringLiteral("�ô����Ѿ�����Ƶ�ڲ��ţ�"));
        }
        else    /* �ô���û�в�����Ƶ���򲥷���Ƶ */
        {
            /* ��ȡ��Ҫ������Ƶ���豸��Ϣ */
            for(int i = 0; i < m_listEnabledIPCInfo.count(); i++)
            {
                if(m_listEnabledIPCInfo.at(i).strDeviceName == strChlName)
                {
                    /* ���洰����Ϣ���豸��Ϣ ��ômemcpy�������⣬��Ҫ�Ժ�λһ��*/
                    /* test */
                    stRealDataInfo.stDeviceInfo.enDeviceType = m_listEnabledIPCInfo.at(i).enDeviceType;
                    stRealDataInfo.stDeviceInfo.ishasParent = m_listEnabledIPCInfo.at(i).ishasParent;
                    stRealDataInfo.stDeviceInfo.nChlIndex  = m_listEnabledIPCInfo.at(i).nChlIndex;
                    stRealDataInfo.stDeviceInfo.nDeviceID = m_listEnabledIPCInfo.at(i).nDeviceID;
                    stRealDataInfo.stDeviceInfo.nDevicePort = m_listEnabledIPCInfo.at(i).nDevicePort;
                    stRealDataInfo.stDeviceInfo.nParentID = m_listEnabledIPCInfo.at(i).nParentID;
                    stRealDataInfo.stDeviceInfo.nParentPort = m_listEnabledIPCInfo.at(i).nDevicePort;
                    stRealDataInfo.stDeviceInfo.strDeviceIP = m_listEnabledIPCInfo.at(i).strDeviceIP;
                    stRealDataInfo.stDeviceInfo.strDeviceName = m_listEnabledIPCInfo.at(i).strDeviceName;
                    stRealDataInfo.stDeviceInfo.strParentIP = m_listEnabledIPCInfo.at(i).strParentIP;
                    stRealDataInfo.stDeviceInfo.strParentName = m_listEnabledIPCInfo.at(i).strParentName;
                    stRealDataInfo.hWndHandle = (HWND)ui.labVideo4->winId();
                    stRealDataInfo.nWndNum = 4;
                    /* �����������������Ƶ��Ϣ */
                    ret = this->sendSipMessageToServer(SIPMSGTYPE::InvitePriview, &stRealDataInfo);
                    if(TRUE != ret)
                    {
                        QMessageBox::information(this, QString::fromLocal8Bit("���棡"), QStringLiteral("���󲥷���Ƶʧ�ܣ�"));
                    }
                    else
                    {
                        QMessageBox::information(this, QString::fromLocal8Bit("��Ϣ��"), QStringLiteral("����ʵ���ɹ���"));
                        startRealData(stRealDataInfo);
                        /* ���沥�Ŵ�����Ϣ */
                        m_mapLabelManage["labVideo4"] = stRealDataInfo;
                    }
                }
            }
        }
    }
    return TRUE;
}

/**
 @brief ����ʵ����Ƶ
 @param[IN] SIPCOMMINFO stRealDataIn
 @return 
 - �ɹ� TRUE
 - ʧ�� FALSE
*/
bool VideoPlatform::startRealData(SIPCOMMINFO &stRealDataIn)
{
    NETDEV_PREVIEWINFO_S stNetInfo = {0};
    stNetInfo.dwChannelID = stRealDataIn.stDeviceInfo.nChlIndex + 1;
    stNetInfo.hPlayWnd = (LPVOID)stRealDataIn.hWndHandle;
    stNetInfo.dwStreamType = NETDEV_LIVE_STREAM_INDEX_MAIN;
    stNetInfo.dwLinkMode = NETDEV_TRANSPROTOCAL_RTPTCP;
    stRealDataIn.lPlayHandle = (LPVOID)NETDEV_RealPlay(m_lpDevHandle, &stNetInfo, NULL, 0);

    return TRUE;
}