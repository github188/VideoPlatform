#ifndef __CMESSAGECENTER_H__
#define __CMESSAGECENTER_H__

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
     @param[IN] enMessageType enMesgType
     @return 
     - 成功 true
     - 失败 false
     */
    int messageCenter(void *paramMesgDataIn, enMessageType enMesgType);

protected:
private:
};

#endif