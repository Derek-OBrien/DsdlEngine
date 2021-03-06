
#include "GamePlayScene.h"
#include "GameDefines.h"
#include "EnemyManager.h"
#include "SimpleBoxCollision.h"

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
	hud->destroy();
	music.audioStopBG();
	m_AudioManager.destroy();
	world->DestroyBody(groundBody);
}

void GamePlayScene::onEntryScene(){
	
	//Create Layer
	layer = new Layer();
	hud = new HudLayer();

	//Add Audio Manager
	music = m_AudioManager.loadMusic(XmlLocalStorage::getInstance()->getStringForKey("bgmusic"));
	sfx = m_AudioManager.loadSFX(XmlLocalStorage::getInstance()->getStringForKey("sfx"));

	// Define the gravity vector.
	b2Vec2 gravity(0.0f, 0.0f);
	
	world = new b2World(gravity);
	//world->SetContactListener(&collisionManager);

	// Define the ground body.
	groundBodyDef = new b2BodyDef();
	groundBodyDef->position.Set(0.0, GAME_HEIGHT * PIXELSTOMETRES- 130);
	groundBody = world->CreateBody(groundBodyDef);

	groundBox = new b2PolygonShape();
	groundBox->SetAsBox(GAME_WIDTH * PIXELSTOMETRES, 20.0f * PIXELSTOMETRES );
	groundBody->CreateFixture(groundBox, 0.0);

	
	//Add Background
	bg = new ScrollingBg();
	bg->create(XmlLocalStorage::getInstance()->getStringForKey("gamebg"));
	layer->addNodeToLayer(bg->scrollingImage);


	//Add Character
	m_player = new Character();
	m_player->init(world);
	layer->addNodeToLayer(m_player->m_sprite);

	//Add Enemy & Coins
	
	Spawner::GetInstance()->FillEnemyVec(world, layer);

	//Add Middle Ground
	mg = new ScrollingBg();
	mg->create(XmlLocalStorage::getInstance()->getStringForKey("gamemg"));
	layer->addNodeToLayer(mg->scrollingImage);


	fg = new ScrollingBg();
	fg->create(XmlLocalStorage::getInstance()->getStringForKey("gamefg"));
	fg->scrollingImage->setOpacity(120);
	layer->addNodeToLayer(fg->scrollingImage);



	//Add Layer to Scene
	addLayerToScene(layer);
	addLayerToScene(hud->createHud());
	
	music.play(-1);


	bgSpeed = 3;
}

void GamePlayScene::onExitScene(){
	destroyScene();
}

void GamePlayScene::updateScene(){
	
	
	///Physics world step
	world->Step(timeStep, velocityIterations, positionIterations);

	
	///Process Input
	onInput();
	m_player->update(m_game->m_InputManager, world);
	
	checkCollision();

	///update score
	hud->updateScore();

	///Update Game Elements
	bg->update(bgSpeed * 2);
	mg->update(bgSpeed);
	fg->update(bgSpeed);
	
	if (m_player->getPlayerState() == EPlayerState::SLIDING) {
		///Update Game Elements
		bg->update(bgSpeed * 4);
		mg->update(bgSpeed * 2);
		fg->update(bgSpeed * 2);

	}
	///update enemy and coin positions
	Spawner::GetInstance()->update();
	
}


void GamePlayScene::onInput() {
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt)) {

		hud->onInput(m_game, m_player,music);
		m_game->onSDLEvent(evnt);
		
	}
}

void GamePlayScene::checkCollision() {

	auto spawner = Spawner::GetInstance();
	for (size_t i = 0; i < spawner->getCoinVec().size(); i++)
	{
		if (SimpleBoxCollision::getInstance()->check(
			m_player->m_sprite->getBoundingBox(), 
			spawner->getEnemyVec().at(i)->m_enemySprite->getBoundingBox())) {

			hud->checkHighScore();

			hud->saveScore();

			m_sceneIndex = SCENE_INDEX_OVER;
			m_eCurrentState = DsdlEngine::SceneState::CHANGE_NEXT;
		
		}

		if (SimpleBoxCollision::getInstance()->check(
			m_player->m_sprite->getBoundingBox(), 
			spawner->getCoinVec().at(i)->m_coinSprite->getBoundingBox())) {

			layer->removeNodeFromLayer(spawner->getCoinVec().at(i)->m_coinSprite);
			
			hud->updateCoinCount(1);
			sfx.play(0);
			break;
		}
	}
}