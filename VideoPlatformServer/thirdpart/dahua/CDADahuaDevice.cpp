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
 @brief ���豸
 @param[IN] void *paramIn
 @return 
 */
int CDADahuaDevice::openDevice(void *paramIn)
{
    return true;
}

/**
 @brief �ر��豸
 @param[IN] void *paramIn
 @return
 */
int CDADahuaDevice::closeDevice(void *paramIn)
{
    return true;
}

/**
 @brief ��ʼ��SDK
 @param[IN] 
 @param[OUT]
 @return
 */
int CDADahuaDevice::initSDK()
{
    return true;
}

/**
 @brief ����ʼ��SDK
 @param[IN]
 @param[OUT]
 @return
 */
int CDADahuaDevice::uninitSDK()
{
    return true;
}

/**
 @brief ��ȡ�豸��Ϣ
 @param[IN] void *paramIn, void *paramOut
 */
int CDADahuaDevice::getDeviceInfo(void *paramIn, void *paramOut)
{
    return true;
}

/**
 @brief ��ȡ�豸����
 @return std::string
 */
std::string CDADahuaDevice::getDeviceName()
{
    std::string strDeviceName;
    return strDeviceName;
}

/**
 @brief ��ȡ�豸IP
 @return std::string
 */
std::string CDADahuaDevice::getDeviceIP()
{
    std::string strDeviceIP;
    return strDeviceIP;
}

/**
 @brief ��ȡ�豸�˿�
 @return int
 */
int CDADahuaDevice::getDevicePort()
{
    int nDevicePort;
    return nDevicePort;
}

/**
 @brief ��ȡ�豸ͨ����
 @return int
 */
int CDADahuaDevice::getDeviceChlNum()
{
    int nDeviceChlNum;
    return nDeviceChlNum;
}

/**
 @brief ��ȡ�豸����
 @return ENUMDEVICETYPE
 */
ENUMDEVICETYPE CDADahuaDevice::getDeviceType()
{
    ENUMDEVICETYPE enDeviceType;
    return enDeviceType;
}

/**
 @brief ��ȡͨ������
 @param[IN] void *paramIn
 @return CChannelInterface*
 */
CChannelInterface* CDADahuaDevice::getChannelObject(void *paramIn)
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
        pChannel = new CDADahuaChannel;
        /* ����ͨ�����浽map�� */
        m_mapChannelManage[pstDeviceInfo->nDeviceChlNum] = pChannel;
    }
    return pChannel;
}
