
#include "GamePlayScene.h"
#include "GameDefines.h"

GamePlayScene::GamePlayScene(){
	m_sceneIndex = SCENE_INDEX_GAMEPLAY;
}
GamePlayScene::~GamePlayScene(){}


int GamePlayScene::getNextSceneIndex() const{
	return SCENE_INDEX_NO_SCENE;

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
	
	//Add Background
	bg = new ScrollingBg();
	bg->create("DemoGame/backgrounds/bg_city.png");
	
	//Add Middle Ground
	mg = new ScrollingBg();
	mg->create("DemoGame/backgrounds/bg_image.png");
	
	//Add Character
	myChar2 = new Character();
	myChar2->init();
	

	//Add Nodes to Layer
	layer->addNodeToLayer(bg->bg);
	layer->addNodeToLayer(myChar2->m_sprite);
	layer->addNodeToLayer(mg->bg);
	
	//Add Layer to Scene
	addLayerToScene(layer);
}

void GamePlayScene::onExitScene(){
	destroyScene();
}

void GamePlayScene::updateScene(){

	bg->update();
	mg->update();
	checkInput();
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
			//Touch down
		case SDL_FINGERDOWN:
			m_inputManager.pressKey(evnt.button.button);
			break;
		case SDL_FINGERMOTION:
			m_inputManager.setMouseCoords((float)evnt.motion.x, (float)evnt.motion.y);
			break;
		case SDL_FINGERUP:
			m_inputManager.releaseKey(evnt.button.button);
			break;
		default:
			break;
		}
	}
}