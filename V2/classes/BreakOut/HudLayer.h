#pragma once

#include "../../dsdl-engine/DsdlEngine.h"
#include <sstream>

USING_NS_DSDL;

class HudLayer : public DsdlEngine::Layer
{
public:
	HudLayer();
	~HudLayer();

	Layer* createHud();

	virtual void onInput(IMainGame* game);

	void pauseGame(IMainGame* game);

	void updateScore();
	
	
	Label* scoreLabel;
	
private:

	DsdlGui* gui;
	int score;

	std::string scoreText;	
	
	std::stringstream scoreDisplay;	
	
};

