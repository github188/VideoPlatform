#include "CDADeviceInterface.h"
#include "CDADahuaChannel.h"

/**
 @brief ��ͨ��
 @param[IN] void *paramIn
 @param[OUT] void *paramOut
 @return 
 - �ɹ� true
 - ʧ�� false
 */
bool CDADahuaChannel::openChl(void *paramIn/*, void *paramLoginHandle*/)
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
bool CDADahuaChannel::closeChl(void *paramIn/*, void *paramOut*/)
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
bool CDADahuaChannel::setChl(void *paramIn)
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
bool CDADahuaChannel::getChlInfo(void *paramIn, void *paramOut)
{
    return true;
}