#pragma once

#include "../../dsdl-engine/DsdlEngine.h"
#include "GameDefines.h"

USING_NS_DSDL;

class GameOverScene : public IScene {

public:


	GameOverScene();
	~GameOverScene();


	virtual int getNextSceneIndex() const override;
	virtual int getPreviousSceneIndex() const override;

	virtual void destroyScene() override;

	virtual void onEntryScene() override;
	virtual void onExitScene() override;

	virtual void updateScene() override;

	bool changeNext();

private:

	int m_nextScreenIndex = SCENE_INDEX_OVER;

	Layer* layer;

};