#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"



/*ptr to the notification function*/
void (*SetCallBackPtr)(void) = NULL;



/****************************************************************************************************
 * 	Decription: This Function is used to intialize the SPI Master according to prebuilt configs     *
 * 	Parameters: void																				*
 * 	Returns: void																					*
 * 	Preconditions: The SPI_Config.h file must be adjusted                                           *
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: - SPI Master  is initalised succesfully.                                       *
 * 					 - SPI Slave must be initalised by SPI_voidSlaveInit func	                    *
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Re                                                						*
 ***************************************************************************************************/
void SPI_voidMasterInit(void)
{
	/*Setting The Node To Be Master Node*/
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_MSTR);

	/*clk speed setting*/
	SPI_u8_SPCR_REG &= ~((u8)PRESEC_MASK);
	SPI_u8_SPCR_REG |= ((u8)SPI_PRESEC_MODE);

#if SPI_PRESEC_MODE == PRESEC_2
#warning Caution: you are choosing a very high sampling speed
#endif


	/*clk Polarity setting*/

#if SPI_CLK_POLARITY == IDLE_LOW
	CLR_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_CPOL);
#elif SPI_CLK_POLARITY == IDLE_HIGH
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_CPOL);
#else
#error Wrong SPI_CLK_POLARITY configuration
#endif


	/*clk Phase setting*/
#if SPI_CLK_PHASE == CLK_PHASE_DISABLED
	CLR_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_CPHA);
#elif SPI_CLK_PHASE == CLK_PHASE_ENABLED
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_CPHA);
#else
#error Wrong SPI_CLK_PHASE configuration
#endif


	/*Data order select*/
#if SPI_DATA_ORDER == MSB_FIRST
	CLR_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_DORD);
#elif SPI_DATA_ORDER == LSB_FIRST
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_DORD);
#else
#error Wrong SPI_DATA_ORDER configuration
#endif


	/*Set the interrupt mode*/
#if SPI_INT_MODE == INT_DISABLED
	CLR_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_SPIE);
#elif SPI_INT_MODE == INT_ENABLED
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_SPIE);
#else
#error Wrong SPI_INT_MODE configuration
#endif

	/*Set the 2x speed mode config*/
#if SPI_SPEED_2X_MODE == SPEED_2x_DISABLED
	CLR_BIT(SPI_u8_SPSR_REG, SPI_u8_SPSR_SPI2X);

#elif SPI_SPEED_2X_MODE == SPEED_2x_ENABLED
	SET_BIT(SPI_u8_SPSR_REG, SPI_u8_SPSR_SPI2X);
#else
#error Wrong SPI_SPEED_2X_MODE Configuration
#endif

#if ((SPI_PRESEC_MODE == PRESEC_2) || (SPI_PRESEC_MODE == PRESEC_8) || (SPI_PRESEC_MODE == PRESEC_32) || (SPI_PRESEC_MODE == PRESEC_64))
	SET_BIT(SPI_u8_SPSR_REG, SPI_u8_SPSR_SPI2X);
#endif


#if (SPI_SPEED_2X_MODE == SPEED_2x_ENABLED) && ((SPI_PRESEC_MODE == PRESEC_4) || (SPI_PRESEC_MODE == PRESEC_2))
#warning Caution: The speed of sampling is really high, increase the prescaler or cancel Speed2x feature.
#endif

	/*Enable The SPI*/
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_SPE);
}



/****************************************************************************************************
 * 	Decription: This Function is used to intialize the SPI Slave							        *
 * 	Parameters: void																				*
 * 	Returns: void																					*
 * 	Preconditions: Prefrable that, The SPI_Config.h file is adjusted first                          *
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: SPI Slave is initalised succesfully. 	                                        *
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Re                                                						*
 ***************************************************************************************************/
void SPI_voidSlaveInit(void)
{
	/*Set The Node To Be Salve Node*/
	CLR_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_MSTR);
	
	/*Enable The SPI*/
	SET_BIT(SPI_u8_SPCR_REG, SPI_u8_SPCR_SPE);
}



/****************************************************************************************************
 * 	Decription: This Function is used to send or recive by SPI using the SPDR register              *
 * 	Parameters: void																				*
 * 	Returns: void																					*
 * 	Preconditions: Master & Slave must be initialized.	                                            *
 * 	Side effects: No side effects                                                                   *
 * 	Post Conditions: Data is send to slave, or slave recive data.                                   *
 * 	Synch/Asynch: Synch.																			*
 * 	Reentrant/NonReenterant: Re                                                						*
 ***************************************************************************************************/
u8 SPI_u8Tranceive(u8 Copy_u8Data)
{
	/*Sending the data to the send register*/
	SPI_u8_SPDR_REG = Copy_u8Data;


	/*Waiting for sending/reciption compeletion*/
	while ((GET_BIT(SPI_u8_SPSR_REG, SPI_u8_SPSR_SPIF)) != 1);

	/*Reseting the flag, in case the INT is disabled*/
#if SPI_INT_MODE == INT_DISABLED
	CLR_BIT(SPI_u8_SPSR_REG, SPI_u8_SPSR_SPIF);
#endif

	/*Returning the data*/
	return SPI_u8_SPDR_REG;
}



void __vector_12(void) __attribute__((signal));
void __vector_12(void)
{

	if (SetCallBackPtr != NULL)
	{
		/*Invoking the notfication function*/
		SetCallBackPtr();
	}

	else
	{
		/*NULL ptr error*/
	}
}




