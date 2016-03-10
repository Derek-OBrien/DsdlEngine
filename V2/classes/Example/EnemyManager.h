#pragma once
#include "EnemyFactory.h"

class Spawner
{
public:
	static Spawner *GetInstance();

	void AddEnemy(Enemy* enemy);
	void AddCoin(Coins* coin);

	void FillEnemyVec(b2World* world, Layer* layer);

	void update();

	void destroy();

	~Spawner();
private:
	std::vector<Enemy*> m_enemies;
	std::vector<Coins*> m_coins;

protected:
	Factory* factory;
	void EnemyUpdate();
	void CoinUpdate();
	Enemy* enemy;
	Coins* coin;

	Spawner();
};
