#ifndef _NETDEV_H_
#define _NETDEV_H_

#ifdef  __cplusplus
extern "C"{
#endif

#ifndef STATIC
    #define STATIC                  static
#endif

#ifndef CONST
    #define CONST                   const
#endif

#ifndef EXTERN
    #define EXTERN                  extern
#endif

#ifndef INLINE
    #define INLINE                  __inline
#endif

#ifndef UNION
    #define UNION                   union
#endif

#ifndef IN
    #define IN
#endif

#ifndef OUT
    #define OUT
#endif

#ifndef INOUT
    #define INOUT
#endif

#ifndef NEWINTERFACE
    #define NEWINTERFACE
#endif

#if defined(WIN32)  /* windows */
#if defined(NETDEV_SDK_DLL)
#define NETDEV_API                  __declspec(dllexport)
#else
#define NETDEV_API                  __declspec(dllimport)
#endif
#else
#define NETDEV_API
#endif

/* ������׼����Լ�� Standard function calling convention */
#ifdef i386
    #ifndef STDCALL
        #define STDCALL                 __attribute__((stdcall))
    #endif
#else
    #ifndef WIN32
    #ifndef STDCALL
        #define STDCALL
    #endif
#else
    #ifndef STDCALL
        #define STDCALL                 __stdcall
    #endif
#endif

#endif

#ifndef UCHAR_DEF
#define UCHAR_DEF
    typedef unsigned char           UCHAR;
#endif

#ifndef CHAR_DEF
#define CHAR_DEF
    typedef char                    CHAR;
#endif

#ifndef BYTE_DEF
#define BYTE_DEF
    typedef unsigned char           BYTE;
#endif

#ifndef UINT16_DEF
#define UINT16_DEF
    typedef unsigned short          UINT16;
#endif

#ifndef UINT_DEF
#define UINT_DEF
    typedef unsigned int            UINT32;
#endif

#ifndef INT16_DEF
#define INT16_DEF
    typedef  short                  INT16;
#endif

#ifndef INT32_DEF
#define INT32_DEF
    typedef  int                    INT32;
#endif

#ifndef LPVOID_DEF
#define LPVOID_DEF
    typedef void*                   LPVOID;
#endif

#ifndef VOID
#ifndef VOID_DEF
#define VOID_DEF
    typedef void                    VOID;
#endif
#endif

#ifndef INT64_DEF
#define INT64_DEF
    typedef long long               INT64;
#endif

#ifndef BOOL_DEF
#define BOOL_DEF
    typedef int                     BOOL;
#endif

#ifndef FLOAT
#ifndef VOID_FLOAT
#define VOID_FLOAT
    typedef float                   FLOAT;
#endif
#endif

#ifndef FALSE
    #define FALSE                   0
#endif

#ifndef TRUE
    #define TRUE                    1
#endif

#ifndef WIN32
    typedef LPVOID                 HWND;
#endif

/********************************** ������ֵ��  Commonly used numerical macros *************** */

/* ��ID��ʶ����  Length of stream ID*/
#define NETDEV_STREAM_ID_LEN                    32

/* �ļ�������  Length of filename */
#define NETDEV_FILE_NAME_LEN                    (256u)

/* �û�����󳤶�  Maximum length of username */
#define NETDEV_USER_NAME_LEN                    32

/* ������󳤶�  Maximum length of password */
#define NETDEV_PASSWD_LEN                       64

/* �û���¼����,���Ŀ�����ܺ��ַ�������  Length of password and encrypted passcode for user login */
#define NETDEV_PASSWD_ENCRYPT_LEN               64

/* ��Դ������Ϣ�ַ�������  Length of resource code string */
#define NETDEV_RES_CODE_LEN                     48

/* ������󳤶�  Maximum length of domain name */
#define NETDEV_DOMAIN_LEN                       64

/* �豸������󳤶�  Maximum length of device name */
#define NETDEV_DEVICE_NAME_LEN                  32

/* ·����󳤶�  Maximum length of path */
#define NETDEV_PATH_LEN_WITHOUT_NAME            64

/* ·����󳤶�:�����ļ�����  Maximum length of path, including filename */
#define NETDEV_PATH_LEN                         128

/* Email��ַ��󳤶�  Maximum length of email address */
#define NETDEV_EMAIL_NAME_ADDR                  32

/* Mac��ַ����  Length of MAC address */
#define NETDEV_MAC_ADDR_LEN                     6

/* gsoap����endpoint����  Length of endpoint called by gSOAP */
#define NETDEV_ENDPOINT_LEN                     96

/* ����ID��󳤶�  Maximum length of session ID */
#define NETDEV_SESSION_ID_LEN                   16

/* URL ����󳤶�  Maximum length of URL */
#define NDE_MAX_URL_LEN                         260

/* ͨ�ó���  Common length */
#define NETDEV_LEN_4                            4
#define NETDEV_LEN_8                            8
#define NETDEV_LEN_16                           16
#define NETDEV_LEN_32                           32
#define NETDEV_LEN_64                           64
#define NETDEV_LEN_128                          128
#define NETDEV_LEN_132                          132
#define NETDEV_LEN_260                          260

/* IP ��ַ��Ϣ�ַ�������  Length of IP address string */
#define NETDEV_IPADDR_STR_MAX_LEN              (64u)

/* ͨ�������ַ�������  Length of common name string */
#define NETDEV_NAME_MAX_LEN                    (20u)

/* ͨ��CODE ����  Length of common code */
#define NETDEV_CODE_STR_MAX_LEN                (48u)

/* ��������ַ����� Maximum length of date string "2008-10-02 09:25:33.001 GMT" */
#define NETDEV_MAX_DATE_STRING_LEN             (64u)

/* ʱ����Ϣ�ַ������� Length of time string "hh:mm:ss" */
#define NETDEV_SIMPLE_TIME_LEN                 (12u)

/* ������Ϣ�ַ������� Length of date string "YYYY-MM-DD"*/
#define NETDEV_SIMPLE_DATE_LEN                 (12u)

/* �澯�����������  Maximum number of alarm inputs */
#define NETDEV_MAX_ALARM_IN_NUM                 64

/* �澯����������  Maximum number of alarm outputs */
#define NETDEV_MAX_ALARM_OUT_NUM                64

/* һ���еļƻ�ʱ���  Number of scheduled time sections in a day */
#define NETDEV_PLAN_SECTION_NUM                 8

/* һ���ܹ������õļƻ�����,������һ�����պͼ���  Total number of plans allowed in a week, including Monday to Sunday, and holidays */
#define NETDEV_PLAN_NUM_AWEEK                   8

/* ���������ƶ�����������  Maximum number of motion detection areas allowed */
#define NETDEV_MAX_MOTION_DETECT_AREA_NUM       4

/* ���������ڸ��������  Maximum number of privacy mask areas allowed */
#define NETDEV_MAX_PRIVACY_MASK_AREA_NUM        8

/* ���������ڵ��������  Maximum number of tamper-proof areas allowed */
#define NETDEV_MAX_TAMPER_PROOF_AREA_NUM        1

/* ͨ���ַ���������  Maximum number of text overlays allowed for a channel */
#define NETDEV_MAX_TEXTOVERLAY_NUM              6

/* ��Ƶͨ�����������  Maximum number of video streams */
#define NETDEV_MAX_VIDEO_STREAM_NUM             8

/* ����/ÿ��  Month of the year */
#define NETDEV_MONTH_OF_YEAR                    12

/* ����/ÿ��  Day of the month */
#define NETDEV_DAYS_OF_MONTH                    32

/* �豸ID����  Length of device ID */
#define NETDEV_DEV_ID_LEN                       64

/* �豸���кų���  Length of device serial number */
#define NETDEV_SERIAL_NUMBER_LEN                32

/* ��������ѯ����  Maximum number of queries allowed at a time */
#define NETDEV_MAX_QUERY_NUM                    200

/* �ܹ�����ѯ����  Total number of queries allowed */
#define NETDEV_MAX_QUERY_TOTAL_NUM              2000

/* IPC������  Maximum number of IP cameras */
#define NETDEV_MAX_IPC_NUM                      128

/* Ԥ��λ�����  Maximum number of presets */
#define NETDEV_MAX_PRESET_NUM                   256

/* Ѳ��·����Ԥ��λ��������  Maximum number of presets for preset patrol */
#define NETDEV_MAX_CRUISEPOINT_NUM              32

/* Ԥ��λѲ��·���������  Maximum number of routes for preset patrol */
#define NETDEV_MAX_CRUISEROUTE_NUM              16

/* ��̨�ƶ��ٶ�  PTZ rotating speed */
#define NETDEV_MIN_PTZ_SPEED_LEVEL              1
#define NETDEV_MAX_PTZ_SPEED_LEVEL              9

/* ͼ����������� �Աȶ� ɫ�� ���Ͷȣ����/Сֵ  Maximum / Minimum values for image parameters (brightness, contrast, hue, saturation) */
#define NETDEV_MAX_VIDEO_EFFECT_VALUE           255
#define NETDEV_MIN_VIDEO_EFFECT_VALUE           0

/* ͼ�������٤��ֵ�����ֵ Minimum values for image parameters (Gama) */
#define NETDEV_MAX_VIDEO_EFFECT_GAMMA_VALUE     10

/* ���ӳ�ʱʱ�����ֵ  Maximum connection timeout */
#define NETDEV_MAX_CONNECT_TIME_VALUE           75000

/* ���ӳ�ʱʱ����Сֵ  Minimum connection timeout */
#define NETDEV_MIN_CONNECT_TIME_VALUE           300

/* ����û���  Maximum number of users */
#define NETDEV_MAX_USER_NUM                     (256 + 32)

/* ���ʵʱԤ����·��  Maximum number of channels allowed for live preview */
#define NETDEV_MAX_REALPLAY_NUM                 128

/* ���طŻ����ص�·��  Maximum number of channels allowed for playback or download */
#define NETDEV_MAX_PALYBACK_NUM                 128

/* ���������ͨ����·��  Maximum number of alarm channels */
#define NETDEV_MAX_ALARMCHAN_NUM                128

/* ���Ӳ�̸�ʽ����·��  Maximum number of channels allowed for formatting hard disk */
#define NETDEV_MAX_FORMAT_NUM                   128

/* ����ļ�������·��  Maximum number of channels allowed for file search */
#define NETDEV_MAX_FILE_SEARCH_NUM              2000

/* �����־������·��  Maximum number of channels allowed for log search */
#define NETDEV_MAX_LOG_SEARCH_NUM               2000

/* �����͸��ͨ����·��  Maximum number of channels allowed for creating transparent channels */
#define NETDEV_MAX_SERIAL_NUM                   2000

/* ���������·��  Maximum number of channels allowed for upgrade */
#define NETDEV_MAX_UPGRADE_NUM                  256

/* �������ת����·��  Maximum number of channels allowed for audio forwarding */
#define NETDEV_MAX_VOICE_COM_NUM                256

/* ��������㲥��·��  Maximum number of channels allowed for audio broadcast */
#define NETDEV_MAX_VOICE_BROADCAST_NUM          256

/* ��ʱʱ�����ֵ,��λ����  Maximum timeout, unit: ms */
#define NETDEV_MAX_CONNECT_TIME                 75000

/* ��ʱʱ����Сֵ,��λ����  Minimum timeout, unit: ms */
#define NETDEV_MIN_CONNECT_TIME                 300

/* ��ʱʱ��Ĭ��ֵ,��λ����  Default timeout, unit: ms */
#define NETDEV_DEFAULT_CONNECT_TIME             3000

/* ���ӳ��Դ���  Number of connection attempts */
#define NETDEV_CONNECT_TRY_TIMES                1

/* �û�����ʧ�ܴ���  User keep-alive interval */
#define NETDEV_KEEPLIVE_TRY_TIMES               3

/* ͨ�� OSD �ַ���������  Number of OSD text overlays */
#define NETDEV_OSD_TEXTOVERLAY_NUM              6

/* ͨ�� OSD �ַ�����  Length of OSD texts */
#define NETDEV_OSD_TEXT_MAX_LEN                 (64u)

/* ���澯���澯����  Maximum number of alarms a user can get */
#define NETDEV_PULL_ALARM_MAX_NUM               8

/* ֧�ֵĹ켣Ѳ�����������  Maximum number of patrol routes allowed  */
#define NETDEV_TRACK_CRUISE_MAXNUM               1

/* ����������Сֵ  Minimum volume */
#define NETDEV_AUDIO_SOUND_MIN_VALUE            0

/* �����������ֵ  Maximum volume */
#define NETDEV_AUDIO_SOUND_MAX_VALUE            255

/* ��˷�����������Сֵ  Minimum volume */
#define NETDEV_MIC_SOUND_MIN_VALUE              0

/* ��˷������������ֵ  Maximum volume */
#define NETDEV_MIC_SOUND_MAX_VALUE              255

/* ��Ļ��Ϣ����  Screen Info Row */
#define NETDEV_SCREEN_INFO_ROW                  18

/* ��Ļ��Ϣ����  Screen Info Column */
#define NETDEV_SCREEN_INFO_COLUMN               22

/* BEGIN**************************** ������ Error codes ************************************************************/
#define NETDEV_E_SUCCEED                        0           /* �ɹ�  Succeeded*/
#define NETDEV_E_FAILED                         -1          /* ʧ��  Failed*/

/* ͨ�ô�����  Common error codes */
#define NETDEV_E_COMMON_FAILED                  1           /* ͨ�ô���  Common error */
#define NETDEV_E_DEV_COMMON_FAILED              2           /* ���豸���ص�ͨ�ô���  Common error returned by device */
#define NETDEV_E_SYSCALL_FALIED                 3           /* ϵͳ��������ʧ��,��鿴errno  Failed to call system function. See errno */
#define NETDEV_E_NULL_POINT                     4           /* ��ָ��  Null pointer */
#define NETDEV_E_INVALID_PARAM                  5           /* ��Ч����  Invalid parameter */
#define NETDEV_E_INVALID_MODULEID               6           /* ��Чģ��ID  Invalid module ID */
#define NETDEV_E_NO_MEMORY                      7           /* �ڴ����ʧ��  Failed to allocate memory */
#define NETDEV_E_NOT_SUPPORT                    8           /* �豸��֧��  Not supported by device */
#define NETDEV_E_SDK_SOCKET_LSN_FAIL            9           /* ����socket listenʧ��  Failed to create socket listen */
#define NETDEV_E_INIT_MUTEX_FAIL                10          /* ��ʼ����ʧ��  Failed to initialize lock */
#define NETDEV_E_INIT_SEMA_FAIL                 11          /* ��ʼ���ź���ʧ��  Failed to initialize semaphore */
#define NETDEV_E_ALLOC_RESOURCE_ERROR           12          /* SDK��Դ�������  Error occurred during SDK resource allocation */
#define NETDEV_E_SDK_NOINTE_ERROR               13          /* SDKδ��ʼ��  SDK not initialized */
#define NETDEV_E_ALREDY_INIT_ERROR              14          /* SDK�Ѿ���ʼ����  SDK already initialized */
#define NETDEV_E_HAVEDATA                       15          /* ��������   Data not all sent */
#define NETDEV_E_NEEDMOREDATA                   16          /* ��Ҫ��������  More data required  */
#define NETDEV_E_CONNECT_ERROR                  17          /* ��������ʧ��  Failed to create connection */
#define NETDEV_E_SEND_MSG_ERROR                 18          /* ����������Ϣʧ��  Failed to send request message */
#define NETDEV_E_TIMEOUT                        19          /* ��Ϣ��ʱ  Message timeout */
#define NETDEV_E_DECODE_RSP_ERROR               20          /* ������Ӧ��Ϣʧ��  Failed to decode response message */
#define NETDEV_E_SOCKET_RECV_ERROR              21          /* Socket������Ϣʧ��  Socket failed to receive message */
#define NETDEV_E_NUM_MAX_ERROR                  22          /* �����ﵽ��󡣷����ע����������Ԥ������������SDK֧�ֵ������  Maximum number reached. The assigned numbers of registration connections and preview connections reached the maximum supported by SDK */
#define NETDEV_E_GET_PORT_ERROR                 24          /* ��ȡ���ض˿ں�ʧ��  Failed to obtain local port number */
#define NETDEV_E_CREATE_THREAD_FAIL             25          /* �����߳�ʧ��  Failed to create thread */
#define NETDEV_E_NOENOUGH_BUF                   26          /* ������̫С: �����豸���ݵĻ�����  Buffer is too small for receiving device data */
#define NETDEV_E_GETLOCALIPANDMACFAIL           27          /* ��ñ���PC��IP��ַ�������ַʧ��  Failed to obtain the IP or MAC address of the local PC */
#define NETDEV_E_RESCODE_NO_EXIST               28          /* ��Դ���벻����  Resource code not exist */
#define NETDEV_E_MSG_DATA_INVALID               31          /* ��Ϣ���ݴ���  Incorrect message content */
#define NETDEV_E_GET_CAPABILITY_ERROR           32          /* ��ȡ������ʧ��  Failed to obtain capabilities */
#define NETDEV_E_USER_NOT_BIND                  33          /* ���û�û�ж��ĸ澯   User not subscribed to alarms */
#define NETDEV_E_AUTHORIZATIONFAIL              34          /* �û���Ȩʧ��  User authentication failed */
#define NETDEV_E_BINDNOTIFY_FAIL                35          /* �󶨸澯ʧ��  Failed to bind alarms*/
#define NETDEV_E_NOTADMIN                       36          /* ����Ȩ�޲���,windows��һ��Ϊ�ǹ���Ա�ʺŲ������� Not enough permission. In Windows, it is normally because the operator is not an administrator. */
#define NETDEV_E_DEVICE_FACTURER_ERR            37          /* ��֧�ֵ��豸���� Manufacturers that are not supported */
#define NETDEV_E_NONSUPPORT                     38          /* �ù��ܲ�֧��  Function not supported */
#define NETDEV_E_TRANSFILE_FAIL                 39          /* �ļ�����ʧ��  File transmission failed */
#define NETDEV_E_JSON_ERROR                     40          /* Json ͨ�ô���  Json common error */
#define NETDEV_E_NO_RESULT                      41          /* ���޽��   No result */

/* �û���ش�����  User-related error codes */
#define NETDEV_E_USER_WRONG_PASSWD              101         /* �û��������  Incorrect password */
#define NETDEV_E_USER_LOGIN_MAX_NUM             102         /* �û���¼���Ѵ�����  Number of login users reached the upper limit */
#define NETDEV_E_USER_NOT_ONLINE                103         /* �û�������  User not online */
#define NETDEV_E_USER_NO_SUCH_USER              104         /* û�и��û�  User not online */
#define NETDEV_E_USER_NO_AUTH                   105         /* �û���Ȩ��  User has no rights */
#define NETDEV_E_USER_MAX_NUM                   106         /* �û�����-�����ٱ����  Reached the upper limit�Cno more users can be added */
#define NETDEV_E_USER_EXIST                     107         /* �û��Ѵ���  User already exists */
#define NETDEV_E_USER_PASSWORD_CHANGE           108         /* �û������޸�  Password changed */
#define NETDEV_E_REMOTE_USER_WITH_WEAK_PASSWD   109         /* Զ���û����������  Remote user with weak password */

/* ҵ����ش�����  Service-related error codes */

/* �ط���ش�����  Playback-related error codes */
#define NETDEV_E_VOD_PLAY_END                   250         /* �طŽ���  Playback ended */
#define NETDEV_E_VOD_NO_CM                      251         /* �طſ��ƿ鲻����  Playback controlling module not exist */
#define NETDEV_E_VOD_OVER_ABILITY               252         /* �ط�������������  Beyond playback capability */
#define NETDEV_E_VOD_NO_RECORDING_CM            253         /* ¼���ļ����ƿ鲻����  Recording file controlling module not exist */
#define NETDEV_E_VOD_NO_RECORDING               254         /* ��¼������   No recording */
#define NETDEV_E_VOD_NO_REPLAYURL               255         /* �޷���ȡ�طŵ�url   Cannot get the URL for playback*/


/* ��̨��ش�����  PTZ-related error codes */
#define NETDEV_E_PTZ_SET_PRESET_FAILED              300         /* Ԥ��λ����ʧ��  Failed to set preset */
#define NETDEV_E_PTZ_QUERY_PRESET_FAILED            301         /* Ԥ��λ��ѯʧ��  Failed to query preset */
#define NETDEV_E_PTZ_QUERY_TRACK_FAILED             302         /* �켣��ѯʧ��  Failed to query route */
#define NETDEV_E_PTZ_START_RECORD_TRACK_FAILED      303         /* ��ʼ¼�ƹ켣ʧ��  Failed to start route recording */
#define NETDEV_E_PTZ_STOP_RECORD_TRACK_FAILED       304         /* ����¼�ƹ켣ʧ��  Failed to end route recording */
#define NETDEV_E_PTZ_QUERY_CRUISE_FAILED            305         /* Ѳ����·��ѯʧ��  Failed to query patrol route */
#define NETDEV_E_PTZ_SET_CRUISE_FAILED              306         /* Ѳ����·����ʧ��  Failed to set patrol route */
#define NETDEV_E_PTZ_CTRL_FAILED                    307         /* ��̨����ʧ��  PTZ operation failed */
#define NETDEV_E_PTZ_PRESET_IN_CRUISE               308         /* Ԥ��λ��Ѳ����·��ʹ��, �޷�ɾ��  Preset is being used in patrol route and cannot be deleted */
#define NETDEV_E_PTZ_CRUISEPOINT_ERR                309         /* ����Ѳ���㲻����  Discontinuous presets */
#define NETDEV_E_PTZ_TRACK_ISUSED                   310         /* �켣��ʹ��,�޷�ɾ��  Route is in use and cannot be deleted */
#define NETDEV_E_PTZ_SERIALMODE_MISMATCH            311         /* ����ģʽ��ƥ��  Serial modes do not match */
#define NETDEV_E_PTZ_TRACK_NOT_EXIST                312         /* �켣������  Route does not exist */
#define NETDEV_E_PTZ_MODE_CRUISE_FULL               313         /* ģʽ·���켣���������  Route points are full */


/* SOAP��ش�����  SOAP-related error codes */
#define NETDEV_E_DEVICE_STREAM_FULL                 500         /* �豸������  Device stream full */
#define NETDEV_E_DEVICE_STREAM_CLOSED               501         /* �豸���ѹر�  Device stream closed */
#define NETDEV_E_DEVICE_STREAM_NONEXIST             502         /* �豸��������  Device stream does not exist */

#define NETDEV_E_COMMON_FAIL_STAT                   503         /* ��ȡ�ļ���Ŀ¼��״̬ʧ��  Failed to read file (directory) status */
#define NETDEV_E_COMMON_FILE_NONEXIST               504         /* �ļ�������  File does not exist */
#define NETDEV_E_COMMON_MKDIR_ERR                   505         /* ����Ŀ¼ʧ��  Failed to create directory */
#define NETDEV_E_SUBSCRIBE_FULL                     506         /* ���û���������, �豸���û����������Ĵ����벻�ܷ���  Subscription is full for current user */
#define NETDEV_E_UPGRADE_NOTADMIN                   507         /* ��admin�û��޷�����  Only admin can upgrade */
#define NETDEV_E_UPGRADE_INVALID                    508         /* ���� δ��ʼ  Upgrade not started */
#define NETDEV_E_UPGRADE_INPROCESS                  509         /* ���� ������  Upgrade in process */
#define NETDEV_E_UPGRADE_NOMEMORY                   510         /* ���� �ڴ�ռ䲻��  Insufficient memory for upgrade */
#define NETDEV_E_UPGRADE_FILE_OPEN_ERR              511         /* ���� �򿪾����ļ�����  Error occurred while opening the mirror file during upgrade */
#define NETDEV_E_UPGRADE_DEVICE_ERR                 512         /* ���� FLASH����  Error occurred while upgrading FLASH */
#define NETDEV_E_UPGRADE_BUSY                       513         /* ����ͬʱ���ض����������  Cannot load multiple upgrade processes at the same time */
#define NETDEV_E_UPGRADE_FAIL_TIMEOUT               514         /* ������ʱ  Upgrade timeout */
#define NETDEV_E_INVALID_CONFIGFILE                 515         /* �����ļ���Ч  Invalid configuration file */
#define NETDEV_E_STOR_RESOURCE_NOTINIT              516         /* �洢��Դδ����  Storage resource not allocated */

#define NETDEV_E_PLAYER_BASE_ERR                    1000        /* �������������  Basic decoding error code */
#define NETDEV_E_PLAYER_FAIL                        1001        /* ִ��ʧ��  Basic decoding error code */
#define NETDEV_E_PLAYER_INVALID_PARAM               1002        /* ��������Ƿ�  Invalid input parameter */
#define NETDEV_E_PLAYER_NO_MEMORY                   1003        /* ϵͳ�ڴ治��  Not enough system memory */
#define NETDEV_E_PLAYER_SOCKET_FAIL                 1004        /* ����SOCKETʧ��  Failed to create SOCKET */
#define NETDEV_E_PLAYER_RECV_FAIL                   1005        /* ����ʧ��  Failed to receive */
#define NETDEV_E_PLAYER_RECV_ZERO                   1006        /* ����Ϊ��  None received */
#define NETDEV_E_PLAYER_NOT_SUPPORT                 1007        /* �����ݲ�֧��  Currently not supported */
#define NETDEV_E_PLAYER_CREATETHREAD_FAILED         1008        /* �����߳�ʧ��  Failed to create the thread */
#define NETDEV_E_PLAYER_OPENDL_FAILED               1009        /* ���ض�̬��ʧ��  Failed to load the dynamic library */
#define NETDEV_E_PLAYER_SYMDL_FAILED                1010        /* ��ȡ��̬����ʧ��  Failed to get the dynamic library */
#define NETDEV_E_PLAYER_SEND_FAILED                 1011        /* ����ʧ��  Failed to send */
#define NETDEV_E_PLAYER_EACCES                      1012        /* �����ļ�Ȩ�޲���  No permission to create the file */
#define NETDEV_E_PLAYER_FILE_NOT_FIND               1013        /* ���ļ�δ�ҵ�  Failed to find the file to read */
#define NETDEV_E_PLAYER_LOG_CLOSE                   1014        /* ��־�ر�  Close log */

/*********************** Player ��Դ���********************************/
#define NETDEV_E_FAIL_TO_INIT_EZPLAYER              1257        /* ��ʼ��������ʧ��  Failed to initialize the player */
#define NETDEV_E_FAIL_TO_ALLOC_PORT_RES             1258        /* ���䲥��ͨ����Դʧ��  Failed to allocate playing channel resources */
#define NETDEV_E_FAIL_TO_GET_PORT_RES               1259        /* ��ò���ͨ����Դʧ��  Failed to get playing channel resources */
#define NETDEV_E_BUFFER_QUEUE_FULL                  1260        /* �����������  Cache queue full */
#define NETDEV_E_BUFFER_QUEUE_EMPTY                 1261        /* ������п�  Cache queue empty */
#define NETDEV_E_OPEN_FILE_FAILED                   1262        /* ���ļ�ʧ��  Failed to open the file */
#define NETDEV_E_FILE_READ_END                      1263        /* �ļ��Ѿ���ȡ���  The file is read */
#define NETDEV_E_FILE_DISKSPACE_FULL                1264        /* ���̿ռ���  Disk space full */
#define NETDEV_E_FILE_READ_FAIL                     1265        /* ��ȡʧ��  Failed to read */
#define NETDEV_E_MCM_MIC_NOT_EXIST                  1266        /* ��˷粻����  The microphone does not exist */
#define NETDEV_E_TS_PACKET_IN_THE_ROUGH             1267        /* TS���δ���  TS packing not finished */
#define NETDEV_E_FILE_RECORD_FINISH                 1268        /* ¼�񱣴����  Recording saved */

#define NETDEV_E_FAIL_TO_OPEN_STREAM                1513        /* ����ý��������ʧ��  Failed to start media streaming */
#define NETDEV_E_FAIL_TO_CLOSE_STREAM               1514        /* �ر�ý��������ʧ��  Failed to close media streaming */
#define NETDEV_E_FAIL_TO_RECV_DATA                  1515        /* ������ϵ��½�������ʧ��  Failed to receive data due to network error */
#define NETDEV_E_FAIL_TO_PROCESS_MEDIA_DATA         1516        /* ý�����ݴ���ʧ��  Failed to handle media data */
#define NETDEV_E_NOT_START_PLAY                     1517        /* ����ͨ��δ��ʼ���Ų���  Playing not started in playing channel */
#define NETDEV_E_FAIL_TO_INPUT_DATA                 1518        /* ����ý��������ʧ��  Failed to enter media stream data */
#define NETDEV_E_INPUTDATA_BUFFER_FULL              1519        /* �������ݻ�����  Input data cache full */
#define NETDEV_E_FAIL_TO_SET_PROCESS_DATA_CB        1520        /* ����ý�������ݻص�����ʧ��  Failed to set media stream data callback function */
#define NETDEV_E_VOICE_RUNNING                      1521        /* ����ҵ�����й����г���  Error occurred when running voice service */
#define NETDEV_E_FAIL_TO_OPEN_VOICE_SVC             1522        /* ��������ҵ��ʧ��  Failed to start voice service */
#define NETDEV_E_FAIL_TO_CLOSE_VOICE_SVC            1523        /* �ر�����ҵ��ʧ��  Failed to close voice service */
#define NETDEV_E_UNKNOWN_STREAM_TYPE                1524        /* δ֪ý����  Unknown media stream */
#define NETDEV_E_PACKET_LOSE                        1525        /* ����  Packet loss */
#define NETDEV_E_NEED_MORE_PACKET                   1526        /* ƴ��δ���,��Ҫ�����  More packets are needed for the packing */
#define NETDEV_E_FAIL_TO_CREATE_DECODE              1527        /* ����������ʧ��  Failed to create the decoder */
#define NETDEV_E_FAIL_TO_DECODE                     1528        /* ����ʧ�� Failed to decode */
#define NETDEV_E_RECV_DATA_NOTENOUGH                1529        /* �������ݲ���  Not enough data received */
#define NETDEV_E_RENDER_RES_FULL                    1530        /* ��ʾ��Դ��  Display resources full */
#define NETDEV_E_RENDER_RES_NOT_EXIST               1531        /* ��ʾ��Դ������  Display resources do not exist */
#define NETDEV_E_CREATE_DEV_FAILED                  1532        /* ��Դ����ʧ��  Failed to create the resources */
#define NETDEV_E_AUDIO_RES_NOT_EXIST                1533        /* ��Ƶ��Դ������  Audio resources do not exist */
#define NETDEV_E_IHW265D_NEED_MORE_BITS             1534        /* ��������Ҫ��������  Decoder requires more data */
#define NETDEV_E_FAIL_TO_CREATE_ENCODE              1535        /* ����������ʧ��  Failed to create encoder */
#define NETDEV_E_CAPTURE_RES_EXIST                  1536        /* �ɼ���Դ������  Capture resources do not exist */
#define NETDEV_E_RECORD_STARTED                     1537        /* ¼���Ѵ�  Recording already opened */
#define NETDEV_E_NEED_WAIT_DECODEC                  1538        /* δ�������,��Ҫ�ȴ�  Decoding in progress, please wait */
#define NETDEV_E_MORE_DATA_NEED_PACKET              1539        /* ���ݹ���,����Ҫ�������  Too much data, still need packing */

/* ʵ����ش�����  Live video error codes */
#define NETDEV_E_LIVE_EXISTED                       2000        /* ʵ��ҵ���Ѿ�����  Live video service already established */
#define NETDEV_E_LIVE_INPUT_NOT_READY               2001        /* ý����δ׼������  Media stream not ready */
#define NETDEV_E_LIVE_OUTPUT_BUSY                   2002        /* ʵ��ҵ����ʾ��Դæ  Display resource is busy for live video service */
#define NETDEV_E_LIVE_CB_NOTEXIST                   2003        /* ʵ�����ƿ鲻����  Control module for live video not exist */
#define NETDEV_E_LIVE_STREAM_FULL                   2004        /* ʵ������Դ����  Live stream resource full */

/* ץ����ش�����  Capture-related error codes */
#define NETDEV_E_CAPTURE_NO_SUPPORT_FORMAT          2100        /* ץ�ĸ�ʽ��֧��  Format of captured image not supported */
#define NETDEV_E_CAPTURE_NO_ENOUGH_CAPACITY         2101        /* Ӳ�̿ռ䲻��  Insufficient disk space */
#define NETDEV_E_CAPTURE_NO_DECODED_PICTURE         2102        /* û�н������ͼƬ�ɹ�ץ��  No decoded image for capture */
#define NETDEV_E_CAPTURE_SINGLE_FAILED              2103        /* ����ץ�Ĳ���ʧ��  Single capture failed */

/* �����Խ���ش�����  Error codes related to two-way audio */
#define NETDEV_E_AUDIO_EXISTED                      2200        /* �����Խ��Ѵ���  Two-way audio already exists */
#define NETDEV_E_AUDIO_NO_EXISTED                   2201        /* ����ҵ�񲻴���  Two-way audio service does not exist */
#define NETDEV_E_AUDIO_RESCODE_INVALID              2202        /* �����Խ���Դ������Ч  Invalid two-way audio resource code */
#define NETDEV_E_AUDIO_RES_USED_BY_TALK             2203        /* ������Դ�ѱ��Խ�ʹ��  Audio resource is being used by two-way audio */
#define NETDEV_E_AUDIO_FAILED                       2204        /* �����Խ�ʧ��  Two-way audio failed */
#define NETDEV_E_AUDIO_AUDIOBCAST_FULL              2205        /* ����ҵ������  No more audio service allowed */

/* END********************* ������  Error codes *********************************************************** */

/* BEGIN:****************** ö��ֵ  Enumeration value ***************************************************** */

/**
 * @enum tagNETDEVChannelStatus
 * @brief ͨ��״̬ ö�ٶ��� Channel status Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVChannelStatus
{
    NETDEV_CHL_STATUS_OFFLINE,      /* ͨ������  Channel offline */
    NETDEV_CHL_STATUS_ONLINE,       /* ͨ������  Channel online */
    NETDEV_CHL_STATUS_VIDEO_LOST,   /* ��Ƶ��ʧ  Video lost */
    NETDEV_CHL_STATUS_MAX,

    NETDEV_CHL_STATUS_BUTT
}NETDEV_CHANNEL_STATUS_E;

/**
 * @enum tagNETDEVCameraType
 * @brief ��������� ö�ٶ��� Camera type Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVCameraType
{
    NETDEV_CAMERA_TYPE_FIX         = 0,            /* �̶������  Fixed camera */
    NETDEV_CAMERA_TYPE_PTZ         = 1,            /* ��̨�����  PTZ camera */

    NETDEV_CAMERA_TYPE_INVALID     = 0xFF          /* ��Чֵ  Invalid value */
}NETDEV_CAMERA_TYPE_E;

/**
 * @enum tagNETDEVLiveStreamIndex
 * @brief ʵ��ҵ�������� ö�ٶ� �� Live stream index Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVLiveStreamIndex
{
    NETDEV_LIVE_STREAM_INDEX_MAIN  = 0,   /* ����  Main stream */
    NETDEV_LIVE_STREAM_INDEX_AUX   = 1,   /* ����  Sub stream */
    NETDEV_LIVE_STREAM_INDEX_THIRD = 2,   /* ������  Third stream */

    NETDEV_LIVE_STREAM_INDEX_BUTT
}NETDEV_LIVE_STREAM_INDEX_E;

/**
 * @enum tagHOSTType
 * @brief IPЭ������ ö�ٶ���  Protocol type Enumeration definition
 * @attention �� None
 */
typedef enum tagHOSTType
{
    NETDEV_NETWORK_HOSTTYPE_IPV4 = 0,               /* IPv4 */
    NETDEV_NETWORK_HOSTTYPE_IPV6 = 1,               /* IPv6 */
    NETDEV_NETWORK_HOSTTYPE_DNS  = 2                /* DNS */
}NETDEV_HOSTTYPE_E;


/**
 * @enum tagNETDEVProtocal
 * @brief ý�崫��Э�� ö�ٶ���  Media transport protocol Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVProtocal
{
    NETDEV_TRANSPROTOCAL_RTPTCP = 1,         /* TCP */
    NETDEV_TRANSPROTOCAL_RTPUDP = 2          /* UDP */
}NETDEV_PROTOCAL_E;

/**
 * @enum tagNETDEVMediaFileFormat
 * @brief ý���ļ���ʽ ö�ٶ���  Media file format Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVMediaFileFormat
{
    NETDEV_MEDIA_FILE_MP4 = 0,           /* mp4��ʽ��ý���ļ�  mp4 media file */
    NETDEV_MEDIA_FILE_TS = 1,            /* TS��ʽ��ý���ļ�  TS media file */
    NETDEV_MEDIA_FILE_BUTT
}NETDEV_MEDIA_FILE_FORMAT_E;

/**
 * @enum tagNETDEVVideoCodeType
 * @brief ��Ƶ�����ʽ ö�ٶ���  Video encoding format Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVVideoCodeType
{
    NETDEV_VIDEO_CODE_MJPEG = 0,          /* MJPEG */
    NETDEV_VIDEO_CODE_H264  = 1,          /* H.264 */
    NETDEV_VIDEO_CODE_H265  = 2,          /* H.265 */
    NETDEV_VIDEO_CODE_BUTT
}NETDEV_VIDEO_CODE_TYPE_E;

/**
 * @enum tagNETDEVVideoFrameType
 * @brief ��Ƶ֡���� ö�ٶ���  Video frame type Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVVideoFrameType
{
    NETDEV_VIDEO_FRAME_I = 0,               /* ��Ƶ֡ΪI֡  I-frame */
    NETDEV_VIDEO_FRAME_P = 1,               /* ��Ƶ֡ΪP֡  P-frame */
    NETDEV_VIDEO_FRAME_B = 2                /* ��Ƶ֡ΪB֡  B-frame */
}NETDEV_VIDEO_FRAME_TYPE_E;

/**
 * @enum tagNETDEVRenderScale
 * @brief ��Ƶ��ʾ���� ö�ٶ���  Video display ratio Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVRenderScale
{
    NETDEV_RENDER_SCALE_FULL       = 0,                  /* ͼ������������� ����  Stretch */
    NETDEV_RENDER_SCALE_PROPORTION = 1,                  /* ͼ�񰴱�����ʾ  Scale */

    NETDEV_RENDER_SCALE_BUTT       = 0xFF
}NETDEV_RENDER_SCALE_E;

/**
 * @enum tagNETDEVPictureFormat
 * @brief ͼƬ��ʽ ö�ٶ��� Picture type Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVPictureFormat
{
    NETDEV_PICTURE_BMP = 0,                  /* ͼƬ��ʽΪbmp��ʽ  Picture format is bmp */
    NETDEV_PICTURE_JPG = 1,                  /* ͼƬ��ʽΪjpg��ʽ  Picture format is jpg */

    NETDEV_PICTURE_BUTT
}NETDEV_PICTURE_FORMAT_E;

/**
 * @enum tagNETDEVVideoQuality
 * @brief ��Ƶͼ������ ö�ٶ���  Video image quality Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVVideoQuality
{
    NETDEV_VQ_L0 = 0,                    /* ���  Highest */
    NETDEV_VQ_L1 = 1,
    NETDEV_VQ_L2 = 4,                    /* �ϸ�  Higher */
    NETDEV_VQ_L3 = 8,
    NETDEV_VQ_L4 = 12,                   /* ��  Medium */
    NETDEV_VQ_L5 = 16,
    NETDEV_VQ_L6 = 20,                   /* ��  Low */
    NETDEV_VQ_L7 = 24,
    NETDEV_VQ_L8 = 28,                   /* �ϵ�  Lower */
    NETDEV_VQ_L9 = 31,                   /* ���  Lowest */

    NETDEV_VQ_LEVEL_INVALID = -1,        /* ��Ч  Valid */
}NETDEV_VIDEO_QUALITY_E;

/**
 * @enum tagNETDEVPictureSize
 * @brief ͼ��ֱ��� ö�ٶ��� Image resolution Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVPictureSize
{
    NETDEV_PICTURE_SIZE_D1     = 0,           /* D1 */
    NETDEV_PICTURE_SIZE_4CIF   = 1,           /* 4CIF */
    NETDEV_PICTURE_SIZE_2CIF   = 2,           /* 2CIF */
    NETDEV_PICTURE_SIZE_CIF    = 3,           /* CIF */
    NETDEV_PICTURE_SIZE_960H   = 4,           /* 960H */
    NETDEV_PICTURE_SIZE_QCIF   = 5,           /* QCIF */
    NETDEV_PICTURE_SIZE_HALFD1 = 6,           /* HALFD1 */
    NETDEV_PICTURE_SIZE_720    = 7,           /* 720 */
    NETDEV_PICTURE_SIZE_1080   = 8,           /* 1080 */
    NETDEV_PICTURE_SIZE_XGA    = 9,           /* 1024*768 */
    NETDEV_PICTURE_SIZE_SXGA   = 10,          /* 1280*1024 */

    NETDEV_PICTURE_SIZE_INVALID               /* ��Чֵ  Invalid value */
}NETDEV_PICTURE_SIZE_E;

/**
 * @enum tagNETDEVPtzCmdEnum
 * @brief ��̨���� ö�ٶ��� PTZ commands Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVPtzCmdEnum
{
#if 0
    NETDEV_PTZ_IRISCLOSE            =0x0102,       /* ��Ȧ��  Iris close */
    NETDEV_PTZ_IRISOPEN             =0x0104,       /* ��Ȧ��  Iris open */
#endif
    NETDEV_PTZ_FOCUSNEAR            = 0x0202,       /* ���ۼ�  Focus near */
    NETDEV_PTZ_FOCUSFAR             = 0x0204,       /* Զ�ۼ�  Focus far */
    NETDEV_PTZ_ZOOMTELE             = 0x0302,       /* �Ŵ�  Zoom in */
    NETDEV_PTZ_ZOOMWIDE             = 0x0304,       /* ��С  Zoom out */
    NETDEV_PTZ_TILTUP               = 0x0402,       /* ����  Tilt up */
    NETDEV_PTZ_TILTDOWN             = 0x0404,       /* ����  Tilt down */
    NETDEV_PTZ_PANRIGHT             = 0x0502,       /* ����  Pan right */
    NETDEV_PTZ_PANLEFT              = 0x0504,       /* ����  Pan left */
    NETDEV_PTZ_LEFTUP               = 0x0702,       /* ����  Move up left */
    NETDEV_PTZ_LEFTDOWN             = 0x0704,       /* ����  Move down left */
    NETDEV_PTZ_RIGHTUP              = 0x0802,       /* ����  Move up right */
    NETDEV_PTZ_RIGHTDOWN            = 0x0804,       /* ����  Move down right */

#if 0
    NETDEV_PTZ_PRESAVE              = 0x0601,       /* Ԥ��λ����  Save preset */
    NETDEV_PTZ_PRECALL              = 0x0602,       /* Ԥ��λ����  Call preset */
    NETDEV_PTZ_PREDEL               = 0x0603,       /* Ԥ��λɾ��  Delete preset */
#endif

    NETDEV_PTZ_ALLSTOP              = 0x0901,       /* ȫͣ������  All-stop command word */

    NETDEV_PTZ_TRACKCRUISE          = 0x1001,       /* ��ʼ�켣Ѳ��  Start route patrol*/
    NETDEV_PTZ_TRACKCRUISESTOP      = 0x1002,       /* ֹͣ�켣Ѳ��  Stop route patrol*/
    NETDEV_PTZ_TRACKCRUISEREC       = 0x1003,       /* ��ʼ¼�ƹ켣  Start recording route */
    NETDEV_PTZ_TRACKCRUISERECSTOP   = 0x1004,       /* ֹͣ¼�ƹ켣  Stop recording route */
    NETDEV_PTZ_TRACKCRUISEADD       = 0x1005,       /* ���Ѳ���켣  Add patrol route */
    NETDEV_PTZ_TRACKCRUISEDEL       = 0x1006,       /* ɾ���켣Ѳ��  Delete patrol route */

    NETDEV_PTZ_AREAZOOMIN           = 0x1101,       /* ����Ŵ�  Zoom in area */
    NETDEV_PTZ_AREAZOOMOUT          = 0x1102,       /* ������С  Zoom out area */
    NETDEV_PTZ_AREAZOOM3D           = 0x1103,       /* 3D��λ  3D positioning */

    NETDEV_PTZ_BRUSHON              = 0x0A01,       /* ��ˢ��  Wiper on */
    NETDEV_PTZ_BRUSHOFF             = 0x0A02,       /* ��ˢ��  Wiper off */

    NETDEV_PTZ_LIGHTON              = 0x0B01,       /* �ƿ�  Lamp on */
    NETDEV_PTZ_LIGHTOFF             = 0x0B02,       /* �ƹ�  Lamp off */

    NETDEV_PTZ_HEATON               = 0x0C01,       /* ���ȿ�  Heater on */
    NETDEV_PTZ_HEATOFF              = 0x0C02,       /* ���ȹ�  Heater off */

    NETDEV_PTZ_SNOWREMOINGON        = 0x0D01,       /* ��ѩ��  Snowremoval on */
    NETDEV_PTZ_SNOWREMOINGOFF       = 0x0D02,       /* ��ѩ��  Snowremoval off  */

#if 0
    NETDEV_PTZ_ABSPOSITION          = 0x0902,       /* ������������ԽǶ�  Set absolute position of camera */
    NETDEV_PTZ_GUARD                = 0x0903,       /* �ؿ���λ,���������̨ģ������  Return to home position (this command is not implemented on the PTZ template) */
    NETDEV_PTZ_SPEEDSET             = 0x0904,       /* �����ٶ�  Set speed */

    NETDEV_PTZ_INFRAREDON           = 0x0E01,       /* ���⿪  IR on */
    NETDEV_PTZ_INFRAREDOFF          = 0x0E02,       /* �����  IR off */

    NETDEV_PTZ_PRESETCRUISE         = 0x1001,       /* ��̨��Ԥ��λѲ�� ,�������ֲ�����̨ģ������  Preset-based PTZ patrol (the command word is not implemented on the PTZ template) */
    NETDEV_PTZ_PRESETCRUISESTOP     = 0x1002,       /* ��̨��Ԥ��λѲ��ֹͣ,�������ֲ�����̨ģ������  Preset-based PTZ patrol stop (the command word is not implemented on the PTZ template) */
    NETDEV_PTZ_CRUISEDEL            = 0X1003,       /* ɾ����·  Delete route */
    NETDEV_PTZ_CRUISEADDPRESET      = 0x1004,       /* ����·�����Ԥ��λ  Add preset to route */
    NETDEV_PTZ_CRUISEADDSTART       = 0x1005,       /* ��ʼ����·�����Ԥ��λ  Start adding preset to route */
    NETDEV_PTZ_CRUISEADDSTOP        = 0x1006,       /* ��������·�����Ԥ��λ  Stop adding preset to route */
#endif

    NETDEV_PTZ_BUTT
} NETDEV_PTZ_E;

/**
 * @enum tagNETDEVPtzPresetCmd
 * @brief ��̨Ԥ��λ�������� ö�ٶ��� PTZ preset operation commands Enumeration Definition
 * @attention �� None
 */
typedef enum tagNETDEVPtzPresetCmd
{
    NETDEV_PTZ_SET_PRESET   = 0,            /* ����Ԥ��λ  Set preset */
    NETDEV_PTZ_CLE_PRESET   = 1,            /* ���Ԥ��λ  Clear preset */
    NETDEV_PTZ_GOTO_PRESET  = 2             /* ת��Ԥ��λ  Go to preset */
}NETDEV_PTZ_PRESETCMD_E;

/**
 * @enum tagNETDEVPTZCruiseCmd
 * @brief ��̨Ѳ���������� ö�ٶ��� PTZ patrol operation commands Enumeration Definition
 * @attention �� None
 */
typedef enum tagNETDEVPTZCruiseCmd
{
    NETDEV_PTZ_ADD_CRUISE      = 0,         /* ���Ѳ��·��   Add patrol route */
    NETDEV_PTZ_MODIFY_CRUISE   = 1,         /* �༭Ѳ��·��  Edit patrol route */
    NETDEV_PTZ_DEL_CRUISE      = 2,         /* ɾ��Ѳ��·��  Delete patrol route */
    NETDEV_PTZ_RUN_CRUISE      = 3,         /* ��ʼѲ��  Start patrol */
    NETDEV_PTZ_STOP_CRUISE     = 4          /* ֹͣѲ��  Stop patrol */
}NETDEV_PTZ_CRUISECMD_E;

/**
 * @enum tagNETDEVPlayControl
 * @brief �طſ������� ö�ٶ��� Playback control commands Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVPlayControl
{
    NETDEV_PLAY_CTRL_PLAY            = 0,           /* ��ʼ����  Play */
    NETDEV_PLAY_CTRL_PAUSE           = 1,           /* ��ͣ����  Pause */
    NETDEV_PLAY_CTRL_RESUME          = 2,           /* �ָ�����  Resume */
    NETDEV_PLAY_CTRL_GETPLAYTIME     = 3,           /* ��ȡ���Ž���  Obtain playing time */
    NETDEV_PLAY_CTRL_SETPLAYTIME     = 4,           /* ���ò��Ž���  Configure playing time */
    NETDEV_PLAY_CTRL_GETPLAYSPEED    = 5,           /* ��ȡ�����ٶ�  Obtain playing speed */
    NETDEV_PLAY_CTRL_SETPLAYSPEED    = 6            /* ���ò����ٶ�  Configure playing speed */
}NETDEV_VOD_PLAY_CTRL_E;

/**
 * @enum tagNETDEVVodPlayStatus
 * @brief �طš�����״̬ ö�ٶ��� Playback and download status Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVVodPlayStatus
{
/** ����״̬  Play status */
    NETDEV_PLAY_STATUS_16_BACKWARD        = 0,        /* 16���ٺ��˲���  Backward at 16x speed */
    NETDEV_PLAY_STATUS_8_BACKWARD         = 1,        /* 8���ٺ��˲���  Backward at 8x speed */
    NETDEV_PLAY_STATUS_4_BACKWARD         = 2,        /* 4���ٺ��˲���  Backward at 4x speed */
    NETDEV_PLAY_STATUS_2_BACKWARD         = 3,        /* 2���ٺ��˲���  Backward at 2x speed */
    NETDEV_PLAY_STATUS_1_BACKWARD         = 4,        /* �����ٶȺ��˲���  Backward at normal speed */
    NETDEV_PLAY_STATUS_HALF_BACKWARD      = 5,        /* 1/2���ٺ��˲���  Backward at 1/2 speed */
    NETDEV_PLAY_STATUS_QUARTER_BACKWARD   = 6,        /* 1/4���ٺ��˲���  Backward at 1/4 speed */
    NETDEV_PLAY_STATUS_QUARTER_FORWARD    = 7,        /* 1/4���ٲ���  Play at 1/4 speed */
    NETDEV_PLAY_STATUS_HALF_FORWARD       = 8,        /* 1/2���ٲ���  Play at 1/2 speed */
    NETDEV_PLAY_STATUS_1_FORWARD          = 9,        /* �����ٶ�ǰ������  Forward at normal speed */
    NETDEV_PLAY_STATUS_2_FORWARD          = 10,       /* 2����ǰ������  Forward at 2x speed */
    NETDEV_PLAY_STATUS_4_FORWARD          = 11,       /* 4����ǰ������  Forward at 4x speed */
    NETDEV_PLAY_STATUS_8_FORWARD          = 12,       /* 8����ǰ������  Forward at 8x speed */
    NETDEV_PLAY_STATUS_16_FORWARD         = 13,       /* 16����ǰ������  Forward at 16x speed */

    NETDEV_PLAY_STATUS_INVALID
}NETDEV_VOD_PLAY_STATUS_E;

/**
 * @enum tagNETDEVDownloadSpeed
 * @brief ¼�������ٶ�  Recording download speed
 * @attention �� None
 */
typedef enum tagNETDEVDownloadSpeed
{
    NETDEV_DOWNLOAD_SPEED_ONE = 0,          /* һ����  1x */
    NETDEV_DOWNLOAD_SPEED_TWO,              /* ������  2x */
    NETDEV_DOWNLOAD_SPEED_FOUR,             /* �ı���  4x */
    NETDEV_DOWNLOAD_SPEED_EIGHT,            /* �˱���  8x */
    NETDEV_DOWNLOAD_SPEED_TWO_IFRAME,       /* ������I֡  I2x */
    NETDEV_DOWNLOAD_SPEED_FOUR_IFRAME,      /* �ı���I֡  I4x */
    NETDEV_DOWNLOAD_SPEED_EIGHT_IFRAME      /* �˱���I֡  I8x */
}NETDEV_E_DOWNLOAD_SPEED_E;

/**
 * @enum tagNETDEVStoreType
 * @brief ¼��洢���� ö�ٶ��� Recording storage type Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVStoreType
{
    NETDEV_TYPE_STORE_TYPE_ALL                  = 0,            /* ���еĴ洢  All */

    NETDEV_EVENT_STORE_TYPE_MOTIONDETECTION     = 4,            /* �˶�����¼��洢  Motion detection */
    NETDEV_EVENT_STORE_TYPE_DIGITALINPUT        = 5,            /* ���������¼��洢  Digital input */
    NETDEV_EVENT_STORE_TYPE_VIDEOLOSS           = 7,            /* ��Ƶ��ʧ�¼��洢  Video loss */

    NETDEV_TYPE_STORE_TYPE_INVALID              = 0xFF          /* ��Чֵ  Invalid value */
}NETDEV_PLAN_STORE_TYPE_E;

/**
 * @enum tagNETDEVException
 * @brief �쳣�ص�����Ϣ���� ö�ٶ��� Exception callback message types Enumeration definition 
 * @attention �� None
 */
typedef enum tagNETDEVException
{
    /* ʵ�� ҵ���쳣�ϱ�  Live view exceptions report 200~299 */

    /* �ط�ҵ���쳣�ϱ�  Playback exceptions report 300~399 */
    NETDEV_EXCEPTION_REPORT_VOD_END             = 300,          /* �طŽ���  Playback ended*/
    NETDEV_EXCEPTION_REPORT_VOD_ABEND           = 301,          /* �ط��쳣  Playback exception occured */
    NETDEV_EXCEPTION_REPORT_BACKUP_END          = 302,          /* ���ݽ���  Backup ended */
    NETDEV_EXCEPTION_REPORT_BACKUP_DISC_OUT     = 303,          /* ���̱��γ�  Disk removed */
    NETDEV_EXCEPTION_REPORT_BACKUP_DISC_FULL    = 304,          /* ��������  Disk full */
    NETDEV_EXCEPTION_REPORT_BACKUP_ABEND        = 305,          /* ����ԭ���±���ʧ��   Backup failure caused by other reasons */

    NETDEV_EXCEPTION_EXCHANGE                   = 0x8000,       /* �û�����ʱ�쳣���û����ʱ��  Exception occurred during user interaction (keep-alive timeout) */

    NETDEV_EXCEPTION_REPORT_INVALID             = 0xFFFF        /* ��Чֵ  Invalid value */
}NETDEV_EXCEPTION_TYPE_E;

/**
 * @enum tagNETDEVAlarmTypeEn
 * @brief �澯���ò��� ö�ٶ���  Alarm configuration operation Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVAlarmTypeEn
{
    /*********************************************************************** */
    /* �澯 Alarm                                                            */
    /*********************************************************************** */
    /* �лָ����͵ĸ澯  Recoverable alarms */
    NETDEV_ALARM_MOVE_DETECT                        = 1,            /* �˶����澯  Motion detection alarm */
    NETDEV_ALARM_VIDEO_LOST                         = 2,            /* ��Ƶ��ʧ�澯  Video loss alarm */
    NETDEV_ALARM_VIDEO_TAMPER_DETECT                = 3,            /* �ڵ����澯  Tampering detection alarm */
    NETDEV_ALARM_INPUT_SWITCH                       = 4,            /* ���뿪�����澯  boolean input alarm */
    NETDEV_ALARM_TEMPERATURE_HIGH                   = 5,            /* ���¸澯  High temperature alarm */
    NETDEV_ALARM_TEMPERATURE_LOW                    = 6,            /* ���¸澯  Low temperature alarm */
    NETDEV_ALARM_AUDIO_DETECT                       = 7,            /* �������澯  Audio detection alarm */
    NETDEV_ALARM_DISK_ABNORMAL                      = 8,            /* �����쳣 */
    NETDEV_ALARM_DISK_OFFLINE                       = 9,            /* �������� */

    /* NVR�������豸״̬�ϱ�  Status report of NVR and access device 100~199 */
    NETDEV_ALARM_REPORT_DEV_ONLINE                  = 100,          /* �豸����  Device online */
    NETDEV_ALARM_REPORT_DEV_OFFLINE                 = 101,          /* �豸����  Device offline */
    NETDEV_ALARM_REPORT_DEV_VIDEO_LOSS              = 102,          /* ��Ƶ��ʧ  Video loss */
    NETDEV_ALARM_REPORT_DEV_VIDEO_LOSS_RECOVER      = 103,          /* ��Ƶ��ʧ�ָ�  Video loss recover */
    NETDEV_ALARM_REPORT_DEV_REBOOT                  = 104,          /* �豸����  Device restart */
    NETDEV_ALARM_REPORT_DEV_SERVICE_REBOOT          = 105,          /* ��������  Service restart */

    /* ʵ��ҵ���쳣�ϱ�  Live view exception report 200~299 */
    NETDEV_ALARM_NET_FAILED                         = 200,          /* �Ự������� Network error */
    NETDEV_ALARM_NET_TIMEOUT                        = 201,          /* �Ự���糬ʱ Network timeout */
    NETDEV_ALARM_SHAKE_FAILED                       = 202,          /* �Ự�������� Interaction error */
    NETDEV_ALARM_STREAMNUM_FULL                     = 203,          /* �����Ѿ��� Stream full */
    NETDEV_ALARM_STREAM_THIRDSTOP                   = 204,          /* ������ֹͣ�� Third party stream stopped */
    NETDEV_ALARM_FILE_END                           = 205,          /* �ļ����� File ended */


    /* �޲���24Сʱ��Ч�ĸ澯  Valid alarms within 24 hours without arming schedule */
    NETDEV_ALARM_ALLTIME_FLAG_START                 = 400,          /* �޲����澯��ʼ���  Start marker of alarm without arming schedule */
    NETDEV_ALARM_STOR_ERR                           = 401,          /* �洢����  Storage error */
    NETDEV_ALARM_STOR_DISOBEY_PLAN                  = 402,          /* δ���ƻ��洢  Not stored as planned */

    /* �޻ָ����͵ĸ澯  Unrecoverable alarms */
    NETDEV_ALARM_NO_RECOVER_FLAG_START              = 500,          /* �޻ָ����͸澯��ʼ���  Start marker of unrecoverable alarm */
    NETDEV_ALARM_DISK_ERROR                         = 501,          /* ���̴���  Disk error */
    NETDEV_ALARM_ILLEGAL_ACCESS                     = 502,          /* �Ƿ�����  Illegal access */

    NETDEV_ALARM_ALLTIME_FLAG_END                   = 600,          /* �޲����澯�������  End marker of alarm without arming schedule */

    /* �澯�ָ�  Alarm recover */
    NETDEV_ALARM_RECOVER_BASE                       = 1000,         /* �澯�ָ�����  Alarm recover base */
    NETDEV_ALARM_MOVE_DETECT_RECOVER                = 1001,         /* �˶����澯�ָ�  Motion detection alarm recover */
    NETDEV_ALARM_VIDEO_LOST_RECOVER                 = 1002,         /* ��Ƶ��ʧ�澯�ָ�  Video loss alarm recover */
    NETDEV_ALARM_VIDEO_TAMPER_RECOVER               = 1003,         /* �ڵ����澯�ָ�  Tampering detection alarm recover */
    NETDEV_ALARM_INPUT_SWITCH_RECOVER               = 1004,         /* ���뿪�����澯�ָ�  Boolean input alarm recover */
    NETDEV_ALARM_TEMPERATURE_RECOVER                = 1005,         /* �¶ȸ澯�ָ�  Temperature alarm recover */
    NETDEV_ALARM_AUDIO_DETECT_RECOVER               = 1006,         /* �������澯�ָ�  Audio detection alarm recover */
    NETDEV_ALARM_DISK_ABNORMAL_RECOVER              = 1008,         /* �����쳣�ָ� */
    NETDEV_ALARM_DISK_OFFLINE_RECOVER               = 1009,         /* �������߻ָ� */

    NETDEV_ALARM_STOR_ERR_RECOVER                   = 1201,         /* �洢����ָ�  Storage error recover */
    NETDEV_ALARM_STOR_DISOBEY_PLAN_RECOVER          = 1202,         /* δ���ƻ��洢�ָ�  Not stored as planned recover */

    NETDEV_ALARM_BUTT                               = 0xFFFF        /* ��Чֵ  Invalid value */
}NETDEV_ALARM_TYPE_E;

/**
 * @enum tagNETDEVLogMainType
 * @brief ��־������ö�� ö�ٶ��� Major types of logs Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVLogMainType
{
    NETDEV_LOG_MAIN_TYPE_ALL                    = 0,               /* ȫ�����͵���־  Logs of all types */
    NETDEV_LOG_MAIN_TYPE_ALARM                  = 1,               /* �澯��  Alarms */
    NETDEV_LOG_MAIN_TYPE_EXCEPTION              = 2,               /* �쳣��  Exceptions */
    NETDEV_LOG_MAIN_TYPE_OPERATION              = 3,               /* ������  Operations */
    NETDEV_LOG_MAIN_TYPE_MESSAGE                = 4,               /* ��Ϣ��  Messages */

    NETDEV_LOG_MAIN_TYPE_BUTT                   = 0xFFFF            /* ��Чֵ  Invalid value */
}NETDEV_LOG_MAIN_TYPE_E;

/**
 * @enum tagNETDEVLogSubType
 * @brief ��־������ID ö�ٶ��� Minor type IDs of logs Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVLogSubType
{
    NETDEV_LOG_ALL_SUB_TYPES                     = 0x0101,          /* ������Ϣ����־  All information logs */

    /* ��Ϣ����־  Information logs */
    NETDEV_LOG_MSG_HDD_INFO                     = 300,              /* Ӳ����Ϣ  HDD information */
    NETDEV_LOG_MSG_SMART_INFO                   = 301,              /* S.M.A.R.T��Ϣ  S.M.A.R.T information */
    NETDEV_LOG_MSG_REC_OVERDUE                  = 302,              /* ����¼��ɾ��  Expired recording deletion */
    NETDEV_LOG_MSG_PIC_REC_OVERDUE              = 303,              /* ����ͼƬ�ļ�ɾ��  Expired image deletion */

    /* �澯����־����������־ID  Sub type log ID of alarm logs */
    NETDEV_LOG_ALARM_MOTION_DETECT              = 350,              /* �ƶ����澯  Motion detection alarm */
    NETDEV_LOG_ALARM_MOTION_DETECT_RESUME       = 351,              /* �ƶ����澯�ָ�  Motion detection alarm recover */
    NETDEV_LOG_ALARM_VIDEO_LOST                 = 352,              /* ��Ƶ��ʧ�澯  Video loss alarm */
    NETDEV_LOG_ALARM_VIDEO_LOST_RESUME          = 353,              /* ��Ƶ��ʧ�澯�ָ�  Video loss alarm recover */
    NETDEV_LOG_ALARM_VIDEO_TAMPER_DETECT        = 354,              /* �ڵ����澯  Tampering detection alarm */
    NETDEV_LOG_ALARM_VIDEO_TAMPER_RESUME        = 355,              /* �ڵ����澯�ָ�  Tampering detection alarm recover */
    NETDEV_LOG_ALARM_INPUT_SW                   = 356,              /* ���뿪�����澯  Boolean input alarm */
    NETDEV_LOG_ALARM_INPUT_SW_RESUME            = 357,              /* ���뿪�����澯�ָ�  Boolean input alarm recover */
    NETDEV_LOG_ALARM_IPC_ONLINE                 = 358,              /* IPC �豸����  Device online */
    NETDEV_LOG_ALARM_IPC_OFFLINE                = 359,              /* IPC �豸����  Device offline */

    /* �쳣����־����������־ID  Sub type log ID of exception logs */
    NETDEV_LOG_EXCEP_DISK_ONLINE                = 400,              /* ��������  Disk online */
    NETDEV_LOG_EXCEP_DISK_OFFLINE               = 401,              /* ��������  Disk offline */
    NETDEV_LOG_EXCEP_DISK_ERR                   = 402,              /* �����쳣  Disk exception */
    NETDEV_LOG_EXCEP_STOR_ERR                   = 403,              /* �洢����  Storage error */
    NETDEV_LOG_EXCEP_STOR_ERR_RECOVER           = 404,              /* �洢����ָ�  Storage error recover */
    NETDEV_LOG_EXCEP_STOR_DISOBEY_PLAN          = 405,              /* δ���ƻ��洢  Not stored as planned */
    NETDEV_LOG_EXCEP_STOR_DISOBEY_PLAN_RECOVER  = 406,              /* δ���ƻ��洢�ָ�  Not stored as planned recover */
    NETDEV_LOG_EXCEP_ILLEGAL_ACCESS             = 407,              /* �Ƿ�����  Illegal access */
    NETDEV_LOG_EXCEP_IP_CONFLICT                = 408,              /* IP��ַ��ͻ  IP address conflict */
    NETDEV_LOG_EXCEP_NET_BROKEN                 = 409,              /* ����Ͽ�  Network disconnection */
    NETDEV_LOG_EXCEP_PIC_REC_ERR                = 410,              /* ץͼ����,��ȡͼƬ�ļ�ʧ��  Failed to get captured image */
    NETDEV_LOG_EXCEP_VIDEO_EXCEPTION            = 411,              /* ��Ƶ�����쳣(ֻ���ģ��ͨ��)  Video input exception (for analog channel only) */
    NETDEV_LOG_EXCEP_VIDEO_MISMATCH             = 412,              /* ��Ƶ��ʽ��ƥ��   Video standards do not match */
    NETDEV_LOG_EXCEP_RESO_MISMATCH              = 413,              /* ����ֱ��ʺ�ǰ�˷ֱ��ʲ�ƥ��  Encoding resolution and front-end resolution do not match */
    NETDEV_LOG_EXCEP_TEMP_EXCE                  = 414,              /* �¶��쳣  Temperature exception */

    /* ��������־����������־ID  Sub type log ID of operation logs */
    /* ҵ����  Services */
    NETDEV_LOG_OPSET_LOGIN                      = 450,              /* �û���¼  User login */
    NETDEV_LOG_OPSET_LOGOUT                     = 451,              /* ע����¼  Log out */
    NETDEV_LOG_OPSET_USER_ADD                   = 452,              /* �û����  Add user */
    NETDEV_LOG_OPSET_USER_DEL                   = 453,              /* �û�ɾ��  Delete user */
    NETDEV_LOG_OPSET_USER_MODIFY                = 454,              /* �û��޸�  Modify user */
    NETDEV_LOG_OPSET_START_REC                  = 455,              /* ��ʼ¼��  Start recording */
    NETDEV_LOG_OPSET_STOP_REC                   = 456,              /* ֹͣ¼��  Stop recording */
    NETDEV_LOG_OPSETR_PLAY_DOWNLOAD             = 457,              /* �ط�/����  Playback and download */
    NETDEV_LOG_OPSET_DOWNLOAD                   = 458,              /* ����  Download */
    NETDEV_LOG_OPSET_PTZCTRL                    = 459,              /* ��̨����  PTZ control */
    NETDEV_LOG_OPSET_PREVIEW                    = 460,              /* ʵ��Ԥ��  Live preview */
    NETDEV_LOG_OPSET_REC_TRACK_START            = 461,              /* �켣¼�ƿ�ʼ  Start recording route */
    NETDEV_LOG_OPSET_REC_TRACK_STOP             = 462,              /* �켣¼��ֹͣ  Stop recording route */
    NETDEV_LOG_OPSET_START_TALKBACK             = 463,              /* ��ʼ�����Խ�  Start two-way audio */
    NETDEV_LOG_OPSET_STOP_TALKBACK              = 464,              /* ֹͣ�����Խ�  Stop two-way audio */
    NETDEV_LOG_OPSET_IPC_ADD                    = 465,              /* ���IPC  Add IP camera */
    NETDEV_LOG_OPSET_IPC_DEL                    = 466,              /* ɾ��IPC  Delete IP camera */
    NETDEV_LOG_OPSET_IPC_SET                    = 467,              /* ����IPC  Modify IP camera */

    /* ������  Configurations */
    NETDEV_LOG_OPSET_DEV_BAS_CFG                = 500,              /* �豸������Ϣ����  Basic device information */
    NETDEV_LOG_OPSET_TIME_CFG                   = 501,              /* �豸ʱ������  Device time */
    NETDEV_LOG_OPSET_SERIAL_CFG                 = 502,              /* �豸��������  Device serial port */
    NETDEV_LOG_OPSET_CHL_BAS_CFG                = 503,              /* ͨ����������  Basic channel configuration */
    NETDEV_LOG_OPSET_CHL_NAME_CFG               = 504,              /* ͨ����������  Channel name configuration */
    NETDEV_LOG_OPSET_CHL_ENC_VIDEO              = 505,              /* ��Ƶ�����������  Video encoding configuration */
    NETDEV_LOG_OPSET_CHL_DIS_VIDEO              = 506,              /* ͨ����Ƶ��ʾ��������  Video display configuration */
    NETDEV_LOG_OPSET_PTZ_CFG                    = 507,              /* ��̨����  PTZ configuration */
    NETDEV_LOG_OPSET_CRUISE_CFG                 = 508,              /* Ѳ����·����  Patrol route configuration */
    NETDEV_LOG_OPSET_PRESET_CFG                 = 509,              /* Ԥ��λ����  Preset configuration */
    NETDEV_LOG_OPSET_VIDPLAN_CFG                = 510,              /* ¼��ƻ�����  Recording schedule configuration */
    NETDEV_LOG_OPSET_MOTION_CFG                 = 511,              /* �˶��������  Motion detection configuration */
    NETDEV_LOG_OPSET_VIDLOSS_CFG                = 512,              /* ��Ƶ��ʧ����  Video loss configuration */
    NETDEV_LOG_OPSET_COVER_CFG                  = 513,              /* ��Ƶ�ڵ�����  Tampering detection configuration */
    NETDEV_LOG_OPSET_MASK_CFG                   = 514,              /* ��Ƶ�ڸ�����  Privacy mask configuration */
    NETDEV_LOG_OPSET_SCREEN_OSD_CFG             = 515,              /* OSD��������  OSD overlay configuration */
    NETDEV_LOG_OPSET_ALARMIN_CFG                = 516,              /* ������������  Alarm input configuration */
    NETDEV_LOG_OPSET_ALARMOUT_CFG               = 517,              /* �����������  Alarm output configuration */
    NETDEV_LOG_OPSET_ALARMOUT_OPEN_MAN          = 518,              /* �ֶ������������,�˻�  Manually enable alarm output, GUI */
    NETDEV_LOG_OPSET_ALARMOUT_CLOSE_MAN         = 519,              /* �ֶ��رձ������,�˻�  Manually disable alarm input, GUI */
    NETDEV_LOG_OPSET_ABNORMAL_CFG               = 520,              /* �쳣����  Exception configuration */
    NETDEV_LOG_OPSET_HDD_CFG                    = 521,              /* Ӳ������  HDD configuration */
    NETDEV_LOG_OPSET_NET_IP_CFG                 = 522 ,             /* TCP/IP����  TCP/IP configuration */
    NETDEV_LOG_OPSET_NET_PPPOE_CFG              = 523,              /* PPPOE����  PPPOE configuration */
    NETDEV_LOG_OPSET_NET_PORT_CFG               = 524,              /* �˿�����  Port configuration */
    NETDEV_LOG_OPSET_NET_DDNS_CFG               = 525,              /* DDNS����  DDNS configuration */

    /* ά���� Maintenance */
    NETDEV_LOG_OPSET_START_DVR                  = 600,              /* ����  Start up*/
    NETDEV_LOG_OPSET_STOP_DVR                   = 601,              /* �ػ�  Shut down */
    NETDEV_LOG_OPSET_REBOOT_DVR                 = 602,              /* �����豸  Restart device */
    NETDEV_LOG_OPSET_UPGRADE                    = 603,              /* �汾����  Version upgrade */
    NETDEV_LOG_OPSET_LOGFILE_EXPORT             = 604,              /* ������־�ļ�  Export log files */
    NETDEV_LOG_OPSET_CFGFILE_EXPORT             = 605,              /* ���������ļ�  Export configuration files */
    NETDEV_LOG_OPSET_CFGFILE_IMPORT             = 606,              /* ���������ļ�  Import configuration files */
    NETDEV_LOG_OPSET_CONF_SIMPLE_INIT           = 607,              /* �򵥻ָ�����  Export configuration files */
    NETDEV_LOG_OPSET_CONF_ALL_INIT              = 608               /* �ָ���������  Restore to factory settings */

}NETDEV_LOG_SUBTYPE_ID_E;

typedef enum tagNETDEVDeviceType
{
    NETDEV_DTYPE_UNKNOWN                        = 0,            /* Unknown type */
    NETDEV_DTYPE_IPC                            = 1,            /* IPC range */
    NETDEV_DTYPE_IPC_FISHEYE                    = 2,            /* ����IPC  fish eye IPC */
    NETDEV_DTYPE_NVR                            = 101,          /* NVR range */
    NETDEV_DTYPE_NVR_BACKUP                     = 102,          /* NVR���ݷ�����  NVR back up */
    NETDEV_DTYPE_DC                             = 201,          /* DC range */
    NETDEV_DTYPE_EC                             = 301,          /* EC range */
    NETDEV_DTYPE_BUTT                           = 0xFFFF        /* ��Чֵ  Invalid value */
}NETDEV_DEVICETYPE_E;

/**
 * @enum tagNETDEVCFGCmd
 * @brief �������������� ö�ٶ��� Parameter configuration command words Enumeration definition
 * @attention �� None
 */
typedef enum tagNETDEVCFGCmd
{
    NETDEV_GET_DEVICECFG                = 100,              /* ��ȡ�豸��Ϣ,�μ�#NETDEV_DEVICE_BASICINFO_S  Get device information, see #NETDEV_DEVICE_BASICINFO_S */
    NETDEV_SET_DEVICECFG                = 101,              /* ���� Reserved */

    NETDEV_GET_NTPCFG                   = 110,              /* ��ȡNTP����,�μ�#NETDEV_SYSTEM_NTP_INFO_S  Get NTP parameter, see #NETDEV_SYSTEM_NTP_INFO_S */
    NETDEV_SET_NTPCFG                   = 111,              /* ����NTP����,�μ�#NETDEV_SYSTEM_NTP_INFO_S  Set NTP parameter, see #NETDEV_SYSTEM_NTP_INFO_S */

    NETDEV_GET_STREAMCFG                = 120,              /* ��ȡ��Ƶ�������,�μ�#NETDEV_VIDEO_STREAM_INFO_S  Get video encoding parameter, see #NETDEV_VIDEO_STREAM_INFO_S */
    NETDEV_SET_STREAMCFG                = 121,              /* ������Ƶ�������,�μ�#NETDEV_VIDEO_STREAM_INFO_S  Set video encoding parameter, see #NETDEV_VIDEO_STREAM_INFO_S */

    NETDEV_GET_PTZPRESETS               = 130,              /* ��ȡ��̨Ԥ��λ,�μ�#NETDEV_PTZ_ALLPRESETS_S  Get PTZ preset, see #NETDEV_PTZ_ALLPRESETS_S */

    NETDEV_GET_OSDCFG                   = 140,              /* ��ȡOSD������Ϣ,�μ�#NETDEV_VIDEO_OSD_CFG_S  Get OSD configuration information, see #NETDEV_VIDEO_OSD_CFG_S */
    NETDEV_SET_OSDCFG                   = 141,              /* ����OSD������Ϣ,�μ�#NETDEV_VIDEO_OSD_CFG_S  Set OSD configuration information, see #NETDEV_VIDEO_OSD_CFG_S */

    NETDEV_GET_ALARM_OUTPUTCFG          = 150,              /* ��ȡ������������Ϣ,�μ�#NETDEV_ALARM_OUTPUT_LIST_S  Get boolean configuration information, see #NETDEV_ALARM_OUTPUT_LIST_S */
    NETDEV_SET_ALARM_OUTPUTCFG          = 151,              /* ���ÿ�����������Ϣ,�μ�#NETDEV_ALARM_OUTPUT_LIST_S  Set boolean configuration information, see #NETDEV_ALARM_OUTPUT_LIST_S */
    NETDEV_TRIGGER_ALARM_OUTPUT         = 152,              /* ����������,�μ�#NETDEV_TRIGGER_ALARM_OUTPUT_S        Trigger boolean, see #NETDEV_TRIGGER_ALARM_OUTPUT_S */
    NETDEV_GET_ALARM_INPUTCFG           = 153,              /* ��ȡ��������������,�μ�#NETDEV_ALARM_INPUT_LIST_S   Get the number of boolean inputs, see #NETDEV_ALARM_INPUT_LIST_S */

    NETDEV_GET_IMAGECFG                 = 160,              /* ��ȡͼ��������Ϣ,�μ�#NETDEV_IMAGE_SETTING_S  Get image configuration information, see #NETDEV_IMAGE_SETTING_S */
    NETDEV_SET_IMAGECFG                 = 161,              /* ����ͼ��������Ϣ,�μ�#NETDEV_IMAGE_SETTING_S  Set image configuration information, see #NETDEV_IMAGE_SETTING_S */

    NETDEV_GET_NETWORKCFG               = 170,              /* ��ȡ����������Ϣ,�μ�#NETDEV_NETWORKCFG_S  Get network configuration information, see #NETDEV_NETWORKCFG_S */
    NETDEV_SET_NETWORKCFG               = 171,              /* ��������������Ϣ,�μ�#NETDEV_NETWORKCFG_S  Set network configuration information, see #NETDEV_NETWORKCFG_S */

    NETDEV_GET_PRIVACYMASKCFG           = 180,              /* ��ȡ��˽�ڸ�������Ϣ,�μ�#NETDEV_PRIVACY_MASK_CFG_S  Get privacy mask configuration information, see #NETDEV_PRIVACY_MASK_CFG_S */
    NETDEV_SET_PRIVACYMASKCFG           = 181,              /* ������˽�ڸ�������Ϣ,�μ�#NETDEV_PRIVACY_MASK_CFG_S  Set privacy mask configuration information, see #NETDEV_PRIVACY_MASK_CFG_S */
    NETDEV_DELETE_PRIVACYMASKCFG        = 182,              /* ɾ����˽�ڸ�������Ϣ  Delete privacy mask configuration information */

    NETDEV_GET_TAMPERALARM              = 190,              /* ��ȡ�ڵ����澯��Ϣ  �μ�#NETDEV_TAMPER_ALARM_INFO_S  Get tamper alarm configuration information, see #NETDEV_TAMPER_ALARM_INFO_S */
    NETDEV_SET_TAMPERALARM              = 191,              /* �����ڵ����澯��Ϣ  �μ�#NETDEV_TAMPER_ALARM_INFO_S  Set tamper alarm configuration information, see #NETDEV_TAMPER_ALARM_INFO_S */

    NETDEV_GET_MOTIONALARM              = 201,              /* ��ȡ�˶����澯��Ϣ �μ�#NETDEV_MOTION_ALARM_INFO_S  Get motion alarm configuration information, see #NETDEV_MOTION_ALARM_INFO_S */
    NETDEV_SET_MOTIONALARM              = 202,              /* �����˶����澯��Ϣ �μ�#NETDEV_MOTION_ALARM_INFO_S  Set motion alarm configuration information, see #NETDEV_MOTION_ALARM_INFO_S */

    NETDEV_CFG_BUTT                     = 0xFFFF            /* ��Чֵ  Invalid value */

}NETDEV_CONFIG_COMMAND_E;

/**
 * @enum tagNETDEVDateOSDFormateCap
 * @brief ���ڸ�ʽ������ ö�ٶ��� OSD date format capabilities enumeration 
 * @attention �� None
 */
typedef enum tagNETDEVDateOSDFormateCap
{
    NETDEV_OSD_DATE_FORMAT_CAP_MD_YYYY          = 0,        /* M/d/yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_MMDD_YYYY        = 1,        /* MM/dd/yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_DDMM_YYYY        = 2,        /* dd/MM/yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_YYYY_MMDD        = 3,        /* yyyy/MM/dd */
    NETDEV_OSD_DATE_FORMAT_CAP_YYYYMMDDB        = 4,        /* yyyy-MM-dd */
    NETDEV_OSD_DATE_FORMAT_CAP_XX_MMDD_YYYY     = 5,        /* dddd, MMMM dd, yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_MMMMDD_YYYY      = 6,        /* MMMM dd, yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_DDMMMM_YYYY      = 7         /* dd MMMM, yyyy */
}NETDEV_OSD_DATE_FORMAT_CAP_E;

/**
 * @enum tagNETDEVTimeOSDFormateCap
 * @brief OSDʱ���ʽ������ö�� OSD time format capabilities enumeration
 * @attention �� None
 */
typedef enum tagNETDEVTimeOSDFormateCap
{
    NETDEV_OSD_TIME_FORMAT_CAP_HHMMSS = 0,                  /* HH:mm:ss */
    NETDEV_OSD_TIME_FORMAT_CAP_HH_MM_SS_PM                  /* hh:mm:ss tt */
}NETDEV_OSD_TIME_FORMAT_CAP_E;

/**
 * @enum tagNETDEVBooleanMode
 * @brief ���뿪��������ģʽ Boolean input operation mode
 * @attention �� None
 */
typedef enum tagNETDEVBooleanMode
{
    NETDEV_BOOLEAN_MODE_OPEN   = 1,                         /* ����  Always open */
    NETDEV_BOOLEAN_MODE_CLOSE  = 2,                         /* ����  Always closed */
    NETDEV_BOOLEAN_MODE_BUTT
}NETDEV_BOOLEAN_MODE_E;

/**
 * @enum tagNETDEVTimeOSDFormateCap
 * @brief ������״̬ Boolean input operation mode
 * @attention �� None
 */
typedef enum tagNETDEVRelayOutPutState
{
    NETDEV_BOOLEAN_STATUS_ACTIVE    = 0,                /* ����״̬  Triggered */
    NETDEV_BOOLEAN_STATUS_INACTIVE  = 1                 /* �Ǵ���״̬ Not triggered */
}NETDEV_RELAYOUTPUT_STATE_E;

/**
* @enum tagNETDEVMediaDataFormat
* @brief ý����������ʽ
* @attention ��
*/
typedef enum tagNETDEVMediaDataFormat
{
    NETDEV_MEDIA_DATA_TS            = 0,            /* TS */
    NETDEV_MEDIA_DATA_RTP_ES        = 3             /* RTP + ES */
}NETDEV_MEDIA_DATA_FORMAT_E;

/**
* @enum tagNETDEVProtocolType
* @brief Э������
* @attention ��
*/
typedef enum tagNETDEVProtocolType
{
    NETDEV_PROTOCOL_TYPE_HTTP  = 0,
    NETDEV_PROTOCOL_TYPE_HTTPS = 1,
    NETDEV_PROTOCOL_TYPE_RTSP  = 2
}NETDEV_PROTOCOL_TYPE_E;

/**
* @enum tagNETDEVTTimeZone
* @brief ʱ��  Time Zone
* @attention �� None
*/
typedef enum tagNETDEVTimeZone
{
    NETDEV_TIME_ZONE_W1200 = 0,              /* W12 */
    NETDEV_TIME_ZONE_W1100 = 1,              /* W11 */
    NETDEV_TIME_ZONE_W1000 = 2,              /* W10 */
    NETDEV_TIME_ZONE_W0900 = 3,              /* W9 */
    NETDEV_TIME_ZONE_W0800 = 4,              /* W8 */
    NETDEV_TIME_ZONE_W0700 = 5,              /* W7 */
    NETDEV_TIME_ZONE_W0600 = 6,              /* W6 */
    NETDEV_TIME_ZONE_W0500 = 7,              /* W5 */
    NETDEV_TIME_ZONE_W0430 = 8,              /* W4:30 */
    NETDEV_TIME_ZONE_W0400 = 9,              /* W4 */
    NETDEV_TIME_ZONE_W0330 = 10,             /* W3:30 */
    NETDEV_TIME_ZONE_W0300 = 11,             /* W3 */
    NETDEV_TIME_ZONE_W0200 = 12,             /* W2 */
    NETDEV_TIME_ZONE_W0100 = 13,             /* W1 */
    NETDEV_TIME_ZONE_0000  = 14,             /* W0 */
    NETDEV_TIME_ZONE_E0100 = 15,             /* E1 */
    NETDEV_TIME_ZONE_E0200 = 16,             /* E2 */
    NETDEV_TIME_ZONE_E0300 = 17,             /* E3 */
    NETDEV_TIME_ZONE_E0330 = 18,             /* E3:30 */
    NETDEV_TIME_ZONE_E0400 = 19,             /* E4 */
    NETDEV_TIME_ZONE_E0430 = 20,             /* E4:30 */
    NETDEV_TIME_ZONE_E0500 = 21,             /* E5 */
    NETDEV_TIME_ZONE_E0530 = 22,             /* E5:30 */
    NETDEV_TIME_ZONE_E0545 = 23,             /* E5:45 */
    NETDEV_TIME_ZONE_E0600 = 24,             /* E6 */
    NETDEV_TIME_ZONE_E0630 = 25,             /* E6:30 */
    NETDEV_TIME_ZONE_E0700 = 26,             /* E7 */
    NETDEV_TIME_ZONE_E0800 = 27,             /* E8 */
    NETDEV_TIME_ZONE_E0900 = 28,             /* E9 */
    NETDEV_TIME_ZONE_E0930 = 29,             /* E9:30 */
    NETDEV_TIME_ZONE_E1000 = 30,             /* E10 */
    NETDEV_TIME_ZONE_E1100 = 31,             /* E11 */
    NETDEV_TIME_ZONE_E1200 = 32,             /* E12 */
    NETDEV_TIME_ZONE_E1300 = 33,             /* E13 */

    NETDEV_TIME_ZONE_INVALID = 0xFF          /* Invalid value */
}NETDEV_TIME_ZONE_E;

/* END************* ö��ֵ  Enumeration value *************************** */

/* BEGIN*********** �ṹ��  Structure *********************************** */

/**
 * @struct tagNETDEVDeviceInfo
 * @brief �豸��Ϣ �ṹ�嶨�� Device information Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVDeviceInfo
{
    INT32   dwDevType;                          /* �豸����,�μ�ö��#NETDEV_DEVICETYPE_E  Device type, see enumeration #NETDEV_DEVICETYPE_E */
    INT16   wAlarmInPortNum;                    /* �����������  Number of alarm inputs */
    INT16   wAlarmOutPortNum;                   /* �����������  Number of alarm outputs */
    INT32   dwChannelNum;                       /* ͨ������  Number of Channels */
    BYTE    byRes[48];                          /* �����ֶ�  Reserved */
}NETDEV_DEVICE_INFO_S,*LPNETDEV_DEVICE_INFO_S;

/**
 * @struct tagNETDEVDeviceBasicInfo
 * @brief �豸������Ϣ �ṹ�嶨�� Basic device information Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVDeviceBasicInfo
{ 
    CHAR szDevModel[NETDEV_LEN_64];                     /* �豸�ͺ�  Device model */
    CHAR szSerialNum[NETDEV_LEN_64];                    /* Ӳ�����к�  Hardware serial number */
    CHAR szFirmwareVersion[NETDEV_LEN_64];              /* ����汾��  Software version */
    CHAR szMacAddress[NETDEV_LEN_64];                   /* IPv4��Mac��ַ  MAC address of IPv4 */
    CHAR szDeviceName[NETDEV_LEN_64];                   /* �豸����  Device name */
    BYTE byRes[448];                                    /* ������  Reserved */
}NETDEV_DEVICE_BASICINFO_S, *LPNETDEV_DEVICE_BASICINFO_S;

/**
 * @struct tagNETDEVNetworkInterfaces
 * @brief ����������Ϣ �ṹ�嶨�� Network configuration information
 * @attention �� None
 */
typedef struct tagNETDEVNetworkInterfaces
{
    INT32   dwMTU;                              /* MTUֵ  MTU value */
    INT32   dwIPv4DHCP;                         /* IPv4��DHCP  DHCP of IPv4 */
    CHAR    szIpv4Address[NETDEV_LEN_32];       /* IPv4��IP��ַ  IP address of IPv4 */
    CHAR    szIPv4GateWay[NETDEV_LEN_32];       /* IPv4�����ص�ַ  Gateway of IPv4 */
    CHAR    szIPv4SubnetMask[NETDEV_LEN_32];    /* IPv4����������  Subnet mask of IPv4 */
    BYTE    byRes[480];                         /* ������  Reserved */
}NETDEV_NETWORKCFG_S, *LPNETDEV_NETWORKCFG_S;

/**
 * @struct tagSysemIPAddr
 * @brief ��ַ �ṹ�嶨�� Address Structure definition 
 * @attention �� None
 */
typedef struct tagSysemIPAddr
{
    INT32   eIPType;                            /* Э�����Ͳμ�ö��#NETDEV_HOSTTYPE_E  Protocol type, see enumeration #NETDEV_HOSTTYPE_E */
    CHAR    szIPAddr[NETDEV_LEN_132];           /* IP��ַ  IP address */
}NETDEV_SYSTEM_IPADDR_S, *LPNETDEV_SYSTEM_IPADDR_S;

/**
 * @struct tagNETDEVSystemNTPInfo
 * @brief  NTP���� NTP parameter
 * @attention �� None
 */
typedef struct tagNETDEVSystemNTPInfo
{
    BOOL bSupportDHCP;                      /* �Ƿ�֧��DHCP  Support DHCP or not */
    NETDEV_SYSTEM_IPADDR_S stAddr;          /* NTP ��Ϣ  NTP information */
}NETDEV_SYSTEM_NTP_INFO_S, *LPNETDEV_SYSTEM_NTP_INFO_S;

/**
 * @struct tagNETDEVPriviewInfo
 * @brief ʵ��Ԥ������ �ṹ�嶨�� Live view parameter Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVPriviewInfo
{
    INT32   dwChannelID;                    /* ͨ��ID  Channel ID */
    INT32   dwStreamType;                   /* ��������,�μ�ö��#NETDEV_LIVE_STREAM_INDEX_E  Stream type, see enumeration #NETDEV_LIVE_STREAM_INDEX_E */
    INT32   dwLinkMode;                     /* ����Э��,�μ�ö��#NETDEV_PROTOCAL_E  Transport protocol, see enumeration #NETDEV_PROTOCAL_E */
    LPVOID  hPlayWnd;                       /* ���Ŵ��ھ�� Play window handle */ 
    BYTE    byRes[264];                     /* �����ֶ�  Reserved */
}NETDEV_PREVIEWINFO_S, *LPNETDEV_PREVIEWINFO_S;

/**
 * @struct tagNETDEVVideoEffect
 * @brief ʵ��Ӱ����Ϣ �ṹ�嶨�� Live image information Structure definition
 * @attention ٤�������Χ0-10,��������ȡֵ��Χ0-255 Gamma parameter range: 0-10, other parameters: 0-255
 */
typedef struct tagNETDEVVideoEffect
{
    INT32 dwContrast;                   /* �Աȶ�  Contrast */
    INT32 dwBrightness;                 /* ����  Brightness */
    INT32 dwSaturation;                 /* ���Ͷ�  Saturation */
    INT32 dwHue;                        /* ɫ��  Hue */
    INT32 dwGamma;                      /* ٤��ֵ  Gamma */
    BYTE  byRes[16];                    /* �����ֶ�  Reserved */
}NETDEV_VIDEO_EFFECT_S, *LPNETDEV_VIDEO_EFFECT_S;

/**
 * @struct tagNETDEVImagingSetting
 * @brief �豸ͼ������ �ṹ�嶨��    Device image settings Structure definition
 * @attention ����ȡֵ��Χ��0-255     parameter range: 0-255
 */
typedef struct tagNETDEVImagingSetting
{
    INT32 dwContrast;                   /* �Աȶ�  Contrast */
    INT32 dwBrightness;                 /* ����  Brightness */
    INT32 dwSaturation;                 /* ���Ͷ�  Saturation */
    INT32 dwSharpness;                  /* ����  Sharpness */
    BYTE  byRes[252];                   /* �����ֶ�  Reserved */
}NETDEV_IMAGE_SETTING_S, *LPNETDEV_IMAGE_SETTING_S;

/************ �ط�ҵ�� Playback services***********************************************/

/**
 * @struct tagNETDEVVodFile
 * @brief ¼���ļ� �ṹ�嶨�� Recording file Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVVodFile
{
    CHAR                        szFileName[NETDEV_LEN_64];      /* ¼���ļ���  Recording file name */
    NETDEV_PLAN_STORE_TYPE_E    enType;                         /* ¼��洢����  Recording storage type */
    INT64                       tBeginTime;                     /* ��ʼʱ��  Start time */
    INT64                       tEndTime;                       /* ����ʱ��  End time */
}NETDEV_VOD_FILE_S, *LPNETDEV_VOD_FILE_S;

/**
 * @struct tagNETDEVFindCond
 * @brief ¼����� �ṹ�嶨�� Recording query Structure definition
 *        �����ļ����͡�ʱ������豸¼���ļ� Query recording files according to file type and time
 * @attention �� None
 */
typedef struct tagNETDEVFindCond
{
    CHAR    szFileName[NETDEV_LEN_64];      /* ¼���ļ���  Recording file name */
    INT32   dwChannelID;                    /* ͨ����  Channel number */
    INT32   dwFileType;                     /* ¼��洢����,�μ�ö��#NETDEV_PLAN_STORE_TYPE_E  Recording storage type, see enumeration #NETDEV_PLAN_STORE_TYPE_E */
    INT64   tBeginTime;                     /* ��ʼʱ��  Start time */
    INT64   tEndTime;                       /* ����ʱ��  End time */
    BYTE    byRes[40];                      /* �����ֶ�  Reserved */
}NETDEV_FILECOND_S, *LPNETDEV_FILECOND_S;

/**
 * @struct tagNETDEVFingData
 * @brief ¼��������� �ṹ�嶨�� Recording query data Structure definition
 *        �����ȡ���ҵ����ļ���Ϣ Get the information of found files one by one
 * @attention �� None
 */
typedef struct tagNETDEVFingData
{
    CHAR    szFileName[NETDEV_FILE_NAME_LEN];               /* ¼���ļ���  Recording file name */
    INT64   tBeginTime;                                     /* ��ʼʱ��  Start time */
    INT64   tEndTime;                                       /* ����ʱ��  End time */
    BYTE    byFileType;                                     /* ¼��洢����  Recording storage type */
    BYTE    byRes[171];                                     /* �����ֶ�  Reserved */
}NETDEV_FINDDATA_S,*LPNETDEV_FINDDATA_S;

/**
 * @struct tagNETDEVPlayBackInfo
 * @brief ���ļ����ط�¼����� �ṹ�嶨�� Parameters of play back recordings by file name Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVPlayBackInfo
{
    char    szName[NETDEV_LEN_260];         /* �طŵĿ��ƿ�����  Playback control block name*/
    INT64   tBeginTime;                     /* �طſ�ʼʱ��  Playback start time */
    INT64   tEndTime;                       /* �طŽ���ʱ��  Playback end time */
    INT32   dwLinkMode;                     /* ����Э��,�μ�ö��#NETDEV_PROTOCAL_E  Transport protocol, see enumeration #NETDEV_PROTOCAL_E */
    LPVOID  hPlayWnd;                       /* ���Ŵ��ھ��  Play window handle */
    INT32   dwFileType;                     /* ¼��洢����,�μ�ö��#NETDEV_PLAN_STORE_TYPE_E  Recording storage type, see enumeration #NETDEV_PLAN_STORE_TYPE_E */
    INT32   dwDownloadSpeed;                /* �����ٶ� �μ�ö��#NETDEV_E_DOWNLOAD_SPEED_E  Download speed, see enumeration #NETDEV_E_DOWNLOAD_SPEED_E */
    BYTE    byRes[256];                     /* �����ֶ�  Reserved */
}NETDEV_PLAYBACKINFO_S, *LPNETDEV_PLAYBACKINFO_S;

/**
 * @struct tagNETDEVPlayBackCondition
 * @brief ��ʱ��ط�¼����� �ṹ�嶨�� Parameters of play back by time Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVPlayBackCondition
{
    INT32   dwChannelID;                /* �طŵ�ͨ��  Playback channel */
    INT64   tBeginTime;                 /* �طſ�ʼʱ��  Playback start time */
    INT64   tEndTime;                   /* �طŽ���ʱ��  Playback end time */
    INT32   dwLinkMode;                 /* ����Э��,�μ�ö��#NETDEV_PROTOCAL_E  Transport protocol, see enumeration #NETDEV_PROTOCAL_E */
    LPVOID  hPlayWnd;                   /* ���Ŵ��ھ��  Play window handle */
    INT32   dwFileType;                 /* ¼��洢����,�μ�ö��#NETDEV_PLAN_STORE_TYPE_E  Recording storage type, see enumeration #NETDEV_PLAN_STORE_TYPE_E */
    INT32   dwDownloadSpeed;            /* �����ٶ� �μ�ö��#NETDEV_E_DOWNLOAD_SPEED_E */
    BYTE    byRes[256];                 /* �����ֶ�  Reserved */
}NETDEV_PLAYBACKCOND_S, *LPNETDEV_PLAYBACKCOND_S;

/************************************************* ��̨ҵ��*****************************************************/
/************************************************* PTZ services*****************************************************/
/**
 * @struct tagstNETDEVPtzPreset
 * @brief ��̨Ԥ��λ��Ϣ �ṹ�嶨�� PTZ preset information Structure definition
 * @attention �� None
 */
typedef struct tagstNETDEVPtzPreset
{
    INT32   dwPresetID;                                 /* Ԥ��λID  Preset ID */
    CHAR    szPresetName[NETDEV_LEN_32];                /* Ԥ��λ����  Preset name */
}NETDEV_PTZ_PRESET_S, *LPNETDEV_PTZ_PRESET_S;

/**
 * @struct tagstNETDEVPtzAllPresets
 * @brief ������̨Ԥ��λ �ṹ�嶨�� All PTZ presets Structure definition
 * @attention �� None
 */
typedef struct tagstNETDEVPtzAllPresets
{
    INT32               dwSize;                             /* Ԥ��λ����  Total number of presets */
    NETDEV_PTZ_PRESET_S astPreset[NETDEV_MAX_PRESET_NUM];   /* Ԥ��λ��Ϣ�ṹ��  Structure of preset information */
}NETDEV_PTZ_ALLPRESETS_S, *LPNETDEV_PTZ_ALLPRESETS_S;

/**
 * @struct tagNETDEVCruisePointInfo
 * @brief ��̨Ԥ��λѲ���켣����Ϣ �ṹ�嶨�� PTZ preset patrol point information Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVCruisePoint
{
    INT32   dwPresetID;                     /* Ԥ��λID  Preset ID */
    INT32   dwStayTime;                     /* ͣ��ʱ��  Stay time */
    INT32   dwSpeed;                        /* ת���ٶ�  Speed */
    INT32   dwReserve;                      /* �����ֶ�  Reserved */
}NETDEV_CRUISE_POINT_S, *LPNETDEV_CRUISE_POINT_S;

/**
 * @struct tagNETDEVCruiseInfo
 * @brief ��̨Ԥ��λѲ��·����ϸ��Ϣ �ṹ�嶨�� PTZ preset patrol route information Structure definition 
 * @attention �� None
 */
typedef struct tagNETDEVCruiseInfo
{
    INT32                   dwCuriseID;                                     /* �켣ID  Route ID */
    CHAR                    szCuriseName[NETDEV_LEN_32];                    /* �켣����  Route name */
    INT32                   dwSize;                                         /* ·�������Ĺ켣������  Number of presets included in the route */
    NETDEV_CRUISE_POINT_S   astCruisePoint[NETDEV_MAX_CRUISEPOINT_NUM];     /* ·�������Ĺ켣����Ϣ   Information of presets included in the route */
}NETDEV_CRUISE_INFO_S, *LPNETDEV_CRUISE_INFO_S;

/**
 * @struct tagNETDEVCruiseList
 * @brief ��̨Ԥ��λѲ��·���б� �ṹ�嶨�� PTZ preset patrol route list Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVCruiseList
{
    INT32                   dwSize;                                         /* Ѳ��·������  Number of patrol routes */
    NETDEV_CRUISE_INFO_S    astCruiseInfo[NETDEV_MAX_CRUISEROUTE_NUM];      /* Ѳ��·����Ϣ  Information of patrol routes */
}NETDEV_CRUISE_LIST_S, *LPNETDEV_CRUISE_LIST_S;

/**
 * @struct tagNETDEVPtzTrackinfo
 * @brief ��̨�켣Ѳ��·����Ϣ �ṹ�嶨�� Route information of PTZ route patrol Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVPtzTrackinfo
{
    INT32 dwTrackNum;                                               /* �Ѵ��ڵ�Ѳ���켣������  Number of existing patrol routes */
    CHAR  aszTrackName[NETDEV_TRACK_CRUISE_MAXNUM][NETDEV_LEN_64];  /* �켣����  Route name */
}NETDEV_PTZ_TRACK_INFO_S, *LPNETDEV_PTZ_TRACK_INFO_S;

/**
 * @struct tagNETDEVRect
 * @brief �������� �ṹ�嶨�� Rectangle Area  Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVRect
{
    INT32   dwLeft;                               /* x�����ֵ[0,10000]  X axis left point value [0,10000] */
    INT32   dwTop;                                /* y�ᶥ��ֵ[0,10000]  Y axis top point value [0,10000] */
    INT32   dwRight;                              /* x���ҵ�ֵ[0,10000]  X axis right point value [0,10000] */
    INT32   dwBottom;                             /* y��׵�ֵ[0,10000]  Y axis bottom point value [0,10000] */
}NETDEV_RECT_S, *LPNETDEV_RECT_S;

/**
 * @struct tagNETDEVPtzOperateAreaInfo
 * @brief ͼ��������Ϣ �ṹ�嶨�� Image area information Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVPtzOperateAreaInfo
{
    INT32   dwBeginPointX;                           /* ������ʼ��Xֵ[0,10000]  Area start point X value [0,10000] */
    INT32   dwBeginPointY;                           /* ������ʼ��Yֵ[0,10000]  Area start point Y value [0,10000] */
    INT32   dwEndPointX;                             /* ���������Xֵ[0,10000]  Area end point X value [0,10000] */
    INT32   dwEndPointY;                             /* ���������Yֵ[0,10000]  Area end point Y value [0,10000] */
}NETDEV_PTZ_OPERATEAREA_S, *LPNETDEV_PTZ_OPERATEAREA_S;

/**
 * @struct tagNETDEVPictureData
 * @brief ͼ������ �ṹ�嶨�� Image data Structure definition
 *        ��Ž����ͼ�����ݵ�ָ��ͳ��ȵ���Ϣ Storing pointer and length of decoded picture data
 * @attention �� None
 */
typedef struct tagNETDEVPictureData
{
    BYTE    *pucData[4];                /* pucData[0]:Y ƽ��ָ��,pucData[1]:U ƽ��ָ��,pucData[2]:V ƽ��ָ��  pucData[0]: Y plane pointer, pucData[1]: U plane pointer, pucData[2]: V plane pointer */
    INT32   dwLineSize[4];              /* ulLineSize[0]:Yƽ��ÿ�п��, ulLineSize[1]:Uƽ��ÿ�п��, ulLineSize[2]:Vƽ��ÿ�п��  ulLineSize[0]: Y line spacing, ulLineSize[1]: U line spacing, ulLineSize[2]: V line spacing */
    INT32   dwPicHeight;                /* ͼƬ�߶�  Picture height */
    INT32   dwPicWidth;                 /* ͼƬ���  Picture width */
    INT32   dwRenderTimeType;           /* ������Ⱦ��ʱ����������  Time data type for rendering */
    INT64   tRenderTime;                /* ������Ⱦ��ʱ������  Time data for rendering */
}NETDEV_PICTURE_DATA_S, *LPNETDEV_PICTURE_DATA_S;

/**
 * @struct tagNETDEVWaveData
 * @brief ��Ƶ���� �ṹ�嶨�� Audio data Structure definition
 *        ��Ž������Ƶ���ݵ�ָ��ͳ��ȵ���Ϣ Storing pointer and length of decoded picture data
 * @attention �� None
 */
typedef struct tagNETDEVWaveData
{
    CHAR  *pcData;                      /* ��Ƶ����ָ��  Audio data pointer */
    INT32 dwDataLen;                    /* ��Ƶ���ݳ���  Audio data length */
    INT32 dwWaveFormat;                 /* �������Ƶ��ʽ  Format of decoded audio*/
}NETDEV_WAVE_DATA_S, *LPNETDEV_WAVE_DATA_S;

/**
 * @struct tagNETDEVParseVideoData
 * @brief ��Ƶ�������� �ṹ�嶨�� Video analytic data Structure definition
 *        ���ƴ֡����Ƶ���ݵ�ָ��ͳ��ȵ���Ϣ Storing pointer and length of framed video data
 * @attention �� None
 */
typedef struct tagNETDEVParseVideoData
{
    BYTE   *pucData;             /* ��Ƶ����ָ��  Pointer to video data */
    INT32  dwDataLen;            /* ��Ƶ���ݳ���  Video data length */
    INT32  dwVideoFrameType;     /* ��Ƶ֡����,�ο�ö��#NETDEV_VIDEO_FRAME_TYPE_E  Frame type, see enumeration #NETDEV_VIDEO_FRAME_TYPE_E */
    INT32  dwVideoCodeFormat;    /* ��Ƶ�����ʽ,�ο�ö��#NETDEV_VIDEO_CODE_TYPE_E  Video encoding format, see enumeration #NETDEV_VIDEO_CODE_TYPE_E */
    INT32  dwHeight;             /* ��Ƶͼ��߶�  Video image height */
    INT32  dwWidth;              /* ��Ƶͼ����  Video image width */
    INT64  tTimeStamp;           /* ʱ��������룩  Time stamp (ms) */
    BYTE  byRes[8];              /* �����ֶ�  Reserved field*/
}NETDEV_PARSE_VIDEO_DATA_S, *LPNETDEV_PARSE_VIDEO_DATA_S;


/**
 * @struct tagNETDEVVideoChlDetailInfo
 * @brief ��Ƶͨ����ϸ��Ϣ �ṹ�嶨��  Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVVideoChlDetailInfo
{
    INT32                       dwChannelID;            /* ͨ��ID  Channel ID */
    INT32                       dwType;                 /* �����ֶ�  Reserved field*/
    NETDEV_CHANNEL_STATUS_E     enStatus;               /* ͨ��״̬  Channel status */
    INT32                       dwStreamNum;            /* ������  Number of streams */
    BYTE                        byRes[68];              /* �����ֶ�  Reserved field*/
}NETDEV_VIDEO_CHL_DETAIL_INFO_S, *LPNETDEV_VIDEO_CHL_DETAIL_INFO_S;

/**
 * @struct tagNETDEVVideoStreamInfo
 * @brief ͨ����Ƶ����Ϣ �ṹ�嶨�� Channel video stream information Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVVideoStreamInfo
{
    NETDEV_LIVE_STREAM_INDEX_E  enStreamType;       /* ��������  Stream index */
    INT32                       bEnableFlag;        /* �Ƿ�����  Enable or not */
    INT32                       dwHeight;           /* ��Ƶ����ֱ���-Height  Video encoding resolution - Height */
    INT32                       dwWidth;            /* ��Ƶ����ֱ���-Width  Video encoding resolution - Width */
    INT32                       dwFrameRate;        /* ��Ƶ��������֡��  Video encoding configuration frame rate */
    INT32                       dwBitRate;          /* ����  Bit rate */
    NETDEV_VIDEO_CODE_TYPE_E    enCodeType;         /* ��Ƶ�����ʽ  Video encoding format */
    NETDEV_VIDEO_QUALITY_E      enQuality;          /* ͼ������  Image quality */
    INT32                       dwGop;              /* I֡���  I-frame interval */
    BYTE                        byRes[32];          /* �����ֶ�  Reserved */
}NETDEV_VIDEO_STREAM_INFO_S, *LPNETDEV_VIDEO_STREAM_INFO_S;


/**
 * @struct tagNETDEVLogFindCond
 * @brief ��־��ѯ���� �ṹ�嶨�� Log query condition Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVLogFindCond
{
    NETDEV_LOG_MAIN_TYPE_E      enMainType;         /* ������  Main type */
    NETDEV_LOG_SUBTYPE_ID_E     enSubType;          /* ������  Sub type */
    INT64                       tBeginTime;         /* ��ʼʱ��  Start time */
    INT64                       tEndTime;           /* ����ʱ��  End time */
}NETDEV_LOG_FIND_COND_S, *LPNETDEV_LOG_FIND_COND_S;

/***************** �澯ҵ��  Alarm services**************************************************/
/**
 * @struct tagNETDEVAlarmInfo
 * @brief �澯��Ϣ �ṹ�嶨�� Alarm information Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVAlarmInfo
{
    INT32   dwAlarmType;        /* �澯����,�μ�ö��#NETDEV_ALARM_TYPE_E  Alarm type, see enumeration #NETDEV_ALARM_TYPE_E */
    INT64   tAlarmTime;         /* �澯����ʱ��  Alarm time */
    INT32   dwChannelID;        /* ͨ����,����NVR  Channel number for NVR */
    UINT16  wIndex;             /* ������,�����������Ż���̲�λ������  Index number, alarm input/output index number or disk slot index number */
    BYTE    byRes[26];          /* �����ֶ�  Reserved */
}NETDEV_ALARM_INFO_S, *LPNETDEV_ALARM_INFO_S;

/**
 * @struct tagNETDEVPullAlarmInfo
 * @brief  ���澯��Ϣ �ṹ�嶨�� Get alarm information Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVPullAlarmInfo
{
    NETDEV_ALARM_TYPE_E   enAlarm;         /* �澯����  Alarm type */
    INT32   dwChancelId;                   /* ͨ����,����NVR  Channel number for NVR */
}NETDEV_PULLALARM_INFO_S, *LPNETDEV_PULLALARM_INFO_S;

/*********************** ����������  Boolean configuration***************************** */

/**
 * @struct tagNETDEVAlarmInputInfo
 * @brief  �澯������������Ϣ �ṹ�嶨��  Alarm boolean inputs info Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVAlarmInputInfo
{
    CHAR  szName[NETDEV_LEN_64];                                                  /* ���뿪��������   Name of input alarm */
}NETDEV_ALARM_INPUT_INFO_S, *LPNETDEV_ALARM_INPUT_INFO_S;

/**
 * @struct tagNETDEVAlarmInputInfoList
 * @brief  ���и澯������������Ϣ �ṹ�嶨��  All Alarm boolean inputs info Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVAlarmInputInfoList
{
    INT32                        dwSize;                                           /* ���뿪��������  Number of input alarms */
    NETDEV_ALARM_INPUT_INFO_S    astAlarmInputInfo[NETDEV_MAX_ALARM_IN_NUM];       /* ���뿪����������Ϣ  Configuration information of input alarms */
}NETDEV_ALARM_INPUT_LIST_S, *LPNETDEV_ALARM_INPUT_LIST_S;

/**
 * @struct tagNETDEVAlarmOutputInfo
 * @brief  �澯�����������Ϣ �ṹ�嶨�� Alarm boolean outputs info Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVAlarmOutputInfo
{   
    CHAR    szName[NETDEV_LEN_64];                  /* ����������  Boolean name */
    INT32   dwChancelId;                            /* ͨ���� Channel number */
    INT32   enDefaultStatus;                        /* ���������Ĭ��״̬ �μ�#NETDEV_BOOLEAN_MODE_E  Default status of boolean output, see enumeration #NETDEV_BOOLEAN_MODE_E */
    INT32   dwDurationSec;                          /* �澯����ʱ�� ��λ S  Alarm duration (s) */
} NETDEV_ALARM_OUTPUT_INFO_S, *LPNETDEV_ALARM_OUTPUT_INFO_S;

/**
 * @struct tagNETDEVAlarmOutputList
 * @brief  ���и澯������������Ϣ �ṹ�嶨�� All Alarm boolean outputs info Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVAlarmOutputList
{   
    INT32                       dwSize;                                                 /* ����������   Number of booleans  */
    NETDEV_ALARM_OUTPUT_INFO_S  astAlarmOutputInfo[NETDEV_MAX_ALARM_OUT_NUM];           /* ������������Ϣ  Boolean configuration information */
} NETDEV_ALARM_OUTPUT_LIST_S, *LPNETDEV_ALARM_OUTPUT_LIST_S;

/**
 * @struct tagNETDEVTriggerAlarmOutput
 * @brief  ��������������澯 �ṹ�嶨�� Trigger boolean output alarm Structure definition
 * @attention �� None
 */
typedef struct tagNETDEVTriggerAlarmOutput
{   
    CHAR                        szName[NETDEV_LEN_64];          /* ����������  Boolean name */
    NETDEV_RELAYOUTPUT_STATE_E  enOutputState;                  /* ����״̬,�ο�ö��#NETDEV_RELAYOUTPUT_STATE_E  Trigger status, see enumeration #NETDEV_RELAYOUTPUT_STATE_E */
} NETDEV_TRIGGER_ALARM_OUTPUT_S, *LPNETDEV_TRIGGER_ALARM_OUTPUT_S;

/************************************************ OSD********************************************************/

/**
 * @struct tagNETDEVAreaScope
 * @brief  ���� Area
 * @attention �� None
 */
typedef struct tagNETDEVAreaScope
{
    INT32  dwLocateX;             /** ����x����ֵ[0,10000] * Coordinates of top point x [0,10000] */
    INT32  dwLocateY;             /** ����y����ֵ[0,10000] * Coordinates of top point y [0,10000] */
}NETDEV_AREA_SCOPE_S, *LPNETDEV_AREA_SCOPE_S;

/**
 * @struct tagNETDEVOsdTime
 * @brief OSDʱ��������Ϣ OSD time configuration information
 * @attention �� None
 */
typedef struct tagNETDEVOsdTime
{
    BOOL                    bEnableFlag;        /** ʱ��OSDʹ��, BOOL_TRUEΪʹ��,BOOL_FALSEΪ��ʹ�� * Enable time OSD, BOOL_TRUE means enable and BOOL_FALSE means disable */
    BOOL                    bWeekEnableFlag;    /** �Ƿ���ʾ����(Ԥ��) * Display week or not (reserved) */
    NETDEV_AREA_SCOPE_S     stAreaScope;        /** �������� * Area coordinates */
    UINT32                  udwTimeFormat;      /** ʱ��OSDʱ���ʽ,���NETDEV_OSD_TIME_FORMAT_E * Time OSD format, see NETDEV_OSD_TIME_FORMAT_E */
    UINT32                  udwDateFormat;      /** ����OSDʱ���ʽ,���NETDEV_OSD_DATE_FMT_E * Date OSD format, see NETDEV_OSD_TIME_FORMAT_E */

}NETDEV_OSD_TIME_S, *LPNETDEV_OSD_TIME_S;

/**
 * @struct tagNETDEVOsdTextOverlay
 * @brief OSD�ַ�������Ϣ OSD text overlay information
 * @attention
 */
typedef struct tagNETDEVOsdTextOverlay
{
    BOOL                    bEnableFlag;                /** OSD�ַ�����ʹ��, BOOL_TRUEΪʹ��,BOOL_FALSEΪ��ʹ�� * Enable OSD text overlay, BOOL_TRUE means enable and BOOL_FALSE means disable */
    NETDEV_AREA_SCOPE_S     stAreaScope;                /** OSD�ַ������������� * OSD text overlay area coordinates */
    CHAR                    szOSDText[NETDEV_OSD_TEXT_MAX_LEN];    /** OSD�ַ����������ַ��� * OSD text overlay name strings */
    BYTE                    byRes[4];                               /* �����ֶ�  Reserved */
}NETDEV_OSD_TEXT_OVERLAY_S, *LPNETDEV_OSD_TEXT_OVERLAY_S;

/**
 * @struct tagNETDEVOsdCfgInfo
 * @brief ͨ��OSD�Ļ���������Ϣ Basic channel OSD information
 * @attention
 */
typedef struct tagNETDEVOsdCfgInfo
{
    NETDEV_OSD_TIME_S         stTimeOSD;        /* ͨ����ʱ��OSD��Ϣ  Information of channel time OSD */
    NETDEV_OSD_TEXT_OVERLAY_S stNameOSD;        /* ͨ��������OSD��Ϣ  Information of channel name OSD */
    INT16                     wTextNum;         /* �ַ�OSD����  Text OSD number */
    NETDEV_OSD_TEXT_OVERLAY_S astTextOverlay[NETDEV_OSD_TEXTOVERLAY_NUM];   /* ͨ��OSD�ַ�������Ϣ  Information of channel OSD text overlay */
}NETDEV_VIDEO_OSD_CFG_S, *LPNETDEV_VIDEO_OSD_CFG_S;

/**
 * @struct tagAreaInfo
 * @brief �������ýṹ�嶨�� Definition of area configuration structure 
 * @attention
 */
typedef struct tagAreaInfo
{
    INT32   bIsEanbled;           /* �Ƿ�����  Enable or not. */
    INT32   dwTopLeftX;           /* ���Ͻ�X [0, 10000]  Upper left corner X [0, 10000]  */
    INT32   dwTopLeftY;           /* ���Ͻ�Y [0, 10000]  Upper left corner Y [0, 10000]  */
    INT32   dwBottomRightX;       /* ���½�X [0, 10000]  Lower right corner x [0, 10000] */
    INT32   dwBottomRightY;       /* ���½�Y [0, 10000]  Lower right corner y [0, 10000] */
    INT32   dwIndex;              /* ����  Index. */
}NETDEV_PRIVACY_MASK_AREA_INFO_S;

/**
 * @struct tagPrivacyMaskPara
 * @brief ��˽�ڸ�������Ϣ Privacy mask configuration information
 * @attention
 */
typedef struct tagPrivacyMaskPara
{
    INT32                                  dwSize;                                     /* �������  Mask area number */ 
    NETDEV_PRIVACY_MASK_AREA_INFO_S        astArea[NETDEV_MAX_PRIVACY_MASK_AREA_NUM];  /* �ڸ��������  Mask area parameters */
}NETDEV_PRIVACY_MASK_CFG_S, *LPNETDEV_PRIVACY_MASK_CFG_S;

/************************************************ ��Ƶ����********************************************************/

/**
 * @struct tagNETDEVTamperAlarmInfo
 * @brief �ڵ���������Ϣ
 * @attention �� None
 */
typedef struct tagNETDEVTamperAlarmInfo
{
    INT32  dwSensitivity;                               /* ������  Sensitivity */
    BYTE   byRes[256];                                  /* �����ֶ�  Reserved */
}NETDEV_TAMPER_ALARM_INFO_S, *LPNETDEV_TAMPER_ALARM_INFO_S;

/**
 * @struct tagNETDEVMotionAlarmInfo
 * @brief �˶���������Ϣ
 * @attention �� None
 */
typedef struct tagNETDEVMotionAlarmInfo
{
    INT32  dwSensitivity;                                                     /* ������  Sensitivity */
    INT32  dwObjectSize;                                                      /* �����С  Objection Size */
    INT32  dwHistory;                                                         /* ����ʱ��  History */
    INT16  awScreenInfo[NETDEV_SCREEN_INFO_ROW][NETDEV_SCREEN_INFO_COLUMN];   /* ��Ļ�����Ϣ  Screen Info */
    BYTE   byRes[64];                                                         /* �����ֶ�  Reserved */
}NETDEV_MOTION_ALARM_INFO_S, *LPNETDEV_MOTION_ALARM_INFO_S;

/**
 * @struct tagNETDEVUpnpPortState
 * @brief Э����Ϣ  Protocol info
 * @attention �� None
 */
typedef struct tagNETDEVUpnpPortState
{
    NETDEV_PROTOCOL_TYPE_E   eType;                            /* Э�����Ͳμ�ö��#NETDEV_PROTOCOL_TYPE_E  Protocol type, see enumeration #NETDEV_PROTOCOL_TYPE_E */
    BOOL                     bEnbale;                          /* �Ƿ�֧��  Supported or not */
    INT32                    dwPort;                           /* �˿ں�  Port number */
    BYTE                     byRes[128];                       /* �����ֶ�  Reserved */
}NETDEV_UPNP_PORT_STATE_S, *LPNETDEV_UPNP_PORT_STATE_S;


/**
 * @struct tagNETDEVUpnpNatState
 * @brief Э����Ϣ�б�  Protocol info list
 * @attention �� None
 */
typedef struct tagNETDEVUpnpNatState
{
    INT32   dwSize;                                            /* Э�����  Number of protocols */
    NETDEV_UPNP_PORT_STATE_S  astUpnpPort[NETDEV_LEN_16];      /* Э����Ϣ  Protocol info */
}NETDEV_UPNP_NAT_STATE_S, *LPNETDEV_UPNP_NAT_STATE_S;


/**
 * @struct tagNetDEVDiscoveryDevInfo
 * @brief �豸���ֵ��豸��Ϣ  Info of discovered device
 * @attention �� None
 */
typedef struct tagNetDEVDiscoveryDevInfo
{
    CHAR    szDevAddr[NETDEV_LEN_64];                            /* �豸��ַ  Device address */
    CHAR    szDevModule[NETDEV_LEN_64];                          /* �豸�ͺ�  Device model */
    CHAR    szDevSerailNum[NETDEV_LEN_64];                       /* �豸���к�  Device serial number */
    CHAR    szDevMac[NETDEV_LEN_64];                             /* �豸MAC��ַ  Device MAC address */
    CHAR    szDevName[NETDEV_LEN_64];                            /* �豸����  Device name */
    CHAR    szDevVersion[NETDEV_LEN_64];                         /* �豸�汾  Device version */
    NETDEV_DEVICETYPE_E  enDevType;                              /* �豸����  Device type */
    INT32   dwDevPort;                                           /* �豸�˿ں�  Device port number */
    BYTE    byRes[NETDEV_LEN_260];                               /* �����ֶ�  Reserved */
}NETDEV_DISCOVERY_DEVINFO_S, *LPNETDEV_DISCOVERY_DEVINFO_S;

/**
* @struct tagNETDEVTime
* @brief ʱ����� �ṹ�嶨�� Time parameter Structure definition
* @attention �� None
*/
typedef struct tagNETDEVTime
{
    INT32   dwYear;                       /* ��  Year */
    INT32   dwMonth;                      /* ��  Month */
    INT32   dwDay;                        /* ��  Day */
    INT32   dwHour;                       /* ʱ  Hour */
    INT32   dwMinute;                     /* ��  Minute */
    INT32   dwSecond;                     /* ��  Second */
}NETDEV_TIME_S, *LPNETDEV_TIME_S;

/**
* @struct tagNETDEVSystemTimeInfo
* @brief ʱ������ �ṹ�嶨�� Time configuration structure definition
* @attention
*/
typedef struct tagNETDEVSystemTimeInfo
{
    NETDEV_TIME_ZONE_E   dwTimeZone;                  /* ʱ�� �μ�ö��#NETDEV_TIME_ZONE_E  Time zone, see enumeration #NETDEV_TIME_ZONE_E */
    NETDEV_TIME_S        stTime;                      /* ʱ��  Time */
    BYTE                 byRes[260];                  /* �����ֶ�  Reserved */
}NETDEV_TIME_CFG_S, *LPNETDEV_TIME_CFG_S;

/* END************************************************ �ṹ��************************************************** */


/**
* ƴ֡ǰý�������ݻص�������ָ������  Type of pointer to media stream data callback function before being framed 
* @param [IN] lpRealHandle      ��ǰ��ʵ�����ž�� Current live playing handle
* @param [IN] pucBuffer         ���ƴ֡ǰý�������ݻ�����ָ�� Pointer to buffer that stores stream data that is not framed
* @param [IN] dwBufSize         ��������С Buffer size
* @param [IN] dwMediaDataType   ý����������,�μ�ý������ö�ٶ���#NETDEV_MEDIAFORMAT_E Media data type, see definitions of enumeration #NETDEV_MEDIA_DATA_TYPE_E
* @param [IN] lpUserParam       �û����ò���,���û��ڵ���#NDPlayer_SetSourceMediaDataCB����ʱָ�����û����� User-set parameters, specified by users when they call the #NDPlayer_SetSourceMediaDataCB function
* @return �ޡ� None.
* @note  �û�Ӧ��ʱ���������ý��������,ȷ���������췵��,�����Ӱ�첥�����ڵ�ý�������� Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL *NETDEV_SOURCE_DATA_CALLBACK_PF)(IN LPVOID        lpRealHandle,
                                                       IN const BYTE    *pucBuffer,
                                                       IN INT32         dwBufSize,
                                                       IN INT32         dwMediaDataType,
                                                       IN LPVOID        lpUserParam
                                                       );

/**
* ƴ֡����Ƶ�����ݻص�������ָ������  Type of pointer to callback function for framed stream data 
* @param [IN] lpRealHandle          ��ǰ��ʵ�����ž�� Current live playing handle
* @param [IN] pstParseVideoData     ���ƴ֡����Ƶ��������Ϣ������ָ�� Pointer to buffer that stores framed video stream data
* @param [IN] lUserParam            �û����ò���,���û��ڵ���#NDPlayer_SetParseVideoDataCB����ʱָ�����û����� User-set parameters, specified by users when they call the #NDPlayer_SetParseVideoDataCB function
* @return �ޡ� None.
* @note
* -     �û�Ӧ��ʱ�������������,ȷ���������췵��,�����Ӱ�첥�����ڵ�ý�������� Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL *NETDEV_PARSE_VIDEO_DATA_CALLBACK_PF)(IN LPVOID lpRealHandle,
                                                            IN const NETDEV_PARSE_VIDEO_DATA_S *pstParseVideoData,
                                                            IN LPVOID lpUserParam
                                                            );

/**
* �������Ƶ�����ݻص�������ָ������  Type of pointer to callback function for decoded video stream data 
* @param [IN] lpRealHandle      ��ǰ��ʵ�����ž�� Current live playing handle
* @param [IN] pstPictureData    ��Ž������Ƶ��������Ϣ������ָ�� Pointer to buffer that stores decoded video stream data
* @param [IN] lpUserParam       �û����ò���,���û��ڵ���#NDPlayer_SetDecodeVideoDataCB����ʱָ�����û����� User-set parameters, specified by users when they call the #NDPlayer_SetDecodeVideoDataCB function
* @return �ޡ� None.
* @note
* -     1���û�Ӧ��ʱ�����������Ƶ������,ȷ���������췵��,�����Ӱ�첥�����ڵ�ý��������
* -     1. Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
* -     2����Ƶ������yv12��ʽ������˳��Y0-Y1-......��,��U0-U1-......��,��V0-V1-......��
* -     2. Video data is in yv12 format in sequence of Y0-Y1-......, U0-U1-......, V0-V1-......
*/
typedef void (STDCALL* NETDEV_DECODE_VIDEO_DATA_CALLBACK_PF)(IN LPVOID lpRealHandle,
                                                             IN const NETDEV_PICTURE_DATA_S *pstPictureData,
                                                             IN LPVOID lpUserParam
                                                             );

/**
* �������Ƶ�����ݻص�������ָ������  Type of pointer to callback function for decoded audio stream data 
* @param [IN] lpRealHandle   ��ǰ��ʵ�����ž�� Current live playing handle
* @param [IN] pstWaveData    ��Ž������Ƶ��������Ϣ������ָ�� Pointer to buffer that stores decoded audio stream data
* @param [IN] lpUserParam    �û����ò���,���û��ڵ���#NDPlayer_SetDecodeAudioDataCB����ʱָ�����û����� User-set parameters, specified by users when they call the #NDPlayer_SetDecodeAudioDataCB function
* @return �ޡ� None.
* @note
* -     �û�Ӧ��ʱ�����������Ƶ������,ȷ���������췵��,�����Ӱ�첥�����ڵ�ý��������
* -     Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL* NETDEV_DECODE_AUDIO_DATA_CALLBACK_PF)(IN LPVOID lpRealHandle,
                                                             IN const NETDEV_WAVE_DATA_S *pstWaveData,
                                                             IN LPVOID lpUserParam
                                                             );

/**
* ��ʾ���ݻص�������ָ������ Type of pointer to display data callback function
* @param [IN] lpHandle       ��ǰ��ʵ�����ž�� Current live playing handle
* @param [IN] hdc            ��ʾ�����hdc,�û����������hdc ��ͼ Display superficial hdc which can be used for drawing graphics.
* @param [IN] lpUserParam    �û����ò���,���û��ڵ���#NETDEV_SetPlayDisplayCB����ʱָ�����û����� User-set parameters, specified by users when they call the #NETDEV_SetPlayDisplayCB
* @return �ޡ�
* @note
* -     �û�Ӧ��ʱ�����������Ƶ������,ȷ���������췵��,�����Ӱ�첥�����ڵ�ý��������
* -     Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL* NETDEV_DISPLAY_CALLBACK_PF)(IN LPVOID lpHandle,
                                                   IN LPVOID hdc,
                                                   IN LPVOID lpUserParam
                                                   );

/**
* ���ո澯��Ϣ�Ļص�����  Callback function to receive alarm information
* @param [IN] lpUserID              �û���¼ID User login ID
* @param [IN] dwChannelID           ͨ���� Channel number
* @param [IN] NETDEV_ALARM_INFO_S   �澯��Ϣ Alarm information
* @param [IN] lpBuf                 ������ָ�� Pointer to buffer
* @param [IN] dwBufLen              �澯��Ϣ��Ӧ�ṹ��ĳ��� Length of structure for alarm information
* @param [IN] dwBufLen              �û����� User data
* @note
*/
typedef void(STDCALL *NETDEV_AlarmMessCallBack_PF)(IN LPVOID    lpUserID,
                                                   IN INT32     dwChannelID,
                                                   IN NETDEV_ALARM_INFO_S   stAlarmInfo,
                                                   IN LPVOID    lpBuf,
                                                   IN INT32     dwBufLen,
                                                   IN LPVOID    lpUserData
                                                   );

/**
* �����쳣����������Ϣ�Ļص�����  Callback function to receive exception and reconnection messages
* @param [IN] lpUserID     �û���¼ID User login ID
* @param [IN] dwType       �쳣����������Ϣ������:NETDEV_EXCEPTION_TYPE_E Type of exception or reconnection message: NETDEV_EXCEPTION_TYPE_E
* @param [IN] lpExpHandle  �����쳣����Ӧ���͵ľ�� Exception type handle
* @param [IN] lpUserData   �û����� User data
* @note
*/
typedef void(STDCALL *NETDEV_ExceptionCallBack_PF)(IN LPVOID    lpUserID,
                                                   IN INT32     dwType,
                                                   IN LPVOID    lpExpHandle,
                                                   IN LPVOID    lpUserData
                                                   );

/**
* ע��ص�����,���ձ�����Ϣ�ȣ�ͬʱ�ص���¼ID,�������ֲ�ͬ�豸�� Register callback function and receive alarm information, etc. (Call back login ID at the same time to distinguish different devices)\n
* @param [IN] lpUserID              �û���¼ID User login ID
* @param [IN] cbAlarmMessCallBack   �ص����� Callback function
* @param [IN] lpUserData            �û����� User data
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetAlarmCallBack(IN LPVOID lpUserID,
                                                             IN NETDEV_AlarmMessCallBack_PF cbAlarmMessCallBack,
                                                             IN LPVOID lpUserData
                                                             );

/**
* ע��sdk�����쳣����������Ϣ�Ļص�����  Callback function to register SDK, receive exception and reconnection messages, etc.
* @param [IN] cbExceptionCallBack       �����쳣��Ϣ�Ļص�����,�ص���ǰ�쳣�������Ϣ Callback function to receive exception messages, used to call back information about current exceptions
* @param [IN] lpUserData                �û����� User data
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetExceptionCallBack(IN NETDEV_ExceptionCallBack_PF cbExceptionCallBack,
                                                                 IN LPVOID lpUserData
                                                                 );

/**
* �豸���ֻص�����
* @param [IN] pstDevInfo                �豸��Ϣ
* @param [IN] lpUserData                �û����� User data
* @note
*/
typedef void(STDCALL *NETDEV_DISCOVERY_CALLBACK_PF)(IN LPNETDEV_DISCOVERY_DEVINFO_S pstDevInfo,
                                                    IN LPVOID lpUserData
                                                    );

/**
* ע���豸���ֻص�����
* @param [IN] cbDiscoveryCallBack   �ص����� Callback function
* @param [IN] lpUserData            �û����� User data
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetDiscoveryCallBack(IN NETDEV_DISCOVERY_CALLBACK_PF cbDiscoveryCallBack,
                                                                 IN LPVOID lpUserData
                                                                 );

/**
* �豸���� ��ע���豸������صĻص�,�ٵ��ô˽ӿڷ����豸,���ֵ��豸��Ϣ�ڻص��з�ӳ
* This interface is used for device discovery. Please first register callback functions related to device discovery and use this interface for device discovery. Discovered device info will be included in the callback function.
* @param [IN]   pszBeginIP                 ��ʼIP��ַ
* @param [IN]   pszEndIP                   ����IP��ַ
* @return TRUE��ʾ�ɹ�,������ʾʧ��
* @note ��pszBeginIP��pszEndIP����"0.0.0.0",�������������豸
*/
NETDEV_API NEWINTERFACE BOOL  STDCALL NETDEV_Discovery(IN CHAR *pszBeginIP,
                                                       IN CHAR *pszEndIP
                                                       );

/**
* SDK ��ʼ��  SDK initialization
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note �̲߳���ȫ Thread not safe
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Init(void);

/**
* SDK ����  SDK cleaning
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Cleanup(void);

/**
* ��ȡSDK�İ汾��Ϣ Get SDK version information 
* @return SDK�汾��Ϣ SDK version information
* @note
* - 2�����ֽڱ�ʾ���汾,2�����ֽڱ�ʾ�ΰ汾����0x00030000����ʾ�汾Ϊ3.0��
* - The two high bytes indicate the major version, and the two low bytes indicate the minor version. For example, 0x00030000 means version 3.0.
*/
NETDEV_API NEWINTERFACE INT32 STDCALL NETDEV_GetSDKVersion(void);



/**
* �û���¼  User login
* @param [IN]  pszDevIP         �豸IP Device IP
* @param [IN]  wDevPort         �豸�������˿� Device server port
* @param [IN]  pszUserName      �û��� Username
* @param [IN]  pszPassword      ���� Password
* @param [OUT] pstDevInfo       �豸��Ϣ�ṹ��ָ�� Pointer to device information structure
* @return ���ص��û���¼ID,���� 0 ��ʾʧ��,����ֵ��ʾ���ص��û�IDֵ�� Returned user login ID. 0 indicates failure, and other values indicate the user ID.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_Login(IN char *pszDevIP,
                                                    IN INT16 wDevPort,
                                                    IN char *pszUserName,
                                                    IN char *pszPassword,
                                                    OUT LPNETDEV_DEVICE_INFO_S pstDevInfo
                                                    );

/**
* �û�ע��  User logout
* @param [IN] lpUserID    �û���¼ID User login ID
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Logout(IN LPVOID lpUserID);

/**
* ��ѯͨ��������  Query channel capabilities
* @param [IN]    lpUserID           �û���¼ID User login ID
* @param [INOUT] pdwChlCount        ͨ���� Number of channels
* @param [OUT]   pstVideoChlList    ͨ���������б� List of channel capabilities
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_QueryVideoChlDetailList(IN LPVOID   lpUserID,
                                                                    INOUT INT32 *pdwChlCount,
                                                                    OUT LPNETDEV_VIDEO_CHL_DETAIL_INFO_S pstVideoChlList
                                                                    );


/*************** Beginʵ��ҵ��  Begin live view services*********************************************/

/**
* ����ʵʱԤ��  Start live preview
* @param [IN]  lpUserID             �û���¼ID User login ID
* @param [IN]  pstPreviewInfo       Ԥ������,�ο�ö�٣�NETDEV_PROTOCAL_E,NETDEV_LIVE_STREAM_INDEX_E�� Preview parameter, see enumeration: NETDEV_PROTOCAL_E, NETDEV_LIVE_STREAM_INDEX_E.
* @param [IN]  cbRealDataCallBack   �������ݻص�����ָ�� Pointer to callback function of stream data
* @param [IN]  lpUserData           �û����� User data
* @return ���ص��û���¼ID,���� 0 ��ʾʧ��,����ֵ��ʾ���ص��û�IDֵ�� Returned user login ID. 0 indicates failure, and other values indicate the user ID.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_RealPlay(IN LPVOID lpUserID,
                                                       IN LPNETDEV_PREVIEWINFO_S pstPreviewInfo,
                                                       IN NETDEV_SOURCE_DATA_CALLBACK_PF cbPlayDataCallBack,
                                                       IN LPVOID lpUserData
                                                       );

/**
* ֹͣʵʱԤ��  Stop live preview
* @param [IN]  lpRealHandle     Ԥ����� Preview handle
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note ��Ӧ�ر�NETDEV_RealPlay������ʵ�� Stop the live view started by NETDEV_RealPlay
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopRealPlay(IN LPVOID lpRealHandle);

/**
* ����¼��  Local recording
* @param [IN]  lpRealHandle         Ԥ����� Preview handle
* @param [IN]  pszSaveFileName      ������ļ��� Name of saved file
* @param [IN]  dwFormat             Format of saved file, see #NETDEV_MEDIA_FILE_FORMAT_E 
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SaveRealData(IN LPVOID  lpRealHandle,
                                                         IN CHAR    *pszSaveFileName,
                                                         IN INT32   dwFormat
                                                         );

/**
* ֹͣ����¼�� Stop local recording
* @param [IN]  lpRealHandle     Ԥ����� Preview handle
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopSaveRealData(IN LPVOID lpRealHandle);

/**
* ��������  Enable sound
* @param [IN]  lpRealHandle   Ԥ����� Preview handle
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_OpenSound(IN LPVOID lpRealHandle);

/**
* ��������������
* @param [IN]  lpRealHandle   Ԥ����� Preview handle
* @param [IN]  dwVolume       ���� Volume
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SoundVolumeControl(IN LPVOID lpRealHandle, 
                                                               IN INT32 dwVolume
                                                               );

/**
* �ر����� Mute
* @param [IN]  lpRealHandle   Ԥ����� Preview handle
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_CloseSound(IN LPVOID lpRealHandle);


/**
* ��ȡ��������  Get window bit rate
* @param [IN]  lpPlayHandle     Ԥ��\�طž�� Preview\playback handle
* @param [OUT] pdwBitRate       ��ȡ������ָ�� Pointer to obtained bit rate
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetBitRate(IN LPVOID lpPlayHandle,
                                                       OUT INT32 *pdwBitRate
                                                       );

/*
* ��ȡ����֡��  Get window frame rate
* @param [IN]  lpPlayHandle     Ԥ��\�طž�� Preview\playback handle
* @param [OUT] pdwFrameRate     ��ȡ��֡��ָ�� Pointer to obtained frame rate
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetFrameRate(IN LPVOID lpPlayHandle,
                                                         OUT INT32 *pdwFrameRate
                                                         );

/**
* ��ȡ���ڱ����ʽ  Get window encoding format
* @param [IN]  lpPlayHandle         Ԥ��\�طž�� Preview\playback handle
* @param [OUT] pdwVideoEncFmt       ��ȡ����Ƶ�����ʽָ�� Pointer to obtained encoding format
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetVideoEncodeFmt(IN LPVOID lpPlayHandle,
                                                              OUT INT32 *pdwVideoEncFmt
                                                              );


/**
* ��ȡ��Ƶ�ֱ���  Get video resolution
* @param [IN]  lpPlayHandle     Ԥ��\�طž�� Preview\playback handle
* @param [OUT] pdwWidth         ��ȡ�ķֱ���-���ָ�� Pointer to obtained resolution �C width
* @param [OUT] pdwHeight        ��ȡ�ķֱ���-�߶�ָ�� Pointer to obtained resolution �C height
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetResolution(IN LPVOID lpPlayHandle,
                                                          OUT INT32 *pdwWidth,
                                                          OUT INT32 *pdwHeight
                                                          );

/**
* ��ȡ���ڶ�����  Get window packet loss rate
* @param [IN]  lpPlayHandle     Ԥ��\�طž�� Preview\playback handle
* @param [OUT] pulRecvPktNum    ���յ����ݰ�����ָ�� Pointer to number of received packets
* @param [OUT] pulLostPktNum    ��ʧ�����ݰ�����ָ�� Pointer to number of lost packets
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetLostPacketRate(IN LPVOID lpPlayHandle,
                                                              OUT INT32 *pulRecvPktNum,
                                                              OUT INT32 *pulLostPktNum
                                                              );

/**
* ���ô��ڶ�����  Reset window packet loss rate
* @param [IN]  lpPlayHandle   Ԥ��\�طž�� Preview\playback handle
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ResetLostPacketRate(IN LPVOID lpPlayHandle);

/**
* ʵ��ץ��  Live view snapshot
* @param [IN]  lpPlayHandle     Ԥ��\�طž�� Preview\playback handle
* @param [IN]  pszFileName      ����ͼ����ļ�·���������ļ����� File path to save images (including file name)
* @param [IN]  dwCaptureMode    ����ͼ���ʽ,�μ�#NETDEV_PICTURE_FORMAT_E   Image saving format, see #NETDEV_PICTURE_FORMAT_E
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note �ļ����п��Բ�Я��ץ�ĸ�ʽ�ĺ�׺�� File format suffix is not required in the file name
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_CapturePicture(IN LPVOID    lpPlayHandle,
                                                           IN char      *pszFileName,
                                                           IN INT32     dwCaptureMode
                                                           );

/**
* ������Ƶͼ����ʾ����  Modify image display ratio
* @param [IN]  lpPlayHandle   Ԥ��\�طž�� Preview\playback handle
* @param [IN]  enRenderScale  ��Ƶͼ�����ʾ���� Image display ratio
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetRenderScale(IN LPVOID lpPlayHandle,
                                                           IN NETDEV_RENDER_SCALE_E enRenderScale
                                                           );

/**
* Ӱ�������ȡ,ֻ��ȡ��ǰ�������  Get the current image info
* @param [IN]  lpPlayHandle   Ԥ��\�طž�� Preview\playback handle
* @param [IN]  pstImageInfo   ͼ����Ϣ�б� Image information list
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetVideoEffect(IN LPVOID lpPlayHandle, 
                                                           OUT LPNETDEV_VIDEO_EFFECT_S pstImageInfo
                                                           );

/**
* Ӱ�����,ֻ�ı䵱ǰ����  Adjust the current image
* @param [IN]  lpPlayHandle   Ԥ��\�طž�� Preview\playback handle
* @param [IN]  pstImageInfo   ͼ����Ϣ�б� Image information list
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetVideoEffect(IN LPVOID lpPlayHandle, 
                                                           IN LPNETDEV_VIDEO_EFFECT_S pstImageInfo
                                                           );

/**
* �������ַŴ�  Set Digital zoom
* @param [IN] lpPlayHandle   Ԥ��\�طž�� Preview\playback handle
* @param [IN] hWnd           ���ھ��  window handle 
* @param [IN] pstRect        �������� Rectangle Area
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note pstRectΪ��ʱ,��ʾȫ������,���˳����ַŴ�
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetDigitalZoom(IN LPVOID          lpPlayHandle, 
                                                           IN LPVOID          hWnd,
                                                           IN LPNETDEV_RECT_S pstRect
                                                           );

/**
* ע�������ص�����:ԭʼ����  Callback function to register streams (original stream)
* @param [IN]  lpRealHandle               ʵʱԤ����� Live preview handle
* @param [IN]  cbSourceDataCallBack       �������ݻص����� Callback function for stream data
* @param [IN]  bContinue                  �Ƿ�������к����ƴ֡���������ʾ���� Whether to continue to following framing, decoding and displaying operations.
* @param [IN]  lpUser                     �û����� User data
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE  BOOL STDCALL NETDEV_SetPlayDataCallBack(IN LPVOID lpPlayHandle,
                                                                 IN NETDEV_SOURCE_DATA_CALLBACK_PF cbPlayDataCallBack,
                                                                 IN INT32 bContinue,
                                                                 IN LPVOID lpUser);

/**
* ע��ʵ�������ص�����:ƴ֡����������  Callback function to register live stream (framed stream data)
* @param [IN]  lpPlayHandle              Ԥ��\�طž�� Preview\playback handle
* @param [IN]  cbParsePlayDataCallBack   ���ݻص����� Data callback function
* @param [IN]  bContinue                 �Ƿ���� Continue or not
* @param [IN]  lpUserData                �û����� User data
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
* - ���رջص�����,���ڶ���������ΪNULL��
* - To shut the callback function, set the second parameter as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPlayParseCB(IN LPVOID    lpPlayHandle,
                                                           IN NETDEV_PARSE_VIDEO_DATA_CALLBACK_PF cbParsePlayDataCallBack,
                                                           IN INT32     bContinue,
                                                           IN LPVOID    lpUserData
                                                           );

/**
* ע��ʵʱ�����ص��������������Ƶý��������  Callback function to register live stream (decoded media stream data)
* @param [IN]  lpPlayHandle                 Ԥ��\�طž�� Preview\playback handle
* @param [IN]  cbPlayDecodeVideoCALLBACK    ���ݻص����� Data callback function
* @param [IN]  bContinue                    �Ƿ���� Continue or not
* @param [IN]  lpUserData                   �û����� User data
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
* - ���رջص�����,���ڶ���������ΪNULL��
* - To shut the callback function, set the second parameter as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPlayDecodeVideoCB(IN LPVOID  lpPlayHandle,
                                                                 IN NETDEV_DECODE_VIDEO_DATA_CALLBACK_PF cbPlayDecodeVideoCALLBACK,
                                                                 IN INT32   bContinue,
                                                                 IN LPVOID  lpUserData
                                                                 );

/**
* ������ʾ�����ݻص�  Modify displayed data callback
* @param [IN]  lpPlayHandle             Ԥ��\�طž�� Preview\playback handle
* @param [IN]  cbPlayDisplayCallBack    ���ݻص����� Data callback function
* @param [IN]  lpUserData               �û����� User data
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
* - ���رջص�����,���ڶ���������ΪNULL��
* - To shut the callback function, set the second parameter as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPlayDisplayCB(IN LPVOID lpPlayHandle,
                                                             IN NETDEV_DISPLAY_CALLBACK_PF cbPlayDisplayCallBack,
                                                             IN LPVOID lpUserData
                                                             );

/***************ʵ��ҵ�� live view service*************************************************/

/***************�ط�ҵ�� Begin playback service********************************************/

/**
* �����ļ����͡�ʱ������豸¼���ļ�  Query recording files according to file type and time
* @param [IN]  lpUserID     �û���¼ID User login ID
* @param [IN]  pstFindCond    ¼���ѯ���� Search condition
* @return ¼���ѯҵ���,����0��ʾʧ��,����ֵ��ΪNETDEV_FindClose�Ⱥ����Ĳ�����
Recording search service number. 0 means failure. Other values are used as the handle parameters of functions like NETDEV_FindClose.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindFile(IN LPVOID lpUserID,
                                                       IN LPNETDEV_FILECOND_S pstFindCond
                                                       );

/**
* �����ȡ���ҵ����ļ���Ϣ  Obtain the information of found files one by one.
* @param [IN]  lpFindHandle     �ļ����Ҿ�� File search handle
* @param [OUT] pstFindData       �����ļ���Ϣ��ָ�� Pointer to save file information
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note ����ʧ��˵����ѯ���� A returned failure indicates the end of search.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextFile(IN LPVOID lpFindHandle,
                                                         OUT LPNETDEV_FINDDATA_S pstFindData
                                                         );

/**
* �ر��ļ�����,�ͷ���Դ  Close file search and release resources
* @param [IN] lpFindHandle  �ļ����Ҿ�� File search handle
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindClose(IN LPVOID lpFindHandle);


/**
* �����ƻط�¼���ļ�  Play back recording files by name
* @param [IN] lpUserID          �û���¼ID User login ID
* @param [IN] pstPlayBackInfo   ¼��طŽṹ��ָ��,�ο� LPNETDEV_PLAYBACKINFO_S Pointer to recording playback structure, see LPNETDEV_PLAYBACKINFO_S
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NEWINTERFACE LPVOID STDCALL NETDEV_PlayBackByName(IN LPVOID lpUserID,
                                                  IN LPNETDEV_PLAYBACKINFO_S pstPlayBackInfo
                                                  );

/**
* ��ʱ��ط�¼���ļ�  Play back recording by time. 
* @param [IN] lpUserID          �û���¼ID User login ID
* @param [IN] pstPlayBackCond   ��ʱ��¼��طŽṹ��ָ��  �ο� LPNETDEV_PLAYBACKCOND_S Pointer to playback-by-time structure, see LPNETDEV_PLAYBACKCOND_S
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_PlayBackByTime(IN LPVOID lpUserID,
                                                             IN LPNETDEV_PLAYBACKCOND_S pstPlayBackInfo
                                                             );

/**
* ֹͣ�ط�ҵ��  Stop playback service
* @param [IN] lpPlayHandle  �طž�� Playback handle
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopPlayBack(IN LPVOID lpPlayHandle);

/**
* �ļ�������¼���ļ� Download recordings by file name
* @param [IN]  lpUserID             �û���¼ID User login ID
* @param [IN]  pstPlayBackInfo      ¼��طŽṹ��ָ��,�ο� LPNETDEV_PLAYBACKINFO_S Pointer to recording playback structure, see LPNETDEV_PLAYBACKINFO_S
* @param [IN]  *pszSaveFileName     ���غ󱣴浽PC�����ļ�·��,��Ϊ����·���������ļ����� Downloaded file save path on PC, must be an absolute path (including file name)
* @param [IN]  dwFormat             ¼���ļ������ʽ Recording file saving format
* @return ���ؾ��, ����0��ʾʧ��,����ֵ��ΪNETDEV_StopGetFile�Ⱥ����Ĳ����� Download handle. 0 means failure. Other values are used as the handle parameters of functions like NETDEV_StopGetFile.
* @note
*/
NEWINTERFACE LPVOID STDCALL NETDEV_GetFileByName(IN LPVOID  lpUserID,
                                                 IN LPNETDEV_PLAYBACKINFO_S pstPlayBackInfo,
                                                 IN char    *pszSaveFileName,
                                                 IN INT32   dwFormat
                                                 );


/**
* ��ʱ������¼���ļ� Download recordings by time
* @param [IN]  lpUserID                �û���¼ID User login ID
* @param [IN]  pstPlayBackCond   ��ʱ��¼��طŽṹ��ָ��,�ο� LPNETDEV_PLAYBACKCOND_S Pointer to playback-by-time structure, see LPNETDEV_PLAYBACKCOND_S
* @param [IN]  *pszSaveFileName        ���غ󱣴浽PC�����ļ�·��,��Ϊ����·���������ļ����� Downloaded file save path on PC, must be an absolute path (including file name)
* @param [IN]  dwFormat                ¼���ļ������ʽ Recording file saving format
* @return ���ؾ��, ����0��ʾʧ��,����ֵ��ΪNETDEV_StopGetFile�Ⱥ����Ĳ����� Download handle. 0 means failure. Other values are used as the handle parameters of functions like NETDEV_StopGetFile.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_GetFileByTime(IN LPVOID lpUserID, 
                                                            IN LPNETDEV_PLAYBACKCOND_S pstPlayBackCond, 
                                                            IN char *pszSaveFileName, 
                                                            IN INT32 dwFormat
                                                            );

/**
* ֹͣ����¼���ļ� Stop downloading recording files
* @param [IN]  lpPlayHandle  �طž�� Playback handle
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopGetFile(IN LPVOID lpPlayHandle);


/**
* ����¼��طŵ�״̬  Control recording playback status.
* @param [IN]  lpPlayHandle     �طŻ����ؾ�� Playback or download handle
* @param [IN]  dwControlCode    ����¼��ط�״̬���� �ο�ö�٣�NETDEV_VOD_PLAY_CTRL_E Command for controlling recording playback status, see NETDEV_VOD_PLAY_CTRL_E
* @param [INOUT]  lpBuffer     ָ������/���������ָ��, �����ٶȲο�ö�٣�NETDEV_VOD_PLAY_STATUS_E,����ʱ���������Ϊ��INT64 Pointer to input/output parameters. For playing speed, see NETDEV_VOD_PLAY_STATUS_E. The type of playing time: INT64.
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note ��ʼ����ͣ���ָ�����ʱ,lpBuffer��ΪNULL When playing, pause or resume videos, set IpBuffer as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PlayBackControl(IN LPVOID   lpPlayHandle,
                                                            IN INT32    dwControlCode,
                                                            INOUT LPVOID lpBuffer
                                                            );




/***********�ط�ҵ�� End playback service ************************************************ */

/*********** ��̨����  Begin PTZ control ************************************************* */
/**
* ��̨Ԥ��λ����(��������Ԥ��)  PTZ preset operation (preview required)
* @param [IN]  lpRealHandle         ʵʱԤ����� Live preview handle
* @param [IN]  dwPTZPresetCmd       ������̨Ԥ��λ����,�ο�ö��NETDEV_PTZ_PRESETCMD_E  PTZ preset operation commands, see NETDEV_PTZ_PRESETCMD_E
* @param [IN]  pszPresetName        Ԥ��λ������ Preset name
* @param [IN]  dwPresetID           Ԥ��λ����ţ���1��ʼ��,���֧��255��Ԥ��λ Preset number (starting from 1). Up to 255 presets are supported.
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZPreset(IN LPVOID lpRealHandle,
                                                      IN INT32  dwPTZPresetCmd,
                                                      IN CHAR   *pszPresetName,
                                                      IN INT32  dwPresetID
                                                      );

/**
* ��̨Ԥ��λ����(����Ҫ����Ԥ��)  PTZ preset operation (preview not required)
* @param [IN]  lpUserID             �û���¼ID User login ID
* @param [IN]  dwChannelID          ͨ���� Channel number
* @param [IN]  dwPTZPresetCmd       ������̨Ԥ��λ����,�ο�ö��NETDEV_PTZ_PRESETCMD_E PTZ preset operation commands, see NETDEV_PTZ_PRESETCMD_E
* @param [IN]  pszPresetName        Ԥ��λ������ Preset name
* @param [IN]  dwPresetID           Ԥ��λ����ţ���1��ʼ��,���֧��255��Ԥ��λ�� Preset number (starting from 1). Up to 255 presets are supported.
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZPreset_Other(IN LPVOID   lpUserID,
                                                            IN INT32    dwChannelID,
                                                            IN INT32    dwPTZPresetCmd,
                                                            IN CHAR     *pszPresetName,
                                                            IN INT32    dwPresetID
                                                            );

/**
* ��̨���Ʋ���(��������ʵ��Ԥ��)  PTZ control operation (preview required)
* @param [IN]  lpRealHandle         ʵʱԤ����� Live preview handle
* @param [IN]  dwPTZCommand         ��̨��������,�μ�#NETDEV_PTZ_E PTZ control commands, see #NETDEV_PTZ_E
* @param [IN]  dwSpeed              ��̨���Ƶ��ٶ�,�û�����ͬ���������ٶȿ���ֵ���á�ȡֵ��Χ[1,9] Speed of PTZ control, which is configured according to the speed control value of different decoders. Value ranges from 1 to 9.
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZControl(IN LPVOID    lpRealHandle,
                                                       IN INT32     dwPTZCommand,
                                                       IN INT32     dwSpeed
                                                       );


/**
* ��̨���Ʋ���(������ʵ��Ԥ��)  PTZ control operation (preview not required)
* @param [IN]  lpUserID             �û���¼ID User login ID
* @param [IN]  dwChannelID          ͨ���� Channel Number
* @param [IN]  dwPTZCommand         ��̨��������,�μ�#NETDEV_PTZ_E
PTZ control commands, see #NETDEV_PTZ_E
* @param [IN]  dwSpeed              ��̨���Ƶ��ٶ�,�û�����ͬ���������ٶȿ���ֵ���á�ȡֵ��Χ[1,9] Speed of PTZ control, which is configured according to the speed control value of different decoders. Value ranges from 1 to 9.
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZControl_Other(IN LPVOID  lpUserID,
                                                             IN INT32   dwChannelID,
                                                             IN INT32   dwPTZCommand,
                                                             IN INT32   dwSpeed
                                                             );

/**
* ��ȡ��̨Ԥ��λѲ��·��  Get PTZ preset patrol route
* @param [IN]   lpUserID            �û���¼ID User login ID
* @param [IN]   dwChannelID         ͨ���� Channel number
* @param [OUT]  pstCruiseList        Ѳ��·���б� Patrol route list
* @return  TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZGetCruise(IN LPVOID  lpUserID,
                                                         IN INT32   dwChannelID,
                                                         OUT LPNETDEV_CRUISE_LIST_S pstCruiseList
                                                         );

/**
* ��̨Ԥ��λѲ������(����Ҫ����Ԥ��)  PTZ preset patrol operation (preview not required)
* @param [IN]  lpUserID             �û���¼ID User login ID
* @param [IN]  dwChannelID          ͨ���� Channel number
* @param [IN]  dwPTZCruiseCmd       ������̨Ѳ������,�ο�#NETDEV_PTZ_CRUISECMD_E  PTZ patrol operation commands, see #NETDEV_PTZ_CRUISECMD_E
* @param [IN]  pstCruiseInfo         ��̨Ѳ��·����Ϣ,�ο�#LPNETDEV_CRUISE_INFO_S  PTZ patrol route information, see #LPNETDEV_CRUISE_INFO_S
* @return  TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
* - 1��Ѳ��·��,���֧��16��·������Ŵ�1��ʼ�� Patrol route. Up to 16 routes are supported (starting from 1).
* - 2��Ѳ����,���֧��32���㣨��Ŵ�1��ʼ�� Patrol point. Up to 32 points are supported (starting from 1).
* - 3��Ԥ��λ(���255)��ʱ��(���255)���ٶ�(���40)  Preset (max 255), time (max 255) and speed (max 40).
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZCruise_Other(IN LPVOID lpUserID,
                                                            IN INT32 dwChannelID,
                                                            IN INT32 dwPTZCruiseCmd,
                                                            IN LPNETDEV_CRUISE_INFO_S pstCruiseInfo
                                                            );


/**
* ��̨Ԥ��λѲ������(��������Ԥ��)  PTZ preset patrol operation (preview required)
* @param [IN]  lpRealHandle         ʵʱԤ����� Live preview handle
* @param [IN]  dwPTZCruiseCmd       ������̨Ѳ������,�ο�ö�٣�NETDEV_PTZ_CRUISECMD_E  PTZ patrol operation commands, see NETDEV_PTZ_CRUISECMD_E
* @param [IN]  pstCruiseInfo         ��̨Ѳ��·����Ϣ,�ο�#LPNETDEV_CRUISE_INFO_S  PTZ patrol route information, see #LPNETDEV_CRUISE_INFO_S
* @return  TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
* - 1��Ѳ��·��ID�����޸ġ� Patrol route ID cannot be modified.
* - 2������Ѳ��·��ʱ,Ĭ�ϰ�˳��������  New routes are added one after another.
* - 3��ɾ������ʼ��ֹͣѲ��·��ʱ,pstCruiseInfo��ֻ��Ҫ��дѲ��·��ID���ɡ�  When deleting, starting or stopping patrol, enter patrol route ID in pstCruiseInfo.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZCruise(IN LPVOID lpRealHandle,
                                                      IN INT32 dwPTZCruiseCmd,
                                                      IN LPNETDEV_CRUISE_INFO_S pstCruiseInfo
                                                      );


/**
* ��ȡ��̨�켣Ѳ��·��  Get PTZ patrol route
* @param [IN]   lpUserID            �û���¼ID User login ID
* @param [IN]   dwChannelID         ͨ���� Channel number
* @param [OUT]  pstTrackCruiseInfo        Ѳ��·���б�,�ο�#LPNETDEV_PTZ_TRACK_INFO_S  Patrol route list, see #LPNETDEV_PTZ_TRACK_INFO_S
* @return  TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZGetTrackCruise(IN LPVOID  lpUserID,
                                                              IN INT32   dwChannelID,
                                                              OUT LPNETDEV_PTZ_TRACK_INFO_S pstTrackCruiseInfo
                                                              );

/**
* ��̨�켣Ѳ������(����Ҫ����Ԥ��)   PTZ route patrol operation (preview not required)
* @param [IN]  lpUserID             �û���¼ID User login ID
* @param [IN]  dwChannelID          ͨ���� Channel number
* @param [IN]  dwPTZCruiseCmd       ������̨�켣Ѳ������,�ο�#NETDEV_PTZ_TRACKCMD_E  PTZ route patrol operation commands, see #NETDEV_PTZ_TRACKCMD_E
* @param [INOUT]  pszTrackCruiseName         �켣Ѳ������,���鳤��#NETDEV_LEN_64  Route patrol name, suggested length #NETDEV_LEN_64
* @return  TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
* - 1��Ѳ���켣·��,���֧��1��·��  Only one patrol route allowed.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZTrackCruise(IN LPVOID lpUserID,
                                                           IN INT32 dwChannelID,
                                                           IN INT32 dwPTZTrackCruiseCmd,
                                                           INOUT CHAR *pszTrackCruiseName
                                                           );

/**
* ����Ŵ���С(��������Ԥ��)   Drag to zoom in and out (preview required)
* @param [IN]  lpRealHandle         ʵʱԤ����� Live preview handle
* @param [IN]  pstPtzOperateArea    ����Ŵ�ṹ����Ϣ Drag-to-zoom structure information
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note ����˾NVR��,��ͨ��˽��Э��������˾IPC��֧�ָýӿ�  In our NVR, this interface is supported only when our camera is connected through private protocol.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZSelZoomIn(IN LPVOID lpRealHandle, 
                                                         IN LPNETDEV_PTZ_OPERATEAREA_S pstPtzOperateArea
                                                         );

/**
* ����Ŵ���С(����Ҫ����Ԥ��)   Drag to zoom in and out(preview not required)
* @param lpUserID                   �û���¼ID User login ID
* @param [IN]  dwChannelID          ͨ���� Channel number
* @param [IN]  pstPtzOperateArea    ����Ŵ�ṹ����Ϣ Drag-to-zoom structure information
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note ����˾NVR��,��ͨ��˽��Э��������˾IPC��֧�ָýӿ�  In our NVR, this interface is supported only when our camera is connected through private protocol.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZSelZoomIn_Other(IN LPVOID lpUserID,
                                                               IN INT32 dwChannelID,
                                                               IN LPNETDEV_PTZ_OPERATEAREA_S pstPtzOperateArea
                                                               );

/**********��̨����  End PTZ control ************************************************/

/********** Զ�̲������� Begin remote parameter configuration ***********************/

/**
* ��ȡ�豸��������Ϣ  Get configuration information of device
* @param [IN]   lpUserID                �û���¼ID User login ID
* @param [IN]   dwChannelID             ͨ���� Channel number
* @param [IN]   dwCommand               �豸��������,�μ�#NETDEV_CONFIG_COMMAND_E  Device configuration commands, see #NETDEV_CONFIG_COMMAND_E
* @param [OUT]  lpOutBuffer             �������ݵĻ���ָ�� Pointer to buffer that receives data
* @param [OUT]  dwOutBufferSize         �������ݵĻ��峤��(���ֽ�Ϊ��λ),����Ϊ0 Length (in byte) of buffer that receives data, cannot be 0.
* @param [OUT]  pdwBytesReturned        ʵ���յ������ݳ���ָ��,����ΪNULL  Pointer to length of received data, cannot be NULL.
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
* - 1��Ѳ��·��ID�����޸ġ�  Route ID cannot be modified.
* - 2������Ѳ��·��ʱ,Ĭ�ϰ�˳��������  New routes are added one after another.
* - 3��ɾ������ʼ��ֹͣѲ��·��ʱ,pstCruiseInfo��ֻ��Ҫ��дѲ��·��ID���ɡ�  When deleting, starting or stoping a patrol route, enter route ID in pstCruiseInfo.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetDevConfig(IN LPVOID  lpUserID,
                                                         IN INT32   dwChannelID,
                                                         IN INT32   dwCommand,
                                                         OUT LPVOID lpOutBuffer,
                                                         OUT INT32  dwOutBufferSize,
                                                         OUT INT32  *pdwBytesReturned
                                                         );

/**
* �����豸��������Ϣ  Modify device configuration information
* @param [IN]   lpUserID            �û���¼ID User login ID
* @param [IN]   dwChannelID         ͨ���� Channel number
* @param [IN]   dwCommand           �豸��������,�μ�#NETDEV_CONFIG_COMMAND_E  Device configuration commands, see #NETDEV_CONFIG_COMMAND_E
* @param [IN]   lpInBuffer          �������ݵĻ���ָ�� Pointer to buffer of input data
* @param [IN]   dwInBufferSize      �������ݵĻ��峤��(���ֽ�Ϊ��λ) Length of input data buffer (byte)
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetDevConfig(IN LPVOID  lpUserID,
                                                         IN INT32   dwChannelID,
                                                         IN INT32   dwCommand,
                                                         IN LPVOID  lpInBuffer,
                                                         IN INT32   dwInBufferSize
                                                         );

/**************Զ�̲�������  End remote parameter configuration ******************************/
/**
* �����豸\n
* Restart device\n
* @param [IN]  lpUserID     �û���¼ID User login ID
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Reboot(IN LPVOID lpUserID);

/**
* �ָ���������  Restore to factory default settings
* @param [IN]  lpUserID     �û���¼ID User login ID
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note �����������ú��û�����,���������ָ����������á� Restore all parameters to factory settings, except network settings and user settings.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_RestoreConfig(IN LPVOID lpUserID);

/**
* ��ȡ������  Get error codes
* @return ������ Error codes
*/
NETDEV_API NEWINTERFACE INT32 STDCALL NETDEV_GetLastError();

/**
* ������ȡ�豸�澯��Ϣ  Get alarm information from the device
* @param [IN]  lpUserID        �û���¼ID User login ID
* @param [IN]  dwPullWaitTime  �澯�ȴ�ʱ��,��λs Alarm wait time (s)
* @param [INOUT] pdwListCnt     �澯�������,�����ʱ��ʾ�澯��Ϣ�б��С,����ʱ��ʾʵ�ʸ澯����Maximum number of alarms. When working as an input parameter, it indicates the length of alarm information list; when working as an output parameter, it indicates the actual number of alarms.
* @param [OUT]   pstPullAlarmList   �澯��Ϣ�б�,���ڴ���Ԥ�ȷ��� List of alarm information. The memory should be allocated in advance.
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* note: �������û�����login,logout, �����鳤ʱ��ȴ� Calling the function will block login and logout. It is not recommended to wait for a long time.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PullAlarm(IN LPVOID lpUserID, 
                                                      IN INT32 dwPullWaitTime, 
                                                      INOUT INT32 *pdwListCnt, 
                                                      OUT LPNETDEV_PULLALARM_INFO_S pstPullAlarmList
                                                      );

/**
* ��Ԥ����ץ��  Snapshot without preview
* @param [IN]  lpUserID             �û���¼ID User login ID
* @param [IN]  dwChannelID          ͨ���� Channel number
* @param [IN]  dwStreamType;        ��������,�μ�ö��#NETDEV_LIVE_STREAM_INDEX_E  Stream type, see enumeration #NETDEV_LIVE_STREAM_INDEX_E 
* @param [IN]  pszFileName          ����ͼ����ļ�·���������ļ����� File path to save images (including file name)
* @param [IN]  dwCaptureMode        ����ͼ���ʽ,�μ�#NETDEV_PICTURE_FORMAT_E   Image saving format, see #NETDEV_PICTURE_FORMAT_E
* @return  TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
        ��֧��JPG��ʽ��
        Only JPG format is supported.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_CaptureNoPreview(IN LPVOID lpUserID,
                                                             IN INT32 dwChannelID,
                                                             IN INT32 dwStreamType,
                                                             IN CHAR *pszFileName,
                                                             IN INT32 dwCaptureMode
                                                             );

/**
* ��̬����һ���ؼ�֡\n 
* Dynamically create an I frame\n 
* @param [IN] lpUserID       �û���¼ID  User login ID
* @param [IN] dwChannelID    ͨ����  Channel number
* @param [IN] dwStreamType   �ο�ö��NETDEV_LIVE_STREAM_INDEX_E  See enumeration NETDEV_LIVE_STREAM_INDEX_E
* @return NETDEV_E_SUCCEED   ��ʾ�ɹ�,������ʾʧ��  NETDEV_E_SUCCEED means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_MakeKeyFrame(IN LPVOID lpUserID,
                                                         IN INT32 dwChannelID,
                                                         IN INT32 dwStreamType
                                                         );

/**
* ���ñ������
* Set keep-alive parameters
* @param [IN]  dwWaitTime            ����ȴ�ʱ��  Waiting time
* @param [IN]  dwTrytimes            �������Ӵ���  Connecting attempts
* @return TRUE��ʾ�ɹ�,������ʾʧ�� TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetConnectTime(IN INT32 dwWaitTime,
                                                           IN INT32 dwTrytimes
                                                           );

/**
* �����豸����ҵ��\n
* Set device name\n
* @param [IN] lpUserID         �û���¼ID User login ID
* @param [IN] pszDeviceName    �豸����  Device name
* @return TRUE��ʾ�ɹ�,������ʾʧ��  TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ModifyDeviceName(IN LPVOID lpUserID,
                                                             IN CHAR* pszDeviceName
                                                             );

/**
* ��ȡӳ��˿�ҵ��\n
* @param [IN]   lpUserID     �û���¼ID User login ID
* @param [IN]   pstNatState  ����˿ں�״̬��Ϣ
* @return TRUE��ʾ�ɹ�,     ������ʾʧ��
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetUpnpNatState(IN LPVOID lpUserID,
                                                            OUT LPNETDEV_UPNP_NAT_STATE_S pstNatState
                                                            );

/**
* ������־·��ҵ��\n
* Set log path\n
* @param [IN]   pszLogPath  ��־·��(�������ļ���)  Log path (file name not included)
* @return TRUE��ʾ�ɹ�,������ʾʧ��  TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetLogPath(IN CHAR* pszLogPath);

/**
* ��ȡ�豸ϵͳʱ������\n
* Get device System time configuration\n
* @param [IN]  pstSystemTimeInfo    ʱ�����ýṹ��ָ��  Pointer to time configuration structure
* @return TRUE��ʾ�ɹ�,������ʾʧ��  TRUE means success, and any other value means failure.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetSystemTimeCfg(IN LPVOID lpUserID,
                                                             OUT LPNETDEV_TIME_CFG_S pstSystemTimeInfo
                                                             );

/**
* �����豸ϵͳʱ������\n
* Set device system time configuration\n
* @param [IN]  pstSystemTimeInfo    ʱ�����ýṹ��ָ��  Pointer to time configuration structure
* @return TRUE��ʾ�ɹ�,������ʾʧ��  TRUE means success, and any other value means failure.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetSystemTimeCfg(IN LPVOID lpUserID,
                                                             IN LPNETDEV_TIME_CFG_S pstSystemTimeInfo
                                                             );

#ifdef  __cplusplus
}
#endif  /* end of __cplusplus */

#endif  /* end of _NETDEV_NET_SDK_H_ */

