#pragma once

#include <dsdl-engine\EngineDefines.h>

class Box
{
public:
	Box();
	~Box();


	void init(b2World* world, int x, int y, int w, int h);


	b2Body* getbody(){ return body; }
	b2Fixture* getfixture(){ return fixture; }


private:


	b2Body* body = nullptr;
	b2Fixture* fixture = nullptr;
};
