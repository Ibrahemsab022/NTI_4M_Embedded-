#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include "RCC_config.h"
#include "STD_TYPES.h"

	/*
	Config RCC Enum
	- Crystal CLK SRC (RCC_HSE : External ,RCC_HSI : Internal  ,RCC_PLL Use_PLL) ---->ClkSrcName_t
	- For External Crystal CLK From (HSE_Crystal , HSE_RC )--->HSESrcName_t
	- For PLL Can Be For (HSE , HSI) --------->PllSrcName_t
	- PLL  Prescaller ( M /(2:63) N*(50:432) P Q )               ---> User Select By #define                  
	- AHB  Prescaller ( 1 : 512 )  							---> AHBPreName_t
	- APB1 Prescaller (1  : 16)    							---> APB1_Prescaller
	- APB2_Prescaller (1  : 16)    							---> APB2_Prescaller
	- Select Bus ( AHB1 AHB2 AHB3 APB1  APB2 )  --->BusName_t
	                   
	             
	*/
		
 typedef enum
		 {
			 RCC_HSE	=	 0 ,		//High Speed External
			 RCC_HSI		   ,		//High Speed Internal
			 RCC_PLL						//Use Pll
			 
			 }ClkSrcName_t;
			 
typedef enum
		 {
			 HSE_Crystal	=	 0 ,
			 HSE_RC
			 
		 }HSESrcName_t;
		 
typedef enum 
		 {
			 PLL_HSE  = 0 ,
			 PLL_HSI  
		 }PllSrcName_t;	 
		 
	/*
		- C
	*/
typedef enum 
		{
			AHB_Pre1 = 	0, 			// No Action
			AHB_Pre2 = 	0b1000,
			AHB_Pre4 =	0b1001,
			AHB_Pre8 =	0b1010,
			AHB_Pre16 =	0b1011,
			AHB_Pre64 =	0b1100,
			AHB_Pre128 = 0b1101,
			AHB_Pre256 = 0b1110,
			AHB_Pre512 = 0b111
			
			}AHBPreName_t;
		
	/*
		- APB1_Prescaller 
	*/
	
typedef enum
		{
			ABP1_Pre1  =	 0b0 ,
			ABP1_Pre2  =	 0b100 ,
			ABP1_Pre4  =	 0b101 ,
			ABP1_Pre8  =	 0b110 ,
			ABP1_Pre16 =	 0b111
		}APB1PreName_t ;
	
/*
		* APB2_Prescaller 
*/
typedef enum
		{
			ABP2_Pre1 	= 	0 ,
			ABP2_Pre2	= 	0b100  ,
			ABP2_Pre4	= 	0b101  ,
			ABP2_Pre8	= 	0b110  ,
			ABP2_Pre16  =   0b111
		}APB2PreName_t ;


/*
	Buses 
*/
typedef enum
		{
			AHB1	=	 0 ,
			AHB2		   ,
			AHB3		   ,
			APB1		   ,
			APB2 
			
		}BusName_t;
	 

/*
	- Frist You Must Know The Perpheral On Which Bus
	- 

*/
	/*
	-Function To Set System CLK From Enum Type Send :
																				* ClkSrcName_t 		: RCC_HSE  RCC_HSI	RCC_PLL	
																				* HSESrcName_t 		: Crystal CLK From (HSE_Crystal , HSE_RC )
																				* AHBPreName_t    : AHB  Prescaller ( 1 : 512 )
																				* APB1PreName_t   : APB1 Prescaller ( 1 : 16  )  
																				* APB2PreName_t   : APB2_Prescaller ( 1 : 16  ) 
																				*( M N P Q )      : By #define 
																									
																
	*/
	 void RCC_voidInitSysClock( ClkSrcName_t ClkSrc , HSESrcName_t HSESrc , PllSrcName_t PLLSrc  , AHBPreName_t AHB_Prescaler , APB1PreName_t APB1_Prescaler  , APB2PreName_t APB2_Prescaler ) ;
	
	/*
	- Function To Enable Prepheral :
																	- BusName_t      :  The Bus Of The Prepheral ( AHB1 , AHB2 , AHB3 , APB1 , APB2 ) Every One Detect Which REG To Choice Pripheral From It
																	- Copy_u8PerName :  The Order Of Prepheral On The Selected Reg 
	
	*/
	 void RCC_voidEnableClock (BusName_t BusName ,u8 Copy_u8PerName  );
	/*
	- Function To Disable Prepheral :
																	- BusName_t      :  The Bus Of The Prepheral ( AHB1 , AHB2 , AHB3 , APB1 , APB2 ) Every One Detect Which REG To Choice Pripheral From It
																	- Copy_u8PerName :  The Order Of Prepheral On The Selected Reg 
	
	*/
	 void RCC_voidDisableClock (BusName_t BusName ,u8 Copy_u8PerName);
	 


	 /*
	 BUS
	 */
	  #define  AHB1_BUS				 	   0
	  #define  AHB2_BUS				 	   1
	  #define  APB1_BUS				 	   2
	  #define  APB2_BUS				 	   3


		/* Macros Of :

								- RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
		*/
	#define PERIPHERAL_EN_GPIOA							0
	#define PERIPHERAL_EN_GPIOB							1
	#define PERIPHERAL_EN_GPIOC							2
	#define PERIPHERAL_EN_GPIOD							3
	#define PERIPHERAL_EN_GPIOE							4
	#define PERIPHERAL_EN_GPIOF							5
	#define PERIPHERAL_EN_GPIOG							6
	#define PERIPHERAL_EN_GPIOH							7
	#define PERIPHERAL_EN_GPIOI							8
	#define PERIPHERAL_EN_CRC							12
	#define PERIPHERAL_EN_FLITF                         15
	#define PERIPHERAL_EN_BKPSRAM         	            18
	#define PERIPHERAL_EN_CCMDATARAM      	            20
	#define PERIPHERAL_EN_DMA1							21
	#define PERIPHERAL_EN_DMA2							22
	#define PERIPHERAL_EN_ETHMAC						25
	#define PERIPHERAL_EN_ETHMACTX                      26
	#define PERIPHERAL_EN_ETHMACRX                      27
	#define PERIPHERAL_EN_ETHMACPTP                     28
	#define PERIPHERAL_EN_OTGHS					  	    29
	#define PERIPHERAL_EN_OTGHSULPI                     30


	/* Macros Of :

								- RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
		*/

	#define PERIPHERAL_EN_DCMI 						 0
	#define PERIPHERAL_EN_CRYP 						 4
	#define PERIPHERAL_EN_HASH 						 5
	#define PERIPHERAL_EN_RNG 	  				     6
	#define PERIPHERAL_EN_OTGFS 					 7

		/* Macros Of :

								- RCC APB1 peripheral clock enable register
		*/

	#define PERIPHERAL_EN_TIM2						0
	#define PERIPHERAL_EN_TIM3						1
	#define PERIPHERAL_EN_TIM4						2
	#define PERIPHERAL_EN_TIM5					    3
	#define PERIPHERAL_EN_TIM6						4
	#define PERIPHERAL_EN_TIM7						5
	#define PERIPHERAL_EN_TIM12					    6
	#define PERIPHERAL_EN_TIM13					    7
	#define PERIPHERAL_EN_TIM14					    8
	#define PERIPHERAL_EN_WWDG						11
	#define PERIPHERAL_EN_SPI2						14
	#define PERIPHERAL_EN_SPI3						15
	#define PERIPHERAL_EN_UART2						17
	#define PERIPHERAL_EN_UART3						18
	#define PERIPHERAL_EN_UART4						19
	#define PERIPHERAL_EN_UART5						20
	#define PERIPHERAL_EN_I2C1						21
	#define PERIPHERAL_EN_I2C2						22
	#define PERIPHERAL_EN_I2C3						23
	#define PERIPHERAL_EN_CAN1						25
	#define PERIPHERAL_EN_CAN2						26
	#define PERIPHERAL_EN_PWR						28
	#define PERIPHERAL_EN_DAC						29

	/* Macros Of :

								- RCC AHB3 peripheral clock enable register (RCC_AHB3ENR)
		*/

	#define PERIPHERAL_EN_FSMC					    0

	/* Macros Of :

								- RCC APB2 peripheral clock enable register (RCC_APB2ENR)
		*/

	#define PERIPHERAL_EN_TIM1  				 0
	#define PERIPHERAL_EN_TIM8					 1
	#define PERIPHERAL_EN_USART1				 4
	#define PERIPHERAL_EN_USART6				 5
	#define PERIPHERAL_EN_ADC1					 8
	#define PERIPHERAL_EN_ADC2					 9
	#define PERIPHERAL_EN_ADC3					 10
	#define PERIPHERAL_EN_SDIO					 11
	#define PERIPHERAL_EN_SPI1					 12
	#define PERIPHERAL_EN_SYSCFG				 14
	#define PERIPHERAL_EN_TIM9					 16
	#define PERIPHERAL_EN_TIM10					 17
	#define PERIPHERAL_EN_TIM11 				 18

#endif //RCC_INTERFACE_H

