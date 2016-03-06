
#include "EnemyFactory.h"


Factory::Factory() {
	//Empty	
}

Factory::~Factory() {
	//Empty
}

Enemy* Factory::createEnemy(b2World* world, Vec2 position) {

	Enemy* e = new Enemy();
	e->createEnemy(world, position);
	return e;
}

Coins* Factory::createCoin(b2World* world, Vec2 position) {

	Coins* c = new Coins();
	c->createCoin(world, position);
	return c;
}