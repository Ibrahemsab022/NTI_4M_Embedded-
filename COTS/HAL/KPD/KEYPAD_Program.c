
/****************************************************/
/* Header files Inclusions						    */
/****************************************************/
#include "util/delay.h"

#include "KEYPAD_Config.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Config.h"

#include "KEYPAD_Interface.h"
#include "KEYPAD_Private.h"
#include "KEYPAD_Config.h"

u8 KEYPAD_Au8Keys [KEYPAD_u8_ROW_NUM][KEYPAD_u8_COL_NUM] = KEYPAD_Au8_KEYS;

u8 KEYPAD_Au8RowsPins[KEYPAD_u8_ROW_NUM] = KEYPAD_Au8ROWs;
u8 KEYPAD_Au8ColsPins[KEYPAD_u8_COL_NUM] = KEYPAD_Au8Cols;

/*********************************************************************************/
/* Function: KPD_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize KEYPAD								       	    **/
/*********************************************************************************/
void KPD_voidInit(void)
{
	/*Settign row pins direction to be output*/
	DIO_voidSetPinDirection(KEYPAD_u8_PORT_ROW, KEYPAD_u8_R1_PIN, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_PORT_ROW, KEYPAD_u8_R2_PIN, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_PORT_ROW, KEYPAD_u8_R3_PIN, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_PORT_ROW, KEYPAD_u8_R4_PIN, DIO_u8_OUTPUT);
	
	/*Setting column pins direction as input*/
	DIO_voidSetPinDirection(KEYPAD_u8_PORT_COL, KEYPAD_u8_C1_PIN, DIO_u8_INPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_PORT_COL, KEYPAD_u8_C2_PIN, DIO_u8_INPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_PORT_COL, KEYPAD_u8_C3_PIN, DIO_u8_INPUT);
	DIO_voidSetPinDirection(KEYPAD_u8_PORT_COL, KEYPAD_u8_C4_PIN, DIO_u8_INPUT);
	
	/*Init the row pins as high*/
	DIO_voidSetPinValue(KEYPAD_u8_PORT_ROW, KEYPAD_u8_R1_PIN, DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_u8_PORT_ROW, KEYPAD_u8_R2_PIN, DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_u8_PORT_ROW, KEYPAD_u8_R3_PIN, DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_u8_PORT_ROW, KEYPAD_u8_R4_PIN, DIO_u8_HIGH);
	
	/*Init the coloumn pins as Pull-uped*/
	DIO_voidSetPinValue(KEYPAD_u8_PORT_COL, KEYPAD_u8_C1_PIN, DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_u8_PORT_COL, KEYPAD_u8_C2_PIN, DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_u8_PORT_COL, KEYPAD_u8_C3_PIN, DIO_u8_HIGH);
	DIO_voidSetPinValue(KEYPAD_u8_PORT_COL, KEYPAD_u8_C4_PIN, DIO_u8_HIGH);
	
}

/*********************************************************************************/
/* Function: KPD_u8GetPressedKey	                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns u8	                                				    **/
/* Desc:This Function used to get the value of the pressed key		       	    **/
/*********************************************************************************/
u8 KPD_u8GetPressedKey (void)
{
	u8 local_u8RowCounter;
	u8 local_u8ColCounter;
	u8  local_u8KeyValue = KEYPAD_KEY_NOT_PRESSED;
	u8  local_u8Flag = KEYPAD_u8_FLAG_DOWN;
	   
	   /*
	   local_u8RowCounter: the current row number in the For Loop
	   local_u8ColCounter: the current Col number in the For Loop
	   local_u8PinValue  : the state of the current Col reading is High or Low
	   local_u8KeyValue  : the pressed key value in asci ('0' '1' ... '*' '/' ...)
						   initial state =KEYPAD_KEY_NOT_PRESSED = 0xff
	   local_u8Flag      : when a key is pressed flag will be up and the loop will be broken 
						   initially =KEYPAD_u8_FLAG_DOWN; 
	   */

	for (local_u8RowCounter = 0; local_u8RowCounter < KEYPAD_u8_ROW_NUM; local_u8RowCounter++ )
	{
		DIO_voidSetPinValue(KEYPAD_u8_PORT_ROW, KEYPAD_Au8RowsPins[local_u8RowCounter], DIO_u8_LOW); //Activate ROw by Setting 0 at output

		for (local_u8ColCounter = 0; local_u8ColCounter < KEYPAD_u8_COL_NUM; local_u8ColCounter++)
		{
			if (!DIO_u8GetPinValue(KEYPAD_u8_PORT_COL, KEYPAD_Au8ColsPins[local_u8ColCounter]))
			{
				_delay_ms(KEYPAD_u8_DEBOUNCING_MS);
				local_u8KeyValue = KEYPAD_Au8Keys[local_u8RowCounter][local_u8ColCounter];
				while (!DIO_u8GetPinValue(KEYPAD_u8_PORT_COL, KEYPAD_Au8ColsPins[local_u8ColCounter]));
				local_u8Flag = KEYPAD_u8_FLAG_UP;
			}

			else
			{
				/*Do nothing*/
			}
		}

		DIO_voidSetPinValue(KEYPAD_u8_PORT_ROW,KEYPAD_Au8RowsPins[local_u8RowCounter],DIO_u8_HIGH); //De-Activate column by Setting 1 at output

		if (local_u8Flag==KEYPAD_u8_FLAG_UP)
		{
			break;
		}
	}


	return local_u8KeyValue;
}
