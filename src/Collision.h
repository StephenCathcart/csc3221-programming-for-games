#ifndef COLLISION_H
#define COLLISION_H

#include "Square.h"
#include "Circle.h"

/**
 *	Class which contains the logic for square/square, circle/circle &
 *	circle/square collison. 
 */
class Collision {
public:
	~Collision(void);

	static bool isCollision(const Square &squareOne, const Square &squareTwo);
	static bool isCollision(const Circle &circleOne, const Circle &circleTwo);
	static bool isCollision(const Circle &circle, const Square &square);

private:
/**
 *	We declare the constructor as private as this is a static only use class to
 *	call collision detection on
 */
	Collision(void);
};

#endif
