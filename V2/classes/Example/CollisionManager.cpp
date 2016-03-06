#include "CollisionManager.h"
#include "Character.h"
#include "Enemy.h"
#include "HudLayer.h"


/*CollisionManager *collisionManagerInstance = 0;
CollisionManager *CollisionManager::getInstance() {
	if (collisionManagerInstance == 0) {					
		collisionManagerInstance = new CollisionManager();	
	}														
	return collisionManagerInstance;						
}*/

bool CollisionManager::checkForCollision(b2Fixture* body1, b2Fixture* body2) {

	
	return true;

}


// Called when two fixtures begin to touch
void CollisionManager::BeginContact(b2Contact* contact) {

	void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	
	if (bodyUserData) {
		static_cast<Enemy*>(bodyUserData)->destroy();
	}
}

// Called when two fixtures cease to touch
void CollisionManager::EndContact(b2Contact* contact) {

}
