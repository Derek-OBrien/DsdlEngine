
#include "Character.h"




Character::Character(){};
Character::~Character(){};

void Character::init(b2World* world){

	m_sprite = new Sprite();
	bodyDef = new b2BodyDef();


	m_sprite->create(90, 125, "DemoGame/player_sprites/player2.png", 14);
	
	bodyDef->type = b2_dynamicBody;
	body = world->CreateBody(bodyDef);

	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(90 , 125 );

	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	// Add the shape to the body.
	body->CreateFixture(&fixtureDef);

	
	//Set Position
	bodyDef->position.Set(150, 500);
	m_sprite->setPosition(Vec2(150, 500));
}


void Character::update(){

	b2Vec2 position =	body->GetPosition();
	float32 angle =		body->GetAngle();

	m_sprite->setPosition(Vec2(position.x, position.y));
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