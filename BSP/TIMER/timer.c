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
}