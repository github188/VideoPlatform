#ifndef __CDAUNIVIEWCHANNEL_H__
#define __CDAUNIVIEWCHANNEL_H__

class CDAUniviewChannel:public CChannelInterface
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
    bool openChl(void *paramIn/*, void *paramLoginHandle*/);

    /**
     @brief 关闭通道
     @param[IN] void *paramIn
     @param[OUT] void *paramOut
     @return 
      - 成功 true
      - 失败 false
     */
    bool closeChl(void *paramIn/*, void *paramOut*/);

    /**
     @brief 设置通道
     @param[IN] void *paramIn
     @return 
     - 成功 true
     - 失败 false
     */
    bool setChl(void *paramIn);

    /**
     @brief 获取通道信息
     @param[IN] void *paramIn
     @param[OUT] void *paramOut
     @return 
     - 成功 true
     - 失败 false
     */
    bool getChlInfo(void *paramIn, void *paramOut);

public:
    void *m_lDevHandle;
protected:
private:
    /* 实况句柄 */
    void *m_lplayHandle;

};

class CDAUniviewAlarm : public CAlarmInterface
{
public:
    /**
     @brief 订阅告警
     @param[IN] void *paramIn
     @return 
     - 成功 true
     - 失败 false
     */
    bool subscribeAlarm(void *paramIn);

    /**
     @brief 取消订阅
     @param[IN] void *paramIn
     @return 
     - 成功 true
     -失败 false
    */
    bool unSubscribeAlarm(void *paramIn);

     /**
     @brief 设置告警回调函数
     @return 
     - 成功 true
     -失败 false
    */
    bool setAlarmCallBack(void);

protected:
private:
};
#endif