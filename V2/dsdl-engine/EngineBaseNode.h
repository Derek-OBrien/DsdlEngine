#ifndef _ENGINEBASENODE_
#define _ENGINEBASENODE_

#include "EngineDefines.h"
#include "ResourceTexture.h"


namespace DsdlEngine{
	class EngineBaseNode
	{
	public:
		EngineBaseNode();
		~EngineBaseNode();
		
		//Render Node
		void render(SDL_Renderer* r);

		//Set position of node
		void setPosition(const Vec2& pos){ position.x_ = pos.x_, position.y_ = pos.y_; };

	protected:

		ResourceTexture* engineTexture ;
		SDL_Rect objectBoundingBox;

		//nodes position Vec2
		Vec2 position;
	};
}

#endif