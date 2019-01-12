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
	FMGL_FontTerminusRegular12.Characters['['] = FMGL_FontTerminusRegular12_SqareBracketLeftRaster;
	FMGL_FontTerminusRegular12.Characters['\\'] = FMGL_FontTerminusRegular12_BackSlashRaster;
	FMGL_FontTerminusRegular12.Characters[']'] = FMGL_FontTerminusRegular12_SqareBracketRightRaster;
	FMGL_FontTerminusRegular12.Characters['^'] = FMGL_FontTerminusRegular12_CaretRaster;
	FMGL_FontTerminusRegular12.Characters['_'] = FMGL_FontTerminusRegular12_UnderscoreRaster;
	FMGL_FontTerminusRegular12.Characters['`'] = FMGL_FontTerminusRegular12_GraveAccentRaster;
	FMGL_FontTerminusRegular12.Characters['a'] = FMGL_FontTerminusRegular12_EnLowCaseARaster;
	FMGL_FontTerminusRegular12.Characters['b'] = FMGL_FontTerminusRegular12_EnLowCaseBRaster;
	FMGL_FontTerminusRegular12.Characters['c'] = FMGL_FontTerminusRegular12_EnLowCaseCRaster;
	FMGL_FontTerminusRegular12.Characters['d'] = FMGL_FontTerminusRegular12_EnLowCaseDRaster;
	FMGL_FontTerminusRegular12.Characters['e'] = FMGL_FontTerminusRegular12_EnLowCaseERaster;
	FMGL_FontTerminusRegular12.Characters['f'] = FMGL_FontTerminusRegular12_EnLowCaseFRaster;
	FMGL_FontTerminusRegular12.Characters['g'] = FMGL_FontTerminusRegular12_EnLowCaseGRaster;
	FMGL_FontTerminusRegular12.Characters['h'] = FMGL_FontTerminusRegular12_EnLowCaseHRaster;
	FMGL_FontTerminusRegular12.Characters['i'] = FMGL_FontTerminusRegular12_EnLowCaseIRaster;
	FMGL_FontTerminusRegular12.Characters['j'] = FMGL_FontTerminusRegular12_EnLowCaseJRaster;
	FMGL_FontTerminusRegular12.Characters['k'] = FMGL_FontTerminusRegular12_EnLowCaseKRaster;
	FMGL_FontTerminusRegular12.Characters['l'] = FMGL_FontTerminusRegular12_EnLowCaseLRaster;
	FMGL_FontTerminusRegular12.Characters['m'] = FMGL_FontTerminusRegular12_EnLowCaseMRaster;
	FMGL_FontTerminusRegular12.Characters['n'] = FMGL_FontTerminusRegular12_EnLowCaseNRaster;
	FMGL_FontTerminusRegular12.Characters['o'] = FMGL_FontTerminusRegular12_EnLowCaseORaster;
	FMGL_FontTerminusRegular12.Characters['p'] = FMGL_FontTerminusRegular12_EnLowCasePRaster;
	FMGL_FontTerminusRegular12.Characters['q'] = FMGL_FontTerminusRegular12_EnLowCaseQRaster;
	FMGL_FontTerminusRegular12.Characters['r'] = FMGL_FontTerminusRegular12_EnLowCaseRRaster;
	FMGL_FontTerminusRegular12.Characters['s'] = FMGL_FontTerminusRegular12_EnLowCaseSRaster;
	FMGL_FontTerminusRegular12.Characters['t'] = FMGL_FontTerminusRegular12_EnLowCaseTRaster;
	FMGL_FontTerminusRegular12.Characters['u'] = FMGL_FontTerminusRegular12_EnLowCaseURaster;
	FMGL_FontTerminusRegular12.Characters['v'] = FMGL_FontTerminusRegular12_EnLowCaseVRaster;
	FMGL_FontTerminusRegular12.Characters['w'] = FMGL_FontTerminusRegular12_EnLowCaseWRaster;
	FMGL_FontTerminusRegular12.Characters['x'] = FMGL_FontTerminusRegular12_EnLowCaseXRaster;
	FMGL_FontTerminusRegular12.Characters['y'] = FMGL_FontTerminusRegular12_EnLowCaseYRaster;
	FMGL_FontTerminusRegular12.Characters['z'] = FMGL_FontTerminusRegular12_EnLowCaseZRaster;
	FMGL_FontTerminusRegular12.Characters['\{'] = FMGL_FontTerminusRegular12_CurlyBracketLeftRaster;
	FMGL_FontTerminusRegular12.Characters['\|'] = FMGL_FontTerminusRegular12_VerticalBarRaster;
	FMGL_FontTerminusRegular12.Characters['\}'] = FMGL_FontTerminusRegular12_CurlyBracketRightRaster;
	FMGL_FontTerminusRegular12.Characters['\~'] = FMGL_FontTerminusRegular12_TildeRaster;

	FMGL_FontTerminusRegular12.Characters[0xc0] = FMGL_FontTerminusRegular12_CyrLowCaseIURaster;
	FMGL_FontTerminusRegular12.Characters[0xc1] = FMGL_FontTerminusRegular12_CyrLowCaseARaster;
	FMGL_FontTerminusRegular12.Characters[0xc2] = FMGL_FontTerminusRegular12_CyrLowCaseBeRaster;
	FMGL_FontTerminusRegular12.Characters[0xc3] = FMGL_FontTerminusRegular12_CyrLowCaseTseRaster;
	FMGL_FontTerminusRegular12.Characters[0xc4] = FMGL_FontTerminusRegular12_CyrLowCaseDeRaster;
	FMGL_FontTerminusRegular12.Characters[0xc5] = FMGL_FontTerminusRegular12_CyrLowCaseIeRaster;
	FMGL_FontTerminusRegular12.Characters[0xc6] = FMGL_FontTerminusRegular12_CyrLowCaseEfRaster;
	FMGL_FontTerminusRegular12.Characters[0xc7] = FMGL_FontTerminusRegular12_CyrLowCaseGeRaster;
	FMGL_FontTerminusRegular12.Characters[0xc8] = FMGL_FontTerminusRegular12_CyrLowCaseKhaRaster;
	FMGL_FontTerminusRegular12.Characters[0xc9] = FMGL_FontTerminusRegular12_CyrLowCaseIiRaster;
	FMGL_FontTerminusRegular12.Characters[0xca] = FMGL_FontTerminusRegular12_CyrLowCaseShortIiRaster;
	FMGL_FontTerminusRegular12.Characters[0xcb] = FMGL_FontTerminusRegular12_CyrLowCaseKaRaster;
	FMGL_FontTerminusRegular12.Characters[0xcc] = FMGL_FontTerminusRegular12_CyrLowCaseElRaster;
	FMGL_FontTerminusRegular12.Characters[0xcd] = FMGL_FontTerminusRegular12_CyrLowCaseEmRaster;
	FMGL_FontTerminusRegular12.Characters[0xce] = FMGL_FontTerminusRegular12_CyrLowCaseEnRaster;
	FMGL_FontTerminusRegular12.Characters[0xcf] = FMGL_FontTerminusRegular12_CyrLowCaseORaster;

	return FMGL_FontTerminusRegular12;
}



