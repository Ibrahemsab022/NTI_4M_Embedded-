#ifndef TIMERS_INERFACE_H_
#define TIMERS_INTERFACE_H_





void TIMER0_voidInit(void);

void TIMER0_voidStart(void);

void TIMER0_voidStop(void);

void TIMER0_voidPreload(u8 Copy_u8PreloadVal);

void TIMER0_voidSetCallBack(void (*PtrToFunc)(void));

void TIMER0_voidGeneratePWM(u8 DutyCycle);








#endif
