/**
 * @file
 * @brief Level 2 HAL main file.
 */

/**
 * How to use level 2 HAL.
 *
 * 1) Put your custom hardware-initialization code into l2hal_custom, call functions, setting up hardware from L2HAL_InitCustomHardware()
 *
 * 2) Call L2HAL_Init() from your code before any L2HAL functions use.
 *
 */

#ifndef L2HAL_INCLUDE_L2HAL_H_
#define L2HAL_INCLUDE_L2HAL_H_

#include <stm32f1xx_hal.h>
#include <l2hal_errors.h>
#include <l2hal_custom.h>


/**
 * Call it to setup hardware.
 */
void L2HAL_Init(void);

/**
 * Set up MCU clocks. Being called from L2HAL_Init() automatically.
 */
void L2HAL_SetupClocks(void);

#endif /* L2HAL_INCLUDE_L2HAL_H_ */
