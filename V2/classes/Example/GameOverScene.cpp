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
	gui->destroy();
}

void GameOverScene::onEntryScene() {
	layer = new Layer();
	gui = new DsdlGui();

	//Add bg
	auto bg = new Sprite();
	bg->create(Vec2(1920, 1080), Vec2::ZERO, XmlLocalStorage::getInstance()->getStringForKey("menubg"));
	bg->setPosition(Vec2::ZERO);

	//Add to Layer
	layer->addNodeToLayer(bg);

	//Add Gui Elements
	auto label = new Label();
	label->create(Vec2(GAME_WIDTH / 3, GAME_HEIGHT / 3), "Score : ", 60, SDL_Color{ 0,255,255 }, XmlLocalStorage::getInstance()->getStringForKey("font"));
	gui->addPreDefineLabel(label, LableType::LABEL_DYNAMIC);

	auto scoreLabel = new Label();
	char str[10];
	
#ifdef __WIN32__	
	sprintf_s(str, " %d ", XmlLocalStorage::getInstance()->getIntegerForKey("score"));
#endif

#ifdef __ANDROID__
	sprintf(str, " %d ", XmlLocalStorage::getInstance()->getIntegerForKey("score"));
#endif
	scoreLabel->create(Vec2(GAME_WIDTH / 2, GAME_HEIGHT / 3), str, 60, SDL_Color{ 0,255,255 }, XmlLocalStorage::getInstance()->getStringForKey("font"));
	gui->addPreDefineLabel(scoreLabel, LableType::LABEL_DYNAMIC);


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
		"restart",
		Vec2(GAME_WIDTH - 200, GAME_HEIGHT - 100),
		Vec2(64, 64),
		XmlLocalStorage::getInstance()->getStringForKey("restart"),
		SDL_Color{ NULL },
		SDL_Color{ NULL },
		NULL
		);


	addLayerToScene(layer);
	addLayerToScene(gui);
}

void GameOverScene::onInput() {
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt)) {
		gui->onSDLEvent(evnt);

		switch (evnt.type) {
		case SDL_MOUSEBUTTONDOWN:
			for (size_t i = 0; i < gui->GUIElements.size(); i++)
			{
				if (gui->GUIElements.at(i)->m_eCurrentState == ButtonState::PRESSED) {

					if (gui->GUIElements.at(i)->getButtonName() == "restart") {
						changeNext();
						break;
					}
					if (gui->GUIElements.at(i)->getButtonName() == "close") {
						m_eCurrentState = DsdlEngine::SceneState::EXIT_APP;
						destroyScene();
						break;
					}
				}
			}
			//break;
		default:
			break;
		}
	}
}



void GameOverScene::onExitScene() {
	destroyScene();
}

void GameOverScene::updateScene() {
	onInput();
}


bool GameOverScene::changeNext() {
	//Set Next Scene to load
	m_nextScreenIndex = SCENE_INDEX_MAINMENU;
	m_eCurrentState = DsdlEngine::SceneState::CHANGE_NEXT;

	return 0;
}
