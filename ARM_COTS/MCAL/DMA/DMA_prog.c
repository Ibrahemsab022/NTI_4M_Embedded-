/******************************************************************************************/
/******************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"



#include "DMA_private.h"
#include "DMA_config.h"
#include "DMA_interface.h"



void (*DMA_CallBackChannel1 )( void );

void DMA_voidInit(FuncArgs_T* PtrToFuncArgs)
{
     /* 1- Before Any Config The Bit Of EN Must = 0 ,It must Be Disable*/
	/* Use Stream NUM = 0 */
	/* If Enable Bit == 1 */
	CLR_BIT((DMA_2 -> StreamID[PtrToFuncArgs -> StreamID].CR), CR_EN);
	
	/*waiting for the EN bit to clear*/
	while ((GET_BIT((DMA_2 -> StreamID[PtrToFuncArgs -> StreamID].CR), CR_EN)) != 0);


  	/* 2- Select The Channel(Used For Conect Peripheral To Memory) In stream  But From Mermoery To Memory Not Use*/
	DMA_2 -> StreamID[PtrToFuncArgs -> StreamID].CR &= (~((u32)0b111) << 25);
	DMA_2 -> StreamID[PtrToFuncArgs -> StreamID].CR |= (((u32)(PtrToFuncArgs -> ChannelSelect)) << 25);
	

	/* 3-SoftWare Priority Stream :{ LOW , Medium , High , VeryHigh} BIT(16 , 17)---> VeryHigh  */
	DMA_2 -> StreamID[PtrToFuncArgs -> StreamID].CR &= (~((u32)0b11) << 16);
	DMA_2 -> StreamID[PtrToFuncArgs -> StreamID].CR |= (((u32)(PtrToFuncArgs -> Priority)) << 16);

	/* 4- Set DIR Mode :{ (MTM) ,PTM ,MTP} BIT (6,7) */
	DMA_2 -> StreamID[PtrToFuncArgs -> StreamID].CR &= (~((u32)0b11) << 6);
	DMA_2 -> StreamID[PtrToFuncArgs -> StreamID].CR |= (((u32)(PtrToFuncArgs -> DataDirection)) << 6);
	
	
	/* 5- Set M & M SIZE BIT(13,14) ,(11,12) :{Byte , HaveWord , (Word)}*/
	DMA_2 -> StreamID[PtrToFuncArgs -> StreamID].CR &= (~((u32)0b11) << 13);
	DMA_2 -> StreamID[PtrToFuncArgs -> StreamID].CR |= (((u32)(PtrToFuncArgs -> MemoryDataSize)) << 13);

	DMA_2 -> StreamID[PtrToFuncArgs -> StreamID].CR &= (~((u32)0b11) << 11);
	DMA_2 -> StreamID[PtrToFuncArgs -> StreamID].CR |= (((u32)(PtrToFuncArgs -> PrephieralDataSize)) << 11);

	
	/* 6- Disable Direct Mode to used fifo  */

	if ((PtrToFuncArgs -> DirectModeState) == DIRECT_MODE_DISABLED)
	{
		SET_BIT(DMA_2 -> StreamID[PtrToFuncArgs -> StreamID].FCR, 2);

		/* 7-Set FIFO Threshold {(1/4),(1/2),(3/4),full} */
		DMA_2 -> StreamID[PtrToFuncArgs -> StreamID].FCR &= (~((u32)0b11) << 3);
		DMA_2 -> StreamID[PtrToFuncArgs -> StreamID].FCR |= (((u32)(PtrToFuncArgs -> FIFOThreshold)) << 3);
	}
	

	/* 8-SRC & DIS Increament For Both */
	if ((PtrToFuncArgs -> MemoryIncMode) == INC_MODE_ENABLED)
	{
		SET_BIT(DMA_2 -> StreamID[PtrToFuncArgs -> StreamID].CR, 10);
	}

	if (PtrToFuncArgs -> PeripheralIncMode == INC_MODE_ENABLED)
	{
		SET_BIT(DMA_2 -> StreamID[PtrToFuncArgs -> StreamID].CR, 9);
	}
    
	/* 9- EN Interrput Of Transfer Complete */
	if ((PtrToFuncArgs -> CompleteIntMode) == COMP_INT_ENABLED)
	{
		SET_BIT(DMA_2 -> StreamID[PtrToFuncArgs -> StreamID].CR, 4);
	}

}






void DMA_voidSetAddress(u32 *Ptr_u32SrcAdd , u32 *Ptr_u32DistAdd , u16 Copy_u16Size ,u8 Copy_u8StreamID)
{
	
	CLR_BIT((DMA_2 -> StreamID[Copy_u8StreamID].CR), CR_EN);
	/*waiting for the EN bit to clear*/
	while ((GET_BIT((DMA_2 -> StreamID[Copy_u8StreamID].CR), CR_EN)) != 0);

	/*Setting the addresses of the src and distance (double buffer)*/
	DMA_2 -> StreamID[Copy_u8StreamID].PAR =   Ptr_u32SrcAdd;
	DMA_2 -> StreamID[Copy_u8StreamID].M0AR =  Ptr_u32DistAdd;

	/*Setting the data size*/
	DMA_2 -> StreamID[Copy_u8StreamID].NDTR = (u16)Copy_u16Size;

}

void DMA_voidStreamEnable(u8 Copy_u8StreamID )
{
	/*Clearing the flags*/
	DMA_2 -> HISR = 0;
	DMA_2 -> LISR = 0;
	
	/*Enabling the DMA*/
	SET_BIT((DMA_2 -> StreamID[Copy_u8StreamID].CR), CR_EN);
}


void DMA_voidSetCallBackChannel1( void ( *Ptr ) ( void ) ){

	DMA_CallBackChannel1 = Ptr ;

}

void DMA1_Channel1_IRQHandler(void){

	DMA_CallBackChannel1();

}
/******************************************************************************************/

/********************************
DMA STEPS
*********************************
	/*Enable clock access to DMA*/

	/*Disable DMA1 Stream6*/ //CR

    /*Wait until DMA1 Stream 6 is disabled */ //CR

	/*Clear all interrupt flags of Stream6*/ //HIFCR

	/*Set the destination buffer*/  //PAR

	/*Set the source buffer*/  //M0AR

	/*Set length*/  //NDTR

	/*Select Stream6 CH4*/ //CR

	/*Enable memory increment*/  //CR

	/*Configure transfer direction*/  //CR

	/*Enable DMA transfer complete interrupt*/  //CR

	/*Enable direct mode and disable FIFO*/  //FCR

	/*Enable DMA1 Stream6*/  //CR

	/*Enable UART2 transmitter DMA*/  // UART DMA

	/*DMA Interrupt enable in NVIC*/// NVIC_EnableIRQ(DMA1_Stream6_IRQn);

/*******************************/

