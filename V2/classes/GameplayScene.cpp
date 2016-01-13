
#include "GameplayScene.h"
#include <dsdl-engine/IMainGame.h>
#include <iostream>
#include <SDL.h>

GameplayScene::GameplayScene(){}
GameplayScene::~GameplayScene(){}


int GameplayScene::getNextSceneIndex() const{
	return SCENE_INDEX_NO_SCENE;
}

int GameplayScene::getPreviousSceneIndex() const{
	return SCENE_INDEX_NO_SCENE;
}


void GameplayScene::buildScene(){
	m_window.createWindow("TestGame", 1024, 512, 2);
	m_iSceneIndex = 0;
	setSceneRunning();
	m_Player.createSprite(100.0, 200.0, 73.0, 79.0, "../../assets/Character.png", m_window.getRenderer());

}


void GameplayScene::destroyScene(){}


void GameplayScene::onEntryScene(){
	std::cout << "OnEntry\n";
}

void GameplayScene::onExitScene(){

}

void GameplayScene::updateScene(){
//	std::cout << "Update\n";
	checkInput();
}

void GameplayScene::drawScene(){
//	std::cout << "Draw\n";
	SDL_RenderClear(m_window.getRenderer());

	// Draw palyer
	m_Player.draw(m_window.getRenderer());

	m_window.swapBuffer();
	SDL_SetRenderDrawColor(m_window.getRenderer(), 0x00, 0x00, 0x00, 0xff);
	SDL_RenderPresent(m_window.getRenderer());

}


void GameplayScene::addChild(){

}

void GameplayScene::checkInput(){
	m_inputManager.update();

	SDL_Event evnt;
	//Will keep looping until there are no more events to process
	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
		case SDL_QUIT:
			exit(0);
			break;
		case SDL_MOUSEMOTION:
			m_inputManager.setMouseCoords(evnt.motion.x, evnt.motion.y);
			break;
		case SDL_KEYDOWN:
			m_inputManager.pressKey(evnt.key.keysym.sym);
			break;
		case SDL_KEYUP:
			m_inputManager.releaseKey(evnt.key.keysym.sym);
			break;
		case SDL_MOUSEBUTTONDOWN:
			m_inputManager.pressKey(evnt.button.button);
			break;
		case SDL_MOUSEBUTTONUP:
			m_inputManager.releaseKey(evnt.button.button);
			break;
		}
	}


	//Test input manager and player mvement
	if (m_inputManager.isKeyDown(SDLK_d)) {
		m_Player.setPosX(10);
	}

	if (m_inputManager.isKeyDown(SDLK_a)){
		m_Player.setPosX(-10);
	}

	if (m_inputManager.isKeyDown(SDLK_s)) {
		m_Player.setPosY(10);
	}

	if (m_inputManager.isKeyDown(SDLK_w)){
		m_Player.setPosY(-10);
	}
}