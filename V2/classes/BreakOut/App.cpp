
#include "App.h"


#include "../../dsdl-engine/DsdlEngine.h"

#ifdef __ANDROID__
template<typename T, typename ...Args>
std::unique_ptr<T> make_unique(Args&& ...args) {
	return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
#endif


App::App() {
	m_mainMenuScene = nullptr;
	m_gamePlayScene = nullptr;
}

App::~App() {}

void App::onInit() {
	setupWindow(GAME_WIDTH, GAME_HEIGHT, "BreakOut", "../assets/", SDL_WINDOW_OPENGL);

	setFps(550);
}

void App::addScenes() {
	//Create a pointer to all scenes
	m_mainMenuScene = make_unique<MainMenuScene>();
	m_gamePlayScene = make_unique<GamePlayScene>();

	//Add Scenes pointers to the scene manager
	m_pSceneManager->addScene(m_mainMenuScene.get());
	m_pSceneManager->addScene(m_gamePlayScene.get());

	//Set initial sceen to load
	m_pSceneManager->setScene(m_gamePlayScene->getSceneIndex());
}


void App::onExit() {
	m_pSceneManager->destroy();
}