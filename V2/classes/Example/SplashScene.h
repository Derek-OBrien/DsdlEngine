
#pragma once

#include "../../dsdl-engine/DsdlEngine.h"
#include "GameDefines.h"

USING_NS_DSDL;

class SplashScene : public IScene
{
public:
	//SplashScene(DsdlEngine::Window* window);
	SplashScene();
	~SplashScene ();

	virtual int getNextSceneIndex() const override;
	virtual int getPreviousSceneIndex() const override;

	virtual void destroyScene() override;

	virtual void onEntryScene() override;
	virtual void onExitScene() override;

	virtual void updateScene() override;

	bool changeNext();

private:

	int m_nextScreenIndex = SCENE_INDEX_SPLASH;

	InputManager m_inputManager;
	Label* m_label;
	Layer* layer;

	Sprite* bg;
//	Window* m_window;
private:

};
