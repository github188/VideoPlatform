#include "CDADeviceInterface.h"
#include "CDAUniviewDevice.h"
#include "CDAUniviewChannel.h"

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
    return true;
}

/**
 @brief �ر��豸
 @param[IN] void *paramIn
 @return
 */
int CDAUnivewDevice::closeDevice(void *paramIn)
{
    return true;
}

/**
 @brief ��ʼ��SDK
 @param[IN] 
 @param[OUT]
 @return
 */
int CDAUnivewDevice::initSDK()
{
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
    return true;
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
        pChannel = new CDAUniviewChannel;
        /* ����ͨ�����浽map�� */
        m_mapChannelManage[pstDeviceInfo->nDeviceChlNum] = pChannel;
    }
    return pChannel;
}
