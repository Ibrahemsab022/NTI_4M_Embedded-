#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_Registers.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(void)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 00 to choose to connect external reference voltage by input this voltage through AREF pin
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX = (1<<ADMUX_REFS0); // AREF=AVCC

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = 011 to choose ADC_Clock = F_CPU/8 = 1Mhz/8 = 125Khz --> ADC must operate in range 50-200Khz
	 */
	ADCSRA = (1<<ADCSRA_ADEN) | (1<<ADCSRA_ADPS2) | (1<<ADCSRA_ADPS1) | (1<<ADCSRA_ADPS0); //enable adc + PRrescalar div factor =128
}

u16 ADC_readChannel(u8 channel_num)
{

	/*Selecting The ADC Channel*/
	ADMUX |= channel_num;

	/*Starting Conv*/
	ADCSRA |= (1 << 6);

	/*waiting for the conv done flag*/
	while (GET_BIT(ADCSRA, ADCSRA_ADIF) != 1);


	/*Clearing the conv done flag*/
	SET_BIT(ADCSRA, ADCSRA_ADIF);

	return ADC; /* Read the digital value from the data register */
}
