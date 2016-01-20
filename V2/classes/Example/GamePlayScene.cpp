
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


	DsdlEngine::Music music = m_AudioManager.loadMusic("Sound/XYZ.ogg");
	music.play(-1);


	b2Vec2 gravity(0.0f, 25.8f);
	m_World = new b2World(gravity);

	m_texture = m_texture.loadTexture("bricks.png", m_window->getRenderer());

	m_label.create(100, 100,"GamePlay Scene", 70, SDL_Color{ 200, 200, 0 }, "fonts/font.ttf", m_window->getRenderer());
	addChild(m_label);

	// Make the ground
	b2BodyDef groundBodyDef;
	groundBodyDef.type = b2_staticBody;

	groundBodyDef.position.Set(0.0f, 25.0f);
	b2Body* groundBody = m_World->CreateBody(&groundBodyDef);

	// Make the ground fixture
	b2PolygonShape groundBox;
	groundBox.SetAsBox(1024.0f, 100.0f);
	groundBody->CreateFixture(&groundBox, 1.0f);


	// Make a bunch of boxes
	std::mt19937 randGenerator;
	std::uniform_real_distribution<float> xPos(100, m_window->getScreenWidth() - 300);
	std::uniform_real_distribution<float> yPos(20, m_window->getScreenHeight() - 300);
	const int NUM_BOXES = 20;

	for (int i = 0; i < NUM_BOXES; i++) {
		Box newBox;
		newBox.init(m_World, xPos(randGenerator), yPos(randGenerator), 50, 50, m_texture);
		boxes.push_back(newBox);
		
	}
}

void GamePlayScene::onExitScene(){

}

void GamePlayScene::updateScene(){

	checkInput();

	// Update the physics simulation
	m_World->Step(1.0f / 60.0f, 6, 2);

	for (int i = 0; i < boxes.size(); i++){
		// Now print the position and angle of the body.
		b2Vec2 position = boxes.at(i).getbody()->GetPosition();
		float32 angle = boxes.at(i).getbody()->GetAngle();

		printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);

	}
}

void GamePlayScene::drawScene(){


	for (int i = 0; i < boxes.size(); i++){

		boxes.at(i).draw(m_window->getRenderer());
	}
}


/*void GamePlayScene::addChild(){

	sceneChildren.push_back(m_label);
	
}

void GamePlayScene::renderChildNodes(){

	for (int i = 0; i < sceneChildren.size(); i++){
		sceneChildren.at(i).render(m_window->getRenderer());
	}
}*/

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