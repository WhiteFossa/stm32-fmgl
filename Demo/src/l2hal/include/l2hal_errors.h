/**
 * @file
 * @brief Errors handling stuff for level 2 HAL.
 */

#ifndef L2HAL_INCLUDE_L2HAL_ERRORS_H_
#define L2HAL_INCLUDE_L2HAL_ERRORS_H_

#include <stm32f1xx_hal.h>
#include <stm32f1xx_hal_rcc.h>

/**
 * Clock this port on error.
 */
#define L2HAL_ERROR_CLOCK_SIGNAL_PORT() __HAL_RCC_GPIOC_CLK_ENABLE()

/**
 * In case of error pin at this port will be changed.
 */
#define L2HAL_ERROR_SIGNAL_PORT GPIOC

/**
 * Change this pin on error.
 */
#define L2HAL_ERROR_SIGNAL_PIN GPIO_PIN_13

/**
 * Do this with L2HAL_ERROR_SIGNAL_PIN of L2HAL_ERROR_SIGNAL_PORT on error.
 */
#define L2HAL_ERROR_SIGNAL_PIN_STATE GPIO_PIN_RESET


/**
 * Possible error codes. 0-32767 is for stock codes, 32768-65535 is for user-defined ones.
 */
typedef enum
{
	/**
	 * No error.
	 */
	OK = 0,

	/**
	 * Generic error.
	 */
	Generic = 1,

	/**
	 * Function was called with wrong arguments
	 */
	WrongArgument = 2
} L2HAL_ErrorCode;


/**
 * Call it if error happened.
 * @param code Error code.
 */
void L2HAL_Error(L2HAL_ErrorCode code);

#endif /* L2HAL_INCLUDE_L2HAL_ERRORS_H_ */
