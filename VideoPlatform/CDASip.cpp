#include "CDASip.h"
#include <QDebug>

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
    while(1)
    {
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
            case EXOSIP_MESSAGE_NEW: break;
            case EXOSIP_CALL_INVITE: break;
            case EXOSIP_CALL_CLOSED: break;
            case EXOSIP_CALL_MESSAGE_NEW: break;
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
            case EXOSIP_CALL_INVITE:break;
            case EXOSIP_CALL_PROCEEDING:break;
            case EXOSIP_CALL_RINGING:break;
            case EXOSIP_CALL_ANSWERED:
            {
                qDebug("---answered---");
                eXosip_call_build_ack(m_sip_event_je->did, &m_sip_message_ack);
                eXosip_call_send_ack(m_sip_event_je->did, m_sip_message_ack);
                break;
            }
            case EXOSIP_CALL_CLOSED:break;
            case EXOSIP_CALL_ACK:break;
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