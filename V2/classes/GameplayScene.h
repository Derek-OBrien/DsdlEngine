#pragma once

#include <dsdl-engine\IScene.h>
#include <dsdl-engine\DsdlEngine.h>
#include <dsdl-engine\Window.h>
#include <dsdl-engine\Timing.h>
#include <dsdl-engine\InputManager.h>
#include <dsdl-engine\Sprite.h>
#include <dsdl-engine\AudioManager.h>

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