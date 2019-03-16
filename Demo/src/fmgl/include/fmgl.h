/**
 * @file
 * @brief Fossa's MCU Graphics Library main file.
 *
 * GPLv3
 * https://github.com/WhiteFossa/stm32-fmgl
 */


#ifndef FMGL_INCLUDE_FMGL_H_
#define FMGL_INCLUDE_FMGL_H_

#include <stdint.h>
#include <string.h>
#include <l2hal_aux.h>
#include <l2hal_errors.h>

/*
 * Each font defines 256 characters (including null-character for 0x00).
 */
#define FMGL_API_FONT_CHARACTERS_COUNT 256U

/**
 * Maximal brightness for each color channel.
 */
#define FMGL_API_MAX_CHANNEL_BRIGHTNESS 255U

/**
 * Possible transparency rendering modes for XBM images.
 */
typedef enum
{
	FMGL_XBMTransparencyModeNormal = 0, /** Image will be rendered as is. */
	FMGL_XBMTransparencyModeTransparentInactive = 1, /** Inactive pixels will be transparent. */
	FMGL_XBMTransparencyModeTransparentActive = 2 /** Active pixels will be transparent. */
} FMGL_API_XBMTransparencyMode;

/**
 * Structure, containing color.
 */
typedef struct
{
	/**
	 * Red component, [0-FMGL_API_MAX_CHANNEL_BRIGHTNESS].
	 */
	uint8_t R;

	/**
	 * Green component, [0-FMGL_API_MAX_CHANNEL_BRIGHTNESS].
	 */
	uint8_t G;

	/**
	 * Blue component, [0-FMGL_API_MAX_CHANNEL_BRIGHTNESS].
	 */
	uint8_t B;
} FMGL_API_ColorStruct;

/**
 * Structure with XBM image.
 */
typedef struct
{
	/**
	 * Image width.
	 */
	uint16_t Width;

	/**
	 * Image height.
	 */
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
	 * Pointer to function returning device display width.
	 */
	uint16_t (*GetWidth) (void);


	/**
	 * Pointer to function returning device display height.
	 */
	uint16_t (*GetHeight) (void);

	/**
	 * Pointer to function setting device active color.
	 */
	void (*SetActiveColor) (void* deviceContext, FMGL_API_ColorStruct color);

	/**
	 * Pointer to function drawing pixel with active color.
	 */
	void (*DrawPixel) (void* deviceContext, uint16_t x, uint16_t y);

	/**
	 * Pointer to function getting pixel color.
	 */
	FMGL_API_ColorStruct (*GetPixel) (void* deviceContext, uint16_t x, uint16_t y);

	/**
	 * Pointer to function pushing framebuffer into actual display.
	 */
	void (*PushFramebuffer) (void* deviceContext);

	/**
	 * Maximal possible X coordinate (rightest).
	 */
	uint16_t MaxX;

	/**
	 * Maximal possible Y coordinate (bottomest).
	 */
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
 * Font-defining structure.
 */
typedef struct
{
	/**
	 * Character height.
	 */
	uint8_t Height;

	/**
	 * Pointer to function returning character width.
	 */
	uint16_t (*GetCharacterWidth) (uint8_t character);

	/**
	 *Pointer to function, returning character raster.
	 */
	const uint8_t* (*GetCharacterRaster) (uint8_t character);
} FMGL_API_Font;

/**
 * Font settings for drawing.
 */
typedef struct
{
	/**
	 * Font to use.
	 */
	FMGL_API_Font* Font;

	/**
	 * Font scale.
	 */
	uint16_t Scale;

	/**
	 * Add this width between characters (scaled by Scale).
	 */
	uint16_t CharactersSpacing;

	/**
	 * Add this height between lines (scaled by Scale).
	 */
	uint16_t LinesSpacing;

	/**
	 * Font pixels color.
	 */
	FMGL_API_ColorStruct* FontColor;

	/**
	 * Font background color.
	 */
	FMGL_API_ColorStruct* BackgroundColor;

	/**
	 * Font transparency.
	 */
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
 * Call this function to attach FMGL library to driver. Provide function with driver functions pointers and data.
 * @param deviceContext Device context, have to be provided by driver.
 * @param getWidth Pointer to function returning display width.
 * @param getHeight Pointer to function returning display height.
 * @param setActiveColor Pointer to function setting active color.
 * @param drawPixel Pointer to function drawing pixels.
 * @param getPixel Pointer to function returning pixels color.
 * @param pushFramebuffer Pointer to function pushing framebuffer to device.
 */
FMGL_API_DriverContext FMGL_API_AttachToDriver
(
	void* deviceContext,
	uint16_t (*getWidth) (void),
	uint16_t (*getHeight) (void),
	void (*setActiveColor) (void* deviceContext, FMGL_API_ColorStruct color),
	void (*drawPixel) (void* deviceContext, uint16_t x, uint16_t y),
	FMGL_API_ColorStruct (*getPixel) (void* deviceContext, uint16_t x, uint16_t y),
	void (*pushFramebuffer) (void* deviceContext)
);

/***************************
 * Basic drawing functions *
 ***************************/

/**
 * Returns display width.
 * @param context Driver context.
 */
uint16_t FMGL_API_GetDisplayWidth(FMGL_API_DriverContext* context);

/**
 * Returns display height.

 */
uint16_t FMGL_API_GetDisplayHeight(FMGL_API_DriverContext* context);

/**
 * Sets active color.
 * @param context Driver context.
 * @param color New active color.
 */
void FMGL_API_SetActiveColor(FMGL_API_DriverContext* context, FMGL_API_ColorStruct color);

/**
 * Returns current active color.
 * @param context Driver context.
 */
FMGL_API_ColorStruct FMGL_API_GetActiveColor(FMGL_API_DriverContext* context);

/**
 * Draws pixel with current active color.
 * @param context Driver context.
 * @param x X pixel coordinate.
 * @param y Y pixel coordinate.
 */
void FMGL_API_DrawPixel(FMGL_API_DriverContext* context, uint16_t x, uint16_t y);

/**
 * Returns pixel color. If coordinates are incorrect return undefined color.
 * @param context Driver context.
 * @param x X pixel coordinate.
 * @param y Y pixel coordinate.
 */
FMGL_API_ColorStruct FMGL_API_GetPixel(FMGL_API_DriverContext* context, uint16_t x, uint16_t y);

/**
 * Pushes framebuffer to device.
 * @param context Driver context.
 */
void FMGL_API_PushFramebuffer (FMGL_API_DriverContext* context);


/*********
 * Lines *
 *********/

/**
 * Draws horizontal line.
 * @param context Driver context.
 * @param x1 Line one end X coordinate.
 * @param x2 Line another end X coordinate.
 * @param y Line Y coordinate.
 */
void FMGL_API_DrawLineHorizontal(FMGL_API_DriverContext* context, uint16_t x1, uint16_t x2, uint16_t y);

/**
 * Draws vertical line.
 * @param context Driver context.
 * @param x Line X coordinate.
 * @param y1 Line one end Y coordinate.
 * @param y2 Line another end Y coordinate.
 */
void FMGL_API_DrawLineVertical(FMGL_API_DriverContext* context, uint16_t x, uint16_t y1, uint16_t y2);


/**************
 * Rectangles *
 **************/

/**
 * Draws rectangle without filling it.
 * @param context Driver context.
 * @param x1 One corner X coordinate.
 * @param y1 One corner Y coordinate.
 * @param x2 Opposite corner X coordinate.
 * @param y2 Opposite corner X coordinate.
 */
void FMGL_API_DrawRectangle(FMGL_API_DriverContext* context, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

/**
 * Draws filled rectangle. Active color didn't change after this function call.
 * @param context Driver context.
 * @param x1 One corner X coordinate.
 * @param y1 One corner Y coordinate.
 * @param x2 Opposite corner X coordinate.
 * @param y2 Opposite corner X coordinate.
 * @param borderColor Border color.
 * @param fillColor Fill color.
 */
void FMGL_API_DrawRectangleFilled(FMGL_API_DriverContext* context, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, FMGL_API_ColorStruct borderColor, FMGL_API_ColorStruct fillColor);


/***************************
 * XBM rendering functions *
 ***************************/

/**
 * Renders XBM image such way, that (0,0) pixel of image will be placed at (x,y). Image is being
 * scaled up by scaleX and scaleY. XBM's active pixels will be displayed using activeColor, inactive - using inactiveColor.
 * @param context Driver context.
 * @param image Pointer to XBM image struct.
 * @param x X coordinate of top left image corner.
 * @param y Y coordinate of top left image corner.
 * @param scaleX Scale image in horizontal direction by this factor.
 * @param scaleY Scale image in vertical diraction by this factor.
 * @param activeColor Draw image active pixels with this color.
 * @param inactiveColor Draw image inactive pixels with this color.
 * @param transparency Transparency mode.
 */
void FMGL_API_RenderXBM(FMGL_API_DriverContext* context, FMGL_API_XBMImage* image, uint16_t x, uint16_t y, uint16_t scaleX, uint16_t scaleY,
		FMGL_API_ColorStruct activeColor, FMGL_API_ColorStruct inactiveColor, FMGL_API_XBMTransparencyMode transparency);


/*******************************
 * Strings rendering functions *
 *******************************/

/**
 * Draws one line without wrapping at spaces. Newlines aren't allowed, in case of newline L2HAL_Error(L2HAL_ERROR_WRONG_ARGUMENT) will be called.
 * Draws until line end or until no pixels of next character falls into screen area. Returns (in width parameter) width of drawn line.
 * @param context Pointer to FMGL library context.
 * @param fontSettings Pointer to font settings.
 * @param x,y Top left text coordinates.
 * @param width Pointer to variable, where rendered text width will be stored.
 * @param isDryRun If true, then doesn't draw anything, just calculating width.
 * @param string Text to render.
 */
void FMGL_API_RenderOneLineDumb(FMGL_API_DriverContext* context, FMGL_API_FontSettings* fontSettings, uint16_t x, uint16_t y, uint16_t* width,
		bool isDryRun, char* string);

/**
 * Renders text without wrapping at spaces, but with wrapping at newlines.
 * @param context Pointer to FMGL library context.
 * @param fontSettings Pointer to font settings.
 * @param x,y Top left text coordinates.
 * @param width,height Pointers to variables, where rendered text sizes will be stored.
 * @param isDryRun If true, then doesn't draw anything, just calculating width.
 * @param string Text to render.
 */
void FMGL_API_RenderTextWithLineBreaks(FMGL_API_DriverContext* context, FMGL_API_FontSettings* fontSettings, uint16_t x, uint16_t y, uint16_t* width, uint16_t* height,
		bool isDryRun, char* string);

/***************************
 * API functions ends here *
 ***************************/


#endif /* FMGL_INCLUDE_FMGL_H_ */
