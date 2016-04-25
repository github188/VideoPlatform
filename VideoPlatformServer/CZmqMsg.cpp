/* 系统头文件 */
#include <iostream>
#include "zmq.h"

/* 用户自定义头文件 */
#include "CZmqMsg.h"

/**
 *@brief:构造函数
 *@param[IN] std::string &strIP
 *@param[IN] int nPort
 */
CZmqMsg::CZmqMsg(std::string &strIP, int nPort)
{
    const char *pAddr = "tcp://*:7766";
    int nRecTimeOut = 5000;

    m_strIP = strIP;
    m_nPort = nPort;

    /* 创建context, zmq的socket需要在context上进行创建 */
    m_pCtx = zmq_ctx_new();
    if(NULL == m_pCtx)
    {
        return ;
    }

    /* 创建zmq_socket, socket目前有6种属性，这里使用dealer方式 */
    m_pSock = zmq_socket(m_pCtx, ZMQ_DEALER);
    if(NULL != m_pSock)
    {
        zmq_ctx_destroy(m_pCtx);
        return ;
    }

    /* 设置超时时间为5秒 */
    if(0 > zmq_setsockopt(m_pSock, ZMQ_RCVTIMEO, &nRecTimeOut, sizeof(nRecTimeOut)))
    {
        zmq_close(m_pSock);
        zmq_ctx_destroy(m_pCtx);
        return ;
    }

    /* 绑定地址 tcp://*:7766 */
    if(zmq_bind(m_pSock, pAddr) < 0)
    {
        zmq_close(m_pSock);
        zmq_ctx_destroy(m_pCtx);
        return ;
    }
}

/**
 *@brief 析构函数
 */
CZmqMsg::~CZmqMsg()
{
    zmq_close(m_pSock);
    zmq_ctx_destroy(m_pCtx);
}

/**
 *@brief 发送异步消息函数
 *@param[IN] void *paramIn
 *@return 
 * - 成功：true
 * - 失败：false
 **/
bool CZmqMsg::zmqAsySendMsg(void *paramIn)
{
    return true;
}

/**
 *@brief 接收消息
 *@return 
 * - 成功：true
 * - 失败：false
 */
bool CZmqMsg::zmqRecvMsg()
{
    return true;
}

