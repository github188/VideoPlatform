#ifndef __PUBLICDEF_H__
#define __PUBLICDEF_H__

#include <iostream>
using namespace std;
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
    QString strDeviceName;   //�豸����
    QString strDeviceIP;     //�豸IP
    int nDeviceID;          //�豸ID(IDΨһ)
    int nDevicePort;        //�豸�˿�
    int nDeviceChlNum;      //�豸ͨ������IPCֻ��һ��ͨ��
    ENUMDEVICETYPE enDeviceType;   //�豸����
}DEVICEINFO, *pstDeviceInfo;


typedef struct tagIpcInfo
{
    QString strDeviceName;  //�豸����
    QString strDeviceIP;    //�豸IP
    int nDeviceID;          //�豸ID
    int nDevicePort;        //�豸�˿�
    bool ishasParent;       //�Ƿ���и��ڵ�
    QString strParentName;  //����и��ڵ㣬���ڵ�����
    QString strParentIP;    //���ڵ�IP
    int nParentID;          //���ڵ�ID
    int nParentPort;        //���ڵ�˿�
    int nChlIndex;          //�����ӽڵ��num
    ENUMDEVICETYPE enDeviceType;   //�豸����
}IPCINFO, *pstIpcInfo;

typedef struct tagSipCommInfo
{
    int nWndNum;
    HWND hWndHandle;
    IPCINFO stDeviceInfo;
}SIPCOMMINFO;


#endif