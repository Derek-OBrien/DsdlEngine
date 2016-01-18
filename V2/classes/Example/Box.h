#pragma once

#include <dsdl-engine\EngineDefines.h>

#include <dsdl-engine\ResourceTexture.h>

class Box
{
public:
	Box();
	~Box();


	void init(b2World* world, float x, float y, float w, float h, DsdlEngine::ResourceTexture tex);


	b2Body* getbody(){ return body; }
	b2Fixture* getfixture(){ return fixture; }

	SDL_Rect getboxRect(){ return rect; }


	void draw(SDL_Renderer* r);
private:
	SDL_Rect rect;
	DsdlEngine::ResourceTexture m_tex;
	b2Body* body = nullptr;
	b2Fixture* fixture = nullptr;


	int posX, posY;
};
