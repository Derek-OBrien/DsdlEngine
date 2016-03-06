#pragma once
#include "../../dsdl-engine/DsdlEngine.h"


class CollisionManager : public b2ContactListener
{
public:
	CollisionManager() {}
	~CollisionManager() {}

	// Called when two fixtures begin to touch
	virtual void BeginContact(b2Contact* contact);

};
