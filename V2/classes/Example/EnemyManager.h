#pragma once
#include "EnemyFactory.h"

class EnemyManager
{
public:
	static EnemyManager *GetInstance();

	void AddEnemy(Enemy* enemy);
	void AddCoin(Coins* coin);

	void FillEnemyVec();
	void update();

	void destroy();

	~EnemyManager();
private:
	std::vector<Enemy*> m_enemies;
	std::vector<Coins*> m_coins;

protected:
	Factory* factory;
	void EnemyUpdate();
	void CoinUpdate();

	EnemyManager();
};
