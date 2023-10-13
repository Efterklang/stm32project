/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月03日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
 ****************************************************************************/

#ifndef __SETUP_H__
#define __SETUP_H__

#include "z_timer.h"
#include "z_uart.h"
#include "z_ps2.h"

/*******初始化函数声明*******/
void setup_systick(void);	//初始化滴答时钟，1S增加一次systick_ms的值
void setup_uart1(void);		//初始化串口1
void setup_ps2(void);			//初始化PS2手柄

#endif
