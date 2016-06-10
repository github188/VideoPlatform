#include "CDADeviceInterface.h"
#include "CDAHikDevice.h"

CDAHikDevice::CDAHikDevice()
{

}

CDAHikDevice::~CDAHikDevice()
{

}

/**
 @brief 打开设备
 @param[IN] void *paramIn
 @return 
 */
int CDAHikDevice::openDevice(void *paramIn)
{
    return true;
}

/**
 @brief 关闭设备
 @param[IN] void *paramIn
 @return
 */
int CDAHikDevice::closeDevice(void *paramIn)
{
    return true;
}

/**
 @brief 初始化SDK
 @param[IN] 
 @param[OUT]
 @return
 */
int CDAHikDevice::initSDK()
{
    return true;
}

/**
 @brief 反初始化SDK
 @param[IN]
 @param[OUT]
 @return
 */
int CDAHikDevice::uninitSDK()
{
    return true;
}

/**
 @brief 获取设备信息
 @param[IN] void *paramIn, void *paramOut
 */
int CDAHikDevice::getDeviceInfo(void *paramIn, void *paramOut)
{
    return true;
}

/**
 @brief 获取设备名称
 @return std::string
 */
std::string CDAHikDevice::getDeviceName()
{
    std::string strDeviceName;
    return strDeviceName;
}

/**
 @brief 获取设备IP
 @return std::string
 */
std::string CDAHikDevice::getDeviceIP()
{
    std::string strDeviceIP;
    return strDeviceIP;
}

/**
 @brief 获取设备端口
 @return int
 */
int CDAHikDevice::getDevicePort()
{
    int nDevicePort;
    return nDevicePort;
}

/**
 @brief 获取设备通道数
 @return int
 */
int CDAHikDevice::getDeviceChlNum()
{
    int nDeviceChlNum;
    return nDeviceChlNum;
}

/**
 @brief 获取设备类型
 @return ENUMDEVICETYPE
 */
ENUMDEVICETYPE CDAHikDevice::getDeviceType()
{
    ENUMDEVICETYPE enDeviceType;
    return enDeviceType;
}