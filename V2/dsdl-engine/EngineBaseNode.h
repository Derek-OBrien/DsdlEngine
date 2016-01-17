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
		
		virtual void render(SDL_Renderer* r) = 0;

	private:

	};
}

#endif