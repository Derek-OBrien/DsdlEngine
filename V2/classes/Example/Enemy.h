#pragma once
#include "../../dsdl-engine/DsdlEngine.h"

USING_NS_DSDL;


class Enemy : public DsdlEngine::Sprite{

public: 
	Enemy();
	~Enemy();
	void createEnemy(b2World* world, Vec2 position);
	void update();

	Sprite* m_enemySprite;
	int pos;

	b2Body* m_body;
	b2BodyDef m_bodyDef;
	b2PolygonShape m_shape;
	b2FixtureDef m_fixtureDef;
};