#pragma once
#include "../../dsdl-engine/DsdlEngine.h"

USING_NS_DSDL;


class Enemy : public DsdlEngine::Sprite{

public: 
	Enemy();
	~Enemy();
	void createEnemy();
	void update();

	Sprite* m_enemySprite;
	int pos;
};