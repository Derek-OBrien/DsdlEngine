#include "IMainGame.h"


#include "SceneManager.h"
#include "IScene.h"


namespace DsdlEngine{

	/*
	*Added template version of make_unique as Ndk did not support it in its version of STL 
	*Error was make_unique not part of std::
	*After research this was the easiest solution to solve error
	*Ndk-build now builds apk as of 26/01/2016
	*/
	template<typename T, typename ...Args>
	std::unique_ptr<T> make_unique(Args&& ...args){
		return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
	}


	IMainGame::IMainGame(){
		m_pSceneManager = DsdlEngine::make_unique<SceneManager>(this);
	}

	IMainGame::~IMainGame(){
		//Empty
	}
	

	/*
		Main engine Game Loop
	*/
	void IMainGame::run(){

		if (!init()) return;

		FpsLimiter fpsLimit;
		fpsLimit.setMaxFPS(m_fFps);

	
		m_bIsRunning = true;
		while (m_bIsRunning){
			fpsLimit.begin();
	
			m_InputManager.update();
			update();

			draw();
			
			m_fFps = fpsLimit.end();
		}
	}

	/*
		Main Inputmanager control
	*/

	void IMainGame::onSDLEvent(SDL_Event& evnt){

		//Will keep looping until there are no more events to process
		switch (evnt.type) {
		case SDL_QUIT:
			exitGame();
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
			//Touch down
		case SDL_FINGERDOWN:
			m_InputManager.pressKey(evnt.button.button);
			break;
		case SDL_FINGERMOTION:
			m_InputManager.setMouseCoords((float)evnt.motion.x, (float)evnt.motion.y);
			break;
		case SDL_FINGERUP:
			m_InputManager.releaseKey(evnt.button.button);
			break;
		default:
			break;
		}
	}

	/*
		Get users window information
	*/
	void IMainGame::setupWindow(int w, int h, std::string windowName, unsigned int flag){
		m_windowWidth = w;
		m_windowHeight = h;
		windowtitle = windowName;
		windowFlag = flag;

		EngineMaster* em = EngineMaster::getInstance();

		em->setIntegerForKey(m_windowHeight, "windowHeight");
		em->setStringForKey(windowtitle.c_str(), "windowName");
		em->setBoolForKey(true, "TestBool");
		em->setDoubleForKey(0.324, "testDouble");
		em->setFloatForKey(0.3456, "testFloat");



		SDL_Log("get int test %d",em->getIntegerForKey("windowHeight"));
		SDL_Log("get string test %s",em->getStringForKey("windowName").c_str());
		if (em->getBoolForKey("TestBool")) SDL_Log("bool test work");

		SDL_Log("get double test %f",em->getDoubleForKey("testDouble"));
		SDL_Log("get float test %f",em->getFloatForKey("testFloat"));
	}


	/*
	
		Init all Engine elements
	*/
	bool IMainGame::init(){
		DsdlEngine::init();
		m_audioManager.init();
		
		//call game's on init method
		onInit();

		//If window creation fails exit
		if (!initSystems()) {
			DEBUG_MSG("InitSystems Failed : ");
			return false;
		}

		//Add all Scenes
		addScenes();
		
		//Load up First Scene
		m_pCurrentRunning = m_pSceneManager->getCurrentScene();
		m_pCurrentRunning->onEntryScene();
		m_pCurrentRunning->setSceneRunning();

		//Load all scene Children nodes for first scene on init of game
		for (size_t i = 0; i < m_pCurrentRunning->sceneLayers.size(); i++){
			m_pCurrentRunning->loadScene(m_pGameRenderer);
		}

		return true;
	}

	/*
		InitSystem 
		Create window and get window render
	*/
	bool IMainGame::initSystems(){
		m_Window.createWindow(windowtitle, m_windowWidth, m_windowHeight, windowFlag);
		m_pGameRenderer = m_Window.getRenderer();
		return true;
	}


	/*
		Call current scenes update
		Handel switching between scenes
	*/

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
					//Load all scene Children nodes for next scene
					for (size_t i = 0; i < m_pCurrentRunning->sceneLayers.size(); i++) {
						m_pCurrentRunning->loadScene(m_pGameRenderer);
					}
				}
				break;
			case SceneState::CHANGE_PREVIOUS:
				m_pCurrentRunning->onExitScene();
				m_pCurrentRunning = m_pSceneManager->movePrevious();
				if (m_pCurrentRunning){
					m_pCurrentRunning->setSceneRunning();
					m_pCurrentRunning->onEntryScene();
					//Load all scene Children nodes for previous scene
					for (size_t i = 0; i < m_pCurrentRunning->sceneLayers.size(); i++) {
						m_pCurrentRunning->loadScene(m_pGameRenderer);
					}
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
	

	/*
		Render all Scene nodes to screen
	
	*/

	void IMainGame::draw(){
		if (m_pCurrentRunning && m_pCurrentRunning->getSceneState() == SceneState::RUNNING){
			SDL_RenderClear(m_pGameRenderer);
			
			//for running scene render each node that is in the child vector
			for (size_t i = 0; i < m_pCurrentRunning->sceneLayers.size(); i++) {
				m_pCurrentRunning->drawScene(m_pGameRenderer);
			}

			SDL_RenderPresent(m_pGameRenderer);
		}
	}



	/*
		Exit Game
	*/
	void IMainGame::exitGame(){
		m_pCurrentRunning->onExitScene();
		if (m_pSceneManager){
			m_pSceneManager->destroy();
			m_pSceneManager.reset();
		}
		m_bIsRunning = false;
	}
}