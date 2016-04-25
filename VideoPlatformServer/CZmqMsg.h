#ifndef __CZMQMSG_H__
#define __CZMQMSG_H__

/* 消息通信类 */
class CZmqMsg
{
public:
    /**
     *@brief 构造函数
     *@param[IN] std::string &strIP
     *@param[IN] int nPort
    */
    CZmqMsg(std::string &strIp, int nPort);
    
    /**
     *@brief 析构函数
    */
    ~CZmqMsg();

    /**
     *@brief 创建客户端接口
     *@param[IN] 
    */


    /**
     *@brief 发送异步消息函数
     *@param[IN] void *paramIn
     *@return 
     * - 成功：true
     * - 失败：false
     **/
    bool zmqAsySendMsg(void *paramIn);

    /**
     *@brief 接收消息
     *@return 
     * - 成功：true
     * - 失败：false
     */
    bool zmqRecvMsg();

protected:
private:
    /* 目的IP */
    std::string m_strIP;
    /* 目的端口 */
    int m_nPort;

    /* socket句柄 */
    void *m_pSock;
    void *m_pCtx;
};

#endif 