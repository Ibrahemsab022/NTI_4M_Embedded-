#ifndef		SPI_INTERFACE_H
#define		SPI_INTERFACE_H




/*Config The Ports and pins of the master:
 * 							DIO_u8_PIN0
 * 							DIO_u8_PIN1
 * 							DIO_u8_PIN2
 * 							DIO_u8_PIN3
 * 							DIO_u8_PIN4
 * 							DIO_u8_PIN5
 * 							DIO_u8_PIN6
 * 							DIO_u8_PIN7
 *
 * 							DIO_u8_PORTA
 * 							DIO_u8_PORTB
 * 							DIO_u8_PORTC
 * 							DIO_u8_PORTD
 **/
#define SPI_MASTER_PORT		DIO_u8_PORTB
#define MASTER_MOSI_PIN		DIO_u8_PIN5
#define MASTER_MISO_PIN		DIO_u8_PIN6
#define MASTER_SCK_PIN		DIO_u8_PIN7
#define MASTER_SS_PIN		DIO_u8_PIN4



/*********************************************************************************/
/* Function: SPI_voidMasterInit			                       			 	    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize MC as Master Node					       	    **/
/*********************************************************************************/
void SPI_voidMasterInit(void);

/*********************************************************************************/
/* Function: SPI_voidSlaveInit			                       				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize MC as Slave Node					       	    **/
/*********************************************************************************/
void SPI_voidSlaveInit(void);

/*********************************************************************************/
/* Function: SPI_voidSlaveInit			                       				    **/
/* I/P Parameters: Copy_u8Data								          		    **/
/* Returns:it returns u8        	                        				    **/
/* Desc:This Function Transmit/recieve data							       	    **/
/*********************************************************************************/
/* Copy_u8Data Options:	Data assigned directly						       	    **/
/*********************************************************************************/
u8 SPI_u8Tranceive(u8 Copy_u8Data);



#endif
