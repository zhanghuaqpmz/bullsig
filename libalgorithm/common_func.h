/*Copyright (C)[2019-2029] [Bruce Zhang, hua_zhang_bj@sina.com]
* 
* All rights reserved
* 
*/
/* Change Logs:
*     Date               Author           Notes
*     2019-04-10         bruce.zhang        the first version
*/


#ifndef _COMMON_FUNC_H_
#define _COMMON_FUNC_H_

#ifdef __cplusplus
extern "C"{
#endif

#define NONE                 "\e[0m"
#define BLACK                "\e[0;30m"
#define L_BLACK              "\e[1;30m"
#define RED                  "\e[0;31m"
#define L_RED                "\e[1;31m"
#define GREEN                "\e[0;32m"
#define L_GREEN              "\e[1;32m"
#define BROWN                "\e[0;33m"
#define YELLOW               "\e[1;33m"
#define BLUE                 "\e[0;34m"
#define L_BLUE               "\e[1;34m"
#define PURPLE               "\e[0;35m"
#define L_PURPLE             "\e[1;35m"
#define CYAN                 "\e[0;36m"
#define L_CYAN               "\e[1;36m"
#define GRAY                 "\e[0;37m"
#define WHITE                "\e[1;37m"

#define BOLD                 "\e[1m"
#define UNDERLINE            "\e[4m"
#define BLINK                "\e[5m"
#define REVERSE              "\e[7m"
#define HIDE                 "\e[8m"
#define CLEAR                "\e[2J"
#define CLRLINE              "\r\e[K" //or "\e[1K\r"

void quit(char* file, int line, char* reason);
int set_disp_mode(int fd,int option);


//hex字符串转字节流
void hex2bytes(const char* hex, int hlen, unsigned char* bytes);
//字节流转hex字符串
void bytes2hex(const unsigned char* bytes, int blen, unsigned char* hex);
void dump_byte(const unsigned char* bytes, int blen);


#ifdef __cplusplus
}
#endif


#endif    //#ifndef _COMMON_FUNC_H_