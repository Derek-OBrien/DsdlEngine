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

	//Add bg
	auto bg = new Sprite();
	bg->create(Vec2(1920, 1080), Vec2::ZERO, XmlLocalStorage::getInstance()->getStringForKey("menubg"));
	bg->setPosition(Vec2::ZERO);

	//Add to Layer
	layer->addNodeToLayer(bg);

	//Add Gui Elements
	auto scoreLabel = new Label();

	//scoreLabel->create(Vec2(GAME_WIDTH / 2, GAME_HEIGHT / 3), (" %d ", XmlLocalStorage::getInstance()->getIntegerForKey("score")), 60, SDL_Color{ 0,255,255 }, XmlLocalStorage::getInstance()->getStringForKey("font"));
//	layer->addNodeToLayer(scoreLabel);


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
