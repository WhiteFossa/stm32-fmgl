#ifndef FMGL_INCLUDE_FONTS_TERMINUSREGULAR12_H_
#define FMGL_INCLUDE_FONTS_TERMINUSREGULAR12_H_

/**
 * Terminus font, regular, 6x12 pixels
 */

#include "fmgl.h"

/**
 * Character width.
 */
#define FMGL_FONT_TERMINUS_REGULAR_12_CHARACTER_WIDTH 6

/**
 * Call this function to get font instance.
 */
FMGL_Font FMGL_FontTerminusRegular12Init(void);

/**
 * Returns character width.
 */
uint16_t FMGL_FontTerminusRegular12GetCharacterWidth (uint8_t character);

/* Basic font settings */
FMGL_Font FMGL_FontTerminusRegular12;

/*************************
 * Characters going here *
 *************************/

static const uint8_t FMGL_FontTerminusRegular12_SpaceRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; /* Space */
static const uint8_t FMGL_FontTerminusRegular12_EclamationMarkRaster[] = { 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x04, 0x04, 0x00, 0x00 }; /* ! */
static const uint8_t FMGL_FontTerminusRegular12_DoubleQuotesRaster[] = { 0x00, 0x0A, 0x0A, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; /* " */
static const uint8_t FMGL_FontTerminusRegular12_SharpRaster[] = { 0x00, 0x00, 0x0A, 0x0A, 0x1F, 0x0A, 0x0A, 0x1F, 0x0A, 0x0A, 0x00, 0x00 }; /* # */
static const uint8_t FMGL_FontTerminusRegular12_DollarRaster[] = { 0x00, 0x00, 0x04, 0x0E, 0x15, 0x05, 0x0E, 0x14, 0x15, 0x0E, 0x04, 0x00 }; /* $ */
static const uint8_t FMGL_FontTerminusRegular12_PercentRaster[] = { 0x00, 0x00, 0x12, 0x15, 0x0A, 0x08, 0x04, 0x14, 0x2A, 0x12, 0x00, 0x00 }; /* % */
static const uint8_t FMGL_FontTerminusRegular12_AmpersandRaster[] = { 0x00, 0x00, 0x04, 0x0A, 0x0A, 0x04, 0x16, 0x09, 0x09, 0x16, 0x00, 0x00 }; /* & */
static const uint8_t FMGL_FontTerminusRegular12_QuoteRaster[] = { 0x00, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; /* ' */
static const uint8_t FMGL_FontTerminusRegular12_LeftParenthesisRaster[] = { 0x00, 0x00, 0x08, 0x04, 0x02, 0x02, 0x02, 0x02, 0x04, 0x08, 0x00, 0x00 }; /* ( */
static const uint8_t FMGL_FontTerminusRegular12_RightParenthesisRaster[] = { 0x00, 0x00, 0x02, 0x04, 0x08, 0x08, 0x08, 0x08, 0x04, 0x02, 0x00, 0x00 }; /* ) */
static const uint8_t FMGL_FontTerminusRegular12_AsteriskRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x0A, 0x04, 0x1F, 0x04, 0x0A, 0x00, 0x00, 0x00 }; /* * */
static const uint8_t FMGL_FontTerminusRegular12_PlusRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x1F, 0x04, 0x04, 0x00, 0x00, 0x00 }; /* + */
static const uint8_t FMGL_FontTerminusRegular12_CommaRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x02, 0x00 }; /* , */
static const uint8_t FMGL_FontTerminusRegular12_MinusRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00 }; /* - */
static const uint8_t FMGL_FontTerminusRegular12_DotRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00 }; /* . */
static const uint8_t FMGL_FontTerminusRegular12_SlashRaster[] = { 0x00, 0x00, 0x10, 0x10, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02, 0x00, 0x00 }; /* / */
static const uint8_t FMGL_FontTerminusRegular12_ZeroRaster[] = { 0x00, 0x00, 0x0E, 0x11, 0x19, 0x15, 0x13, 0x11, 0x11, 0x0E, 0x00, 0x00 }; /* 0 */
static const uint8_t FMGL_FontTerminusRegular12_OneRaster[] = { 0x00, 0x00, 0x04, 0x06, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0E, 0x00, 0x00 }; /* 1 */
static const uint8_t FMGL_FontTerminusRegular12_TwoRaster[] = { 0x00, 0x00, 0x0E, 0x11, 0x11, 0x10, 0x08, 0x04, 0x02, 0x1F, 0x00, 0x00 }; /* 2 */
static const uint8_t FMGL_FontTerminusRegular12_ThreeRaster[] = { 0x00, 0x00, 0x0E, 0x11, 0x10, 0x0C, 0x10, 0x10, 0x11, 0x0E, 0x00, 0x00 }; /* 3 */
static const uint8_t FMGL_FontTerminusRegular12_FourRaster[] = { 0x00, 0x00, 0x10, 0x18, 0x14, 0x12, 0x11, 0x1F, 0x10, 0x10, 0x00, 0x00 }; /* 4 */
static const uint8_t FMGL_FontTerminusRegular12_FiveRaster[] = { 0x00, 0x00, 0x1F, 0x01, 0x01, 0x0F, 0x10, 0x10, 0x11, 0x0E, 0x00, 0x00 }; /* 5 */
static const uint8_t FMGL_FontTerminusRegular12_SixRaster[] = { 0x00, 0x00, 0x0E, 0x01, 0x01, 0x0F, 0x11, 0x11, 0x11, 0x0E, 0x00, 0x00 }; /* 6 */
static const uint8_t FMGL_FontTerminusRegular12_SevenRaster[] = { 0x00, 0x00, 0x1F, 0x10, 0x10, 0x08, 0x08, 0x04, 0x04, 0x04, 0x00, 0x00 }; /* 7 */
static const uint8_t FMGL_FontTerminusRegular12_EightRaster[] = { 0x00, 0x00, 0x0E, 0x11, 0x11, 0x0E, 0x11, 0x11, 0x11, 0x0E, 0x00, 0x00 }; /* 8 */
static const uint8_t FMGL_FontTerminusRegular12_NineRaster[] = { 0x00, 0x00, 0x0E, 0x11, 0x11, 0x11, 0x1E, 0x10, 0x10, 0x0E, 0x00, 0x00 }; /* 9 */
static const uint8_t FMGL_FontTerminusRegular12_ColonRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00 }; /* : */
static const uint8_t FMGL_FontTerminusRegular12_SemicolonRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00, 0x04, 0x04, 0x02, 0x00 }; /* ; */
static const uint8_t FMGL_FontTerminusRegular12_LessRaster[] = { 0x00, 0x00, 0x00, 0x10, 0x08, 0x04, 0x02, 0x04, 0x08, 0x10, 0x00, 0x00 }; /* < */
static const uint8_t FMGL_FontTerminusRegular12_EqualRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00 }; /* = */
static const uint8_t FMGL_FontTerminusRegular12_GreaterRaster[] = { 0x00, 0x00, 0x00, 0x02, 0x04, 0x08, 0x10, 0x08, 0x04, 0x02, 0x00, 0x00 }; /* > */
static const uint8_t FMGL_FontTerminusRegular12_QuestionMarkRaster[] = { 0x00, 0x00, 0x0E, 0x11, 0x11, 0x08, 0x04, 0x00, 0x04, 0x04, 0x00, 0x00 }; /* ? */
static const uint8_t FMGL_FontTerminusRegular12_AtRaster[] = { 0x00, 0x00, 0x0E, 0x11, 0x19, 0x15, 0x15, 0x19, 0x01, 0x1E, 0x00, 0x00 }; /* @ */
static const uint8_t FMGL_FontTerminusRegular12_EnCapARaster[] = { 0x00, 0x00, 0x0E, 0x11, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11, 0x00, 0x00 }; /* A */
static const uint8_t FMGL_FontTerminusRegular12_EnCapBRaster[] = { 0x00, 0x00, 0x0F, 0x11, 0x11, 0x0F, 0x11, 0x11, 0x11, 0x0F, 0x00, 0x00 }; /* B */
static const uint8_t FMGL_FontTerminusRegular12_EnCapCRaster[] = { 0x00, 0x00, 0x0E, 0x11, 0x01, 0x01, 0x01, 0x01, 0x11, 0x0E, 0x00, 0x00 }; /* C */
static const uint8_t FMGL_FontTerminusRegular12_EnCapDRaster[] = { 0x00, 0x00, 0x07, 0x09, 0x11, 0x11, 0x11, 0x11, 0x09, 0x07, 0x00, 0x00 }; /* D */
static const uint8_t FMGL_FontTerminusRegular12_EnCapERaster[] = { 0x00, 0x00, 0x1F, 0x01, 0x01, 0x0F, 0x01, 0x01, 0x01, 0x1F, 0x00, 0x00 }; /* E */
static const uint8_t FMGL_FontTerminusRegular12_EnCapFRaster[] = { 0x00, 0x00, 0x1F, 0x01, 0x01, 0x0F, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00 }; /* F */
static const uint8_t FMGL_FontTerminusRegular12_EnCapGRaster[] = { 0x00, 0x00, 0x0E, 0x11, 0x01, 0x01, 0x1D, 0x11, 0x11, 0x0E, 0x00, 0x00 }; /* G */
static const uint8_t FMGL_FontTerminusRegular12_EnCapHRaster[] = { 0x00, 0x00, 0x11, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00 }; /* H */
static const uint8_t FMGL_FontTerminusRegular12_EnCapIRaster[] = { 0x00, 0x00, 0x0E, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0E, 0x00, 0x00 }; /* I */
static const uint8_t FMGL_FontTerminusRegular12_EnCapJRaster[] = { 0x00, 0x00, 0x1C, 0x08, 0x08, 0x08, 0x08, 0x09, 0x09, 0x06, 0x00, 0x00 }; /* J */
static const uint8_t FMGL_FontTerminusRegular12_EnCapKRaster[] = { 0x00, 0x00, 0x11, 0x09, 0x05, 0x03, 0x03, 0x05, 0x09, 0x11, 0x00, 0x00 }; /* K */
static const uint8_t FMGL_FontTerminusRegular12_EnCapLRaster[] = { 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x1F, 0x00, 0x00 }; /* L */
static const uint8_t FMGL_FontTerminusRegular12_EnCapMRaster[] = { 0x00, 0x00, 0x11, 0x1B, 0x15, 0x15, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00 }; /* M */
static const uint8_t FMGL_FontTerminusRegular12_EnCapNRaster[] = { 0x00, 0x00, 0x11, 0x11, 0x13, 0x15, 0x19, 0x11, 0x11, 0x11, 0x00, 0x00 }; /* N */
static const uint8_t FMGL_FontTerminusRegular12_EnCapORaster[] = { 0x00, 0x00, 0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E, 0x00, 0x00 }; /* O */
static const uint8_t FMGL_FontTerminusRegular12_EnCapPRaster[] = { 0x00, 0x00, 0x0F, 0x11, 0x11, 0x11, 0x0F, 0x01, 0x01, 0x01, 0x00, 0x00 }; /* P */
static const uint8_t FMGL_FontTerminusRegular12_EnCapQRaster[] = { 0x00, 0x00, 0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x15, 0x0E, 0x10, 0x00 }; /* Q */
static const uint8_t FMGL_FontTerminusRegular12_EnCapRRaster[] = { 0x00, 0x00, 0x0F, 0x11, 0x11, 0x11, 0x0F, 0x05, 0x09, 0x11, 0x00, 0x00 }; /* R */
static const uint8_t FMGL_FontTerminusRegular12_EnCapSRaster[] = { 0x00, 0x00, 0x0E, 0x11, 0x01, 0x0E, 0x10, 0x10, 0x11, 0x0E, 0x00, 0x00 }; /* S */
static const uint8_t FMGL_FontTerminusRegular12_EnCapTRaster[] = { 0x00, 0x00, 0x1F, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00 }; /* T */
static const uint8_t FMGL_FontTerminusRegular12_EnCapURaster[] = { 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E, 0x00, 0x00 }; /* U */
static const uint8_t FMGL_FontTerminusRegular12_EnCapVRaster[] = { 0x00, 0x00, 0x11, 0x11, 0x11, 0x0A, 0x0A, 0x0A, 0x04, 0x04, 0x00, 0x00 }; /* V */
static const uint8_t FMGL_FontTerminusRegular12_EnCapWRaster[] = { 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x15, 0x15, 0x1B, 0x11, 0x00, 0x00 }; /* W */
static const uint8_t FMGL_FontTerminusRegular12_EnCapXRaster[] = { 0x00, 0x00, 0x11, 0x11, 0x0A, 0x04, 0x04, 0x0A, 0x11, 0x11, 0x00, 0x00 }; /* X */
static const uint8_t FMGL_FontTerminusRegular12_EnCapYRaster[] = { 0x00, 0x00, 0x11, 0x11, 0x0A, 0x0A, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00 }; /* Y */
static const uint8_t FMGL_FontTerminusRegular12_EnCapZRaster[] = { 0x00, 0x00, 0x1F, 0x10, 0x08, 0x04, 0x02, 0x01, 0x01, 0x1F, 0x00, 0x00 }; /* Z */
static const uint8_t FMGL_FontTerminusRegular12_SqareBracketLeftRaster[] = { 0x00, 0x00, 0x0E, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0E, 0x00, 0x00 }; /* [ */
static const uint8_t FMGL_FontTerminusRegular12_BackSlashRaster[] = { 0x00, 0x00, 0x02, 0x02, 0x04, 0x04, 0x08, 0x08, 0x10, 0x10, 0x00, 0x00 }; /* \ */
static const uint8_t FMGL_FontTerminusRegular12_SqareBracketRightRaster[] = { 0x00, 0x00, 0x0E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0E, 0x00, 0x00 }; /* ] */
static const uint8_t FMGL_FontTerminusRegular12_CaretRaster[] = { 0x00, 0x04, 0x0A, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; /* ^ */
static const uint8_t FMGL_FontTerminusRegular12_UnderscoreRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00 }; /* _ */
static const uint8_t FMGL_FontTerminusRegular12_GraveAccentRaster[] = { 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; /* ` */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseARaster[] = { 0x00, 0x00, 0x00, 0x00, 0x0E, 0x10, 0x1E, 0x11, 0x11, 0x1E, 0x00, 0x00 }; /* a */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseBRaster[] = { 0x00, 0x00, 0x01, 0x01, 0x0F, 0x11, 0x11, 0x11, 0x11, 0x0F, 0x00, 0x00 }; /* b */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseCRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x0E, 0x11, 0x01, 0x01, 0x11, 0x0E, 0x00, 0x00 }; /* c */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseDRaster[] = { 0x00, 0x00, 0x10, 0x10, 0x1E, 0x11, 0x11, 0x11, 0x11, 0x1E, 0x00, 0x00 }; /* d */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseERaster[] = { 0x00, 0x00, 0x00, 0x00, 0x0E, 0x11, 0x1F, 0x01, 0x01, 0x1E, 0x00, 0x00 }; /* e */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseFRaster[] = { 0x00, 0x00, 0x18, 0x04, 0x0E, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00 }; /* f */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseGRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x1E, 0x11, 0x11, 0x11, 0x11, 0x1E, 0x10, 0x0E }; /* g */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseHRaster[] = { 0x00, 0x00, 0x01, 0x01, 0x0F, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00 }; /* h */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseIRaster[] = { 0x00, 0x04, 0x04, 0x00, 0x06, 0x04, 0x04, 0x04, 0x04, 0x0E, 0x00, 0x00 }; /* i */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseJRaster[] = { 0x00, 0x10, 0x10, 0x00, 0x18, 0x10, 0x10, 0x10, 0x10, 0x10, 0x12, 0x0C }; /* j */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseKRaster[] = { 0x00, 0x00, 0x02, 0x02, 0x12, 0x0A, 0x06, 0x06, 0x0A, 0x12, 0x00, 0x00 }; /* k */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseLRaster[] = { 0x00, 0x00, 0x06, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0E, 0x00, 0x00 }; /* l */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseMRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x0F, 0x15, 0x15, 0x15, 0x15, 0x15, 0x00, 0x00 }; /* m */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseNRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x0F, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00 }; /* n */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseORaster[] = { 0x00, 0x00, 0x00, 0x00, 0x0E, 0x11, 0x11, 0x11, 0x11, 0x0E, 0x00, 0x00 }; /* o */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCasePRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x0F, 0x11, 0x11, 0x11, 0x11, 0x0F, 0x01, 0x01 }; /* p */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseQRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x1E, 0x11, 0x11, 0x11, 0x11, 0x1E, 0x10, 0x10 }; /* q */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseRRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x1D, 0x03, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00 }; /* r */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseSRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x1E, 0x01, 0x0E, 0x10, 0x10, 0x0F, 0x00, 0x00 }; /* s */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseTRaster[] = { 0x00, 0x00, 0x04, 0x04, 0x0E, 0x04, 0x04, 0x04, 0x04, 0x18, 0x00, 0x00 }; /* t */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseURaster[] = { 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1E, 0x00, 0x00 }; /* u */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseVRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x0A, 0x0A, 0x04, 0x04, 0x00, 0x00 }; /* v */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseWRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x15, 0x15, 0x15, 0x0E, 0x00, 0x00 }; /* w */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseXRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x11, 0x0A, 0x04, 0x04, 0x0A, 0x11, 0x00, 0x00 }; /* x */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseYRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1E, 0x10, 0x0E }; /* y */
static const uint8_t FMGL_FontTerminusRegular12_EnLowCaseZRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x1F, 0x08, 0x04, 0x02, 0x01, 0x1F, 0x00, 0x00 }; /* z */
static const uint8_t FMGL_FontTerminusRegular12_CurlyBracketLeftRaster[] = { 0x00, 0x00, 0x18, 0x04, 0x04, 0x02, 0x04, 0x04, 0x04, 0x18, 0x00, 0x00 }; /* { */
static const uint8_t FMGL_FontTerminusRegular12_VerticalBarRaster[] = { 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00 }; /* | */
static const uint8_t FMGL_FontTerminusRegular12_CurlyBracketRightRaster[] = { 0x00, 0x00, 0x06, 0x08, 0x08, 0x10, 0x08, 0x08, 0x08, 0x06, 0x00, 0x00 }; /* } */
static const uint8_t FMGL_FontTerminusRegular12_TildeRaster[] = { 0x00, 0x12, 0x15, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; /* ~ */

static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseIURaster[] = { 0x00, 0x00, 0x00, 0x00, 0x09, 0x15, 0x15, 0x17, 0x15, 0x09, 0x00, 0x00 }; /* ю */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseARaster[] = { 0x00, 0x00, 0x00, 0x00, 0x0E, 0x10, 0x1E, 0x11, 0x11, 0x1E, 0x00, 0x00 }; /* а */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseBeRaster[] = { 0x00, 0x00, 0x0E, 0x01, 0x0F, 0x11, 0x11, 0x11, 0x11, 0x0F, 0x00, 0x00 }; /* б */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseTseRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x3E, 0x20, 0x20 }; /* ц */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseDeRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x1E, 0x11, 0x11, 0x11, 0x11, 0x1E, 0x10, 0x0E }; /* д */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseIeRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x0E, 0x11, 0x1F, 0x01, 0x01, 0x1E, 0x00, 0x00 }; /* е */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseEfRaster[] = { 0x00, 0x00, 0x00, 0x04, 0x0E, 0x15, 0x15, 0x15, 0x15, 0x0E, 0x04, 0x00 }; /* ф */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseGeRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x1F, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00 }; /* г */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseKhaRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x11, 0x0A, 0x04, 0x04, 0x0A, 0x11, 0x00, 0x00 }; /* х */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseIiRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1E, 0x00, 0x00 }; /* и */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseShortIiRaster[] = { 0x00, 0x00, 0x0A, 0x04, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1E, 0x00, 0x00 }; /* й */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseKaRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x12, 0x0A, 0x06, 0x06, 0x0A, 0x12, 0x00, 0x00 }; /* к */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseElRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x1C, 0x12, 0x12, 0x12, 0x12, 0x11, 0x00, 0x00 }; /* л */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseEmRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x11, 0x1B, 0x15, 0x11, 0x11, 0x11, 0x00, 0x00 }; /* м */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseEnRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11, 0x00, 0x00 }; /* н */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseORaster[] = { 0x00, 0x00, 0x00, 0x00, 0x0E, 0x11, 0x11, 0x11, 0x11, 0x0E, 0x00, 0x00 }; /* о */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCasePeRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x1F, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00 }; /* п */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseIaRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x1E, 0x11, 0x11, 0x1E, 0x14, 0x12, 0x00, 0x00 }; /* я */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseErRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x0F, 0x11, 0x11, 0x11, 0x11, 0x0F, 0x01, 0x01 }; /* р */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseEsRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x0E, 0x11, 0x01, 0x01, 0x11, 0x0E, 0x00, 0x00 }; /* с */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseTeRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x1F, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00 }; /* т */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseURaster[] = { 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1E, 0x10, 0x0E }; /* у */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseZheRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x15, 0x15, 0x0E, 0x15, 0x15, 0x15, 0x00, 0x00 }; /* ж */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseVeRaster[] = { 0x00, 0x00, 0x07, 0x09, 0x09, 0x0F, 0x11, 0x11, 0x11, 0x0F, 0x00, 0x00 }; /* в */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseSoftSignRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x0E, 0x12, 0x12, 0x0E, 0x00, 0x00 }; /* ь */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseYeriRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x13, 0x15, 0x15, 0x13, 0x00, 0x00 }; /* ы */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseZeRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x0E, 0x11, 0x0C, 0x10, 0x11, 0x0E, 0x00, 0x00 }; /* з */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseShaRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x15, 0x15, 0x15, 0x15, 0x15, 0x1E, 0x00, 0x00 }; /* ш */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseReversedERaster[] = { 0x00, 0x00, 0x00, 0x00, 0x0E, 0x11, 0x1C, 0x10, 0x11, 0x0E, 0x00, 0x00 }; /* э */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseShchaRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x15, 0x15, 0x15, 0x15, 0x15, 0x3E, 0x20, 0x20 }; /* щ */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseCheRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x1E, 0x10, 0x10, 0x00, 0x00 }; /* ч */
static const uint8_t FMGL_FontTerminusRegular12_CyrLowCaseHardSignRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x0E, 0x12, 0x12, 0x0E, 0x00, 0x00 }; /* ъ */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapIURaster[] = { 0x00, 0x00, 0x09, 0x15, 0x15, 0x15, 0x17, 0x15, 0x15, 0x09, 0x00, 0x00 }; /* Ю */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapARaster[] = { 0x00, 0x00, 0x0E, 0x11, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11, 0x00, 0x00 }; /* А */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapBeRaster[] = { 0x00, 0x00, 0x0F, 0x01, 0x01, 0x0F, 0x11, 0x11, 0x11, 0x0F, 0x00, 0x00 }; /* Б */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapTseRaster[] = { 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x3E, 0x20, 0x20 }; /* Ц */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapDeRaster[] = { 0x00, 0x00, 0x1C, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x3F, 0x21, 0x00 }; /* Д */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapIeRaster[] = { 0x00, 0x00, 0x1F, 0x01, 0x01, 0x0F, 0x01, 0x01, 0x01, 0x1F, 0x00, 0x00 }; /* Е */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapEfRaster[] = { 0x00, 0x04, 0x0E, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x0E, 0x04, 0x00 }; /* Ф */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapGeRaster[] = { 0x00, 0x00, 0x1F, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00 }; /* Г */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapKhaRaster[] = { 0x00, 0x00, 0x11, 0x11, 0x0A, 0x04, 0x04, 0x0A, 0x11, 0x11, 0x00, 0x00 }; /* Х */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapIiRaster[] = { 0x00, 0x00, 0x11, 0x11, 0x19, 0x15, 0x13, 0x11, 0x11, 0x11, 0x00, 0x00 }; /* И */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapShortIiRaster[] = { 0x0A, 0x04, 0x11, 0x11, 0x19, 0x15, 0x13, 0x11, 0x11, 0x11, 0x00, 0x00 }; /* Й */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapKaRaster[] = { 0x00, 0x00, 0x11, 0x09, 0x05, 0x03, 0x03, 0x05, 0x09, 0x11, 0x00, 0x00 }; /* К */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapElRaster[] = { 0x00, 0x00, 0x1C, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x11, 0x00, 0x00 }; /* Л */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapEmRaster[] = { 0x00, 0x00, 0x11, 0x1B, 0x15, 0x15, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00 }; /* М */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapEnRaster[] = { 0x00, 0x00, 0x11, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00 }; /* Н */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapORaster[] = { 0x00, 0x00, 0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E, 0x00, 0x00 }; /* О */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapPeRaster[] = { 0x00, 0x00, 0x1F, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00 }; /* П */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapIaRaster[] = { 0x00, 0x00, 0x1E, 0x11, 0x11, 0x11, 0x1E, 0x14, 0x12, 0x11, 0x00, 0x00 }; /* Я */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapErRaster[] = { 0x00, 0x00, 0x0F, 0x11, 0x11, 0x11, 0x0F, 0x01, 0x01, 0x01, 0x00, 0x00 }; /* Р */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapEsRaster[] = { 0x00, 0x00, 0x0E, 0x11, 0x01, 0x01, 0x01, 0x01, 0x11, 0x0E, 0x00, 0x00 }; /* С */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapTeRaster[] = { 0x00, 0x00, 0x1F, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00 }; /* Т */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapURaster[] = { 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1E, 0x10, 0x10, 0x0E, 0x00, 0x00 }; /* У */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapZheRaster[] = { 0x00, 0x00, 0x15, 0x15, 0x15, 0x0E, 0x0E, 0x15, 0x15, 0x15, 0x00, 0x00 }; /* Ж */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapVeRaster[] = { 0x00, 0x00, 0x0F, 0x11, 0x11, 0x0F, 0x11, 0x11, 0x11, 0x0F, 0x00, 0x00 }; /* В */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapSoftSignRaster[] = { 0x00, 0x00, 0x02, 0x02, 0x0E, 0x12, 0x12, 0x12, 0x12, 0x0E, 0x00, 0x00 }; /* Ь */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapYeriRaster[] = { 0x00, 0x00, 0x11, 0x11, 0x13, 0x15, 0x15, 0x15, 0x15, 0x13, 0x00, 0x00 }; /* Ы */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapZeRaster[] = { 0x00, 0x00, 0x0E, 0x11, 0x10, 0x0C, 0x10, 0x10, 0x11, 0x0E, 0x00, 0x00 }; /* З */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapShaRaster[] = { 0x00, 0x00, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x1E, 0x00, 0x00 }; /* Ш */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapReversedERaster[] = { 0x00, 0x00, 0x0E, 0x11, 0x10, 0x1C, 0x10, 0x10, 0x11, 0x0E, 0x00, 0x00 }; /* Э */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapShchaRaster[] = { 0x00, 0x00, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x3E, 0x20, 0x20 }; /* Щ */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapCheRaster[] = { 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1E, 0x10, 0x10, 0x10, 0x00, 0x00 }; /* Ч */
static const uint8_t FMGL_FontTerminusRegular12_CyrCapHardSignRaster[] = { 0x00, 0x00, 0x03, 0x02, 0x0E, 0x12, 0x12, 0x12, 0x12, 0x0E, 0x00, 0x00 }; /* Ъ */

static const uint8_t FMGL_FontTerminusRegular12_FormsLtHorizRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; /* Forms light horizontal */
static const uint8_t FMGL_FontTerminusRegular12_FormsLtVertRaster[] = { 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04 }; /* Forms light vertical */
static const uint8_t FMGL_FontTerminusRegular12_FormsLtDownRightRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04 }; /* Forms light down and right */
static const uint8_t FMGL_FontTerminusRegular12_FormsLtDownLeftRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04 }; /* Forms light down and left */
static const uint8_t FMGL_FontTerminusRegular12_FormsLtUpRightRaster[] = { 0x04, 0x04, 0x04, 0x04, 0x04, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; /* Forms light up and right */
static const uint8_t FMGL_FontTerminusRegular12_FormsLtUpLeftRaster[] = { 0x04, 0x04, 0x04, 0x04, 0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; /* Forms light up and left */
static const uint8_t FMGL_FontTerminusRegular12_FormsLtVertRightRaster[] = { 0x04, 0x04, 0x04, 0x04, 0x04, 0x3C, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04 }; /* Forms light vertical and right */
static const uint8_t FMGL_FontTerminusRegular12_FormsLtVertLeftRaster[] = { 0x04, 0x04, 0x04, 0x04, 0x04, 0x07, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04 }; /* Forms light vertical and left */
static const uint8_t FMGL_FontTerminusRegular12_FormsLtHorizDownRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04 }; /* Forms light down and horizontal */
static const uint8_t FMGL_FontTerminusRegular12_FormsLtHorizUpRaster[] = { 0x04, 0x04, 0x04, 0x04, 0x04, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; /* Forms light up and horizontal */
static const uint8_t FMGL_FontTerminusRegular12_FormsLtVertHorizRaster[] = { 0x04, 0x04, 0x04, 0x04, 0x04, 0x3F, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04 }; /* Forms light vertical and horizontal */
static const uint8_t FMGL_FontTerminusRegular12_HfBlockUpRaster[] = { 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; /* Upper half block */
static const uint8_t FMGL_FontTerminusRegular12_HfBlockLowRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F }; /* Lower half block */
static const uint8_t FMGL_FontTerminusRegular12_FullBlockRaster[] = { 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F }; /* Full block */
static const uint8_t FMGL_FontTerminusRegular12_HfBlockLeftRaster[] = { 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07 }; /* Left half block */
static const uint8_t FMGL_FontTerminusRegular12_HfBlockRightRaster[] = { 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38 }; /* Right half block */
static const uint8_t FMGL_FontTerminusRegular12_ShadeLightRaster[] = { 0x09, 0x24, 0x09, 0x24, 0x09, 0x24, 0x09, 0x24, 0x09, 0x24, 0x09, 0x24 }; /* Light shade */
static const uint8_t FMGL_FontTerminusRegular12_ShadeMediumRaster[] = { 0x15, 0x2A, 0x15, 0x2A, 0x15, 0x2A, 0x15, 0x2A, 0x15, 0x2A, 0x15, 0x2A }; /* Medium shade */
static const uint8_t FMGL_FontTerminusRegular12_ShadeDarkRaster[] = { 0x1B, 0x2D, 0x1B, 0x2D, 0x1B, 0x2D, 0x1B, 0x2D, 0x1B, 0x2D, 0x1B, 0x2D }; /* Dark shade */
static const uint8_t FMGL_FontTerminusRegular12_HfIntegralTopRaster[] = { 0x00, 0x00, 0x08, 0x14, 0x14, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04 }; /* Top half integral */
static const uint8_t FMGL_FontTerminusRegular12_BlackSmallSquareRaster[] = { 0x00, 0x00, 0x00, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x00, 0x00, 0x00, 0x00 }; /* Black small square */
static const uint8_t FMGL_FontTerminusRegular12_BulletRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x0C, 0x1E, 0x1E, 0x0C, 0x00, 0x00, 0x00, 0x00 }; /* Bullet operator */
static const uint8_t FMGL_FontTerminusRegular12_SqrtRaster[] = { 0x00, 0x30, 0x10, 0x10, 0x10, 0x11, 0x11, 0x12, 0x14, 0x18, 0x00, 0x00 }; /* Square root */
static const uint8_t FMGL_FontTerminusRegular12_AlmostEqualRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x16, 0x0D, 0x00, 0x16, 0x0D, 0x00, 0x00, 0x00 }; /* Almost equal to */
static const uint8_t FMGL_FontTerminusRegular12_LessOrEquRaster[] = { 0x00, 0x08, 0x04, 0x02, 0x01, 0x02, 0x04, 0x08, 0x00, 0x1F, 0x00, 0x00 }; /* Less than or equal to */
static const uint8_t FMGL_FontTerminusRegular12_GreaterOrEquRaster[] = { 0x00, 0x02, 0x04, 0x08, 0x10, 0x08, 0x04, 0x02, 0x00, 0x1F, 0x00, 0x00 }; /* Greater than or equal to */
static const uint8_t FMGL_FontTerminusRegular12_HfIntegralBottomRaster[] = { 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x05, 0x05, 0x02, 0x00, 0x00 }; /* Bottom half integral */
static const uint8_t FMGL_FontTerminusRegular12_DegreeSignRaster[] = { 0x00, 0x04, 0x0A, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; /* Degree sign */
static const uint8_t FMGL_FontTerminusRegular12_SuperscriptTwoRaster[] = { 0x00, 0x0C, 0x12, 0x08, 0x04, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; /* Superscript digit two */
static const uint8_t FMGL_FontTerminusRegular12_MiddleDotRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00 }; /* Middle dot */
static const uint8_t FMGL_FontTerminusRegular12_DivisionSignRaster[] = { 0x00, 0x00, 0x00, 0x04, 0x04, 0x00, 0x1F, 0x00, 0x04, 0x04, 0x00, 0x00 }; /* Division sign */

#endif /* FMGL_INCLUDE_FONTS_TERMINUSREGULAR12_H_ */
