#ifndef __UART_1_H
#define __UART_1_H	 
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

#define UART1_printf_DMA(...) HAL_UART_Transmit_DMA(&huart1,\
												   (uint8_t *)uadc_buf,\
													sprintf((char*)uadc_buf,__VA_ARGS__))



#endif 