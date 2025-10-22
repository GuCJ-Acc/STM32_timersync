#ifndef __TIMER_H
#define __TIMER_H	 
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "uart_1.h"
#include <string.h>

extern uint8_t uart1_buf[256];

void TIM_SetCCR(TIM_TypeDef *TIMx, uint32_t CHx, uint16_t CCR);
void TIM3_IRQProcess(void);

int checkNum(const char *gprmcContext);
void print_PPS_GPS();

#endif 