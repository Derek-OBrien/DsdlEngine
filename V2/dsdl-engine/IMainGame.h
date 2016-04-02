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
/**
*	@author Derek O Brien
*/

namespace DsdlEngine{
	
	///Forward Declare Classes
	class SceneManager;
	class IScene;

	/**
	*	IMainGame is the heart of the engine as it contians the mian game loop and ties all the engine together with the game.
	*	Users must inherit from this class to make their application entry point.
	*/
	class IMainGame{

	public:
		/**
		*	Constructor
		*/
		IMainGame();

		/**
		*	Deconstructor
		*/
		virtual ~IMainGame();
		
		/**
		*	run, called in main file, runs the main game loop.
		*/
		void run();

		/**
		*	setupWindow, sets up the window defaults for Windows Platform.
		*	@parma w as int width of the window.
		*	@parma h as int height of the window.
		*	@parma windowName as a std::string name of the window.
		*	@parma path as std::string path to the windows root assets folder.
		*	@parma flag as int SDL window creation flag
		*/
		void setupWindow(int w, int h, std::string windowName, std::string path, int flag);
		
		/**
		*	setFps, Set the desired frame rate for the game.
		*	@parma fps as a float value
		*/
		void setFps(float fps){ m_fFps = fps; }

		/**
		*	onInit, pure virtual function for user custom logic
		*	should be used to setup window and fps as it is called before window is created.
		*/
		virtual void onInit() = 0;

		/**
		*	addScenes, pure virtual function for user custom logic.
		*	this is where the user can add their scenes to the game scene manager (m_pSceneManager)
		*	it is called at start of main loop.
		*/
		virtual void addScenes() = 0;

		/**
		*	onExit, pure virtual function for user custom logic.
		*	called when exiting the game, so user should implement any cleaup they want to do in here.
		*/
		virtual void onExit() = 0;

		/**
		*	onSDLEvent, the games main Event listner
		*	@parma envt as an SDL_Event
		*/
		void onSDLEvent(SDL_Event& evnt);

		/**
		*	setPaused, Pauses the main game loop.
		*/
		void setPaused() { m_bIsPaused = true; }

		/**
		*	setRunning, Starts the game loop running if paused.
		*/
		void setRunning() { m_bIsPaused = false; m_bIsRunning = true; }

		/**
		*	checkPaused, check if the game is currently paused.
		*	@return bool
		*/
		bool checkPaused() { return m_bIsPaused; }

		InputManager m_InputManager;		/**< Main games inputmanage object*/
	protected:
		//Scene Manager
		std::unique_ptr<SceneManager> m_pSceneManager;	/**< Main Scene Manager for the Engine*/

		//Current Scene
		IScene* m_pCurrentRunning;						/**< current running scene*/
		bool m_bIsRunning, m_bIsPaused;					/**< bool variables for control*/

		Window m_Window;								/**< the main window variable */
		SDL_Renderer* m_pGameRenderer;					/**< the engine renderer*/
		
		AudioManager m_audioManager;					/**< the main AudioManager*/
		
	private:

		//Game frame rate
		float m_fFps;									/**< engines fps*/

		//Game Windows details
		unsigned int windowFlag;						/**< windowFlag variable*/
		int m_windowWidth;								/**< window width variabel*/
		int m_windowHeight;								/**< window height variable*/
		std::string windowtitle;						/**< window title variable*/
		std::string mainAssetsPath;						/**< asset path to windows assets folder*/


		/**
		*	getFps, Get the running Frame Rate.
		*	@return float fps,
		*/
		const float getFps() const { return m_fFps; }

		/**
		*	mainLoop The main game loop for the engine and game.
		*/
		void mainLoop();

		/**
		*	update, the main update function, called once every loop cycle
		*	updates any node that needs updating
		*/
		void update();

		/**
		*	draw, the main draw function, called once every loop cycle.
		*	calls all nodes draw functions and display the node to window
		*/
		void draw();

		/**
		*	init, Initilazie the engine subsystems.
		*	@return bool.
		*/
		bool init();

		/**
		*	initSystems. Create the SDL window and Renderer.
		*	@return bool.
		*/
		bool initSystems();

		/**
		*	exitGame. Cleans up and exits the game.
		*/
		void exitGame();

	};
}

#endif //!_MAINGAME_