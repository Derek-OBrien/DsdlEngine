#ifndef _SPRITE_
#define _SPRITE_

#include "EngineBaseNode.h"

namespace DsdlEngine{

	class Sprite :public EngineBaseNode
	{
	public:
		Sprite();
		virtual ~Sprite();


		/**
		* Create a Sprite
		*
		* @param width The width of the sprite
		* @param height the height of the sprite
		* @param path The path to the Sprite asset
		* 
		*/

		void create(Vec2 spriteSize, Vec2 position, std::string path);
		void create(Vec2 spriteSize, Vec2 position, std::string path, int numFrames);
		void createWithPhysics(b2World* world, Vec2 spriteSize, Vec2 position, std::string path, int numFrames, float den, float fri, bool FixedRotation);
		
		void updateTexure(Vec2 spriteSize, Vec2 position, std::string path, int numFrames);
		b2Body* getCollisionBody() { return m_CollisionShape->getBody(); }
		//cleanup
		void destroy();

	private:

	};
}

#endif