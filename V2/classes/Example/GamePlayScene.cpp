
#include "GamePlayScene.h"
#include "GameDefines.h"


GamePlayScene::GamePlayScene(DsdlEngine::Window* window) : m_window(window){
	m_sceneIndex = SCENE_INDEX_GAMEPLAY;
}
GamePlayScene::~GamePlayScene(){}


int GamePlayScene::getNextSceneIndex() const{
	return SCENE_INDEX_NO_SCENE;

}
int GamePlayScene::getPreviousSceneIndex() const{
	return SCENE_INDEX_MAINMENU;
}

void GamePlayScene::buildScene(){

}

void GamePlayScene::destroyScene(){

}

void GamePlayScene::onEntryScene(){
	m_label.create(100, 100,"GamePlay Scene", 70, SDL_Color{ 200, 200, 0 }, "../../assets/fonts/font.ttf", m_window->getRenderer());

	b2Vec2 gravity(0.0f, -9.8f);
	m_World = std::make_unique<b2World>(gravity);

	//make ground
	b2BodyDef groundbodydef;
	groundbodydef.position.Set(0.0f, -10.f);
	b2Body* groundBody = m_World->CreateBody(&groundbodydef);

	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);

	newBox.init(m_World.get(), 0, 14, 15., 15);

	boxes.push_back(newBox);
}

void GamePlayScene::onExitScene(){

}

void GamePlayScene::updateScene(){

	checkInput();
}

void GamePlayScene::drawScene(){

	m_label.render( m_window->getRenderer());

}
void GamePlayScene::addChild(){

}

void GamePlayScene::renderChildNodes(){

}

void GamePlayScene::checkInput(){

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
			break;
		case SDL_MOUSEBUTTONUP:
			m_inputManager.releaseKey(evnt.button.button);
			break;
		}
	}

}