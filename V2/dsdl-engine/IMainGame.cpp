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
	std::unique_ptr<T> make_unique(Args&& ...args)
	{
		return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
	}


	IMainGame::IMainGame(){
		m_pSceneManager = DsdlEngine::make_unique<SceneManager>(this);
	}

	IMainGame::~IMainGame(){}
	

	/*
		Main engine Game Loop
	*/
	void IMainGame::run(){
		if (!init()) return;

		const float DESIRED_FPS = 60.0f;
		const float MS_PER_SECOND = 1000;

		const float DESIRED_FRAMETIME = MS_PER_SECOND / DESIRED_FPS; // The desired frame time per frame
		const float MAX_DELTA_TIME = 1.0f; // Maximum size of deltaTime


		FpsLimiter fpsLimit;
		fpsLimit.setMaxFPS(m_fFps);

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
		}
	}

	/*
		Main Inputmanager control
	*/

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

	/*
		Get users window information
	*/
	void IMainGame::setupWindow(int w, int h, std::string windowName, unsigned int flag){
		m_windowWidth = w;
		m_windowHeight = h;
		windowtitle = windowName;
		windowFlag = flag;
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

		addScenes();
		
		m_pCurrentRunning = m_pSceneManager->getCurrentScene();
		m_pCurrentRunning->onEntryScene();
		m_pCurrentRunning->setSceneRunning();

		//Load all scene Children nodes
		for (int i = 0; i < m_pCurrentRunning->sceneChildren.size(); i++){
			//switch (m_pCurrentRunning->sceneChildren.at(i)->getNodeType())
			//{
			//case NodeType::SPRITE:
				m_pCurrentRunning->sceneChildren.at(i)->load(m_pGameRenderer);
			//	break;
			//case NodeType::LABEL:
			//	m_pCurrentRunning->sceneChildren.at(i)->load(m_pGameRenderer);
			//	break;
		//	default:
			//	break;
			//}

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
	

	/*
		Render all Scene nodes to screen
	
	*/

	void IMainGame::draw(){
		if (m_pCurrentRunning && m_pCurrentRunning->getSceneState() == SceneState::RUNNING){
			
			SDL_RenderClear(m_pGameRenderer);
			m_pCurrentRunning->drawScene();

			//for running scene 
			//render each node that is in the child vector
			for (int i = 0; i < m_pCurrentRunning->sceneChildren.size(); i++){
					m_pCurrentRunning->sceneChildren.at(i)->render(m_pGameRenderer);
			}


			m_Window.swapBuffer();
			SDL_SetRenderDrawColor(m_pGameRenderer, 0x00, 0x00, 0x00, 0xff);
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