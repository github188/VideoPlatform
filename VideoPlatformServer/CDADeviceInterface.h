#ifndef __CDADEVICEINTERFACE_H__
#define __CDADEVICEINTERFACE_H__

class CDADeviceInterface
{
public:
    /**
     @brief 构造函数
     */
//    CDADeviceInterface();

    /**
     @brief 析构函数
     */
//    ~CDADeviceInterface();

    /**
     @brief 打开设备
     @param[IN]
     @return 
     */
    virtual void openDevice() = 0;

    /**
     @brief 关闭设备
     @param[IN]
     @return
     */
    virtual void closeDevice() = 0;

    /**
     @brief 打开通道
     @param[IN]
     @param[OUT]
     @return
     */
    virtual void openChl() = 0;

    /**
     @brief 关闭通道
     @param[IN]
     @param[OUT]
     @return
     */
    virtual void closeChl() = 0;

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
#endif
