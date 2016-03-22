#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "Board.h"

class HandleCollision
{
public:
	HandleCollision() {}
	~HandleCollision() {}


	bool Collides(Sprite* one, Sprite* two);
private:

};
