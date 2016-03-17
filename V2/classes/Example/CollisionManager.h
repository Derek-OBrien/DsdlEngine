#pragma once
#include "../../dsdl-engine/DsdlEngine.h"
#include "HudLayer.h"


class CollisionManager : public b2ContactListener
{
public:
	CollisionManager() {}
	~CollisionManager() {}

	// Called when two fixtures begin to touch
	virtual void BeginContact(b2Contact* contact, HudLayer* hud);

	virtual void EndContact(b2Contact* contact, HudLayer* hud);

	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold, HudLayer* hud);
	virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse, HudLayer* hud);

	bool coinCollide;
};
