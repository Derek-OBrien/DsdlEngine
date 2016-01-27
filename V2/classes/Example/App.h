
#pragma once
//#include <dsdl-engine\IMainGame.h>

#include "../../dsdl-engine/IMainGame.h"
#include "MainMenuScene.h"
#include "GamePlayScene.h"
#include "GameDefines.h"

class App : public DsdlEngine::IMainGame{

public:

	App();
	~App();

	virtual void onInit() override;
	virtual void addScenes() override;
	virtual void onExit() override;

private:

	std::unique_ptr<MainMenuScene> m_mainMenuScene;
	std::unique_ptr<GamePlayScene> m_gamePlayScene;
};