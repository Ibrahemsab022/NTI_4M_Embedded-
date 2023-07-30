/***************************************************************************************/
/***************************************************************************************/
//File guard 
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

//Registers macros
#define DIO_u8_PORTA      0
#define DIO_u8_PORTB      1
#define DIO_u8_PORTC      2
#define DIO_u8_PORTD      3

//Pins macros
#define DIO_u8_PIN0       0
#define DIO_u8_PIN1       1
#define DIO_u8_PIN2       2
#define DIO_u8_PIN3       3
#define DIO_u8_PIN4       4
#define DIO_u8_PIN5       5
#define DIO_u8_PIN6       6
#define DIO_u8_PIN7       7

//Other macros
#define DIO_u8_LOW        0
#define DIO_u8_HIGH       1
 
#define DIO_u8_INPUT      0
#define DIO_u8_OUTPUT     1

/********************************************************************************************************************************************/
/* Function: 				DIO_voidSetPinValue	                        				                                                    */
/* Input/outPut Parameters:	PortId, PinId and Value.		          		                                                                */
/* Returns:   				returns nothing (void)                           				                                                */
/* Descruption: this function takes the PortId wehther Port A,B,C or D and the PinId Pin0-7, and wether you want that pin to be high or low.*/
/********************************************************************************************************************************************/
void DIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value);



/*********************************************************************************************************************************************/
/* Function: 				DIO_voidSetPinDirection	                        				    										     */
/* Input/outPut Parameters:	PortId, PinId and Direction		          		                            								     */
/* Returns:   				returns nothing (void)                             				                        					     */
/* Descruption: this func takes the PortId wehther Port A,B,C or D and the PinId Pin0-7, and wether you want that pin to be Input or Output. */
/*********************************************************************************************************************************************/
void DIO_voidSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction);



/*******************************************************************************************************************/
/* Function: DIO_voidGetPinValue	                        				     							       */
/* Input/outPut Parameters:	PortId, PinID		          		                                                   */
/* Returns: returns unsigned 8bit value (u8)                          				                               */
/* Descruption:	this func takes the PortId wehther Port A,B,C or D and the PinId Pin0-7, and returns the Pin value.*/
/*******************************************************************************************************************/
u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId);



/*********************************************************************************************************/
/* Function: DIO_voidSetPortValue	                        				     						 */
/* Input/outPut Parameters:	PortId and value		          		            						 */
/* Returns:  returns nothing (void)                              				                         */
/* Descruption:	this func takes the PortId wehther Port A,B,C or D and the value and put it in that port */
/*********************************************************************************************************/
void DIO_voidSetPortValue(u8 Copy_u8PortId, u8 Copy_u8Value);



/*************************************************************************************************************/
/* Function: DIO_voidSetPortDirection	                        				                             */
/* Input/outPut Parameters:	PortId, and Direction		          		                                     */
/* Returns: returns nothing (void)                            				                                 */
/* Descruption:	this func takes the PortId wehther Port A,B,C or D and the direction and put it in that port */
/*************************************************************************************************************/
void DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8Direction);



/*****************************************************************************************************************/
/* Function: DIO_voidGetPortValue	                        				     								 */
/* Input/outPut Parameters:PortId		          		                            							 */
/* Returns: returns an unsigned 8 bit data (u8)          				                    	                 */
/* Descruption:this func takes the PortId wehther Port A,B,C or D and returns the content of the port as a u8    */
/*****************************************************************************************************************/
u8 DIO_u8GetPortValue(u8 Copy_u8PortId);







#endif
/***************************************************************************************/
