#ifndef _WINDOW_
#define _WINDOW_

#include "EngineDefines.h"

namespace DsdlEngine{

	class Window
	{
	public:
		Window();
		virtual ~Window();
		
		//Create window
		int createWindow(std::string windowNname, int screenWidth, int screenHeight, unsigned int flag);
		void swapBuffer();

		//Get Window Width and Height
		int getScreenWidth() { return m_screenWidth; }
		int getScreenHeight() { return m_screenHeight; }

		//Get Renderer
		SDL_Renderer* getRenderer(){ return m_pSdlRenderer; }

		void destroy();
	private:

		SDL_Window* m_pSdlWindow;
		SDL_Renderer* m_pSdlRenderer;
		SDL_Surface* m_pScreenSurface;

		int m_screenHeight, m_screenWidth;


	};
}
#endif