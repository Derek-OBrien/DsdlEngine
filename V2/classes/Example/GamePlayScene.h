
#pragma once

//#include <dsdl-engine\IMainGame.h>
#include <dsdl-engine\IScene.h>
#include <dsdl-engine\EngineDefines.h>
#include <dsdl-engine\Window.h>
#include <dsdl-engine\Sprite.h>
#include <dsdl-engine\Label.h>
#include <dsdl-engine\InputManager.h>

#include "Box.h"
//#include <Box2D\Box2D.h>
#include "../../dependencies/Box2D/Box2D/Box2D/Box2D.h"
#include <random>


class GamePlayScene : public DsdlEngine::IScene{
public:
	GamePlayScene(DsdlEngine::Window* window);
	~GamePlayScene();

	virtual int getNextSceneIndex() const override;
	virtual int getPreviousSceneIndex() const override;

	virtual void buildScene() override;
	virtual void destroyScene() override;

	virtual void onEntryScene() override;
	virtual void onExitScene() override;

	virtual void updateScene() override;
	virtual void drawScene() override;

	virtual void addChild() override;
	virtual void renderChildNodes() override;

private:

	//void initUI();
	void checkInput();

	int m_sceneIndex = SCENE_INDEX_NO_SCENE;


	//DsdlEngine::InputManager m_input;
	DsdlEngine::Sprite m_sprite;
	DsdlEngine::Window* m_window;
	DsdlEngine::Label m_label;
	DsdlEngine::InputManager m_inputManager;
	DsdlEngine::ResourceTexture m_texture;


	b2World* m_World;
	std::vector<Box> boxes;
};





