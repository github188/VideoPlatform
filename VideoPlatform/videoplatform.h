#ifndef VIDEOPLATFORM_H
#define VIDEOPLATFORM_H

#include <QtWidgets/QDialog>
#include "ui_videoplatform.h"

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
    /* 重新实现拖拽函数 */
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void paintEvent(QPaintEvent *event);

private slots:
    void change_style();    /* 切换样式 */
    void screen_full();     /* 全屏模式 */
    void screen_normal();   /* 普通模式 */

    void show_video_1();    /* 切换到1画面 */
    void show_video_4();    /* 切换到4画面 */

    void on_btnMenu_Close_clicked();
    void on_btnMenu_Min_clicked();
    void on_treeMain_doubleClicked(const QModelIndex &index);

private:
    Ui::VideoPlatformClass ui;
    QMenu *m_menuStyle;     /* 样式菜单 */
    bool m_bVideoMax;        /* 通道是否处于最大化标志位 */
    QMenu *m_VideoChlmenu;  /* 鼠标右键菜单对象 */

    QList<QLabel *> m_VideoLab;  /* 通道显示视频lab载体 */
    QList<QLayout *>m_VideoLay;  /* 通道视频所在lab的layout */
    QLabel *m_tempLab;             /* 临时播放视频的标签 */

    void InitStyle();   /* 初始化无边框窗体 */
    void InitForm();    /* 初始化窗体数据 */
    void InitVideo();   /* 初始化视频布局载体数据 */
    void LoadConfig();   /* 加载配置文件数据 */

    void deleteVideo_one(); /* 删除一路视频 */
    void deleteVideo_all(); /* 删除全部视频 */

    void removelayout();            /* 移除所有布局 */
    void change_video_1(int index); /* 改变1画面布局 */
    void change_video_4(int index); /* 改变4画面布局 */

    void ChangeVideoLayout();   /* 改变通道布局 */

    void ChangeRtspAddr(int ch, QString rtspAddr);  /* 对应改变通道rtsp地址 */
    void GetRtspAddr(QString NVRID, QString IPCIP, QString &IPCRtspAddrMain, QString &IPCRtspAddrSub);  /* 获取摄像机主码流子码流地址 */

};

#endif // VIDEOPLATFORM_H
