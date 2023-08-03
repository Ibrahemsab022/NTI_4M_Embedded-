
#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_

#define UDR_T            *((volatile u8 *)0x2C)
#define UDR_R            *((volatile u8 *)0x2C)

#define UCSRA            *((volatile u8 *)0x2B)		/*Control and Status register A*/
#define UCSRA_RXC        7u							/*Recive compelte flag*/
#define UCSRA_TXC        6u                         /*Transmit compelte flag*/
#define UCSRA_UDRE       5u                         /*Data Register empty flag*/
#define UCSRA_FE         4u                         /*Frame Error bit*/
#define UCSRA_DOR        3u                         /*Data over run bit*/
#define UCSRA_PE         2u                         /*Parity error bit*/
#define UCSRA_U2X        1u                         /*Double speed bit*/
#define UCSRA_MPCM       0u                         /*Multi-processor mode enable bit*/



#define UCSRB            *((volatile u8 *)0x2A)		/*Control and Stat reg B*/
#define UCSRB_RXCIE		  7u						/*RX compelte interrupt enable bit*/
#define UCSRB_TXCIE       6u                        /*TX compelte interrupt enable bit*/
#define UCSRB_UDRIE       5u                        /*Data reg empty interrupt enable bit*/
#define UCSRB_RXEN        4u                        /*Reciver enable*/
#define UCSRB_TXEN        3u                        /*Transmiter enable*/
#define UCSRB_UCSZ2       2u                        /*Charachter size selection, this bit and UCSZ1 in UCSRC*/
#define UCSRB_RXB8        1u                        /*Ninth bit to be read first in 9bit mode*/
#define UCSRB_TXB8        0u                        /*Ninth bit to be written first as the MSB bit in 9bit mode*/



#define UCSRC            *((volatile u8 *)0x40)		/*Control and stat reg C*/
#define UCSRC_URSEL       7u                        /*Reg select*/
#define UCSRC_UMSEL       6u                        /*USART mode select*/
#define UCSRC_UPM1        5u                        /*UPM1:0 Parity mode select*/
#define UCSRC_UPM0        4u
#define UCSRC_USBS        3u                        /*Stop bit select*/
#define UCSRC_UCSZ1       2u                        /*UCSZ1:0 charachter size select*/
#define UCSRC_UCSZ0       1u
#define UCSRC_UCPOL       0u                        /*CLK polarity select*/

#define UBRRL            *((volatile u8 *)0x29)		/*Baud rate reg low*/
#define UBRRH            *((volatile u8 *)0x40)		/*Baud rate reg high*/
#define UBRRH_URSEL		 7u							/*Selects between UBRRH & UCSRC*/



#endif /* UART_REGISTER_H_ */
