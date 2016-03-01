#pragma once
#include "../../dsdl-engine/DsdlEngine.h"

USING_NS_DSDL;


class Character : public DsdlEngine::Sprite{

public:
	Character();
	~Character();

	void init(b2World* world);
	void update();

	void jump();
	void drop();
	Sprite* m_sprite;


	b2Body* m_body;
	b2BodyDef m_bodyDef;
	b2PolygonShape m_shape;
	b2FixtureDef m_fixtureDef;
};