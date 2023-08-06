#ifndef		SPI_PRIVATE_H
#define		SPI_PRIVATE_H

#define		SPI_u8_SPDR_REG			*((volatile u8 *)(0x2F))			// SPI Data Register

#define		SPI_u8_SPCR_REG			*((volatile u8 *)(0x2D))			// SPI Control Register
#define     SPI_u8_SPCR_SPR0		0u									// SPI Prescaler Bit0
#define     SPI_u8_SPCR_SPR1		1u									// SPI Prescaler Bit1
#define     SPI_u8_SPCR_CPHA		2u									// Clock Phase
#define     SPI_u8_SPCR_CPOL		3u									// Clock Polarity
#define     SPI_u8_SPCR_MSTR		4u									// MASTER bit
#define     SPI_u8_SPCR_DORD		5u									// Data OverRun
#define     SPI_u8_SPCR_SPE		    6u									// SPI Enable
#define     SPI_u8_SPCR_SPIE		7u									// SPI Interrupt Enable

#define		SPI_u8_SPSR_REG			*((volatile u8 *)(0x2E))			// SPI Status Register
#define		SPI_u8_SPSR_SPI2X		0u									// SPI Prescaler Bit2
#define		SPI_u8_SPSR_WCOL		6u									// SPI Write Collision Flag
#define		SPI_u8_SPSR_SPIF		7u									// SPI Interrupt Flag


/*Macros for prescalers*/
#define PRESEC_4                     0u
#define PRESEC_16                    1u
#define PRESEC_64                    2u
#define PRESEC_128                   3u
#define PRESEC_2                     4u
#define PRESEC_8                     5u
#define PRESEC_32                    6u
#define PRESEC_64                    7u

#define PRESEC_MASK					0b11



/*Macros for clk Polarity*/
#define IDLE_LOW          1u
#define IDLE_HIGH         2u


/*Macros for clk phase*/
#define CLK_PHASE_DISABLED			   1u
#define CLK_PHASE_ENABLED              2u

/*Macros for Data order*/
#define LSB_FIRST                       1u
#define MSB_FIRST                       2u


/*Macros for interrupt state*/
#define INT_DISABLED                     1u
#define INT_ENABLED                      2u

/*Macros for double the speed mode*/
#define SPEED_2x_DISABLED				1u
#define SPEED_2x_ENABLED                2u







#endif
