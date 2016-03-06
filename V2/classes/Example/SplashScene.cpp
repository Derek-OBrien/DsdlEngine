#include "SplashScene.h"


SplashScene::SplashScene() {
	//Empty
}

SplashScene::~SplashScene(){
	//Empty
}

//Get next Scene
int SplashScene::getNextSceneIndex() const{
	return m_nextScreenIndex;
}

//Previous Scene
int SplashScene::getPreviousSceneIndex() const{
	return SCENE_INDEX_NO_SCENE;
}


void SplashScene::destroyScene(){
	layer->destroy();
}

Uint32 callback(Uint32 interval, void* splashScene) {
	return ((class SplashScene *)splashScene)->changeNext();
}

bool SplashScene::changeNext() {
	//Set Next Scene to load
	m_nextScreenIndex = SCENE_INDEX_MAINMENU;
	m_eCurrentState = DsdlEngine::SceneState::CHANGE_NEXT;
	
	return 0;
}

void SplashScene::onEntryScene(){
	//Create Layer
	layer = new Layer();
	auto gui = new DsdlGui();

	//Create Label	
	gui->addLabel(LableType::LABEL_STATIC, Vec2(400, 300), "-[In The Smoke]-", 150, SDL_Color{ 0, 255, 255 }, "fonts/font.ttf");

	//Create Background Sprite
	auto bg = new Sprite();
	bg->create(1980, 1080, "DemoGame/backgrounds/menu.png");
	bg->setPosition(Vec2::ZERO);


	//Set callback
	CallBackTimer timerID = SDL_AddTimer(3 * 1000, callback, this);
	

	//Add Nodes to Layer
	layer->addNodeToLayer(bg);
	
	//Add Scene to Layer
	addLayerToScene(layer);
	addLayerToScene(gui);
}


void SplashScene::onExitScene(){
	destroyScene();
}

void SplashScene::updateScene(){

	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		m_game->onSDLEvent(evnt);
	}
}
