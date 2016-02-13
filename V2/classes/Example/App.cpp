
#include "App.h"
//#include <dsdl-engine\SceneManager.h>


//#include "../../dsdl-engine/DsdlEngine.h"
#include <DsdlEngine.h>

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


App::App() {

	m_mainMenuScene = nullptr;
	m_gamePlayScene = nullptr;
}

App::~App() {}

void App::onInit() {
	setupWindow(1080, 900, "SDL Engine Example Game", 2);
	setFps(120);
}

void App::addScenes() {
	m_mainMenuScene = make_unique<MainMenuScene>(&m_Window);
	m_gamePlayScene = make_unique<GamePlayScene>(&m_Window);

	m_pSceneManager->addScene(m_mainMenuScene.get());
	m_pSceneManager->addScene(m_gamePlayScene.get());

	m_pSceneManager->setScene(m_mainMenuScene->getSceneIndex());
}


void App::onExit() {
	m_pSceneManager->destroy();
}