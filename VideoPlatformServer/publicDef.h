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

/****************结构体定义********************/
/* 设备对象结构 */
typedef struct tagDeviceInfo
{
    string strDeviceName;   //设备名称
    string strDeviceIP;     //设备IP
    int nDeviceID;          //设备ID(ID唯一)
    int nDevicePort;        //设备端口
    int nDeviceChlNum;      //设备通道数，IPC只有一个通道
    ENUMDEVICETYPE enDeviceType;   //设备类型

}DEVICEINFO, *pstDeviceInfo;

#endif