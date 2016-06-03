#ifndef __CDADEVICEINTERFACE_H__
#define __CDADEVICEINTERFACE_H__

class CDADeviceInterface
{
public:
    /**
     @brief ���캯��
     */
//    CDADeviceInterface();

    /**
     @brief ��������
     */
//    ~CDADeviceInterface();

    /**
     @brief ���豸
     @param[IN]
     @return 
     */
    virtual void openDevice() = 0;

    /**
     @brief �ر��豸
     @param[IN]
     @return
     */
    virtual void closeDevice() = 0;

    /**
     @brief ��ͨ��
     @param[IN]
     @param[OUT]
     @return
     */
    virtual void openChl() = 0;

    /**
     @brief �ر�ͨ��
     @param[IN]
     @param[OUT]
     @return
     */
    virtual void closeChl() = 0;

    /**
     @brief ��ʼ��SDK
     @param[IN] 
     @param[OUT]
     @return
     */
    virtual void initSDK() = 0;

    /**
     @brief ����ʼ��SDK
     @param[IN]
     @param[OUT]
     @return
     */
    virtual void uninitSDK() = 0;

protected:
private:

};
#endif
