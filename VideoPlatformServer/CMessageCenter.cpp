#include <map>
#include <iostream>
//#include <string>
#include "publicDef.h"
#include "CMessageCenter.h"
#include "CDADeviceInterface.h"
#include "CDADeviceFactory.h"

/* ����ע�ᵽ���������豸 */
std::map<int, CDADeviceInterface *> mapDeviceInfo;

/**
 @brief ��ʼʵʱԤ���ܽӿ�
 @param[IN] void *paramIn
 @return 
 - �ɹ� true
 - ʧ�� false
 */
int startRealData(void *paramIn)
{
    DEVICEINFO *pstDevInfo = (DEVICEINFO*)paramIn;
    std::map<int, CDADeviceInterface*>::iterator iterDevInfo;
    void *paramOut;
    int ret = true;

    /* �жϸ��豸�Ƿ���� */
    iterDevInfo = mapDeviceInfo.find(pstDevInfo->nDeviceID);
    if(mapDeviceInfo.end() != iterDevInfo)
    {
        /* ���������и��豸��ִ�д�ʵ������*/
        ret = iterDevInfo->second->getChannelObject(paramIn)->openChl(paramIn, paramOut);
        if(true != ret)
        {

        }
        else
        {

        }
    }
    else
    {
        /* �����ڸ��豸 */
        return false;
    }

    return true;
}
/**
 @brief ����ʵʱԤ���ܽӿ�
 @param[IN] void *paramIn
 @return 
 - �ɹ� true
 - ʧ�� false
 */
int closeRealData(void *paramIn)
{
    DEVICEINFO *pstDevInfo = (DEVICEINFO*)paramIn;
    std::map<int, CDADeviceInterface*>::iterator iterDevInfo;
    void *paramOut;
    int ret = true;

    /* �жϸ��豸�Ƿ���� */
    iterDevInfo = mapDeviceInfo.find(pstDevInfo->nDeviceID);
    if(mapDeviceInfo.end() != iterDevInfo)
    {
        /* ���������и��豸��ִ�д�ʵ������*/
        ret = iterDevInfo->second->getChannelObject(paramIn)->openChl(paramIn, paramOut);
        if(true != ret)
        {

        }
        else
        {

        }
    }
    else
    {
        /* �����ڸ��豸 */
        return false;
    }

    return true;
}

/**
 @brief �澯�ܽӿ�
 @param[IN] void *paramIn
 @return 
 - �ɹ� true
 - ʧ�� false
 */
int dealAlarmfunc(void *paramIn)
{
    return true;
}

/**
 @brief ��ʼ�ط��ܽӿ�
 @param[IN] void *paramIn
 @return 
 - �ɹ� true
 - ʧ�� false
 */
int startPlayBack(void *paramIn)
{

    return true;
}

/**
 @brief ��ʼ�ط��ܽӿ�
 @param[IN] void *paramIn
 @return 
 - �ɹ� true
 - ʧ�� false
 */
int closePlayBack(void *paramIn)
{

    return true;
}

/**
 @brief ���豸�ӿ�
 @param[IN] void *paramIn
 @return 
 - �ɹ� true
 - ʧ�� false
 */
int openDevicefunc(void *paramIn)
{
    DEVICEINFO *pstDevInfo = (DEVICEINFO*)paramIn;
    std::map<int, CDADeviceInterface*>::iterator iterDevInfo;

    /* �жϸ��豸�Ƿ���� */
    iterDevInfo = mapDeviceInfo.find(pstDevInfo->nDeviceID);
    if(mapDeviceInfo.end() != iterDevInfo)
    {
        /* ���������Ѿ��и��豸��Ϣ�ˣ����سɹ�*/
        return true;
    }
    else
    {
        /* �½��ö����ŵ�MAP�� */
        CDADeviceInterface *pDevice = CDADeviceFactory::getDevice(paramIn);
        if(NULL == pDevice)
        {
            return false;
        }
        else
        {
            /* ���豸 */
            pDevice->openDevice(pstDevInfo);

            /* ���ö��󱣴浽map�� */
            mapDeviceInfo[pstDevInfo->nDeviceID] = pDevice;
        }
    }

    return true;
}

/**
 @brief �ر��豸
 @param[IN] void *paramIn
 @return 
 - �ɹ� true
 - ʧ�� false
 */
int closeDevicefunc(void *paramIn)
{
    DEVICEINFO *pstDevInfo = (DEVICEINFO*)paramIn;
    std::map<int, CDADeviceInterface*>::iterator iterDevInfo;

    /* �жϸ��豸�Ƿ���� */
    iterDevInfo = mapDeviceInfo.find(pstDevInfo->nDeviceID);
    if(mapDeviceInfo.end() != iterDevInfo)
    {
        /* ������û�и��豸��Ϣ*/
        return true;
    }
    else
    {
        /* ���ýӿڹر��豸 */
        iterDevInfo->second->closeDevice(paramIn);

        /* ���豸��Ϣɾ�� */
        mapDeviceInfo.erase(iterDevInfo);
    }
    return true;
}

/**
 @brief ���캯��
 */
CMessageCenter::CMessageCenter()
{

}

/**
 @brief ��������
 */
CMessageCenter::~CMessageCenter()
{

}

/**
 @brief ��Ϣ��������
 @param[IN] void *paramMesgDataIn
 @param[IN] enMessageType enMesgType
 @return 
 - �ɹ� true
 - ʧ�� false
 */
int CMessageCenter::messageCenter(void *paramMesgDataIn, enMessageType enMesgType)
{
    int ret = true;
    int ret1 = true;

    if(paramMesgDataIn == NULL)
    {
        return false;
    }

    /* �ж�����һ�����͵���Ϣ */
    switch(enMesgType)
    {
        case InvitePriview : 
            {
                ret = startRealData(paramMesgDataIn);
                if(ret != true)
                {
                    ret1 = false;
                }
                else
                {
                    ret1 = true;
                }
                break;
            }
        case ClosePriview : 
            {
                ret = closeRealData(paramMesgDataIn);
                if(ret != true)
                {
                    ret1 = false;
                }
                else
                {
                    ret1 = true;
                }
                break;
            }
        case ReceiveAlarm :
            {
                ret = dealAlarmfunc(paramMesgDataIn);
                if(ret != true)
                {
                    ret1 = false;
                }
                else
                {
                    ret1 = true;
                }

                break;
            }
        case InvitePlayBack :
            {
                ret = startPlayBack(paramMesgDataIn);
                if(ret != true)
                {
                    ret1 = false;
                }
                else
                {
                    ret1 = true;
                }
                break;
            }
        case SearchVideo : break;
        case OpenDevice:
            {
                ret = openDevicefunc(paramMesgDataIn);
                if(ret != true)
                {
                    ret1 = false;
                }
                else
                {
                    ret1 = true;
                }
                break;
            }
        case CloseDevice:
            {
                ret = closeDevicefunc(paramMesgDataIn);
                if(ret != true)
                {
                    ret1 = false;
                }
                else
                {
                    ret1 = true;
                }
                break;
            }
        default:break;
    }

    return true;
}