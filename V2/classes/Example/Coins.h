#pragma once
#include "../../dsdl-engine/DsdlEngine.h"
#include "GameDefines.h"
#include "ColisionCapsule.h"

USING_NS_DSDL;

class Coins : public Sprite
{
public:
	Coins();
	~Coins();


	void createCoin(b2World* world, Vec2 position);
	void update();

	Sprite* m_coinSprite;
	int pos;

	b2Body* m_body;
	b2BodyDef m_bodyDef;
	b2PolygonShape m_shape;
	b2FixtureDef m_fixtureDef;


};

