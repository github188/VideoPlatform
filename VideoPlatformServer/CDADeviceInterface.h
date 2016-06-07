#ifndef __CDADEVICEINTERFACE_H__
#define __CDADEVICEINTERFACE_H__
#include "publicDef.h"

class CDADeviceInterface
{
public:
    /**
     @brief ���豸
     @param[IN] DEVICEINFO *paramIn
     @return 
     */
    virtual void openDevice(DEVICEINFO *paramIn) = 0;

    /**
     @brief �ر��豸
     @param[IN] DEVICEINFO *paramIn
     @return
     */
    virtual void closeDevice(DEVICEINFO *paramIn) = 0;

    /**
     @brief ��ȡ�豸��Ϣ
     @param[IN] DEVICEINFO *paramIn, void *paramOut
     */
    virtual bool getDeviceInfo(DEVICEINFO *paramIn, void *paramOut) = 0;

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
