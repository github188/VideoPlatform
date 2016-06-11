#include <iostream>
#include "publicDef.h"
#include "CDADeviceInterface.h"
#include "CDADeviceFactory.h"

/*-------------------������ͷ�ļ�---------------------------*/
#include "CDAHikDevice.h"
#include "CDAUniviewDevice.h"
#include "CDADahuaDevice.h"

/**
 @brief ��ȡ�豸�����
 @param[IN] IN void *paramIn
 @return 
*/
CDADeviceInterface* CDADeviceFactory::getDevice(IN void *paramIn)
{
    DEVICEINFO *pstDeviceInfo = (DEVICEINFO*)paramIn;
    CDADeviceInterface *pDevice;
    switch(pstDeviceInfo->enDeviceFirm)
    {
        case HIK:
        {
            pDevice = new CDAHikDevice;
            break;
        }
        case UNIVIEW:
        {
            pDevice = new CDAUnivewDevice;
            break;
        }
        case DAHUA:
        {
            pDevice = new CDADahuaDevice;
            break;
        }
        default:
        {
            pDevice = NULL;
        }
    }

    return pDevice;
}