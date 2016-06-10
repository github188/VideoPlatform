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
 @brief ���豸
 @param[IN] void *paramIn
 @return 
 */
int CDAHikDevice::openDevice(void *paramIn)
{
    return true;
}

/**
 @brief �ر��豸
 @param[IN] void *paramIn
 @return
 */
int CDAHikDevice::closeDevice(void *paramIn)
{
    return true;
}

/**
 @brief ��ʼ��SDK
 @param[IN] 
 @param[OUT]
 @return
 */
int CDAHikDevice::initSDK()
{
    return true;
}

/**
 @brief ����ʼ��SDK
 @param[IN]
 @param[OUT]
 @return
 */
int CDAHikDevice::uninitSDK()
{
    return true;
}

/**
 @brief ��ȡ�豸��Ϣ
 @param[IN] void *paramIn, void *paramOut
 */
int CDAHikDevice::getDeviceInfo(void *paramIn, void *paramOut)
{
    return true;
}

/**
 @brief ��ȡ�豸����
 @return std::string
 */
std::string CDAHikDevice::getDeviceName()
{
    std::string strDeviceName;
    return strDeviceName;
}

/**
 @brief ��ȡ�豸IP
 @return std::string
 */
std::string CDAHikDevice::getDeviceIP()
{
    std::string strDeviceIP;
    return strDeviceIP;
}

/**
 @brief ��ȡ�豸�˿�
 @return int
 */
int CDAHikDevice::getDevicePort()
{
    int nDevicePort;
    return nDevicePort;
}

/**
 @brief ��ȡ�豸ͨ����
 @return int
 */
int CDAHikDevice::getDeviceChlNum()
{
    int nDeviceChlNum;
    return nDeviceChlNum;
}

/**
 @brief ��ȡ�豸����
 @return ENUMDEVICETYPE
 */
ENUMDEVICETYPE CDAHikDevice::getDeviceType()
{
    ENUMDEVICETYPE enDeviceType;
    return enDeviceType;
}

/**
 @brief ��ȡͨ������
 @param[IN] void *paramIn
 @return CChannelInterface*
 */
CChannelInterface* CDAHikDevice::getChannelObject(void *paramIn)
{
    std::map<int, CChannelInterface*>::iterator iterChannel;
    DEVICEINFO *pstDeviceInfo = (DEVICEINFO*)paramIn;
    CChannelInterface *pChannel;

    /* �жϸ�ͨ���Ƿ��Ѿ��ڲ���ʵ�� */
    iterChannel = m_mapChannelManage.find(pstDeviceInfo->nDeviceChlNum);
    if(m_mapChannelManage.end() != iterChannel)
    {
        /* ��ͨ���Ѿ���ʵ������ */
    }
    else
    {
        pChannel = new CDAHikChannel;
        /* ����ͨ�����浽map�� */
        m_mapChannelManage[pstDeviceInfo->nDeviceChlNum] = pChannel;
    }
    return pChannel;
}
