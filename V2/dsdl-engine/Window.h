#ifndef _WINDOW_
#define _WINDOW_

#include "EngineDefines.h"

namespace DsdlEngine{

	class Window
	{
	public:
		Window();
		~Window();

		int createWindow(std::string windowNname, int screenWidth, int screenHeight, unsigned int flag);
		void swapBuffer();

		int getScreenWidth() { return m_screenWidth; }
		int getScreenHeight() { return m_screenHeight; }

	private:

		SDL_Window* m_pSdlWindow;
		SDL_Renderer* m_pSdlRenderer;
		int m_screenHeight, m_screenWidth;

	};
}
#endif