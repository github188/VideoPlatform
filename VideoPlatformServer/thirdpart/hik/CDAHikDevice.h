#ifndef __CDAHIKDEVICE_H__
#define __CDAHIKDEVICE_H__

class CDAHikDevice : public CDADeviceInterface
{
public:
    /**
     @brief 构造函数
     */
    CDAHikDevice();

    /**
     @brief 析构函数
     */
    ~CDAHikDevice();

    /**
     @brief 打开设备
     @param[IN] void *paramIn
     @return 
     */
     int openDevice(void *paramIn);

    /**
     @brief 关闭设备
     @param[IN] void *paramIn
     @return
     */
    int closeDevice(void *paramIn);

    /**
     @brief 获取设备信息
     @param[IN] void *paramIn, void *paramOut
     */
    int getDeviceInfo(void *paramIn, void *paramOut);

    /**
     @brief 初始化SDK
     @param[IN] 
     @param[OUT]
     @return
     */
    int initSDK();

    /**
     @brief 反初始化SDK
     @param[IN]
     @param[OUT]
     @return
     */
    int uninitSDK();

    /**
     @brief 获取设备名称
     @return std::string
     */
    std::string getDeviceName();

    /**
     @brief 获取设备IP
     @return std::string
     */
    std::string getDeviceIP();

    /**
     @brief 获取设备端口
     @return int
    */
    int getDevicePort();

    /**
     @brief 获取设备通道数
     @return int
    */
    int getDeviceChlNum();

    /**
     @brief 获取设备类型
     @return ENUMDEVICETYPE
     */
    ENUMDEVICETYPE getDeviceType();

    /**
     @brief 获取通道对象
     @param[IN] void *paramIn
     @return CChannelInterface*
     */
    CChannelInterface* getChannelObject(void *paramIN);


protected:
private:
};

#endif
