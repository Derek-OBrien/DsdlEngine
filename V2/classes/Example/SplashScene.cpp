#include "SplashScene.h"


SplashScene::SplashScene(Window* window) : m_window(window){
}

SplashScene::~SplashScene(){
}

int SplashScene::getNextSceneIndex() const{
	return m_nextScreenIndex;
}


int SplashScene::getPreviousSceneIndex() const{
	return SCENE_INDEX_NO_SCENE;
}


void SplashScene::destroyScene(){

}

void SplashScene::onEntryScene(){

}

void SplashScene::onExitScene(){

}

void SplashScene::updateScene(){

}
