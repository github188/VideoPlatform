#ifndef __CDAHikCHANNEL_H__
#define __CDAHikCHANNEL_H__

class CDAHikChannel:public CChannelInterface
{
public:
    /**
     @brief 打开通道
     @param[IN] void *paramIn
     @param[OUT] void *paramOut
     @return 
      - 成功 true
      - 失败 false
     */
    bool openChl(void *paramIn, void *paramOut);

    /**
     @brief 关闭通道
     @param[IN] void *paramIn
     @param[OUT] void *paramOut
     @return 
      - 成功 true
      - 失败 false
     */
    bool closeChl(void *paramIn, void *paramOut);

    /**
     @brief 设置通道
     @param[IN] void *paramIn
     @return 
     - 成功 true
     - 失败 false
     */
    bool setChl(void *paramIn);

    /**
     @brief 获取通道信息
     @param[IN] void *paramIn
     @param[OUT] void *paramOut
     @return 
     - 成功 true
     - 失败 false
     */
    bool getChlInfo(void *paramIn, void *paramOut);

protected:
private:

};
#endif