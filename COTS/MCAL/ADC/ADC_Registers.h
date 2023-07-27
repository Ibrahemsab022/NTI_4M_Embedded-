#ifndef ADC_REGISTERS_H_
#define ADC_REGISTERS_H_


#define ADMUX			*((volatile u8*) 0x27)
#define ADMUX_REFS1      7u
#define ADMUX_REFS0      6u
#define ADMUX_ADLAR      5u
#define ADMUX_MUX4       4u
#define ADMUX_MUX3       3u
#define ADMUX_MUX2       2u
#define ADMUX_MUX1       1u
#define ADMUX_MUX0       0u

#define ADCSRA			*((volatile u8 *) 0x26)
#define ADCSRA_ADEN     7u
#define ADCSRA_ADSC     6u
#define ADCSRA_ADATE    5u
#define ADCSRA_ADIF     4u
#define ADCSRA_ADIE     3u
#define ADCSRA_ADPS2    2u
#define ADCSRA_ADPS1    1u
#define ADCSRA_ADPS0    0u


#define ADCH		*((volatile u8 *) 0x25)
#define ADCL  		*((volatile u8 *) 0x24)

#define ADC			*((volatile u16 *) 0x24)

#define SFIOR		*((volatile u8 *) 0x50)
#define SFIOR_ADTS2      2u
#define SFIOR_ADTS1      1u
#define SFIOR_ADTS0      0u












#endif
