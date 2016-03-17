#include "CollisionShape.h"


namespace DsdlEngine {

	CollisionShape::CollisionShape(){
		//Empty
		
	}

	CollisionShape::~CollisionShape(){
		//Empty
	}


	void CollisionShape::init(b2World* world,
		Vec2 position,
		Vec2 dimensions,
		float density,
		float friction,
		bool fixedRotation) {

		m_dimensions = dimensions;

		// Make the body
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(position.x_, position.y_);
		bodyDef.fixedRotation = fixedRotation;
		m_body = world->CreateBody(&bodyDef);


		// Create the box
		b2PolygonShape boxShape;
		boxShape.SetAsBox(dimensions.x_ / 2.0f, (dimensions.y_ - dimensions.x_) / 2.0f);

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &boxShape;
		fixtureDef.density = density;
		fixtureDef.friction = friction;
		m_fixtures[0] = m_body->CreateFixture(&fixtureDef);
	}


	void CollisionShape::destroy(b2World* world) {
		if (m_body) {
			world->DestroyBody(m_body);
			m_body = nullptr;
		}
	}
}