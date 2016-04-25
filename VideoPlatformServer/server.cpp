#include <iostream>
#include "server.h"

using namespace std;

server::server(std::string &strIPAddress, std::string &strPort)
{
    m_strPort = strPort;
    m_strIPAddress = strIPAddress;
}

void server::run()
{
    while(1)
    {
    
    }

    return ;
}