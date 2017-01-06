#include "Square.h"
#include "Collision.h"
#include <iostream>

/** CONSTRUCTORS & DESTRUCTOR **/

/**
 *	Default constructor
 */
Square::Square(void) 
	: Shape() {
	this->length = 0;
}

/**
 *	Constructor with explicit x, y, length values
 */
Square::Square(const float x, const float y, const float length) 
	: Shape(x, y, length, length) {
	this->length = length;
}

/**
 *	Copy constructor
 */
Square::Square(const Square& copy) {
		pos.left = copy.pos.left;
		pos.top = copy.pos.top;
		pos.right = copy.pos.right;
		pos.bottom = copy.pos.bottom;
		length = copy.length;
}

/**
 *	Destructor
 */
Square::~Square(void) {
}

/** MEMBER FUNCTIONS **/

/**
 *	As we cant make the << operator virtual in the base class this function
 *	gets an ostream passed in and just calls this classes own << overload so
 *	we can print out the square output.
 */
std::ostream& Square::print(std::ostream& o) const {
	o << *this;
	return o;
}

/**
 *	Checks the run time type ID for the shape being passed in and 
 *	calls the correct collision method in the Collision class respectivly
 */
bool Square::isCollision(const Shape &shape) const {
	try {
		if(typeid(shape) == typeid(Square)) {
			return Collision::isCollision(dynamic_cast<const Square&>(shape), *this);
		} else if(typeid(shape) == typeid(Circle)) {
			return Collision::isCollision(dynamic_cast<const Circle&>(shape), *this);
		}else {
			throw "Error: Cannot define derived shape type";
		}
	} catch (char const* &e) {
		std::cout << e;
	}
	return false;
}

/** OPERATOR OVERLOADS **/

/**
 *	Overloads assignment operator
 */
Square& Square::operator=(const Square &square) {
	if(this != &square) {
		pos.left = square.pos.left;
		pos.top = square.pos.top;
		pos.right = square.pos.right;
		pos.bottom = square.pos.bottom;
		length = square.length;
	}
	return *this;
}

/**
 *	Overloads ostream operator
 */
std::ostream& operator<<(std::ostream& o, const Square& square) {
	o << "SQUARE" << std::endl << 
		 "Position[Top: " << square.pos.top << " , Right: " << square.pos.right << " , Bottom: " << square.pos.bottom << " , Left: " << square.pos.left << "]" << std::endl <<
		 "Length[" << square.length << "]" << std::endl <<
		 "Origin[X: " << square.getOriginX() << " , Y: " << square.getOriginY() << "]" << std::endl;
	return o;
}
