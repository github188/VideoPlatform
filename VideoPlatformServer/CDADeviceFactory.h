#ifndef __CDADEVICEFACTORY_H__
#define __CDADEVICEFACTORY_H__

class CDADeviceFactory
{
public:
    /**
     @brief ������Ĺ��캯��
     */
    CDADeviceFactory();

    /**
     @brief ���������������
     */
    ~CDADeviceFactory();

    /**
     @brief ��ȡ�豸�����
     @param[IN] IN DEVICEINFO& stDeviceInfoIn
     @return 
    */
    CDADeviceInterface* getDevice(IN DEVICEINFO& stDeviceInfo);

protected:
private:

};
#endif