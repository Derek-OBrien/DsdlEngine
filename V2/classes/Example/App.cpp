
#include "App.h"
//#include <dsdl-engine\SceneManager.h>


#include "../../dsdl-engine/DsdlEngine.h"
//#include <DsdlEngine.h>

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


App::App() {
	m_splashScene = nullptr;
	m_mainMenuScene = nullptr;
	m_gamePlayScene = nullptr;
	//m_pauseScene = nullptr;
	m_gameOverScene = nullptr;
}

App::~App() {}

void App::onInit() {
	setupWindow(GAME_WIDTH, GAME_HEIGHT, "SDL Engine Example Game", "../../assets/", 2);
	SDL_Log("window set up complete");
	setFps(60);
}

void App::addScenes() {
	//Create a pointer to all scenes
	m_splashScene = make_unique<SplashScene>();
	m_mainMenuScene = make_unique<MainMenuScene>();
	m_gamePlayScene = make_unique<GamePlayScene>();
	m_gameOverScene = make_unique<GameOverScene>();

	//Add Scenes pointers to the scene manager
	m_pSceneManager->addScene(m_splashScene.get());
	m_pSceneManager->addScene(m_mainMenuScene.get());
	m_pSceneManager->addScene(m_gamePlayScene.get());
	m_pSceneManager->addScene(m_gameOverScene.get());

	//Set initial sceen to load
	m_pSceneManager->setScene(m_splashScene->getSceneIndex());
}


void App::onExit() {
	m_pSceneManager->destroy();
}