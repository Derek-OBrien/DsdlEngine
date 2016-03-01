
#include "MainMenuScene.h"
#include "GamePlayScene.h"

#include "../../dsdl-engine/EngineMath.h"


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
	auto gui = new DsdlGui();

	//Add Audio Manager
	music = m_AudioManager.loadMusic("Sound/XYZ.ogg");
	music.play(-1);

	//Add bg
	auto bg = new Sprite();
	bg->create(1920, 1080, "DemoGame/backgrounds/menu.png");
	bg->setPosition(Vec2::ZERO);

	
	//Add Gui Elements
	gui->addButton(ButtonType::LABEL_BTN, Vec2(600, 500), Size(200, 100), "fonts/font.ttf", SDL_Color{ 0,255,255 }, SDL_Color{ 255,0,0 }, "New-Game");
	gui->addLabel(Vec2(20,300) , "Main Menu", 80, SDL_Color{ 255, 0, 0 }, "fonts/font.ttf");
	
	//Add to Layer
	layer->addNodeToLayer(bg);
	
	//Add Layer to scene
	addLayerToScene(layer);
	addLayerToScene(gui);
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
			onNewGameClicked();
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

void MainMenuScene::onNewGameClicked(){
	m_nextScreenIndex = SCENE_INDEX_GAMEPLAY;
	m_eCurrentState = DsdlEngine::SceneState::CHANGE_NEXT;
}
