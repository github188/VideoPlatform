#include <iostream>
#include "server.h"

using namespace std;

server::server(std::string &strIPAddress, std::string &strPort)
{
    m_strPort = strPort;
    m_strIPAddress = strIPAddress;
    m_sip = new CDASip;

    m_sip->sip_init();
    m_sip->sip_listen_addr(IPPROTO_UDP, NULL, 15061, AF_INET, 0);
}

void server::run()
{
    /* 启动接收客户端消息 */
    m_sip->sip_server_run();

    return ;
}