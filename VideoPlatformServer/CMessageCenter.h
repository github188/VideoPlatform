#ifndef __CMESSAGECENTER_H__
#define __CMESSAGECENTER_H__

class CMessageCenter
{
public:
    /**
     @brief ���캯��
     */
    CMessageCenter();

    /**
     @brief ��������
     */
    ~CMessageCenter();

    /**
     @brief ��Ϣ��������
     @param[IN] void *paramMesgDataIn
     @param[IN] enMessageType enMesgType
     @return 
     - �ɹ� true
     - ʧ�� false
     */
    int messageCenter(void *paramMesgDataIn, enMessageType enMesgType);

protected:
private:
};

#endif