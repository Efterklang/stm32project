/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月03日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
	*	@功能	：	ZL-KPZ控制板（32版）模块例程6————PS2手柄解析
	*	@函数列表:
	*	1.	void main(void) -- 主函数
 ****************************************************************************/

#include "z_main.h"

/*******全局变量定义*******/
// 无符号8bit整数 u8 = unit8_t = unsigned char 表示0-255
u8 i=0;
u8 uart_receive_buf[UART_RECEIVE_BUF_SIZE]={0}, uart_receive_buf_index, uart_get_ok;
u8 ps2_buf[9]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
u8 ps2_mode=0;
u8 cmd_return[100];

int main(void) {
	/*
	 * 这个函数调用了三个其他的函数：setup_systick()、setup_uart1() 和 setup_ps2()。
	 * 这些函数分别负责初始化系统的滴答时钟、UART1串口通信和PS2控制器。
	 * 这些函数的目的是设置系统，使其准备好接收来自PS2控制器的输入
	 * systick(滴答时钟)、uart1(串口1)、ps2(手柄)
	 * 
	*/
	setup_systick();	// 初始化滴答时钟，1S增加一次systick_ms的值
	setup_uart1();		//初始化串口1
	setup_ps2();			//初始化完成

	while (1) {
		loop_ps2();			//循环检测手柄状态
	}
}
