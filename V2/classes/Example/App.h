
#pragma once
#include "SplashScene.h"
#include "MainMenuScene.h"
#include "GamePlayScene.h"
#include "PauseScene.h"
#include "GameOverScene.h"
#include "GameDefines.h"

class App : public DsdlEngine::IMainGame{

public:

	App();
	~App();

	virtual void onInit() override;
	virtual void addScenes() override;
	virtual void onExit() override;

private:

	std::unique_ptr<SplashScene> m_splashScene;
	std::unique_ptr<MainMenuScene> m_mainMenuScene;
	std::unique_ptr<GamePlayScene> m_gamePlayScene;
	std::unique_ptr<GameOverScene> m_gameOverScene;

};