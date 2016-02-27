#include "Enemy.h"


Enemy::Enemy() {}

Enemy::~Enemy() {}

void Enemy::createEnemy(){

	m_enemySprite = new Sprite();

	m_enemySprite->create(63, 33, "DemoGame/obstical_sprites/bird.png", 6);
	m_enemySprite->setPosition(Vec2(1980, 820));

	pos = m_enemySprite->getPosition().x_;
}


void Enemy::update() {

	pos -= 10;
	if (pos <= 0) {
		pos = 1980;
	}
	m_enemySprite->setPositionX(pos);

}