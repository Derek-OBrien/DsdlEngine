
#include "Character.h"




Character::Character(){};
Character::~Character(){};

void Character::init(b2World* world){

	m_sprite = new Sprite();
	player = XmlLocalStorage::getInstance()->getStringForKey("selectedPlayer").c_str();
	
	m_sprite->createWithPhysics(
		world,
		Vec2(90, 125),
		Vec2(150, 820),
		XmlLocalStorage::getInstance()->getStringForKey(player.c_str()),
		14,
		1.0f,
		0.0f,
		true);

	m_body = m_sprite->getCollisionBody();

	b2Filter playerfilter;
	playerfilter.maskBits = PLAYER_FILTER;

	m_body->GetFixtureList()->SetFilterData(playerfilter);
	m_body->SetUserData(m_sprite);
	m_body->SetTransform(
		b2Vec2(m_sprite->getPosition().x_, m_sprite->getPosition().y_),
		0
		);

	setPlayerState(ALIVE);

	if (currentState == ALIVE) {
		m_sprite->setAssetPath(XmlLocalStorage::getInstance()->getStringForKey(player.c_str()));
	}
	if (currentState == JUMPING) {
		m_sprite->setAssetPath(XmlLocalStorage::getInstance()->getStringForKey("player2jump"));
	}
	if (currentState == SLIDING) {
		m_sprite->setAssetPath(XmlLocalStorage::getInstance()->getStringForKey("player2slide"));
	}
}



void Character::update(InputManager& inputManager, b2World* world){

#ifdef __WIN32__
	if (inputManager.isKeyPressed(SDLK_UP)) {
		jump();
	}

	if (inputManager.isKeyPressed(SDLK_DOWN)) {
		slide();
	}

	if (inputManager.isKeyReleased(SDLK_UP)) {
		fall();
	}

	if (inputManager.isKeyReleased(SDLK_DOWN)) {
		stopSlide();
	}

#endif

#ifdef __ANDROID__
	if (inputManager.isKeyPressed(SDL_FINGERDOWN)) {
		jump();
	}
#endif
}

void Character::jump() {
	setPlayerState(JUMPING);
	int x = m_sprite->getPosition().y_;

	m_sprite->updateTexure(
		Vec2(122, 112),
		m_sprite->getPosition(),
		XmlLocalStorage::getInstance()->getStringForKey("player2jump"), 2);

		int pos = x -= 30;
		m_sprite->setPositionY(pos);

		m_sprite->setBoundingBox(m_sprite->getPosition(), m_sprite->getContentSize());
		m_body->SetTransform(
			b2Vec2(m_sprite->getPosition().x_, m_sprite->getPosition().y_),
			0
			);
}

void Character::fall() {
	setPlayerState(FALLING);
	int x = m_sprite->getPosition().y_;

	m_sprite->updateTexure(
		Vec2(90, 125),
		m_sprite->getPosition(),
		XmlLocalStorage::getInstance()->getStringForKey(player.c_str()), 14);

	while (x < 820) {


		int pos = x += 30;
		m_sprite->setPositionY(pos);

		m_sprite->setBoundingBox(m_sprite->getPosition(), m_sprite->getContentSize());
		m_body->SetTransform(
			b2Vec2(m_sprite->getPosition().x_, m_sprite->getPosition().y_),
			0
			);
	}
}

void Character::slide() {
	setPlayerState(SLIDING);
	int x = m_sprite->getPosition().x_;

	int pos = x += 30;
	m_sprite->setPositionX(pos);

	m_body->SetTransform(
		b2Vec2(m_sprite->getPosition().x_, m_sprite->getPosition().y_),
		0
		);

	m_sprite->updateTexure(
		Vec2(130,75), 
		m_sprite->getPosition(), 
		XmlLocalStorage::getInstance()->getStringForKey("player2slide"), 1);
}

void Character::stopSlide() {
	setPlayerState(SLIDING);
	int x = m_sprite->getPosition().x_;

	m_sprite->updateTexure(
		Vec2(90, 125),
		m_sprite->getPosition(),
		XmlLocalStorage::getInstance()->getStringForKey(player.c_str()), 14);

	while (x > 100) {

		int pos = x -= 30;
		m_sprite->setPositionX(pos);

		m_body->SetTransform(
			b2Vec2(m_sprite->getPosition().x_, m_sprite->getPosition().y_),
			0
			);
	}
}