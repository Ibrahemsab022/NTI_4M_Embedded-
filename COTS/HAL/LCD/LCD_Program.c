#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h> /* For the delay functions */
#include "lcd.h"
#include "DIO_Interface.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */

void LCD_voidSendEnablePulse(void)
{
	DIO_voidSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, DIO_u8_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, DIO_u8_LOW);

}
void LCD_init(void)
{
	/* Configure the direction for RS and E pins as output pins */
	DIO_voidSetPinDirection(LCD_RS_PORT_ID, LCD_RS_PIN_ID, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(LCD_E_PORT_ID, LCD_E_PIN_ID, DIO_u8_OUTPUT);

	_delay_ms(40);		/* LCD Power ON delay always > 15ms */


	/* Configure 4 pins in the data port as output pins */
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, DIO_u8_OUTPUT);

	/* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);


	LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(u8 command)
{
	/*Clearing RS Pin for Writing Operation*/
	DIO_voidSetPinValue(LCD_RS_PORT_ID, LCD_RS_PIN_ID, DIO_u8_LOW);


	/*Sending The MSB 4 bits*/
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, GET_BIT(command, 7));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, GET_BIT(command, 6));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, GET_BIT(command, 5));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, GET_BIT(command, 4));

	/*sending enable pulse*/
	LCD_voidSendEnablePulse();

	/*Sending The LSB 4 bits*/
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, GET_BIT(command, 3));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, GET_BIT(command, 2));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, GET_BIT(command, 1));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, GET_BIT(command, 0));
	
	/*sending enable pulse*/
	LCD_voidSendEnablePulse();
	

}

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(u8 data)
{
	/*Setting RS Pin for data writing operation*/
	DIO_voidSetPinValue(LCD_RS_PORT_ID, LCD_RS_PIN_ID, DIO_u8_HIGH);

	/*Sending The MSB 4 bits*/
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, GET_BIT(data, 7));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, GET_BIT(data, 6));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, GET_BIT(data, 5));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, GET_BIT(data, 4));

	/*sending enable pulse*/
	LCD_voidSendEnablePulse();

	/*Sending The LSB 4 bits*/
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_DB7_PIN_ID, GET_BIT(data, 3));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_DB6_PIN_ID, GET_BIT(data, 2));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_DB5_PIN_ID, GET_BIT(data, 1));
	DIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_DB4_PIN_ID, GET_BIT(data, 0));

	/*sending enable pulse*/
	LCD_voidSendEnablePulse();

}

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char *Str)
{
	if (Str != NULL)
	{
		u8 Local_u8Itterator = 0;

		while (Str[Local_u8Itterator] != '\0')
		{

			LCD_displayCharacter(Str[Local_u8Itterator]);
			Local_u8Itterator++;
		}
	}

	else
	{
		/*Do nothing*/
	}
}


void LCD_DisplayNumber(s32 Copy_s32Number)
{
	char Local_charDigitsArr[10];
	u8 Local_u8Itterator1 = 0;
	s8 Local_s8Itterator2;

	if (Copy_s32Number == 0)
	{
		LCD_displayCharacter('0');
	}

	if (Copy_s32Number < 0)
	{
		LCD_displayCharacter('-');
		Copy_s32Number *= -1;
	}

	while (Copy_s32Number != 0)
	{

		Local_charDigitsArr[Local_u8Itterator1] = ((Copy_s32Number % 10) + '0');

		Copy_s32Number /= 10;

		Local_u8Itterator1++;

	}

	for (Local_s8Itterator2 = Local_u8Itterator1 - 1; Local_s8Itterator2 >= 0; Local_s8Itterator2--)
	{
		LCD_displayCharacter(Local_charDigitsArr[Local_s8Itterator2]);
	}

}

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(u8 row,u8 col)
{
	u8 Local_u8DDRAMAddress = 0;

	if (row == 1)
	{
		Local_u8DDRAMAddress = col;
	}

	else if (row == 2)
	{
		Local_u8DDRAMAddress = 0x40 + col;
	}

	else if (row == 3)
	{
		Local_u8DDRAMAddress = 0x14 + col;
	}

	else if (row == 4)
	{
		Local_u8DDRAMAddress = 0x54 + col;
	}


	SET_BIT(Local_u8DDRAMAddress, 7);

	LCD_sendCommand(Local_u8DDRAMAddress);
}


void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}
