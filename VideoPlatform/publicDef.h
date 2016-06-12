#ifndef __PUBLICDEF_H__
#define __PUBLICDEF_H__

#include <iostream>
using namespace std;
/****************宏定义***********************/
#define IN
#define OUT

/****************定义枚举类型  ****************/
typedef enum enDeviceType
{
    IPC = 0,
    NVR,
    DVR,
    PLAT
}ENUMDEVICETYPE;

typedef enum enMessageType
{
    InvitePriview = 0,
    ClosePriview,
    ReceiveAlarm,
    InvitePlayBack,
    SearchVideo,
    OpenDevice,
    CloseDevice
}SIPMSGTYPE;

typedef enum enDeviceFirm
{
    HIK = 0,
    UNIVIEW,
    DAHUA,
    TianDy,
}ENDEVICEFIRM;

/****************结构体定义********************/
/* 设备对象结构 */
typedef struct tagDeviceInfo
{
    QString strDeviceName;   //设备名称
    QString strDeviceIP;     //设备IP
    int nDeviceID;          //设备ID(ID唯一)
    int nDevicePort;        //设备端口
    int nDeviceChlNum;      //设备通道数，IPC只有一个通道
    QString strDeviceLoginName; //设备登录用户名
    QString strDeviceLoginPwd;        //设备登录密码
    ENUMDEVICETYPE enDeviceType;   //设备类型
    ENDEVICEFIRM enDeviceFirm;  //设备厂商
}DEVICEINFO, *pstDeviceInfo;


typedef struct tagIpcInfo
{
    QString strDeviceName;  //设备名称
    QString strDeviceIP;    //设备IP
    int nDeviceID;          //设备ID
    int nDevicePort;        //设备端口
    bool ishasParent;       //是否具有父节点
    QString strParentName;  //如果有父节点，父节点名称
    QString strParentIP;    //父节点IP
    int nParentID;          //父节点ID
    int nParentPort;        //父节点端口
    int nChlIndex;          //所在子节点的num
    ENUMDEVICETYPE enDeviceType;   //设备类型
}IPCINFO, *pstIpcInfo;

typedef struct tagSipCommInfo
{
    int nWndNum;
    HWND hWndHandle;
    void* lPlayHandle;
    IPCINFO stDeviceInfo;
}SIPCOMMINFO;


#endif