/**
 * @file
 * @biref File for custom hardware-related stuff.
 */

#ifndef L2HAL_INCLUDE_L2HAL_CUSTOM_H_
#define L2HAL_INCLUDE_L2HAL_CUSTOM_H_

#include <l2hal_ssd1306.h>

/**
 * I2C1 interrupt priorities.
 */
#define I2C1_ER_IRQN_PRIORITY 0
#define I2C1_ER_IRQN_SUBPRIORITY 1

#define I2C1_EV_IRQN_PRIORITY 0
#define I2C1_EV_IRQN_SUBPRIORITY 2

/**
 * I2C bus handle.
 */
I2C_HandleTypeDef I2CHandle;

/**
 * Display driver context.
 */
L2HAL_SSD1306_ContextStruct L2HAL_SSD1306_Context;

/**
 * Put custom hardware initialization stuff here,
 */
void L2HAL_InitCustomHardware(void);

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

/**
 * I2C interrput handlers.
 */
void I2C1_EV_IRQHandler(void);
void I2C1_ER_IRQHandler(void);
void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c);


#endif /* L2HAL_INCLUDE_L2HAL_CUSTOM_H_ */
