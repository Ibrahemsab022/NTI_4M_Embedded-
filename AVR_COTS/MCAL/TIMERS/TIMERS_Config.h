#ifndef TIMERS_CONFIG_H_
#define TIMERS_CONFIG_H_



/*Enter the clk speed in MHz*/
#define SYSTEM_FREQ   16u


/*Config the number of overflows*/
#define OVERFLOW_NUM	977u


/*Config the init state of the overflow interrupt:
 *                            1- INTERRUPT_ENABLED
 *                            2- INERRUPT_DISABLED
 *
 **/
#define OVERFLOW_INTERRUPT_STATE   INERRUPT_DISABLED



/*Config the init state of the overflow interrupt:
 *                            1- INTERRUPT_ENABLED
 *                            2- INERRUPT_DISABLED
 *
 **/
#define OUTPUT_COMPARE_INTERRUPT_STATE		INERRUPT_DISABLED




/*Config the init state of the Force-output-Compare mode:
 *											1- FOC_DISABLED
 *											2- FOC_ENABLED
 *
 **/
#define FOC_INIT_MODE	FOC_DISABLED


/*Config the timer mode:
 *					1- NORMAL_MODE
 *					2- PHASE_CORRECT_MODE
 *					3- CTC_MODE
 *					4- FAST_PWM_MODE
 *
 *
 **/
#define TIMER_MODE		FAST_PWM_MODE


/*Config Compare match output mode:
 *					1- OC0_DISCONNECTED
 * 		            2- OC0_TOGGLE
 * 		            3- OC0_CLEAR
 *                  4- OC0_SET
 **/
#define COMP_MATCH_OUTPUT_MODE		OC0_CLEAR


/*Config the Prescaler:
 *		1- CLK_DISCONNECTED
 *	    2- DIVIDE_BY_1
 *      3- DIVIDE_BY_8
 *      4- DIVIDE_BY_64
 *      5- DIVIDE_BY_256
 *      6- DIVIDE_BY_1024
 *      7- EXT_CLK_FALLING_EDGE
 *      8- EXT_CLK_RISING_EDGE
 *
 *
 *
 */
#define TIMER_PRESCALER		DIVIDE_BY_64



#endif
