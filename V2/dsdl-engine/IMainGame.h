
#ifndef _MAINGAME_
#define _MAINGAME_

#include "EngineDefines.h"
#include "DsdlEngine.h"
#include "Window.h"
#include "InputManager.h"
#include "Timing.h"
#include "AudioManager.h"
#include "ResourceTexture.h"
#include "Layer.h"


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
		void setupWindow(int w, int h, std::string windowName, std::string path, int flag);
		void setFps(float fps){ m_fFps = fps; }

		/*
			Functions User must over ride when creating a game
			For Custom logic
		*/
		virtual void onInit() = 0;
		virtual void addScenes() = 0;
		virtual void onExit() = 0;


		InputManager m_InputManager;
		void onSDLEvent(SDL_Event& evnt);

		const float getFps() const { return m_fFps; }

		void setPaused() { m_bIsPaused = true; }
		void setRunning() { m_bIsPaused = false; m_bIsRunning = true; }

		bool checkPaused() { return m_bIsPaused; }

	protected:
		std::unique_ptr<SceneManager> m_pSceneManager;

		IScene* m_pCurrentRunning;
		bool m_bIsRunning;
		bool m_bIsPaused;
		
		Window m_Window;
		SDL_Renderer* m_pGameRenderer;

		AudioManager m_audioManager;
		ResourceTexture m_resourceManager;

	private:

		float m_fFps;

		unsigned int windowFlag;
		int m_windowWidth;
		int m_windowHeight;
		std::string windowtitle;
		std::string mainAssetsPath;



		void exitGame();

		void update();
		void draw();

		bool init();
		bool initSystems();
	};
}

#endif