#include "App.h"
#include <dsdl-engine/SceneManager.h>

App::App(){}

App::~App(){}

void App::onInit(){

	///m_pWindow.createWindow("Test Scene Manager", 1024, 512, 2);
	//m_pGameplayScene->buildScene();
}

void App::addScenes(){

	m_pSceneManager->getInstance()->addScene(m_pGameplayScene);
	m_pSceneManager->getInstance()->setScene(m_pGameplayScene->getSceneIndex());
}

void App::onExit(){

}
