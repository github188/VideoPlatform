#ifndef __CDASIP_H__
#define __CDASIP_H__
#include <WinSock2.h>
#include <eXosip2/eXosip.h>
#include <iostream>

class CDASip
{
public:
    CDASip();
    ~CDASip();

    /**
     * 初始化第三方sip库 （exosip.lib）
     */
    int sip_init(void);

    /**
     * 启动接收客户端发送的消息
     */
    void sip_server_run(void);

    /**
     @brief 启动接收服务器端发送的消息
     */
    bool sip_client_receivemsg(void);

    /**
     * @param[IN] transport 传输类型
     * @param[IN] char *addr 地址
     * @param[IN] port 端口
     * @param[IN] family (the IP family (AF_INET or AF_INET6))
     * @param[IN] secure (0 for UDP or TCP, 1 for TLS(with TCP))
     */
    int sip_listen_addr(int transport, const char *addr, int port, int family, int secure);

    /**
     * @param[IN] subject Subject for the call
     */
    int sip_call_build_initial_invite(const char *subject);

    /**
     * Set the Body of the SIP message.
     * @param buf The buffer containing the body.
     * @param length The length of the buffer.
     */
    int sip_message_set_body(const char *buf, size_t length);

    /**
     * Set the Content-type header.
     * @param hvalue The string describing the element.
     */
    int sip_message_set_content_type(const char *hvalue);

    /**
     * Initiate a call.
     */
    int sip_call_send_initial_invite ();

    /**
      * 停止监听
      */
    void sip_quit(void);

protected:
private:
    eXosip_event_t *m_sip_event_je;
    osip_message_t *m_sip_message_ack;
    osip_message_t *m_sip_message_invite;
    osip_message_t *m_sip_message_answer;
    sdp_message_t *m_remote_sdp;

    char *m_pIdentity;
    char *m_pRegistar;
    char *m_pSource_call;
    char *m_pDest_call;
};

#endif