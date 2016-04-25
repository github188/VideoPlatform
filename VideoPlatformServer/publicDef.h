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

/****************�ṹ�嶨��********************/
/* �豸����ṹ */
typedef struct tagDeviceInfo
{
    string strDeviceName;   //�豸����
    string strDeviceIP;     //�豸IP
    int nDeviceID;          //�豸ID(IDΨһ)
    int nDevicePort;        //�豸�˿�
    int nDeviceChlNum;      //�豸ͨ������IPCֻ��һ��ͨ��
    ENUMDEVICETYPE enDeviceType;   //�豸����

}DEVICEINFO, *pstDeviceInfo;

#endif