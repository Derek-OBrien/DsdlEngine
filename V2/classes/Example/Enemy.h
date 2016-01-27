#pragma once

//#include <dsdl-engine\Sprite.h>

#include "../../dsdl-engine/Sprite.h"

class Enemy : public DsdlEngine::Sprite{

public: 
	Enemy(){}

	void createEnemy();


	Sprite* enemy;
};