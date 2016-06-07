#ifndef __CDADEVICEINTERFACE_H__
#define __CDADEVICEINTERFACE_H__
#include "publicDef.h"

class CDADeviceInterface
{
public:
    /**
     @brief 打开设备
     @param[IN] DEVICEINFO *paramIn
     @return 
     */
    virtual void openDevice(DEVICEINFO *paramIn) = 0;

    /**
     @brief 关闭设备
     @param[IN] DEVICEINFO *paramIn
     @return
     */
    virtual void closeDevice(DEVICEINFO *paramIn) = 0;

    /**
     @brief 获取设备信息
     @param[IN] DEVICEINFO *paramIn, void *paramOut
     */
    virtual bool getDeviceInfo(DEVICEINFO *paramIn, void *paramOut) = 0;

    /**
     @brief 初始化SDK
     @param[IN] 
     @param[OUT]
     @return
     */
    virtual void initSDK() = 0;

    /**
     @brief 反初始化SDK
     @param[IN]
     @param[OUT]
     @return
     */
    virtual void uninitSDK() = 0;

protected:
private:

};

class CChannelInterface
{
public:
    /**
     @brief 打开通道
     @param[IN] void *paramIn
     @param[OUT] void *paramOut
     @return 
      - 成功 true
      - 失败 false
     */
    virtual bool openChl(void *paramIn, void *paramOut) = 0;

    /**
     @brief 关闭通道
     @param[IN] void *paramIn
     @param[OUT] void *paramOut
     @return 
      - 成功 true
      - 失败 false
     */
    virtual bool closeChl(void *paramIn, void *paramOut) = 0;

    /**
     @brief 设置通道
     @param[IN] void *paramIn
     @return 
     - 成功 true
     - 失败 false
     */
    virtual bool setChl(void *paramIn) = 0;

    /**
     @brief 获取通道信息
     @param[IN] void *paramIn
     @param[OUT] void *paramOut
     @return 
     - 成功 true
     - 失败 false
     */
    virtual bool getChlInfo(void *paramIn, void *paramOut) = 0;

protected:
private:
};

class CAlarmInterface
{
public:
    /**
     @brief 订阅告警
     @param[IN] void *paramIn
     @return 
     - 成功 true
     - 失败 false
     */
    virtual bool subscribeAlarm(void *paramIn) = 0;

    /**
     @brief 取消订阅
     @param[IN] void *paramIn
     @return 
     - 成功 true
     -失败 false
    */
    virtual bool unSubscribeAlarm(void *paramIn) = 0;

     /**
     @brief 设置告警回调函数
     @return 
     - 成功 true
     -失败 false
    */
    virtual bool setAlarmCallBack(void) = 0;

protected:
private:
};
#endif
