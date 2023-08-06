
/*************************************************************************************
*************************************************************************************/

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H


/*This struct to hold the arguments of the init function*/
typedef struct
{
	u8 StreamID;
	u8 ChannelSelect;
	u8 Priority;
	u8 DataDirection;
	u8 MemoryDataSize;
	u8 PrephieralDataSize;
	u8 DirectModeState;
	u8 FIFOThreshold;
	u8 DirectionModeState;
	u8 PeripheralIncMode;
	u8 MemoryIncMode;
	u8 CompleteIntMode;

}FuncArgs_T;


/* DMA init */
void DMA_voidInit(FuncArgs_T* PtrToFuncArgs);
/* Function to set source and distination */
void DMA_voidSetAddress(u32 *Ptr_u32SrcAdd , u32 *Ptr_u32DistAdd , u16 Copy_u16Size ,u8 Copy_u8StreamID);
/* Func To enable DMA */
void DMA_voidStreamEnable(u8 Copy_u8StreamID);



/*Macros for channel select:*/
#define CH0     0u
#define CH1     1u
#define CH2     2u
#define CH3     3u
#define CH4     4u
#define CH5     5u
#define CH6     6u
#define CH7     7u


/*Macros for Priority select*/
#define PRIORITY_VERY_HIGH        3u
#define PRIORITY_HIGH        	  1u
#define PRIORITY_MEDIUM           1u
#define PRIORITY_LOW              0u

/*Macros for Direction select*/
#define DIRECTION_P2M           0u
#define DIRECTION_M2P           1u
#define DIRECTION_M2M			2u


/*Macros for memory data size*/
#define DATA_SIZE_BYTE8              0u
#define DATA_SIZE_HALFWORD16         1u
#define DATA_SIZE_WORD32         	 2u


/*Macros for Direct mode State*/
#define DIRECT_MODE_ENABLED            1u
#define DIRECT_MODE_DISABLED           2u



/*Macros for the FIFO Threshold*/
#define FIFO_025              0u
#define FIFO_05               1u
#define FIFO_075              2u
#define FIFO_1                3u

/*Macros for INC mode*/
#define INC_MODE_ENABLED      1u
#define INC_MODE_DISABLED     2u


/*Macros for complete interrupt mode*/
#define COMP_INT_ENABLED	1u
#define COMP_INT_DISABLED    2u






#endif 
/*************************************************************************************/
