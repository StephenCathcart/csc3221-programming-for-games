#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {

/** Position struct for all derived shapes **/
struct Position {
	float top;
	float bottom;
	float left;
	float right;
};

public:
	/** CONSTRUCTORS & DESTRUCTOR **/
	Shape(void);
	Shape(const float x, const float y, const float width, const float height);
	virtual ~Shape(void);

	/** MEMBER FUNCTIONS **/
	virtual std::ostream& print(std::ostream& o) const = 0;
	virtual bool isCollision(const Shape &shape) const = 0;
	void move(const float x, const float y);

	float getTop() const { return pos.top; };
	float getBottom() const { return pos.bottom; };
	float getLeft() const { return pos.left; };
	float getRight() const { return pos.right; };
	float getOriginX() const { return (pos.left + pos.right) / 2; }
	float getOriginY() const { return (pos.bottom + pos.top) / 2; }

	bool getIncreaseXBounds() const { return increaseXBounds; }
	void setIncreaseXBounds(const bool increase) { increaseXBounds = increase; }
	bool getIncreaseYBounds() const { return increaseYBounds; }
	void setIncreaseYBounds(const bool increase) { increaseYBounds = increase; }

	/** OPERATOR OVERLOADS **/
	bool operator==(const Shape &square) const;	
	bool operator!=(const Shape &square) const;	

protected:
	// vtptr RTTI gets created in here for us to use typeid later on
	Position pos;
	bool increaseXBounds;
	bool increaseYBounds;
};

#endif

