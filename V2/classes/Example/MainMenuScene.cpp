
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
	m_label.create(300,200,"Main Menu", 70, SDL_Color{ 200, 200, 0 }, "../../assets/fonts/font.ttf", m_window->getRenderer());
	m_button.createTextButton(200, 300, 200, 50, 30, "New Game", m_window->getRenderer(), "../../assets/fonts/font.ttf", SDL_Color{ 255, 0, 0 }, SDL_Color{ NULL, NULL, NULL });
	m_SpriteButton.createSpriteButton(400, 400, 100, 100, m_window->getRenderer(), "../../assets/Character.png");
}

void MainMenuScene::onExitScene(){
	m_nextScreenIndex = SCENE_INDEX_GAMEPLAY;
	m_eCurrentState = DsdlEngine::SceneState::CHANGE_NEXT;
}

void MainMenuScene::updateScene(){

	checkInput();
}

void MainMenuScene::drawScene(){
	m_label.render(m_window->getRenderer());
	m_button.render( m_window->getRenderer());
	m_SpriteButton.render(m_window->getRenderer());
}

void MainMenuScene::addChild(){

}

void MainMenuScene::renderChildNodes(){

}

void MainMenuScene::checkInput(){
	
	m_inputManager.update();
	

	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		
		m_button.checkInput(evnt);
		m_SpriteButton.checkInput(evnt);
		switch (evnt.type) {
		case SDL_QUIT:
			exit(1);
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

	if (m_inputManager.isKeyDown(SDLK_a)){
		onNewGameClicked();
		DEBUG_MSG("A button pressed Should Change scene");
	}

}

bool MainMenuScene::onNewGameClicked(){
	m_nextScreenIndex = SCENE_INDEX_GAMEPLAY;
	m_eCurrentState = DsdlEngine::SceneState::CHANGE_NEXT;
	return true;
}
