#pragma once

#include "Enemy.h"

class EnemyFactory
{
public:
	EnemyFactory();
	~EnemyFactory();

	virtual Enemy* createEnemy(b2World* world, Vec2 position);

};
