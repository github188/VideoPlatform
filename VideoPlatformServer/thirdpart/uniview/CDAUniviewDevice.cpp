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
 @brief ���豸
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
        /* ��ʼ��SDK */
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

    /* ���õ������ӿڽ��е�¼���� */
    m_lpDevHandle = NETDEV_Login(szTempIP, pstDeviceInfo->nDevicePort, szTempLoginName, szTempLoginPwd, &stDevInfo);
    if(NULL == m_lpDevHandle)
    {
        /* ��¼ʧ�� */
        return FALSE;
    }

    return TRUE;
}

/**
 @brief �ر��豸
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
 @brief ��ʼ��SDK
 @param[IN] 
 @param[OUT]
 @return
 */
int CDAUnivewDevice::initSDK()
{
    int ret = TRUE;

    /* ���õ������ӿڳ�ʼ��SDK */
    ret = NETDEV_Init();
    if(TRUE != ret)
    {
        return FALSE;
    }

    return true;
}

/**
 @brief ����ʼ��SDK
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
 @brief ��ȡ�豸��Ϣ
 @param[IN] void *paramIn, void *paramOut
 */
int CDAUnivewDevice::getDeviceInfo(void *paramIn, void *paramOut)
{
    return true;
}

/**
 @brief ��ȡ�豸����
 @return std::string
 */
std::string CDAUnivewDevice::getDeviceName()
{
    std::string strDeviceName;
    return strDeviceName;
}

/**
 @brief ��ȡ�豸IP
 @return std::string
 */
std::string CDAUnivewDevice::getDeviceIP()
{
    std::string strDeviceIP;
    return strDeviceIP;
}

/**
 @brief ��ȡ�豸�˿�
 @return int
 */
int CDAUnivewDevice::getDevicePort()
{
    int nDevicePort;
    return nDevicePort;
}

/**
 @brief ��ȡ�豸ͨ����
 @return int
 */
int CDAUnivewDevice::getDeviceChlNum()
{
    int nDeviceChlNum;
    return nDeviceChlNum;
}

/**
 @brief ��ȡ�豸����
 @return ENUMDEVICETYPE
 */
ENUMDEVICETYPE CDAUnivewDevice::getDeviceType()
{
    ENUMDEVICETYPE enDeviceType;
    return enDeviceType;
}

/**
 @brief ��ȡͨ������
 @param[IN] void *paramIn
 @return CChannelInterface*
 */
CChannelInterface* CDAUnivewDevice::getChannelObject(void *paramIn)
{
    std::map<int, CChannelInterface*>::iterator iterChannel;
    INVITEINFO *pstDeviceInfo = (INVITEINFO*)paramIn;
    CChannelInterface *pChannel = NULL;

    /* �жϸ�ͨ���Ƿ��Ѿ��ڲ���ʵ�� */
    iterChannel = m_mapChannelManage.find(pstDeviceInfo->nChannelNum);
    if(m_mapChannelManage.end() != iterChannel)
    {
        /* ��ͨ���Ѿ���ʵ������ */
        pChannel = iterChannel->second;
    }
    else
    {
        pChannel = new CDAUniviewChannel;
        ((CDAUniviewChannel*)pChannel)->m_lDevHandle = m_lpDevHandle;
        /* ����ͨ�����浽map�� */
        m_mapChannelManage[pstDeviceInfo->nChannelNum] = pChannel;
    }
    return pChannel;
}
