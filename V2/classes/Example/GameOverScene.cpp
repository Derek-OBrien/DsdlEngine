#include "GameOverScene.h"


GameOverScene::GameOverScene() {}

GameOverScene::~GameOverScene() {}

int GameOverScene::getNextSceneIndex() const {
	return m_nextScreenIndex;
}
int GameOverScene::getPreviousSceneIndex() const {
	return SCENE_INDEX_GAMEPLAY;
}

void GameOverScene::destroyScene() {
	layer->destroy();
}

void GameOverScene::onEntryScene() {
	layer = new Layer();



	addLayerToScene(layer);
}


void GameOverScene::onExitScene() {
	destroyScene();
}

void GameOverScene::updateScene() {

}


bool GameOverScene::changeNext() {
	//Set Next Scene to load
	m_nextScreenIndex = SCENE_INDEX_MAINMENU;
	m_eCurrentState = DsdlEngine::SceneState::CHANGE_NEXT;

	return 0;
}
