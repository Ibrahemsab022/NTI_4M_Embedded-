/****************************************************************************************
***************************   The Foundation Of Function   ***************************** 
****************************************************************************************/


/************** INCLUDE LIB **************/
		 #include "STD_TYPES.h"
		 #include "BIT_MATH.h"
/*****************************************/	 

/************** INCLUDE MCAL**************/
		#include "RCC_private.h"
		#include "RCC_interface.h"
		#include "RCC_config.h"
/*****************************************/

/************** INCLUDE HALL**************/
			

/*****************************************/

/************** INCLUDEAPP***************/


/*****************************************/





/************************************ Start_FUNCTION  ************************************/
/* About The Function :
	
				- CLK		: HSE | HSI |PLL	
				- PLLSrc	:PLL_HSE | PLL_HSI
				- HSESrc    :HSE_Crystal ,HSE_RC 
				- If not used send 0
 */
 void RCC_voidInitSysClock( ClkSrcName_t ClkSrc , HSESrcName_t HSESrc , PllSrcName_t PLLSrc  , AHBPreName_t AHB_Prescaler , APB1PreName_t APB1_Prescaler  , APB2PreName_t APB2_Prescaler)
 {
		switch(ClkSrc)
		{
			//HSE
			case RCC_HSE:
			{
				switch (HSESrc)
				{

					// HSE CRYSTAL
					case  HSE_Crystal : SET_BIT(RCC_CR, RCC_CR_HSEON); CLR_BIT(RCC_CR, RCC_CR_HSEBYP); break;

					// HSE RC
					case  HSE_RC : SET_BIT(RCC_CR, RCC_CR_HSEON); SET_BIT(RCC_CR, RCC_CR_HSEBYP); break;
						
					
					default: /*Choose HSE_Crystla*/
						SET_BIT(RCC_CR, RCC_CR_HSEON); CLR_BIT(RCC_CR, RCC_CR_HSEBYP); break;
				}

				/*Setting the switch mode (SW bits in RCC_CFGR)*/
				RCC_CFGR &= ~(0b11);
				RCC_CFGR |= RCC_HSE;

			}break;

			 /*******************************************************************************/ 
			 // HSI  
			case RCC_HSI:
			{
				SET_BIT(RCC_CR, RCC_CR_HSION);

		/*Setting the switch mode (SW bits in RCC_CFGR)*/
		RCC_CFGR &= ~(0b11);
		RCC_CFGR |= RCC_HSI;
			}break;

			/*********************************************************************************/
			// PLL 
			case RCC_PLL:
				 switch(PLLSrc)
				 {
					 // PLL HSE 
					 case PLL_HSE: SET_BIT(RCC_PLLCFGR, RCC_PLLCFGR_PLLSRC); break;
					 // PLL HSI
					 case PLL_HSI: CLR_BIT(RCC_PLLCFGR, RCC_PLLCFGR_PLLSRC); break;
					 default: SET_BIT(RCC_PLLCFGR, RCC_PLLCFGR_PLLSRC); /*PLL with internal*/
					 


			/*Setting the switch mode (SW bits in RCC_CFGR)*/
			RCC_CFGR &= ~(0b11);
			RCC_CFGR |= RCC_PLL;

				 }break;

			
			 }
			/****************************************************************************************/
				/*
	 ABP1_Pre1
	 ABP1_Pre2
	 ABP1_Pre4
	 ABP1_Pre8
	 ABP1_Pre16
	
	*/
		RCC_CFGR &= ~(((u32)0b111) << 10);
		RCC_CFGR |= (((u32)APB1_Prescaler) << 10);
/**************************************************************************************************/	
		/*
		* APB2_Prescaller 
		ABP2_Pre1
		ABP2_Pre2
		ABP2_Pre4
		ABP2_Pre8
		ABP2_Pre16
		13 , 14 ,15
		*/
		RCC_CFGR &= ~(((u32)0b111) << 13);
		RCC_CFGR |= (((u32)APB2_Prescaler) << 13);


			
			/*
					AHB_Pre1
					AHB_Pre2
					AHB_Pre4
					AHB_Pre8
					AHB_Pre16
					AHB_Pre32
					AHB_Pre64
					AHB_Pre128
					AHB_Pre256
					AHB_Pre512
			*/
		RCC_CFGR &= ~(((u32)0b1111) << 4);
		RCC_CFGR |= (((u32)AHB_Prescaler) << 4);
 }



/*********************************************************** END_ FUNCTION   ***********************************************************/



\
/************************************ Start_FUNCTION  ************************************/

 void RCC_voidEnableClock (BusName_t BusName ,u8 Copy_u8PerName)
 {
	 switch(BusName) 
	 {
		 case AHB1_BUS :
			SET_BIT(RCC_AHB1ENR , Copy_u8PerName  ) ;
		 break ; 
		 
		 case AHB2_BUS  :
			SET_BIT(RCC_AHB2ENR , Copy_u8PerName  ) ;
		 break ;
		 
		 case APB1_BUS  :
			SET_BIT(RCC_APB1LPENR , Copy_u8PerName  ) ;
		 break ;

		 case APB2_BUS  :
			SET_BIT(RCC_APB2LPENR , Copy_u8PerName  ) ;
		 break ;

		 default: /*do nothing*/

			/*default		:  break;*/


	 }
 }


/************************************ Start_FUNCTION  ************************************/

 void RCC_voidDisableClock (BusName_t BusName ,u8 Copy_u8PerName)
 {
	 switch(BusName)
	 {
		 case AHB1_BUS :
			CLR_BIT(RCC_AHB1ENR , Copy_u8PerName) ;
		 break ;

		 case AHB2_BUS  :
			CLR_BIT(RCC_AHB2ENR , Copy_u8PerName) ;
		 break ;
		 
		 case APB1_BUS  :
			CLR_BIT(RCC_APB1LPENR , Copy_u8PerName) ;
		 break ;
		 
		 case APB2_BUS  :
			CLR_BIT(RCC_APB2LPENR , Copy_u8PerName) ;
		 break ;
		 
		 default: /*do nothing*/

			/*default		:  break;*/
		 
		 
	 }
 }
