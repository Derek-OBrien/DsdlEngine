#pragma once

#include <dsdl-engine\Window.h>
#include <dsdl-engine\IScene.h>
#include <dsdl-engine\Label.h>
#include <dsdl-engine\InputManager.h>
#include <dsdl-engine\Button.h>

#include "GameDefines.h"

#include "Character.h"

#include "Enemy.h"

USING_NS_DSDL;

class MainMenuScene : public DsdlEngine::IScene{

public:

	MainMenuScene(DsdlEngine::Window* window);
	~MainMenuScene();

	virtual int getNextSceneIndex() const override;
	virtual int getPreviousSceneIndex() const override;

	virtual void buildScene() override;
	virtual void destroyScene() override;

	virtual void onEntryScene() override;
	virtual void onExitScene() override;

	virtual void updateScene() override;

	virtual void drawScene() override;

	//virtual void addChild() override;

	//virtual void renderChildNodes() override;

private:

	void checkInput();

	bool onNewGameClicked();


	int m_nextScreenIndex = SCENE_INDEX_GAMEPLAY;

	Window* m_window;
	Label* m_label;
	InputManager m_inputManager;
	Button m_button;

	Character* myChar;

	Enemy* myChar2;


//	DsdlEngine::Sprite m_sprite;
};