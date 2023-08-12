#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMERS_Interface.h"
#include "TIMERS_Private.h"
#include "TIMERS_Config.h"


static void (*Global_pfPtrToFunc)(void) = NULL;
u16 Global_u16NumOfOverFlows = OVERFLOW_NUM;



void TIMER0_voidSetCallBack(void (*PtrToFunc)(void))
{
	if (PtrToFunc != NULL)
	{
		Global_pfPtrToFunc = PtrToFunc;
	}

	else
	{
		/*NULL PTR ERROR*/
	}
}


void TIMER0_voidInit(void)
{
	/*setting the force output compare mdoe*/
	TCCR0 -> TCCR0_FOC0 = FOC_INIT_MODE;

	/*Setting the mode of operation*/
#if TIMER_MODE == NORMAL_MODE
	TCCR0 -> TCCR0_WGM00 = 0;
	TCCR0 -> TCCR0_WGM01 = 0;

#elif TIMER_MODE == CTC_MODE
	TCCR0 -> TCCR0_WGM00 = 0;
    TCCR0 -> TCCR0_WGM01 = 0;


#elif TIMER_MODE == PHASE_CORRECT_MODE
	TCCR0 -> TCCR0_WGM00 = 1;
    TCCR0 -> TCCR0_WGM01 = 0;


#elif TIMER_MODE == CTC_MODE
	TCCR0 -> TCCR0_WGM00 = 0;
    TCCR0 -> TCCR0_WGM01 = 1;

#elif TIMER_MODE == FAST_PWM_MODE
	TCCR0 -> TCCR0_WGM00 = 1;
    TCCR0 -> TCCR0_WGM01 = 1;

#else
#error Wrong config of TIMER_MODE
#endif


    /*Setting the Compare match output mode*/
    TCCR0 -> TCCR0_COM = COMP_MATCH_OUTPUT_MODE;

    /*Setting the interrupt mode*/
#if OVERFLOW_INTERRUPT_STATE == INERRUPT_DISABLED
    CLR_BIT(TIMSK, TIMSK_TOIE0);

#elif OVERFLOW_INTERRUPT_STATE == INTERRUPT_ENABLED
    SET_BIT(TIMSK, TIMSK_TOIE0);
#else
#error Wrong Config of OVERFLOW_INTERRUPT_STATE
#endif

}

void TIMER0_voidStart(void)
{
	/*Setting the prescaler (Setting the prescaler will start the Timer)*/
	TCCR0 -> TCCR0_CS = TIMER_PRESCALER;
}

void TIMER0_voidStop(void)
{
	/*Setting the prescaler to 0 (dsiconnecting the clk)*/
	TCCR0 -> TCCR0_CS = CLK_DISCONNECTED;
}

void TIMER0_voidPreload(u8 Copy_u8PreloadVal)
{
	TCNT0 = Copy_u8PreloadVal;
}


void TIMER0_voidGeneratePWM(u8 DutyCycle)
{

	if (COMP_MATCH_OUTPUT_MODE == OC0_CLEAR)
	{

		OCR0 = (u8)((float)(DutyCycle / 100.0) * 256);
		//OCR0 = ((DutyCycle * 256)/100);
	}

	else if (COMP_MATCH_OUTPUT_MODE == OC0_SET)
	{
		OCR0 = ((u8)((1 - (float)(DutyCycle/100))) * 256);
	}




}


void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	static u16 Local_u16Counter = 0;

	Local_u16Counter++;

	if (Local_u16Counter == Global_u16NumOfOverFlows)
	{
		Local_u16Counter = 0;

		/*Invoke the Callback function*/
		if (Global_pfPtrToFunc != NULL)
		{
			Global_pfPtrToFunc();
		}

		else
		{
			/*NULL Ptr error*/
		}

		/*Load TCNT0 with the same value if you want to make it predioc*/
		/*TCNT0 = x*/

	}

}



