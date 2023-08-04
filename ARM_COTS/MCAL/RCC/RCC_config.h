#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/*
 * Select the PLL Main division factor PLLQ:
 * 								1-  PLLQ_divideBy_2
 *                              2-  PLLQ_divideBy_3
 *                              3-  PLLQ_divideBy_4
 *                              4-  PLLQ_divideBy_5
 *                              5-  PLLQ_divideBy_6
 *                              6-  PLLQ_divideBy_7
 *                              7-  PLLQ_divideBy_8
 *                              8-  PLLQ_divideBy_9
 *                              9-  PLLQ_divideBy_10
 *                              10- PLLQ_divideBy_11
 *                              11- PLLQ_divideBy_12
 *                              12- PLLQ_divideBy_13
 *                              13- PLLQ_divideBy_14
 *                              14- PLLQ_divideBy_15
 * */


#define PLLQ		PLLQ_divideBy_4


/*Enter the FVCO Multiply factor value between 192 & 432 (VALUE MUST NOT EXCEED THIS RANGE)
 *
 * */
#define PLLN	195u


/*Enter the main division factor value between 2 & 63 (VALUE MUST NOT EXCEED THIS RANGE)*/
#define PLLM		50u
	 
	 
	
	
	
	
	
	
#endif /* RCC_CONFIG_H_ */
