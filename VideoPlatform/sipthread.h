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
     * 停止通信模块线程
     */
    void stop();
protected:
    /**
     * 线程运行函数
     */
    void run();

    /**
     * 初始化通信模块
     */
    void InitSip(); /* 初始化通信消息模块 */

private:
    CDASip *m_sip;

    volatile bool stopped;
};
#endif