#ifndef __CMMODULE_H__
#define __CMMODULE_H__
#include <iostream>

typedef struct
{
    std::string strDeviceName;
    std::string strDecoderTag;
    int iDeviceID;
    int iChlNum;
}REALDATAPARAM;

class CCmModule
{
public:
    /**
     @brief CMģ��Ĺ��캯��
     */
    CCmModule();

    /**
     @brief CMģ����������
     */
    ~CCmModule();

    /**
     @brief ����ʵʱԤ��
     @param[IN] REALDATAPARAM *stRealDataParamIn
     @return 
     - �ɹ� TRUE
     - ʧ�� ERRORCODE
     */
    int requestRealData(REALDATAPARAM *stRealDataParamIn);

protected:
private:

};
#endif