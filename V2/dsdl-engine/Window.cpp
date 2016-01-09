#include "Window.h"

#include "EngineError.h"

#include <SDL_image.h>

namespace DsdlEngine{

	Window::Window(){}
	Window::~Window(){}

	int Window::createWindow(std::string windowName, int screenWidth, int screenHeight, unsigned int flag){

		m_screenHeight = screenHeight;
		m_screenWidth = screenWidth;


		m_pSdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, flag);
		if (m_pSdlWindow == nullptr)
			dsdl_error("SDL Window not created");

		m_pScreenSurface = SDL_GetWindowSurface(m_pSdlWindow);

		m_pSdlRenderer = SDL_CreateRenderer(m_pSdlWindow, -1, SDL_RENDERER_ACCELERATED);
		if (m_pSdlRenderer == nullptr)
			dsdl_error("SDL Renderer not created");

		SDL_SetRenderDrawColor(m_pSdlRenderer, 0, 0, 0, 255);
		
		//Initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());

		return 0;
	}


	void Window::swapBuffer(){
		SDL_GL_SwapWindow(m_pSdlWindow);
	}

}