#ifndef __CDADEVICEMANGER_H__
#define __CDADEVICEMANGER_H__

class CDADeviceMangerSingleton
{
public:
    /**
     *@brief ��������
     */
    ~CDADeviceMangerSingleton(){};

    /**
     @brief ��õ���ʵ��ָ��
     @return static CDADeviceMangerSingleton &
     */
    static CDADeviceMangerSingleton & getInstance()
    {
        static CDADeviceMangerSingleton instance;
        return instance;
    }

    /**
     @brief ����豸����
     @param[IN] 
     @return
     */
    CDADeviceInterface* getDevice();

protected:

private:
    /**
     @breif �������캯������Ҫ��˽�е�
     */
    CDADeviceMangerSingleton(){};
    
    /**
     @breif ��ʾ�Ĵ����������캯��
     @param[IN] const CDADeviceMangerSingleton &
     */
    CDADeviceMangerSingleton(const CDADeviceMangerSingleton &);

    /**
     @brief ��ʾ�Ĵ�����ֵ���캯��
     */
    CDADeviceMangerSingleton &operator = (const CDADeviceMangerSingleton &);

private:
    CDADeviceFactory m_deviceFactory;
};

#endif