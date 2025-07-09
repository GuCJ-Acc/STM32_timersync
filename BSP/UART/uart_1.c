#include "uart_1.h"
#include "stdio.h"

#define printf_UART_1(...) HAL_UART_Transmit(&huart1,\
										(uint8_t *)u_buf,\
										 sprintf((char*)u_buf,__VA_ARGS__),\
										 0xffff)

