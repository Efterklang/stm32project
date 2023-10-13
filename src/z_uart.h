/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月03日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
 ****************************************************************************/

#ifndef __UART_H__
#define __UART_H__

#include <stdio.h>
#include "stm32f10x.h"
#include "z_main.h"

/*******串口快捷指令表*******/
#define uart1_open()  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE)
#define uart1_close() USART_ITConfig(USART1, USART_IT_RXNE, DISABLE)

/*******串口相关函数声明*******/
void uart1_init(u32 baud);
void uart1_send_byte(u8 dat);
void uart1_send_str(u8 *s);
void uart1_send_int(int tmp);

#endif
