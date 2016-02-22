
#pragma once

#include "../../dsdl-engine/DsdlEngine.h"
#include "GameDefines.h"

USING_NS_DSDL;

class SplashScene : public IScene
{
public:
	SplashScene(Window* window);
	~SplashScene ();

	virtual int getNextSceneIndex() const override;
	virtual int getPreviousSceneIndex() const override;

	virtual void destroyScene() override;

	virtual void onEntryScene() override;
	virtual void onExitScene() override;

	virtual void updateScene() override;

private:


	int m_nextScreenIndex = SCENE_INDEX_SPLASH;

	Window* m_window;
	Label* m_label;

private:

};
