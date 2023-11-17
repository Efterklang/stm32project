/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月03日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
 ****************************************************************************/

#ifndef __MAIN_H__
#define __MAIN_H__

#include "z_setup.h"
#include "z_loop.h"

/*******全局变量宏定义*******/
#define FOSC  11059200L        	//系统晶振频率
#define UART_RECEIVE_BUF_SIZE  100

/*******全局变量外部声明*******/
extern u8 i;
extern u8 uart_receive_buf[UART_RECEIVE_BUF_SIZE], uart_receive_buf_index, uart_get_ok;
extern u8 ps2_buf[9];
extern u8 ps2_mode;
extern u8 cmd_return[100];

#endif 
