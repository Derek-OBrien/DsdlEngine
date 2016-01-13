#pragma once

#include <dsdl-engine/DsdlEngine.h>
#include <dsdl-engine/IMainGame.h>
#include "GameplayScene.h"

class App : public DsdlEngine::IMainGame{
public:
	App();
	~App();
 
	virtual void onInit() override;
	virtual void addScenes() override;
	virtual void onExit() override;

private:

	//DsdlEngine::Window m_pWindow;
	GameplayScene* m_pGameplayScene = new GameplayScene();
};
