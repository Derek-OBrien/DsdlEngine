#pragma once
#include "../../dsdl-engine/DsdlEngine.h"

class SimpleBoxCollision
{
public:
	static SimpleBoxCollision* getInstance();

	bool check(SDL_Rect* a, SDL_Rect* b);
private:
	SimpleBoxCollision() {}
	~SimpleBoxCollision() {}

	bool collided;

};
