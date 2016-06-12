#include <list>
#include <iostream>
#include "CDASip.h"
#include "publicDef.h"
using namespace std;

CDASip::CDASip()
{
    sip_init();
}

CDASip::~CDASip()
{

}

/**
 * 初始化第三方sip库 （exosip.lib）
 */
int CDASip::sip_init()
{
    int ret = eXosip_init();
    if(0 != ret)
    {
        return -1;
    }

    m_pIdentity = "sip:140@127.0.0.1";
    m_pRegistar = "sip:133@127.0.0.1:15061";
    m_pSource_call = "sip:140@127.0.0.1";
    m_pDest_call = "sip:133@127.0.0.1:15061";

    return 1;
}

/**
 * 启动接收客户端发送的消息
*/
void CDASip::sip_server_run()
{
    int call_id;
    int dialog_id;
    char tmp[4096];
    int pos = 0;
    int ret = true;
    INVITEINFO stInviteInfo;

    while(1)
    {
        pos = 0;
        /* 监听是否有消息到来 */
        m_sip_event_je = eXosip_event_wait(0, 50);
        eXosip_lock();
        eXosip_default_action(m_sip_event_je);
        eXosip_automatic_refresh();
        eXosip_unlock();

        if(NULL == m_sip_event_je)
        {
            continue;
        }

        /* 有消息到来 */
        switch(m_sip_event_je->type)
        {
            case EXOSIP_MESSAGE_NEW: 
            {
                std::cout << "new message" << std::endl;
                if(MSG_IS_MESSAGE(m_sip_event_je->request))
                {
                    cout << "注册到服务器的设备信息：" << endl;
                    int i = 0;
                    DEVICEINFO stDeviceInfo;
                    osip_body_t *stbody;
                    list<string> listResult;
                    osip_message_get_body(m_sip_event_je->request, 0, &stbody);
                    listResult = sip_string_split(stbody->body, "$");

                    list<string>::iterator iter;
                    for(iter = listResult.begin(), i = 0; iter != listResult.end(); iter++, i++)
                    {
                        cout << iter->data() << endl;
                        switch(i)
                        {
                            case 0:stDeviceInfo.strDeviceName = iter->data();break;
                            case 1:stDeviceInfo.strDeviceIP = iter->data();break;
                            case 2:stDeviceInfo.nDeviceID = atoi(iter->data());break;
                            case 3:stDeviceInfo.nDevicePort = atoi(iter->data());break;
                            case 4:stDeviceInfo.nDeviceChlNum = atoi(iter->data());break;
                            case 5:stDeviceInfo.strDeviceLoginName = iter->data();break;
                            case 6:stDeviceInfo.strDeviceLoginPwd = iter->data();break;
                            case 7:stDeviceInfo.enDeviceType = (ENUMDEVICETYPE)atoi(iter->data());break;
                            case 8:stDeviceInfo.enDeviceFirm = (ENDEVICEFIRM)atoi(iter->data());break;
                            default:break;
                        }
                    }

                    /* 将消息发送给消息转发中心*/
                    ret = m_messageCenter.messageCenter(&stDeviceInfo,OpenDevice);
                    if(true != ret)
                    {
                        eXosip_lock();
                        /* 发送请求失败消息 */
                        eXosip_message_build_answer (m_sip_event_je->tid, 400,&m_sip_message_answer);
                        eXosip_call_send_answer(m_sip_event_je->tid, 400, m_sip_message_answer);
                        eXosip_unlock();
                    }
                    else
                    {
                        /* 发送请求成功消息 */
                        eXosip_lock();
                        eXosip_message_build_answer (m_sip_event_je->tid, 200,&m_sip_message_answer);
                        eXosip_call_send_answer(m_sip_event_je->tid, 200, m_sip_message_answer);
                        eXosip_unlock();
                    }
                }
                break;
            }
            case EXOSIP_CALL_INVITE: 
            {
                std::cout << "receive invite!" << std::endl;
                /* 得到消息 */
                m_remote_sdp = eXosip_get_remote_sdp(m_sip_event_je->did);
                call_id = m_sip_event_je->cid;
                dialog_id = m_sip_event_je->did;

                std::cout << "the Info is : " << std::endl;
                while(!osip_list_eol(&(m_remote_sdp->a_attributes), pos))
                {
                    sdp_attribute_t *at;
                    at = (sdp_attribute_t *)osip_list_get(&m_remote_sdp->a_attributes, pos);
                    std::cout << at->a_att_field << "  " << at->a_att_value << std::endl;

                    /* 构建消息参数 */
                    if(!strcmp("DeviceName", at->a_att_field))
                    {
                        stInviteInfo.strDeviceName = at->a_att_value;
                    }
                    else if(!strcmp("ParentID", at->a_att_field))
                    {
                        stInviteInfo.nDeviceID = atoi(at->a_att_value);
                    }
                    else if(!strcmp("ChannelNum", at->a_att_field))
                    {
                        stInviteInfo.nChannelNum = atoi(at->a_att_value);
                    }
                    pos++;
                }

                std::cout << std::endl;

                ret = m_messageCenter.messageCenter(&stInviteInfo,InvitePriview);
                eXosip_lock();
                if(ret == true)
                {
                    _snprintf(tmp, 4096,
                        "v=0\r\n"
                        "o=anonymous 0 0 IN IP4 0.0.0.0\r\n"
                        "t=1 10\r\n"
                        "a=invite:rainfish\r\n"
                        "a=result:success\r\n");
                    cout << "play success!" << endl;
                }
                else
                {
                    _snprintf(tmp, 4096,
                    "v=0\r\n"
                        "o=anonymous 0 0 IN IP4 0.0.0.0\r\n"
                        "t=1 10\r\n"
                        "a=invite:rainfish\r\n"
                        "a=result:failed\r\n");
                    cout << "paly success!" << endl;
                }
                ret = true;
                if(true != ret)
                {
                    /* 发送请求失败消息 */
                    eXosip_call_send_answer(m_sip_event_je->tid, 400, m_sip_message_answer);
                    eXosip_unlock();
                }
                else
                {
                    /* 发送请求成功消息 */
                    eXosip_call_build_answer (m_sip_event_je->tid, 200,&m_sip_message_answer);

                    osip_message_set_body(m_sip_message_answer, tmp, strlen(tmp));
                    osip_message_set_content_type(m_sip_message_answer, "application/sdp");

                    eXosip_call_send_answer(m_sip_event_je->tid, 200, m_sip_message_answer);
                    eXosip_unlock();
                }
                break;
            }
            case EXOSIP_CALL_ACK:
            {
                //std::cout << "receive ack" << std::endl;
            }
            case EXOSIP_CALL_CLOSED: break;
                std::cout << "call_closed" << std::endl;break;
            case EXOSIP_CALL_MESSAGE_NEW: 
                std::cout << "call_message_new" << std::endl;break;
            default:
            {

            }
        }
    }
}

/**
 * 启动监听服务器端的消息
 */
void CDASip::sip_client_receivemsg()
{
    while(1)
    {
        m_sip_event_je = eXosip_event_wait(0, 200);
        if(m_sip_event_je == NULL)
        {
            /* 没有回复或者超时 */
            break;
        }

        switch(m_sip_event_je->type)
        {
            case EXOSIP_CALL_INVITE:
            case EXOSIP_CALL_PROCEEDING:
            case EXOSIP_CALL_RINGING:
            case EXOSIP_CALL_ANSWERED:
            case EXOSIP_CALL_CLOSED:
            case EXOSIP_CALL_ACK:
            default:
            {
                break;
            }
        }
    }
    return;
}

/**
 * @param[IN] int transport 传输类型
 * @param[IN] const char *addr 地址
 * @param[IN] int port 端口
 * @param[IN] int family (the IP family (AF_INET or AF_INET6))
 * @param[IN] int secure (0 for UDP or TCP, 1 for TLS(with TCP))
 */
int CDASip::sip_listen_addr(int transport, const char *addr, int port, int family, int secure)
{
    int ret = eXosip_listen_addr(transport, NULL, port, family, secure);
    if(0 != ret)
    {
        sip_quit();
        return -1;
    }

    return 1;
}

/**
 * 停止监听
 */
void CDASip::sip_quit()
{
    eXosip_quit();

    return;
}

/**
 * @param[IN] subject Subject for the call
 */
int CDASip::sip_call_build_initial_invite(const char *subject)
{
    int ret = eXosip_call_build_initial_invite(&m_sip_message_invite, m_pDest_call, m_pSource_call, NULL, subject);
    if(0 != ret)
    {
        return 0;
    }

    return 1;
}

/**
 * Set the Body of the SIP message.
 * @param buf The buffer containing the body.
 * @param length The length of the buffer.
 */
int CDASip::sip_message_set_body(const char *buf, size_t length)
{
    osip_message_set_body(m_sip_message_invite, buf, length);

    return 1;
}

/**
 * Set the Content-type header.
 * @param hvalue The string describing the element.
 */
int CDASip::sip_message_set_content_type(const char *hvalue)
{
    osip_message_set_content_type(m_sip_message_invite, hvalue);

    return 1;
}

/**
 * Initiate a call.
 */
int CDASip::sip_call_send_initial_invite ()
{
    eXosip_lock();
    /* invite SIP INVITE message to send */
    eXosip_call_send_initial_invite(m_sip_message_invite);
    eXosip_unlock();

    return 1;
}

/**
 @brief 实现类似于split的函数功能
 */
list<string> CDASip::sip_string_split(string str, string separator)
{
    list<string> result;
    int cutAt;
    while((cutAt = str.find_first_of(separator)) != str.npos)
    {
        /* 有可能存在string str = "a,b,c",求split(str, ",")的情况，所以每次要判断cutAt是否为零*/
        if(cutAt > 0)
        {
            result.push_back(str.substr(0, cutAt));
        }
        str = str.substr(cutAt + 1);
    }
    if(str.length() > 0)
    {
        result.push_back(str);
    }

    return result;
}
