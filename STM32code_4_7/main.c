/*Author: Daniel Takyi*/
/*Filename: main.c*/


#include <stdint.h>
#include "stm32f10x.h"
#include "clocks.h"
#include "pwm.h"
#include "sensors.h"
#include "interrupts.h"



uint32_t convert(uint32_t reg_data)
{
	reg_data *= 0x64;
	reg_data /= 0xfff;
	
	
	return reg_data;
}


void delay(uint32_t count)//value of 6000 gives approximately 1ms of delay
{
	int i = 0;
	for(i = 0; i < count; i++)
	{
	}
}

	
int main()
{
	clockInit();
	
	pwmInit();
	
	RIGHTsense_init();
	
	LINEsense_init();
	 
	FRONTsense_init();
	
//	EXTI7n13_init();
	

	while((GPIOA->IDR & 0x1) != 0x1)
	{}
	
	int i;
	int count = 0;
	int j;
	int line = 0;
	int	targetNO = 0;	

	while(targetNO < 3)
	{
		
		while(LINEsense_read() == 0x0)
		{
			PWMForward();
		}
		
		for(j = 0; j < 8000000; j++)
		{
			while(LINEsense_read() == 0x1)
			{
				if(LINEsense_read() == 0x0)
				{
					line++;
				}
			}
		}
		
		PWMStop();
		for(j = 0; j < 7; j++)
		{
			GPIOC->ODR ^= line << 8;
			delay(3000000);
		}
		targetNO++;
	}
	
	while(1)
	{}
		

		
//	while(1)
//	{
//		while(LINEsense_read() == 0x1 )
//		{
//			PWMForward();
//			if(FRONTDIGsense_read() == 0x0 && count == 0)
//			{
//				PWMStop();
//				delay(2000000);
//				PWMLeft();
//				delay(5800000);
//				PWMStop();
//				delay(2000000);
//				PWMForward();
//				delay(2000000);
//				PWMStop();
//				delay(2000000);
//				PWMRight();
//				delay(7800000);
//				PWMStop();
//				delay(2000000);
//				PWMForward();
//				delay(2000000);
//				PWMStop();
//				delay(2000000);
//				PWMRight();
//				delay(7800000);
//				PWMStop();
//				delay(2000000);
//				while(LINEsense_read() == 0x0)
//				{
//					PWMForward();
//				}
//				delay(2000000);
//				PWMStop();
//				delay(2000000);
//				count++;
//			}
//			while(convert(FRONTsense_read()) > 80 && (count == 1))
//			{
//			PWMStop();
//			
//			}
//		}
//		
//		delay(3000);		
//		if(LINEsense_read() == 0x0)
//		{
//			PWMStop();
//			delay(6000);
//			
//			for(i = 0; i < 400000 && LINEsense_read() == 0x0; i++)
//			{
//				PWMSharpLeft();
//			}
//			PWMStop();
//			delay(6000);
//		
//			
//			for(i = 0; i < 800000 && LINEsense_read() == 0x0; i++)
//			{
//				PWMSharpRight();
//			}
//			
//			
//			while(LINEsense_read() == 0x0)
//			{
//				PWMStop();
//			}
//		}

//}
}


	