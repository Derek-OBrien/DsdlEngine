
#include "HudLayer.h"
#include "GameDefines.h"
#include "PauseScene.h"

HudLayer::HudLayer() {
	//Empty
}

HudLayer::~HudLayer() {
	//Empty
}


Layer* HudLayer::createHud() {

	coinLabel = new Label();
	scoreLabel = new Label();


	gui = new DsdlEngine::DsdlGui();
	score = 0;
	coinCount = 0;
	scoreText = "0";
	coinText = "Coins";

	coinLabel->create(Vec2(20, 50), coinText.c_str(), 60, SDL_Color{ 0,255,255 }, "fonts/font.ttf");
	gui->addPreDefineLabel(coinLabel, LableType::LABEL_DYNAMIC);

	
	scoreLabel->create(Vec2(GAME_WIDTH / 2, 50), scoreText.c_str(), 70, SDL_Color{ 0,255,255 }, "fonts/font.ttf");
	gui->addPreDefineLabel(scoreLabel, LableType::LABEL_DYNAMIC);

	gui->addButton(
		ButtonType::SPRITE_BTN,
		"pause",
		Vec2(GAME_WIDTH - 300, 60),
		Vec2(64, 64),
		XmlLocalStorage::getInstance()->getStringForKey("pause"),
		SDL_Color{ NULL },
		SDL_Color{ NULL },
		NULL
		);
	

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


void HudLayer::updateCoinCount() {
	coinCount = coinCount + 1;
	coinDisplay.str(" ");
	coinDisplay << coinCount;

	coinLabel->updateLabelText(coinDisplay.str().c_str());
}