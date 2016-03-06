#include "Enemy.h"


Enemy::Enemy() {
	//Empty
}

Enemy::~Enemy() {
	//Empty
}

void Enemy::createEnemy(b2World* world, Vec2 position){

	m_enemySprite = new Sprite();
	
	m_enemySprite->create(63, 33, XmlLocalStorage::getInstance()->getStringForKey("enemy"), 6);
	m_enemySprite->setPosition(Vec2(position.x_, position.y_));


	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(
		m_enemySprite->getPosition().x_, 
		m_enemySprite->getPosition().y_);

	m_bodyDef.userData = this;


	m_body = world->CreateBody(&m_bodyDef);

	// Define another box shape for our dynamic body.
	m_shape.SetAsBox(
		(m_enemySprite->getContentSize().x_ / 2),
		(m_enemySprite->getContentSize().y_ / 2));

	m_fixtureDef.shape = &m_shape;
	m_fixtureDef.density = 0.5f;
	m_fixtureDef.friction = 0;
	m_fixtureDef.userData = this;

	m_body->CreateFixture(&m_fixtureDef);
	m_body->SetTransform(b2Vec2(
		m_enemySprite->getPosition().x_, 
		m_enemySprite->getPosition().y_), 0.0);

	pos = m_enemySprite->getPosition().x_;
}


void Enemy::update() {

	pos -= 5;
	if (pos <= -20) {
		pos = 1980;
	}
	m_enemySprite->setPositionX(pos);
	
	m_body->SetTransform(b2Vec2(
		m_enemySprite->getPosition().x_,
		m_enemySprite->getPosition().y_), 0.0);
}