
#pragma once

#include "../../dsdl-engine/DsdlEngine.h"

#include "Character.h"
#include "ScrollingBg.h"
#include "EnemyFactory.h"
#include "HudLayer.h"

class GamePlayScene : public DsdlEngine::IScene{
public:
	GamePlayScene();
	~GamePlayScene();

	virtual int getNextSceneIndex() const override;
	virtual int getPreviousSceneIndex() const override;

	virtual void destroyScene() override;

	virtual void onEntryScene() override;
	virtual void onExitScene() override;

	virtual void updateScene() override;

private:

	void checkInput();
	void generateEnemy(Vec2 position);

	int m_sceneIndex = SCENE_INDEX_NO_SCENE;

	InputManager m_inputManager;
	Layer* layer;
	Layer* fgLayer;
	HudLayer* hud;

	ScrollingBg* bg;
	ScrollingBg* mg;

	Character* m_player;

	Enemy* enemy;

	///Enemy Factory
	EnemyFactory *m_enemyFactory;

	///Ground Physics
	b2World* world;
	b2BodyDef* groundBodyDef;
	b2Body* groundBody;

	b2PolygonShape* groundBox;

	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

};





