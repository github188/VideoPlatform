

class CDAHikDevice : public CDADeviceInterface
{
public:
    /**
     @brief ���캯��
     */
    CDAHikDevice();

    /**
     @brief ��������
     */
    ~CDAHikDevice();

    /**
     @brief ���豸
     @param[IN]
     @return 
     */
    void openDevice();

    /**
     @brief �ر��豸
     @param[IN]
     @return
     */
    void closeDevice();

    /**
     @brief ��ͨ��
     @param[IN]
     @param[OUT]
     @return
     */
    void openChl();

    /**
     @brief �ر�ͨ��
     @param[IN]
     @param[OUT]
     @return
     */
    void closeChl();

    /**
     @brief ��ʼ��SDK
     @param[IN] 
     @param[OUT]
     @return
     */
    void initSDK();

    /**
     @brief ����ʼ��SDK
     @param[IN]
     @param[OUT]
     @return
     */
    void uninitSDK();

protected:
private:
};
