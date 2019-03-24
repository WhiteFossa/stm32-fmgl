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

#ifndef __MAIN_H
#define __MAIN_H

#include <l2hal.h>
#include <fmgl.h>
#include <terminusRegular12.h>
#include <Awesome.h>

/**
 * Number of drawing cycles before inverting font.
 */
#define FONT_BLINKING_INTERVAL 5U

/**
 * Sprite movement speed.
 */
#define SPRITE_SPEED_X 3
#define SPRITE_SPEED_Y 4

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
 * Sprite to draw.
 */
FMGL_API_XBMImage sprite;

/**
 * Draws background text with given font.
 * @param fontSettings Pointer to font settings.
 */
void DrawBackgroundText(FMGL_API_FontSettings* fontSettings);

#endif /* __MAIN_H */
