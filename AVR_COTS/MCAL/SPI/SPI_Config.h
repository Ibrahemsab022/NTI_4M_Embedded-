#ifndef		SPI_CONFIG_H
#define		SPI_CONFIG_H


/*
* Select the pre scaler:
* 					 1- PRESEC_4
*                	 2- PRESEC_16
*                    3- PRESEC_64
*                    4- PRESEC_128
*                    5- PRESEC_2
*                    6- PRESEC_8
*                    7- PRESEC_32
*                    8- PRESEC_64
*
* NOTE: for proper sampling of the data, Speed must never exceed (Fsys / 4), Check datasheet p131
*/
#define SPI_PRESEC_MODE		PRESEC_16


/*Select clk polarity mode:
 * 					1- IDLE_LOW
 * 		            2- IDLE_HIGH
 * */
#define SPI_CLK_POLARITY	IDLE_LOW


/*Select clk phase mode:
 * 				1- CLK_PHASE_DISABLED
 *              2- CLK_PHASE_ENABLED
 * 	*/
#define SPI_CLK_PHASE	CLK_PHASE_DISABLED


/*
 * Select Data order mode:
 * 				1- LSB_FIRST
 *              2- MSB_FIRST
 * */
#define SPI_DATA_ORDER	MSB_FIRST

/*
 * Select Interrupt mode:
 * 			1- INT_DISABLED
			2- INT_ENABLED
 * */
#define SPI_INT_MODE	INT_DISABLED


/*Select double speed mdoe:
 *					1- SPEED_2x_DISABLED
 *					2- SPEED_2x_ENABLED
 *
 *Note: when config this, make sure to follow the condition in PRESEC_MODE config
 * */
#define SPI_SPEED_2X_MODE	SPEED_2x_DISABLED

#endif
