#ifndef FMGL_INCLUDE_FONTS_TERMINUSREGULAR12_H_
#define FMGL_INCLUDE_FONTS_TERMINUSREGULAR12_H_

/**
 * Terminus font, regular, 6x12 pixels
 */

#include "fmgl.h"

/**
 * Call this function to get font instance.
 */

FMGL_Font FMGL_FontTerminusRegular12Init(void);

/* Basic font settings */
FMGL_Font FMGL_FontTerminusRegular12;

/*************************
 * Characters going here *
 *************************/

/* Space */
FMGL_FontCharacter FMGL_FontTerminusRegular12_Space;
static const uint8_t FMGL_FontTerminusRegular12_SpaceRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00 };

/* ! */
FMGL_FontCharacter FMGL_FontTerminusRegular12_EclamationMark;
static const uint8_t FMGL_FontTerminusRegular12_EclamationMarkRaster[] = { 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x04, 0x04, 0x00, 0x00 };

/* " */
FMGL_FontCharacter FMGL_FontTerminusRegular12_DoubleQuotes;
static const uint8_t FMGL_FontTerminusRegular12_DoubleQuotesRaster[] = { 0x00, 0x0A, 0x0A, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

/* # */
FMGL_FontCharacter FMGL_FontTerminusRegular12_Sharp;
static const uint8_t FMGL_FontTerminusRegular12_SharpRaster[] = { 0x00, 0x00, 0x0A, 0x0A, 0x1F, 0x0A, 0x0A, 0x1F, 0x0A, 0x0A, 0x00, 0x00 };

/* $ */
FMGL_FontCharacter FMGL_FontTerminusRegular12_Dollar;
static const uint8_t FMGL_FontTerminusRegular12_DollarRaster[] = { 0x00, 0x00, 0x04, 0x0E, 0x15, 0x05, 0x0E, 0x14, 0x15, 0x0E, 0x04, 0x00 };

/* % */
FMGL_FontCharacter FMGL_FontTerminusRegular12_Percent;
static const uint8_t FMGL_FontTerminusRegular12_PercentRaster[] = { 0x00, 0x00, 0x12, 0x15, 0x0A, 0x08, 0x04, 0x14, 0x2A, 0x12, 0x00, 0x00 };

/* & */
FMGL_FontCharacter FMGL_FontTerminusRegular12_Ampersand;
static const uint8_t FMGL_FontTerminusRegular12_AmpersandRaster[] = { 0x00, 0x00, 0x04, 0x0A, 0x0A, 0x04, 0x16, 0x09, 0x09, 0x16, 0x00, 0x00 };

/* ' */
FMGL_FontCharacter FMGL_FontTerminusRegular12_Quote;
static const uint8_t FMGL_FontTerminusRegular12_QuoteRaster[] = { 0x00, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

/* ( */
FMGL_FontCharacter FMGL_FontTerminusRegular12_LeftParenthesis;
static const uint8_t FMGL_FontTerminusRegular12_LeftParenthesisRaster[] = { 0x00, 0x00, 0x08, 0x04, 0x02, 0x02, 0x02, 0x02, 0x04, 0x08, 0x00, 0x00 };

/* ) */
FMGL_FontCharacter FMGL_FontTerminusRegular12_RightParenthesis;
static const uint8_t FMGL_FontTerminusRegular12_RightParenthesisRaster[] = { 0x00, 0x00, 0x02, 0x04, 0x08, 0x08, 0x08, 0x08, 0x04, 0x02, 0x00, 0x00 };

/* * */
FMGL_FontCharacter FMGL_FontTerminusRegular12_Asterisk;
static const uint8_t FMGL_FontTerminusRegular12_AsteriskRaster[] = { 0x00, 0x00, 0x00, 0x00, 0x0A, 0x04, 0x1F, 0x04, 0x0A, 0x00, 0x00, 0x00 };

#endif /* FMGL_INCLUDE_FONTS_TERMINUSREGULAR12_H_ */
