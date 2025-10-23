#ifndef __UART_1_H
#define __UART_1_H	 
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

extern uint8_t uart1_buf[256];

//串口DMA发送方式（非阻塞），增加延时以保证数据的完整性	
#define UART1_printf_DMA(...) HAL_UART_Transmit_DMA(&huart1,\
												   (uint8_t *)uart1_buf,\
													sprintf((char*)uart1_buf,__VA_ARGS__))


//普通串口发送方式（阻塞）
#define UART1_printf_Tr(...) HAL_UART_Transmit(&huart1,\
											  (uint8_t *)uart1_buf,\
											   sprintf((char*)uart1_buf,__VA_ARGS__),\
											   0xffff)



#endif 