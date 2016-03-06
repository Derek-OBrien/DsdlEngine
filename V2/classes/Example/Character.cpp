
#include "Character.h"




Character::Character(){};
Character::~Character(){};

void Character::init(b2World* world){

	m_sprite = new Sprite();
	
	m_sprite->create(90, 125, XmlLocalStorage::getInstance()->getStringForKey(XmlLocalStorage::getInstance()->getStringForKey("selectedPlayer").c_str()), 14);
	
	m_sprite->setPosition(Vec2(150, 820));

	m_capsule.init(world,m_sprite->getPosition(), m_sprite->getContentSize(),1.0f,0.0f,true );

	m_body = m_capsule.getBody();
}



void Character::update(InputManager& inputManager){

	//b2Vec2 position =	m_body->GetPosition();
	//float32 angle =		m_body->GetAngle();

	if (inputManager.isKeyDown(SDLK_UP)) {
		jump();
		SDL_Log("a Pressed");
	}
	else if (inputManager.isKeyDown(SDLK_DOWN)) {
		slide();
		SDL_Log("d Pressed");
	}
}

void Character::jump() {
	setPlayerState(JUMPING);
	//int x = m_sprite->getPosition().y_;

	//int pos = x -= 300;
	//m_sprite->setPositionY(pos);

	

	m_body->ApplyForceToCenter(b2Vec2(-200.0, 0.0), true);

}


void Character::slide() {
	setPlayerState(SLIDING);
	/*int x = m_sprite->getPosition().y_;

	int pos = x += 300;
	m_sprite->setPositionY(pos);*/


	m_body->ApplyForceToCenter(b2Vec2(200.0, 0.0), true);
}