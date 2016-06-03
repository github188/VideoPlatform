#ifndef __SIPTHREAD_H__
#define __SIPTHREAD_H__

#include <QThread>
#include "CDASip.h"

class CSipThread : public QThread
{
    Q_OBJECT
public:
    CSipThread();
    ~CSipThread();
    /**
     * ֹͣͨ��ģ���߳�
     */
    void stop();
protected:
    /**
     * �߳����к���
     */
    void run();

    /**
     * ��ʼ��ͨ��ģ��
     */
    void InitSip(); /* ��ʼ��ͨ����Ϣģ�� */

private:
    CDASip *m_sip;

    volatile bool stopped;
};
#endif