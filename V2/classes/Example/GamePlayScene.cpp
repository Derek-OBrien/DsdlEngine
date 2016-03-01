
#include "GamePlayScene.h"
#include "GameDefines.h"
#include "EnemyManager.h"

USING_NS_DSDL;

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
	EnemyManager::GetInstance()->destroy();

}

void GamePlayScene::onEntryScene(){
	
	//Create Layer
	layer = new Layer();
	fgLayer = new Layer();
	hud = new HudLayer();

	// Define the gravity vector.
	b2Vec2 gravity(1.0f, 10.0f);
	world = new b2World(gravity);

	// Define the ground body.
	groundBodyDef = new b2BodyDef();
	groundBodyDef->position.Set(0.0, 1080 - 130);
	groundBody = world->CreateBody(groundBodyDef);

	groundBox = new b2PolygonShape();
	groundBox->SetAsBox(1920  , (10.0) );
	groundBody->CreateFixture(groundBox, 0.0f);

	
	//Add Background
	bg = new ScrollingBg();
	bg->create("DemoGame/backgrounds/bg_city.png");
	layer->addNodeToLayer(bg->bg);

	//Add Middle Ground
	//mg = new ScrollingBg();
	//mg->create("DemoGame/backgrounds/bg_image.png");
	

	//Add Character
	m_player = new Character();
	m_player->init(world);
	layer->addNodeToLayer(m_player->m_sprite);

	//Add Enemy
	enemy = new Enemy();
	
	m_enemyFactory = new EnemyFactory();
	
	generateEnemy(Vec2(20, 20));

	
	layer->addBox2dNodes(groundBody);
	layer->addBox2dNodes(m_player->m_body);
	
	//Add Layer to Scene
	addLayerToScene(layer);
	//addLayerToScene(fgLayer);

	addLayerToScene(hud->createHud());

}

void GamePlayScene::onExitScene(){
	destroyScene();
}

void GamePlayScene::updateScene(){
	///Physics world step
	world->Step(timeStep, velocityIterations, positionIterations);

	///Process Input
	checkInput();

	///Update Game Elements

	bg->update();
	
	m_player->update();
	
	EnemyManager::GetInstance()->update();
}


void GamePlayScene::generateEnemy(Vec2 position) {
	
	Vec2 pos;
	for (int i = 0; i < 5; i++) {
		switch (i) {
		case 0:
			pos.x_ = GAME_WIDTH + (GAME_WIDTH *0.2);
			pos.y_ = GAME_HEIGHT - 550;

			enemy = m_enemyFactory->createEnemy(world, pos);
			EnemyManager::GetInstance()->AddEnemy(enemy);
			layer->addNodeToLayer(enemy->m_enemySprite);
			layer->addBox2dNodes(enemy->m_body);

			break;
		case 1:
			pos.x_ = GAME_WIDTH + (GAME_WIDTH *0.4);
			pos.y_ = GAME_HEIGHT - 300;
			enemy = m_enemyFactory->createEnemy(world, pos);

			EnemyManager::GetInstance()->AddEnemy(enemy);
			layer->addNodeToLayer(enemy->m_enemySprite);
			layer->addBox2dNodes(enemy->m_body);

			break;
		case 2:
			pos.x_ = GAME_WIDTH + (GAME_WIDTH*0.6);
			pos.y_ = GAME_HEIGHT - 180;
			enemy = m_enemyFactory->createEnemy(world, pos);

			EnemyManager::GetInstance()->AddEnemy(enemy);
			layer->addNodeToLayer(enemy->m_enemySprite);
			layer->addBox2dNodes(enemy->m_body);

			break;
		case 3:
			pos.x_ = GAME_WIDTH + (GAME_WIDTH*0.8);
			pos.y_ = GAME_HEIGHT - 450;
			enemy = m_enemyFactory->createEnemy(world, pos);

			EnemyManager::GetInstance()->AddEnemy(enemy);
			layer->addNodeToLayer(enemy->m_enemySprite);
			layer->addBox2dNodes(enemy->m_body);

			break;
		case 4:
			pos.x_ = GAME_WIDTH + (GAME_WIDTH);
			pos.y_ = GAME_HEIGHT - 250;

			enemy = m_enemyFactory->createEnemy(world, pos);

			EnemyManager::GetInstance()->AddEnemy(enemy);
			layer->addNodeToLayer(enemy->m_enemySprite);
			layer->addBox2dNodes(enemy->m_body);

			break;
		case 5:
			pos.x_ = GAME_WIDTH + (GAME_WIDTH);
			pos.y_ = GAME_HEIGHT - 350;

			enemy = m_enemyFactory->createEnemy(world, pos);

			EnemyManager::GetInstance()->AddEnemy(enemy);
			layer->addNodeToLayer(enemy->m_enemySprite);
			layer->addBox2dNodes(enemy->m_body);

			break;
		default:
			break;
		}
	}
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