
#ifndef _MAINGAME_
#define _MAINGAME_

#include "EngineDefines.h"
#include "DsdlEngine.h"
#include "Window.h"
#include "InputManager.h"
#include "Timing.h"
#include "AudioManager.h"


namespace DsdlEngine{
	
	class SceneManager;
	class IScene;

	class IMainGame{
	public:
		IMainGame();
		virtual ~IMainGame();
		
		/*
			User MUST call to run game
		*/
		void run();

		/*
			Functions user can use to customize game window and fps
		*/
		void setupWindow(int w, int h, std::string windowName, unsigned int flag);
		void setFps(float fps){ m_fFps = fps; }

		/*
			Functions User must over ride when creating a game
		*/
		virtual void onInit() = 0;
		virtual void addScenes() = 0;
		virtual void onExit() = 0;


	protected:
		unsigned int windowFlag;
		int m_windowWidth;
		int m_windowHeight;
		std::string windowtitle;

		std::unique_ptr<SceneManager> m_pSceneManager = nullptr;

		IScene* m_pCurrentRunning = nullptr;
		bool m_bIsRunning = false;
		float m_fFps = 0;

		Window m_Window;
		SDL_Renderer* m_pGameRenderer = nullptr;
		InputManager m_InputManager;
		AudioManager m_audioManager;

	private:
		void exitGame();

		void update();
		void draw();

		bool init();
		bool initSystems();

		const float getFps() const{ return m_fFps; }
		void onSDLEvent(SDL_Event& evnt);

	};
}

#endif