#include "Enemy.h"
#include <dsdl-engine\EngineMath.h>


void Enemy::createEnemy(){

	enemy = new Sprite();

	enemy->create(50, 50, "bricks.png");

	//enemy->setPosition(DsdlEngine::Vec2(600, 600));

}