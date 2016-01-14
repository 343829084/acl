#ifndef _MSG_INCLUDE_H_
#define _MSG_INCLUDE_H_

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdarg.h>
#include <stdio.h>
#include "define.h"

#undef	USE_PRINTF_MACRO

/**
 * ����¼��־��Ϣ����־�ļ�ʱ����Ҫ�������µ���־��¼����
 */

#ifndef	USE_PRINTF_MACRO

/**
 * һ�㼶����־��Ϣ��¼����
 * @param fmt {const char*} ������ʽ
 * @param ... �������
 */
void PRINTF(1, 2) msg_info(const char *fmt,...);

/**
 * ���漶����־��Ϣ��¼����
 * @param fmt {const char*} ������ʽ
 * @param ... �������
 */
void PRINTF(1, 2) msg_warn(const char *fmt,...);

/**
 * ���󼶱���־��Ϣ��¼����
 * @param fmt {const char*} ������ʽ
 * @param ... �������
 */
void PRINTF(1, 2) msg_error(const char *fmt,...);

/**
 * ����������־��Ϣ��¼����
 * @param fmt {const char*} ������ʽ
 * @param ... �������
 */
void PRINTF(1, 2) msg_fatal(const char *fmt,...);

#else

/**
 * ����¼��־��Ϣ����׼���ʱ����Ҫ�������µ���־��¼����
 */

#include <stdio.h>

#undef	msg_info
#undef	msg_warn
#undef	msg_error
#undef	msg_fatal

#define	msg_info	msg_printf
#define	msg_warn	msg_printf
#define	msg_error	msg_printf
#define	msg_fatal	msg_printf

#endif

const char *msg_strerror(int errnum, char *buffer, size_t size);

/**
 * ����ϴ�ϵͳ���ó���ʱ�Ĵ���������Ϣ
 * @param buffer {char*} �洢����������Ϣ���ڴ滺����
 * @param size {size_t} buffer �Ŀռ��С
 * @return {const char*} ���صĵ�ַӦ�� buffer ��ͬ
 */
const char *last_strerror(char *buffer, size_t size);

/**
 * ����ϴ�ϵͳ���ó���ʱ�Ĵ���������Ϣ���ú����ڲ��������ֲ߳̾�������������
 * �̰߳�ȫ�ģ���ʹ����������Щ
 * @return {const char *} ���ش�����ʾ��Ϣ 
 */
const char *last_serror(void);

/**
 * ����ϴ�ϵͳ���ó���ʱ�Ĵ����
 * @return {int} �����
 */
int last_error(void);

/**
 * �ֹ����ô����
 * @param errnum {int} �����
 */
void set_error(int errnum);

/**
 * �����Ϣ����׼���
 * @param fmt {const char*} ��ʽ����
 * @param ... �������
 */
void PRINTF(1, 2) msg_printf(const char *fmt,...);

#ifdef  __cplusplus
}
#endif

#endif