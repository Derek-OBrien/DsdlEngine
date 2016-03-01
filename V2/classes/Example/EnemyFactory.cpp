
#include "EnemyFactory.h"


EnemyFactory::EnemyFactory() {
	//Empty	
}

EnemyFactory::~EnemyFactory() {
	//Empty
}

Enemy* EnemyFactory::createEnemy(b2World* world, Vec2 position) {

	Enemy* e = new Enemy();
	e->createEnemy(world, position);
	return e;
}