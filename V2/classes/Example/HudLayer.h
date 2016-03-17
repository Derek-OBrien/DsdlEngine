#pragma once

#include "../../dsdl-engine/DsdlEngine.h"
#include <sstream>
#include "Character.h"
USING_NS_DSDL;

class HudLayer : public DsdlEngine::Layer
{
public:
	HudLayer();
	~HudLayer();

	Layer* createHud();

	virtual void onInput(IMainGame* game, Character* player);

	void pauseGame(IMainGame* game);

	void updateScore();
	void updateCoinCount();

	
	Label* scoreLabel;
	Label* coinLabel;
private:

	DsdlGui* gui;
	int score, coinCount;

	std::string scoreText;	
	std::string coinText;	

	std::stringstream scoreDisplay;	
	std::stringstream coinDisplay;	

};

