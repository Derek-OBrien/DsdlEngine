
#include "Character.h"




Character::Character(){};
Character::~Character(){};

void Character::init(){

	m_sprite = new Sprite();

	m_sprite->create(79, 79, "Character.png");
	m_sprite->setPosition(Vec2(200,200));


}


void Character::update(){

}