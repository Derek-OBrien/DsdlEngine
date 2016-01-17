
#include "App.h"
#include <dsdl-engine\SceneManager.h>

App::App() {

}

App::~App() {

}

void App::onInit() {

}

void App::addScenes() {
	m_mainMenuScene = std::make_unique<MainMenuScene>(&m_Window);

	m_gamePlayScene = std::make_unique<GamePlayScene>(&m_Window);

	m_pSceneManager->addScene(m_mainMenuScene.get());
	m_pSceneManager->addScene(m_gamePlayScene.get());

	m_pSceneManager->setScene(m_mainMenuScene->getSceneIndex());
}

void App::onExit() {

}