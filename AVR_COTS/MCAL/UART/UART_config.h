#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_



/*Enter the FOSC of ur micro in Hz*/
#define FOSC		16000000ul

/*Enter the baud rate value*/
#define USART_BAUD_RATE			9600ul

/*Select the initial state of the TX
 * 								1- TX_ENABLED
 * 								2- TX_DISABLED
 * */
#define USART_TX_INIT_STATE	TX_ENABLED

/*Select the inital state of the RX
 * 								1- RX_ENABLED
 * 								2- RX_DISABLED
 **/
#define USART_RX_INIT_STATE	RX_ENABLED

/*
 * Select the mode of transmission:
 * 							1- SYNCH
 * 							2- ASYNCH
 *
 */
#define USART_TRANS_MODE		ASYNCH


/*
 * Select the Parity mode:
 * 						1- EVEN_PARITY
 * 						2- ODD_PARITY
 * 						3- NO_PARITY
 **/
#define USART_PARITY_MODE		NO_PARITY


/*Chose the Stop bit mode:
 * 					1- SINGLE_STOP_BIT
 * 					2- TWO_STOP_BITS
 **/
#define USART_STOP_BIT_MODE		SINGLE_STOP_BIT


/*Select the Charachter size (Data size):
 * 									1- FIVE_BITS
 * 									2- SIX_BITS
 * 									3- SEVEN_BITS
 * 									4- EIGHT_BITS
 * 									5- NINE_BITS
 *
 **/
#define USART_CHAR_SIZE			EIGHT_BITS



/*Select the CLK polarity (only when SYNCH mode is selected):
 * 												1- TXRISING_RXFALLING
 * 												2- TXFALLING_RXRISING
 *
 **/
#define USART_CLK_POLARITY		TXRISING_RXFALLING





#endif
