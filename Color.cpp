//============================================================================
// Name        : Color.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : File to define RGB colors used by CImg library.
//============================================================================

#include "Color.h"

//==============================================================================
/* Color */
//==============================================================================

/*------------------------------------------------------------------------------
 * Constructor.
 */
Color::Color(void) : r{0.f}, g{0.f}, b{0.f} {}

/*------------------------------------------------------------------------------
 * Constructor.
 */
Color::Color(float _r, float _g, float _b) : r{_r}, g{_g}, b{_b} {}

/*------------------------------------------------------------------------------
 * Function to define blue.
 */
const Color &Color::blue(void) {
	static const Color color(0, 191, 255);
	return color;
}

/*------------------------------------------------------------------------------
 * Function to define black.
 */
const Color &Color::black(void){
	static const Color color(0, 0, 0);
	return color;
}

/*------------------------------------------------------------------------------
 * Function to define yellow.
 */
const Color &Color::yellow(void){
	static const Color color(255, 255, 225);
	return color;
}

/*------------------------------------------------------------------------------
 * Function to define red.
 */
const Color &Color::red(void){
	static const Color color(250, 0, 0);
	return color;
}

//==============================================================================
