#ifndef __CMESSAGECENTER_H__
#define __CMESSAGECENTER_H__
#include "publicDef.h"

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
     @param[IN] SIPMSGTYPE enMesgType
     @return 
     - �ɹ� true
     - ʧ�� false
     */
    int messageCenter(void *paramMesgDataIn, SIPMSGTYPE enMesgType);

protected:
private:
};

#endif