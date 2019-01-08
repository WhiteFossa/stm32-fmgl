#include <fonts/include/terminusRegular12.h>

uint16_t FMGL_FontTerminusRegular12GetCharacterWidth (uint8_t character)
{
	return FMGL_FONT_TERMINUS_REGULAR_12_CHARACTER_WIDTH;
}

FMGL_Font FMGL_FontTerminusRegular12Init(void)
{
	/* Basic setup */
	FMGL_FontTerminusRegular12.Height = 12;
	FMGL_FontTerminusRegular12.GetCharacterWidth = &FMGL_FontTerminusRegular12GetCharacterWidth;

	/* Characters table */
	FMGL_FontTerminusRegular12.Characters[' '] = FMGL_FontTerminusRegular12_SpaceRaster;
	FMGL_FontTerminusRegular12.Characters['!'] = FMGL_FontTerminusRegular12_EclamationMarkRaster;
	FMGL_FontTerminusRegular12.Characters['"'] = FMGL_FontTerminusRegular12_DoubleQuotesRaster;
	FMGL_FontTerminusRegular12.Characters['#'] = FMGL_FontTerminusRegular12_SharpRaster;
	FMGL_FontTerminusRegular12.Characters['$'] = FMGL_FontTerminusRegular12_DollarRaster;
	FMGL_FontTerminusRegular12.Characters['%'] = FMGL_FontTerminusRegular12_PercentRaster;
	FMGL_FontTerminusRegular12.Characters['&'] = FMGL_FontTerminusRegular12_AmpersandRaster;
	FMGL_FontTerminusRegular12.Characters['\''] = FMGL_FontTerminusRegular12_QuoteRaster;
	FMGL_FontTerminusRegular12.Characters['('] = FMGL_FontTerminusRegular12_LeftParenthesisRaster;
	FMGL_FontTerminusRegular12.Characters[')'] = FMGL_FontTerminusRegular12_RightParenthesisRaster;
	FMGL_FontTerminusRegular12.Characters['*'] = FMGL_FontTerminusRegular12_AsteriskRaster;

	return FMGL_FontTerminusRegular12;
}



