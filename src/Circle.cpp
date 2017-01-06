#include "Circle.h"
#include "Collision.h"
#include <iostream>

/** CONSTRUCTORS & DESTRUCTOR **/

/**
 *	Default constructor
 */
Circle::Circle(void) 
	: Shape() {
	this->diameter = 0;
	this->radius = 0;
}

/**
 *	Constructor with explicit x, y, diameter values
 */
Circle::Circle(const float x, const float y, const float diameter) 
	: Shape(x, y, diameter, diameter) {
	this->diameter = diameter;
	this->radius = diameter / 2;
}

/**
 *	Copy constructor
 */
Circle::Circle(const Circle& copy) {
		pos.left = copy.pos.left;
		pos.top = copy.pos.top;
		pos.right = copy.pos.right;
		pos.bottom = copy.pos.bottom;
		diameter = copy.diameter;
		radius = copy.radius;
}

/**
 *	Destructor
 */
Circle::~Circle(void) {
}

/** MEMBER FUNCTIONS **/

/**
 *	As we cant make the << operator virtual in the base class this function
 *	gets an ostream passed in and just calls this classes own << overload so
 *	we can print out the circles output.
 */
std::ostream& Circle::print(std::ostream& o) const {
	o << *this;
	return o;
}

/**
 *	Checks the run time type ID for the shape being passed in and 
 *	calls the correct collision method in the Collision class respectivly
 */
bool Circle::isCollision(const Shape &shape) const {
	try {
		if(typeid(shape) == typeid(Square)) {
			return Collision::isCollision(*this, dynamic_cast<const Square&>(shape));
		} else if(typeid(shape) == typeid(Circle)) {
			return Collision::isCollision(dynamic_cast<const Circle&>(shape), *this);
		}else {
			throw "Error: Cannot define derived shape type";
		}
	}catch (char const* &e) {
		std::cout << e;
	}
	return false;
}

/** OPERATOR OVERLOADS **/

/**
 *	Overloads assignment operator
 */
Circle& Circle::operator=(const Circle &circle) {
	if(this != &circle){
		pos.left = circle.pos.left;
		pos.top = circle.pos.top;
		pos.right = circle.pos.right;
		pos.bottom = circle.pos.bottom;
		diameter = circle.diameter;
		radius = circle.radius;
	}
	return *this;
}

/**
 *	Overloads ostream operator
 */
std::ostream& operator<<(std::ostream& o, const Circle& circle) {
	o << "CIRCLE" << std::endl << 
		 "Position[Top: " << circle.pos.top << " , Right: " << circle.pos.right << " , Bottom: " << circle.pos.bottom << " , Left: " << circle.pos.left << "]" << std::endl <<
		 "Diameter[" << circle.diameter << "]" << std::endl <<
		 "Radius[" << circle.radius << "]" << std::endl <<
		 "Origin[X: " << circle.getOriginX() << " , Y: " << circle.getOriginY() << "]" << std::endl;
	return o;
}