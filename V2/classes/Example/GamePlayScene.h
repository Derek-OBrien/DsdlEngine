
#pragma once

//#include <dsdl-engine\IMainGame.h>
//#include <dsdl-engine\IScene.h>
//#include <dsdl-engine\EngineDefines.h>
//#include <dsdl-engine\Window.h>
//#include <dsdl-engine\Sprite.h>
//#include <dsdl-engine\Label.h>
//#include <dsdl-engine\InputManager.h>
//#include <dsdl-engine\AudioManager.h>


#include "../../dsdl-engine/DsdlEngine.h"
//#include "DsdlEngine.h"

#include <random>

#include "Character.h"

class GamePlayScene : public DsdlEngine::IScene{
public:
	//GamePlayScene(DsdlEngine::Window* window);
	GamePlayScene();
	~GamePlayScene();

	virtual int getNextSceneIndex() const override;
	virtual int getPreviousSceneIndex() const override;

	virtual void destroyScene() override;

	virtual void onEntryScene() override;
	virtual void onExitScene() override;

	virtual void updateScene() override;

private:

	void checkInput();

	int m_sceneIndex = SCENE_INDEX_NO_SCENE;


//	DsdlEngine::Window* m_window;
	DsdlEngine::Label* m_glabel;
	DsdlEngine::InputManager m_inputManager;

	Character* myChar2;

};





