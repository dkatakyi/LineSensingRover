/*ENEL 387*/
/*Author: Daniel Takyi*/
/*Filename: interrupts.c*/

 #include "stm32f10x.h"
 #include "interrupts.h"





void EXTI7n13_init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;		
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	GPIOC->CRH &= 0xFFFFFF00;
	GPIOC->CRH |= 0x00000033;
	
	
//	AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI7_PB;
//	EXTI->IMR |= EXTI_IMR_MR7;
//	EXTI->RTSR |= EXTI_RTSR_TR7;	
//	NVIC_EnableIRQ(EXTI9_5_IRQn);
	
	AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI13_PC;
	EXTI->IMR |= EXTI_IMR_MR13;
	EXTI->RTSR |= EXTI_RTSR_TR13;
	NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI7_IRQHandler(void)
{
	EXTI->PR |= EXTI_PR_PR7;
	
	
}

int lines = 0;

void EXTI13_IRQHandler(void)
{

//	if (EXTI->PR & EXTI_PR_PR13)
//	{
//		delay(1000);
//		lines++;
//	}
	
	EXTI->PR |= EXTI_PR_PR13;
	GPIOC->ODR ^= GPIO_ODR_ODR9;
	
}

