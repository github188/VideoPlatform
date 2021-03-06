#include "CDADeviceInterface.h"
#include "CDADahuaDevice.h"
#include "CDADahuaChannel.h"

CDADahuaDevice::CDADahuaDevice()
{

}

CDADahuaDevice::~CDADahuaDevice()
{

}

/**
 @brief 打开设备
 @param[IN] void *paramIn
 @return 
 */
int CDADahuaDevice::openDevice(void *paramIn)
{
    return true;
}

/**
 @brief 关闭设备
 @param[IN] void *paramIn
 @return
 */
int CDADahuaDevice::closeDevice(void *paramIn)
{
    return true;
}

/**
 @brief 初始化SDK
 @param[IN] 
 @param[OUT]
 @return
 */
int CDADahuaDevice::initSDK()
{
    return true;
}

/**
 @brief 反初始化SDK
 @param[IN]
 @param[OUT]
 @return
 */
int CDADahuaDevice::uninitSDK()
{
    return true;
}

/**
 @brief 获取设备信息
 @param[IN] void *paramIn, void *paramOut
 */
int CDADahuaDevice::getDeviceInfo(void *paramIn, void *paramOut)
{
    return true;
}

/**
 @brief 获取设备名称
 @return std::string
 */
std::string CDADahuaDevice::getDeviceName()
{
    std::string strDeviceName;
    return strDeviceName;
}

/**
 @brief 获取设备IP
 @return std::string
 */
std::string CDADahuaDevice::getDeviceIP()
{
    std::string strDeviceIP;
    return strDeviceIP;
}

/**
 @brief 获取设备端口
 @return int
 */
int CDADahuaDevice::getDevicePort()
{
    int nDevicePort;
    return nDevicePort;
}

/**
 @brief 获取设备通道数
 @return int
 */
int CDADahuaDevice::getDeviceChlNum()
{
    int nDeviceChlNum;
    return nDeviceChlNum;
}

/**
 @brief 获取设备类型
 @return ENUMDEVICETYPE
 */
ENUMDEVICETYPE CDADahuaDevice::getDeviceType()
{
    ENUMDEVICETYPE enDeviceType;
    return enDeviceType;
}

/**
 @brief 获取通道对象
 @param[IN] void *paramIn
 @return CChannelInterface*
 */
CChannelInterface* CDADahuaDevice::getChannelObject(void *paramIn)
{
    std::map<int, CChannelInterface*>::iterator iterChannel;
    INVITEINFO *pstDeviceInfo = (INVITEINFO*)paramIn;
    CChannelInterface *pChannel;

    /* 判断该通道是否已经在播放实况 */
    iterChannel = m_mapChannelManage.find(pstDeviceInfo->nChannelNum);
    if(m_mapChannelManage.end() != iterChannel)
    {
        /* 该通道已经有实况播放 */
        pChannel = iterChannel->second;
    }
    else
    {
        pChannel = new CDADahuaChannel;
        /* 将该通道保存到map中 */
        m_mapChannelManage[pstDeviceInfo->nChannelNum] = pChannel;
    }
    return pChannel;
}
