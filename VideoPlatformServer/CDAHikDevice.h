

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
     @param[IN]
     @return 
     */
    void openDevice();

    /**
     @brief 关闭设备
     @param[IN]
     @return
     */
    void closeDevice();

    /**
     @brief 打开通道
     @param[IN]
     @param[OUT]
     @return
     */
    void openChl();

    /**
     @brief 关闭通道
     @param[IN]
     @param[OUT]
     @return
     */
    void closeChl();

    /**
     @brief 初始化SDK
     @param[IN] 
     @param[OUT]
     @return
     */
    void initSDK();

    /**
     @brief 反初始化SDK
     @param[IN]
     @param[OUT]
     @return
     */
    void uninitSDK();

protected:
private:
};
