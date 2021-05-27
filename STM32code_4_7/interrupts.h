/*ENEL 387*/
/*Author: Daniel Takyi*/
/*Filename: interrupts.h*/

#include <stdint.h>



void EXTI0_init(void);

void EXTI7n13_init(void);

void EXTI0_IRQHandler(void);

void EXTI7_IRQHandler(void);

void EXTI13_IRQHandler(void);
