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
    bool openChl(void *paramIn, void *paramOut);

    /**
     @brief �ر�ͨ��
     @param[IN] void *paramIn
     @param[OUT] void *paramOut
     @return 
      - �ɹ� true
      - ʧ�� false
     */
    bool closeChl(void *paramIn, void *paramOut);

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

protected:
private:

};
#endif