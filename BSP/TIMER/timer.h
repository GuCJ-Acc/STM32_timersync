#ifndef __TIMER_H
#define __TIMER_H	 
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

void TIM_SetCCR(TIM_TypeDef *TIMx, uint32_t CHx, uint16_t CCR);
void TIM3_IRQProcess(void);

#endif 