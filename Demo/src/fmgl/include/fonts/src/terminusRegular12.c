#include <fonts/include/terminusRegular12.h>

FMGL_Font FMGL_FontTerminusRegular12Init(void)
{
	/* Basic setup */
	FMGL_FontTerminusRegular12.Height = 12;

	/* Characters table */
	FMGL_FontTerminusRegular12.Characters[' '] = &FMGL_FontTerminusRegular12_Space;
	FMGL_FontTerminusRegular12.Characters['!'] = &FMGL_FontTerminusRegular12_EclamationMark;
	FMGL_FontTerminusRegular12.Characters['"'] = &FMGL_FontTerminusRegular12_DoubleQuotes;
	FMGL_FontTerminusRegular12.Characters['#'] = &FMGL_FontTerminusRegular12_Sharp;
	FMGL_FontTerminusRegular12.Characters['$'] = &FMGL_FontTerminusRegular12_Dollar;
	FMGL_FontTerminusRegular12.Characters['%'] = &FMGL_FontTerminusRegular12_Percent;
	FMGL_FontTerminusRegular12.Characters['&'] = &FMGL_FontTerminusRegular12_Ampersand;
	FMGL_FontTerminusRegular12.Characters['\''] = &FMGL_FontTerminusRegular12_Quote;
	FMGL_FontTerminusRegular12.Characters['('] = &FMGL_FontTerminusRegular12_LeftParenthesis;
	FMGL_FontTerminusRegular12.Characters[')'] = &FMGL_FontTerminusRegular12_RightParenthesis;
	FMGL_FontTerminusRegular12.Characters['*'] = &FMGL_FontTerminusRegular12_Asterisk;

	/* Characters images */

	/* Space */
	FMGL_FontTerminusRegular12_Space.Width = 6;
	FMGL_FontTerminusRegular12_Space.Raster = FMGL_FontTerminusRegular12_SpaceRaster;

	/* ! */
	FMGL_FontTerminusRegular12_EclamationMark.Width = 6;
	FMGL_FontTerminusRegular12_EclamationMark.Raster = FMGL_FontTerminusRegular12_EclamationMarkRaster;

	/* " */
	FMGL_FontTerminusRegular12_DoubleQuotes.Width = 6;
	FMGL_FontTerminusRegular12_DoubleQuotes.Raster = FMGL_FontTerminusRegular12_DoubleQuotesRaster;

	/* # */
	FMGL_FontTerminusRegular12_Sharp.Width = 6;
	FMGL_FontTerminusRegular12_Sharp.Raster = FMGL_FontTerminusRegular12_SharpRaster;

	/* $ */
	FMGL_FontTerminusRegular12_Dollar.Width = 6;
	FMGL_FontTerminusRegular12_Dollar.Raster = FMGL_FontTerminusRegular12_DollarRaster;

	/* % */
	FMGL_FontTerminusRegular12_Percent.Width = 6;
	FMGL_FontTerminusRegular12_Percent.Raster = FMGL_FontTerminusRegular12_PercentRaster;

	/* & */
	FMGL_FontTerminusRegular12_Ampersand.Width = 6;
	FMGL_FontTerminusRegular12_Ampersand.Raster = FMGL_FontTerminusRegular12_AmpersandRaster;

	/* ' */
	FMGL_FontTerminusRegular12_Quote.Width = 6;
	FMGL_FontTerminusRegular12_Quote.Raster = FMGL_FontTerminusRegular12_QuoteRaster;

	/* ( */
	FMGL_FontTerminusRegular12_LeftParenthesis.Width = 6;
	FMGL_FontTerminusRegular12_LeftParenthesis.Raster = FMGL_FontTerminusRegular12_LeftParenthesisRaster;

	/* ) */
	FMGL_FontTerminusRegular12_RightParenthesis.Width = 6;
	FMGL_FontTerminusRegular12_RightParenthesis.Raster = FMGL_FontTerminusRegular12_RightParenthesisRaster;

	/* * */
	FMGL_FontTerminusRegular12_Asterisk.Width = 6;
	FMGL_FontTerminusRegular12_Asterisk.Raster = FMGL_FontTerminusRegular12_AsteriskRaster;

	return FMGL_FontTerminusRegular12;
}



