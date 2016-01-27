#ifndef _SPRITE_
#define _SPRITE_

#include "EngineBaseNode.h"

namespace DsdlEngine{

	class Sprite :public EngineBaseNode
	{
	public:
		Sprite();
		~Sprite();


		/**
		* Create a Sprite
		*
		* @param width The width of the sprite
		* @param height the height of the sprite
		* @param path The path to the Sprite asset
		* 
		*/

		void create(int width, int height, std::string path);
		void create(int width, int height, std::string path, int numFrames);

		void setPosition(Vec2 pos){ position.x_ = pos.x_; position.y_ = pos.y_; }
		void setPosX(int x){ position.x_ += x; objectBoundingBox.x += x; }
		void setPosY(int y){ position.y_ += y; objectBoundingBox.y += y; }


		//int Set number of sprite sprite frames in animation
	private:

	};
}

#endif