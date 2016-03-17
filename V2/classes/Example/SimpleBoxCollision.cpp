#include "SimpleBoxCollision.h"


SimpleBoxCollision* instance = 0;
SimpleBoxCollision* SimpleBoxCollision::getInstance() {
	if (instance == 0) {
		instance = new (std::nothrow) SimpleBoxCollision();
	}

	return instance;
}


bool SimpleBoxCollision::check(SDL_Rect* a, SDL_Rect* b) {

	if (SDL_HasIntersection(a, b) == SDL_TRUE) {
		collided = true;
	}
	else {
		collided = false;
	}

	return collided;
}