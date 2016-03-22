
#include "EngineDefines.h"
#include "DsdlEngine.h"

namespace DsdlEngine{

	int init(){
		//Initialize SDL
		SDL_Init(SDL_INIT_AUDIO | SDL_INIT_EVENTS | SDL_INIT_TIMER | SDL_INIT_VIDEO);
			
		SDL_Log("Log Print SDL Finised Init!\n");
		
		//Initialize TTF
		TTF_Init();

		SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

		return 0;
	}
}