

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_


#include "STD_TYPES.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* LCD Data bits mode configuration, its value should be 4 or 8*/
#define LCD_DATA_BITS_MODE 4

#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif

/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID                 DIO_u8_PORTA
#define LCD_RS_PIN_ID                  DIO_u8_PIN3

#define LCD_E_PORT_ID                  DIO_u8_PORTA
#define LCD_E_PIN_ID                   DIO_u8_PIN2

#define LCD_DATA_PORT_ID               DIO_u8_PORTB

#if (LCD_DATA_BITS_MODE == 4)

#define LCD_DB4_PIN_ID                 DIO_u8_PIN0
#define LCD_DB5_PIN_ID                 DIO_u8_PIN1
#define LCD_DB6_PIN_ID                 DIO_u8_PIN2
#define LCD_DB7_PIN_ID                 DIO_u8_PIN4

#endif

/* LCD Commands */
#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define DDRAM_INCREASE_BY1                   0x06
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80




/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void);

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(u8 command);

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(u8 data);

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char *Str);

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(u8 row,u8 col);


/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void);



/*
 * This Command sends a pluse to enable pin of the lcd
 * */

void LCD_voidSendEnablePulse(void);


/*
 * This Function takes a signed 32bit integers from the user and displays it on the LCD
 * */
void LCD_DisplayNumber(s32 Number);


/**
 * This function is used to send binary numbers to the LCD
 * */
void LCD_DisplayBinary(s8 Copy_s8Data);

/*
 * This Function is used to Send Floating numbers to thec CLD
 * */

void LCD_DisplayFloats(f32 Copy_f32FloatNum);


/*
 * This function is used to send special char
 * */

void LCD_voidSendSpechialChar(u8 *Copy_u8Pattern, u8 Copy_u8PatternID, u8 Copy_u8XPossition, u8 Copy_u8YPossition);



#endif /* HAL_LCD_LCD_H_ */
