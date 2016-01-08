#include "Window.h"

#include "EngineError.h"


namespace DsdlEngine{

	Window::Window(){}
	Window::~Window(){}

	int Window::createWindow(std::string windowName, int screenWidth, int screenHeight, unsigned int flag){

		m_screenHeight = screenHeight;
		m_screenWidth = screenWidth;


		m_pSdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, flag);
		if (m_pSdlWindow == nullptr)
			dsdl_error("SDL Window not created");

		m_pSdlRenderer = SDL_CreateRenderer(m_pSdlWindow, -1, SDL_RENDERER_ACCELERATED);
		if (m_pSdlRenderer == nullptr)
			dsdl_error("SDL Renderer not created");

		SDL_SetRenderDrawColor(m_pSdlRenderer, 0, 0, 0, 255);


		//Set up our OpenGL context
		SDL_GLContext glContext = SDL_GL_CreateContext(m_pSdlWindow);
		if (glContext == nullptr) 
			dsdl_error("SDL_GL context could not be created!");


		//Set VSYNC
		SDL_GL_SetSwapInterval(0);

		return 0;
	}


	void Window::swapBuffer(){
		SDL_GL_SwapWindow(m_pSdlWindow);
	}

}