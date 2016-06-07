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
     * ��ʼ��������sip�� ��exosip.lib��
     */
    int sip_init(void);

    /**
     * �������տͻ��˷��͵���Ϣ
     */
    void sip_server_run(void);

    /**
     @brief �������շ������˷��͵���Ϣ
     */
    bool sip_client_receivemsg(void);

    /**
     * @param[IN] transport ��������
     * @param[IN] char *addr ��ַ
     * @param[IN] port �˿�
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
      * ֹͣ����
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