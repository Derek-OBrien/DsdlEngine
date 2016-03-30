#ifndef _SPRITE_
#define _SPRITE_

#include "EngineBaseNode.h"
/*
	File: Sprite.h
	Author: Derek O Brien
	Description: Sprite file for creating in game sprites. Inherits from engine base node

*/
namespace DsdlEngine{

	class Sprite : public EngineBaseNode{
	public:
		Sprite();
		virtual ~Sprite();


		//Create basic sprite with one frame
		void create(Vec2 spriteSize, Vec2 position, std::string path);

		//Create basic sprite with more than one frame
		void create(Vec2 spriteSize, Vec2 position, std::string path, int numFrames);

		//Create basic sprite with more than one frame and physics body attached
		void createWithPhysics(b2World* world, Vec2 spriteSize, Vec2 position, std::string path, int numFrames, float den, float fri, bool FixedRotation);
		
		//Change sprite texture after sprite is loaded
		void updateTexure(Vec2 spriteSize, Vec2 position, std::string path, int numFrames);

		//Get Sprite collision body
		b2Body* getCollisionBody() { return m_CollisionShape->getBody(); }
		
		//cleanup
		void destroy();

	private:

	};
}

#endif //!_SPRITE_