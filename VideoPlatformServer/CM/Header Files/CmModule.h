#ifndef __CMMODULE_H__
#define __CMMODULE_H__

typedef struct
{
    string strDeviceName;
    string strDecoderTag;
    int iDeviceID;
    int iChlNum;
}REALDATAPARAM;

class CCmModule
{
public:
    /**
     @brief CM模块的构造函数
     */
    CCmModule();

    /**
     @brief CM模块析构函数
     */
    ~CCmModule();

    /**
     @brief 请求实时预览
     @param[IN] REALDATAPARAM *stRealDataParamIn
     @return 
     - 成功 TRUE
     - 失败 ERRORCODE
     */
    int requestRealData(REALDATAPARAM *stRealDataParamIn);

protected:
private:

};
#endif