#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/***********************************************************************************
	*
	-----> Macros
			*  Base_Address is				0x40023800 
			*  Register Map
************************************************************************************/
    #define         RCC_BASE_ADDRESS                    0x40023800

	#define			 RCC_CR								(*((volatile u32*) (RCC_BASE_ADDRESS+0X00)))
	#define 		 RCC_CR_HSEON						16u /*Ext clk enable bit*/
	#define 		 RCC_CR_HSEBYP						18u	/*Ext clk crystal bypass bit*/
	#define			 RCC_CR_HSION						0u  /*Int clk enable bit*/


	#define			 RCC_PLLCFGR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x04)))
	#define			 RCC_PLLCFGR_PLLSRC					22u


	#define			 RCC_CFGR							(*((volatile u32*) (RCC_BASE_ADDRESS+0x08)))
	#define			 RCC_CIR							(*((volatile u32*) (RCC_BASE_ADDRESS+0x0C)))
	#define			 RCC_AHB1RSTR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x10)))
	#define			 RCC_AHB2RSTR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x14)))
	#define			 RCC_AHB3RSTR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x18)))
	#define			 RCC_APB1RSTR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x20)))
	#define			 RCC_APB2RSTR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x24)))
	#define			 RCC_AHB1ENR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x30)))
	#define			 RCC_AHB2ENR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x34)))
	#define			 RCC_AHB3ENR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x38)))
	#define			 RCC_APB1ENR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x40)))
	#define			 RCC_APB2ENR					    (*((volatile u32*) (RCC_BASE_ADDRESS+0x44)))
	#define			 RCC_AHB1LPENR				        (*((volatile u32*) (RCC_BASE_ADDRESS+0x50)))
	#define			 RCC_AHB2LPENR				        (*((volatile u32*) (RCC_BASE_ADDRESS+0x54)))
	#define			 RCC_AHB3LPENR				        (*((volatile u32*) (RCC_BASE_ADDRESS+0x58)))
	#define			 RCC_APB1LPENR				        (*((volatile u32*) (RCC_BASE_ADDRESS+0x60)))
	#define			 RCC_APB2LPENR				        (*((volatile u32*) (RCC_BASE_ADDRESS+0x64)))
	#define			 RCC_BDCR							(*((volatile u32*) (RCC_BASE_ADDRESS+0x70)))
	#define			 RCC_CSR							(*((volatile u32*) (RCC_BASE_ADDRESS+0x74)))
	#define			 RCC_SSCGR						    (*((volatile u32*) (RCC_BASE_ADDRESS+0x80)))
	#define			 RCC_PLLI2SCFGR				        (*((volatile u32*) (RCC_BASE_ADDRESS+0x84)))

	 

/*
 *  Main PLL division Factor Macros
 * */
#define PLLQ_divideBy_2				2u
#define PLLQ_divideBy_3             3u
#define PLLQ_divideBy_4             4u
#define PLLQ_divideBy_5             5u
#define PLLQ_divideBy_6             6u
#define PLLQ_divideBy_7             7u
#define PLLQ_divideBy_8             8u
#define PLLQ_divideBy_9             9u
#define PLLQ_divideBy_10            10u
#define PLLQ_divideBy_11            11u
#define PLLQ_divideBy_12            12u
#define PLLQ_divideBy_13            13u
#define PLLQ_divideBy_14            14u
#define PLLQ_divideBy_15            15u






#endif //RCC_PRIVATE_H

