
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"

#define SREG    *((volatile u8*)0x5F)
//enable global interrupt
void GIE_voidGlobalInterruptEnable(void)
{
	/*This is an atomic assembly instruction that is used to enable GIE*/
		asm ("SEI");
}
//disable interrupt
void GIE_voidGlobalInterruptDisable(void)
{
	/*This is an atomic assembly instruction that is used to disable GIE*/
		asm("CLI");
}
