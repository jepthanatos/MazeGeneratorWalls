//============================================================================
// Name        : Img.h
// Author      : Jorge
// Version     : 0.1
// Copyright   :
// Description : File to wrap CImg library.
//============================================================================

#ifndef IMG_H_
#define IMG_H_

#include <string>

// Local includes.
#include "CImg.h"

//==============================================================================
/* Img */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to wrap CImg library.
 */
class Img {

public:

	// Constructor.
    Img(int w, int h, std::string title);

    // Functions to get the height and width of the image.
    int getHeight() const;
    int getWidth() const;

    // Function to know if the image is closed.
    bool isClosed() const;

    // Procedure to set the title of the window.
    void setTitle(const char* title);

    // Draw procedures.
    void drawPoint(int col, int row, float* color);
    void drawCircle(int col, int row, float* color);
    void drawLine(int x0, int y0, int x1, int y1, float* color);
    void drawRectangle(const int x0, const int y0, const int x1, const int y1, float* color, const float opacity=1);

    // Procedure to display the image.
    void display();

    // Function to know if the left mouse button has been clicked.
    // Returns true (false) if the left mouse button has (not) been clicked.
    bool mouseClick();

private:

    cimg_library::CImg<float> img;
    cimg_library::CImgDisplay disp;

};

//------------------------------------------------------------------------------
#endif /* IMG_H_ */
