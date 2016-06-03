#ifndef VIDEOPLATFORM_H
#define VIDEOPLATFORM_H

#include <QtWidgets/QDialog>
#include "ui_videoplatform.h"
#include "sipthread.h"
#include "publicDef.h"

class QMenu;
class QLabel;
class QModelIndex;

class VideoPlatform : public QDialog
{
    Q_OBJECT
public:
    VideoPlatform(QWidget *parent = 0);
    ~VideoPlatform();

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void keyPressEvent(QKeyEvent *event);
    /* ����ʵ����ק���� */
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void paintEvent(QPaintEvent *event);

private slots:
    void change_style();    /* �л���ʽ */
    void screen_full();     /* ȫ��ģʽ */
    void screen_normal();   /* ��ͨģʽ */

    void deleteVideo_one(); /* ɾ��һ·��Ƶ */
    void deleteVideo_all(); /* ɾ��ȫ����Ƶ */

    void show_video_1();    /* �л���1���� */
    void show_video_4();    /* �л���4���� */

    void on_btnMenu_Close_clicked();
    void on_btnMenu_Min_clicked();
    void on_treeMain_doubleClicked(const QModelIndex &index);

private:
    Ui::VideoPlatformClass ui;
    QMenu *m_menuStyle;     /* ��ʽ�˵� */
    bool m_bVideoMax;        /* ͨ���Ƿ�����󻯱�־λ */
    QMenu *m_VideoChlmenu;  /* ����Ҽ��˵����� */

    QList<QLabel *> m_VideoLab;  /* ͨ����ʾ��Ƶlab���� */
    QList<QLayout *>m_VideoLay;  /* ͨ����Ƶ����lab��layout */
    QLabel *m_tempLab;           /* ��ʱ������Ƶ�ı�ǩ */

    void InitStyle();   /* ��ʼ���ޱ߿��� */
    void InitForm();    /* ��ʼ���������� */
    void InitVideo();   /* ��ʼ����Ƶ������������ */
    void LoadConfig();  /* ���������ļ����� */
    void InitSDK();     /* ��ʼ��SDK */

    void removelayout();            /* �Ƴ����в��� */
    void change_video_1(int index); /* �ı�1���沼�� */
    void change_video_4(int index); /* �ı�4���沼�� */

    void ChangeVideoLayout();   /* �ı�ͨ������ */

    void ChangeRtspAddr(int ch, QString rtspAddr);  /* ��Ӧ�ı�ͨ��rtsp��ַ */
    void GetRtspAddr(QString NVRID, QString IPCIP, QString &IPCRtspAddrMain, QString &IPCRtspAddrSub);  /* ��ȡ�������������������ַ */

private:
    int sendSipMessageToServer(SIPMSGTYPE enMsgType, void *param);

private:
    CSipThread m_sipthread;
    CDASip m_sip;

    /* ���������ļ����� */
    QList<DEVICEINFO> m_listConfigInfo;

    /* ����label�в��ŵ���Ƶ��Ϣ */
    QMap<QString, SIPCOMMINFO> m_mapLabelManage;

    /* ��������ϷŲ�����Ƶ���豸��Ϣ */
    QList<IPCINFO> m_listEnabledIPCInfo;

    /* �豸��¼��� */
    LPVOID m_lpDevHandle;

    /* ʵ����� */
    LPVOID m_lpPlayHandle;
};

#endif // VIDEOPLATFORM_H
