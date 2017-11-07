/******************************************************************************

                  ��Ȩ���� (C), 2001-2013, ������Ѷ�������޹�˾

 ******************************************************************************
  �� �� ��   : csdbg.h
  �� �� ��   : ����
  ��    ��   : yanghaifeng
  ��������   : 2013��4��1��
  ����޸�   :
  ��������   : csdbg.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��4��1��
    ��    ��   : yanghaifeng
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __LOG_PROC_H__
#define __LOG_PROC_H__

/*----------------------------------------------*
 * ����ͷ�ļ�                                   *
 *----------------------------------------------*/
#include "gbldef.inc"
#include "libsip.h"

#include <vector>
#include <string>
#include <queue>

#include "common/DBOper.h"
#include "user/user_info_mgn.inc"

using namespace std;

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

    /*----------------------------------------------*
     * �ⲿ����˵��                                 *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * �ⲿ����ԭ��˵��                             *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * �ڲ�����ԭ��˵��                             *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * ȫ�ֱ���                                     *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * ģ�鼶����                                   *
     *----------------------------------------------*/
    /* SIP��Ϣ�ļ���¼�ṹ */
    typedef struct _sip_msglog_t
    {
        int sndcnt;
        int rcvcnt;
        FILE* logfile;
    } sip_msglog_t;

    /* SIP������Ϣ�ļ���¼�ṹ */
    typedef struct _sip_errorlog_t
    {
        int cnt;
        FILE* logfile;
    } sip_errorlog_t;

    /* ϵͳ������־�ļ���¼�ṹ */
    typedef struct _debug_log_t
    {
        FILE* logfile;
    } debug_log_t;

    typedef debug_log_t run_log_t;

    typedef struct _cms_log_t
    {
        sip_msglog_t* sip_msglog;
        sip_errorlog_t* sip_errorlog;
        debug_log_t* debug_log;
        run_log_t* run_log;
    } cms_log_t;

    /* 1��SIP��Ϣ��־��¼�ļ� �ṹ�� */
    typedef struct _sip_msg_log2file_t
    {
        int type;
        char msg[MAX_2048CHAR_STRING_LEN + 4];
        char ipaddr[MAX_IP_LEN];
        int port;
    } sip_msg_log2file_t;

    /* SIP��Ϣ��־���� */
    typedef std::deque <sip_msg_log2file_t*> sip_msg_log2file_queue;


    /* 2����־��¼���ļ� �ṹ�� */
    typedef struct _trace_log2file_t
    {
        int type;
        char msg[MAX_2048CHAR_STRING_LEN + 4];
    } trace_log2file_t;

    /* ��־��¼���ļ���Ϣ���� */
    typedef std::deque <trace_log2file_t*> trace_log2file_queue;

    /* 3��ϵͳ��־��¼�����ݿ�ṹ�� */
    typedef struct _system_log2db_t
    {
        int iType;                /* ��־���� */
        int iLevel;               /* ��־���� */
        int iTime;                /* ��־ʱ��*/
        char msg[MAX_2048CHAR_STRING_LEN + 4];           /* ��־���� */
    } system_log2db_t;

    /* ϵͳ��־��¼�����ݿ���Ϣ���� */
    typedef std::deque <system_log2db_t*> system_log2db_queue;

    /* 4���û�������¼�����ݿ�ṹ�� */
    typedef struct _user_log2db_t
    {
        char pcUserID[MAX_ID_LEN + 4];               /* �û�ID */
        char pcUserIP[MAX_IP_LEN];                   /* �û�IP */
        unsigned int iUserIndex;                     /* �û����� */
        int iType;                                   /* ��־���� */
        int iLevel;                                  /* ��־���� */
        int iTime;                                   /* ��־ʱ��*/
        char msg[MAX_2048CHAR_STRING_LEN + 4];       /* ��־���� */
    } user_log2db_t;

    /* �û�������¼�����ݿ���Ϣ���� */
    typedef std::deque <user_log2db_t*> user_log2db_queue;

    /*----------------------------------------------*
     * ��������                                     *
     *----------------------------------------------*/
    /* ��־���� */
#define LOG_ALL     1    /* ��ӡ������־ */

#define LOG_DEBUG   2    /* ��ӡ������־ */
#define LOG_TRACE   3    /* ��ӡ������־ */
#define LOG_INFO    4    /* ��ӡһ����־ */
#define LOG_WARN    5    /* ��ӡ�澯��־ */
#define LOG_ERROR   6    /* ��ӡ������־ */
#define LOG_FATAL   7    /* ��ӡ������־ */

#define LOG_OFF     8    /* �ر���־ */

    /* ģ�鶨�� */
#define MODULE_COMMON           1    /* ����ģ�� */
#define MODULE_SIPSTACK         2    /* SIPЭ��ջģ�� */
#define MODULE_USER             3    /* �û�ģ�� */
#define MODULE_DEVICE           4    /* �豸ģ�� */
#define MODULE_ROUTE            5    /* ����·��ģ�� */
#define MODULE_RECORD           6    /* ¼��ģ�� */
#define MODULE_RESOURCE         7    /* ��Դģ�� */
#define MODULE_CRUISE_SRV       8    /* Ѳ��ҵ��ģ�� */
#define MODULE_PLAN_SRV         9    /* Ԥ��ҵ��ģ�� */
#define MODULE_POLL_SRV         10   /* ��Ѳҵ��ģ�� */

    /*----------------------------------------------*
     * �궨��                                       *
     *----------------------------------------------*/
#define LOGFILE_DIR            ("/data/log/")
#define LOGFILE_SIP_MSG        ("cms_sipmsg")
#define LOGFILE_SIP_ERRORMSG   ("cms_siperror")
#define LOGFILE_RUN            ("cms_run")
#define LOGFILE_DEBUG          ("cms_debug")

#define __LOG4CMS_FUNC__ "X::X()"

    extern int cms_log_init(cms_log_t** log);
    extern void cs_log_free(cms_log_t* log);
    extern void DebugRunTrace(const char* fmt, ...);
    extern void DebugSIPMessage(int type, int iDirect, char* ipaddr, int port, char* msg);
    extern void DebugTrace(int iModule, int iLevel, const char* FILENAME, const char* FUNCTIONNAME, int CODELINE, const char* fmt, ...);
    extern void debug_log_free(debug_log_t* log);
    extern int debug_log_init(debug_log_t** log);
    extern void DeleteOutDateFile(int iYear, int iMonth, int iDay, int iHour);
    extern void EnSystemLog(int iType, int iLevel, const char* fmt, ...);
    extern void EnUserLog(int iType, int iLevel, user_info_t* pUserInfo, const char* fmt, ...);
    extern char* GetLogFilename(int type);
    extern void ListDirFile(char* path, int indent);
    extern void Log2FileFree();
    extern int Log2FileInit();
    extern void LogDebugTraceToFile(char* msg);
    extern void LogRunTraceToFile(char* msg);
    extern void LogSipErrMsgToFile(int type, char* msg, char* ipaddr, int port);
    extern void LogSipMsgToFile(int type, char* msg, char* ipaddr, int port);
    extern void run_log_free(run_log_t* log);
    extern int run_log_init(run_log_t** log);
    extern void scan_sip_msg_log2file_list();
    extern void scan_system_log2db_list(thread_proc_t* run);
    extern void scan_trace_log2file_list();
    extern void scan_user_log2db_list(thread_proc_t* run);
    extern void sip_errorlog_free(sip_errorlog_t* log);
    extern int  sip_errorlog_init(sip_errorlog_t** log);
    extern void sip_msglog_free(sip_msglog_t* log);
    extern int sip_msglog_init(sip_msglog_t** log);
    extern int sip_msg_log2file_add(int type, char* msg, char* ipaddr, int port);
    extern void sip_msg_log2file_free(sip_msg_log2file_t* sip_msg_log2file);
    extern int sip_msg_log2file_init(sip_msg_log2file_t** sip_msg_log2file);
    extern void sip_msg_log2file_list_free();
    extern int sip_msg_log2file_list_init();
    extern void SystemLog(int iType, int iLevel, const char* fmt, ...);
    extern void SystemLogToDB(DBOper* pLog2DB_dboper, system_log2db_t* system_log);
    extern int system_log2db_add(int type, int level, int iTime, char* msg);
    extern void system_log2db_free(system_log2db_t* system_log2db);
    extern int system_log2db_init(system_log2db_t** system_log2db);
    extern void system_log2db_list_clean();
    extern void system_log2db_list_free();
    extern int system_log2db_list_init();
    extern int trace_log2file_add(int type, char* msg);
    extern void trace_log2file_free(trace_log2file_t* trace_log2file);
    extern int trace_log2file_init(trace_log2file_t** trace_log2file);
    extern void trace_log2file_list_free();
    extern int trace_log2file_list_init();
    extern void UserLog(int iType, int iLevel, user_info_t* pUserInfo, const char* fmt, ...);
    extern void UserLogToDB(DBOper* pLog2DB_dboper, user_log2db_t* user_log);
    extern int user_log2db_add(int type, int level, user_info_t* pUserInfo, int iTime, char* msg);
    extern void user_log2db_free(user_log2db_t* user_log2db);
    extern int user_log2db_init(user_log2db_t** user_log2db);
    extern void user_log2db_list_clean();
    extern void user_log2db_list_free();
    extern int user_log2db_list_init();

#define DEBUG_TRACE(Module, level, fmt, args...) \
    DebugTrace(Module, level, __FILE__, __LOG4CMS_FUNC__, __LINE__, fmt, ##args)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __CSDBG_H__ */