#ifndef __CDADEVICEMANGER_H__
#define __CDADEVICEMANGER_H__

class CDADeviceMangerSingleton
{
public:
    /**
     *@brief 析构函数
     */
    ~CDADeviceMangerSingleton(){};

    /**
     @brief 获得单例实例指针
     @return static CDADeviceMangerSingleton &
     */
    static CDADeviceMangerSingleton & getInstance()
    {
        static CDADeviceMangerSingleton instance;
        return instance;
    }

    /**
     @brief 获得设备对象
     @param[IN] 
     @return
     */
    CDADeviceInterface* getDevice();

protected:

private:
    /**
     @breif 单例构造函数，需要是私有的
     */
    CDADeviceMangerSingleton(){};
    
    /**
     @breif 显示的创建拷贝构造函数
     @param[IN] const CDADeviceMangerSingleton &
     */
    CDADeviceMangerSingleton(const CDADeviceMangerSingleton &);

    /**
     @brief 显示的创建赋值构造函数
     */
    CDADeviceMangerSingleton &operator = (const CDADeviceMangerSingleton &);

private:
    CDADeviceFactory m_deviceFactory;
};

#endif