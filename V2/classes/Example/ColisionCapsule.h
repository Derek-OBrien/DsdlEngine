#pragma once

#include "../../dsdl-engine/DsdlEngine.h"

USING_NS_DSDL;

class CollisionCapsule {
public:
	void init(b2World* world,
		const Vec2 position,
		const Vec2 dimensions,
		float density,
		float friction,
		bool fixedRotation);

	void destroy(b2World* world);

	
	b2Body* getBody() const { return m_body; }
	b2Fixture* getFixture(int index) const { return m_fixtures[index]; }
	const Vec2 getDimensions() const { return m_dimensions; }
private:
	b2Body* m_body = nullptr;
	b2Fixture* m_fixtures[3];
	Vec2 m_dimensions;
};