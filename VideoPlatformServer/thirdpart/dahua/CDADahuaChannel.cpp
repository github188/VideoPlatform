#include "CDADeviceInterface.h"
#include "CDADahuaChannel.h"

/**
 @brief 打开通道
 @param[IN] void *paramIn
 @param[OUT] void *paramOut
 @return 
 - 成功 true
 - 失败 false
 */
bool CDADahuaChannel::openChl(void *paramIn/*, void *paramLoginHandle*/)
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
bool CDADahuaChannel::closeChl(void *paramIn/*, void *paramOut*/)
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
bool CDADahuaChannel::setChl(void *paramIn)
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
bool CDADahuaChannel::getChlInfo(void *paramIn, void *paramOut)
{
    return true;
}