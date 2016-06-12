#include "CDADeviceInterface.h"
#include "CDAUniviewDevice.h"
#include "CDAUniviewChannel.h"
#include <sstream>
#include "NetDEVSDK.h"

CDAUnivewDevice::CDAUnivewDevice()
{

}

CDAUnivewDevice::~CDAUnivewDevice()
{

}

/**
 @brief 打开设备
 @param[IN] void *paramIn
 @return 
 */
int CDAUnivewDevice::openDevice(void *paramIn)
{
    static int i11 = 0;
    int ret = true;
    DEVICEINFO *pstDeviceInfo = (DEVICEINFO*)paramIn;
    NETDEV_DEVICE_INFO_S stDevInfo = {0};
    std::stringstream strTemp;
    char szTempIP[20];
    char szTempLoginName[20];
    char szTempLoginPwd[20];

    if(i11 == 0)
    {
        /* 初始化SDK */
        ret = initSDK();
        i11++;
    }
    strTemp << pstDeviceInfo->strDeviceIP;
    strTemp >> szTempIP;

    strTemp.clear();
    strTemp.str("");
    strTemp << pstDeviceInfo->strDeviceLoginName;
    strTemp >> szTempLoginName;

    strTemp.clear();
    strTemp.str("");
    strTemp << pstDeviceInfo->strDeviceLoginPwd;
    strTemp >> szTempLoginPwd;

    /* 调用第三方接口进行登录操作 */
    m_lpDevHandle = NETDEV_Login(szTempIP, pstDeviceInfo->nDevicePort, szTempLoginName, szTempLoginPwd, &stDevInfo);
    if(NULL == m_lpDevHandle)
    {
        /* 登录失败 */
        return FALSE;
    }

    return TRUE;
}

/**
 @brief 关闭设备
 @param[IN] void *paramIn
 @return
 */
int CDAUnivewDevice::closeDevice(void *paramIn)
{
    int ret = TRUE;

    ret = NETDEV_Logout(m_lpDevHandle);
    if(TRUE != ret)
    {
        return FALSE;
    }

    return TRUE;
}

/**
 @brief 初始化SDK
 @param[IN] 
 @param[OUT]
 @return
 */
int CDAUnivewDevice::initSDK()
{
    int ret = TRUE;

    /* 调用第三方接口初始化SDK */
    ret = NETDEV_Init();
    if(TRUE != ret)
    {
        return FALSE;
    }

    return true;
}

/**
 @brief 反初始化SDK
 @param[IN]
 @param[OUT]
 @return
 */
int CDAUnivewDevice::uninitSDK()
{
    int ret = TRUE;

    ret = NETDEV_Cleanup();
    if(TRUE != ret)
    {
        return FALSE;
    }

    return TRUE;
}

/**
 @brief 获取设备信息
 @param[IN] void *paramIn, void *paramOut
 */
int CDAUnivewDevice::getDeviceInfo(void *paramIn, void *paramOut)
{
    return true;
}

/**
 @brief 获取设备名称
 @return std::string
 */
std::string CDAUnivewDevice::getDeviceName()
{
    std::string strDeviceName;
    return strDeviceName;
}

/**
 @brief 获取设备IP
 @return std::string
 */
std::string CDAUnivewDevice::getDeviceIP()
{
    std::string strDeviceIP;
    return strDeviceIP;
}

/**
 @brief 获取设备端口
 @return int
 */
int CDAUnivewDevice::getDevicePort()
{
    int nDevicePort;
    return nDevicePort;
}

/**
 @brief 获取设备通道数
 @return int
 */
int CDAUnivewDevice::getDeviceChlNum()
{
    int nDeviceChlNum;
    return nDeviceChlNum;
}

/**
 @brief 获取设备类型
 @return ENUMDEVICETYPE
 */
ENUMDEVICETYPE CDAUnivewDevice::getDeviceType()
{
    ENUMDEVICETYPE enDeviceType;
    return enDeviceType;
}

/**
 @brief 获取通道对象
 @param[IN] void *paramIn
 @return CChannelInterface*
 */
CChannelInterface* CDAUnivewDevice::getChannelObject(void *paramIn)
{
    std::map<int, CChannelInterface*>::iterator iterChannel;
    INVITEINFO *pstDeviceInfo = (INVITEINFO*)paramIn;
    CChannelInterface *pChannel = NULL;

    /* 判断该通道是否已经在播放实况 */
    iterChannel = m_mapChannelManage.find(pstDeviceInfo->nChannelNum);
    if(m_mapChannelManage.end() != iterChannel)
    {
        /* 该通道已经有实况播放 */
        pChannel = iterChannel->second;
    }
    else
    {
        pChannel = new CDAUniviewChannel;
        ((CDAUniviewChannel*)pChannel)->m_lDevHandle = m_lpDevHandle;
        /* 将该通道保存到map中 */
        m_mapChannelManage[pstDeviceInfo->nChannelNum] = pChannel;
    }
    return pChannel;
}
