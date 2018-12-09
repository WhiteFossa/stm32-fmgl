/*
 * Level 2 HAL
 */

#ifndef L2HAL_INCLUDE_L2HAL_H_
#define L2HAL_INCLUDE_L2HAL_H_

#include "stm32f1xx_hal.h"

#include "l2hal_errors.h"

/* Defines */



/* Variables */

I2C_HandleTypeDef I2CHandle;


/**
 * Call it to setup hardware.
 */
void L2HAL_Init(void);

/**
 * Set up MCU clocks.
 */
void L2HAL_SetupClocks(void);

/**
 * Settig up I2C for display.
 */
void L2HAL_SetupI2C(void);

/**
 * I2C init.
 */
void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c);

/**
 * I2C shutdown.
 */
void HAL_I2C_MspDeInit(I2C_HandleTypeDef* hi2c);



#endif /* L2HAL_INCLUDE_L2HAL_H_ */
