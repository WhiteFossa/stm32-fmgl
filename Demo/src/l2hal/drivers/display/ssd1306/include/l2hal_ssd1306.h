/**
 * SSD1306 level 2 HAL driver.
 */

#ifndef L2HAL_INCLUDE_SSD1306HAL_L2HAL_SSD1306_H_
#define L2HAL_INCLUDE_SSD1306HAL_L2HAL_SSD1306_H_

#include <stdint.h>
#include <stm32f1xx_hal.h>
#include <l2hal_aux.h>
#include <l2hal_ssd1306_commands.h>
#include <fmgl.h>

/* Display I/O timeout in milliseconds */
#define L2HAL_SSD1306_IO_TIMEOUT 100U

/* Display can have one of this two addresses. Addresses already shifted. */
#define L2HAL_SSD1306_POSSIBLE_ADDRESS1 0x78U
#define L2HAL_SSD1306_POSSIBLE_ADDRESS2 0x7AU

/**
 * Possible values of control byte (sent after device address).
 */
#define L2HAL_SSD1306_CONTROL_BYTE_COMMAND 0b00000000 /* Next byte is command */
#define L2HAL_SSD1306_CONTROL_BYTE_DATA 0b01000000 /* Next byte is data */

/**
 * Default brightness.
 */
#define L2HAL_SSD1306_DEFAULT_BRIGHTNESS 0xFF

/**
 * Display dimensions.
 */
#define L2HAL_SSD1306_DISPLAY_WIDTH 128
#define L2HAL_SSD1306_DISPLAY_HEIGHT 64

/**
 * Page (horizontal stripe) height.
 */
#define L2HAL_SSD1306_PAGE_HEIGHT 8

/**
 * Framebuffer size.
 */
#define L2HAL_SSD1306_FRAMEBUFFER_SIZE L2HAL_SSD1306_DISPLAY_WIDTH * L2HAL_SSD1306_DISPLAY_HEIGHT / 8

/**
 * Pixel states.
 */
#define L2HAL_SSD1306_PIXEL_OFF 0x00
#define L2HAL_SSD1306_PIXEL_ON 0xFF

/**
 * If L2HAL_SSD1306_GetBrightness() for giver color is higher or equal to this value,
 * then pixel will be lit.
 */
#define L2HAL_SSD1306_BRIGHTNESS_THRESHOLD 127U

/**
 * Factors for brightness calculation, normalized to 0xFF.
 * Br = 0.2126 * R + 0.7152 * G + 0.0722 * B
 */
#define L2HAL_SSD1306_BRIGHTNESS_DIV_FACTOR 255U
#define L2HAL_SSD1306_BRIGHTNESS_MUL_R_FACTOR 54U
#define L2HAL_SSD1306_BRIGHTNESS_MUL_G_FACTOR 182U
#define L2HAL_SSD1306_BRIGHTNESS_MUL_B_FACTOR 18U

/**
 * Maximal possible brightness.
 */
#define L2HAL_SSD1306_MAX_BRIGHTNESS FMGL_API_MAX_CHANNEL_BRIGHTNESS

/**
 * Return this color if pixel is lit.
 */
#define L2HAL_SSD1306_PIXEL_ON_R FMGL_API_MAX_CHANNEL_BRIGHTNESS
#define L2HAL_SSD1306_PIXEL_ON_G FMGL_API_MAX_CHANNEL_BRIGHTNESS
#define L2HAL_SSD1306_PIXEL_ON_B FMGL_API_MAX_CHANNEL_BRIGHTNESS

/**
 * Return this color if pixel is off.
 */
#define L2HAL_SSD1306_PIXEL_OFF_R 0
#define L2HAL_SSD1306_PIXEL_OFF_G 0
#define L2HAL_SSD1306_PIXEL_OFF_B 0

/**
 * Display context, I2C connection, device address etc are stored here.
 */
typedef struct
{
	/* True if display found on bus, false otherwise. */
	bool IsFound;

	/* Talk with display via this I2C instance. */
	I2C_HandleTypeDef* I2CHandle;

	/* Display bus address. */
	uint8_t BusAddress;

	/* True if transfer to display in progress. */
	bool IsTransferInProgress;

	/* Command code is stored here. !! DO NOT ACCESS IT DIRECTLY !! Use L2HAL_SSD1306_SetCommandBuffer() instead */
	uint8_t CommandBuffer;

	/* Framebuffer. !! CONTENT MUST NOT CHANGE DURING FRAMEBUFFER PUSH !! See
	 * void L2HAL_SSD1306_PushFramebuffer() for details.
	 */
	uint8_t Framebuffer[L2HAL_SSD1306_FRAMEBUFFER_SIZE];

	/* If true then framebuffer push in progress */
	bool IsFramebufferBeingPushed;

	/**
	 * Active color.
	 */
	uint8_t ActiveColor;

} L2HAL_SSD1306_ContextStruct;


/**************************************
 ****** API functions goes here *******
 **************************************/

/**
 * Attempts to detect display on bus. If detected, then IsFound and BussAddress will be set in context.
 */
void L2HAL_SSD1306_DetectDisplay(L2HAL_SSD1306_ContextStruct* context);

/**
 * Attempts to detect display on bus at given address. If detected, then IsFound and BussAddress will be set in context.
 */
void L2HAL_SSD1306_DetectDisplayAtAddress(L2HAL_SSD1306_ContextStruct* context, uint8_t address);

/**
 * Initializes display and turning it on. Doesn't affect framebuffer contents.
 */
void L2HAL_SSD1306_TurnDisplayOn(L2HAL_SSD1306_ContextStruct* context);

/* Turn display off (screen is off, Vcc step-up is off) */
void L2HAL_SSD1306_TurnDisplayOff(L2HAL_SSD1306_ContextStruct* context);

/**
 * Set brightness. 0x00 is minimal, 0xFF is maximal.
 */
void L2HAL_SSD1306_SetBrightness(L2HAL_SSD1306_ContextStruct* context, uint8_t brightness);

/**
 * Display dimensions (needed by graphics library)
 */
uint16_t L2HAL_SSD1306_GetWidth(void);
uint16_t L2HAL_SSD1306_GetHeight(void);

/**
 * Set color, what will be used for drawing.
 */
void L2HAL_SSD1306_SetActiveColor(L2HAL_SSD1306_ContextStruct* context, FMGL_API_ColorStruct color);

/**
 * Draws pixel with active color. Do nothing if coordinates are incorrect. DOESN'T PUSH
 * FRAMEBUFFER.
 */
void L2HAL_SSD1306_DrawPixel(L2HAL_SSD1306_ContextStruct* context, uint16_t x, uint16_t y);

/**
 * Get color of pixel with given coordinates. Return off pixel color if coordinates are incorrect.
 */
FMGL_API_ColorStruct L2HAL_SSD1306_GetPixel(L2HAL_SSD1306_ContextStruct* context, uint16_t x, uint16_t y);

/**
 * Pushes framebuffer to display, if push already initiated waits for completion.
 */
void L2HAL_SSD1306_PushFramebuffer(L2HAL_SSD1306_ContextStruct* context);


/**************************************
 ****** API functions ends here *******
 **************************************/

/**
 * Call this function from I2C interrupt transfer completed handler, i.e. from void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c)
 * for correct I2C bus.
 */
void L2HAL_SSD1306_InterruptTransferCompleted(L2HAL_SSD1306_ContextStruct* context);

/**
 * Waits in loop (polling) for context->IsTransferInProgress == false.
 */
void L2HAL_SSD1306_WaitForTransferCompletion(L2HAL_SSD1306_ContextStruct* context);

/**
 * Stores command in command buffer (within context), waiting for transfer completion if needed.
 */
void L2HAL_SSD1306_SetCommandBuffer(L2HAL_SSD1306_ContextStruct* context, uint8_t command);

/**
 * Send command to display.
 */
void L2HAL_SSD1306_WriteCommand(L2HAL_SSD1306_ContextStruct* context, uint8_t command);

/**
 * Send data to videomemory.
 */
void L2HAL_SSD1306_WriteData(L2HAL_SSD1306_ContextStruct* context, uint8_t* data, uint16_t length);

/**
 * If called when display is not found - causes HAL error.
 */
void L2HAL_SSD1306_CheckIfFound(L2HAL_SSD1306_ContextStruct* context);

/**
 * Getting x and y position, checks it against display size. If incorrect returns false.
 * If correct - putting framebuffer array index into index and bit mask (all bits is 0 except one, pointing to requested
 * pixel) for pixel in byte.
 */
bool L2HAL_SSD1306_GetFramebufferAddress(uint16_t x, uint16_t y, uint16_t* index, uint8_t* mask);

/**
 * Returns brightness [0-L2HAL_SSD1306_MAX_BRIGHTNESS] for given color.
 */
uint16_t L2HAL_SSD1306_GetBrightness(FMGL_API_ColorStruct color);

#endif /* L2HAL_INCLUDE_SSD1306HAL_L2HAL_SSD1306_H_ */
