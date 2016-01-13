#include "IMainGame.h"


#include "SceneManager.h"
#include "IScene.h"


namespace DsdlEngine{
	IMainGame::IMainGame(){
		m_pSceneManager->getInstance();
	}

	IMainGame::~IMainGame(){}
	
	void IMainGame::run(){
		if (!init()) return;

		const float DESIRED_FPS = 60.0f;
		const float MS_PER_SECOND = 1000;

		const float DESIRED_FRAMETIME = MS_PER_SECOND / DESIRED_FPS; // The desired frame time per frame
		const float MAX_DELTA_TIME = 1.0f; // Maximum size of deltaTime


		FpsLimiter fpsLimit;
		fpsLimit.setMaxFPS(60.0f);

		// Start our previousTicks variable
		Uint32 previousTicks = SDL_GetTicks();

		m_bIsRunning = true;

		while (m_bIsRunning){
			fpsLimit.begin();
			Uint32 newTicks = SDL_GetTicks();
			Uint32 frameTime = newTicks - previousTicks;
			previousTicks = newTicks; // Store newTicks in previousTicks so we can use it next frame
			// Get the total delta time
			float totalDeltaTime = frameTime / DESIRED_FRAMETIME;

			
			m_InputManager.update();
			update();
			draw();

			m_fFps = fpsLimit.end();
			//std::cout << m_fFps << std::endl;

		//	m_Window.swapBuffer();
		}
	}

	void IMainGame::exitGame(){

		m_pCurrentRunning->onExitScene();

		if (m_pSceneManager->getInstance()){
			m_pSceneManager->getInstance()->destroy();
		}
		m_bIsRunning = false;
	}

	void IMainGame::onSDLEvent(SDL_Event& evnt){

		//Will keep looping until there are no more events to process
		switch (evnt.type) {
		case SDL_QUIT:
			m_bIsRunning = false;
			break;
		case SDL_MOUSEMOTION:
			m_InputManager.setMouseCoords((float)evnt.motion.x, (float)evnt.motion.y);
			break;
		case SDL_KEYDOWN:
			m_InputManager.pressKey(evnt.key.keysym.sym);
			break;
		case SDL_KEYUP:
			m_InputManager.releaseKey(evnt.key.keysym.sym);
			break;
		case SDL_MOUSEBUTTONDOWN:
			m_InputManager.pressKey(evnt.button.button);
			break;
		case SDL_MOUSEBUTTONUP:
			m_InputManager.releaseKey(evnt.button.button);
			break;
		}
	}

	bool IMainGame::init(){
		DsdlEngine::init();
		m_audioManager.init();



		if (!initSystems()) return false;
		onInit();
		addScenes();

		m_pCurrentRunning = m_pSceneManager->getInstance()->getCurrentScene();
		m_pCurrentRunning->onEntryScene();
		m_pCurrentRunning->setSceneRunning();

		return true;
	}

	bool IMainGame::initSystems(){
	//	m_Window.createWindow("Dsdl Engine", 1024, 680, SDL_WINDOW_OPENGL);
		
	//	m_pGameRenderer = m_Window.getRenderer();
		return true;
	}


	void IMainGame::update(){
		if (m_pCurrentRunning){
			switch (m_pCurrentRunning->getSceneState()){
			case SceneState::RUNNING:
				m_pCurrentRunning->updateScene();
				break;
			case SceneState::CHANGE_NEXT:
				m_pCurrentRunning->onExitScene();
				m_pCurrentRunning = m_pSceneManager->moveNext();
				if (m_pCurrentRunning){
					m_pCurrentRunning->setSceneRunning();
					m_pCurrentRunning->onEntryScene(); 
				}
				break;
			case SceneState::CHANGE_PREVIOUS:
				m_pCurrentRunning->onExitScene();
				m_pCurrentRunning = m_pSceneManager->movePrevious();
				if (m_pCurrentRunning){
					m_pCurrentRunning->setSceneRunning();
					m_pCurrentRunning->onEntryScene();
				}
				break;
			case SceneState::EXIT_APP:
				exitGame();
				break;
			default:
				break;
			}
		}
		else{
			exitGame();
		}
	}
	
	void IMainGame::draw(){
		if (m_pCurrentRunning && m_pCurrentRunning->getSceneState() == SceneState::RUNNING){
			
			//SDL_RenderClear(m_window.getRenderer());


			m_pCurrentRunning->drawScene();

			//m_window.swapBuffer();
			//SDL_SetRenderDrawColor(m_window.getRenderer(), 0x00, 0x00, 0x00, 0xff);
			//SDL_RenderPresent(m_window.getRenderer());

		}

	}
}