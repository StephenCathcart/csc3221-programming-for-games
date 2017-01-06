#include "Square.h"
#include "Circle.h"
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

vector<Shape*> shapeVector;

const int GRID_WIDTH = 2000;
const int GRID_HEIGHT = 2000;
const int NUM_OF_SHAPES = 60;
const float MAX_SHAPE_SPEED = 0.2f;
const float MAX_SHAPE_WIDTH = 20.0f;
const float MIN_SHAPE_WIDTH = 5.0f;

void setupShapeVector();
void updateShapePositions();
void updateCollisions();
void outputCollisionData(Shape* shapeOne, Shape* shapeTwo);
float randomFloat(float min, float max);
int randomInt(int min, int max);

/**
 *	Main game loop, sets up the shape vector then updates each shape and checks
 *	for collisons until vector is empty or has only one shape left.
 */
int main () {
	// Allows read friendly booleans
	cout.setf(ios::boolalpha);
	// Seed rand
	srand (time(0));

	setupShapeVector();
	while(true) {
		// End program if vector size is <= 1
		if(shapeVector.size() <= 1) { break; }
		updateShapePositions();
		updateCollisions();
	}
	cout << "Game finished with " << shapeVector.size() << " shape(s) left..." << endl;

	// Clean up
	for(int i = 0; i < shapeVector.size(); i++) {
		delete shapeVector[i];
	}

	// Keep console window open
	std::cin.get();
	return 0;
}

/**
 *	Adds X amount of random shapes (circles & squares) to the shape vector
 *	with random x, y and width properties. It doesn't matter if the are slightly outside
 *	the grid as the movement functions takes care of this.
 */
void setupShapeVector() {
	for(int i = 0; i < NUM_OF_SHAPES; i++) {
		// Random 0 or 1 to used to choose either square or circle
		int bit = randomInt(0, 2);
		float x = randomFloat(0, GRID_WIDTH);
		float y = randomFloat(0, GRID_HEIGHT);
		float width = randomFloat(MIN_SHAPE_WIDTH, MAX_SHAPE_WIDTH);
		// Create a random shape with random properties and add to vector
		if(bit == 0) {
			shapeVector.push_back(new Circle(x, y, width));
		}else {
			shapeVector.push_back(new Square(x, y, width));
		}
	}
}

/**
 *	For each shape we check if it is outside the grid so we can decide on with
 *	direction to move (either positive or negative). We then add random x and y speed in
 *	that direction.
 */
void updateShapePositions() {
	for(int i = 0; i < shapeVector.size(); i++) {
		if(shapeVector[i]->getTop() > GRID_HEIGHT) { 
			shapeVector[i]->setIncreaseYBounds(false);
		}else if(shapeVector[i]->getBottom() < 0){
			shapeVector[i]->setIncreaseYBounds(true);
		}
		if(shapeVector[i]->getLeft() < 0) { 
			shapeVector[i]->setIncreaseXBounds(true);
		}else if(shapeVector[i]->getRight() > GRID_WIDTH) {
			shapeVector[i]->setIncreaseXBounds(false);
		}

		float x = (shapeVector[i]->getIncreaseXBounds()) ? randomFloat(0, MAX_SHAPE_SPEED) : randomFloat(0, -MAX_SHAPE_SPEED);
		float y = (shapeVector[i]->getIncreaseYBounds()) ? randomFloat(0, MAX_SHAPE_SPEED) : randomFloat(0, -MAX_SHAPE_SPEED);

		shapeVector[i]->move(x, y);
	}
}

/**
 *	Checks each shape in the vector for collisions, it does not check itself. The comments
 *	below explain what is happening...
 */
void updateCollisions() {
	// For each shape...
	for(int i = 0; i < shapeVector.size(); i++) {
		// Check against every other shape...
		for(int j = 0; j < shapeVector.size(); j++) {
			// But not if it that shape is itself...
			if(shapeVector[i] != shapeVector[j]) {
				// Then check if we have a collision...
				if(shapeVector[i]->isCollision(*shapeVector[j])) {
					// If we do we need to check the values of i & j to delete correct element
					// as the vector will shift left after erasing a value. We also free
					// memory before erasing...
					outputCollisionData(shapeVector[i], shapeVector[j]);
					if(i < j) {
						delete shapeVector[i];
						shapeVector.erase(shapeVector.begin() + i);
						delete shapeVector[j - 1];
						shapeVector.erase(shapeVector.begin() + (j - 1));
					}else {
						delete shapeVector[i];
						shapeVector.erase(shapeVector.begin() + i);
						delete shapeVector[j];
						shapeVector.erase(shapeVector.begin() + j);
					}
					cout << "SHAPES LEFT IN VECTOR: " << shapeVector.size() << endl;
					cout << "***********************" << endl;
					cout << endl;
				}
			}
		}
	}
}

/**
 *	Outputs the collision between two shapes formatted nicely.
 */
void outputCollisionData(Shape* shapeOne, Shape* shapeTwo) {
	cout << endl;
	cout << "***********************" << endl;
	cout << "** COLLISON DETECTED **" << endl;
	cout << endl;
	shapeOne->print(cout) << endl;
	shapeTwo->print(cout) << endl;
}

/**
 *	Returns a random float between two floats.
 */
float randomFloat(float min, float max) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = max - min;
    float r = random * diff;
    return min + r;
}

/**
 *	Returns a random int between two ints.
 */
int randomInt(int min, int max) {
    return (rand()%(max-min))+min;
}