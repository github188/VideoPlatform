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

/**
 @brief ���ĸ澯
 @param[IN] void *paramIn
 @return 
 - �ɹ� true
 - ʧ�� false
*/
bool CDAUniviewAlarm::subscribeAlarm(void *paramIn)
{
    return true;
}

/**
 @brief ȡ������
 @param[IN] void *paramIn
 @return 
 - �ɹ� true
 -ʧ�� false
 */
bool CDAUniviewAlarm::unSubscribeAlarm(void *paramIn)
{
    return true;
}

/**
 @brief ���ø澯�ص�����
 @return 
 - �ɹ� true
 -ʧ�� false
 */
bool CDAUniviewAlarm::setAlarmCallBack(void)
{
    return true;
}