/**
 * Fossa's MCU Graphic Library
 * GPLv3
 * https://github.com/WhiteFossa/stm32-fmgl
 */

#ifndef FMGL_INCLUDE_FMGL_H_
#define FMGL_INCLUDE_FMGL_H_

#include <stdint.h>
#include <string.h>
#include <l2hal_aux.h>
#include <l2hal_errors.h>

/**
 * Each font defines 256 characters (including null-character for 0x00)
 */
#define FMGL_API_FONT_CHARACTERS_COUNT 256

/**
 * Possible transparency rendering modes for XBM images.
 */
typedef enum
{
	FMGL_XBMTransparencyModeNormal = 0, /* Image will be rendered as is */
	FMGL_XBMTransparencyModeTransparentInactive = 1, /* Inactive pixels will be transparent */
	FMGL_XBMTransparencyModeTransparentActive = 2 /* Active pixels will be transparent */
} FMGL_API_XBMTransparencyMode;

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
} FMGL_API_ColorStruct;

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
} FMGL_API_XBMImage;

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
	void (*SetActiveColor) (void* deviceContext, FMGL_API_ColorStruct color);

	/**
	 * Pointer to function, drawing pixel with active color.
	 */
	void (*DrawPixel) (void* deviceContext, uint16_t x, uint16_t y);

	/**
	 * Pointer to function, getting pixel color.
	 */
	FMGL_API_ColorStruct (*GetPixel) (void* deviceContext, uint16_t x, uint16_t y);

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
	FMGL_API_ColorStruct ActiveColor;

} FMGL_API_DriverContext;


/***************************
 * Font-related structures *
 ***************************/

/**
 * Font.
 */
typedef struct
{
	/* Character height. */
	uint8_t Height;

	/* Array of pointers to character rasters (XBM images) */
	uint8_t* Characters[FMGL_API_FONT_CHARACTERS_COUNT];

	/* Pointer to function, returning character width. */
	uint16_t (*GetCharacterWidth) (uint8_t character);
} FMGL_API_Font;

/**
 * Font settings for drawing
 */
typedef struct
{
	/* Font to use */
	FMGL_API_Font* Font;

	/* Font scale */
	uint16_t Scale;

	/* Add this width between characters (scaled by Scale) */
	uint16_t CharactersSpacing;

	/* Add this height between lines (scaled by Scale) */
	uint16_t LinesSpacing;

	/* Font pixels color */
	FMGL_API_ColorStruct* FontColor;

	/* Font background color */
	FMGL_API_ColorStruct* BackgroundColor;

	/* Font transparency */
	FMGL_API_XBMTransparencyMode* Transparency;

} FMGL_API_FontSettings;


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
FMGL_API_DriverContext FMGL_API_AttachToDriver
(
	void* deviceContext, /* Driver context, have to be provided by driver */
	uint16_t (*GetWidth) (void), /* This function returns display width */
	uint16_t (*GetHeight) (void), /* This function returns display height */
	void (*SetActiveColor) (void* deviceContext, FMGL_API_ColorStruct color), /* This function set active color */
	void (*DrawPixel) (void* deviceContext, uint16_t x, uint16_t y), /* This function draws pixel */
	FMGL_API_ColorStruct (*GetPixel) (void* deviceContext, uint16_t x, uint16_t y), /* This function returns pixel color */
	void (*PushFramebuffer) (void* deviceContext) /* This function pushes framebuffer to device */
);

/***************************
 * Basic drawing functions *
 ***************************/

/**
 * Returns display width and height.
 */
uint16_t FMGL_API_GetDisplayWidth(FMGL_API_DriverContext* context);
uint16_t FMGL_API_GetDisplayHeight(FMGL_API_DriverContext* context);

/**
 * Set active color.
 */
void FMGL_API_SetActiveColor(FMGL_API_DriverContext* context, FMGL_API_ColorStruct color);

/**
 * Returns current active color.
 */
FMGL_API_ColorStruct FMGL_API_GetActiveColor(FMGL_API_DriverContext* context);

/**
 * Draws pixel with given color.
 */
void FMGL_API_DrawPixel(FMGL_API_DriverContext* context, uint16_t x, uint16_t y);

/**
 * Returns given pixel color. If coordinates are incorrect return undefined color.
 */
FMGL_API_ColorStruct FMGL_API_GetPixel(FMGL_API_DriverContext* context, uint16_t x, uint16_t y);

/**
 * Pushes framebuffer to device.
 */
void FMGL_API_PushFramebuffer (FMGL_API_DriverContext* context);


/*********
 * Lines *
 *********/

/**
 * Draws horizontal line.
 */
void FMGL_API_DrawLineHorizontal(FMGL_API_DriverContext* context, uint16_t x1, uint16_t x2, uint16_t y);

/**
 * Draws vertical line.
 */
void FMGL_API_DrawLineVertical(FMGL_API_DriverContext* context, uint16_t x, uint16_t y1, uint16_t y2);


/**************
 * Rectangles *
 **************/

/**
 * Draws rectangle without filling it.
 */
void FMGL_API_DrawRectangle(FMGL_API_DriverContext* context, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

/**
 * Draws filled rectangle. Active color didn't change after this function call.
 */
void FMGL_API_DrawRectangleFilled(FMGL_API_DriverContext* context, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, FMGL_API_ColorStruct borderColor, FMGL_API_ColorStruct fillColor);


/***************************
 * XBM rendering functions *
 ***************************/

/**
 * Renders XBM image such way, that (0,0) pixel of image will be placed at (x,y). Image is being
 * scaled up by scaleX and scaleY. XBM's active pixels will be displayed using activeColor, inactive - using inactiveColor.
 */
void FMGL_API_RenderXBM(FMGL_API_DriverContext* context, FMGL_API_XBMImage* image, uint16_t x, uint16_t y, uint16_t scaleX, uint16_t scaleY,
		FMGL_API_ColorStruct activeColor, FMGL_API_ColorStruct inactiveColor, FMGL_API_XBMTransparencyMode transparency);


/*******************************
 * Strings rendering functions *
 *******************************/

/**
 * Draws one line without wrapping at spaces. Newlines aren't allowed, in case of newline L2HAL_Error(L2HAL_ERROR_WRONG_ARGUMENT) will be called.
 * Draws until line end or until no pixels of next character falls into screen area. Returns (in width parameter) width of drawn line.
 */
void FMGL_API_RenderOneLineDumb(FMGL_API_DriverContext* context, FMGL_API_FontSettings* fontSettings, uint16_t x, uint16_t y, uint16_t* width, char* string);

/**
 * Renders text without wrapping at spaces, but with wrapping at newlines.
 * @param context Pointer to FMGL library context.
 * @param fontSettings Pointer to font settings.
 * @param x,y Top left text coordinates.
 * @param string Text to render.
 * @param width,height Output parameters, rendered text sizes.
 */
void FMGL_API_RenderTextWithLineBreaks(FMGL_API_DriverContext* context, FMGL_API_FontSettings* fontSettings, uint16_t x, uint16_t y, uint16_t* width, uint16_t* height,
		char* string);

/**
 * Calculates given string width (in pixels). Spaces are treated as usual characters (no carry), newlines aren't allowed (L2HAL_Error(L2HAL_ERROR_WRONG_ARGUMENT) will be called).
 */
uint16_t FMGL_API_CalculateOneLineWidth(FMGL_API_FontSettings* fontSettings, char* string);

/***************************
 * API functions ends here *
 ***************************/


#endif /* FMGL_INCLUDE_FMGL_H_ */
