#ifndef __COLLISIONSHAPE__
#define __COLLISIONSHAPE__

#include "EngineDefines.h"

namespace DsdlEngine {
	class CollisionShape
	{
	public:
		CollisionShape();
		~CollisionShape();

		//Init Collision shape Bounding box
		void init(b2World* world,
			Vec2 position,
			Vec2 dimensions,
			float density,
			float friction,
			bool fixedRotation);

		//Destroy the collision shape
		void destroy(b2World* world);

		//Get the shape body
		//return b2body 
		b2Body* getBody() const { return m_body; }

		//Get the fixtures
		//input index of fixture you want
		//return b2Fixture at that index
		b2Fixture* getFixture(int index) const { return m_fixtures[index]; }

		//Get the Dimensions
		//return Vec2 m_dimensions
		const Vec2 getDimensions() const { return m_dimensions; }

	protected:
		b2Body* m_body = nullptr;
		b2Fixture* m_fixtures[1];
		Vec2 m_dimensions;
	};

}
#endif // !__COLLISIONSHAPE__
