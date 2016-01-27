#pragma once

//#include <dsdl-engine\Sprite.h>

#include "../../dsdl-engine/Sprite.h"
USING_NS_DSDL;


class Character : public DsdlEngine::Sprite{

public:
	Character();
	~Character();

	void init();
	void update();

	Sprite* m_sprite;

};