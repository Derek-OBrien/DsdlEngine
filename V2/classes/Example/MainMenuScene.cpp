
#include "MainMenuScene.h"


MainMenuScene::MainMenuScene(DsdlEngine::Window* window) : m_window(window){

	m_nextScreenIndex = SCENE_INDEX_MAINMENU;
}
MainMenuScene::~MainMenuScene(){}

int MainMenuScene::getNextSceneIndex() const{
	return m_nextScreenIndex;
}


int MainMenuScene::getPreviousSceneIndex() const{
	return SCENE_INDEX_NO_SCENE;
}

void MainMenuScene::buildScene(){
	
}

void MainMenuScene::destroyScene(){

}

void MainMenuScene::onEntryScene(){
	m_label.create("Main Menu", 70, SDL_Color{ 200, 200, 0 }, "../../assets/fonts/font.ttf", m_window->getRenderer());
	m_button.createTextButton(200, 300, 200, 50, 30, "New Game", m_window->getRenderer(), "../../assets/fonts/font.ttf", SDL_Color{ 255, 0, 0 }, SDL_Color{ NULL, NULL, NULL });
	m_SpriteButton.createSpriteButton(400, 400, 100, 100, m_window->getRenderer(), "../../assets/Character.png");
}

void MainMenuScene::onExitScene(){
	m_nextScreenIndex = SCENE_INDEX_GAMEPLAY;
	m_eCurrentState = DsdlEngine::SceneState::CHANGE_NEXT;
	m_label.render(20, 20, m_window->getRenderer());
}

void MainMenuScene::updateScene(){

	checkInput();
}

void MainMenuScene::drawScene(){
	m_label.render(500, 100, m_window->getRenderer());
	m_button.render( m_window->getRenderer());
	m_SpriteButton.render(m_window->getRenderer());
}

void MainMenuScene::addChild(){

}

void MainMenuScene::checkInput(){
	
	m_inputManager.update();
	

	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		
		m_button.checkInput(evnt);
		m_SpriteButton.checkInput(evnt);
		switch (evnt.type) {
		case SDL_QUIT:
		
			break;
		}
	}

	if (m_inputManager.isKeyPressed(SDLK_a)){
		onExitScene();
	}

}

bool MainMenuScene::onNewGameClicked(){
	m_nextScreenIndex = SCENE_INDEX_GAMEPLAY;
	m_eCurrentState = DsdlEngine::SceneState::CHANGE_NEXT;
	return true;
}
