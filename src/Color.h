//============================================================================
// Name        : Color.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : File to define RGB colors used by CImg library.
//============================================================================

#ifndef COLOR_H_
#define COLOR_H_

#include <cstdint>

//==============================================================================
/* Color */
//==============================================================================

class Color {
public:
	// Constructors and destructor.
	Color(void);
	Color(float _r, float _g, float _b);
	~Color(void) {}

	// Predefined colors.
	static const Color &blue(void);
	static const Color &black(void);
	static const Color &yellow(void);
	static const Color &red(void);

private:
	float r;
	float g;
	float b;
};

//------------------------------------------------------------------------------
#endif /* COLOR_H_ */
