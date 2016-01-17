#include "Window.h"

#include "EngineError.h"

namespace DsdlEngine{

	Window::Window(){}
	Window::~Window(){}

	int Window::createWindow(std::string windowName, int screenWidth, int screenHeight, unsigned int flag){

		m_screenHeight = screenHeight;
		m_screenWidth = screenWidth;

		//Screen dimensions
		SDL_Rect gScreenRect = { 0, 0, 320, 240 };

		SDL_DisplayMode displayMode;
		if (SDL_GetCurrentDisplayMode(0, &displayMode) == 0)
		{
			gScreenRect.w = displayMode.w;
			gScreenRect.h = displayMode.h;
		}

		//Load Window
		m_pSdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,/* gScreenRect.w, gScreenRect.h,*/ m_screenWidth, m_screenHeight, flag);
		if (m_pSdlWindow == nullptr){
			DEBUG_MSG("SDL_CreateWindow Error : " + std::string(SDL_GetError()));
			SDL_Log("Window could not be created! SDL Error: %s\n", SDL_GetError());
		}
		//Load Window renderer
		m_pSdlRenderer = SDL_CreateRenderer(m_pSdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (m_pSdlRenderer == nullptr){
			DEBUG_MSG("SDL_CreateRenderer Error : " + std::string(SDL_GetError()));
			SDL_Log("SDL_CreateRenderer Error: %s\n", SDL_GetError());
		}
		//Set initial draw color
		SDL_SetRenderDrawColor(m_pSdlRenderer, 0, 0, 0, 255);
		
		//Initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags)){
			DEBUG_MSG("SDL_image could not initialize! SDL_image Error:" + std::string(IMG_GetError()));
			SDL_Log("SDL_image could not initialize! SDL_image Error %s\n", IMG_GetError());
		}

		return 0;
	}


	void Window::swapBuffer(){
		SDL_GL_SwapWindow(m_pSdlWindow);
	}

}