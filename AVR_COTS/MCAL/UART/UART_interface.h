#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_



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
void UART_voidInit(void);

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
void UART_voidSendChar(u8 Copy_u8data);

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
u8 UART_voidGetChar(void);

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
void UART_voidGetStringSynch(u8* Copy_pu8str, u8 Copy_u8size);


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
void UART_voidSendStringSynch(const u8* Copy_pu8str);

#endif /* UART_INTERFACE_H_ */
