#include "l2hal.h"

void L2HAL_Init(void)
{
	/* Setting up clocks */
	L2HAL_SetupClocks();

	/* Preparing I2C */
	L2HAL_SetupI2C();
}

void L2HAL_SetupClocks(void)
{
	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitTypeDef oscinitstruct = {0};
	oscinitstruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	oscinitstruct.HSEState = RCC_HSE_ON;
	oscinitstruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
	oscinitstruct.PLL.PLLState = RCC_PLL_ON;
	oscinitstruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	oscinitstruct.PLL.PLLMUL = RCC_PLL_MUL9;
	if (HAL_RCC_OscConfig(&oscinitstruct)!= HAL_OK)
	{
		/* Initialization Error */
		L2HAL_Error(L2HAL_ERROR_GENERIC);
	}

	/* Select PLL as system clock source and configure the HCLK (AHB), PCLK1 (APB1), PCLK2 (APB2) clocks */
	RCC_ClkInitTypeDef clkinitstruct = {0};
	clkinitstruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	clkinitstruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK; /* 72 MHz */
	clkinitstruct.AHBCLKDivider = RCC_SYSCLK_DIV1; /* AHB at 72 MHz*/
	clkinitstruct.APB1CLKDivider = RCC_HCLK_DIV2; /* APB1 at 36 MHz*/
	clkinitstruct.APB2CLKDivider = RCC_HCLK_DIV1; /* APB2 at 72 MHz */

	if (HAL_RCC_ClockConfig(&clkinitstruct, FLASH_LATENCY_2)!= HAL_OK)
	{
		/* Initialization Error */
		L2HAL_Error(L2HAL_ERROR_GENERIC);
	}
}

void L2HAL_SetupI2C(void)
{
	/* Clocking I2C */
	__HAL_RCC_I2C1_CLK_ENABLE();

	/**
	 * Setting up I2C
	 */

	I2CHandle.Instance = I2C1;
	I2CHandle.Init.ClockSpeed = 400000; /* 400 KHz */
	I2CHandle.Init.DutyCycle = I2C_DUTYCYCLE_2;
	I2CHandle.Init.OwnAddress1 = 0x00;
	I2CHandle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	I2CHandle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	I2CHandle.Init.OwnAddress2 = 0x00;
	I2CHandle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	I2CHandle.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

	if(HAL_I2C_Init(&I2CHandle) != HAL_OK)
	{
		/* Initialization Error */
		L2HAL_Error(L2HAL_ERROR_GENERIC);
	}
}

void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c)
{
	if (hi2c->Instance == I2C1)
	{
		/**
		 * Setting up port
		 * I2C1 at PB6 (SCL) and PB7 (SDA)
		 */

		/* Clocking port */
		__HAL_RCC_GPIOB_CLK_ENABLE();

		GPIO_InitTypeDef GPIO_InitStruct;

		GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	}
}

void HAL_I2C_MspDeInit(I2C_HandleTypeDef* hi2c)
{
	if (hi2c->Instance == I2C1)
	{
		__HAL_RCC_I2C1_CLK_DISABLE();
		HAL_GPIO_DeInit(GPIOB, GPIO_PIN_6 | GPIO_PIN_7);
	}
}
