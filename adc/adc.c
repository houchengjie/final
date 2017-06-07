#include "LPC11xx.h"                    // Device header

/*********************************
	ADC初始化
	**********************************/
	void ADC_Init(void)
	{
	  LPC_SYSCON->SYSAHBCLKCTRL|=(1<<16);
		LPC_IOCON->PIO1_11&=~0xBF;//配置PIO1_11为模拟输入模式
		LPC_IOCON->PIO1_11|=0x01;//PIO1_11模拟输入通道0
		LPC_SYSCON->PDRUNCFG&=~(0x01<<4);//ADC模块上电
		LPC_SYSCON->SYSAHBCLKCTRL|=(0x01<<13);//使能ADC模块时钟
		LPC_ADC->CR=(0x01<<7)|  //，选择ADC7
		            ((SystemCoreClock/1000000-1)<<8)|//转换时钟1MHz
		            (0<<16)|//软件控制转换操作
		            (0<<17)|//使用11clocks转换
		            (0<<24)|//ADC转换停止
		            (0<<27);//直接启动ADC转换，此位无效
	}