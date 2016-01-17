#include "Box.h"

Box::Box(){}

Box::~Box(){}


void Box::init(b2World* world, int x, int y, int w, int h){
	b2BodyDef bodyDef;

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x, y);
	body = world->CreateBody(&bodyDef);


	b2PolygonShape boxShape;
	boxShape.SetAsBox(w / 2, h / 2);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &boxShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	fixture = body->CreateFixture(&fixtureDef);
}