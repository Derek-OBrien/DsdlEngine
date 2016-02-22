
#include "Character.h"




Character::Character(){};
Character::~Character(){};

void Character::init(){

	m_sprite = new Sprite();

	EngineMaster* em =  EngineMaster::getInstance();
//	DEBUG_MSG("TEST XML FILE: " + std::string(em->getXMLFilePath()));
	
	
	//em->setIntegerForKey(100, "playerPosx");
	int test = em->getIntegerForKey("playerPosx");
	//std::cout << "PosX : %d " , test << std::endl;
	
	SDL_Log("PosX : %d", test);

	//em->setIntegerForKey(600, "playerPosy");
	int test2 = em->getIntegerForKey("playerPosy");
	//std::cout << "PosY : d% ", test2 << std::endl;
	SDL_Log("PosY : %d ",test2);

	
	//em->setIntegerForKey(500, "playerPosx");

	//em->deleteValueForKey("playerPosx");


	//int test2 = em->getIntegerForKey("playerPosx");

	//std::cout << test2 << std::endl;

	//em->setIntegerForKey(600, "DefaultRoot");

	m_sprite->create(90, 125, "player2.png", 14);
	m_sprite->setPosition(Vec2(200,100));
}


void Character::update(){

}