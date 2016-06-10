#ifndef __CDAHIKDEVICE_H__
#define __CDAHIKDEVICE_H__

class CDAHikDevice : public CDADeviceInterface
{
public:
    /**
     @brief ���캯��
     */
    CDAHikDevice();

    /**
     @brief ��������
     */
    ~CDAHikDevice();

    /**
     @brief ���豸
     @param[IN] void *paramIn
     @return 
     */
     int openDevice(void *paramIn);

    /**
     @brief �ر��豸
     @param[IN] void *paramIn
     @return
     */
    int closeDevice(void *paramIn);

    /**
     @brief ��ȡ�豸��Ϣ
     @param[IN] void *paramIn, void *paramOut
     */
    int getDeviceInfo(void *paramIn, void *paramOut);

    /**
     @brief ��ʼ��SDK
     @param[IN] 
     @param[OUT]
     @return
     */
    int initSDK();

    /**
     @brief ����ʼ��SDK
     @param[IN]
     @param[OUT]
     @return
     */
    int uninitSDK();

    /**
     @brief ��ȡ�豸����
     @return std::string
     */
    std::string getDeviceName();

    /**
     @brief ��ȡ�豸IP
     @return std::string
     */
    std::string getDeviceIP();

    /**
     @brief ��ȡ�豸�˿�
     @return int
    */
    int getDevicePort();

    /**
     @brief ��ȡ�豸ͨ����
     @return int
    */
    int getDeviceChlNum();

    /**
     @brief ��ȡ�豸����
     @return ENUMDEVICETYPE
     */
    ENUMDEVICETYPE getDeviceType();

    /**
     @brief ��ȡͨ������
     @param[IN] void *paramIn
     @return CChannelInterface*
     */
    CChannelInterface* getChannelObject(void *paramIN);


protected:
private:
};

#endif
