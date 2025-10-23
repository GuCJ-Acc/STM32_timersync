#ifndef __PPS_H
#define __PPS_H	 
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "stdio.h"
#include "uart_1.h"
#include <string.h>


int checkNum(const char *gprmcContext);
void print_PPS_GPS();

#endif 