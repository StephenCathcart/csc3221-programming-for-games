#include "Shape.h"
#include <iostream>

/** CONSTRUCTORS & DESTRUCTOR **/

/**
 *	Default constructor
 */
Shape::Shape(void) {
	pos.top = 0;
	pos.bottom = 0;
	pos.left = 0;
	pos.right = 0;
	increaseXBounds = true;
	increaseYBounds = true;
}

/**
 *	Constructor with explicit x, y, width & height values
 */
Shape::Shape(const float x, const float y, const float width, const float height) {
	pos.top = y + height;
	pos.bottom = y;
	pos.left = x;
	pos.right = x + width;
	increaseXBounds = true;
	increaseYBounds = true;
}

/**
 *	Destructor
 */
Shape::~Shape(void) {
}

/** MEMBER FUNCTIONS **/

/**
 *	Updates the shape with the x and y values passed in
 */
void Shape::move(const float x, const float y) {
	pos.top += y;
	pos.bottom += y;
	pos.left += x;
	pos.right += x;
}

/** OPERATOR OVERLOADS **/

/**
 *	Overloads equal operator
 */
bool Shape::operator==(const Shape &square) const {
	return (this == &square) ? true : false;
}

/**
 *	Overloads not equal operator
 */
bool Shape::operator!=(const Shape &square) const {
	return (this == &square) ? false : true;
}