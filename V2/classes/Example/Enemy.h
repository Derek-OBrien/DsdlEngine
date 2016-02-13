#pragma once

//#include <dsdl-engine\Sprite.h>

//#include "../../dsdl-engine/DsdlEngine.h"
#include "DsdlEngine.h"


class Enemy : public DsdlEngine::Sprite{

public: 
	Enemy(){}

	void createEnemy();


	Sprite* enemy;
};