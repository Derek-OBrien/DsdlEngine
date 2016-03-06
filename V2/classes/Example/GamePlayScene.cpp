
#include "GamePlayScene.h"
#include "GameDefines.h"
#include "EnemyManager.h"

USING_NS_DSDL;

GamePlayScene::GamePlayScene(){
	m_sceneIndex = SCENE_INDEX_GAMEPLAY;
}

GamePlayScene::~GamePlayScene(){
	//Empty
}


int GamePlayScene::getNextSceneIndex() const{
	return SCENE_INDEX_OVER;

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

	//Add Audio Manager
	music = m_AudioManager.loadMusic("DemoGame/sounds/Severe_Tire_Damage.wav");
	music.play(-1);


	// Define the gravity vector.
	b2Vec2 gravity(0.0f, 50.0f);
	
	world = new b2World(gravity);
	world->SetContactListener(&collisionManager);

	// Define the ground body.
	groundBodyDef = new b2BodyDef();
	groundBodyDef->position.Set(0.0, GAME_HEIGHT - 130);
	groundBody = world->CreateBody(groundBodyDef);

	groundBox = new b2PolygonShape();
	groundBox->SetAsBox(GAME_WIDTH , 10.0f );
	groundBody->CreateFixture(groundBox, 0.0);

	
	//Add Background
	bg = new ScrollingBg();
	bg->create("DemoGame/backgrounds/bg_city.png");
	layer->addNodeToLayer(bg->bg);


	//Add Character
	m_player = new Character();
	m_player->init(world);

	layer->addNodeToLayer(m_player->m_sprite);

	//Add Enemy
	enemy = new Enemy();
	m_enemyFactory = new EnemyFactory();
	generateEnemy(Vec2(20, 20));


	//Add Middle Ground
	mg = new ScrollingBg();
	mg->create("DemoGame/backgrounds/bg_image.png");
	//layer->addNodeToLayer(mg->bg);


	fg = new ScrollingBg();
	fg->create("DemoGame/backgrounds/fg_smoke.png");
	fg->bg->setOpacity(120);
	//layer->addNodeToLayer(fg->bg);

	//Add box2d boxes to render them (Debug only)
	layer->addBox2dNodes(groundBody);
	layer->addBox2dNodes(m_player->m_body);
	
	//Add Layer to Scene
	addLayerToScene(layer);

	addLayerToScene(hud->createHud());

}

void GamePlayScene::onExitScene(){
	destroyScene();
}

void GamePlayScene::updateScene(){
	///Physics world step
	world->Step(timeStep, velocityIterations, positionIterations);

	///Process Input
	this->onInput();
	m_player->update(m_game->m_InputManager);


	hud->updateScore();

	///Update Game Elements
	bg->update();
	mg->update();
	fg->update();

	EnemyManager::GetInstance()->update();
}


void GamePlayScene::onInput() {
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt)) {

		//hud->onInput(m_game);
		m_game->onSDLEvent(evnt);
		
	}
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
