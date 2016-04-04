
#include "MainMenuScene.h"
#include "GamePlayScene.h"

#include "../../dsdl-engine/EngineMath.h"


MainMenuScene::MainMenuScene() {}
MainMenuScene::~MainMenuScene(){}

int MainMenuScene::getNextSceneIndex() const{
	return m_nextScreenIndex;
}


int MainMenuScene::getPreviousSceneIndex() const{
	return SCENE_INDEX_SPLASH;
}

void MainMenuScene::destroyScene(){
	//Destroy layer and all child nodes
	layer->destroy();
	gui->destroy();
	m_AudioManager.destroy();
}

void MainMenuScene::onEntryScene(){

	layer = new Layer();	
	gui = new DsdlGui();

	//Add Audio Manager
	music = m_AudioManager.loadMusic("Sound/XYZ.ogg");

	sfx = m_AudioManager.loadSFX("DemoGame/sounds/sfx.wav");
	music.play(-1);


	//Add bg
	auto bg = new Sprite();
	bg->create(Vec2(1920, 1080), Vec2::ZERO, XmlLocalStorage::getInstance()->getStringForKey("menubg"));
	bg->setPosition(Vec2::ZERO);

	//Add to Layer
	layer->addNodeToLayer(bg);
	
	//Add Gui Elements
	gui->addLabel(LableType::LABEL_STATIC, Vec2(GAME_WIDTH / 3, 50), "[ Select Your Runner ]", 50, SDL_Color{ 0, 255, 255 }, XmlLocalStorage::getInstance()->getStringForKey("font"));

	gui->addButton(
		ButtonType::SPRITE_BTN,
		"close",
		Vec2(GAME_WIDTH - 300, 60),
		Vec2(64, 64),
		XmlLocalStorage::getInstance()->getStringForKey("close"),
		SDL_Color{ NULL },
		SDL_Color{ NULL },
		NULL
		);

	gui->addButton(
		ButtonType::SPRITE_BTN,
		"player1",
		Vec2(GAME_WIDTH / 4, 400),
		Vec2(160,300),
		XmlLocalStorage::getInstance()->getStringForKey("player1btn"),
		SDL_Color{ NULL },
		SDL_Color{ NULL },
		NULL
		);

	gui->addButton(
		ButtonType::SPRITE_BTN,
		"player2",
		Vec2((GAME_WIDTH / 4) + GAME_WIDTH / 4, 400),
		Vec2(160, 300),
		XmlLocalStorage::getInstance()->getStringForKey("player2btn"),
		SDL_Color{ NULL },
		SDL_Color{ NULL },
		NULL
		);

	//Add Layer to scene
	addLayerToScene(layer);
	addLayerToScene(gui);
}

void MainMenuScene::onExitScene(){
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

					if (gui->GUIElements.at(i)->getButtonName() == "player2") {
						onNewGameClicked();
						XmlLocalStorage* db = XmlLocalStorage::getInstance();
						db->setStringForKey("player2", "selectedPlayer");
						sfx.play(0);
					}
					if (gui->GUIElements.at(i)->getButtonName() == "player1") {
						onNewGameClicked();
						XmlLocalStorage* db = XmlLocalStorage::getInstance();
						db->setStringForKey("player1", "selectedPlayer");
						sfx.play(0);
					}
					if (gui->GUIElements.at(i)->getButtonName() == "close") {

						m_eCurrentState = DsdlEngine::SceneState::EXIT_APP;
						onExitScene();
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
