/**
 * Fossa's MCU Graphic Library
 * GPLv3
 * https://github.com/WhiteFossa/stm32-fmgl
 */

#ifndef FMGL_INCLUDE_FMGL_H_
#define FMGL_INCLUDE_FMGL_H_

#include "stdint.h"
#include "bool_type.h"

/**
 * To avoid magic 8 in code.
 */
#define FMGL_BITS_PER_BYTE 8

/**
 * Structure, containing color.
 */
typedef struct
{
	/**
	 * Color components [0-1].
	 */
	float R;
	float G;
	float B;
} FMGL_ColorStruct;

/**
 * Structure with XBM image.
 */
typedef struct
{
	/**
	 * Image dimensions.
	 */
	uint16_t Width;
	uint16_t Height;

	/**
	 * Raster, packed as array of bytes.
	 */
	uint8_t* Raster;
} FMGL_XBMStruct;

/**
 * Device driver context. Library works with driver using this context.
 */
typedef struct
{
	/**
	 * Pointer to device context. Context have to be provided by driver.
	 */
	void* DeviceContext;

	/**
	 * Pointers to get device sizes functions.
	 */
	uint16_t (*GetWidth) (void);
	uint16_t (*GetHeight) (void);

	/**
	 * Pointer to function, setting device active color.
	 */
	void (*SetActiveColor) (void* deviceContext, FMGL_ColorStruct color);

	/**
	 * Pointer to function, drawing pixel with active color.
	 */
	void (*DrawPixel) (void* deviceContext, uint16_t x, uint16_t y);

	/**
	 * Pointer to function, getting pixel color.
	 */
	FMGL_ColorStruct (*GetPixel) (void* deviceContext, uint16_t x, uint16_t y);

	/**
	 * Pointer to function, pushing framebuffer into actual display.
	 */
	void (*PushFramebuffer) (void* deviceContext);

	/**
	 * Maximal possible coordinates. Minimal possible is (0,0).
	 */
	uint16_t MaxX;
	uint16_t MaxY;

	/**
	 * Active color.
	 */
	FMGL_ColorStruct ActiveColor;

} FMGL_DriverContext;


#endif /* FMGL_INCLUDE_FMGL_H_ */

/*****************************
 * API functions starts here *
 *****************************/

/*******************
 * Setup functions *
 *******************/

/**
 * Call this function to attach FMGL library to driver. Provide function with driver functions and data.
 */
FMGL_DriverContext FMGL_AttachToDriver
(
	void* deviceContext, /* Driver context, have to be provided by driver */
	uint16_t (*GetWidth) (void), /* This function returns display width */
	uint16_t (*GetHeight) (void), /* This function returns display height */
	void (*SetActiveColor) (void* deviceContext, FMGL_ColorStruct color), /* This function set active color */
	void (*DrawPixel) (void* deviceContext, uint16_t x, uint16_t y), /* This function draws pixel */
	FMGL_ColorStruct (*GetPixel) (void* deviceContext, uint16_t x, uint16_t y), /* This function returns pixel color */
	void (*PushFramebuffer) (void* deviceContext) /* This function pushes framebuffer to device */
);

/***************************
 * Basic drawing functions *
 ***************************/

/**
 * Returns display width and height.
 */
uint16_t FMGL_GetDisplayWidth(FMGL_DriverContext* context);
uint16_t FMGL_GetDisplayHeight(FMGL_DriverContext* context);

/**
 * Set active color.
 */
void FMGL_SetActiveColor(FMGL_DriverContext* context, FMGL_ColorStruct color);

/**
 * Returns current active color.
 */
FMGL_ColorStruct FMGL_GetActiveColor(FMGL_DriverContext* context);

/**
 * Draws pixel with given color.
 */
void FMGL_DrawPixel(FMGL_DriverContext* context, uint16_t x, uint16_t y);

/**
 * Returns given pixel color. If coordinates are incorrect return undefined color.
 */
FMGL_ColorStruct FMGL_GetPixel(FMGL_DriverContext* context, uint16_t x, uint16_t y);

/**
 * Pushes framebuffer to device.
 */
void FMGL_PushFramebuffer (FMGL_DriverContext* context);

/***************************
 * API functions ends here *
 ***************************/

/**
 * Returns true if pixel at given coordinates is active, false otherwise.
 * If coordinates are out of image, then result is undefined.
 */
bool FMGL_IsActiveXBMPixel(FMGL_XBMStruct* image, uint16_t x, uint16_t y);

