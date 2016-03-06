
#include "Character.h"




Character::Character(){};
Character::~Character(){};

void Character::init(b2World* world){

	m_sprite = new Sprite();
	
	
	XmlLocalStorage* db = XmlLocalStorage::getInstance();
	std::string player = db->getStringForKey("selectedPlayer");

	if (player == "player1") {

		m_sprite->create(90, 125, "DemoGame/player_sprites/player1.png", 14);
	}
	if (player == "player2") {

		m_sprite->create(90, 125, "DemoGame/player_sprites/player2.png", 14);
	}

	m_sprite->setPosition(Vec2(150, 820));

	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(
		m_sprite->getPosition().x_,
		m_sprite->getPosition().y_);

	m_body = world->CreateBody(&m_bodyDef);

	m_shape.SetAsBox(
		m_sprite->getContentSize().x_,
		m_sprite->getContentSize().y_,
		b2Vec2(0,0), 0);

	m_fixtureDef.shape = &m_shape;
	m_fixtureDef.density = 1.0f;
	m_fixtureDef.friction = 0.3f;
	
	// Add the shape to the body.
	m_body->CreateFixture(&m_fixtureDef);
	m_body->SetTransform(b2Vec2(
		m_sprite->getPosition().x_, 
		m_sprite->getPosition().y_), 0.0);

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
	else {
		m_body->SetLinearVelocity(b2Vec2(m_body->GetLinearVelocity().x * 0.95f, m_body->GetLinearVelocity().y));
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