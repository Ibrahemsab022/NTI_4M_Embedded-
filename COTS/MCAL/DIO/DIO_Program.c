/***************************************************************************************/
/***************************************************************************************/
/* Header Inclusions					     	    */
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Config.h"

/********************************************************************************************************************************************/
/* Function: 				DIO_voidSetPinValue	                        				                                                    */
/* Input/outPut Parameters:	PortId, PinId and Value.		          		                                                                */
/* Returns:   				returns nothing (void)                           				                                                */
/* Descruption: this function takes the PortId wehther Port A,B,C or D and the PinId Pin0-7, and wether you want that pin to be high or low.*/
/********************************************************************************************************************************************/
void DIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value)
{
    
    if((Copy_u8PortId <= DIO_u8_PORTD) || (Copy_u8PinId <= DIO_u8_PIN7))
    {
        switch(Copy_u8PortId)   
        {
            case DIO_u8_PORTA:  switch(Copy_u8Value)    
                                {
                                    case  DIO_u8_LOW:   CLR_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);     break;  
                                    case  DIO_u8_HIGH:  SET_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);     break;   
                                }                            
                                break;
            case DIO_u8_PORTB:  switch(Copy_u8Value)
                                {       
                                    case  DIO_u8_LOW:   CLR_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);     break;
                                    case  DIO_u8_HIGH:  SET_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);     break;
                                }                            
                                break;
            case DIO_u8_PORTC:  switch(Copy_u8Value)
                                {
                                    case  DIO_u8_LOW:   CLR_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);     break;
                                    case  DIO_u8_HIGH:  SET_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);     break;
                                }                            
                                break;
            case DIO_u8_PORTD:  switch(Copy_u8Value)
                                {
                                    case  DIO_u8_LOW:   CLR_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);     break;
                                    case  DIO_u8_HIGH:  SET_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);     break;
                                }                            
                                break;
            
        }
    }
    else
    {
        
    }
}


/*********************************************************************************************************************************************/
/* Function: 				DIO_voidSetPinDirection	                        				    										     */
/* Input/outPut Parameters:	PortId, PinId and Direction		          		                            								     */
/* Returns:   				returns nothing (void)                             				                        					     */
/* Descruption: this func takes the PortId wehther Port A,B,C or D and the PinId Pin0-7, and wether you want that pin to be Input or Output. */
/*********************************************************************************************************************************************/
void DIO_voidSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction)
{
    
    if((Copy_u8PortId <= DIO_u8_PORTD) || (Copy_u8PinId <= DIO_u8_PIN7))
    {
        switch(Copy_u8PortId)   
        {
            case DIO_u8_PORTA:  switch(Copy_u8Direction)    
                                {
                                    case  DIO_u8_INPUT:   CLR_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);     break;  
                                    case  DIO_u8_OUTPUT:  SET_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);     break;   
                                }                            
                                break;
            case DIO_u8_PORTB:  switch(Copy_u8Direction)
                                {       
                                    case  DIO_u8_INPUT:   CLR_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);     break;
                                    case  DIO_u8_OUTPUT:  SET_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);     break;
                                }                            
                                break;
            case DIO_u8_PORTC:  switch(Copy_u8Direction)
                                {
                                    case  DIO_u8_INPUT:   CLR_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);     break;
                                    case  DIO_u8_OUTPUT:  SET_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);     break;
                                }                            
                                break;
            case DIO_u8_PORTD:  switch(Copy_u8Direction)
                                {
                                    case  DIO_u8_INPUT:   CLR_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);     break;
                                    case  DIO_u8_OUTPUT:  SET_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);     break;
                                }                            
                                break;
            
        }
    }
    else
    {
        
    }
}



/*******************************************************************************************************************/
/* Function: DIO_voidGetPinValue	                        				     							       */
/* Input/outPut Parameters:	PortId, PinID		          		                                                   */
/* Returns: returns unsigned 8bit value (u8)                          				                               */
/* Descruption:	this func takes the PortId wehther Port A,B,C or D and the PinId Pin0-7, and returns the Pin value.*/
/*******************************************************************************************************************/
u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
    
    u8 Local_u8PinValue = 5;
    
    if( (Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7))
    {
        switch(Copy_u8PortId)   
        {
            case DIO_u8_PORTA:  Local_u8PinValue = GET_BIT(DIO_u8_PINA_REG,Copy_u8PinId);  break;   
            case DIO_u8_PORTB:  Local_u8PinValue = GET_BIT(DIO_u8_PINB_REG,Copy_u8PinId);  break;
            case DIO_u8_PORTC:  Local_u8PinValue = GET_BIT(DIO_u8_PINC_REG,Copy_u8PinId);  break;
            case DIO_u8_PORTD:  Local_u8PinValue = GET_BIT(DIO_u8_PIND_REG,Copy_u8PinId);  break;
        }
    }
    else
    {
        
    }
    return Local_u8PinValue;    
}

/*********************************************************************************************************/
/* Function: DIO_voidSetPortValue	                        				     						 */
/* Input/outPut Parameters:	PortId and value		          		            						 */
/* Returns:  returns nothing (void)                              				                         */
/* Descruption:	this func takes the PortId wehther Port A,B,C or D and the value and put it in that port */
/*********************************************************************************************************/
void DIO_voidSetPortValue(u8 Copy_u8PortId, u8 Copy_u8Value)
{
    
	switch(Copy_u8Value)
	{
		case DIO_u8_HIGH:
		{
			switch(Copy_u8PortId)
			{
				case DIO_u8_PORTA:  DIO_u8_PORTA_REG = 0xff; break;
				case DIO_u8_PORTB:  DIO_u8_PORTB_REG = 0xff; break;
				case DIO_u8_PORTC:  DIO_u8_PORTC_REG = 0xff; break;
				case DIO_u8_PORTD:  DIO_u8_PORTD_REG = 0xff; break;
			}

			break;
		}

		case DIO_u8_LOW:
		{

			switch(Copy_u8PortId)
			{
				case DIO_u8_PORTA:  DIO_u8_PORTA_REG = 0x00; break;
				case DIO_u8_PORTB:  DIO_u8_PORTB_REG = 0x00; break;
				case DIO_u8_PORTC:  DIO_u8_PORTC_REG = 0x00; break;
				case DIO_u8_PORTD:  DIO_u8_PORTD_REG = 0x00; break;
			}

			break;

		}

		default:
		{
			case DIO_u8_PORTA:  DIO_u8_PORTA_REG = Copy_u8Value; break;
			case DIO_u8_PORTB:  DIO_u8_PORTB_REG = Copy_u8Value; break;
			case DIO_u8_PORTC:  DIO_u8_PORTC_REG = Copy_u8Value; break;
			case DIO_u8_PORTD:  DIO_u8_PORTD_REG = Copy_u8Value; break;
		}

	}
   
}


/*************************************************************************************************************/
/* Function: DIO_voidSetPortDirection	                        				                             */
/* Input/outPut Parameters:	PortId, and Direction		          		                                     */
/* Returns: returns nothing (void)                            				                                 */
/* Descruption:	this func takes the PortId wehther Port A,B,C or D and the direction and put it in that port */
/*************************************************************************************************************/
void DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8Direction)
{
    
	switch(Copy_u8Direction)
	{
		case DIO_u8_OUTPUT:
		{
			switch(Copy_u8PortId)
			{
				case DIO_u8_PORTA:  DIO_u8_DDRA_REG =  0xff; break;
				case DIO_u8_PORTB:  DIO_u8_DDRB_REG =  0xff; break;
				case DIO_u8_PORTC:  DIO_u8_DDRC_REG =  0xff; break;
				case DIO_u8_PORTD:  DIO_u8_DDRD_REG =  0xff; break;
			}

			break;
		}

		case DIO_u8_INPUT:
		{

			switch(Copy_u8PortId)
			{
				case DIO_u8_PORTA:  DIO_u8_DDRA_REG = 0x00; break;
				case DIO_u8_PORTB:  DIO_u8_DDRB_REG = 0x00; break;
				case DIO_u8_PORTC:  DIO_u8_DDRC_REG = 0x00; break;
				case DIO_u8_PORTD:  DIO_u8_DDRD_REG = 0x00; break;
			}

			break;

		}

		default:
		{
			case DIO_u8_PORTA:  DIO_u8_DDRA_REG = Copy_u8Direction; break;
			case DIO_u8_PORTB:  DIO_u8_DDRB_REG = Copy_u8Direction; break;
			case DIO_u8_PORTC:  DIO_u8_DDRC_REG = Copy_u8Direction; break;
			case DIO_u8_PORTD:  DIO_u8_DDRD_REG = Copy_u8Direction; break;
		}

	}
   

}

/*****************************************************************************************************************/
/* Function: DIO_voidGetPortValue	                        				     								 */
/* Input/outPut Parameters:PortId		          		                            							 */
/* Returns: returns an unsigned 8 bit data (u8)          				                    	                 */
/* Descruption:this func takes the PortId wehther Port A,B,C or D and returns the content of the port as a u8    */
/*****************************************************************************************************************/
u8 DIO_u8GetPortValue(u8 Copy_u8PortId)
{
   u8 Local_u8PortValue = 0;

   switch(Copy_u8PortId)
   {
   	   case DIO_u8_PORTA:	Local_u8PortValue = DIO_u8_PINA_REG; break;
   	   case DIO_u8_PORTB:	Local_u8PortValue = DIO_u8_PINB_REG; break;
   	   case DIO_u8_PORTC:	Local_u8PortValue = DIO_u8_PINC_REG; break;
   	   case DIO_u8_PORTD:	Local_u8PortValue = DIO_u8_PIND_REG; break;

   }

   return Local_u8PortValue;
}






/********************************************************************/
/* 	This Section for the initial state configuration implementation */
/****************************************************************** */

/*Initial Direction for PORTA*/
#if DIO_u8_PORTA_INIT_DIR == DIO_u8_INITIAL_INPUT
DDRA = 0x00;

#elif DIO_u8_PORTA_INIT_DIR == DIO_u8_INITIAL_OUTPUT
DDRA = 0xff;

#else
#error Wrong Configuration of PORTA Initial Direction

#endif



/*Initial Direction for PORTB*/
#if DIO_u8_PORTB_INIT_DIR == DIO_u8_INITIAL_INPUT
DDRB = 0x00;

#elif DIO_u8_PORTB_INIT_DIR == DIO_u8_INITIAL_OUTPUT
DDRB = 0xff;

#else
#error Wrong Configuration of PORTA Initial Direction

#endif



/*Initial Direction for PORTC*/
#if DIO_u8_PORTC_INIT_DIR == DIO_u8_INITIAL_INPUT
DDRC = 0x00;

#elif DIO_u8_PORTC_INIT_DIR == DIO_u8_INITIAL_OUTPUT
DDRC = 0xff;

#else
#error Wrong Configuration of PORTA Initial Direction

#endif



/*Initial Direction for PORTD*/
#if DIO_u8_PORTD_INIT_DIR == DIO_u8_INITIAL_INPUT
		DDRD = 0x00;

#elif DIO_u8_PORTD_INIT_DIR == DIO_u8_INITIAL_OUTPUT
		DDRD = 0xff;

#else
#error Wrong Configuration of PORTD Initial Direction

#endif





/*Initial Value of PORTA*/
#if DIO_u8_PORTA_INIT_VAL == DIO_u8_HIGH
		PORTA = 0xff;

#elif DIO_u8_PORTA_INIT_VAL == DIO_u8_LOW
		PORTA = 0x00;

#elif DIO_u8_PORTA_INIT_VAL == DIO_u8_INPUT_FLOATING
		PORTA = 0x00

#elif DIO_u8_PORTA_INIT_VAL == DIO_u8_INPUT_PULLUP
		PORTA = 0xff;

#else
#error Wrong Configuration of the initial value of PORTA

#endif

/*Initial Value of PORTB*/
#if DIO_u8_PORTB_INIT_VAL == DIO_u8_HIGH
		PORTB = 0xff;

#elif DIO_u8_PORTB_INIT_VAL == DIO_u8_LOW
		PORTB = 0x00;

#elif DIO_u8_PORTB_INIT_VAL == DIO_u8_INPUT_FLOATING
		PORTB = 0x00

#elif DIO_u8_PORTB_INIT_VAL == DIO_u8_INPUT_PULLUP
		PORTB = 0xff;

#else
#error Wrong Configuration of the initial value of PORTB

#endif



/*Initial Value of PORTC*/
#if DIO_u8_PORTC_INIT_VAL == DIO_u8_HIGH
		PORTC = 0xff;

#elif DIO_u8_PORTC_INIT_VAL == DIO_u8_LOW
		PORTC = 0x00;

#elif DIO_u8_PORTC_INIT_VAL == DIO_u8_INPUT_FLOATING
		PORTC = 0x00

#elif DIO_u8_PORTC_INIT_VAL == DIO_u8_INPUT_PULLUP
		PORTC = 0xff;

#else
#error Wrong Configuration of the initial value of PORTC

#endif




/*Initial Value of PORTD*/
#if DIO_u8_PORTD_INIT_VAL == DIO_u8_HIGH
		PORTD = 0xff;

#elif DIO_u8_PORTD_INIT_VAL == DIO_u8_LOW
		PORTD = 0x00;

#elif DIO_u8_PORTD_INIT_VAL == DIO_u8_INPUT_FLOATING
		PORTD = 0x00

#elif DIO_u8_PORTD_INIT_VAL == DIO_u8_INPUT_PULLUP
		PORTD = 0xff;

#else
#error Wrong Configuration of the initial value of PORTC

#endif
