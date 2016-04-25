#ifndef __SERVER_H__
#define __SERVER_H__

class server
{
public:
    server(const server&) = delete;
    server& operator=(const server&) = delete;

    server(std::string &strIPAddress, std::string &strPort);

    void run();
protected:

private:
    std::string m_strIPAddress;
    std::string m_strPort;
};
#endif