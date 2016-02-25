
#include "MainMenuScene.h"
#include "GamePlayScene.h"
//#include <dsdl-engine\EngineMath.h>

#include "../../dsdl-engine/EngineMath.h"


//MainMenuScene::MainMenuScene(DsdlEngine::Window* window) : m_window(window) {}
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
}

void MainMenuScene::onEntryScene(){

	layer = new Layer();

	//Add Audio Manager
	music = m_AudioManager.loadMusic("Sound/XYZ.ogg");
	music.play(-1);

	//Add bg
	auto bg = new Sprite();
	bg->create(1920, 1080, "DemoGame/backgrounds/menu.png");
	bg->setPosition(Vec2::ZERO);

	//Add Label
	auto m_label = new Label();
	m_label->create("Main Menu", 80, SDL_Color{ 255, 0, 0 }, "fonts/font.ttf");
	m_label->setPosition(Vec2(600,5));
	
	//Add Button
	auto m_button = new Button();
	m_button->createTextButton(100, 100, 60, "Button", "fonts/font.ttf", SDL_Color{ 0, 255, 0 }, SDL_Color{ 0, 0, 255 });
	m_button->setPosition(Vec2(600, 500));
	
	//Add to Layer
	layer->addNodeToLayer(bg);
	layer->addNodeToLayer(m_label);
	layer->addNodeToLayer(m_button);

	//Add Layer to scene
	addLayerToScene(layer);
}

void MainMenuScene::onExitScene(){
	
	m_AudioManager.destroy();
	destroyScene();
}

void MainMenuScene::updateScene(){

	checkInput();
}


void MainMenuScene::checkInput(){
	
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
			onNewGameClicked();
			break;
		case SDL_MOUSEBUTTONUP:
			m_inputManager.releaseKey(evnt.button.button);
			break;
			//Touch down
		case SDL_FINGERDOWN:
			m_inputManager.pressKey(evnt.button.button);
			SDL_Log("Touch Triggered ");
			onNewGameClicked();
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

bool MainMenuScene::onNewGameClicked(){
	m_nextScreenIndex = SCENE_INDEX_GAMEPLAY;
	m_eCurrentState = DsdlEngine::SceneState::CHANGE_NEXT;

	return true;
}
