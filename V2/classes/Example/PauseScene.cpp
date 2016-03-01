#include "PauseScene.h"


PauseScene::PauseScene() {}
PauseScene::~PauseScene() {}

int PauseScene::getNextSceneIndex() const {
	return m_nextScreenIndex;
}
int PauseScene::getPreviousSceneIndex() const {
	return SCENE_INDEX_GAMEPLAY;
}

void PauseScene::destroyScene() {

}

void PauseScene::onEntryScene() {

}

void PauseScene::onExitScene() {

}

void PauseScene::updateScene() {

}

bool PauseScene::changeNext() {
	return true;
}
