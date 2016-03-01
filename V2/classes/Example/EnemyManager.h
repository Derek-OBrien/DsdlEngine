#pragma once
#include "EnemyFactory.h"

class EnemyManager
{
public:
	static EnemyManager *GetInstance();

	void AddEnemy(Enemy* enemy);
	void FillEnemyVec();
	void update();

	void destroy();

	~EnemyManager();
private:
	std::vector<Enemy*> m_enemies;

protected:
	EnemyFactory* enemyFactory;
	void EnemyUpdate();

	EnemyManager();
};
