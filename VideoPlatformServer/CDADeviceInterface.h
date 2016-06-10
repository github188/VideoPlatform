#ifndef __CDADEVICEINTERFACE_H__
#define __CDADEVICEINTERFACE_H__
#include "publicDef.h"

class CDADeviceInterface
{
public:
    /**
     @brief 打开设备
     @param[IN] void *paramIn
     @return 
     */
    virtual int openDevice(void *paramIn) = 0;

    /**
     @brief 关闭设备
     @param[IN] void *paramIn
     @return
     */
    virtual int closeDevice(void *paramIn) = 0;

    /**
     @brief 获取设备信息
     @param[IN] void *paramIn, void *paramOut
     */
    virtual int getDeviceInfo(void *paramIn, void *paramOut) = 0;

    /**
     @brief 初始化SDK
     @param[IN] 
     @param[OUT]
     @return
     */
    virtual int initSDK() = 0;

    /**
     @brief 反初始化SDK
     @param[IN]
     @param[OUT]
     @return
     */
    virtual int uninitSDK() = 0;

    /**
     @brief 获取设备名称
     @return std::string
     */
    virtual std::string getDeviceName() = 0;

    /**
     @brief 获取设备IP
     @return std::string
     */
    virtual std::string getDeviceIP() = 0;

    /**
     @brief 获取设备端口
     @return int
    */
    virtual int getDevicePort() = 0;

    /**
     @brief 获取设备通道数
     @return int
    */
    virtual int getDeviceChlNum() = 0;

    /**
     @brief 获取设备类型
     @return ENUMDEVICETYPE
     */
    virtual ENUMDEVICETYPE getDeviceType() = 0;

protected:
private:
    std::string strDeviceName;   //设备名称
    std::string strDeviceIP;     //设备IP
    int nDeviceID;          //设备ID(ID唯一)
    int nDevicePort;        //设备端口
    int nDeviceChlNum;      //设备通道数，IPC只有一个通道
    ENUMDEVICETYPE enDeviceType;   //设备类型
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
