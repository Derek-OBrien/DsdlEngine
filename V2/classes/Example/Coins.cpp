#include "Coins.h"
Coins::Coins()
{
}

Coins::~Coins()
{
}


void Coins::createCoin(b2World* world, Vec2 position) {

	m_coinSprite = new Sprite();

	m_coinSprite->create(50, 50, XmlLocalStorage::getInstance()->getStringForKey("coin"));
	m_coinSprite->setPosition(Vec2(position.x_, position.y_));


	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(
		m_coinSprite->getPosition().x_,
		m_coinSprite->getPosition().y_);

	m_bodyDef.userData = this;


	m_body = world->CreateBody(&m_bodyDef);

	// Define another box shape for our dynamic body.
	m_shape.SetAsBox(
		(m_coinSprite->getContentSize().x_ / 2),
		(m_coinSprite->getContentSize().y_ / 2));

	m_fixtureDef.shape = &m_shape;
	m_fixtureDef.density = 0.5f;
	m_fixtureDef.friction = 0;
	m_fixtureDef.userData = this;

	m_body->CreateFixture(&m_fixtureDef);
	m_body->SetTransform(b2Vec2(
		m_coinSprite->getPosition().x_,
		m_coinSprite->getPosition().y_), 0.0);

	pos = m_coinSprite->getPosition().x_;
}


void Coins::update() {

	pos -= 5;
	if (pos <= -20) {
		pos = 1980;
	}
	m_coinSprite->setPositionX(pos);

	m_body->SetTransform(b2Vec2(
		m_coinSprite->getPosition().x_,
		m_coinSprite->getPosition().y_), 0.0);
}