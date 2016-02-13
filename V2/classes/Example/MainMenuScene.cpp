
#include "MainMenuScene.h"

//#include <dsdl-engine\EngineMath.h>

//#include "../../dsdl-engine/EngineMath.h"
#include <DsdlEngine.h>



MainMenuScene::MainMenuScene(DsdlEngine::Window* window) : m_window(window){

	m_iSceneIndex = SCENE_INDEX_GAMEPLAY;
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

	music = m_AudioManager.loadMusic("Sound/XYZ.ogg");
	music.play(-1);



	m_label = new Label();
	m_label->create("Main Menu", 80, SDL_Color{ 255, 0, 0 }, "fonts/font.ttf");
	m_label->setPosition(DsdlEngine::Vec2(600,5));
	addChild(m_label, 1);



	m_button = new Button();
	m_button->createTextButton(100, 100, 60, "Button", "fonts/font.ttf", SDL_Color{ 0, 255, 0 }, SDL_Color{ 0, 0, 255 });
	m_button->setPosition(DsdlEngine::Vec2(600, 500));
	//m_button->assignCallBack(bool()(onNewGameClicked()));
	addChild(m_button, 4);

}

void MainMenuScene::onExitScene(){
	m_nextScreenIndex = SCENE_INDEX_GAMEPLAY;
	m_eCurrentState = DsdlEngine::SceneState::CHANGE_NEXT;

	m_AudioManager.destroy();
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
			onNewGameClicked();
			break;
		case SDL_MOUSEBUTTONUP:
			m_inputManager.releaseKey(evnt.button.button);

			//m_button->onClicked(DsdlEngine::buttonCallBack(onNewGameClicked()));
			break;
			//Touch down
		case SDL_FINGERDOWN:
			m_inputManager.pressKey(evnt.button.button);
			SDL_Log("Touch Triggered ");
			onNewGameClicked();
			break;
		case SDL_FINGERMOTION:
			m_inputManager.setMouseCoords((float)evnt.motion.x, (float)evnt.motion.y);
			SDL_Log("Touch Motion Triggered ");
			break;
		case SDL_FINGERUP:
			m_inputManager.releaseKey(evnt.button.button);
			SDL_Log("Touch up Triggered ");
			break;
		default:
			break;
		}
	}
}

bool MainMenuScene::onNewGameClicked(){
	m_nextScreenIndex = SCENE_INDEX_GAMEPLAY;
	m_eCurrentState = DsdlEngine::SceneState::CHANGE_NEXT;
	return true;
}
