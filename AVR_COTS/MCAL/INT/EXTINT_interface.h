
#ifndef EXTINT_INTERFACE_H_
#define EXTINT_INTERFACE_H_
#include "STD_TYPES.h"

#define EXTINT_INT0         0
#define EXTINT_INT1         1
#define EXTINT_INT2         2

#define EXTINT_FALLING_EDGE       1
#define EXTINT_RAISING_EDGE       2
#define EXTINT_ANY_LOGICAL_CHANGE 3
#define EXTINT_LOW_LEVEL          4


void EXTINT_voidEnable(u8 Copy_u8ExtIntNum , u8 Copy_u8EdgeIntSource);

void EXTINT_voidDisable(u8 Copy_u8ExtIntNum);

void EXTINT_voidSetCallBack(void(*Copy_pfun)(void),u8 Copy_u8ExtIntIndex);

#endif /* EXTINT_INTERFACE_H_ */
