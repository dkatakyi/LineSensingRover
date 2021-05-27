/*ENEL 387*/
/*Author: Daniel Takyi*/
/*Filename: sensors.c*/

#include "stm32f10x.h"
#include "sensors.h"



void RIGHTsense_init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
}


uint32_t RIGHTsense_read(void)
{
	uint32_t temp;
	temp = GPIOB->IDR;
	temp &= 0x40;
	temp = (temp >> 0x06);
	
	return temp;
}


void FRONTsense_init(void)	//CHANGED FRONT SENSOR FROM PA5 TO PA3 ************************************
{
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN;
	
	GPIOA->CRL &= 0xFFFF0FFF;
	                         
	ADC1->CR2 = 0x1;
	
}


uint32_t FRONTsense_read(void)
{
	ADC1->SQR3 = 0x3;
	ADC1->CR2 = 0x1;
	uint32_t test = ADC1->SR;
	test &= 0x2;
	while (test != 0x2)
	{
		test = ADC1->SR;
		test &= 0x2;
	}
	return ADC1->DR;
	
}

uint32_t FRONTDIGsense_read(void)
{
	uint32_t temp;
	temp = GPIOB->IDR;
	temp &= 0x80;
	temp = (temp >> 0x07);
	
	return temp;
}

void LINEsense_init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
}


uint32_t LINEsense_read(void)
{
	uint32_t temp;
	temp = GPIOC->IDR;
	temp &= 0x2000;
	temp = (temp >> 0x0D);
	
	return temp;
}

