
#include "GameplayScene.h"
#include <IMainGame.h>
#include <iostream>
#include <SDL.h>

GameplayScene::GameplayScene(){

}

GameplayScene::~GameplayScene(){

}



int GameplayScene::getNextSceneIndex() const{
	return SCENE_INDEX_NO_SCENE;
}

int GameplayScene::getPreviousSceneIndex() const{
	return SCENE_INDEX_NO_SCENE;
}

void GameplayScene::buildScene(){

}

void GameplayScene::destroyScene(){

}

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
}


void GameplayScene::checkInput(){
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt))
	{
		m_pGame->onSDLEvent(evnt);
	}
}