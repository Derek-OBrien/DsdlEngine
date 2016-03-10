
#include "Character.h"




Character::Character(){};
Character::~Character(){};

void Character::init(b2World* world){

	m_sprite = new Sprite();
	std::string player = XmlLocalStorage::getInstance()->getStringForKey("selectedPlayer").c_str();
	
	m_sprite->createWithPhysics(world, Vec2(90,125), Vec2(150,820), XmlLocalStorage::getInstance()->getStringForKey(player.c_str()),14,1.0f,0.0f,true);
	
	m_body = m_sprite->getCollisionBody();
	m_body->SetTransform(
		b2Vec2(m_sprite->getPosition().x_, m_sprite->getPosition().y_),
		0
		);
}



void Character::update(InputManager& inputManager){

	//b2Vec2 position =	m_body->GetPosition();
	//float32 angle =		m_body->GetAngle();
#ifdef __WIN32__
	if (inputManager.isKeyDown(SDLK_UP)) {
		jump();
		SDL_Log("Up Pressed");
	}
	else if (inputManager.isKeyDown(SDLK_DOWN)) {
		slide();
		SDL_Log("down Pressed");
	}
#endif

#ifdef __ANDROID__
	if (inputManager.isKeyDown(SDL_FINGERDOWN)) {
		jump();
		SDL_Log("Up Pressed");
	}
	else if (inputManager.isKeyDown(SDL_FINGERUP)) {
		slide();
		SDL_Log("down Pressed");
	}
#endif
}

void Character::jump() {
	setPlayerState(JUMPING);
	int x = m_sprite->getPosition().y_;

	int pos = x -= 300;
	m_sprite->setPositionY(pos);
	
	m_body->ApplyForceToCenter(b2Vec2(-200.0, 0.0), true);
}


void Character::slide() {
	setPlayerState(SLIDING);
	int x = m_sprite->getPosition().y_;

	int pos = x += 300;
	m_sprite->setPositionY(pos);

	m_body->ApplyForceToCenter(b2Vec2(200.0, 0.0), true);
}