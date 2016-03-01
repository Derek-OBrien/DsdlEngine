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

	void updateScore();
	void updateCoinCount();
private:

	int score, coinCount;

	std::string scoreText;	
	std::string coinText;	

	std::stringstream scoreDisplay;	
	std::stringstream coinDisplay;	

};

