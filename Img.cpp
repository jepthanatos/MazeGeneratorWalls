//============================================================================
// Name        : Img.cpp
// Author      :
// Version     :
// Copyright   :
// Description : File to wrap CImg library.
//============================================================================

#include "Img.h"


//==============================================================================
/* Img */
//==============================================================================

/*------------------------------------------------------------------------------
 * Constructor.
 */
Img::Img(int w, int h, std::string title) :
	img(w, h, 1, 3), disp(img, title.c_str(), 0)
{
	// We move the display to our defaults position.
	disp.move(200, 200);
}

/*------------------------------------------------------------------------------
 * Function to get the height.
 */
int Img::getHeight() const {
    return img.height();
}

/*------------------------------------------------------------------------------
 * Function to get the width.
 */
int Img::getWidth() const {
    return img.width();
}

/*------------------------------------------------------------------------------
 * Function to know if the image is closed.
 */
bool Img::isClosed() const {
    return disp.is_closed();
}

/*------------------------------------------------------------------------------
 * Procedure to set the title of the window.
 */
void Img::setTitle(const char* title) {
    disp.set_title(title);
}

/*------------------------------------------------------------------------------
 * Procedure to draw a point.
 */
void Img::drawPoint(int col, int row, float* color) {
    img.draw_point(col, row, color);
}

/*------------------------------------------------------------------------------
 * Procedure to draw a circle.
 */
void Img::drawCircle(int col, int row, float* color)
{
	img.draw_circle(col, row, 500, color, 0.5f);
}

/*------------------------------------------------------------------------------
 * Procedure to draw a line.
 */
void Img::drawLine(int x0, int y0, int x1, int y1, float* color)
{
	img.draw_line(x0, y0, x1, y1, color);
}

/*------------------------------------------------------------------------------
 * Procedure to draw a rectangle.
 */
void Img::drawRectangle(const int x0, const int y0, const int x1, const int y1, float* color, const float opacity){
	img.draw_rectangle(x0,y0,x1,y1,color,opacity);
}

/*------------------------------------------------------------------------------
 * Procedure to display the image.
 */
void Img::display() {
    disp.display(img);
}

/*------------------------------------------------------------------------------
 * Function to know if the left mouse button has been clicked.
 * Returns true (false) if the left mouse button has (not) been clicked.
 */
bool Img::mouseClick(){
	return disp.button()&1;
}

//==============================================================================

