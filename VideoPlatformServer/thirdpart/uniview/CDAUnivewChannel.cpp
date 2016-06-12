#include "publicDef.h"
#include "NetDEVSDK.h"
#include "CDADeviceInterface.h"
#include "CDAUniviewChannel.h"

/**
 @brief 打开通道
 @param[IN] void *paramIn
 @param[OUT] void *paramOut
 @return 
 - 成功 true
 - 失败 false
 */
bool CDAUniviewChannel::openChl(void *paramIn/*, void *paramLoginHandle*/)
{
    INVITEINFO *stPlayParamIn = (INVITEINFO*)paramIn;
    NETDEV_PREVIEWINFO_S stNetInfo = {0};
    stNetInfo.dwChannelID = stPlayParamIn->nChannelNum;
    stNetInfo.hPlayWnd = NULL;
    stNetInfo.dwStreamType = NETDEV_LIVE_STREAM_INDEX_MAIN;
    stNetInfo.dwLinkMode = NETDEV_TRANSPROTOCAL_RTPTCP;
    /* 调用第三方接口打开实况 */
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
 @brief 关闭通道
 @param[IN] void *paramIn
 @param[OUT] void *paramOut
 @return 
 - 成功 true
 - 失败 false
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
 @brief 设置通道
 @param[IN] void *paramIn
 @return 
 - 成功 true
 - 失败 false
 */
bool CDAUniviewChannel::setChl(void *paramIn)
{
    return true;
}

/**
 @brief 获取通道信息
 @param[IN] void *paramIn
 @param[OUT] void *paramOut
 @return 
 - 成功 true
 - 失败 false
 */
bool CDAUniviewChannel::getChlInfo(void *paramIn, void *paramOut)
{
    return true;
}

/**
 @brief 订阅告警
 @param[IN] void *paramIn
 @return 
 - 成功 true
 - 失败 false
*/
bool CDAUniviewAlarm::subscribeAlarm(void *paramIn)
{
    return true;
}

/**
 @brief 取消订阅
 @param[IN] void *paramIn
 @return 
 - 成功 true
 -失败 false
 */
bool CDAUniviewAlarm::unSubscribeAlarm(void *paramIn)
{
    return true;
}

/**
 @brief 设置告警回调函数
 @return 
 - 成功 true
 -失败 false
 */
bool CDAUniviewAlarm::setAlarmCallBack(void)
{
    return true;
}