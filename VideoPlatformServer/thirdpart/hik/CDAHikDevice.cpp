#include "CDADeviceInterface.h"
#include "CDAHikDevice.h"
#include "CDAHikChannel.h"

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

/**
 @brief 获取通道对象
 @param[IN] void *paramIn
 @return CChannelInterface*
 */
CChannelInterface* CDAHikDevice::getChannelObject(void *paramIn)
{
    std::map<int, CChannelInterface*>::iterator iterChannel;
    DEVICEINFO *pstDeviceInfo = (DEVICEINFO*)paramIn;
    CChannelInterface *pChannel;

    /* 判断该通道是否已经在播放实况 */
    iterChannel = m_mapChannelManage.find(pstDeviceInfo->nDeviceChlNum);
    if(m_mapChannelManage.end() != iterChannel)
    {
        /* 该通道已经有实况播放 */
    }
    else
    {
        pChannel = new CDAHikChannel;
        /* 将该通道保存到map中 */
        m_mapChannelManage[pstDeviceInfo->nDeviceChlNum] = pChannel;
    }
    return pChannel;
}
