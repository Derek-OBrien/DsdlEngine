#pragma once

#include "Enemy.h"
#include "Coins.h"
class Factory
{
public:
	Factory();
	~Factory();

	virtual Enemy* createEnemy(b2World* world, Vec2 position);
	virtual Coins* createCoin(b2World* world, Vec2 position);
};
