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
	if (Copy_u8PortId <= DIO_u8_PORTD)
	{
		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA: DIO_u8_PORTA_REG = Copy_u8Value; break;
			case DIO_u8_PORTB: DIO_u8_PORTB_REG = Copy_u8Value; break;
			case DIO_u8_PORTC: DIO_u8_PORTC_REG = Copy_u8Value; break;
			case DIO_u8_PORTD: DIO_u8_PORTD_REG = Copy_u8Value; break;
		}
	}

	else
	{
		/*do nothing*/
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
	if (Copy_u8PortId <= DIO_u8_PORTD)
	{
		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA: DIO_u8_PORTA_REG = Copy_u8Direction; break;
			case DIO_u8_PORTB: DIO_u8_PORTB_REG = Copy_u8Direction; break;
			case DIO_u8_PORTC: DIO_u8_PORTC_REG = Copy_u8Direction; break;
			case DIO_u8_PORTD: DIO_u8_PORTD_REG = Copy_u8Direction; break;
		}
	}

	else
	{
		/*do nothing*/
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

	if(Copy_u8PortId <= DIO_u8_PORTD)
	{


	   switch(Copy_u8PortId)
	   {
		   case DIO_u8_PORTA:	Local_u8PortValue = DIO_u8_PINA_REG; break;
		   case DIO_u8_PORTB:	Local_u8PortValue = DIO_u8_PINB_REG; break;
		   case DIO_u8_PORTC:	Local_u8PortValue = DIO_u8_PINC_REG; break;
		   case DIO_u8_PORTD:	Local_u8PortValue = DIO_u8_PIND_REG; break;

	   }


	}

	else
	{
		/*Do nothing*/
	}

	return Local_u8PortValue;

}
