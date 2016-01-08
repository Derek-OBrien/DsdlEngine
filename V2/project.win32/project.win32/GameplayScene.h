#pragma once

#include <IScene.h>

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

private:


};