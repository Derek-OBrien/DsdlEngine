
#include "GamePlayScene.h"
#include "GameDefines.h"


GamePlayScene::GamePlayScene(DsdlEngine::Window* window) : m_window(window){
	m_sceneIndex = SCENE_INDEX_GAMEPLAY;
}
GamePlayScene::~GamePlayScene(){}


int GamePlayScene::getNextSceneIndex() const{
	return SCENE_INDEX_NO_SCENE;

}
int GamePlayScene::getPreviousSceneIndex() const{
	return SCENE_INDEX_MAINMENU;
}

void GamePlayScene::buildScene(){

}

void GamePlayScene::destroyScene(){

}

void GamePlayScene::onEntryScene(){
	m_label.create("GamePlay Scene", 70, SDL_Color{ 200, 200, 0 }, "../../assets/fonts/font.ttf", m_window->getRenderer());
}
void GamePlayScene::onExitScene(){

}

void GamePlayScene::updateScene(){

}
void GamePlayScene::drawScene(){

	m_label.render(m_window->getScreenWidth() / 2 , 100, m_window->getRenderer());

}
void GamePlayScene::addChild(){

}

void GamePlayScene::checkInput(){

}