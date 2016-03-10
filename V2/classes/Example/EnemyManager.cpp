#include "EnemyManager.h"
#include "GameDefines.h"

static Spawner* instance;

Spawner *Spawner::GetInstance() {
	if(!instance){
		instance = new (std::nothrow) Spawner();
	}
	return instance;
}


Spawner::Spawner() {
	//Empty
}

Spawner::~Spawner() {
	destroy();
}
//Add Enemy to enemy vec
void Spawner::AddEnemy(Enemy* enemy) {
	m_enemies.push_back(enemy);
}

//Add Coin to coin vec
void Spawner::AddCoin(Coins* coin) {
	m_coins.push_back(coin);
}

void Spawner::update() {
	EnemyUpdate();
	CoinUpdate();
}

void Spawner::destroy() {
	for (size_t i = 0; i < m_enemies.size(); i++){
		delete m_enemies.at(i);
	}
	for (size_t i = 0; i < m_coins.size(); i++) {
		delete m_coins.at(i);
	}
}

void Spawner::EnemyUpdate() {
	for (size_t i = 0; i < m_enemies.size(); i++){
		m_enemies.at(i)->update();
	}
}

void Spawner::CoinUpdate() {
	for (size_t i = 0; i < m_coins.size(); i++){
		m_coins.at(i)->update();
	}
}


void Spawner::FillEnemyVec(b2World* world, Layer* layer){
	factory = new Factory();
	
	Vec2 pos;
	for (int i = 0; i < 5; i++) {
		switch (i) {
		case 0:
			pos.x_ = GAME_WIDTH + (GAME_WIDTH *0.2);
			pos.y_ = GAME_HEIGHT - 550;

			enemy = factory->createEnemy(world, pos);
			Spawner::GetInstance()->AddEnemy(enemy);
			layer->addNodeToLayer(enemy->m_enemySprite);
			//layer->addBox2dNodes(enemy->m_body);

			break;
		case 1:
			pos.x_ = GAME_WIDTH + (GAME_WIDTH *0.4);
			pos.y_ = GAME_HEIGHT - 300;
			enemy = factory->createEnemy(world, pos);

			Spawner::GetInstance()->AddEnemy(enemy);
			layer->addNodeToLayer(enemy->m_enemySprite);
			//layer->addBox2dNodes(enemy->m_body);

			break;
		case 2:
			pos.x_ = GAME_WIDTH + (GAME_WIDTH*0.6);
			pos.y_ = GAME_HEIGHT - 180;
			enemy = factory->createEnemy(world, pos);

			Spawner::GetInstance()->AddEnemy(enemy);
			layer->addNodeToLayer(enemy->m_enemySprite);
			//layer->addBox2dNodes(enemy->m_body);

			break;
		case 3:
			pos.x_ = GAME_WIDTH + (GAME_WIDTH*0.8);
			pos.y_ = GAME_HEIGHT - 450;
			enemy = factory->createEnemy(world, pos);

			Spawner::GetInstance()->AddEnemy(enemy);
			layer->addNodeToLayer(enemy->m_enemySprite);
			//layer->addBox2dNodes(enemy->m_body);

			break;
		case 4:
			pos.x_ = GAME_WIDTH + (GAME_WIDTH);
			pos.y_ = GAME_HEIGHT - 250;

			enemy = factory->createEnemy(world, pos);

			Spawner::GetInstance()->AddEnemy(enemy);
			layer->addNodeToLayer(enemy->m_enemySprite);
			//layer->addBox2dNodes(enemy->m_body);

			break;
		case 5:
			pos.x_ = GAME_WIDTH + (GAME_WIDTH);
			pos.y_ = GAME_HEIGHT - 350;

			enemy = factory->createEnemy(world, pos);

			Spawner::GetInstance()->AddEnemy(enemy);
			layer->addNodeToLayer(enemy->m_enemySprite);
			//layer->addBox2dNodes(enemy->m_body);

			break;
		default:
			break;
		}
	}
	
	for (int j = 0; j < 5; j++) {

		switch (j) {
		case 0:
			pos.x_ = GAME_WIDTH + (GAME_WIDTH *0.2);
			pos.y_ = GAME_HEIGHT - 450;

			coin = factory->createCoin(world, pos);

			Spawner::GetInstance()->AddCoin(coin);
			layer->addNodeToLayer(coin->m_coinSprite);
			//layer->addBox2dNodes(coin->m_body);

			break;
		case 1:
			pos.x_ = GAME_WIDTH + (GAME_WIDTH *0.2);
			pos.y_ = GAME_HEIGHT - 500;


			coin = factory->createCoin(world, pos);

			Spawner::GetInstance()->AddCoin(coin);
			layer->addNodeToLayer(coin->m_coinSprite);
			//layer->addBox2dNodes(coin->m_body);
			break;
		case 2:
			pos.x_ = GAME_WIDTH + (GAME_WIDTH*0.4);
			pos.y_ = GAME_HEIGHT - 350;


			coin = factory->createCoin(world, pos);

			Spawner::GetInstance()->AddCoin(coin);
			layer->addNodeToLayer(coin->m_coinSprite);
			//layer->addBox2dNodes(coin->m_body);
			break;
		case 3:
			pos.x_ = GAME_WIDTH + (GAME_WIDTH*0.4);///slideunder
			pos.y_ = GAME_HEIGHT - 300;


			coin = factory->createCoin(world, pos);

			Spawner::GetInstance()->AddCoin(coin);
			layer->addNodeToLayer(coin->m_coinSprite);
			//layer->addBox2dNodes(coin->m_body);
			break;
		case 4:
			pos.x_ = GAME_WIDTH + (GAME_WIDTH*0.6);///slide under
			pos.y_ = GAME_HEIGHT - 250;


			coin = factory->createCoin(world, pos);

			Spawner::GetInstance()->AddCoin(coin);
			layer->addNodeToLayer(coin->m_coinSprite);
			//layer->addBox2dNodes(coin->m_body);
			break;
		case 5:
			pos.y_ = GAME_WIDTH + (GAME_WIDTH*0.6);///slide under
			pos.y_ = GAME_HEIGHT - 200;


			coin = factory->createCoin(world, pos);

			Spawner::GetInstance()->AddCoin(coin);
			layer->addNodeToLayer(coin->m_coinSprite);
		//	layer->addBox2dNodes(coin->m_body);
			break;
		default:
			break;
		}
	}
}


