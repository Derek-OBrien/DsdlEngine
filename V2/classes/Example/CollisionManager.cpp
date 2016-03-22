#include "CollisionManager.h"
#include "Character.h"
#include "Enemy.h"
#include "HudLayer.h"


// Called when two fixtures begin to touch
void CollisionManager::BeginContact(b2Contact* contact, HudLayer* hud) {

	b2Fixture* fixtureA = contact->GetFixtureA();
	b2Fixture* fixtureB = contact->GetFixtureB();

	b2Body* bodyA = fixtureA->GetBody();
	b2Body* bodyB = fixtureB->GetBody();

	uint16  data1 = fixtureA->GetFilterData().maskBits;
	uint16  data2 = fixtureB->GetFilterData().maskBits;

	Sprite* actorA = (Sprite*)bodyA->GetUserData();
	Sprite* actorB = (Sprite*)bodyB->GetUserData();

	coinCollide = false;

	if (data1 == PLAYER_FILTER && data2 == COIN_FILTER || data1 == COIN_FILTER && data2 == PLAYER_FILTER) {
		
		coinCollide = true;
		SDL_Log("Coin and Player Collided");
		
	}

	if (data1 == PLAYER_FILTER && data2 == ENEMY_FILTER || data1 == ENEMY_FILTER && data2 == PLAYER_FILTER) {
		SDL_Log("Enemy and Player Collided");
	}

}


void CollisionManager::EndContact(b2Contact* contact, HudLayer* hud) {

	if (coinCollide == true) {
	//	hud->updateCoinCount();
		coinCollide = false;
	}
}


void CollisionManager::PreSolve(b2Contact* contact, const b2Manifold* oldManifold, HudLayer* hud)
{ /* handle pre-solve event */

	hud->updateCoinCount(1);

	b2WorldManifold worldManifold;
	contact->GetWorldManifold(&worldManifold);
	b2PointState state1[2], state2[2];
	b2GetPointStates(state1, state2, oldManifold, contact->GetManifold());
	if (state2[0] == b2_addState)
	{
		const b2Body* bodyA = contact->GetFixtureA()->GetBody();
		const b2Body* bodyB = contact->GetFixtureB()->GetBody();
		b2Vec2 point = worldManifold.points[0];
		b2Vec2 vA = bodyA->GetLinearVelocityFromWorldPoint(point);
		b2Vec2 vB = bodyB->GetLinearVelocityFromWorldPoint(point);
		
			hud->updateCoinCount(1);
		
	}
}

void CollisionManager::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse, HudLayer* hud)
{ /* handle post-solve event */


}