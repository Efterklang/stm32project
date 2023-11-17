/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月03日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
	*	@功能	：	存放PS2相关的函数
	*	@函数列表:
	*	1.	void ps2_init(void) -- 初始化PS2
	*	2.	u8   ps2_transfer(unsigned char dat) -- 读写1个字节
	*	3.	void ps2_write_read(unsigned char *get_buf) -- 滴答时钟查询
 ****************************************************************************/
 
#include "z_ps2.h"
 
/***********************************************
	函数名称：ps2_init() 
	功能介绍：初始化PS2的IO口
	函数参数：无
	返回值：	无
 ***********************************************/
void ps2_init(void) {
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);  		//使能禁止JTAG
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  				//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 				//IO 翻转 50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	

	PS2_ATT(1);
	PS2_CMD(1);
	PS2_CLK(1);
	//PS2_DAT = 0;
	//PS2_ACK = 1;
}

/***********************************************
	函数名称：ps2_transfer() 
	功能介绍：读写1个字节
	函数参数：无
	返回值：	无
 ***********************************************/
u8 ps2_transfer(unsigned char dat) {
	unsigned char rd_data ,wt_data, i;
	wt_data = dat;
	rd_data = 0;
	for(i = 0;i < 8;i++){
		PS2_CMD((wt_data & (0x01 << i)));
		PS2_CLK(1);
		delay_us(6);
		PS2_CLK(0);
		delay_us(6);
		PS2_CLK(1);
		if(PS2_DAT) {
			rd_data |= 0x01<<i;
		}
	}
	return rd_data;
}
	
/***********************************************
	函数名称：ps2_write_read() 
	功能介绍：读取手柄数据
	函数参数：无
	返回值：	无
 ***********************************************/
void ps2_write_read(unsigned char *get_buf) {
	PS2_ATT(0);
	get_buf[0] = ps2_transfer(START_CMD);
	get_buf[1] = ps2_transfer(ASK_DAT_CMD);
	get_buf[2] = ps2_transfer(get_buf[0]);
	get_buf[3] = ps2_transfer(get_buf[0]);
	get_buf[4] = ps2_transfer(get_buf[0]);
	get_buf[5] = ps2_transfer(get_buf[0]);
	get_buf[6] = ps2_transfer(get_buf[0]);
	get_buf[7] = ps2_transfer(get_buf[0]);
	get_buf[8] = ps2_transfer(get_buf[0]);
	PS2_ATT(1);
	return;
}
