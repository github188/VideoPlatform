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
bool CDAUniviewChannel::openChl(void *paramIn, void *paramOut)
{
    return true;
}

/**
 @brief 关闭通道
 @param[IN] void *paramIn
 @param[OUT] void *paramOut
 @return 
 - 成功 true
 - 失败 false
 */
bool CDAUniviewChannel::closeChl(void *paramIn, void *paramOut)
{
    return true;
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