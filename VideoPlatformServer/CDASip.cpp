#include "CDASip.h"

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
                std::cout << "new message" << std::endl;break;
            case EXOSIP_CALL_INVITE: 
            {
                std::cout << "receive invite!" << std::endl;
                /* 得到消息 */
                m_remote_sdp = eXosip_get_remote_sdp(m_sip_event_je->did);
                call_id = m_sip_event_je->cid;
                dialog_id = m_sip_event_je->did;

                eXosip_lock();
                //eXosip_call_send_answer(m_sip_event_je->tid, 180, NULL);
                int ret = eXosip_call_build_answer(m_sip_event_je->tid, 200, &m_sip_message_answer);
                if (0 != ret)
                {
                    eXosip_call_send_answer(m_sip_event_je->tid, 400, NULL);
                }
                else
                {
                    _snprintf(tmp, 4096,
                        "v=0\r\n"
                        "o=anonymous 0 0 IN IP4 0.0.0.0\r\n"
                        "t=1 10\r\n"
                        "a=username:rainfish\r\n"
                        "a=password:123\r\n");
                    osip_message_set_body(m_sip_message_answer, tmp, strlen(tmp));
                    osip_message_set_content_type(m_sip_message_answer, "application/sdp");

                    eXosip_call_send_answer(m_sip_event_je->tid, 200, m_sip_message_answer);
                }
                eXosip_unlock();

                std::cout << "the Info is : " << std::endl;
                while(!osip_list_eol(&(m_remote_sdp->a_attributes), pos))
                {
                    sdp_attribute_t *at;
                    at = (sdp_attribute_t *)osip_list_get(&m_remote_sdp->a_attributes, pos);
                    std::cout << at->a_att_field << "  " << at->a_att_value << std::endl;
                    pos++;
                }
                break;
            }
            case EXOSIP_CALL_ACK:
            {
                std::cout << "receive ack" << std::endl;
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