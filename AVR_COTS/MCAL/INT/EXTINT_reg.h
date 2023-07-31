
#ifndef EXTINT_REG_H_
#define EXTINT_REG_H_


#define MCUCR     *((volatile u8*)0x55)
#define MCUCSR    *((volatile u8*)0x54)
#define GICR      *((volatile u8*)0x5B)
#define GIFR      *((volatile u8*)0x5A)


#endif /* EXTINT_REG_H_ */
