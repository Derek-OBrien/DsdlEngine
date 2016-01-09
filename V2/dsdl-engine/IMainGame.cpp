#include "IMainGame.h"


#include "SceneManager.h"
#include "IScene.h"


namespace DsdlEngine{
	IMainGame::IMainGame(){
		m_pSceneManager = std::make_unique<SceneManager>(this);
	}

	IMainGame::~IMainGame(){}
	
	void IMainGame::run(){
		if (!init()) return;

		FpsLimiter fpsLimit;
		fpsLimit.setMaxFPS(60.0f);

		m_bIsRunning = true;

		while (m_bIsRunning){
			m_InputManager.update();
			update();
			draw();

			m_fFps = fpsLimit.end();
			m_Window.swapBuffer();
		}
	}

	void IMainGame::exitGame(){

		m_pCurrentRunning->onExitScene();

		if (m_pSceneManager){
			m_pSceneManager->destroy();
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

		if (!initSystems()) return false;
		onInit();
		addScenes();

		m_pCurrentRunning = m_pSceneManager->getCurrentScene();
		m_pCurrentRunning->onEntryScene();
		m_pCurrentRunning->setSceneRunning();

		return true;
	}

	bool IMainGame::initSystems(){
		m_Window.createWindow("Dsdl Engine", 1024, 680, SDL_WINDOW_OPENGL);
		
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
			m_pCurrentRunning->drawScene();
		}

	}
}