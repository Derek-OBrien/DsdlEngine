
#include "Character.h"




Character::Character(){};
Character::~Character(){};

void Character::init(){

	m_sprite = new Sprite();

	m_sprite->create(90, 125, "player2.png", 14);
	m_sprite->setPosition(Vec2(200,200));


}


void Character::update(){

}