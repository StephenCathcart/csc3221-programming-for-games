#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
public: 
	/** CONSTRUCTORS & DESTRUCTOR **/
	Square(void);
	Square(const float x, const float y, const float length);
	Square(const Square& copy);
	~Square(void);

	/** MEMBER FUNCTIONS **/
	std::ostream& print(std::ostream& o) const;
	bool isCollision(const Shape &shape) const;
	float getLength() const { return length; };

	/** OPERATOR OVERLOADS **/
	Square& operator=(const Square &square);
	friend std::ostream& operator<<(std::ostream& o, const Square& square);

private:
	float length;
};

#endif
