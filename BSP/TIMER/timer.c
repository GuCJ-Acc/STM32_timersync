#include "timer.h"
#include "led.h"
#include "stdio.h"

/**************************************************************************
函数功能：定时器TIMx的中断函数
入口参数：[*htim]: 定时器的指针
返回  值：无
说    明：定时器的中断函数处理
**************************************************************************/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    // 检查定时器是否为TIM3定时器
    if(htim->Instance == TIM3)
	{
		// LED0_Toggle;

        TIM3_IRQProcess();
	}
}


/**************************************************************************
函数功能：定时器TIMx的PWM输出占空比CCRx设置函数
入口参数：[TIMx]:TIM1~8、[CHx]:TIM_CHANNEL_1~4、[CCR]:0~65535（舵机控制时：0~2500）
返回  值：无
说    明：通过设置TIMx寄存器CCRx的值设置输出通道的占空比
**************************************************************************/
void TIM_SetCCR(TIM_TypeDef *TIMx, uint32_t CHx, uint16_t CCR) 
{    
    if(CHx==TIM_CHANNEL_1)    TIMx->CCR1 = CCR;
    if(CHx==TIM_CHANNEL_2)    TIMx->CCR2 = CCR;
    if(CHx==TIM_CHANNEL_3)    TIMx->CCR3 = CCR;
    if(CHx==TIM_CHANNEL_4)    TIMx->CCR4 = CCR;
} 


/**************************************************************************
函数功能：定时器TIM3的中断处理函数
入口参数：无
返回  值：无
说    明：处理定时器TIM3的中断内容
**************************************************************************/
void TIM3_IRQProcess(void)
{
    LED0_Toggle;    // LED0 取反

    // TIM_SetCCR(TIM3, TIM_CHANNEL_1, 1500);      // TIM3_CH1 --> PA6
    // TIM3->CCR1 = 1500;

    // RX: PA_10,  TX: PA_9
    // UART1_printf_DMA("$GPRMC,004015,A,2812.0498,N,11313.1361,E,0.0,180.0,150122,3.9,W,A*\r\n");

    print_PPS_GPS();
}




/**************************************************************************
函数功能：检查GPS数据函数
入口参数：无
返回  值：无
说    明：用于处理PPS的GPS数据
**************************************************************************/
int ss=0;
int mm=0;
int hh=0;

unsigned char result;
int i;

int checkNum(const char *gprmcContext)
{
    if (gprmcContext == NULL) 
    {
        return -1;
	}
    result = gprmcContext[1];

    for (i = 2; gprmcContext[i] != '*' && gprmcContext[i] != '\0'; i++)
    {
        result ^= gprmcContext[i];
    }

    if (gprmcContext[i] != '*') 
    {
        return -1;
    }

    return result;
}



/**************************************************************************
函数功能：GPS数据生成函数
入口参数：无
返回  值：无
说    明：用于处理PPS的GPS数据
**************************************************************************/
char gprmcStr[7]="$GPRMC,";
int chckNum=0;
char chckNumChar[2];

char value_1[100]="";
char value_2[100]="";

void print_PPS_GPS()
{
    // 计算时间，秒/分钟/小时
    if(ss < 59)
    {  ss++;  }
    else
    {  ss = 0;
        if(mm < 59)
        {  mm++; }
        else
        {  mm = 0;
            if(hh < 23)
            {  hh++;  }
            else
            {  hh = 0;  }
        }
    }

    // "$GPRMC,004015,A,2812.0498,N,11313.1361,E,0.0,180.0,150122,3.9,W,A*";
    sprintf(value_2, "%s%02d%02d%02d%s", gprmcStr, hh, mm, ss, ".00,A,2237.496474,N,11356.089515,E,0.0,225.5,230520,2.3,W,A*");
	strcpy(value_1, value_2);
	chckNum =checkNum(value_1);                 // 检查GPS数据
	sprintf(chckNumChar, "%02X", chckNum);

	UART1_printf_Tr("%s", value_2);             // 输出GPS字符串数据
    UART1_printf_Tr("%s\n", chckNumChar);       // 检查GPS数据完整性，并换行输出

}