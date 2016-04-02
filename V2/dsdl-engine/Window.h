#ifndef _WINDOW_
#define _WINDOW_

#include "EngineDefines.h"

/**
*	@author Derek O Brien
*/

//Wrap Frame Work Code in Namespace
namespace DsdlEngine{
	
	/**
	*	Window class is the engines link to the SDL_Window. The window class is responsible for creating the window and renderer
	*/
	class Window{
	public:
		/**
		*	Constructor
		*/
		Window();

		/**
		*	Deconstructor
		*/
		virtual ~Window();
		

		/**
		*	Create the SDL_Window with the arguments passed in.
		*	@parma windowName, the name of the window.
		*	@parma screenWidth, the width of the window.
		*	@parma screenHeight, the height of the window.
		*	@parma flag, SDL_Window flag to use upon creation
		*	@return int, 0 upon success,
		*/
		int createWindow(std::string windowNname, int screenWidth, int screenHeight, unsigned int flag);
		
		/**
		*	Swap the OpenGl window buffer.
		*/
		void swapBuffer();

		/**
		*	Get the width of the window.
		*	@return int, width of the window.
		*/
		int getScreenWidth() { return m_screenWidth; }

		/**
		*	Get the height of the window.
		*	@return int, height of the window,
		*/
		int getScreenHeight() { return m_screenHeight; }

		/**
		*	Get the SDL_Renderer for the window.
		*	@return SDL_Renderer.
		*/
		SDL_Renderer* getRenderer(){ return m_pSdlRenderer; }

		/**
		*	Destroy the window
		*/
		void destroy();
	private:
		
		SDL_Window* m_pSdlWindow;				/**< the SDL_Window variable	*/
		SDL_Renderer* m_pSdlRenderer;			/**< the SDL_Renderer variable	*/
		SDL_Surface* m_pScreenSurface;			/**< the SDL_Surface variable	*/

		int m_screenHeight, m_screenWidth;		/**<int variables for screenHeight and screenWidth*/

	};
}
#endif	//!_WINDOW_