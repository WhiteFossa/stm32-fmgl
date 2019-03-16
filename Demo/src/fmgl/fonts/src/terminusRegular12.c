#include "terminusRegular12.h"

uint16_t FMGL_FontTerminusRegular12GetCharacterWidth (uint8_t character)
{
	return FMGL_FONT_TERMINUS_REGULAR_12_CHARACTER_WIDTH;
}

uint8_t* FMGL_FontTerminusRegular12GetCharacterRaster(uint8_t character)
{
	if (character < FMGL_FONT_TERMINUS_REGULAR_12_FIRST_CHARACTER_CODE)
	{
		return FMGL_FontTerminusRegular12_WrongCharacterCode;
	}

	return FMGL_FontTerminusRegular12Characters[character - FMGL_FONT_TERMINUS_REGULAR_12_FIRST_CHARACTER_CODE];
}

FMGL_API_Font FMGL_FontTerminusRegular12Init(void)
{
	FMGL_FontTerminusRegular12.Height = FMGL_FONT_TERMINUS_REGULAR_12_CHARACTER_HEIGHT;
	FMGL_FontTerminusRegular12.GetCharacterWidth = &FMGL_FontTerminusRegular12GetCharacterWidth;
	FMGL_FontTerminusRegular12.GetCharacterRaster = &FMGL_FontTerminusRegular12GetCharacterRaster;

	return FMGL_FontTerminusRegular12;
}
