#pragma once
#include "../../dsdl-engine/DsdlEngine.h"
#include "ColisionCapsule.h"

USING_NS_DSDL;


class Coins : public DsdlEngine::Sprite{

public:
	Coins();
	~Coins();

	void createCoin(b2World* world, Vec2 position);
	void update();
	void resetPosition();

	Sprite* m_coinSprite;
	Vec2 pos;

	b2Body* m_body;
	b2BodyDef m_bodyDef;
	b2PolygonShape m_shape;
	b2FixtureDef m_fixtureDef;
};

