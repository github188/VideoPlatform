#ifndef __PUBLICDEF_H__
#define __PUBLICDEF_H__
// #include <WinDef.h>
// #include <Windows.h>
#include <iostream>

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

/****************结构体定义********************/
/* 设备对象结构 */
typedef struct tagDeviceInfo
{
    std::string strDeviceName;   //设备名称
    std::string strDeviceIP;     //设备IP
    int nDeviceID;          //设备ID(ID唯一)
    int nDevicePort;        //设备端口
    int nDeviceChlNum;      //设备通道数，IPC只有一个通道
    ENUMDEVICETYPE enDeviceType;   //设备类型
}DEVICEINFO, *pstDeviceInfo;


typedef struct tagIpcInfo
{
    std::string strDeviceName;  //设备名称
    std::string strDeviceIP;    //设备IP
    int nDeviceID;          //设备ID
    int nDevicePort;        //设备端口
    bool ishasParent;       //是否具有父节点
    std::string strParentName;  //如果有父节点，父节点名称
    std::string strParentIP;    //父节点IP
    int nParentID;          //父节点ID
    int nParentPort;        //父节点端口
    int nChlIndex;          //所在子节点的num
    ENUMDEVICETYPE enDeviceType;   //设备类型
}IPCINFO, *pstIpcInfo;

typedef struct tagSipCommInfo
{
    int nWndNum;
/*    HWND hWndHandle;*/
    void* lPlayHandle;
    IPCINFO stDeviceInfo;
}SIPCOMMINFO;


#endif