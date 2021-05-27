/*ENEL 387*/
/*Author: Daniel Takyi*/
/*Filename: clocks.c*/



 #include "stm32f10x.h"
 #include "clocks.h"
 
 
 void clockInit(void)
{
    uint32_t temp = 0x00;
    //If you hover over the RCC you can go to the definition and then
    //see it is a structure of all the RCC registers.  Then you can
    //simply assign a value.
		RCC->CFGR = 0x00050002;     // MCO: No clock,
                                // PLLMUL X3, PREDIV1 is PLL input

    RCC->CR =  0x01010081;      // Turn on PLL, HSE, HSI

    while (temp != 0x02000000)  // Wait for the PLL to stabilize
    {
        temp = RCC->CR & 0x02000000; //Check to see if the PLL lock bit is set
    }




}





