#pragma once

//#include <dsdl-engine\Window.h>
//#include <dsdl-engine\IScene.h>
//#include <dsdl-engine\Label.h>
//#include <dsdl-engine\InputManager.h>
//#include <dsdl-engine\Button.h>



#include "../../dsdl-engine/DsdlEngine.h"
#include "../../dsdl-engine/Particles.h"
//#include "DsdlEngine.h"

#include "GameDefines.h"

#include "Character.h"

#include "Enemy.h"

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