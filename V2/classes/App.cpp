#include "App.h"
#include <SceneManager.h>

App::App(){

}

App::~App(){

}

void App::onInit(){

}

void App::addScenes(){
	m_pGameplayScene = std::make_unique<GameplayScene>();
	m_pSceneManager->addScene(m_pGameplayScene.get());
	m_pSceneManager->setScene(m_pGameplayScene->getSceneIndex());

}

void App::onExit(){

}
