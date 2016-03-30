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
	
	//Forward Declare Classes
	class SceneManager;
	class IScene;

	class IMainGame{

		//Public functions for user to call when creating a game
	public:
		//Constructor 
		IMainGame();

		//Deconstructor
		virtual ~IMainGame();
		
		
		//Calls Main Loop
		void run();

		//Set window defaults
		void setupWindow(int w, int h, std::string windowName, std::string path, int flag);
		//Set Game frame rate
		void setFps(float fps){ m_fFps = fps; }


		//Pure Virtual For Custom logic by user
		virtual void onInit() = 0;
		virtual void addScenes() = 0;
		virtual void onExit() = 0;

		//Main event loop
		void onSDLEvent(SDL_Event& evnt);

		//Pause Game
		void setPaused() { m_bIsPaused = true; }

		//Set Game Running 
		void setRunning() { m_bIsPaused = false; m_bIsRunning = true; }

		//Check if Game is Paused 
		bool checkPaused() { return m_bIsPaused; }

		InputManager m_InputManager;

	protected:
		//Scene Manager
		std::unique_ptr<SceneManager> m_pSceneManager;

		//Current Scene
		IScene* m_pCurrentRunning;
		bool m_bIsRunning, m_bIsPaused;

		//Game Window		
		Window m_Window;
		//Game Renderer
		SDL_Renderer* m_pGameRenderer;
		//Game Audio Manager
		AudioManager m_audioManager;
		
		//Game Resource manager
		//ResourceTexture m_resourceManager;

	private:

		//Game frame rate
		float m_fFps;

		//Game Windows details
		unsigned int windowFlag;
		int m_windowWidth;
		int m_windowHeight;
		std::string windowtitle;
		std::string mainAssetsPath;

		//Get Game Frame Rate
		const float getFps() const { return m_fFps; }

		//Game Main Running Loop
		void mainLoop();

		//Game Main Update Function
		void update();

		//Game Main Draw Function
		void draw();

		//Init Game Subsystems
		bool init();

		//Create game window and renderer
		bool initSystems();

		//Exit Game 
		void exitGame();

	};
}

#endif //!_MAINGAME_