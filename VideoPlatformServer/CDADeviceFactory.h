#ifndef __CDADEVICEFACTORY_H__
#define __CDADEVICEFACTORY_H__

class CDADeviceFactory
{
public:
    /**
     @brief 工厂类的构造函数
     */
    CDADeviceFactory();

    /**
     @brief 工厂类的析构函数
     */
    ~CDADeviceFactory();

    /**
     @brief 获取设备类对象
     @param[IN] IN DEVICEINFO& stDeviceInfoIn
     @return 
    */
    CDADeviceInterface* getDevice(IN DEVICEINFO& stDeviceInfo);

protected:
private:

};
#endif