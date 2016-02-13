
#include "Character.h"




Character::Character(){};
Character::~Character(){};

void Character::init(){

	m_sprite = new Sprite();

	//DsdlEngine::EngineMaster::getInstance()->setIntegerForKey(100, "playerPosx");

	m_sprite->create(90, 125, "player2.png", 14);
	m_sprite->setPosition(Vec2(200,100));

	std::cout << m_sprite->getContentSize().w_ << std::endl;
	std::cout << m_sprite->getContentSize().h_ << std::endl;
}


void Character::update(){

}