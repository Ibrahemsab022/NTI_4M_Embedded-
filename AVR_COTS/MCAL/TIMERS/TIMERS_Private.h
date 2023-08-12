#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_





/*Macros for interrupt state*/
#define INTERRUPT_ENABLED		1u
#define INERRUPT_DISABLED		2u

/*Macros for the Prescaler configs*/
#define CLK_DISCONNECTED         0u
#define DIVIDE_BY_1              1u
#define DIVIDE_BY_8              2u
#define DIVIDE_BY_64             3u
#define DIVIDE_BY_256            4u
#define DIVIDE_BY_1024           5u
#define EXT_CLK_FALLING_EDGE     6u
#define EXT_CLK_RISING_EDGE      7u




/*Macros for the compare match output mode*/
#define OC0_DISCONNECTED		0u
#define OC0_TOGGLE				1u
#define OC0_CLEAR               2u
#define OC0_SET                 3u




/*Macros for the Forece output compare mode*/
#define FOC_DISABLED 			0u
#define FOC_ENABLED 			u

/*Macros for timer mdoe*/
#define NORMAL_MODE				1u
#define PHASE_CORRECT_MODE		2u
#define	CTC_MODE				3u
#define FAST_PWM_MODE			4u

/*Strcut holding the bits of the reg TCCR0*/
typedef struct
{
	u8 TCCR0_CS 	: 3;
	u8 TCCR0_WGM01  : 1;
	u8 TCCR0_COM	: 2;
	u8 TCCR0_WGM00  : 1;
	u8 TCCR0_FOC0	: 1;

}TCCR0_T;

/*the address of the reg TCC0 is casted as ptr to the struct of bit fileds*/
#define TCCR0	((volatile TCCR0_T *) 0x53)


#define TIMSK 	*((volatile u8 *) 0x59)
#define TIMSK_TOIE0		0u
#define TIMSK_OCIE0		1u



#define TCNT0	*((volatile u8 *) 0x52)
#define OCR0	*((volatile u8 *) 0x5C)

















/*
typedef union
{
	typedef struct
	{
		u8 B0:1;
	};


}Registers_t;*/















#endif
