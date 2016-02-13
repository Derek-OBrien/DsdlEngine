
#include "EngineDefines.h"
#include "DsdlEngine.h"

namespace DsdlEngine{

	int init(){
		//Initialize SDL
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
			
		
		SDL_Log("Log Print SDL Finised Init!\n");
		
		
		TTF_Init();

		//SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

		///Set double Buffer
		//SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		return 0;
	}
}