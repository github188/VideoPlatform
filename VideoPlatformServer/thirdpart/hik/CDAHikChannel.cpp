#include "CDADeviceInterface.h"
#include "CDAHikChannel.h"

/**
 @brief ��ͨ��
 @param[IN] void *paramIn
 @param[OUT] void *paramOut
 @return 
 - �ɹ� true
 - ʧ�� false
 */
bool CDAHikChannel::openChl(void *paramIn, void *paramOut)
{
    return true;
}

/**
 @brief �ر�ͨ��
 @param[IN] void *paramIn
 @param[OUT] void *paramOut
 @return 
 - �ɹ� true
 - ʧ�� false
 */
bool CDAHikChannel::closeChl(void *paramIn, void *paramOut)
{
    return true;
}

/**
 @brief ����ͨ��
 @param[IN] void *paramIn
 @return 
 - �ɹ� true
 - ʧ�� false
 */
bool CDAHikChannel::setChl(void *paramIn)
{
    return true;
}

/**
 @brief ��ȡͨ����Ϣ
 @param[IN] void *paramIn
 @param[OUT] void *paramOut
 @return 
 - �ɹ� true
 - ʧ�� false
 */
bool CDAHikChannel::getChlInfo(void *paramIn, void *paramOut)
{
    return true;
}