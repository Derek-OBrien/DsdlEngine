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

		SDL_Log("Width %d :", gScreenRect.w);

		SDL_Log("height %d :", gScreenRect.h);
		//Load Window for windows using size passed in
#ifdef __WIN32__
		SDL_Log("Windows Created for Windows Platform");
		m_pSdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gScreenRect.w, gScreenRect.h, flag);
		m_pSdlRenderer = SDL_CreateRenderer(m_pSdlWindow, -1, SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		SDL_SetRenderDrawColor(m_pSdlRenderer, 0, 0, 0, 120);
		//EngineMaster::getInstance()->setWindowSize(m_screenHeight, m_screenWidth);
#endif

		//Load Window for Android using device screen Size
#ifdef __ANDROID__
		SDL_Log("Windows Created for Android Platform");
		m_pSdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gScreenRect.w, gScreenRect.h, SDL_WINDOW_ALLOW_HIGHDPI);
		m_pSdlRenderer = SDL_CreateRenderer(m_pSdlWindow, -1, SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		SDL_SetRenderDrawColor(m_pSdlRenderer, 0, 0, 0, 120);
		//EngineMaster::getInstance()->setWindowSize(gScreenRect.h, gScreenRect.w);
#endif


		if (m_pSdlWindow == nullptr){
			DEBUG_MSG("SDL_CreateWindow Error : " + std::string(SDL_GetError()));
			SDL_Log("Window could not be created! SDL Error: %s\n", SDL_GetError());
		}
		

		//Initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags)){
			DEBUG_MSG("SDL_image could not initialize! SDL_image Error:" + std::string(IMG_GetError()));
			SDL_Log("SDL_image could not initialize! SDL_image Error %s\n", IMG_GetError());
		}
		SDL_Log("Image Flag Init ok");

		//Set up our OpenGL context
		//SDL_GLContext glContext = SDL_GL_CreateContext(m_pSdlWindow);

		//Set VSYNC
		//SDL_GL_SetSwapInterval(0);

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