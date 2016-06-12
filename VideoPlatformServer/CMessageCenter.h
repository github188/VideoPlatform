#ifndef __CMESSAGECENTER_H__
#define __CMESSAGECENTER_H__
#include "publicDef.h"

class CMessageCenter
{
public:
    /**
     @brief 构造函数
     */
    CMessageCenter();

    /**
     @brief 析构函数
     */
    ~CMessageCenter();

    /**
     @brief 消息处理中心
     @param[IN] void *paramMesgDataIn
     @param[IN] SIPMSGTYPE enMesgType
     @return 
     - 成功 true
     - 失败 false
     */
    int messageCenter(void *paramMesgDataIn, SIPMSGTYPE enMesgType);

protected:
private:
};

#endif