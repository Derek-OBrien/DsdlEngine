
#ifndef _MAINGAME_
#define _MAINGAME_

#include "DsdlEngine.h"
#include "Window.h"
#include "InputManager.h"
#include "Timing.h"

#include <memory>

namespace DsdlEngine{
	
	class SceneManager;
	class IScene;

	class IMainGame{
	public:
		IMainGame();
		virtual ~IMainGame();
		
		void run();
		void exitGame();

		virtual void onInit() = 0;
		virtual void addScenes() = 0;
		virtual void onExit() = 0;

		const float getFps() const{
			return m_fFps;
		}
		
		void onSDLEvent(SDL_Event& evnt);

	protected:
		virtual void update();
		virtual void draw();

		bool init();
		bool initSystems();

		std::unique_ptr<SceneManager> m_pSceneManager = nullptr;
		IScene* m_pCurrentRunning = nullptr;
		bool m_bIsRunning = false;
		float m_fFps = 0;
		//float m_fTime = 0;
		Window m_Window;
		InputManager m_InputManager;
		//FpsLimiter fpsLimit;
	};
}

#endif