#include "Box.h"

Box::Box(){}

Box::~Box(){}


void Box::init(b2World* world, float x, float y, float w, float h, DsdlEngine::ResourceTexture tex){
	m_tex = tex;
	
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

	posX = x;
	posY = y;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
}

void Box::draw(SDL_Renderer* r){

	m_tex.render(posX, posY, r, 0);

	SDL_SetRenderDrawColor(r, 0x00, 0xff, 0x00, 0xff);
	SDL_RenderDrawRect(r, &rect);

}