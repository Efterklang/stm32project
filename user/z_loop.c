/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月03日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
	*	@功能	：	存放永久循环执行的函数
	*	@函数列表:
	*	1.	void loop_ps2(u32 baud) -- 循环接收处理手柄数据
 ****************************************************************************/

#include "z_loop.h"

/***********************************************
	函数名称：	loop_ps2() 
	功能介绍：	循环接收处理手柄数据
	函数参数：	无
	返回值：		无
 ***********************************************/
void loop_ps2(void) {
	static u32 systick_ms_bak = 0;
	static u32 last_right_x = 0, last_right_y = 0, last_left_x = 0, last_left_y = 0;
	if(millis() - systick_ms_bak >= 20) {
		systick_ms_bak = millis();
		ps2_write_read(ps2_buf);
		#if 0	
			sprintf((char *)cmd_return, "0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x\r\n", 
			(int)ps2_buf[0], (int)ps2_buf[1], (int)ps2_buf[2], (int)ps2_buf[3],
			(int)ps2_buf[4], (int)ps2_buf[5], (int)ps2_buf[6], (int)ps2_buf[7], (int)ps2_buf[8]);
			uart1_send_str(cmd_return);
		#endif 	
	}
	if(ps2_buf[1] == PS2_MODE_GRN) ps2_mode=0;
	else if(ps2_buf[1] == PS2_MODE_RED) ps2_mode=1;
	
	if(ps2_mode){
		#if 0	
			sprintf((char *)cmd_return, "%02d,%02d,%02d,%02d\r\n", 
			PS2_RIGHT_X, PS2_RIGHT_Y, PS2_LEFT_X, PS2_LEFT_Y);
			uart1_send_str(cmd_return);
		#endif 	
		if(PS2_RIGHT_X != last_right_x){
			last_right_x = PS2_RIGHT_X;
			uart1_send_str((u8 *)"\r\nPS2_RIGHT_X:\t");
			uart1_send_int(last_right_x);
		}
		if(PS2_RIGHT_Y != last_right_y){
			last_right_y = PS2_RIGHT_Y;
			uart1_send_str((u8 *)"\r\nPS2_RIGHT_Y:\t");
			uart1_send_int(last_right_y);
		}
		if(PS2_LEFT_X != last_left_x){
			last_left_x = PS2_LEFT_X;
			uart1_send_str((u8 *)"\r\nPS2_LEFT_X:\t");
			uart1_send_int(last_left_x);
		}
		if(PS2_LEFT_Y != last_left_y){
			last_left_y = PS2_LEFT_Y;
			uart1_send_str((u8 *)"\r\nPS2_LEFT_Y:\t");
			uart1_send_int(last_left_y);
		}
	}
	if(PS2_LEFT_UP) {
		uart1_send_str((u8 *)"\r\nPS2_LEFT_UP is pressed!");
		while(PS2_LEFT_UP){	
			if(millis() - systick_ms_bak >= 20) {
				systick_ms_bak = millis();
				ps2_write_read(ps2_buf);
			}
		}
		uart1_send_str((u8 *)"\r\nPS2_LEFT_UP is released!");
	}
	if(PS2_LEFT_DOWN) {
		uart1_send_str((u8 *)"\r\nPS2_LEFT_DOWN is pressed!");
		while(PS2_LEFT_DOWN){	
			if(millis() - systick_ms_bak >= 20) {
				systick_ms_bak = millis();
				ps2_write_read(ps2_buf);
			}
		}
		uart1_send_str((u8 *)"\r\nPS2_LEFT_DOWN is released!");
	}
	if(PS2_LEFT_LEFT) {
		uart1_send_str((u8 *)"\r\nPS2_LEFT_LEFT is pressed!");
		while(PS2_LEFT_LEFT){	
			if(millis() - systick_ms_bak >= 20) {
				systick_ms_bak = millis();
				ps2_write_read(ps2_buf);
			}
		}
		uart1_send_str((u8 *)"\r\nPS2_LEFT_LEFT is released!");
	}
	if(PS2_LEFT_RIGHT) {
		uart1_send_str((u8 *)"\r\nPS2_LEFT_RIGHT is pressed!");
		while(PS2_LEFT_RIGHT){	
			if(millis() - systick_ms_bak >= 20) {
				systick_ms_bak = millis();
				ps2_write_read(ps2_buf);
			}
		}
		uart1_send_str((u8 *)"\r\nPS2_LEFT_RIGHT is released!");
	}
	if(PS2_RIGHT_UP) {
		uart1_send_str((u8 *)"\r\nPS2_RIGHT_UP is pressed!");
		while(PS2_RIGHT_UP){	
			if(millis() - systick_ms_bak >= 20) {
				systick_ms_bak = millis();
				ps2_write_read(ps2_buf);
			}
		}
		uart1_send_str((u8 *)"\r\nPS2_RIGHT_UP is released!");
	}
	if(PS2_RIGHT_DOWN) {
		uart1_send_str((u8 *)"\r\nPS2_RIGHT_DOWN is pressed!");
		while(PS2_RIGHT_DOWN){	
			if(millis() - systick_ms_bak >= 20) {
				systick_ms_bak = millis();
				ps2_write_read(ps2_buf);
			}
		}
		uart1_send_str((u8 *)"\r\nPS2_RIGHT_DOWN is released!");
	}
	if(PS2_RIGHT_LEFT) {
		uart1_send_str((u8 *)"\r\nPS2_RIGHT_LEFT is pressed!");
		while(PS2_RIGHT_LEFT){	
			if(millis() - systick_ms_bak >= 20) {
				systick_ms_bak = millis();
				ps2_write_read(ps2_buf);
			}
		}
		uart1_send_str((u8 *)"\r\nPS2_RIGHT_LEFT is released!");
	}
	if(PS2_RIGHT_RIGHT) {
		uart1_send_str((u8 *)"\r\nPS2_RIGHT_RIGHT is pressed!");
		while(PS2_RIGHT_RIGHT){	
			if(millis() - systick_ms_bak >= 20) {
				systick_ms_bak = millis();
				ps2_write_read(ps2_buf);
			}
		}
		uart1_send_str((u8 *)"\r\nPS2_RIGHT_RIGHT is released!");
	}
	if(PS2_LEFT_1) {
		uart1_send_str((u8 *)"\r\nPS2_LEFT_1 is pressed!");
		while(PS2_LEFT_1){	
			if(millis() - systick_ms_bak >= 20) {
				systick_ms_bak = millis();
				ps2_write_read(ps2_buf);
			}
		}
		uart1_send_str((u8 *)"\r\nPS2_LEFT_1 is released!");
	}
	if(PS2_LEFT_2) {
		uart1_send_str((u8 *)"\r\nPS2_LEFT_2 is pressed!");
		while(PS2_LEFT_2){	
			if(millis() - systick_ms_bak >= 20) {
				systick_ms_bak = millis();
				ps2_write_read(ps2_buf);
			}
		}
		uart1_send_str((u8 *)"\r\nPS2_LEFT_2 is released!");
	}
	if(PS2_RIGHT_1) {
		uart1_send_str((u8 *)"\r\nPS2_RIGHT_1 is pressed!");
		while(PS2_RIGHT_1){	
			if(millis() - systick_ms_bak >= 20) {
				systick_ms_bak = millis();
				ps2_write_read(ps2_buf);
			}
		}
		uart1_send_str((u8 *)"\r\nPS2_RIGHT_1 is released!");
	}
	if(PS2_RIGHT_2) {
		uart1_send_str((u8 *)"\r\nPS2_RIGHT_2 is pressed!");
		while(PS2_RIGHT_2){	
			if(millis() - systick_ms_bak >= 20) {
				systick_ms_bak = millis();
				ps2_write_read(ps2_buf);
			}
		}
		uart1_send_str((u8 *)"\r\nPS2_RIGHT_2 is released!");
	}
	if(PS2_SELECT) {
		uart1_send_str((u8 *)"\r\nPS2_SELECT is pressed!");
		while(PS2_SELECT){	
			if(millis() - systick_ms_bak >= 20) {
				systick_ms_bak = millis();
				ps2_write_read(ps2_buf);
			}
		}
		uart1_send_str((u8 *)"\r\nPS2_SELECT is released!");
	}
	if(PS2_START) {
		uart1_send_str((u8 *)"\r\nPS2_START is pressed!");
		while(PS2_START){	
			if(millis() - systick_ms_bak >= 20) {
				systick_ms_bak = millis();
				ps2_write_read(ps2_buf);
			}
		}
		uart1_send_str((u8 *)"\r\nPS2_START is released!");
	}
}		
