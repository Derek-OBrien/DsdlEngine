#include "ColisionCapsule.h"

void CollisionCapsule::init(b2World* world,
	const Vec2 position,
	const Vec2 dimensions,
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

	// Create the circles
	b2CircleShape circleShape;
	circleShape.m_radius = dimensions.x_ / 2.0f;

	b2FixtureDef circleDef;
	circleDef.shape = &circleShape;
	circleDef.density = density;
	circleDef.friction = friction;

	// Bottom circle
	circleShape.m_p.Set(0.0f, (-m_dimensions.y_ + dimensions.x_) / 2.0f);
	m_fixtures[1] = m_body->CreateFixture(&circleDef);

	// Top Circle
	circleShape.m_p.Set(0.0f, (m_dimensions.y_ - dimensions.x_) / 2.0f);
	m_fixtures[1] = m_body->CreateFixture(&circleDef);
}


void CollisionCapsule::destroy(b2World* world) {
	if (m_body) {
		world->DestroyBody(m_body);
		m_body = nullptr;
	}
}