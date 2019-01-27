
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

	/* ASCII */
//	FMGL_RenderString(&fmglContext, &fontSettings, 0, 0, &drawnWidth, " !\"#$%&'()*+,-./01234");
//	FMGL_RenderString(&fmglContext, &fontSettings, 0, 12, &drawnWidth, "56789:;<=>?@ABCDEFGHI");
//	FMGL_RenderString(&fmglContext, &fontSettings, 0, 24, &drawnWidth, "JKLMNOPQRSTUVWXYZ[\\]^");
//	FMGL_RenderString(&fmglContext, &fontSettings, 0, 36, &drawnWidth, "_`abcdefghijklmnopqrs");
//	FMGL_RenderString(&fmglContext, &fontSettings, 0, 48, &drawnWidth, "tuvwxyz{|}~");

	/* KOI8-R */
	/* Russian letters*/
//	FMGL_RenderString(&fmglContext, &fontSettings, 0, 0, &drawnWidth, "\xc0\xc1\xc2\xc3\xc4\xc5\xc6\xc7\xc8\xc9\xca\xcb\xcc\xcd\xce\xcf\xd0\xd1\xd2\xd3\xd4");
//	FMGL_RenderString(&fmglContext, &fontSettings, 0, 12, &drawnWidth, "\xd5\xd6\xd7\xd8\xd9\xda\xdb\xdc\xdd\xde\xdf\xe0\xe1\xe2\xe3\xe4\xe5\xe6\xe7\xe8\xe9");
//	FMGL_RenderString(&fmglContext, &fontSettings, 0, 24, &drawnWidth, "\xea\xeb\xec\xed\xee\xef\xf0\xf1\xf2\xf3\xf4\xf5\xf6\xf7\xf8\xf9\xfa\xfb\xfc\xfd\xfe");
//	FMGL_RenderString(&fmglContext, &fontSettings, 0, 36, &drawnWidth, "\xff");

	/* Forms elements */
	FMGL_RenderString(&fmglContext, &fontSettings, 0, 0, &drawnWidth, "\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\x8c\x8d\x8e\x8f\x90\x91\x92\x93\x94");
	FMGL_RenderString(&fmglContext, &fontSettings, 0, 12, &drawnWidth, "\x95\x96\x97\x98\x99\x9a\x9b\x9c\x9d\x9e\x9f\xa0\xa1\xa2\xa3\xa4\xa5\xa6\xa7\xa8\xa9");
	FMGL_RenderString(&fmglContext, &fontSettings, 0, 24, &drawnWidth, "\xaa\xab\xac\xad\xae\xaf\xb0\xb1\xb2\xb3\xb4\xb5\xb6\xb7\xb8\xb9\xba\xbb\xbc\xbd\xbe");
	FMGL_RenderString(&fmglContext, &fontSettings, 0, 36, &drawnWidth, "\xbf");

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
