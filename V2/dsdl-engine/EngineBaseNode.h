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
		
		void render(SDL_Renderer* r);

	protected:

		ResourceTexture* engineTexture ;
		int m_posX = 0;
		int m_posY = 0;
	};
}

#endif