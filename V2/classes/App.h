#pragma once

#include <IMainGame.h>
#include "GameplayScene.h"

class App : public DsdlEngine::IMainGame{
public:
	App();
	~App();
 
	virtual void onInit() override;
	virtual void addScenes() override;
	virtual void onExit() override;

private:

	std::unique_ptr<GameplayScene> m_pGameplayScene = nullptr;
};