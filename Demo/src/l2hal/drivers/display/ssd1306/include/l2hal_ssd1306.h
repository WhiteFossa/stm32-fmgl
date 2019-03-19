/**
 * @file
 * @brief SSD1306 level 2 HAL driver.
 */

#ifndef L2HAL_INCLUDE_SSD1306HAL_L2HAL_SSD1306_H_
#define L2HAL_INCLUDE_SSD1306HAL_L2HAL_SSD1306_H_

#include <stdint.h>
#include <stm32f1xx_hal.h>
#include <l2hal_aux.h>
#include <l2hal_ssd1306_commands.h>
#include <fmgl.h>

/**
 * Display dimensions.
 */
#define L2HAL_SSD1306_DISPLAY_WIDTH 128
#define L2HAL_SSD1306_DISPLAY_HEIGHT 64

/**
 * Framebuffer size.
 */
#define L2HAL_SSD1306_FRAMEBUFFER_SIZE L2HAL_SSD1306_DISPLAY_WIDTH * L2HAL_SSD1306_DISPLAY_HEIGHT / 8

/**
 * Display context, I2C connection, device address etc are stored here.
 */
typedef struct
{
	/**
	 * True if display found on bus, false otherwise.
	 */
	bool IsFound;

	/**
	 * Talk with display via this I2C instance.
	 */
	I2C_HandleTypeDef* I2CHandle;

	/**
	 * Display bus address.
	 */
	uint8_t BusAddress;

	/**
	 * Command code is stored here during time of command transfer. !! DO NOT CHANGE DURING DATA TRANSFER !!
	 */
	uint8_t CommandCode;

	/** Framebuffer. !! CONTENT MUST NOT BE CHANGED DURING DATA TRANSFER !! See
	 * void L2HAL_SSD1306_PushFramebuffer() for details.
	 */
	uint8_t Framebuffer[L2HAL_SSD1306_FRAMEBUFFER_SIZE];

	/**
	 * If true then data transfer in progress.
	 * Have to be volatile, because changed in interrupt handler.
	 */
	volatile bool IsDataTransferInProgress;

	/**
	 * Active color.
	 */
	uint8_t ActiveColor;

} L2HAL_SSD1306_ContextStruct;


/**
 * Attempts to detect display on bus. If detected, then IsFound and BussAddress will be set in context.
 * @param context Pointer to driver context.
 */
void L2HAL_SSD1306_DetectDisplay(L2HAL_SSD1306_ContextStruct* context);

/**
 * Attempts to detect display on bus at given address. If detected, then IsFound and BussAddress will be set in context.
 * @param context Pointer to driver context.
 * @param address Attempt to detect display at given address.
 */
void L2HAL_SSD1306_DetectDisplayAtAddress(L2HAL_SSD1306_ContextStruct* context, uint8_t address);

/**
 * Initializes display and turning it on. Doesn't affect framebuffer contents.
 * @param context Pointer to driver context.
 */
void L2HAL_SSD1306_TurnDisplayOn(L2HAL_SSD1306_ContextStruct* context);

/**
 * Turn display off (screen is off, Vcc step-up is off).
 * @param context Pointer to driver context.
 */
void L2HAL_SSD1306_TurnDisplayOff(L2HAL_SSD1306_ContextStruct* context);

/**
 * Set brightness. 0x00 is minimal, 0xFF is maximal.
 * @param context Pointer to driver context.
 * @param brightness Brightness level.
 */
void L2HAL_SSD1306_SetBrightness(L2HAL_SSD1306_ContextStruct* context, uint8_t brightness);

/**
 * Returns display width.
 * @return Display width.
 */
uint16_t L2HAL_SSD1306_GetWidth(void);

/**
 * Returns display height.
 * @return Display height.
 */
uint16_t L2HAL_SSD1306_GetHeight(void);

/**
 * Set color what will be used for drawing.
 * @param context Pointer to driver context.
 * @param color Set this color as active.
 */
void L2HAL_SSD1306_SetActiveColor(L2HAL_SSD1306_ContextStruct* context, FMGL_API_ColorStruct color);

/**
 * Draws pixel with active color. Do nothing if coordinates are incorrect. DOESN'T PUSH
 * FRAMEBUFFER.
 *
 * Function will wait if data transfer is ongoing, because framebuffer can't be changed this time.
 * @param context Pointer to driver context.
 * @param x Pixel X coordinate.
 * @param y Pixel Y coordinate.
 */
void L2HAL_SSD1306_DrawPixel(L2HAL_SSD1306_ContextStruct* context, uint16_t x, uint16_t y);

/**
 * Get color of pixel with given coordinates. Return off pixel color if coordinates are incorrect.
 * @param context Pointer to driver context.
 * @param x Pixel X coordinate.
 * @param y Pixel Y coordinate.
 * @return Color of given pixel or off pixel color if coordinates are incorrect.
 */
FMGL_API_ColorStruct L2HAL_SSD1306_GetPixel(L2HAL_SSD1306_ContextStruct* context, uint16_t x, uint16_t y);

/**
 * Pushes framebuffer to display, if push already initiated waits for completion.
 * @param context Pointer to driver context.
 */
void L2HAL_SSD1306_PushFramebuffer(L2HAL_SSD1306_ContextStruct* context);


#endif /* L2HAL_INCLUDE_SSD1306HAL_L2HAL_SSD1306_H_ */
