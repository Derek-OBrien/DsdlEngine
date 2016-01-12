#pragma once

#include <IScene.h>
#include <DsdlEngine.h>
#include <Window.h>
#include <Timing.h>
#include <InputManager.h>
#include <Sprite.h>

class GameplayScene : public DsdlEngine::IScene{

public:
	GameplayScene();
	~GameplayScene();

	virtual int getNextSceneIndex() const override;
	virtual int getPreviousSceneIndex() const override;

	virtual void buildScene() override;
	virtual void destroyScene() override;

	virtual void onEntryScene() override;
	virtual void onExitScene() override;

	virtual void updateScene() override;
	virtual void drawScene() override;

	virtual void addChild() override;
private:
	
	void checkInput();

	DsdlEngine::Window m_window; ///< The game window
	DsdlEngine::InputManager m_inputManager;
	DsdlEngine::Sprite m_Player;
};