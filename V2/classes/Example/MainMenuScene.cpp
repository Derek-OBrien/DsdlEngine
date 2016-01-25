
#include "MainMenuScene.h"

#include <dsdl-engine\EngineMath.h>


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

	myChar = new Character();
	myChar->init();
	
	addChild(myChar->m_sprite, 2);


	myChar2 = new Enemy();
	myChar2->createEnemy();

	addChild(myChar2->enemy, 2);


	myChar2 = new Enemy();
	myChar2->createEnemy();
	myChar2->setPosition(DsdlEngine::Vec2(600,600));
	addChild(myChar2->enemy, 2);



	m_label = new Label();
	m_label->create("Main Menu", 50, SDL_Color{ 255, 0, 0 }, "fonts/font.ttf");
	m_label->setPosition(DsdlEngine::Vec2(600,600));


	addChild(m_label, 1);



	m_label = new Label();
	m_label->create("Main Menu fdsfdk", 50, SDL_Color{ 255, 0, 0 }, "fonts/font.ttf");
	m_label->setPosition(DsdlEngine::Vec2::ZERO);

	addChild(m_label, 5);

}

void MainMenuScene::onExitScene(){
	m_nextScreenIndex = SCENE_INDEX_GAMEPLAY;
	m_eCurrentState = DsdlEngine::SceneState::CHANGE_NEXT;
}

void MainMenuScene::updateScene(){

	checkInput();
}

void MainMenuScene::drawScene(){
	
	//renderChildNodes();

	//m_label.render(m_window->getRenderer());
	//m_button.render( m_window->getRenderer());
	//m_SpriteButton.render(m_window->getRenderer());



}

/*void MainMenuScene::addChild(){

	sceneChildren.push_back(m_label);
	sceneChildren.push_back(m_button);
	//sceneChildren.push_back(m_SpriteButton);
}*/

/*void MainMenuScene::renderChildNodes(){

	for (int i = 0; i < sceneChildren.size(); i ++){
		sceneChildren.at(i).render(m_window->getRenderer());
	}
}*/

void MainMenuScene::checkInput(){
	
	m_inputManager.update();
	

	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		
	//	m_button.checkInput(evnt);
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
		//	m_button.onClicked(DsdlEngine::buttonCallBack(onNewGameClicked()));
			break;
		}
	}
}

bool MainMenuScene::onNewGameClicked(){
	m_nextScreenIndex = SCENE_INDEX_GAMEPLAY;
	m_eCurrentState = DsdlEngine::SceneState::CHANGE_NEXT;
	return true;
}
