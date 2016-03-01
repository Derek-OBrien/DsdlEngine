
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

	// Define the gravity vector.
	b2Vec2 gravity(3.0f, 10.0f);

	// Construct a world object, which will hold and simulate the rigid bodies.
	world = new b2World(gravity);

	// Define the ground body.
	groundBodyDef = new b2BodyDef();
	groundBodyDef->position.Set(0.0, 1080 - 130);

	groundBody = world->CreateBody(groundBodyDef);

	// Define the ground box shape.
	groundBox = new b2PolygonShape();

	// The extents are the half-widths of the box.
	groundBox->SetAsBox(1920/2, 10.0f);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(groundBox, 0.0f);

	SDL_Log("Box 2d ground Created");
	
	//Add Background
	bg = new ScrollingBg();
	bg->create("DemoGame/backgrounds/bg_city.png");
	

	SDL_Log("bg Created");

	//Add Middle Ground
	//mg = new ScrollingBg();
	//mg->create("DemoGame/backgrounds/bg_image.png");
	

	SDL_Log("Mg Created");
	//Add Character
	myChar2 = new Character();
	myChar2->init(world);
	

	SDL_Log("Character Created");
	//Add Enemy
	enemy = new Enemy();
	enemy->createEnemy();


	SDL_Log("Enemy Created");
	//Add Nodes to Layer
	layer->addNodeToLayer(bg->bg);
	layer->addNodeToLayer(myChar2->m_sprite);
	layer->addNodeToLayer(enemy->m_enemySprite);
//	layer->addNodeToLayer(mg->bg);
	
	SDL_Log("Nodes Added to layer ");
	
	
	layer->addBox2dNodes(groundBody);
	layer->addBox2dNodes(myChar2->body);
	SDL_Log("Box2d Node addedd to layer");

	//Add Layer to Scene
	addLayerToScene(layer);
	
	SDL_Log("layer added to scene");

}

void GamePlayScene::onExitScene(){
	destroyScene();
}

void GamePlayScene::updateScene(){

	world->Step(timeStep, velocityIterations, positionIterations);

	bg->update();
	//mg->update();

	myChar2->update();
	enemy->update();
	checkInput();
}


void GamePlayScene::checkInput(){
	SDL_Event evnt;

	m_inputManager.update();

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
			//myChar2->jump();
			break;
		case SDL_MOUSEBUTTONUP:
			m_inputManager.releaseKey(evnt.button.button);
			//myChar2->drop();
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