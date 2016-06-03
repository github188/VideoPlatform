#ifndef __MYAPP_H__
#define __MYAPP_H__

class myApp
{
public:
    static char AppPath[30];     //Ӧ�ó���·��
    static int DeskWidth;       //������ÿ��
    static int DeskHeight;      //������ø߶�

    static char AppTitle[20];    //�������
    static char NVRType[20];     //Ӳ��¼�������
    static char IPCType[20];    //�������������
    static char AppStyle[20];
    static int VideoDelayTime;      //��Ƶ������Ӧ��ʱʱ��
    static bool UseVideoOffLineCheck;       //��Ƶ���߼��
    static int VideoOffLineCheckInterval;   //��Ƶ���߼����
    static int RtspType;            //��������
    static bool AutoRun;            //�����Զ�����
    static bool AutoPoll;           //�Զ���ѵ
    static int PollType;            //��ѵ������
    static int PollInterval;        //��ѵ���
    static int PollSleep;           //��ѵ��ʱ
    static char RtspAddr4[20];       //4��ͨ����Ӧrtsp��ַ
    static char VideoType[20];       //��ǰ����չʾ����
    static char LastConfig[20];      //������������Ϣ

    static void ReadConfig();       //��ȡ�����ļ�
    static void WriteConfig();      //д�������ļ�

protected:
private:
};

#endif