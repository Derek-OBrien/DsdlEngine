
#pragma once

#include "../../dsdl-engine/DsdlEngine.h"

#include "HudLayer.h"
#include "Ball.h"
#include "Paddle.h"
#include "Board.h"

#include "HandleCollision.h"

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

	bool paddlestick;

	void ResetPaddle();
	void StickBall();
	void setPaddleX(float x);


	float GetReflection(float hitx);


	void CheckBoardCollisions();
	void CheckPaddleCollisions();
	void CheckBrickCollisions();
	void CheckBrickCollisions2();
	void BallBrickResponse(int dirindex);


	int m_sceneIndex = SCENE_INDEX_NO_SCENE;

	AudioManager m_AudioManager;


	Music music;

	InputManager m_inputManager;
	Layer* layer;
	HudLayer* hud;
	
	float32 timeStep = 1.0f / 60.0f;

	Ball* ball;
	Paddle* paddle;
	Board* board;

	HandleCollision* checkCollision;
	
};





