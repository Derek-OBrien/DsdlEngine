
#include "HudLayer.h"


HudLayer::HudLayer() {}
HudLayer::~HudLayer() {}


Layer* HudLayer::createHud() {


	auto gui = new DsdlEngine::DsdlGui();

	gui->addLabel(Vec2(20, 50), "Coin Count", 60, SDL_Color{ 0,255,255 }, "fonts/font.ttf");
	gui->addLabel(Vec2(500, 50), "Score", 60, SDL_Color{ 0,255,255 }, "fonts/font.ttf");


	gui->addButton(ButtonType::LABEL_BTN, Vec2(900, 50), Size(200, 100), "fonts/font.ttf", SDL_Color{ 0,255,255 }, SDL_Color{ 255,0,0 }, "Pause");


	return gui;
}



void HudLayer::updateScore() {
	score += 1;

}

void HudLayer::updateCoinCount() {
	coinCount += 1;
}