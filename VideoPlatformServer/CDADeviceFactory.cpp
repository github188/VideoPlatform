#include <iostream>
#include "publicDef.h"
#include "CDADeviceInterface.h"
#include "CDADeviceFactory.h"
#include "CDAHikDevice.h"

/**
 @brief ��ȡ�豸�����
 @param[IN] IN DEVICEINFO& stDeviceInfoIn
 @return 
*/
CDADeviceInterface* CDADeviceFactory::getDevice(IN DEVICEINFO& stDeviceInfo)
{
    CDAHikDevice *member = new CDAHikDevice;
    switch(stDeviceInfo.enDeviceType)
    {
        case IPC:
        {

        }
        case NVR:
        {

        }
        case DVR:
        {

        }
        case PLAT:
        {

        }
        default:
        {
            
        }

    }

    return member;
}