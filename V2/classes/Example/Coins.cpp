#include "Coins.h"
#include "GameDefines.h"

Coins::Coins(){
	//Empty
}

Coins::~Coins(){
	//Empty
}


void Coins::createCoin(b2World* world, Vec2 position) {

	m_coinSprite = new Sprite();

	m_coinSprite->create(Vec2(50, 50), position, XmlLocalStorage::getInstance()->getStringForKey("coin"),1);

	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(
		m_coinSprite->getPosition().x_,
		m_coinSprite->getPosition().y_);

	m_bodyDef.userData = this;


	m_body = world->CreateBody(&m_bodyDef);
	m_body->SetUserData(m_coinSprite);
	// Define another box shape for our dynamic body.
	m_shape.SetAsBox(
		(m_coinSprite->getContentSize().x_ / 2),
		(m_coinSprite->getContentSize().y_ / 2));

	m_fixtureDef.shape = &m_shape;
	m_fixtureDef.density = 0.5f;
	m_fixtureDef.friction = 0;
	m_fixtureDef.userData = this;

	m_fixtureDef.filter.categoryBits = OBJECT_CAT;
	m_fixtureDef.filter.maskBits = COIN_FILTER;

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


	m_coinSprite->setBoundingBox(m_coinSprite->getPosition(), m_coinSprite->getContentSize());
	m_body->SetTransform(b2Vec2(
		m_coinSprite->getPosition().x_,
		m_coinSprite->getPosition().y_), 0.0);
}

void Coins::resetPosition() {
	m_coinSprite->setPositionX(GAME_WIDTH + 100);
	m_coinSprite->getBoundingBox()->x = m_coinSprite->getPosition().x_;
}