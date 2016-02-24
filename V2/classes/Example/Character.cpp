
#include "Character.h"




Character::Character(){};
Character::~Character(){};

void Character::init(){

	m_sprite = new Sprite();

	EngineMaster* em =  EngineMaster::getInstance();
//	DEBUG_MSG("TEST XML FILE: " + std::string(em->getXMLFilePath()));
	
	//char* contents = NULL;
	//FileIO::getInstance()->loadDocument("../../assets/DemoGame/assets.xml", &contents);

//	SDL_Log(contents);

	std::string temp = em->getStringForKey("player");
	//SDL_Log(temp.c_str());
	
	//em->setIntegerForKey(100, "playerPosx");
	//int test = em->getIntegerForKey("playerPosx");
	//SDL_Log("PosX : %d", test);


	//em->setIntegerForKey(50, "playerPosy");
	//int test2 = em->getIntegerForKey("playerPosy");
	//SDL_Log("PosY : %d ",test2);

	
	//em->setIntegerForKey(500, "playerPosx");

	//em->deleteValueForKey("playerPosx");


	//int test2 = em->getIntegerForKey("playerPosx");

	//std::cout << test2 << std::endl;

	//em->setIntegerForKey(600, "DefaultRoot");

	m_sprite->create(90, 125, em->getStringForKey("player"), 14);
	m_sprite->setPosition(Vec2(em->getIntegerForKey("playerPosx"), em->getIntegerForKey("playerPosy")));
}


void Character::update(){

}