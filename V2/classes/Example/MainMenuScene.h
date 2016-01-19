#pragma once

#include <dsdl-engine\Window.h>
#include <dsdl-engine\IScene.h>
#include <dsdl-engine\Label.h>
#include <dsdl-engine\InputManager.h>
#include <dsdl-engine\Button.h>

#include "GameDefines.h"

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

	DsdlEngine::Window* m_window;
	DsdlEngine::Label m_label;
	DsdlEngine::InputManager m_inputManager;
	DsdlEngine::Button m_button;
	DsdlEngine::Button m_SpriteButton;
};