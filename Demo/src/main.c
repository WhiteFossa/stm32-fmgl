/*
	This file is part of Fossa's MCU Graphics Library (FMGL).

	FMGL is free software:
	you can redistribute it and/or modify it under the terms of the
	GNU General Public License as published by the Free Software
	Foundation, either version 3 of the License, or (at your option)
	any later version.

	FMGL is distributed in the hope
	that it will be useful, but WITHOUT ANY WARRANTY; without even
	the implied warranty of MERCHANTABILITY or FITNESS FOR A
	PARTICULAR PURPOSE.  See the GNU General Public License for more
	details.

	You should have received a copy of the GNU General Public License
	along with FMGL.

	If not, see <http://www.gnu.org/licenses/>.

	-------------------------------------------------------------------------

	Created by White Fossa, also known as Artyom Vetrov.

	Feel free to contact: whitefossa@gmail.com

	Repository: https://github.com/WhiteFossa/stm32-l2hal

	If repository above is not available, try my LiveJournal:
	fossa-white.livejournal.com

	or as last measure try to search for #WhiteFossa hashtag.

	-------------------------------------------------------------------------
 */


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

	FMGL_API_ColorStruct OffColor;
	OffColor.R = 0;
	OffColor.G = 0;
	OffColor.B = 0;

	FMGL_API_ColorStruct OnColor;
	OnColor.R = FMGL_API_MAX_CHANNEL_BRIGHTNESS;
	OnColor.G = FMGL_API_MAX_CHANNEL_BRIGHTNESS;
	OnColor.B = FMGL_API_MAX_CHANNEL_BRIGHTNESS;

	/* Attaching FMGL to display */
	fmglContext = FMGL_API_AttachToDriver(&L2HAL_SSD1306_Context, &L2HAL_SSD1306_GetWidth, &L2HAL_SSD1306_GetHeight, &L2HAL_SSD1306_SetActiveColor,
			&L2HAL_SSD1306_DrawPixel, &L2HAL_SSD1306_GetPixel, &L2HAL_SSD1306_PushFramebuffer, OffColor);

	/* Initializing font */
	FMGL_API_Font font= FMGL_FontTerminusRegular12Init();
	FMGL_API_XBMTransparencyMode transparencyMode = FMGL_XBMTransparencyModeNormal;

	/* Font settings (normal and inverted) */
	normalFont.Font = &font;
	normalFont.Scale = 1;
	normalFont.CharactersSpacing = 0;
	normalFont.LinesSpacing = 0;
	normalFont.FontColor = &OnColor;
	normalFont.BackgroundColor = &OffColor;
	normalFont.Transparency = &transparencyMode;

	invertedFont.Font = &font;
	invertedFont.Scale = 1;
	invertedFont.CharactersSpacing = 0;
	invertedFont.LinesSpacing = 0;
	invertedFont.FontColor = &OffColor;
	invertedFont.BackgroundColor = &OnColor;
	invertedFont.Transparency = &transparencyMode;

	/* Preparing sprite to draw */
	sprite.Width = Awesome_width;
	sprite.Height = Awesome_height;
	sprite.Raster = Awesome_bits;

	uint16_t maxX = FMGL_API_GetDisplayWidth(&fmglContext) -1;
	uint16_t maxY = FMGL_API_GetDisplayHeight(&fmglContext) -1;

	uint16_t spriteAreaMaxX = maxX - sprite.Width;
	uint16_t spriteAreaMaxY = maxY - sprite.Height;

	currentFont = &normalFont;
	uint32_t fontBlinkingCounter = FONT_BLINKING_INTERVAL + 1; /* +1 to cause immediate redraw */

	int16_t spriteX = 0;
	int16_t spriteY = 0;

	int16_t spriteDX = SPRITE_SPEED_X;
	int16_t spriteDY = SPRITE_SPEED_Y;

	/* Main cycle */
	while(true)
	{
		/* Blinking */
		if (fontBlinkingCounter > FONT_BLINKING_INTERVAL)
		{
			fontBlinkingCounter = 0;

			/* Inverting font */
			if (currentFont == &normalFont)
			{
				currentFont = &invertedFont;
			}
			else
			{
				currentFont = &normalFont;
			}
		}
		else
		{
			fontBlinkingCounter ++;
		}

		/* Moving sprite */
		spriteX += spriteDX;
		spriteY += spriteDY;

		if (spriteX < 0)
		{
			spriteX = abs(spriteX);
			spriteDX *= -1;
		}
		else if (spriteX > spriteAreaMaxX)
		{
			spriteX = 2 * spriteAreaMaxX - spriteX;
			spriteDX *= -1;
		}

		if (spriteY < 0)
		{
			spriteY = abs(spriteY);
			spriteDY *= -1;
		}
		else if (spriteY > spriteAreaMaxY)
		{
			spriteY = 2 * spriteAreaMaxY - spriteY;
			spriteDY *= -1;
		}

		/* Clearing screen */
		FMGL_API_ClearScreen(&fmglContext);

		/* Drawing background text */
		DrawBackgroundText(currentFont);

		/* Drawing sprite */
		FMGL_API_RenderXBM(&fmglContext, &sprite, spriteX, spriteY, 1, 1, OnColor, OffColor, FMGL_XBMTransparencyModeTransparentInactive);

		/* Pushing framebuffer */
		FMGL_API_PushFramebuffer(&fmglContext);
	}

	return 0;
}

void DrawBackgroundText(FMGL_API_FontSettings* fontSettings)
{
	/* English banner */
	const char* bannerEng = "\xa5\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa8\n"
			"\xa1Hello, World!\xa1\n"
			"\xab\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xae";

	uint16_t bannerEngWidth;
	uint16_t bannerEngHeight;
	FMGL_API_RenderTextWithLineBreaks(&fmglContext, fontSettings, 0, 0, &bannerEngWidth, &bannerEngHeight, true, bannerEng);

	/* Russian banner*/
	const char* bannerRus = "\xa5\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa8\n"
			"\xa1\xf0\xd2\xc9\xd7\xc5\xd4, \xed\xc9\xd2!\xa1\n"
			"\xab\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xa0\xae";

	uint16_t bannerRusWidth;
	uint16_t bannerRusHeight;
	FMGL_API_RenderTextWithLineBreaks(&fmglContext, fontSettings, 0, 0, &bannerRusWidth, &bannerRusHeight, true, bannerRus);

	uint16_t bannerEngHShift = (FMGL_API_GetDisplayWidth(&fmglContext) - bannerEngWidth) / 2;
	uint16_t bannerRusHShift = (FMGL_API_GetDisplayWidth(&fmglContext) - bannerRusWidth) / 2;

	/* Actual drawing */
	uint16_t width, height;
	FMGL_API_RenderTextWithLineBreaks(&fmglContext, fontSettings, bannerEngHShift, 0, &width, &height, false, bannerEng);
	FMGL_API_RenderTextWithLineBreaks(&fmglContext, fontSettings, bannerRusHShift, 33, &width, &height, false, bannerRus);
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
