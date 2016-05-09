#ifndef __MYAPP_H__
#define __MYAPP_H__

class myApp
{
public:
    static char AppPath[30];     //应用程序路径
    static int DeskWidth;       //桌面可用宽度
    static int DeskHeight;      //桌面可用高度

    static char AppTitle[20];    //界面标题
    static char NVRType[20];     //硬盘录像机厂家
    static char IPCType[20];    //网络摄像机厂家
    static char AppStyle[20];
    static int VideoDelayTime;      //视频加载响应延时时间
    static bool UseVideoOffLineCheck;       //视频断线检测
    static int VideoOffLineCheckInterval;   //视频断线检测间隔
    static int RtspType;            //码流类型
    static bool AutoRun;            //开机自动运行
    static bool AutoPoll;           //自动轮训
    static int PollType;            //轮训画面数
    static int PollInterval;        //轮训间隔
    static int PollSleep;           //轮训延时
    static char RtspAddr4[20];       //4个通道对应rtsp地址
    static char VideoType[20];       //当前画面展示类型
    static char LastConfig[20];      //软件最后配置信息

    static void ReadConfig();       //读取配置文件
    static void WriteConfig();      //写入配置文件

protected:
private:
};

#endif