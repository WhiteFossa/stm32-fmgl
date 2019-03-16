#ifndef __MAIN_H
#define __MAIN_H

#include <l2hal.h>
#include <fmgl.h>
#include <terminusRegular12.h>
#include "Awesome.h"

/**
 * FMGL context.
 */
FMGL_API_DriverContext fmglContext;

/**
 * Draws background text with given font.
 * @param fontSettings Pointer to font settings.
 */
void DrawBackgroundText(FMGL_API_FontSettings* fontSettings);

#endif /* __MAIN_H */
