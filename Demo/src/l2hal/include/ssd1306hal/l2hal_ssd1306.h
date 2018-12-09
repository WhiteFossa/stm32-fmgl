/**
 * SSD1306 level 2 HAL driver.
 */

#ifndef L2HAL_INCLUDE_SSD1306HAL_L2HAL_SSD1306_H_
#define L2HAL_INCLUDE_SSD1306HAL_L2HAL_SSD1306_H_

#include "stm32f1xx_hal.h"
#include "bool_type.h"
#include "l2hal_errors.h"
#include "l2hal_ssd1306_commands.h"

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

/**
 * Structure, containing color.
 */
typedef struct
{
	/**
	 * Color components.
	 */
	uint8_t R;
	uint8_t G;
	uint8_t B;
} FMGL_ColorStruct;

/**************************************
 ****** API functions goes here *******
 **************************************/

/**
 * Call this function from I2C interrupt transfer completed handler, i.e. from void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c)
 * for correct I2C bus.
 */
void L2HAL_SSD1306_InterruptTransferCompleted(L2HAL_SSD1306_ContextStruct* context);

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
 * Set color, what will be used for drawing. If all R = G = B = 0, then pixel will be off, otherwise - on.
 */
void L2HAL_SSD1306_SetActiveColor(L2HAL_SSD1306_ContextStruct* context, FMGL_ColorStruct color);

/**
 * Draws pixel with active color. Do nothing if coordinates are incorrect. DOESN'T PUSH
 * FRAMEBUFFER.
 */
void L2HAL_SSD1306_DrawPixel(L2HAL_SSD1306_ContextStruct* context, uint16_t x, uint16_t y);

/**
 * Pushes framebuffer to display, if push already initiated waits for completion.
 */
void L2HAL_SSD1306_PushFramebuffer(L2HAL_SSD1306_ContextStruct* context);


/**************************************
 ****** API functions ends here *******
 **************************************/

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

#endif /* L2HAL_INCLUDE_SSD1306HAL_L2HAL_SSD1306_H_ */
