#include "EnemyManager.h"

static EnemyManager* instance;

EnemyManager *EnemyManager::GetInstance() {
	if(!instance){
		instance = new (std::nothrow) EnemyManager();
	}
	return instance;
}


EnemyManager::EnemyManager() {
	//Empty
}

EnemyManager::~EnemyManager() {
	destroy();
}

void EnemyManager::AddEnemy(Enemy* enemy) {
	m_enemies.push_back(enemy);
}

void EnemyManager::FillEnemyVec() {
	enemyFactory = new EnemyFactory();

	
}

void EnemyManager::update() {
	EnemyUpdate();
}

void EnemyManager::destroy() {
	for (size_t i = 0; i < m_enemies.size(); i++){
		delete m_enemies.at(i);
	}
}

void EnemyManager::EnemyUpdate() {
	for (size_t i = 0; i < m_enemies.size(); i++){
		m_enemies.at(i)->update();
	}
}
