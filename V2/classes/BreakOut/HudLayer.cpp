
#include "HudLayer.h"
#include "GameDefines.h"

HudLayer::HudLayer() {
	//Empty
}

HudLayer::~HudLayer() {
	//Empty
}


Layer* HudLayer::createHud() {

	scoreLabel = new Label();
	livesLabel = new Label();
	
	gui = new DsdlEngine::DsdlGui();
	score = 0;
	scoreText = "0";
	lives = 5;
	livesText = "5";

	gui->addLabel(LableType::LABEL_STATIC, Vec2(GAME_WIDTH / 2 - 100, 10), " Score : ", 30, SDL_Color{ 0,255,255 }, "fonts/font.ttf");
	gui->addLabel(LableType::LABEL_STATIC, Vec2(50, 10), " Lives : ", 30, SDL_Color{ 0,255,255 }, "fonts/font.ttf");

	livesLabel->create(Vec2(170, 10), livesText.c_str(), 30, SDL_Color{ 0,255,255 }, "fonts/font.ttf");
	gui->addPreDefineLabel(livesLabel, LableType::LABEL_DYNAMIC);

	scoreLabel->create(Vec2(GAME_WIDTH / 2 + 50 , 10), scoreText.c_str(), 30, SDL_Color{ 0,255,255 }, "fonts/font.ttf");
	gui->addPreDefineLabel(scoreLabel, LableType::LABEL_DYNAMIC);


	return gui;
}

void HudLayer::onInput(IMainGame* game) {
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt)) {
		gui->onSDLEvent(evnt);

		switch (evnt.type) {
		case SDL_MOUSEBUTTONDOWN:
			for (size_t i = 0; i < gui->GUIElements.size(); i++)
			{
				if (gui->GUIElements.at(i)->m_eCurrentState == ButtonState::PRESSED) {

					if (gui->GUIElements.at(i)->getButtonName() == "pause") {
						pauseGame(game);
					}
				}
			}
			break;
		default:
			break;
		}
	}
}

void HudLayer::pauseGame(IMainGame* game) {
	SDL_Log("Game Paused");
	if (game->checkPaused() == false)
		game->setPaused();
	else
		game->setRunning();
}


void HudLayer::updateScore() {
	score += 1;
	scoreDisplay.str(" ");
	scoreDisplay << score;
	
	scoreLabel->updateLabelText(scoreDisplay.str().c_str());
}


void HudLayer::updateLives() {
	lives -= 1;
	livesDisplay.str(" ");
	livesDisplay << lives;

	livesLabel->updateLabelText(livesDisplay.str().c_str());
}

