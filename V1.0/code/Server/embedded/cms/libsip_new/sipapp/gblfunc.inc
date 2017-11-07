/******************************************************************************

                  ��Ȩ���� (C), 2001-2013, ������Ѷ�������޹�˾

 ******************************************************************************
  �� �� ��   : gblfunc.h
  �� �� ��   : ����
  ��    ��   : yanghaifeng
  ��������   : 2013��4��1��
  ����޸�   :
  ��������   : gblfunc.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��4��1��
    ��    ��   : yanghaifeng
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __GBLFUNC_H__
#define __GBLFUNC_H__
/*----------------------------------------------*
 * ����ͷ�ļ�                                   *
 *----------------------------------------------*/
#include   <stdlib.h>
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

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

    /*----------------------------------------------*
     * ��������                                     *
     *----------------------------------------------*/
#ifndef   PATH_MAX
#define   PATH_MAX   1024
#endif

    /*----------------------------------------------*
     * �궨��                                       *
     *----------------------------------------------*/
    extern int datetime(char* s, size_t smax, time_t* tp);
    extern unsigned int get_ipaddr(char* host);
    extern int good_host(char* addr);
    extern int good_ipaddr(char* addr);
    extern int host_match(char* host1, char* host2);
    extern int inet_type(char* host);
    extern void ipaddr2str(char* buffer, unsigned long ipaddr);
    extern int is_host_ip(char* host, char* ipaddr);
    extern int  is_private_ip(char* ipaddr);
    extern double satod(char* number);
    extern int sstrcmp(const char* s1, const char* s2);
    extern int printf_system_time1();
    extern unsigned int analysis_time1(char* strTime);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __GBLFUNC_H__ */