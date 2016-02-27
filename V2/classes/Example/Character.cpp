
#include "Character.h"




Character::Character(){};
Character::~Character(){};

void Character::init(){

	m_sprite = new Sprite();

	EngineMaster* em =  EngineMaster::getInstance();

	m_sprite->create(90, 125, "DemoGame/player_sprites/player2.png", 14);
	m_sprite->setPosition(Vec2(150, 820));
}


void Character::update(){

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