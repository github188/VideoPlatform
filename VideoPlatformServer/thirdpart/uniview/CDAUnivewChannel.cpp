#include "publicDef.h"
#include "NetDEVSDK.h"
#include "CDADeviceInterface.h"
#include "CDAUniviewChannel.h"

/**
 @brief ��ͨ��
 @param[IN] void *paramIn
 @param[OUT] void *paramOut
 @return 
 - �ɹ� true
 - ʧ�� false
 */
bool CDAUniviewChannel::openChl(void *paramIn/*, void *paramLoginHandle*/)
{
    INVITEINFO *stPlayParamIn = (INVITEINFO*)paramIn;
    NETDEV_PREVIEWINFO_S stNetInfo = {0};
    stNetInfo.dwChannelID = stPlayParamIn->nChannelNum;
    stNetInfo.hPlayWnd = NULL;
    stNetInfo.dwStreamType = NETDEV_LIVE_STREAM_INDEX_MAIN;
    stNetInfo.dwLinkMode = NETDEV_TRANSPROTOCAL_RTPTCP;
    /* ���õ������ӿڴ�ʵ�� */
    m_lplayHandle = (void *)NETDEV_RealPlay(m_lDevHandle, &stNetInfo, NULL, 0);
    if(NULL == m_lplayHandle)
    {
        return FALSE;
    }

    NETDEV_StopRealPlay(m_lplayHandle);

    m_lplayHandle = NULL;

    return TRUE;
}

/**
 @brief �ر�ͨ��
 @param[IN] void *paramIn
 @param[OUT] void *paramOut
 @return 
 - �ɹ� true
 - ʧ�� false
 */
bool CDAUniviewChannel::closeChl(void *paramIn/*, void *paramOut*/)
{
    int ret = TRUE;

    ret = NETDEV_StopRealPlay(m_lplayHandle);
    if(TRUE != ret)
    {
        return FALSE;
    }

    return TRUE;
}

/**
 @brief ����ͨ��
 @param[IN] void *paramIn
 @return 
 - �ɹ� true
 - ʧ�� false
 */
bool CDAUniviewChannel::setChl(void *paramIn)
{
    return true;
}

/**
 @brief ��ȡͨ����Ϣ
 @param[IN] void *paramIn
 @param[OUT] void *paramOut
 @return 
 - �ɹ� true
 - ʧ�� false
 */
bool CDAUniviewChannel::getChlInfo(void *paramIn, void *paramOut)
{
    return true;
}

/**
 @brief ���ĸ澯
 @param[IN] void *paramIn
 @return 
 - �ɹ� true
 - ʧ�� false
*/
bool CDAUniviewAlarm::subscribeAlarm(void *paramIn)
{
    return true;
}

/**
 @brief ȡ������
 @param[IN] void *paramIn
 @return 
 - �ɹ� true
 -ʧ�� false
 */
bool CDAUniviewAlarm::unSubscribeAlarm(void *paramIn)
{
    return true;
}

/**
 @brief ���ø澯�ص�����
 @return 
 - �ɹ� true
 -ʧ�� false
 */
bool CDAUniviewAlarm::setAlarmCallBack(void)
{
    return true;
}