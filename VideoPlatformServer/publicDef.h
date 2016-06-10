#ifndef __PUBLICDEF_H__
#define __PUBLICDEF_H__
// #include <WinDef.h>
// #include <Windows.h>
#include <iostream>

/****************�궨��***********************/
#define IN
#define OUT

/****************����ö������  ****************/
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

/****************�ṹ�嶨��********************/
/* �豸����ṹ */
typedef struct tagDeviceInfo
{
    std::string strDeviceName;   //�豸����
    std::string strDeviceIP;     //�豸IP
    int nDeviceID;          //�豸ID(IDΨһ)
    int nDevicePort;        //�豸�˿�
    int nDeviceChlNum;      //�豸ͨ������IPCֻ��һ��ͨ��
    ENUMDEVICETYPE enDeviceType;   //�豸����
}DEVICEINFO, *pstDeviceInfo;


typedef struct tagIpcInfo
{
    std::string strDeviceName;  //�豸����
    std::string strDeviceIP;    //�豸IP
    int nDeviceID;          //�豸ID
    int nDevicePort;        //�豸�˿�
    bool ishasParent;       //�Ƿ���и��ڵ�
    std::string strParentName;  //����и��ڵ㣬���ڵ�����
    std::string strParentIP;    //���ڵ�IP
    int nParentID;          //���ڵ�ID
    int nParentPort;        //���ڵ�˿�
    int nChlIndex;          //�����ӽڵ��num
    ENUMDEVICETYPE enDeviceType;   //�豸����
}IPCINFO, *pstIpcInfo;

typedef struct tagSipCommInfo
{
    int nWndNum;
/*    HWND hWndHandle;*/
    void* lPlayHandle;
    IPCINFO stDeviceInfo;
}SIPCOMMINFO;


#endif