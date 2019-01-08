#include "fmgl.h"

FMGL_DriverContext FMGL_AttachToDriver
(
	void* deviceContext,
	uint16_t (*GetWidth) (void),
	uint16_t (*GetHeight) (void),
	void (*SetActiveColor) (void* deviceContext, FMGL_ColorStruct color),
	void (*DrawPixel) (void* deviceContext, uint16_t x, uint16_t y),
	FMGL_ColorStruct (*GetPixel) (void* deviceContext, uint16_t x, uint16_t y),
	void (*PushFramebuffer) (void* deviceContext)
)
{
	FMGL_DriverContext context;

	context.DeviceContext = deviceContext;
	context.GetWidth = GetWidth;
	context.GetHeight = GetHeight;
	context.SetActiveColor = SetActiveColor;
	context.DrawPixel = DrawPixel;
	context.GetPixel = GetPixel;
	context.PushFramebuffer = PushFramebuffer;

	/* Maximal coordinates */
	context.MaxX = context.GetWidth() - 1;
	context.MaxY = context.GetHeight() - 1;

	return context;
}

void FMGL_SetActiveColor(FMGL_DriverContext* context, FMGL_ColorStruct color)
{
	context->ActiveColor = color;
	context->SetActiveColor(context->DeviceContext, context->ActiveColor);
}

FMGL_ColorStruct FMGL_GetActiveColor(FMGL_DriverContext* context)
{
	return context->ActiveColor;
}

void FMGL_DrawPixel (FMGL_DriverContext* context, uint16_t x, uint16_t y)
{
	if (x > context->MaxX || y > context->MaxY)
	{
		return;
	}

	context->DrawPixel(context->DeviceContext, x, y);
}

FMGL_ColorStruct FMGL_GetPixel(FMGL_DriverContext* context, uint16_t x, uint16_t y)
{
	FMGL_ColorStruct result;
	result.R = 0;
	result.G = 0;
	result.B = 0;

	if (x > context->MaxX || y > context->MaxY)
	{
		return result;
	}

	return context->GetPixel(context->DeviceContext, x, y);
}

void FMGL_PushFramebuffer (FMGL_DriverContext* context)
{
	context->PushFramebuffer(context->DeviceContext);
}

uint16_t FMGL_GetDisplayWidth(FMGL_DriverContext* context)
{
	return context->GetWidth();
}

uint16_t FMGL_GetDisplayHeight(FMGL_DriverContext* context)
{
	return context->GetHeight();
}

bool FMGL_IsActiveXBMPixel(FMGL_XBMImage* image, uint16_t x, uint16_t y)
{
	if (x >= image->Width || y >= image->Height)
	{
		return false;
	}

	uint16_t bytesPerRow = image->Width / FMGL_BITS_PER_BYTE; /* Round down */
	if (0 != (image->Width % FMGL_BITS_PER_BYTE)) /* Do we have non completely filled byte at rightmost position in row*/
	{
		bytesPerRow ++;
	}

	uint32_t index = y * bytesPerRow + x / FMGL_BITS_PER_BYTE;
	uint8_t mask = (1 << (x % FMGL_BITS_PER_BYTE));

	if (0 != (image->Raster[index] & mask))
	{
		return true; /* To be sure that 0xFF is returned */
	}
	else
	{
		return false;
	}
}

void FMGL_RenderXBM(FMGL_DriverContext* context, FMGL_XBMImage* image, uint16_t x, uint16_t y, uint16_t scaleX, uint16_t scaleY,
		FMGL_ColorStruct activeColor, FMGL_ColorStruct inactiveColor, FMGL_XBMTransparencyMode transparency)
{
	/* Do at least one pixel fit the screen? */
	if (x > context->MaxX || y > context->MaxY)
	{
		return;
	}

	uint32_t scaledWidth = image->Width * scaleX;
	uint32_t scaledHeight = image->Height * scaleY;

	FMGL_ColorStruct colors[FMGL_XBM_COLORS_NUMBER]; /* Colors, active color first */
	colors[FMGL_XBM_ACTIVE_COLOR_INDEX] = activeColor;
	colors[FMGL_XBM_INACTIVE_COLOR_INDEX] = inactiveColor;

	for (uint8_t colorIndex = 0; colorIndex < FMGL_XBM_COLORS_NUMBER; colorIndex++)
	{
		if
		(
			((FMGL_XBM_ACTIVE_COLOR_INDEX == colorIndex) && (FMGL_XBMTransparencyModeTransparentActive == transparency))
			||
			((FMGL_XBM_INACTIVE_COLOR_INDEX == colorIndex) && (FMGL_XBMTransparencyModeTransparentInactive == transparency))
		)
		{
			/* Skipping transparent color */
			continue;
		}

		FMGL_SetActiveColor(context, colors[colorIndex]);

		for (uint32_t dy = 0; dy < scaledHeight; dy++)
		{
			uint16_t sy = dy / scaleY;

			for (uint32_t dx = 0; dx < scaledWidth; dx++)
			{
				uint16_t sx = dx / scaleX;

				bool isActive = FMGL_IsActiveXBMPixel(image, sx, sy);

				if
				(
					((FMGL_XBM_ACTIVE_COLOR_INDEX == colorIndex) && isActive)
					||
					((FMGL_XBM_INACTIVE_COLOR_INDEX == colorIndex) && !isActive)
				)
				{
					/* Active pixel */
					FMGL_DrawPixel(context, dx + x, dy + y);
				}
			}
		}
	}
}

void FMGL_DrawLineHorizontal(FMGL_DriverContext* context, uint16_t x1, uint16_t x2, uint16_t y)
{
	if (y > context->MaxY)
	{
		return;
	}

	uint16_t minX = FMGL_MIN(x1, x2);
	if (minX > context->MaxX)
	{
		/* Out of screen, can't draw */
		return;
	}

	uint16_t maxX = FMGL_MAX(x1, x2);

	if (maxX > context->MaxX)
	{
		maxX = context->MaxX;
	}

	for (uint16_t x = minX; x <= maxX; x++)
	{
		FMGL_DrawPixel(context, x, y);
	}
}

void FMGL_DrawLineVertical(FMGL_DriverContext* context, uint16_t x, uint16_t y1, uint16_t y2)
{
	if (x > context->MaxX)
	{
		return;
	}

	uint16_t minY = FMGL_MIN(y1, y2);

	if (minY > context->MaxY)
	{
		return;
	}

	uint16_t maxY = FMGL_MAX(y1, y2);

	if (maxY > context->MaxY)
	{
		maxY = context->MaxY;
	}

	for (uint16_t y = minY; y <= maxY; y++)
	{
		FMGL_DrawPixel(context, x, y);
	}
}

/**
 * Draws rectangle without filling it.
 */
void FMGL_DrawRectangle(FMGL_DriverContext* context, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	/* Will at least one pixel be on screen */
	uint16_t minX = FMGL_MIN(x1, x2);

	if (minX > context->MaxX)
	{
		return;
	}

	uint16_t minY = FMGL_MIN(y1, y2);

	if (minY > context->MaxY)
	{
		return;
	}

	/* At least some pixels will be displayed */
	uint16_t maxX = FMGL_MAX(x1, x2);
	uint16_t maxY = FMGL_MAX(y1, y2);

	uint16_t maxVisibleX = FMGL_MIN(maxX, context->MaxX);
	uint16_t maxVisibleY = FMGL_MIN(maxY, context->MaxY);

	/* Drawing 100% visible parts */
	FMGL_DrawLineHorizontal(context, minX, maxVisibleX, minY);
	FMGL_DrawLineVertical(context, minX, minY, maxVisibleY);

	/* Right border */
	if (maxX <= context->MaxX)
	{
		FMGL_DrawLineVertical(context, maxVisibleX, minY, maxVisibleY);
	}

	/* Bottom border */
	if (maxY <= context->MaxY)
	{
		FMGL_DrawLineHorizontal(context, minX, maxVisibleX, maxVisibleY);
	}
}

void FMGL_DrawRectangleFilled(FMGL_DriverContext* context, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, FMGL_ColorStruct borderColor, FMGL_ColorStruct fillColor)
{
	FMGL_ColorStruct activeColor = FMGL_GetActiveColor(context);

	/* Will at least one pixel be on screen */
	uint16_t minX = FMGL_MIN(x1, x2);

	if (minX > context->MaxX)
	{
		return;
	}

	uint16_t minY = FMGL_MIN(y1, y2);

	if (minY > context->MaxY)
	{
		return;
	}

	/* At least some pixels will be displayed */
	uint16_t maxX = FMGL_MAX(x1, x2);
	uint16_t maxY = FMGL_MAX(y1, y2);

	uint16_t maxVisibleX = FMGL_MIN(maxX, context->MaxX);
	uint16_t maxVisibleY = FMGL_MIN(maxY, context->MaxY);

	uint16_t fillLeftX = minX + 1;
	uint16_t fillTopY = minY + 1;

	uint16_t fillRightX = maxVisibleX; /* Initially think that right and bottom borders are off-screen*/
	uint16_t fillBottomY = maxVisibleY;

	/* Borders */
	FMGL_SetActiveColor(context, borderColor);
	FMGL_DrawLineHorizontal(context, minX, maxVisibleX, minY);
	FMGL_DrawLineVertical(context, minX, minY, maxVisibleY);

	if (maxX <= context->MaxX)
	{
		/*Right border is on screen so moving fill right bottom 1 pixel left*/
		fillRightX -= 1;
		FMGL_DrawLineVertical(context, maxVisibleX, minY, maxVisibleY);
	}

	if (maxY <= context->MaxY)
	{
		fillBottomY -= 1;
		FMGL_DrawLineHorizontal(context, minX, maxVisibleX, maxVisibleY);
	}

	/* Fill */
	if ((fillLeftX > context->MaxX) || (fillTopY > context->MaxY) || (fillRightX < fillLeftX) || (fillBottomY < fillTopY))
	{
		FMGL_SetActiveColor(context, activeColor);
		return;
	}

	FMGL_SetActiveColor(context, fillColor);
	for (uint16_t y = fillTopY; y <= fillBottomY; y++)
	{
		FMGL_DrawLineHorizontal(context, fillLeftX, fillRightX, y);
	}

	FMGL_SetActiveColor(context, activeColor);
}

void FMGL_RenderCharacter(FMGL_DriverContext* context, FMGL_FontSettings* fontSettings, uint16_t x, uint16_t y, uint16_t* width, char character)
{
	/* Generating XBM image structure */
	FMGL_XBMImage characterImage;
	characterImage.Height = fontSettings->Font->Height;
	characterImage.Width = fontSettings->Font->GetCharacterWidth((uint8_t)character);
	characterImage.Raster = fontSettings->Font->Characters[(uint8_t)character];

	*width = characterImage.Width;

	FMGL_RenderXBM(context, &characterImage, x, y, fontSettings->Scale, fontSettings->Scale, *fontSettings->FontColor, *fontSettings->BackgroundColor, *fontSettings->Transparency);
}

void FMGL_RenderString(FMGL_DriverContext* context, FMGL_FontSettings* fontSettings, uint16_t x, uint16_t y, uint16_t* width, char* string)
{
	/* Iterating through string until 0x00 or right screen border. */
	uint16_t currentX = x;
	char* currentChar = string;
	uint16_t lastCharWidth;

	while(0x00 != *currentChar)
	{
		FMGL_RenderCharacter(context, fontSettings, currentX, y, &lastCharWidth, *currentChar);

		currentX += lastCharWidth;

		if (currentX > context->MaxX)
		{
			break;
		}

		currentChar ++;
	}

	*width = currentX - x;
}

