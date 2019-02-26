#include <fmgl_private.h>

bool FMGL_Priv_IsActiveXBMPixel(FMGL_API_XBMImage* image, uint16_t x, uint16_t y)
{
	if (x >= image->Width || y >= image->Height)
	{
		return false;
	}

	uint16_t bytesPerRow = image->Width / FMGL_PRIV_BITS_PER_BYTE; /* Round down */
	if (0 != (image->Width % FMGL_PRIV_BITS_PER_BYTE)) /* Do we have non completely filled byte at rightmost position in row*/
	{
		bytesPerRow ++;
	}

	uint32_t index = y * bytesPerRow + x / FMGL_PRIV_BITS_PER_BYTE;
	uint8_t mask = (1 << (x % FMGL_PRIV_BITS_PER_BYTE));

	if (0 != (image->Raster[index] & mask))
	{
		return true; /* To be sure that 0xFF is returned */
	}
	else
	{
		return false;
	}
}

void FMGL_Priv_RenderCharacter(FMGL_API_DriverContext* context, FMGL_API_FontSettings* fontSettings, uint16_t x, uint16_t y, char character)
{
	/* Generating XBM image structure */
	FMGL_API_XBMImage characterImage;
	characterImage.Height = fontSettings->Font->Height;
	characterImage.Width = fontSettings->Font->GetCharacterWidth((uint8_t)character);
	characterImage.Raster = fontSettings->Font->Characters[(uint8_t)character];

	FMGL_API_RenderXBM(context, &characterImage, x, y, fontSettings->Scale, fontSettings->Scale, *fontSettings->FontColor, *fontSettings->BackgroundColor, *fontSettings->Transparency);
}

void FMGL_Priv_RenderSubstring(FMGL_API_DriverContext* context, FMGL_API_FontSettings* fontSettings, uint16_t startPos, uint16_t length,
		uint16_t x, uint16_t* y, uint16_t scaledLineHeight, uint16_t* width, char* string)
{
	char* substr = AUX_Str_Substring(string, startPos, length);
	uint16_t currWidth;
	FMGL_API_RenderOneLineDumb(context, fontSettings, x, *y, &currWidth, substr);
	AUX_Mem_SafeFree(substr);

	if (currWidth > *width)
	{
		*width = currWidth;
	}

	*y += scaledLineHeight;
}
