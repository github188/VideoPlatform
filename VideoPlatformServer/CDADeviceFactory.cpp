#include <iostream>
#include "publicDef.h"
#include "CDADeviceInterface.h"
#include "CDADeviceFactory.h"

/**
 @brief ��ȡ�豸�����
 @param[IN] IN DEVICEINFO& stDeviceInfoIn
 @return 
*/
CDADeviceInterface* CDADeviceFactory::getDevice(IN DEVICEINFO& stDeviceInfo)
{
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

    return 1;
}