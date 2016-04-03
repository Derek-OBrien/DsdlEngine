#ifndef _SPRITE_
#define _SPRITE_

#include "EngineBaseNode.h"
/**
*	@author Derek O Brien
*/
namespace DsdlEngine{

	/**
	*	Sprite file for creating in game sprites. Inherits from EngineBaseNode
	*/
	class Sprite : public EngineBaseNode{
	public:
		/**
		*	Constructor
		*/
		Sprite();

		/**
		*	Deconstructor
		*/
		virtual ~Sprite();

		/**
		*	Create basic sprite with one frame.
		*	@param spriteSize, Vec2 Size of the sprite.
		*	@param position, Vec2 position of sprite.
		*	@param path, std::string path to sprite asset.
		*/
		void create(Vec2 spriteSize, Vec2 position, std::string path);

		/**
		*	Create basic sprite with more then one frame.
		*	@param spriteSize, Vec2 Size of the sprite.
		*	@param position, Vec2 position of sprite.
		*	@param path, std::string path to sprite asset.
		*	@param numFrames, int number of frames.
		*/
		void create(Vec2 spriteSize, Vec2 position, std::string path, int numFrames);

		/**
		*	Create basic sprite with one frame.
		*	@param world, b2World to add the sprite body to.
		*	@param spriteSize, Vec2 Size of the sprite.
		*	@param position, Vec2 position of sprite.
		*	@param path, std::string path to sprite asset.
		*	@param numFrames, int number of frames.
		*	@param den, float value for body dentisty.
		*	@param fri, float value for body friction.
		*	@param fixedRotation, bool value.
		*/
		void createWithPhysics(b2World* world, Vec2 spriteSize, Vec2 position, std::string path, int numFrames, float den, float fri, bool FixedRotation);
		
		/**
		*	Change the sprite texture of a sprite that is all ready loaded
		*	@param spriteSize, Vec2 Size of the sprite.
		*	@param position, Vec2 position of sprite.
		*	@param path, std::string path to sprite asset.
		*	@param numFrames, int number of frames.
		*/
		void updateTexure(Vec2 spriteSize, Vec2 position, std::string path, int numFrames);

		/**
		*	Get the collision body of the sprite.
		*	@return b2Body, the sprites collision body
		*/
		b2Body* getCollisionBody() { return m_CollisionShape->getBody(); }
		
		/**
		*	Destroy the sprite.
		*/
		void destroy();

	private:

	};
}

#endif //!_SPRITE_