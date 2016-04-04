
#include "HudLayer.h"
#include "GameDefines.h"
#include "PauseScene.h"

HudLayer::HudLayer() {
	//Empty
}

HudLayer::~HudLayer() {
	//Empty
}


void HudLayer::destroy() {
	gui->destroy();
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
	
	gui->addButton(
		ButtonType::SPRITE_BTN,
		"up",
		Vec2(200, 200 ),
		Vec2(64, 64),
		XmlLocalStorage::getInstance()->getStringForKey("up"),
		SDL_Color{ NULL },
		SDL_Color{ NULL },
		NULL
		);

	gui->addButton(
		ButtonType::SPRITE_BTN,
		"down",
		Vec2( 200, GAME_HEIGHT - 200),
		Vec2(64, 64),
		XmlLocalStorage::getInstance()->getStringForKey("down"),
		SDL_Color{ NULL },
		SDL_Color{ NULL },
		NULL
		);

	gui->addButton(
		ButtonType::SPRITE_BTN,
		"slide",
		Vec2(GAME_WIDTH - 200, GAME_HEIGHT - 200),
		Vec2(64, 64),
		XmlLocalStorage::getInstance()->getStringForKey("slide"),
		SDL_Color{ NULL },
		SDL_Color{ NULL },
		NULL
		);

	return gui;
}

void HudLayer::onInput(IMainGame* game, Character* player, Music bg) {
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt)) {
		gui->onSDLEvent(evnt);

		switch (evnt.type) {
		case SDL_MOUSEBUTTONDOWN:
			for (size_t i = 0; i < gui->GUIElements.size(); i++)
			{
				if (gui->GUIElements.at(i)->m_eCurrentState == ButtonState::PRESSED) {

					if (gui->GUIElements.at(i)->getButtonName() == "pause") {					
						pauseGame(game, bg);
					}
					if (gui->GUIElements.at(i)->getButtonName() == "up") {
						player->jump();
					}
					if (gui->GUIElements.at(i)->getButtonName() == "down") {
						player->fall();
					}
					if (gui->GUIElements.at(i)->getButtonName() == "slide") {
						player->slide();
					}
				}
			}
			//break;
		default:
			break;
		}
	}
}

void HudLayer::pauseGame(IMainGame* game, Music music) {
	SDL_Log("Game Paused");
	if (game->checkPaused() == false) {
		game->setPaused();
		music.audioPauseBG();
	}
	else {
		game->setRunning();
		music.audioResumeBG();
	}
}


void HudLayer::updateScore() {
	score += 1;
	scoreDisplay.str(" ");
	scoreDisplay << score;
	
	scoreLabel->updateLabelText(scoreDisplay.str().c_str());
}


void HudLayer::updateCoinCount(int x) {
	coinCount = coinCount + x;
	coinDisplay.str(" ");
	coinDisplay << coinCount;

	coinLabel->updateLabelText(coinDisplay.str().c_str());
}



void HudLayer::saveScore() {
	XmlLocalStorage::getInstance()->setIntegerForKey(score, "score");
}

void HudLayer::checkHighScore() {
	int curScore = XmlLocalStorage::getInstance()->getIntegerForKey("score");
	int newScore = score;
	
	if (newScore > score) {
		XmlLocalStorage::getInstance()->setIntegerForKey(newScore, "highscore");
	}

}