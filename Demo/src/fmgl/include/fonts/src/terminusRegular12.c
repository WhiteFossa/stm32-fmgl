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
	FMGL_FontTerminusRegular12.Characters['+'] = FMGL_FontTerminusRegular12_PlusRaster;
	FMGL_FontTerminusRegular12.Characters[','] = FMGL_FontTerminusRegular12_CommaRaster;
	FMGL_FontTerminusRegular12.Characters['-'] = FMGL_FontTerminusRegular12_MinusRaster;
	FMGL_FontTerminusRegular12.Characters['.'] = FMGL_FontTerminusRegular12_DotRaster;
	FMGL_FontTerminusRegular12.Characters['/'] = FMGL_FontTerminusRegular12_SlashRaster;
	FMGL_FontTerminusRegular12.Characters['0'] = FMGL_FontTerminusRegular12_ZeroRaster;
	FMGL_FontTerminusRegular12.Characters['1'] = FMGL_FontTerminusRegular12_OneRaster;
	FMGL_FontTerminusRegular12.Characters['2'] = FMGL_FontTerminusRegular12_TwoRaster;
	FMGL_FontTerminusRegular12.Characters['3'] = FMGL_FontTerminusRegular12_ThreeRaster;
	FMGL_FontTerminusRegular12.Characters['4'] = FMGL_FontTerminusRegular12_FourRaster;
	FMGL_FontTerminusRegular12.Characters['5'] = FMGL_FontTerminusRegular12_FiveRaster;
	FMGL_FontTerminusRegular12.Characters['6'] = FMGL_FontTerminusRegular12_SixRaster;
	FMGL_FontTerminusRegular12.Characters['7'] = FMGL_FontTerminusRegular12_SevenRaster;
	FMGL_FontTerminusRegular12.Characters['8'] = FMGL_FontTerminusRegular12_EightRaster;
	FMGL_FontTerminusRegular12.Characters['9'] = FMGL_FontTerminusRegular12_NineRaster;
	FMGL_FontTerminusRegular12.Characters[':'] = FMGL_FontTerminusRegular12_ColonRaster;
	FMGL_FontTerminusRegular12.Characters[';'] = FMGL_FontTerminusRegular12_SemicolonRaster;
	FMGL_FontTerminusRegular12.Characters['<'] = FMGL_FontTerminusRegular12_LessRaster;
	FMGL_FontTerminusRegular12.Characters['='] = FMGL_FontTerminusRegular12_EqualRaster;
	FMGL_FontTerminusRegular12.Characters['>'] = FMGL_FontTerminusRegular12_GreaterRaster;
	FMGL_FontTerminusRegular12.Characters['?'] = FMGL_FontTerminusRegular12_QuestionMarkRaster;
	FMGL_FontTerminusRegular12.Characters['@'] = FMGL_FontTerminusRegular12_AtRaster;
	FMGL_FontTerminusRegular12.Characters['A'] = FMGL_FontTerminusRegular12_EnCapARaster;
	FMGL_FontTerminusRegular12.Characters['B'] = FMGL_FontTerminusRegular12_EnCapBRaster;
	FMGL_FontTerminusRegular12.Characters['C'] = FMGL_FontTerminusRegular12_EnCapCRaster;
	FMGL_FontTerminusRegular12.Characters['D'] = FMGL_FontTerminusRegular12_EnCapDRaster;
	FMGL_FontTerminusRegular12.Characters['E'] = FMGL_FontTerminusRegular12_EnCapERaster;
	FMGL_FontTerminusRegular12.Characters['F'] = FMGL_FontTerminusRegular12_EnCapFRaster;
	FMGL_FontTerminusRegular12.Characters['G'] = FMGL_FontTerminusRegular12_EnCapGRaster;
	FMGL_FontTerminusRegular12.Characters['H'] = FMGL_FontTerminusRegular12_EnCapHRaster;
	FMGL_FontTerminusRegular12.Characters['I'] = FMGL_FontTerminusRegular12_EnCapIRaster;
	FMGL_FontTerminusRegular12.Characters['J'] = FMGL_FontTerminusRegular12_EnCapJRaster;
	FMGL_FontTerminusRegular12.Characters['K'] = FMGL_FontTerminusRegular12_EnCapKRaster;
	FMGL_FontTerminusRegular12.Characters['L'] = FMGL_FontTerminusRegular12_EnCapLRaster;
	FMGL_FontTerminusRegular12.Characters['M'] = FMGL_FontTerminusRegular12_EnCapMRaster;
	FMGL_FontTerminusRegular12.Characters['N'] = FMGL_FontTerminusRegular12_EnCapNRaster;
	FMGL_FontTerminusRegular12.Characters['O'] = FMGL_FontTerminusRegular12_EnCapORaster;
	FMGL_FontTerminusRegular12.Characters['P'] = FMGL_FontTerminusRegular12_EnCapPRaster;
	FMGL_FontTerminusRegular12.Characters['Q'] = FMGL_FontTerminusRegular12_EnCapQRaster;
	FMGL_FontTerminusRegular12.Characters['R'] = FMGL_FontTerminusRegular12_EnCapRRaster;
	FMGL_FontTerminusRegular12.Characters['S'] = FMGL_FontTerminusRegular12_EnCapSRaster;
	FMGL_FontTerminusRegular12.Characters['T'] = FMGL_FontTerminusRegular12_EnCapTRaster;
	FMGL_FontTerminusRegular12.Characters['U'] = FMGL_FontTerminusRegular12_EnCapURaster;
	FMGL_FontTerminusRegular12.Characters['V'] = FMGL_FontTerminusRegular12_EnCapVRaster;
	FMGL_FontTerminusRegular12.Characters['W'] = FMGL_FontTerminusRegular12_EnCapWRaster;
	FMGL_FontTerminusRegular12.Characters['X'] = FMGL_FontTerminusRegular12_EnCapXRaster;
	FMGL_FontTerminusRegular12.Characters['Y'] = FMGL_FontTerminusRegular12_EnCapYRaster;
	FMGL_FontTerminusRegular12.Characters['Z'] = FMGL_FontTerminusRegular12_EnCapZRaster;

	return FMGL_FontTerminusRegular12;
}



