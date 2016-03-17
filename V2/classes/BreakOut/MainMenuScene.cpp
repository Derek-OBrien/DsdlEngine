
#include "MainMenuScene.h"
#include "GamePlayScene.h"

#include "../../dsdl-engine/EngineMath.h"


MainMenuScene::MainMenuScene() {}
MainMenuScene::~MainMenuScene(){}

int MainMenuScene::getNextSceneIndex() const{
	return m_nextScreenIndex;
}


int MainMenuScene::getPreviousSceneIndex() const{
	return SCENE_INDEX_NO_SCENE;
}

void MainMenuScene::destroyScene(){
	//Destroy layer and all child nodes
	layer->destroy();
}

void MainMenuScene::onEntryScene(){

	layer = new Layer();	
	gui = new DsdlGui();

	//Add Gui Elements
	gui->addLabel(
		LableType::LABEL_STATIC,
		Vec2(GAME_WIDTH / 2 + 100, 10),
		"[ BreakOut ]",
		50,
		SDL_Color{ 0, 255, 255 },
		"fonts/font.ttf");

	gui->addButton(
		ButtonType::LABEL_BTN,
		"Play",
		Vec2(GAME_WIDTH / 2 , GAME_HEIGHT / 3),
		Vec2(100, 70),
		"fonts/font.ttf",
		SDL_Color{ 0,255, 124 },
		SDL_Color{ NULL },
		"[ Play ]")
		;
	
	//Add Layer to scene
	addLayerToScene(layer);
	addLayerToScene(gui);
}

void MainMenuScene::onExitScene(){
	
	m_AudioManager.destroy();
	destroyScene();
}

void MainMenuScene::updateScene(){

	this->onInput();
}

void MainMenuScene::onInput() {
	SDL_Event evnt;

	while(SDL_PollEvent(&evnt)) {
		gui->onSDLEvent(evnt);

		switch (evnt.type){
		case SDL_MOUSEBUTTONDOWN:
			for (size_t i = 0; i < gui->GUIElements.size(); i++)
			{
				if (gui->GUIElements.at(i)->m_eCurrentState == ButtonState::PRESSED) {

					if (gui->GUIElements.at(i)->getButtonName() == "Play") {
						onNewGameClicked();
					}
				}
			}

			break;
		default:
			break;
		}
	}
}


void MainMenuScene::onNewGameClicked(){
	m_nextScreenIndex = SCENE_INDEX_GAMEPLAY;
	m_eCurrentState = DsdlEngine::SceneState::CHANGE_NEXT;
}
