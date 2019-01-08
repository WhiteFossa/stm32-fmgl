
// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

#include "main.h"

int main(int argc, char* argv[])
{
	/* Setting up hardware */
	L2HAL_Init();

	HAL_Delay(100);

	/* Detecting display */
	L2HAL_SSD1306_Context.I2CHandle = &I2CHandle;
	L2HAL_SSD1306_DetectDisplay(&L2HAL_SSD1306_Context);
	L2HAL_SSD1306_TurnDisplayOn(&L2HAL_SSD1306_Context);

	/* Attaching FMGL to display */
	fmglContext = FMGL_AttachToDriver(&L2HAL_SSD1306_Context, &L2HAL_SSD1306_GetWidth, &L2HAL_SSD1306_GetHeight, &L2HAL_SSD1306_SetActiveColor,
			&L2HAL_SSD1306_DrawPixel, &L2HAL_SSD1306_GetPixel, &L2HAL_SSD1306_PushFramebuffer);

	/* Initializing font */
	FMGL_Font font= FMGL_FontTerminusRegular12Init();

	FMGL_ColorStruct OffColor;
	OffColor.R = 0;
	OffColor.G = 0;
	OffColor.B = 0;

	FMGL_ColorStruct OnColor;
	OnColor.R = 1;
	OnColor.G = 1;
	OnColor.B = 1;

	FMGL_XBMTransparencyMode transparencyMode = FMGL_XBMTransparencyModeNormal;

	/* Font settings */
	FMGL_FontSettings fontSettings;
	fontSettings.Font = &font;
	fontSettings.Scale = 1;
	fontSettings.FontColor = &OnColor;
	fontSettings.BackgroundColor = &OffColor;
	fontSettings.Transparency = &transparencyMode;

	uint16_t drawnWidth;

	FMGL_RenderString(&fmglContext, &fontSettings, 0, 0, &drawnWidth, " !\"#$%&'()*+,-./01234");
	FMGL_RenderString(&fmglContext, &fontSettings, 0, 12, &drawnWidth, "56789:;<=>?@ABCDEFGHI");
	FMGL_RenderString(&fmglContext, &fontSettings, 0, 24, &drawnWidth, "JKLMNOPQRSTUVWXYZ");
	FMGL_PushFramebuffer(&fmglContext);

	while(1) {}

//	/* Preparing image */
//	FMGL_XBMImage image;
//	image.Width = Awesome_width;
//	image.Height = Awesome_height;
//	image.Raster = Awesome_bits;

//	FMGL_ColorStruct OffColor;
//	OffColor.R = 0;
//	OffColor.G = 0;
//	OffColor.B = 0;
//
//	FMGL_ColorStruct OnColor;
//	OnColor.R = 1;
//	OnColor.G = 1;
//	OnColor.B = 1;
//
//	FMGL_XBMImage character;
//	character.Height = 12;
//	character.Width = 3;
//	character.Raster = font.Characters[0x21]->Raster;


//	double x = 0;
//	double y = 0;
//
//	double dx = 1;
//	double dy = 2;
//
//	uint16_t oldX = 0;
//	uint16_t oldY = 0;
//
//	while(1)
//	{
//		// Cleaning screen
//		FMGL_DrawRectangleFilled(&fmglContext, 0, 0, FMGL_GetDisplayWidth(&fmglContext), FMGL_GetDisplayHeight(&fmglContext), OffColor, OffColor);
//
//		// Moving to new position
//		x += dx;
//		y += dy;
//
//		if (x < 0)
//		{
//			x = abs(x);
//			dx *= -1;
//		}
//		else if (x >= FMGL_GetDisplayWidth(&fmglContext) - image.Width)
//		{
//			x = 2 * (FMGL_GetDisplayWidth(&fmglContext)- image.Width) - x - 1;
//			dx *= -1;
//		}
//
//		if (y < 0)
//		{
//			y = abs(y);
//			dy *= -1;
//		}
//		else if (y >= FMGL_GetDisplayHeight(&fmglContext) - image.Height)
//		{
//			y = 2 * (FMGL_GetDisplayHeight(&fmglContext) - image.Height) - y - 1;
//			dy *= -1;
//		}
//
//		oldX = floor(x + 0.5);
//		oldY = floor(y + 0.5);
//
//		/* Crosshair */
//		FMGL_SetActiveColor(&fmglContext, OnColor);
//		FMGL_DrawLineHorizontal(&fmglContext, 0, fmglContext.MaxX, oldY + image.Height / 2);
//		FMGL_DrawLineVertical(&fmglContext, oldX + image.Width / 2, 0, fmglContext.MaxY);
//
//		FMGL_DrawRectangle(&fmglContext, oldX, oldY, oldX + 32, oldY + 32);
//		FMGL_RenderXBM(&fmglContext, &image, oldX, oldY, 1, 1, OnColor, OffColor, FMGL_XBMTransparencyModeTransparentInactive);
//		FMGL_PushFramebuffer(&fmglContext);
//
//		HAL_Delay(10);
//
//	}

	return 0;
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
