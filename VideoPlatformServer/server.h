#ifndef __SERVER_H__
#define __SERVER_H__

#include "CDASip.h"

class server
{
public:
    server(const server&);
    server& operator=(const server&);

    server(std::string &strIPAddress, std::string &strPort);

    void run();
protected:

private:
    std::string m_strIPAddress;
    std::string m_strPort;
    CDASip *m_sip;
};

#endif