
#ifndef KEYPAD_CONFIGURATION_H_
#define KEYPAD_CONFIGURATION_H_


#define KEYPAD_u8_PORT_ROW       DIO_u8_PORTC
#define KEYPAD_u8_PORT_COL       DIO_u8_PORTD


#define KEYPAD_u8_C1_PIN     DIO_u8_PIN7
#define KEYPAD_u8_C2_PIN     DIO_u8_PIN6
#define KEYPAD_u8_C3_PIN     DIO_u8_PIN5
#define KEYPAD_u8_C4_PIN     DIO_u8_PIN3


#define KEYPAD_u8_R1_PIN     DIO_u8_PIN5
#define KEYPAD_u8_R2_PIN     DIO_u8_PIN4
#define KEYPAD_u8_R3_PIN     DIO_u8_PIN3
#define KEYPAD_u8_R4_PIN     DIO_u8_PIN2


#define KEYPAD_u8_ROW_NUM     4
#define KEYPAD_u8_COL_NUM     4


#define KEYPAD_u8_DEBOUNCING_MS    20

#define KEYPAD_Au8_KEYS   {{'1', '2', '3', '+'}, \
						   {'4', '5', '6', '-'}, \
						   {'7', '8', '9', '*'}, \
						   {'0', '=', '%', '/'}}

#define KEYPAD_Au8Cols  {KEYPAD_u8_C1_PIN, KEYPAD_u8_C2_PIN, KEYPAD_u8_C3_PIN, KEYPAD_u8_C4_PIN}
#define KEYPAD_Au8ROWs  {KEYPAD_u8_R1_PIN, KEYPAD_u8_R2_PIN, KEYPAD_u8_R3_PIN, KEYPAD_u8_R4_PIN}

#endif
