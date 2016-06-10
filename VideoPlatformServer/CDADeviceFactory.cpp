#include <iostream>
#include "publicDef.h"
#include "CDADeviceInterface.h"
#include "CDADeviceFactory.h"

/*-------------------第三方头文件---------------------------*/
#include "CDAHikDevice.h"
#include "CDAUniviewDevice.h"
#include "CDADahuaDevice.h"

/**
 @brief 获取设备类对象
 @param[IN] IN void *paramIn
 @return 
*/
CDADeviceInterface* CDADeviceFactory::getDevice(IN void *paramIn)
{
    PSTDEVICEINFO pstDeviceInfo = (PSTDEVICEINFO)paramIn;
    CDADeviceInterface *pDevice;
    switch(pstDeviceInfo->enDeviceFirm)
    {
        case HIK:
        {
            pDevice = new CDAHikDevice;
        }
        case UNIVIEW:
        {
            pDevice = new CDAUnivewDevice;
        }
        case DAHUA:
        {
            pDevice = new CDADahuaDevice;
        }
        default:
        {
            pDevice = NULL;
        }
    }

    return pDevice;
}