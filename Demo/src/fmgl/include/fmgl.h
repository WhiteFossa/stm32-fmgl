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
 * Macroses for minimal and maximal values.
 */
#define FMGL_MIN(x, y) (((x) < (y)) ? (x) : (y))
#define FMGL_MAX(x, y) (((x) > (y)) ? (x) : (y))

/**
 * To avoid magic 8 in code.
 */
#define FMGL_BITS_PER_BYTE 8

/**
 * For internal use in FMGL_RenderXBM
 */
#define FMGL_XBM_ACTIVE_COLOR_INDEX 0
#define FMGL_XBM_INACTIVE_COLOR_INDEX 1
#define FMGL_XBM_COLORS_NUMBER 2

/**
 * Possible transparency rendering modes for XBM images.
 */
typedef enum
{
	FMGL_XBMTransparencyModeNormal = 0, /* Image will be rendered as is */
	FMGL_XBMTransparencyModeTransparentInactive = 1, /* Inactive pixels will be transparent */
	FMGL_XBMTransparencyModeTransparentActive = 2 /* Active pixels will be transparent */
} FMGL_XBMTransparencyMode;

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
} FMGL_XBMImage;

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


/***************************
 * Font-related structures *
 ***************************/

/* Each font defines 256 characters (including null-character for 0x00) */
#define FMGL_FONT_CHARACTERS_COUNT 256

/**
 * Font character.
 */
typedef struct
{
	/* Character width (height is defined in font) */
	uint8_t Width;

	/* Character raster (actually XBM image) */
	uint8_t* Raster;
} FMGL_FontCharacter;


/**
 * Font.
 */
typedef struct
{
	/* Character height. */
	uint8_t Height;

	/* Array of pointers to actual characters */
	FMGL_FontCharacter* Characters[FMGL_FONT_CHARACTERS_COUNT];
} FMGL_Font;

/**
 * Font settings for drawing
 */
typedef struct
{
	/* Font to use */
	FMGL_Font* Font;

	/* Font scale */
	uint16_t Scale;

	/* Font pixels color */
	FMGL_ColorStruct* FontColor;

	/* Font background color */
	FMGL_ColorStruct* BackgroundColor;

	/* Font transparency */
	FMGL_XBMTransparencyMode* Transparency;

} FMGL_FontSettings;


/**********************************
 * End of font-related structures *
 **********************************/


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


/*********
 * Lines *
 *********/

/**
 * Draws horizontal line.
 */
void FMGL_DrawLineHorizontal(FMGL_DriverContext* context, uint16_t x1, uint16_t x2, uint16_t y);

/**
 * Draws vertical line.
 */
void FMGL_DrawLineVertical(FMGL_DriverContext* context, uint16_t x, uint16_t y1, uint16_t y2);


/**************
 * Rectangles *
 **************/

/**
 * Draws rectangle without filling it.
 */
void FMGL_DrawRectangle(FMGL_DriverContext* context, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

/**
 * Draws filled rectangle. Active color didn't change after this function call.
 */
void FMGL_DrawRectangleFilled(FMGL_DriverContext* context, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, FMGL_ColorStruct borderColor, FMGL_ColorStruct fillColor);


/***************************
 * XBM rendering functions *
 ***************************/

/**
 * Renders XBM image such way, that (0,0) pixel of image will be placed at (x,y). Image is being
 * scaled up by scaleX and scaleY. XBM's active pixels will be displayed using activeColor, inactive - using inactiveColor.
 */
void FMGL_RenderXBM(FMGL_DriverContext* context, FMGL_XBMImage* image, uint16_t x, uint16_t y, uint16_t scaleX, uint16_t scaleY,
		FMGL_ColorStruct activeColor, FMGL_ColorStruct inactiveColor, FMGL_XBMTransparencyMode transparency);


/***************************
 * API functions ends here *
 ***************************/

/**
 * Returns true if pixel at given coordinates is active, false otherwise.
 * If coordinates are out of image, then result is undefined.
 */
bool FMGL_IsActiveXBMPixel(FMGL_XBMImage* image, uint16_t x, uint16_t y);

/**
 * Draws one character at given position.
 */
void FMGL_RenderCharacter(FMGL_DriverContext* context, FMGL_FontSettings* fontSettings, uint16_t x, uint16_t y, uint8_t character);

#endif /* FMGL_INCLUDE_FMGL_H_ */
