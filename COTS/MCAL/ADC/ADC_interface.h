

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "STD_TYPES.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5

/*ADC Channels*/
#define ADC_CH_0	     0b00000
#define ADC_CH_1		 0b00001
#define ADC_CH_2         0b00010
#define ADC_CH_3         0b00011
#define ADC_CH_4         0b00100
#define ADC_CH_5         0b00101
#define ADC_CH_6         0b00110
#define ADC_CH_7		 0b00111






/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(void);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
u16 ADC_readChannel(u8 channel_num);

#endif /* ADC_INTERFACE_H_ */
