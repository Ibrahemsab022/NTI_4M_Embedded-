/************************************************************************************************/
/************************************************************************************************
		
-The Functionality Of Pines : 
		
		- Input		: (Defult= PullUp | PullDowen | Floating ---> When To Use ????? )  .
		- Floating	: (Not Connect High Or Low Between (0:1) ) When Used ---> With Sensor To Be Sensetive For Zero And 1 And Between  .
		- Pull_Up&Dowen ( To Treat The Floating On The Pin To Read Only ( 1 | 0 ) Nothing In Between ) .
		- OutPut    : Can Be (PushPull | OpenDrain ) .
		- PushPull  : The OutPut From This Case High=1 | LOW = 0  .
		- OpenDrain : The OutPut From This Case At( Pull_Up & PullDowen )  .
							- At Pull_UP   0 == Ground & 1 == Floating .
							- The Advantage Of This Case When You Make OutPut Pin out Floating you Can Connect Vcc From Out Not Micro So Any Volt You Need Connect It Direct And Any Current ( Configrable - High Level Volt) .
							- Must Connect Resistance For The Case Of Zero Not Make Short Circuit At  ( Configrable - High Level Volt) .
							- Open Drain Bus Not Make Short Circuit Between Two Micro At The Same Bus When One Send 1 And Oher Send 0 .
							- At PullDowen 1 == Vcc & 0 == Floating  -----> So Will give Output Only In This Case  .
							
		- Altternative Function : Every Pin Can Make 16 Function Anther (InPut , OutPut , Analog)  As ( Uart , Spi , Can , Timer , ADC , I2C , ........)        Every Pin Need 4 Bit 
		- ALF : From GPIO Choice Bit AS ALF But The Function From -----> ????????
				
	
************************************************************************************************/ 


#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
	
	/*		Function Set The Mode Of Pin ( InPut , OutPut , Alternate Function , Analog )	*/
void DIO_voidSetPinMode(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8MODE)  ;
/*		Function Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1)		*/
void DIO_voidSetOutType(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8Type)  ;
/*		Function Set The Speed (LOW , Meduim , High ,VeryHaigh	) Control Speed Good For Power Consumtion 	*/
void DIO_voidSetOutSpeed(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8Speed)  ;
/*		Function Set The PULL ( OFF , UP , DOWN )		*/
void DIO_voidSetPull(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8PULL_TYPE)  ;
/*		Function To Read Data From IDR At Inpiut Mode 		*/
u8 DIO_u8ReadData(u8 copy_u8PORT ,u8 copy_u8PIN)  ;
/*		Function To Write Data At ODRValue = high , low At OutPot Mode 	*/
void DIO_voidWriteDataOdr(u8 copy_u8PORT ,u8 copy_u8PIN , u8 copy_u8Value )  ;
/*		Function Set The Altternative Function	Every Pin Can Make 16 Function Anther (InPut , OutPut , Analog) */
void DIO_voidPinSetAltFn(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8AlT)  ;


			/* Macros Of Port */
			
#define  GPIOA_PORT										0
#define  GPIOB_PORT										1
#define  GPIOC_PORT										2
#define  GPIOD_PORT										3
#define  GPIOE_PORT										4
#define  GPIOF_PORT										5
#define  GPIOG_PORT										6
#define  GPIOH_PORT										7

			/* Macros Of Pins */

#define  PIN0									   	0
#define  PIN1									   	1
#define  PIN2									   	2
#define  PIN3									   	3
#define  PIN4									   	4
#define  PIN5									   	5
#define  PIN6									   	6
#define  PIN7									   	7
#define  PIN8									   	8
#define  PIN9									   	9
#define  PIN10										10
#define  PIN11										11
#define  PIN12										12
#define  PIN13										13
#define  PIN14										14
#define  PIN15										15

			/*Macros Of Mode*/
#define MODE_INPUT							 				((u8)0x00)
#define MODE_OUTPUT							 				((u8)0x01)
#define MODE_ALTF										 	((u8)0x02)
#define MODE_ANALOG							 				((u8)0x03)
																 
			/*Macros Of Type*/
#define  OUTPUT_TYPE_PUSH_PULL			((u8)0x0)
#define  OUTPUT_TYPE_OPEN_DRAIN			((u8)0x1)

			/*Macros Of Speed*/
			
#define OUTPUT_LOW_SPEED									((u8)0x00)
#define OUTPUT_MEDUIM_SPEED									((u8)0x01)
#define OUTPUT_HIGH_SPEED									((u8)0x02)
#define OUTPUT_VERY_HIGH_SPEED								((u8)0x03)

			/*Macros Of PULL*/	
#define PULL_OFF						((u8)0x00)							
#define PULL_UP							((u8)0x01)
#define PULL_DOWN						((u8)0x02)
																			
			/*Macros Write Data */	
#define  HIGH												((u8)0x1)
#define  LOW												((u8)0x0)		




/*Macros for Alt functions*/
#define AF0       (0x0u)
#define AF1       (0x1u)
#define AF2       (0x2u)
#define AF3       (0x3u)
#define AF4       (0x4u)
#define AF5       (0x5u)
#define AF6       (0x6u)
#define AF7       (0x7u)
#define AF8       (0x8u)
#define AF9       (0x9u)
#define AF10      (0xAu)
#define AF11      (0xBu)
#define AF12      (0xCu)
#define AF13      (0xDu)
#define AF14      (0xEu)
#define AF15      (0xFu)












#endif /* GPIO_INTERFACE_H*/
/************************************************************************************************/
