/***************************************************************************************/
/***************************************************************************************/
#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H

/*
/* Please Select the configuration of the initial state of the PORTs Initial direction:
 * 																	1- DIO_u8_INITIAL_OUTPUT
 * 																	2- DIO_u8_INITIAL_INPUT
 */
#define DIO_u8_PORTA_INIT_DIR    DIO_u8_INITIAL_INPUT
#define DIO_u8_PORTB_INIT_DIR    DIO_u8_INITIAL_INPUT
#define DIO_u8_PORTC_INIT_DIR    DIO_u8_INITIAL_INPUT
#define DIO_u8_PORTD_INIT_DIR    DIO_u8_INITIAL_INPUT


/*
 * Please Select the configuration of the initial state of the PORTs Initial Value:
 * 																	1- DIO_u8_OUTPUT_LOW
 * 																	2- DIO_u8_OUTPUT_HIGH
 * 																	3- DIO_u8_INPUT_FLOATING
 * 																	4- DIO_u8_INPUT_PULLUP
 */
#define DIO_u8_PORTA_INIT_VAL   DIO_u8_INPUT_FLOATING
#define DIO_u8_PORTB_INIT_VAL   DIO_u8_INPUT_FLOATING
#define DIO_u8_PORTC_INIT_VAL   DIO_u8_INPUT_FLOATING
#define DIO_u8_PORTD_INIT_VAL   DIO_u8_INPUT_FLOATING




#endif
/***************************************************************************************/
