#include "Collision.h"
#include "Square.h"
#include <math.h> 
#include <iostream>

/** CONSTRUCTORS & DESTRUCTOR **/

/**
 *	Default constructor
 */
Collision::Collision(void) {
}

/**
 *	Destructor
 */
Collision::~Collision(void) {
}

/**
 *	Basic square on square collision detection; we check the top, left, bottom and right sides
 *	against the other square. If all statements are true we have a collison.
 */
bool Collision::isCollision(const Square &squareOne, const Square &squareTwo) {
	return squareOne.getLeft() < squareTwo.getRight() && squareOne.getRight() > squareTwo.getLeft() &&
		   squareOne.getBottom() < squareTwo.getTop() && squareOne.getTop() > squareTwo.getBottom();
}

/**
 *	Basic circle on circle collision detection; if the distance between the two origins is less than
 *	the sum of the two radii then we have a collision.
 */
bool Collision::isCollision(const Circle &circleOne, const Circle &circleTwo) {
	float radius = circleOne.getRadius() + circleTwo.getRadius();
	float deltaX = circleOne.getOriginX() - circleTwo.getOriginX();
	float deltaY = circleOne.getOriginY() - circleTwo.getOriginY();

	return (deltaX * deltaX + deltaY * deltaY) <= (radius * radius);
}

/**
 *	As this was a tricky method to work out I have referenced the forum from which I based
 *	this code on:
 *	http://stackoverflow.com/questions/401847/circle-rectangle-collision-detection-intersection
 */
bool Collision::isCollision(const Circle &circle, const Square &square) {
	// Calculate the absolute values of the x and y difference between the center of the circle and the center of the rectangle.
	float circleDistanceX = abs(circle.getLeft() - square.getLeft());
	float circleDistanceY = abs(circle.getBottom() - square.getBottom());

	// Eliminate the easy cases where the circle is far enough away from the rectangle (in either direction) that no intersection is possible.
	if (circleDistanceX > (square.getLength()/2 + circle.getRadius())) { return false; }
    if (circleDistanceY > (square.getLength()/2 + circle.getRadius())) { return false; }

	// Handle the easy cases where the circle is close enough to the rectangle (in either direction) that an intersection is guaranteed.
    if (circleDistanceX <= (square.getLength()/2)) { return true; } 
    if (circleDistanceY <= (square.getLength()/2)) { return true; }

	// Calculate the difficult case where the circle may intersect the corner of the rectangle.
    float cornerDistance_sq = pow(circleDistanceX - square.getLength() / 2, 2) +
                              pow(circleDistanceY - square.getLength() / 2, 2);

    return (cornerDistance_sq <= pow(circle.getRadius(), 2));
}
