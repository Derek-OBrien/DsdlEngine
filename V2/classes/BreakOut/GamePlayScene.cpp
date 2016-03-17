
#include "GamePlayScene.h"
#include "GameDefines.h"

USING_NS_DSDL;

GamePlayScene::GamePlayScene(){
	m_sceneIndex = SCENE_INDEX_GAMEPLAY;
}

GamePlayScene::~GamePlayScene(){
	//Empty
}


int GamePlayScene::getNextSceneIndex() const{
	return SCENE_INDEX_MAINMENU;

}
int GamePlayScene::getPreviousSceneIndex() const{
	return SCENE_INDEX_MAINMENU;
}


void GamePlayScene::destroyScene(){
	//Destroy Layer and all its nodes
	layer->destroy();

}

void GamePlayScene::onEntryScene(){
	
	//Create Layer
	layer = new Layer();
	hud = new HudLayer();

	//Add Audio Manager
	//music = m_AudioManager.loadMusic(XmlLocalStorage::getInstance()->getStringForKey("bgmusic"));
	
	// Define the gravity vector.
	b2Vec2 gravity(0.0f, 0.0f);
	
	world = new b2World(gravity);
	//world->SetContactListener(&collisionManager);



	//Add Layer to Scene
	addLayerToScene(layer);
	addLayerToScene(hud->createHud());
	
	//music.play(-1);

}

void GamePlayScene::onExitScene(){
	destroyScene();
}

void GamePlayScene::updateScene(){
	
	///Physics world step
	world->Step(timeStep, velocityIterations, positionIterations);

	
	///Process Input
	onInput();
	
	checkCollision();

	///update score
	hud->updateScore();

	//collisionManager.BeginContact(world->GetContactList() ,hud);
	//collisionManager.EndContact(world->GetContactList(), hud);
}


void GamePlayScene::onInput() {
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt)) {

		hud->onInput(m_game);
		m_game->onSDLEvent(evnt);
		
	}
}

void GamePlayScene::checkCollision() {

	
}