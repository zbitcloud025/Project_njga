/******************************************************************************

                  ��Ȩ���� (C), 2001-2013, ������Ѷ�������޹�˾

 ******************************************************************************
  �� �� ��   : sipauth.h
  �� �� ��   : ����
  ��    ��   : yanghaifeng
  ��������   : 2013��4��1��
  ����޸�   :
  ��������   : sipauth.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��4��1��
    ��    ��   : yanghaifeng
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __SIPAUTH_H__
#define __SIPAUTH_H__

//modified by chenyu 130522
#ifdef WIN32

#ifdef EV9000SIP_EXPORTS  
#define EV9000SIP_API    __declspec(dllexport) 
#else  
#define EV9000SIP_API    __declspec(dllimport) 
#endif

#else
#define EV9000SIP_API    extern
#endif //end WIN32

/*----------------------------------------------*
 * ����ͷ�ļ�                                   *
 *----------------------------------------------*/
#include <osip2/internal.h>
#include <osip2/osip.h>

#include "gbltype.h"

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

    /*----------------------------------------------*
     * �궨��                                       *
     *----------------------------------------------*/
#define HASHLEN 16
    typedef char HASH[HASHLEN];
#define HASHHEXLEN 32
    typedef char HASHHEX[HASHHEXLEN + 1];

    extern int CheckDigestAuth(osip_authorization_t* authorization, int permit_anonym, char* username, char* password, char* method);
    extern int check_digest_auth(osip_authorization_t* authorization, int permit_anonym, char* username, char* password, char* method);
    extern void CvtHex(IN HASH Bin, OUT HASHHEX Hex);
    extern void DigestCalcHA1(IN char* pszAlg,
                                IN char* pszUserName,
                                IN char* pszRealm,
                                IN char* pszPassword,
                                IN char* pszNonce, IN char* pszCNonce, OUT HASHHEX SessionKey);
    extern void DigestCalcResponse(IN HASHHEX HA1,     /* H(A1) */
                                     IN char* pszNonce,  /* nonce from server */
                                     IN char* pszNonceCount, /* 8 hex digits */
                                     IN char* pszCNonce, /* client nonce */
                                     IN char* pszQop,    /* qop-value: "", "auth", "auth-int" */
                                     IN char* pszMethod, /* method from the request */
                                     IN char* pszDigestUri,  /* requested URL */
                                     IN HASHHEX HEntity, /* H(entity body) if qop="auth-int" */
                                     OUT HASHHEX Response    /* request-digest or response-digest */
                                    );
    EV9000SIP_API int SIP_Auth(osip_authorization_t* authorization, char* username, char* password, char* method);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __SIPAUTH_H__ */