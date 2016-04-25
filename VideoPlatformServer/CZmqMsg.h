#ifndef __CZMQMSG_H__
#define __CZMQMSG_H__

/* ��Ϣͨ���� */
class CZmqMsg
{
public:
    /**
     *@brief ���캯��
     *@param[IN] std::string &strIP
     *@param[IN] int nPort
    */
    CZmqMsg(std::string &strIp, int nPort);
    
    /**
     *@brief ��������
    */
    ~CZmqMsg();

    /**
     *@brief �����ͻ��˽ӿ�
     *@param[IN] 
    */


    /**
     *@brief �����첽��Ϣ����
     *@param[IN] void *paramIn
     *@return 
     * - �ɹ���true
     * - ʧ�ܣ�false
     **/
    bool zmqAsySendMsg(void *paramIn);

    /**
     *@brief ������Ϣ
     *@return 
     * - �ɹ���true
     * - ʧ�ܣ�false
     */
    bool zmqRecvMsg();

protected:
private:
    /* Ŀ��IP */
    std::string m_strIP;
    /* Ŀ�Ķ˿� */
    int m_nPort;

    /* socket��� */
    void *m_pSock;
    void *m_pCtx;
};

#endif 