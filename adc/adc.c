#include "LPC11xx.h"                    // Device header

/*********************************
	ADC��ʼ��
	**********************************/
	void ADC_Init(void)
	{
	  LPC_SYSCON->SYSAHBCLKCTRL|=(1<<16);
		LPC_IOCON->PIO1_11&=~0xBF;//����PIO1_11Ϊģ������ģʽ
		LPC_IOCON->PIO1_11|=0x01;//PIO1_11ģ������ͨ��0
		LPC_SYSCON->PDRUNCFG&=~(0x01<<4);//ADCģ���ϵ�
		LPC_SYSCON->SYSAHBCLKCTRL|=(0x01<<13);//ʹ��ADCģ��ʱ��
		LPC_ADC->CR=(0x01<<7)|  //��ѡ��ADC7
		            ((SystemCoreClock/1000000-1)<<8)|//ת��ʱ��1MHz
		            (0<<16)|//�������ת������
		            (0<<17)|//ʹ��11clocksת��
		            (0<<24)|//ADCת��ֹͣ
		            (0<<27);//ֱ������ADCת������λ��Ч
	}