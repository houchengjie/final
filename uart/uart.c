#include "LPC11xx.h"                    // Device header
#include<stdio.h>
#include<string.h>
#define UART_BPS 9600//����ͨ�Ų�����
/**********************************
 ���ڳ�ʼ��������Ϊ8λ����λ��1λֹͣλ������żУ�飬������Ϊ115200
	***********************************/
	void UART_Init(void)
	{
	 uint16_t usFdiv;
	 LPC_SYSCON->SYSAHBCLKCTRL|=(1<<16); //��IOCON����ʱ��
	 LPC_IOCON->PIO1_6&=~0x07;
	 LPC_IOCON->PIO1_6|=(1<<0);//����p1.6ΪRXD
	 LPC_IOCON->PIO1_7&=~0x07;
	 LPC_IOCON->PIO1_7|=(1<<0);//����P1.7ΪTXD
	 LPC_SYSCON->SYSAHBCLKCTRL|=(1<<12);//��UART���ܲ���ʱ��
	 LPC_SYSCON->UARTCLKDIV=0x01;//UARTʱ�ӷ�Ƶ
	 LPC_UART->LCR=0x83;//�������ò�����
	 usFdiv=(SystemCoreClock/LPC_SYSCON->UARTCLKDIV/16)/UART_BPS;//���ò�����
	 LPC_UART->DLM = usFdiv/256;
	 LPC_UART->DLL = usFdiv % 256;
	 LPC_UART->LCR = 0x03;//����������
	 LPC_UART->FCR = 0x07;
	}
	/************************************
	�򴮿ڷ����ֽ����ݣ����ȴ����ݷ�����ɣ�ʹ�ò�ѯ��ʽ
	ucDat:Ҫ���͵�����
	*************************************/
	void UART_SendByte(uint8_t ucDat)
	{
	 LPC_UART->THR=ucDat;//д������
	 while((LPC_UART->LSR&0x40)==0);//�ȴ����ݷ������		
	
	}
	/*************************************
	�򴮿ڷ����ַ���
	puiStr:Ҫ���͵��ַ���ָ��
	**************************************/
	void UART_SendStr(char * pucStr)
	{
	 
		while(1){
		      if(*pucStr=='\0')break;//�������������˳�
			    UART_SendByte(*pucStr++);
		
		}
	}