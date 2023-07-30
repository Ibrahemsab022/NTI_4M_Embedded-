/**************************************************************************************

*	 - Developer can't Edit in it    
*	  - Register _ Defination		
*	  - Design : 
					- #define	:	Yes
					- Union		:	NO
					- Struct	:	NO

**************************************************************************************/

/*************************************************************************************
******************* guard of file will call on time in .c		   *******************
*************************************************************************************/ 


#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


/*this is used to config the limits of the ports, as not all the kits have the same ports*/
#define PORT_LIMIT		GPIOH_PORT
#define PIN_LIMIT		PIN15


/***********************************************************************************
	-----> Macros
			*  Base_Address GPI0X				
************************************************************************************/

#define  GPIOA_BASE_ADDRESS			(0x40020000)
#define  GPIOB_BASE_ADDRESS			(0x40020400)
#define  GPIOC_BASE_ADDRESS			(0x4000800)
#define  GPIOD_BASE_ADDRESS			(0x4000C00)
#define  GPIOE_BASE_ADDRESS			(0x4001000)
#define  GPIOH_BASE_ADDRESS			(0x4001C00)

/***********************************************************************************
	-----> Macros
			  *  Register Map	 GPIO_A		
************************************************************************************/


#define  GPIOA_MODER									(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X00)))			
#define  GPIOA_OTYPER									(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X04)))			
#define  GPIOA_OSPEEDR								    (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X08)))			
#define  GPIOA_PUPDR									(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X0C)))			
#define  GPIOA_IDR										(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X10)))			
#define  GPIOA_ODR										(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X14)))			
#define  GPIOA_BSRR										(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X18)))			
#define  GPIOA_LCKR										(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X1C)))			
#define  GPIOA_AFRL										(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X20)))			
#define  GPIOA_AFRH										(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X24)))			
/***********************************************************************************
	-----> Macros
			  *  Register Map	 GPIO_B		
************************************************************************************/


#define  GPIOB_MODER								   (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X00)))
#define  GPIOB_OTYPER								   (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X04)))
#define  GPIOB_OSPEEDR							       (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X08)))
#define  GPIOB_PUPDR								   (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X0C)))
#define  GPIOB_IDR									   (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X10)))
#define  GPIOB_ODR									   (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X14)))
#define  GPIOB_BSRR									   (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X18)))
#define  GPIOB_LCKR									   (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X1C)))
#define  GPIOB_AFRL									   (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X20)))
#define  GPIOB_AFRH									   (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X24)))
																										
/***********************************************************************************
	-----> Macros
			  *  Register Map	 GPIO_C		
************************************************************************************/


#define  GPIOC_MODER									(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X00)))
#define  GPIOC_OTYPER									(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X04)))
#define  GPIOC_OSPEEDR							    	(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X08)))
#define  GPIOC_PUPDR									(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X0C)))
#define  GPIOC_IDR										(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X10)))
#define  GPIOC_ODR										(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X14)))
#define  GPIOC_BSRR										(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X18)))
#define  GPIOC_LCKR										(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X1C)))
#define  GPIOC_AFRL										(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X20)))
#define  GPIOC_AFRH										(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X24)))
	
/***********************************************************************************
	-----> Macros
			  *  Register Map	 GPIO_D		
************************************************************************************/


#define  GPIOD_MODER									    (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X00)))
#define  GPIOD_OTYPER									    (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X04)))
#define  GPIOD_OSPEEDR							    	    (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X08)))
#define  GPIOD_PUPDR									    (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X0C)))
#define  GPIOD_IDR										    (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X10)))
#define  GPIOD_ODR										    (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X14)))
#define  GPIOD_BSRR										    (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X18)))
#define  GPIOD_LCKR										    (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X1C)))
#define  GPIOD_AFRL										    (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X20)))
#define  GPIOD_AFRH											(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X24)))

/***********************************************************************************
	-----> Macros
			  *  Register Map	 GPIO_E		
************************************************************************************/


#define  GPIOE_MODER									    (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X00)))
#define  GPIOE_OTYPER									    (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X04)))
#define  GPIOE_OSPEEDR								        (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X08)))
#define  GPIOE_PUPDR									    (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X0C)))
#define  GPIOE_IDR										    (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X10)))
#define  GPIOE_ODR										    (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X14)))
#define  GPIOE_BSRR										    (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X18)))
#define  GPIOE_LCKR										    (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X1C)))
#define  GPIOE_AFRL										    (*((volatile u32*) (GPIOA_BASE_ADDRESS +0X20)))
#define  GPIOE_AFRH											(*((volatile u32*) (GPIOA_BASE_ADDRESS +0X24)))


/***********************************************************************************
	-----> Macros
			  *  Register Map	 GPIO_H		
************************************************************************************/


#define  GPIOH_MODER									(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X00)))
#define  GPIOH_OTYPER									(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X04)))
#define  GPIOH_OSPEEDR								    (*((volatile u32*) (GPIOH_BASE_ADDRESS +0X08)))
#define  GPIOH_PUPDR									(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X0C)))
#define  GPIOH_IDR										(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X10)))
#define  GPIOH_ODR										(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X14)))
#define  GPIOH_BSRR										(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X18)))
#define  GPIOH_LCKR										(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X1C)))
#define  GPIOH_AFRL										(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X20)))
#define  GPIOH_AFRH										(*((volatile u32*) (GPIOH_BASE_ADDRESS +0X24)))

																																																																																																																																												
#endif //GPIO_PRIVATE_H

