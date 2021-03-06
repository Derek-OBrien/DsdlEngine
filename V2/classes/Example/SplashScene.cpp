#include "SplashScene.h"
#include "../../dsdl-engine/DsdlEngine.h"

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
	gui->destroy();
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
	
	//Create Game Layer
	layer = new Layer();

	//Create Gui Layer
	gui = new DsdlGui();

	//Create Label	
	gui->addLabel(LableType::LABEL_STATIC, Vec2(400, 300), "-[In The Smoke]-", 100, SDL_Color{ 0, 255, 255 }, XmlLocalStorage::getInstance()->getStringForKey("font"));

	//Create Background Sprite
	auto bg = new Sprite();
	bg->create(Vec2(1980, 1080), Vec2::ZERO,  XmlLocalStorage::getInstance()->getStringForKey("menubg"));
	
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
