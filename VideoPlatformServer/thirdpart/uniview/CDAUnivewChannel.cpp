#include "CDADeviceInterface.h"
#include "CDAUniviewChannel.h"

/**
 @brief ��ͨ��
 @param[IN] void *paramIn
 @param[OUT] void *paramOut
 @return 
 - �ɹ� true
 - ʧ�� false
 */
bool CDAUniviewChannel::openChl(void *paramIn, void *paramOut)
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
bool CDAUniviewChannel::closeChl(void *paramIn, void *paramOut)
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
bool CDAUniviewChannel::setChl(void *paramIn)
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
bool CDAUniviewChannel::getChlInfo(void *paramIn, void *paramOut)
{
    return true;
}