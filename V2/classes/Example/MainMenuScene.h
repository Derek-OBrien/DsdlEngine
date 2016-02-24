#pragma once

//#include <dsdl-engine\Window.h>
//#include <dsdl-engine\IScene.h>
//#include <dsdl-engine\Label.h>
//#include <dsdl-engine\InputManager.h>
//#include <dsdl-engine\Button.h>



#include "../../dsdl-engine/DsdlEngine.h"

//#include "DsdlEngine.h"

#include "GameDefines.h"

#include "Character.h"

#include "Enemy.h"

USING_NS_DSDL;

class MainMenuScene : public IScene{

public:

	//static IScene* create();

	//MainMenuScene(DsdlEngine::Window* window);
	MainMenuScene();
	~MainMenuScene();

	virtual int getNextSceneIndex() const override;
	virtual int getPreviousSceneIndex() const override;

	virtual void destroyScene() override;

	virtual void onEntryScene() override;
	virtual void onExitScene() override;

	virtual void updateScene() override;

private:

	void checkInput();

	bool onNewGameClicked();


	int m_nextScreenIndex = SCENE_INDEX_MAINMENU;

	Layer* layer;
	Label* m_label;
	InputManager m_inputManager;
	Button* m_button;
	AudioManager m_AudioManager;

	Character* myChar;

	Enemy* myChar2;

	Music music;

	//Window* m_window;
};