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

	m_label = new Label();
	m_label->create("Splash Scene", 80, SDL_Color{ 255, 0, 0 }, "fonts/font.ttf");


	//int posx = EngineMaster::getInstance()->returnWindowWidth() / 2 - m_label->getContentSize().w_ / 2;
	m_label->setPosition(DsdlEngine::Vec2(300, 50));
	addChild(m_label, 1);

	//Set callback
	SDL_TimerID timerID = SDL_AddTimer(3 * 1000, callback, this);

}


void SplashScene::onExitScene(){
	
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
