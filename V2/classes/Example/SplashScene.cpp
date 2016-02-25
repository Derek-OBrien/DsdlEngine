#include "SplashScene.h"


//SplashScene::SplashScene(DsdlEngine::Window* window) : m_window(window){}
SplashScene::SplashScene() {}

SplashScene::~SplashScene(){
}

int SplashScene::getNextSceneIndex() const{
	return m_nextScreenIndex;
}


int SplashScene::getPreviousSceneIndex() const{
	return SCENE_INDEX_NO_SCENE;
}


void SplashScene::destroyScene(){
	layer->destroy();
}

Uint32 callback(Uint32 interval, void* splashScene) {
	//Print callback message
	SDL_Log("Timer Callback Called ");
	return ((class SplashScene *)splashScene)->changeNext();
}

bool SplashScene::changeNext() {
	m_nextScreenIndex = SCENE_INDEX_MAINMENU;
	m_eCurrentState = DsdlEngine::SceneState::CHANGE_NEXT;
	
	return 0;
}

void SplashScene::onEntryScene(){

	layer = new Layer();

	auto bg = new Sprite();
	bg->create(1920, 1080, "DemoGame/backgrounds/menu.png");
	bg->setPosition(Vec2::ZERO);

	auto m_label = new Label();
	m_label->create("Splash Scene", 80, SDL_Color{ 255, 0, 0 }, "fonts/font.ttf");
	m_label->setPosition(Vec2(300, 50));


	//Set callback
	SDL_TimerID timerID = SDL_AddTimer(4 * 1000, callback, this);

	layer->addNodeToLayer(bg);
	layer->addNodeToLayer(m_label);

	addLayerToScene(layer);
}


void SplashScene::onExitScene(){
	destroyScene();
}

void SplashScene::updateScene(){

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
			//onNewGameClicked();
			break;
		case SDL_MOUSEBUTTONUP:
			m_inputManager.releaseKey(evnt.button.button);

			//m_button->onClicked(DsdlEngine::buttonCallBack(onNewGameClicked()));
			break;
			//Touch down
		case SDL_FINGERDOWN:
			m_inputManager.pressKey(evnt.button.button);
			SDL_Log("Touch Triggered ");
			//onNewGameClicked();
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
