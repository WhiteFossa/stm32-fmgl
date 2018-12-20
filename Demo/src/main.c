
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

	/* Preparing image */
	FMGL_XBMStruct image;
	image.Width = Demo_width;
	image.Height = Demo_height;
	image.Raster = Demo_bits;

	FMGL_ColorStruct OffColor;
	OffColor.R = 0;
	OffColor.G = 0;
	OffColor.B = 0;

	FMGL_ColorStruct OnColor;
	OnColor.R = 1;
	OnColor.G = 1;
	OnColor.B = 1;

	FMGL_SetActiveColor(&fmglContext, OffColor);
	for (uint16_t y = 0; y < 64; y++)
	{
		for (uint16_t x = 0; x < 128; x++)
		{
			FMGL_DrawPixel(&fmglContext, x, y);
		}
	}
	FMGL_PushFramebuffer(&fmglContext);


	for (uint16_t y = 0; y < 64; y++)
	{
		for (uint16_t x = 0; x < 128; x++)
		{
			if (FMGL_IsActiveXBMPixel(&image, x, y))
			{
				FMGL_SetActiveColor(&fmglContext, OnColor);
			}
			else
			{
				FMGL_SetActiveColor(&fmglContext, OffColor);
			}

			FMGL_DrawPixel(&fmglContext, x, y);
		}
	}

	FMGL_PushFramebuffer(&fmglContext);

	while(1) {}

/*	double x = 0;
	double y = 0;

	double dx = 3;
	double dy = 2;

	uint16_t oldX = 0;
	uint16_t oldY = 0;

	FMGL_ColorStruct OffColor;
	OffColor.R = 0;
	OffColor.G = 0;
	OffColor.B = 0;

	FMGL_ColorStruct OnColor;
	OnColor.R = 1;
	OnColor.G = 1;
	OnColor.B = 1;

	while(1)
	{
		// Turning off old pixel
		FMGL_SetActiveColor(&fmglContext, OffColor);
		FMGL_DrawPixel(&fmglContext, oldX, oldY);

		// Moving to new position
		x += dx;
		y += dy;

		if (x < 0)
		{
			x = abs(x);
			dx *= -1;
		}
		else if (x >= FMGL_GetDisplayWidth(&fmglContext))
		{
			x = 2 * FMGL_GetDisplayWidth(&fmglContext) - x - 1;
			dx *= -1;
		}

		if (y < 0)
		{
			y = abs(y);
			dy *= -1;
		}
		else if (y >= FMGL_GetDisplayHeight(&fmglContext))
		{
			y = 2 * FMGL_GetDisplayHeight(&fmglContext) - y - 1;
			dy *= -1;
		}

		oldX = floor(x + 0.5);
		oldY = floor(y + 0.5);

		// Turning on new pixel
		FMGL_SetActiveColor(&fmglContext, OnColor);
		FMGL_DrawPixel(&fmglContext, oldX, oldY);

		FMGL_PushFramebuffer(&fmglContext);
	}*/

	return 0;
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
