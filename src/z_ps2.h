/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月03日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
 ****************************************************************************/

#ifndef __PS2_H__
#define __PS2_H__

#include "stm32f10x.h"
#include "z_delay.h"

/*******PS2相关指令表*******/
#define START_CMD				0x01
#define ASK_DAT_CMD			0x42

/*******PS2模式数据表*******/
#define PS2_MODE_GRN  		0x41
#define PS2_MODE_RED  		0x73

/*******PS2按键检测表*******/
#define PS2_LEFT_UP				!(ps2_buf[3]&0x10)
#define PS2_LEFT_RIGHT		!(ps2_buf[3]&0x20)
#define PS2_LEFT_DOWN			!(ps2_buf[3]&0x40)
#define PS2_LEFT_LEFT			!(ps2_buf[3]&0x80)

#define PS2_SELECT				!(ps2_buf[3]&0x01)
#define PS2_START					!(ps2_buf[3]&0x08)

#define PS2_RIGHT_UP			!(ps2_buf[4]&0x10)
#define PS2_RIGHT_RIGHT		!(ps2_buf[4]&0x20)
#define PS2_RIGHT_DOWN		!(ps2_buf[4]&0x40)
#define PS2_RIGHT_LEFT		!(ps2_buf[4]&0x80)

#define PS2_LEFT_2				!(ps2_buf[4]&0x01)
#define PS2_RIGHT_2				!(ps2_buf[4]&0x02)
#define PS2_LEFT_1				!(ps2_buf[4]&0x04)
#define PS2_RIGHT_1				!(ps2_buf[4]&0x08)

#define PS2_RIGHT_X				(int)(ps2_buf[5]-0x7f)
#define PS2_RIGHT_Y				(int)(ps2_buf[6]-0x80)
#define PS2_LEFT_X				(int)(ps2_buf[7]-0x7f)
#define PS2_LEFT_Y				(int)(ps2_buf[8]-0x80)

/*******PS2管脚映射表*******/
#define PS2_DAT			GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15)
#define PS2_CMD(x)	GPIO_WriteBit(GPIOA, GPIO_Pin_14, (BitAction)x)
#define PS2_ATT(x)	GPIO_WriteBit(GPIOA, GPIO_Pin_13, (BitAction)x)
#define PS2_CLK(x)	GPIO_WriteBit(GPIOA, GPIO_Pin_12, (BitAction)x)

/*******PS2相关函数声明*******/
void ps2_init(void);
u8   ps2_transfer(unsigned char dat);
void ps2_write_read(unsigned char *get_buf);

#endif
