
/*************************************************************************************
*************************************************************************************/ 


#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H


/***********************************************************************************
----->STRUCT
*  Register Map :SYSCFG
************************************************************************************/


typedef struct
{
	volatile u32 CR;
	volatile u32 NDTR;
	volatile u32 PAR;
	volatile u32 M0AR;
	volatile u32 M1AR;
	volatile u32 FCR;
	
}DMA_STREAM_t;


typedef struct
{
	volatile u32 LISR;
	volatile u32 HISR;
	volatile u32 LIFCR;
	volatile u32 HIFCR;
	volatile DMA_STREAM_t StreamID[8];
	
}DMA_t;

/***********************************************************************************
	-----> Macros
			*  Base_Address DMA_2       --> 0x4002 6400
			*  Base_Address DMA_1       --> 0x4002 6000
************************************************************************************/

#define BASE_ADDRESS_DMA1	0x40026000
#define BASE_ADDRESS_DMA2	0x40026400

#define DMA_1            ((( volatile  DMA_t *) BASE_ADDRESS_DMA1))
#define DMA_2            ((( volatile  DMA_t *) BASE_ADDRESS_DMA2))


#define CR_EN		0u








#endif 
/***********************************************************************************/
