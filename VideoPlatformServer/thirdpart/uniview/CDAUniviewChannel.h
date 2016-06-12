#ifndef __CDAUNIVIEWCHANNEL_H__
#define __CDAUNIVIEWCHANNEL_H__

class CDAUniviewChannel:public CChannelInterface
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
    bool openChl(void *paramIn/*, void *paramLoginHandle*/);

    /**
     @brief �ر�ͨ��
     @param[IN] void *paramIn
     @param[OUT] void *paramOut
     @return 
      - �ɹ� true
      - ʧ�� false
     */
    bool closeChl(void *paramIn/*, void *paramOut*/);

    /**
     @brief ����ͨ��
     @param[IN] void *paramIn
     @return 
     - �ɹ� true
     - ʧ�� false
     */
    bool setChl(void *paramIn);

    /**
     @brief ��ȡͨ����Ϣ
     @param[IN] void *paramIn
     @param[OUT] void *paramOut
     @return 
     - �ɹ� true
     - ʧ�� false
     */
    bool getChlInfo(void *paramIn, void *paramOut);

public:
    void *m_lDevHandle;
protected:
private:
    /* ʵ����� */
    void *m_lplayHandle;

};

class CDAUniviewAlarm : public CAlarmInterface
{
public:
    /**
     @brief ���ĸ澯
     @param[IN] void *paramIn
     @return 
     - �ɹ� true
     - ʧ�� false
     */
    bool subscribeAlarm(void *paramIn);

    /**
     @brief ȡ������
     @param[IN] void *paramIn
     @return 
     - �ɹ� true
     -ʧ�� false
    */
    bool unSubscribeAlarm(void *paramIn);

     /**
     @brief ���ø澯�ص�����
     @return 
     - �ɹ� true
     -ʧ�� false
    */
    bool setAlarmCallBack(void);

protected:
private:
};
#endif