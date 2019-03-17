#ifndef __MAIN_H
#define __MAIN_H

#include <l2hal.h>
#include <fmgl.h>
#include <terminusRegular12.h>
#include "Awesome.h"

/**
 * Number of drawing cycles before inverting font.
 */
#define FONT_BLINKING_INTERVAL 10U

/**
 * FMGL context.
 */
FMGL_API_DriverContext fmglContext;

/**
 * Normal font (white on black).
 */
FMGL_API_FontSettings normalFont;


/**
 * Inverted font (black on white).
 */
FMGL_API_FontSettings invertedFont;

/**
 * Current font (for text blinking).
 */
FMGL_API_FontSettings* currentFont;

/**
 * Draws background text with given font.
 * @param fontSettings Pointer to font settings.
 */
void DrawBackgroundText(FMGL_API_FontSettings* fontSettings);

#endif /* __MAIN_H */
