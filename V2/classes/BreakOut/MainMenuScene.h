#pragma once

#include "../../dsdl-engine/DsdlEngine.h"

#include "GameDefines.h"


USING_NS_DSDL;

class MainMenuScene : public IScene{

public:

	MainMenuScene();
	~MainMenuScene();

	virtual int getNextSceneIndex() const override;
	virtual int getPreviousSceneIndex() const override;

	virtual void destroyScene() override;

	virtual void onEntryScene() override;
	virtual void onExitScene() override;

	virtual void updateScene() override;

	virtual void onInput();
	
	void onNewGameClicked();

private:

	int m_nextScreenIndex = SCENE_INDEX_MAINMENU;

	Layer* layer;

	DsdlGui* gui;

	InputManager m_inputManager;
	AudioManager m_AudioManager;

	Music music;

};