/*********************************************************************************************/
/*********************************************************************************************/


/************** INCLUDE LIB **************/
		 #include "STD_TYPES.h"
		 #include "BIT_MATH.h"
/*****************************************/	 

/************** INCLUDE MCAL**************/
		#include "GPIO_private.h"
		#include "GPIO_interface.h"
		#include "GPIO_config.h"
/*****************************************/

/************** INCLUDE HALL**************/
			

/*****************************************/

/************** INCLUDEAPP***************/


/*****************************************/





/********************************************************** Start_FUNCTION  **********************************************************/
/*		Function Set The Mode Of Pin Mode Take 2Bits	

									MODE_INPUT
									MODE_OUTPUT
									MODE_ALTF
									MODE_ANALOG	

						*/
 void DIO_voidSetPinMode(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8MODE) 
 {
	 
	 	if ((copy_u8PORT <= PORT_LIMIT) && (copy_u8PIN <= PIN_LIMIT))
	 	{
		switch (copy_u8PORT)
		{

				  case GPIOA_PORT: GPIOA_MODER &= (~((u32)(0b11 << (copy_u8PIN * 2))));  GPIOA_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN * 2)); break;
				  case GPIOB_PORT: GPIOA_MODER &= (~((u32)(0b11 << (copy_u8PIN * 2))));  GPIOB_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN * 2)); break;
				  case GPIOC_PORT: GPIOA_MODER &= (~((u32)(0b11 << (copy_u8PIN * 2))));  GPIOC_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN * 2)); break;
				  case GPIOD_PORT: GPIOA_MODER &= (~((u32)(0b11 << (copy_u8PIN * 2))));  GPIOD_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN * 2)); break;
				  case GPIOE_PORT: GPIOA_MODER &= (~((u32)(0b11 << (copy_u8PIN * 2))));  GPIOE_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN * 2)); break;
				  case GPIOH_PORT: GPIOA_MODER &= (~((u32)(0b11 << (copy_u8PIN * 2))));  GPIOH_MODER |=(u32)  (copy_u8MODE << (copy_u8PIN * 2)); break;
				  default: break;
		 }

	 	}

	 	else
	 	{
	 		/*Do nothing*/
	 	}
	 
 }
				

/*********************************************************** END_ FUNCTION   ***********************************************************/


/********************************************************** Start_FUNCTION  **********************************************************/
/*				Function Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1)

								OUTPUT_TYPE_PUSH_PULL
								OUTPUT_TYPE_OPEN_DRAIN	

						*/
void DIO_voidSetOutType(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8Type) 
{
		      

	if ((copy_u8PORT <= PORT_LIMIT) && (copy_u8PIN <= PIN_LIMIT))
		 	{
				switch (copy_u8PORT)
				{
						  case GPIOA_PORT: GPIOA_OTYPER &= (~((u32)(1 << (copy_u8PIN))));  GPIOA_OTYPER |=(u32)  (copy_u8Type << (copy_u8PIN)); break;
						  case GPIOB_PORT: GPIOA_OTYPER &= (~((u32)(1 << (copy_u8PIN))));  GPIOB_OTYPER |=(u32)  (copy_u8Type << (copy_u8PIN)); break;
						  case GPIOC_PORT: GPIOA_OTYPER &= (~((u32)(1 << (copy_u8PIN))));  GPIOC_OTYPER |=(u32)  (copy_u8Type << (copy_u8PIN)); break;
						  case GPIOD_PORT: GPIOA_OTYPER &= (~((u32)(1 << (copy_u8PIN))));  GPIOD_OTYPER |=(u32)  (copy_u8Type << (copy_u8PIN)); break;
						  case GPIOE_PORT: GPIOA_OTYPER &= (~((u32)(1 << (copy_u8PIN))));  GPIOE_OTYPER |=(u32)  (copy_u8Type << (copy_u8PIN)); break;
						  case GPIOH_PORT: GPIOA_OTYPER &= (~((u32)(1 << (copy_u8PIN))));  GPIOH_OTYPER |=(u32)  (copy_u8Type << (copy_u8PIN)); break;
						  default: break;
				 }

		 	}


	else
	{
		/*Do nothing*/
	}


}


/*********************************************************** END_ FUNCTION   ***********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
/*						Function Set The Speed (LOW , Meduim , High ,VeryHaigh		
							
							OUTPUT_LOW_SPEED
							OUTPUT_MEDUIM_SPEED
							OUTPUT_HIGH_SPEED
							OUTPUT_VERY_HIGH_SPEED
							
							

						*/
void DIO_voidSetOutSpeed(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8Speed)
{
		      

	if ((copy_u8PORT <= PORT_LIMIT) && (copy_u8PIN <= PIN_LIMIT))
			 	{
					switch (copy_u8PORT)
					{
							 case GPIOA_PORT: GPIOA_OSPEEDR &= (~((u32)(0b11 << (copy_u8PIN * 2))));   GPIOA_OSPEEDR |=(u32)  (copy_u8Speed << (copy_u8PIN *2)); break;
							 case GPIOB_PORT: GPIOA_OSPEEDR &= (~((u32)(0b11 << (copy_u8PIN * 2))));   GPIOB_OSPEEDR |=(u32)  (copy_u8Speed << (copy_u8PIN *2)); break;
							 case GPIOC_PORT: GPIOA_OSPEEDR &= (~((u32)(0b11 << (copy_u8PIN * 2))));   GPIOC_OSPEEDR |=(u32)  (copy_u8Speed << (copy_u8PIN *2)); break;
							 case GPIOD_PORT: GPIOA_OSPEEDR &= (~((u32)(0b11 << (copy_u8PIN * 2))));   GPIOD_OSPEEDR |=(u32)  (copy_u8Speed << (copy_u8PIN *2)); break;
							 case GPIOE_PORT: GPIOA_OSPEEDR &= (~((u32)(0b11 << (copy_u8PIN * 2))));   GPIOE_OSPEEDR |=(u32)  (copy_u8Speed << (copy_u8PIN *2)); break;
							 case GPIOH_PORT: GPIOA_OSPEEDR &= (~((u32)(0b11 << (copy_u8PIN * 2))));   GPIOH_OSPEEDR |=(u32)  (copy_u8Speed << (copy_u8PIN *2)); break;
							 default: break;
					 }

			 	}


		else
		{
			/*Do nothing*/
		}

}


/*********************************************************** END_ FUNCTION   ***********************************************************/

/********************************************************** Start_FUNCTION  **********************************************************/
	/*		Function Set The PULL :
								
					PULL_OFF
					PULL_UP
					PULL_DOWN
	
	
		*/
	void DIO_voidSetPull(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8PULL_TYPE)  
{
		      
		if ((copy_u8PORT <= PORT_LIMIT) && (copy_u8PIN <= PIN_LIMIT))
				 	{
						switch (copy_u8PORT)
						{
								case GPIOA_PORT: GPIOA_PUPDR &= (~((u32)(0b11 << (copy_u8PIN * 2))));   GPIOA_PUPDR |=(u32)  (copy_u8PULL_TYPE << (copy_u8PIN *2)); break;
								case GPIOB_PORT: GPIOA_PUPDR &= (~((u32)(0b11 << (copy_u8PIN * 2))));   GPIOB_PUPDR |=(u32)  (copy_u8PULL_TYPE << (copy_u8PIN *2)); break;
								case GPIOC_PORT: GPIOA_PUPDR &= (~((u32)(0b11 << (copy_u8PIN * 2))));   GPIOC_PUPDR |=(u32)  (copy_u8PULL_TYPE << (copy_u8PIN *2)); break;
								case GPIOD_PORT: GPIOA_PUPDR &= (~((u32)(0b11 << (copy_u8PIN * 2))));   GPIOD_PUPDR |=(u32)  (copy_u8PULL_TYPE << (copy_u8PIN *2)); break;
								case GPIOE_PORT: GPIOA_PUPDR &= (~((u32)(0b11 << (copy_u8PIN * 2))));   GPIOE_PUPDR |=(u32)  (copy_u8PULL_TYPE << (copy_u8PIN *2)); break;
								case GPIOH_PORT: GPIOA_PUPDR &= (~((u32)(0b11 << (copy_u8PIN * 2))));   GPIOH_PUPDR |=(u32)  (copy_u8PULL_TYPE << (copy_u8PIN *2)); break;
								default: break;
						 }

				 	}


			else
			{
				/*Do nothing*/
			}







}


/*********************************************************** END_ FUNCTION   ***********************************************************/


/********************************************************** Start_FUNCTION  **********************************************************/
		/*		Function To Read Data From IDR		*/
		u8 DIO_u8ReadData(u8 copy_u8PORT ,u8 copy_u8PIN)
{
			u8 u8Local_Data = 0 ;
			
		      
			if ((copy_u8PORT <= PORT_LIMIT) && (copy_u8PIN <= PIN_LIMIT))
					 	{
							switch (copy_u8PORT)
							{
								case GPIOA_PORT: u8Local_Data = GET_BIT(GPIOA_IDR, copy_u8PIN); break;
								case GPIOB_PORT: u8Local_Data = GET_BIT(GPIOB_IDR, copy_u8PIN); break;
								case GPIOC_PORT: u8Local_Data = GET_BIT(GPIOC_IDR, copy_u8PIN); break;
								case GPIOD_PORT: u8Local_Data = GET_BIT(GPIOD_IDR, copy_u8PIN); break;
								case GPIOE_PORT: u8Local_Data = GET_BIT(GPIOE_IDR, copy_u8PIN); break;
								case GPIOH_PORT: u8Local_Data = GET_BIT(GPIOH_IDR, copy_u8PIN); break;
								default: break;
							 }

					 	}


				else
				{
					/*Do nothing*/
				}


			  return u8Local_Data ; 
}


/*********************************************************** END_ FUNCTION   ***********************************************************/


/********************************************************** Start_FUNCTION  **********************************************************/
	/*		
			* Function To Write Data At ODR	Value :
									 high 
									 low	
	*/
	void DIO_voidWriteDataOdr(u8 copy_u8PORT ,u8 copy_u8PIN , u8 copy_u8Value )
 {
	
		if ((copy_u8PORT <= PORT_LIMIT) && (copy_u8PIN <= PIN_LIMIT))
		{
			switch (copy_u8PORT)
			{
				case GPIOA_PORT: GPIOA_ODR &= (~((u32)(1 << (copy_u8PIN)))); GPIOA_ODR |=(u32)  (copy_u8Value << (copy_u8PIN)); break;
				case GPIOB_PORT: GPIOA_ODR &= (~((u32)(1 << (copy_u8PIN)))); GPIOB_ODR |=(u32)  (copy_u8Value << (copy_u8PIN)); break;
				case GPIOC_PORT: GPIOA_ODR &= (~((u32)(1 << (copy_u8PIN)))); GPIOC_ODR |=(u32)  (copy_u8Value << (copy_u8PIN)); break;
				case GPIOD_PORT: GPIOA_ODR &= (~((u32)(1 << (copy_u8PIN)))); GPIOD_ODR |=(u32)  (copy_u8Value << (copy_u8PIN)); break;
				case GPIOE_PORT: GPIOA_ODR &= (~((u32)(1 << (copy_u8PIN)))); GPIOE_ODR |=(u32)  (copy_u8Value << (copy_u8PIN)); break;
				case GPIOH_PORT: GPIOA_ODR &= (~((u32)(1 << (copy_u8PIN)))); GPIOH_ODR |=(u32)  (copy_u8Value << (copy_u8PIN)); break;
				default: break;
			 }

		}


		else
		{
			/*Do nothing*/
		}
	
}


/*********************************************************** END_ FUNCTION   ***********************************************************/
	

/*		Function Set The AltFn		: Every Pin Need 4 Bits SO We Have High AND Low			*/
void DIO_voidPinSetAltFn(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8AlT)

{
	
	/* From 0 To  7 */
	if ((copy_u8PIN >= PIN0) && (copy_u8PIN <= PIN7))
	{

		switch (copy_u8PORT)
		{
			case GPIOA_PORT: GPIOA_AFRL &= (~((u32)(0b1111 << (copy_u8PIN * 4))));   GPIOA_AFRL |=(u32)  (copy_u8AlT << (copy_u8PIN *4)); break;
			case GPIOB_PORT: GPIOA_AFRL &= (~((u32)(0b1111 << (copy_u8PIN * 4))));   GPIOB_AFRL |=(u32)  (copy_u8AlT << (copy_u8PIN *4)); break;
			case GPIOC_PORT: GPIOA_AFRL &= (~((u32)(0b1111 << (copy_u8PIN * 4))));   GPIOC_AFRL |=(u32)  (copy_u8AlT << (copy_u8PIN *4)); break;
			case GPIOD_PORT: GPIOA_AFRL &= (~((u32)(0b1111 << (copy_u8PIN * 4))));   GPIOD_AFRL |=(u32)  (copy_u8AlT << (copy_u8PIN *4)); break;
			case GPIOE_PORT: GPIOA_AFRL &= (~((u32)(0b1111 << (copy_u8PIN * 4))));   GPIOE_AFRL |=(u32)  (copy_u8AlT << (copy_u8PIN *4)); break;
			case GPIOH_PORT: GPIOA_AFRL &= (~((u32)(0b1111 << (copy_u8PIN * 4))));   GPIOH_AFRL |=(u32)  (copy_u8AlT << (copy_u8PIN *4)); break;
			default: break;
		 }

	}


	/* From 8 To  15 */
	else if ((copy_u8PIN > PIN7) && (copy_u8PIN <= PIN15))
	{
		copy_u8PIN -= 8;

		switch (copy_u8PORT)
		{
			case GPIOA_PORT: GPIOA_AFRH &= (~((u32)(0b1111 << (copy_u8PIN * 4))));   GPIOA_AFRH |=(u32)  (copy_u8AlT << (copy_u8PIN *4)); break;
			case GPIOB_PORT: GPIOA_AFRH &= (~((u32)(0b1111 << (copy_u8PIN * 4))));   GPIOB_AFRH |=(u32)  (copy_u8AlT << (copy_u8PIN *4)); break;
			case GPIOC_PORT: GPIOA_AFRH &= (~((u32)(0b1111 << (copy_u8PIN * 4))));   GPIOC_AFRH |=(u32)  (copy_u8AlT << (copy_u8PIN *4)); break;
			case GPIOD_PORT: GPIOA_AFRH &= (~((u32)(0b1111 << (copy_u8PIN * 4))));   GPIOD_AFRH |=(u32)  (copy_u8AlT << (copy_u8PIN *4)); break;
			case GPIOE_PORT: GPIOA_AFRH &= (~((u32)(0b1111 << (copy_u8PIN * 4))));   GPIOE_AFRH |=(u32)  (copy_u8AlT << (copy_u8PIN *4)); break;
			case GPIOH_PORT: GPIOA_AFRH &= (~((u32)(0b1111 << (copy_u8PIN * 4))));   GPIOH_AFRH |=(u32)  (copy_u8AlT << (copy_u8PIN *4)); break;
			default: break;
		 }

	}




	else
	{
		/*Do nothing*/
	}
	
}
