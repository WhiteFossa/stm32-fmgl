/*
 * Errors handling for level 2 HAL.
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
 * No error.
 */
#define L2HAL_ERROR_OK 0

/**
 * Generic error.
 */
#define L2HAL_ERROR_GENERIC 1

/**
 * Function get wrong argument.
 */
#define L2HAL_ERROR_WRONG_ARGUMENT 2


/**
 * Call it if error happened.
 * @param code Error code.
 */
void L2HAL_Error(int16_t code);

#endif /* L2HAL_INCLUDE_L2HAL_ERRORS_H_ */
