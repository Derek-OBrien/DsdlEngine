#include "Window.h"

#include "EngineError.h"

namespace DsdlEngine{

	Window::Window(){}
	Window::~Window() { destroy(); }

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

		//Load Window for windows using size passed in
#ifdef __WIN32__
		SDL_Log("Windows Created for Windows Platform");
		m_pSdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_screenWidth, m_screenHeight, flag);
		m_pSdlRenderer = SDL_CreateRenderer(m_pSdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		SDL_SetRenderDrawColor(m_pSdlRenderer, 0, 0, 0, 120);
		//EngineMaster::getInstance()->setWindowSize(m_screenHeight, m_screenWidth);

#endif

		//Load Window for Android using device screen Size
#ifdef __ANDROID__
		SDL_Log("Windows Created for Android Platform");
		m_pSdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gScreenRect.w, gScreenRect.h, flag);
		m_pSdlRenderer = SDL_CreateRenderer(m_pSdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		SDL_SetRenderDrawColor(m_pSdlRenderer, 0, 0, 0, 120);
		//EngineMaster::getInstance()->setWindowSize(gScreenRect.h, gScreenRect.w);

#endif


		if (m_pSdlWindow == nullptr){
			DEBUG_MSG("SDL_CreateWindow Error : " + std::string(SDL_GetError()));
			SDL_Log("Window could not be created! SDL Error: %s\n", SDL_GetError());
		}
		//Load Window renderer
	/*	m_pSdlRenderer = SDL_CreateRenderer(m_pSdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (m_pSdlRenderer == nullptr){
			DEBUG_MSG("SDL_CreateRenderer Error : " + std::string(SDL_GetError()));
			SDL_Log("SDL_CreateRenderer Error: %s\n", SDL_GetError());
		}
		//Set initial draw color
		SDL_SetRenderDrawColor(m_pSdlRenderer, 0, 0, 0, 255);
		*/
		//Initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags)){
			DEBUG_MSG("SDL_image could not initialize! SDL_image Error:" + std::string(IMG_GetError()));
			SDL_Log("SDL_image could not initialize! SDL_image Error %s\n", IMG_GetError());
		}
		SDL_Log("Image Flag Init ok");

		return 0;
	}


	void Window::swapBuffer(){
		SDL_GL_SwapWindow(m_pSdlWindow);
	}

	void Window::destroy() {
		SDL_DestroyRenderer(m_pSdlRenderer);
		SDL_DestroyWindow(m_pSdlWindow);
		m_pScreenSurface = nullptr;
		SDL_Quit();
	}

}