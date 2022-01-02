//============================================================================
// Name        : Color.h
// Author      : Jorge
// Version     : 0.1
// Copyright   :
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
	Color(uint8_t _r, uint8_t _g, uint8_t _b);
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
