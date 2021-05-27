/*ENEL 387*/
/*Author: Daniel Takyi*/
/*Filename: sensors.h*/

#include <stdint.h>


void RIGHTsense_init(void);


uint32_t RIGHTsense_read(void);


void FRONTsense_init(void);


uint32_t FRONTsense_read(void);


uint32_t FRONTDIGsense_read(void);


void LINEsense_init(void);


uint32_t LINEsense_read(void);
