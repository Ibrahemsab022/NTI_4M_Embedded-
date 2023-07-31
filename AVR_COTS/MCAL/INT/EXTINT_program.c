
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTINT_interface.h"
#include "EXTINT_private.h"
#include "EXTINT_reg.h"


//Global Pointer to function: an array of ptrs to functions to hold the callback funcs of the app

static void (*EXTINT_ApfuncEXTINT[3])(void);
//Copy_u8ExtIntNum select INT0 INT1 INT2


//Copy_u8EdgeIntSource select sense : Rising,Falling, LOW LEVEL, ANYLOGICAL CHANGE
void EXTINT_voidEnable(u8 Copy_u8ExtIntNum , u8 Copy_u8EdgeIntSource)
{
	switch(Copy_u8ExtIntNum)
	{
	case EXTINT_INT0:
			switch(Copy_u8EdgeIntSource)
			{
				case EXTINT_RAISING_EDGE:		SET_BIT(MCUCR, MCUCR_ISC00); SET_BIT(MCUCR, MCUCR_ISC01); break;
				case EXTINT_FALLING_EDGE:		CLR_BIT(MCUCR, MCUCR_ISC00); SET_BIT(MCUCR, MCUCR_ISC01); break;
				case EXTINT_ANY_LOGICAL_CHANGE: SET_BIT(MCUCR, MCUCR_ISC00); CLR_BIT(MCUCR, MCUCR_ISC01); break;
				case EXTINT_LOW_LEVEL:			CLR_BIT(MCUCR, MCUCR_ISC00); CLR_BIT(MCUCR, MCUCR_ISC01); break;
				default: /*do nothing*/ break;

			}
			/* Enable Ext Int 0 */
			SET_BIT(GICR,GICR_INT0);
	break;

	case EXTINT_INT1:
			switch(Copy_u8EdgeIntSource)
			{
				case EXTINT_RAISING_EDGE:		SET_BIT(MCUCR, MCUCR_ISC11); SET_BIT(MCUCR, MCUCR_ISC10); break;
				case EXTINT_FALLING_EDGE:		SET_BIT(MCUCR, MCUCR_ISC11); CLR_BIT(MCUCR, MCUCR_ISC10); break;
				case EXTINT_ANY_LOGICAL_CHANGE: CLR_BIT(MCUCR, MCUCR_ISC11); SET_BIT(MCUCR, MCUCR_ISC10); break;
				case EXTINT_LOW_LEVEL:			CLR_BIT(MCUCR, MCUCR_ISC11); CLR_BIT(MCUCR, MCUCR_ISC10); break;
				default: /*do nothing*/ break;

			}
			/* Enable Ext Int 1 */
			SET_BIT(GICR,GICR_INT1);
	break;
	case EXTINT_INT2:
				switch(Copy_u8EdgeIntSource)
				{
					case EXTINT_RAISING_EDGE:	SET_BIT(MCUCSR, MCUCSR_ISC2); break;
					case EXTINT_FALLING_EDGE:	CLR_BIT(MCUCSR, MCUCSR_ISC2); break;
					default: break;
				}
				/* Enable Ext Int 2 */
				SET_BIT(GICR,GICR_INT2);
	break;


	}
}


/*This function is used to disable the interrupts based on the interrupt number*/
void EXTINT_voidDisable(u8 Copy_u8ExtIntNum)
{
	switch (Copy_u8ExtIntNum)
	{
		case EXTINT_INT0: CLR_BIT(GICR,GICR_INT0); break;
		case EXTINT_INT1: CLR_BIT(GICR,GICR_INT1); break;
		case EXTINT_INT2: CLR_BIT(GICR,GICR_INT2); break;
	}
}
//Copy_u8ExtIntIndex to select INT0 INT1 INT2
//Copy_pfun : the address of the function which will be existed inside ISR
void EXTINT_voidSetCallBack(void(*Copy_pfun)(void),u8 Copy_u8ExtIntIndex)
{
	EXTINT_ApfuncEXTINT[Copy_u8ExtIntIndex] = Copy_pfun;
}

/* ISR Function for External Interrupt 0 */
// __vector_1 for linker
// __attribute__((signal)) to prevent optimization
void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	EXTINT_ApfuncEXTINT[EXTINT_INT0]();
}
/* ISR Function for External Interrupt 0 */
void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{
	EXTINT_ApfuncEXTINT[EXTINT_INT1]();
}
/* ISR Function for External Interrupt 0 */
void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
	EXTINT_ApfuncEXTINT[EXTINT_INT2]();
}


