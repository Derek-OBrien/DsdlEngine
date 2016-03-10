#include "CollisionManager.h"
#include "Character.h"
#include "Enemy.h"
#include "HudLayer.h"


// Called when two fixtures begin to touch
void CollisionManager::BeginContact(b2Contact* contact) {

	void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	
	if (bodyUserData) {
		static_cast<Character*>(bodyUserData)->destroy();
	}
}
