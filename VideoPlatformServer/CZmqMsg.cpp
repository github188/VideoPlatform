/* ϵͳͷ�ļ� */
#include <iostream>
#include "zmq.h"

/* �û��Զ���ͷ�ļ� */
#include "CZmqMsg.h"

/**
 *@brief:���캯��
 *@param[IN] std::string &strIP
 *@param[IN] int nPort
 */
CZmqMsg::CZmqMsg(std::string &strIP, int nPort)
{
    const char *pAddr = "tcp://*:7766";
    int nRecTimeOut = 5000;

    m_strIP = strIP;
    m_nPort = nPort;

    /* ����context, zmq��socket��Ҫ��context�Ͻ��д��� */
    m_pCtx = zmq_ctx_new();
    if(NULL == m_pCtx)
    {
        return ;
    }

    /* ����zmq_socket, socketĿǰ��6�����ԣ�����ʹ��dealer��ʽ */
    m_pSock = zmq_socket(m_pCtx, ZMQ_DEALER);
    if(NULL != m_pSock)
    {
        zmq_ctx_destroy(m_pCtx);
        return ;
    }

    /* ���ó�ʱʱ��Ϊ5�� */
    if(0 > zmq_setsockopt(m_pSock, ZMQ_RCVTIMEO, &nRecTimeOut, sizeof(nRecTimeOut)))
    {
        zmq_close(m_pSock);
        zmq_ctx_destroy(m_pCtx);
        return ;
    }

    /* �󶨵�ַ tcp://*:7766 */
    if(zmq_bind(m_pSock, pAddr) < 0)
    {
        zmq_close(m_pSock);
        zmq_ctx_destroy(m_pCtx);
        return ;
    }
}

/**
 *@brief ��������
 */
CZmqMsg::~CZmqMsg()
{
    zmq_close(m_pSock);
    zmq_ctx_destroy(m_pCtx);
}

/**
 *@brief �����첽��Ϣ����
 *@param[IN] void *paramIn
 *@return 
 * - �ɹ���true
 * - ʧ�ܣ�false
 **/
bool CZmqMsg::zmqAsySendMsg(void *paramIn)
{
    return true;
}

/**
 *@brief ������Ϣ
 *@return 
 * - �ɹ���true
 * - ʧ�ܣ�false
 */
bool CZmqMsg::zmqRecvMsg()
{
    return true;
}

