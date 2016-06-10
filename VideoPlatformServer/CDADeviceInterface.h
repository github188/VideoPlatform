#ifndef __CDADEVICEINTERFACE_H__
#define __CDADEVICEINTERFACE_H__
#include "publicDef.h"

class CDADeviceInterface
{
public:
    /**
     @brief ���豸
     @param[IN] void *paramIn
     @return 
     */
    virtual int openDevice(void *paramIn) = 0;

    /**
     @brief �ر��豸
     @param[IN] void *paramIn
     @return
     */
    virtual int closeDevice(void *paramIn) = 0;

    /**
     @brief ��ȡ�豸��Ϣ
     @param[IN] void *paramIn, void *paramOut
     */
    virtual int getDeviceInfo(void *paramIn, void *paramOut) = 0;

    /**
     @brief ��ʼ��SDK
     @param[IN] 
     @param[OUT]
     @return
     */
    virtual int initSDK() = 0;

    /**
     @brief ����ʼ��SDK
     @param[IN]
     @param[OUT]
     @return
     */
    virtual int uninitSDK() = 0;

    /**
     @brief ��ȡ�豸����
     @return std::string
     */
    virtual std::string getDeviceName() = 0;

    /**
     @brief ��ȡ�豸IP
     @return std::string
     */
    virtual std::string getDeviceIP() = 0;

    /**
     @brief ��ȡ�豸�˿�
     @return int
    */
    virtual int getDevicePort() = 0;

    /**
     @brief ��ȡ�豸ͨ����
     @return int
    */
    virtual int getDeviceChlNum() = 0;

    /**
     @brief ��ȡ�豸����
     @return ENUMDEVICETYPE
     */
    virtual ENUMDEVICETYPE getDeviceType() = 0;

protected:
private:
    std::string strDeviceName;   //�豸����
    std::string strDeviceIP;     //�豸IP
    int nDeviceID;          //�豸ID(IDΨһ)
    int nDevicePort;        //�豸�˿�
    int nDeviceChlNum;      //�豸ͨ������IPCֻ��һ��ͨ��
    ENUMDEVICETYPE enDeviceType;   //�豸����
};

class CChannelInterface
{
public:
    /**
     @brief ��ͨ��
     @param[IN] void *paramIn
     @param[OUT] void *paramOut
     @return 
      - �ɹ� true
      - ʧ�� false
     */
    virtual bool openChl(void *paramIn, void *paramOut) = 0;

    /**
     @brief �ر�ͨ��
     @param[IN] void *paramIn
     @param[OUT] void *paramOut
     @return 
      - �ɹ� true
      - ʧ�� false
     */
    virtual bool closeChl(void *paramIn, void *paramOut) = 0;

    /**
     @brief ����ͨ��
     @param[IN] void *paramIn
     @return 
     - �ɹ� true
     - ʧ�� false
     */
    virtual bool setChl(void *paramIn) = 0;

    /**
     @brief ��ȡͨ����Ϣ
     @param[IN] void *paramIn
     @param[OUT] void *paramOut
     @return 
     - �ɹ� true
     - ʧ�� false
     */
    virtual bool getChlInfo(void *paramIn, void *paramOut) = 0;

protected:
private:
};

class CAlarmInterface
{
public:
    /**
     @brief ���ĸ澯
     @param[IN] void *paramIn
     @return 
     - �ɹ� true
     - ʧ�� false
     */
    virtual bool subscribeAlarm(void *paramIn) = 0;

    /**
     @brief ȡ������
     @param[IN] void *paramIn
     @return 
     - �ɹ� true
     -ʧ�� false
    */
    virtual bool unSubscribeAlarm(void *paramIn) = 0;

     /**
     @brief ���ø澯�ص�����
     @return 
     - �ɹ� true
     -ʧ�� false
    */
    virtual bool setAlarmCallBack(void) = 0;

protected:
private:
};
#endif
