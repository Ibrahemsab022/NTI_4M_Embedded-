#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_register.h"
#include "UART_config.h"
#include "UART_private.h"


/*
static u8 UART_u8ReceivedFlag = 0;
static u8 UART_u8TransmitFlag = 0;
*/

/****************************************************************************************************
 * 	Decription: This Function is used to intialize the UART Prephiral according to prebuilt configs *
 * 	Parameters: void																				*
 * 	Returns: void																					*
 * 	Preconditions: The UART_config.h file must be adjusted                                          *
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: UART Prephiral is initalised succesfully.                                      *
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Re                                                						*
 ***************************************************************************************************/
void UART_voidInit(void)
{
	u16 Local_u16Speed = 0;
	u8 Local_u8UCSRCconfig = 0;

	/*Calculating & Setting the BaudRate*/
	Local_u16Speed = ((u16)((FOSC / (16ul * USART_BAUD_RATE)) - 1));
	if(Local_u16Speed <= 255)
	{
		UBRRL = Local_u16Speed;
	}

	else
	{
		UBRRL = (u8)Local_u16Speed;
		Local_u16Speed = Local_u16Speed >> 8;
		UBRRH = 0x0f & (u8)Local_u16Speed;
	}

	/*Setting the Transmission mode*/
#if USART_TRANS_MODE == ASYNCH
	CLR_BIT(Local_u8UCSRCconfig, UCSRC_UMSEL);
#elif USART_TRANS_MODE == SYNCH
	SET_BIT(Local_u8UCSRCconfig, UCSRC_UMSEL);
#else
#error Wrong config of transmission mode
#endif



	/*Setting the CLK Polarity*/
#if (USART_TRANS_MODE == SYNCH && USART_CLK_POLARITY == TXRISING_RXFALLING)
	CLR_BIT(Local_u8UCSRCconfig, UCSRC_UCPOL);
#elif (USART_TRANS_MODE == SYNCH && USART_PARITY_MODE == TXFALLING_RXRISING)
	SET_BIT(Local_u8UCSRCconfig, UCSRC_UCPOL);
#endif


	/*Selecting the data size*/
#if	USART_CHAR_SIZE == FIVE_BITS
	CLR_BIT(UCSRB, UCSRB_UCSZ2);
	CLR_BIT(Local_u8UCSRCconfig, UCSRC_UCSZ1);
	CLR_BIT(Local_u8UCSRCconfig, UCSRC_UCSZ0);

#elif USART_CHAR_SIZE == SIX_BITS
	CLR_BIT(UCSRB, UCSRB_UCSZ2);
	CLR_BIT(Local_u8UCSRCconfig, UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRCconfig, UCSRC_UCSZ0);

#elif USART_CHAR_SIZE == SEVEN_BITS
	CLR_BIT(UCSRB, UCSRB_UCSZ2);
	SET_BIT(Local_u8UCSRCconfig, UCSRC_UCSZ1);
	CLR_BIT(Local_u8UCSRCconfig, UCSRC_UCSZ0);

#elif USART_CHAR_SIZE == EIGHT_BITS
	CLR_BIT(UCSRB, UCSRB_UCSZ2);
	SET_BIT(Local_u8UCSRCconfig, UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRCconfig, UCSRC_UCSZ0);
#elif USART_CHAR_SIZE == NINE_BITS
	SET_BIT(UCSRB, UCSRB_UCSZ2);
	SET_BIT(Local_u8UCSRCconfig, UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRCconfig, UCSRC_UCSZ0);
#else
#error Wrong config of the Charachter size.
#endif


	/*Setting the Parity mode*/
#if USART_PARITY_MODE == NO_PARITY
	CLR_BIT(Local_u8UCSRCconfig, UCSRC_UPM0);
	CLR_BIT(Local_u8UCSRCconfig, UCSRC_UPM1);
#elif USART_PARITY_MODE == EVEN_PARITY
	CLR_BIT(Local_u8UCSRCconfig, UCSRC_UPM0);
	SET_BIT(Local_u8UCSRCconfig, UCSRC_UPM1);
#elif USART_PARITY_MODE == ODD_PARITY
	SET_BIT(Local_u8UCSRCconfig, UCSRC_UPM0);
	SET_BIT(Local_u8UCSRCconfig, UCSRC_UPM1);
#else
#error Wrong config of Parity mode.
#endif


	/*Setting the stop bit mode*/
#if USART_STOP_BIT_MODE == SINGLE_STOP_BIT
	CLR_BIT(Local_u8UCSRCconfig, UCSRC_USBS);
#elif USART_STOP_BIT_MODE == TWO_STOP_BITS
	CLR_BIT(Local_u8UCSRCconfig, UCSRC_USBS);
#else
#error Wrong Config of STOP_BOT_MODE
#endif


	/*Adjusting the initial states of the Reciver & Transmitter*/
#if USART_RX_INIT_STATE == RX_DISABLED
	CLR_BIT(UCSRB, UCSRB_RXEN);
#elif USART_RX_INIT_STATE == RX_ENABLED
	SET_BIT(UCSRB, UCSRB_RXEN);
#else
#error Wrong config of RX_INIT_STATE
#endif

#if USART_TX_INIT_STATE == TX_DISABLED
	CLR_BIT(UCSRB, UCSRB_TXEN);
#elif USART_TX_INIT_STATE == TX_ENABLED
	SET_BIT(UCSRB, UCSRB_TXEN);
#else
#error Wrong config of TX_INIT_STATE
#endif

	/*Writing the configs in the UCSRC Reg*/
	SET_BIT(UCSRC, UCSRC_URSEL);
	UCSRC = Local_u8UCSRCconfig;

}



/****************************************************************************************************
 * 	Decription: This Function is used to send a single charachter via UART 							*
 * 	Parameters: - Copy_u8data: the char to be transmited.											*									*
 * 	Returns: void																					*
 * 	Preconditions: UART is Initialized through UART_voidInit func                                   *
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: a char is sent succesfully				                                        *
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Re                                                						*
 ***************************************************************************************************/
void UART_voidSendChar(u8 Copy_u8data)
{
    /*wait for the trasmitting flag (UDRE bit in UCSRA register)*/
	while (GET_BIT(UCSRA, UCSRA_UDRE) == 0);

	/*send data*/
	UDR_T = Copy_u8data;
}



/****************************************************************************************************
 * 	Decription: This Function is used to recive a single charachter via UART 						*
 * 	Parameters: void.											     								*
 * 	Returns: The recived charachter																	*				*
 * 	Preconditions: UART is Initialized through UART_voidInit func                                   *
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: a char is recived succesfully				                                    *
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Re                                                						*
 ***************************************************************************************************/
u8 UART_voidGetChar(void)
{

  /*wait for the receiving flag (RXC bit in UCSRA register)*/
  while (GET_BIT(UCSRA, UCSRA_RXC) == 0);
  
  /*read data*/
  return UDR_R;
}



/****************************************************************************************************
 * 	Decription: This Function is used to recive a string via UART			 						*
 * 	Parameters: - Copy_pu8str: is a pointer to an array of u8/chars.								*			     								*
 * 				- Copy_u8size: the size of the passed array											*
 * 	Returns: void																					*
 * 	Preconditions: - UART is Initialized through UART_voidInit func                                 *
 * 				   - UART_voidGetChar func is working properly										*
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: a string is recived succesfully				                                *
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Re                                                						*
 ***************************************************************************************************/
void UART_voidGetStringSynch(u8* Copy_pu8str, u8 Copy_u8size)
{
  u8 Local_u8Itterator = 0;
  
  while (Local_u8Itterator < Copy_u8size)
  {
	  Copy_pu8str[Local_u8Itterator] = UART_voidGetChar();
	  Local_u8Itterator++;
  }
  
  
}




/****************************************************************************************************
 * 	Decription: This Function is used to send a string via UART			 							*
 * 	Parameters: - Copy_pu8str: is a pointer to a const array of u8/chars or a string				*				*			     								*
 * 	Returns: void																					*
 * 	Preconditions: - UART is Initialized through UART_voidInit func                                 *
 * 				   - UART_voidSendChar func is working properly										*
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: a string is sent succesfully				                                	*
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Re                                                						*
 ***************************************************************************************************/
void UART_voidSendStringSynch(const u8* Copy_pu8str)
{
  u8 Local_u8Counter = 0;

  while (Copy_pu8str[Local_u8Counter] != '\0')
  {
    UART_voidSendChar(Copy_pu8str[Local_u8Counter]);
    Local_u8Counter++;
  }
  
}

/*
void __vector_13 (void) __attribute__((signal));
void __vector_13 (void)
{
	UART_u8ReceivedFlag = 1;
}


void __vector_15 (void) __attribute__((signal));
void __vector_15 (void)
{
	UART_u8TransmitFlag = 1;
}
*/
