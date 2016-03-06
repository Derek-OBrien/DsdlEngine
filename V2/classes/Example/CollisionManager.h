#pragma once
#include "../../dsdl-engine/DsdlEngine.h"


class CollisionManager : public b2ContactListener
{
public:
	CollisionManager() {}
	~CollisionManager() {}

//	static CollisionManager* getInstance();

	bool checkForCollision(b2Fixture* body1, b2Fixture* body2);

	// Called when two fixtures begin to touch
	virtual void BeginContact(b2Contact* contact);

	// Called when two fixtures cease to touch
	virtual void EndContact(b2Contact* contact);
private:
	
	bool isCollide;
};
