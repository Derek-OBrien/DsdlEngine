#pragma once
#include "../../dsdl-engine/DsdlEngine.h"

USING_NS_DSDL;


class Character : public DsdlEngine::Sprite{

public:
	Character();
	~Character();

	void init();
	void update();

	void jump();
	void drop();
	Sprite* m_sprite;

};