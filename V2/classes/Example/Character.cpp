
#include "Character.h"




Character::Character(){};
Character::~Character(){};

void Character::init(b2World* world){

	m_sprite = new Sprite();
	
	m_sprite->create(90, 125, "DemoGame/player_sprites/player2.png", 14);
	m_sprite->setPosition(Vec2(150, 820));

	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.position.Set(
		m_sprite->getPosition().x_,
		m_sprite->getPosition().y_);
	m_bodyDef.userData = this;

	m_body = world->CreateBody(&m_bodyDef);

	m_shape.SetAsBox(
		m_sprite->getContentSize().w_,
		m_sprite->getContentSize().h_,
		b2Vec2(0,0), 0);

	m_fixtureDef.shape = &m_shape;
	m_fixtureDef.density = 1.0f;
	m_fixtureDef.friction = 0.3f;
	m_fixtureDef.userData = this;

	// Add the shape to the body.
	m_body->CreateFixture(&m_fixtureDef);
	m_body->SetTransform(b2Vec2(
		m_sprite->getPosition().x_, 
		m_sprite->getPosition().y_), 0.0);
}


void Character::update(){

	b2Vec2 position =	m_body->GetPosition();
	float32 angle =		m_body->GetAngle();

}

void Character::jump() {

	int x = m_sprite->getPosition().y_;

	int pos = x -= 300;
	m_sprite->setPositionY(pos);
}


void Character::drop() {

	int x = m_sprite->getPosition().y_;

	int pos = x += 300;
	m_sprite->setPositionY(pos);
}