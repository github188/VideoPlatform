#include <map>
#include <iostream>
//#include <string>
#include "publicDef.h"
#include "CMessageCenter.h"
#include "CDADeviceInterface.h"
#include "CDADeviceFactory.h"

/* 保存注册到服务器的设备 */
std::map<int, CDADeviceInterface *> mapDeviceInfo;

/**
 @brief 开始实时预览总接口
 @param[IN] void *paramIn
 @return 
 - 成功 true
 - 失败 false
 */
int startRealData(void *paramIn)
{
    DEVICEINFO *pstDevInfo = (DEVICEINFO*)paramIn;
    std::map<int, CDADeviceInterface*>::iterator iterDevInfo;
    void *paramOut;
    int ret = true;

    /* 判断该设备是否存在 */
    iterDevInfo = mapDeviceInfo.find(pstDevInfo->nDeviceID);
    if(mapDeviceInfo.end() != iterDevInfo)
    {
        /* 服务器中有该设备，执行打开实况操作*/
        ret = iterDevInfo->second->getChannelObject(paramIn)->openChl(paramIn, paramOut);
        if(true != ret)
        {

        }
        else
        {

        }
    }
    else
    {
        /* 不存在该设备 */
        return false;
    }

    return true;
}
/**
 @brief 结束实时预览总接口
 @param[IN] void *paramIn
 @return 
 - 成功 true
 - 失败 false
 */
int closeRealData(void *paramIn)
{
    DEVICEINFO *pstDevInfo = (DEVICEINFO*)paramIn;
    std::map<int, CDADeviceInterface*>::iterator iterDevInfo;
    void *paramOut;
    int ret = true;

    /* 判断该设备是否存在 */
    iterDevInfo = mapDeviceInfo.find(pstDevInfo->nDeviceID);
    if(mapDeviceInfo.end() != iterDevInfo)
    {
        /* 服务器中有该设备，执行打开实况操作*/
        ret = iterDevInfo->second->getChannelObject(paramIn)->openChl(paramIn, paramOut);
        if(true != ret)
        {

        }
        else
        {

        }
    }
    else
    {
        /* 不存在该设备 */
        return false;
    }

    return true;
}

/**
 @brief 告警总接口
 @param[IN] void *paramIn
 @return 
 - 成功 true
 - 失败 false
 */
int dealAlarmfunc(void *paramIn)
{
    return true;
}

/**
 @brief 开始回放总接口
 @param[IN] void *paramIn
 @return 
 - 成功 true
 - 失败 false
 */
int startPlayBack(void *paramIn)
{

    return true;
}

/**
 @brief 开始回放总接口
 @param[IN] void *paramIn
 @return 
 - 成功 true
 - 失败 false
 */
int closePlayBack(void *paramIn)
{

    return true;
}

/**
 @brief 打开设备接口
 @param[IN] void *paramIn
 @return 
 - 成功 true
 - 失败 false
 */
int openDevicefunc(void *paramIn)
{
    DEVICEINFO *pstDevInfo = (DEVICEINFO*)paramIn;
    std::map<int, CDADeviceInterface*>::iterator iterDevInfo;

    /* 判断该设备是否存在 */
    iterDevInfo = mapDeviceInfo.find(pstDevInfo->nDeviceID);
    if(mapDeviceInfo.end() != iterDevInfo)
    {
        /* 服务器中已经有该设备信息了，返回成功*/
        return true;
    }
    else
    {
        /* 新建该对象存放到MAP中 */
        CDADeviceInterface *pDevice = CDADeviceFactory::getDevice(paramIn);
        if(NULL == pDevice)
        {
            return false;
        }
        else
        {
            /* 打开设备 */
            pDevice->openDevice(pstDevInfo);

            /* 将该对象保存到map中 */
            mapDeviceInfo[pstDevInfo->nDeviceID] = pDevice;
        }
    }

    return true;
}

/**
 @brief 关闭设备
 @param[IN] void *paramIn
 @return 
 - 成功 true
 - 失败 false
 */
int closeDevicefunc(void *paramIn)
{
    DEVICEINFO *pstDevInfo = (DEVICEINFO*)paramIn;
    std::map<int, CDADeviceInterface*>::iterator iterDevInfo;

    /* 判断该设备是否存在 */
    iterDevInfo = mapDeviceInfo.find(pstDevInfo->nDeviceID);
    if(mapDeviceInfo.end() != iterDevInfo)
    {
        /* 服务器没有改设备信息*/
        return true;
    }
    else
    {
        /* 调用接口关闭设备 */
        iterDevInfo->second->closeDevice(paramIn);

        /* 将设备信息删除 */
        mapDeviceInfo.erase(iterDevInfo);
    }
    return true;
}

/**
 @brief 构造函数
 */
CMessageCenter::CMessageCenter()
{

}

/**
 @brief 析构函数
 */
CMessageCenter::~CMessageCenter()
{

}

/**
 @brief 消息处理中心
 @param[IN] void *paramMesgDataIn
 @param[IN] enMessageType enMesgType
 @return 
 - 成功 true
 - 失败 false
 */
int CMessageCenter::messageCenter(void *paramMesgDataIn, enMessageType enMesgType)
{
    int ret = true;
    int ret1 = true;

    if(paramMesgDataIn == NULL)
    {
        return false;
    }

    /* 判断是哪一种类型的消息 */
    switch(enMesgType)
    {
        case InvitePriview : 
            {
                ret = startRealData(paramMesgDataIn);
                if(ret != true)
                {
                    ret1 = false;
                }
                else
                {
                    ret1 = true;
                }
                break;
            }
        case ClosePriview : 
            {
                ret = closeRealData(paramMesgDataIn);
                if(ret != true)
                {
                    ret1 = false;
                }
                else
                {
                    ret1 = true;
                }
                break;
            }
        case ReceiveAlarm :
            {
                ret = dealAlarmfunc(paramMesgDataIn);
                if(ret != true)
                {
                    ret1 = false;
                }
                else
                {
                    ret1 = true;
                }

                break;
            }
        case InvitePlayBack :
            {
                ret = startPlayBack(paramMesgDataIn);
                if(ret != true)
                {
                    ret1 = false;
                }
                else
                {
                    ret1 = true;
                }
                break;
            }
        case SearchVideo : break;
        case OpenDevice:
            {
                ret = openDevicefunc(paramMesgDataIn);
                if(ret != true)
                {
                    ret1 = false;
                }
                else
                {
                    ret1 = true;
                }
                break;
            }
        case CloseDevice:
            {
                ret = closeDevicefunc(paramMesgDataIn);
                if(ret != true)
                {
                    ret1 = false;
                }
                else
                {
                    ret1 = true;
                }
                break;
            }
        default:break;
    }

    return true;
}