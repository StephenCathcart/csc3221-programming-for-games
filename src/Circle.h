#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
	/** CONSTRUCTORS & DESTRUCTOR **/
	Circle(void);
	Circle(const float x, const float y, const float diameter);
	Circle(const Circle& copy);
	~Circle(void);

	/** MEMBER FUNCTIONS **/
	std::ostream& print(std::ostream& o) const;
	bool isCollision(const Shape &shape) const;
	float getDiameter() const { return diameter; };
	float getRadius() const { return radius; };

	/** OPERATOR OVERLOADS **/
	Circle& operator=(const Circle &circle);
	friend std::ostream& operator<<(std::ostream& o, const Circle& circle);

private:
	float diameter;
	float radius;
};

#endif

