
#include "Character.h"




Character::Character(){};
Character::~Character(){};

void Character::init(){

	m_sprite = new Sprite();

	EngineMaster* em =  EngineMaster::getInstance();

	m_sprite->create(90, 125, em->getStringForKey("player"), 14);
	m_sprite->setPosition(Vec2(150, 820));
}


void Character::update(){

}