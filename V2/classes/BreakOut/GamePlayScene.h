
#pragma once

#include "../../dsdl-engine/DsdlEngine.h"

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

	virtual void onInput();
private:

	void checkCollision();

	int m_sceneIndex = SCENE_INDEX_NO_SCENE;

	AudioManager m_AudioManager;


	Music music;

	InputManager m_inputManager;
	Layer* layer;
	Layer* fgLayer;
	HudLayer* hud;

	b2World* world;
	
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;


	
};





