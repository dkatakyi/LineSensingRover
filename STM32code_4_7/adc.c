/*ENEL 387*/
/*Author: Daniel Takyi*/
/*Filename: adc.c*/

#include "stm32f10x.h"
#include "adc.h"

void adc_init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPAEN;
	
	//GPIOA->CRL = 0x44444004;
	GPIOA->CRL &= 0xFFFFF00F;
	
	
	
	
	ADC1->CR2 = 0x1;
	
	
}

uint32_t adc_read(void)
{

	//ADC1->SQR3 = 0x1;
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




