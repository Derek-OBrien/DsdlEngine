#pragma once
#include "../../dsdl-engine/DsdlEngine.h"
USING_NS_DSDL;

class Paddle : public Sprite
{
public:
	Paddle() {};
	~Paddle() {};

	void create();
	void update(float dt);

	Sprite* m_paddle;

private:

};

