
#include "GamePlayScene.h"
#include "GameDefines.h"

USING_NS_DSDL;

GamePlayScene::GamePlayScene(){
	m_sceneIndex = SCENE_INDEX_GAMEPLAY;
}

GamePlayScene::~GamePlayScene(){
	//Empty
}


int GamePlayScene::getNextSceneIndex() const{
	return SCENE_INDEX_MAINMENU;

}
int GamePlayScene::getPreviousSceneIndex() const{
	return SCENE_INDEX_MAINMENU;
}


void GamePlayScene::destroyScene(){
	//Destroy Layer and all its nodes
	layer->destroy();

}

void GamePlayScene::onEntryScene(){
	
	//Create Layer
	layer = new Layer();
	hud = new HudLayer();


	board = new Board(layer);
	board->create();
	board->setPosition(Vec2(0, 0));
	board->setSize(Size(GAME_WIDTH, GAME_HEIGHT));
	
	board->createLevel();


	ball = new Ball();
	ball->create();

	paddle = new Paddle();
	paddle->create();

	
	layer->addNodeToLayer(ball->m_ball);
	layer->addNodeToLayer(paddle->m_paddle);


	ResetPaddle();

	//Add Layer to Scene
	addLayerToScene(layer);
	addLayerToScene(hud->createHud());

	checkCollision = new HandleCollision();
}

void GamePlayScene::onExitScene(){
	destroyScene();
}

void GamePlayScene::updateScene(){
		
	///Process Input
	onInput();
	
	if (paddlestick) {
		StickBall();
	}

	CheckBoardCollisions();
	CheckPaddleCollisions();
	CheckBrickCollisions2();


	paddle->update(timeStep);

	if (!paddlestick) {
		ball->update(timeStep);
	}
}


void GamePlayScene::onInput() {
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt)) {

		hud->onInput(m_game);
		m_game->onSDLEvent(evnt);
		
	}
	int mx, my;
	Uint8 mstate = SDL_GetMouseState(&mx, &my);
	setPaddleX(mx - paddle->m_paddle->getContentSize().x_ / 2.0f);

	if (mstate&SDL_BUTTON(1)) {
		if (paddlestick) {
			paddlestick = false;
			ball->m_ball->setPosition(Vec2(paddle->m_paddle->getPosition().x_ / 2, paddle->m_paddle->getPosition().x_ + paddle->getContentSize().y_));
			ball->setDirection(1, -1);
		}
	}

}


void GamePlayScene::ResetPaddle() {
	paddlestick = true;
	StickBall();
}

void GamePlayScene::StickBall() {
	ball->m_ball->setPositionX(paddle->m_paddle->getPosition().x_ + paddle->m_paddle->getContentSize().x_ / 2 - ball->m_ball->getContentSize().x_ / 2);
	ball->m_ball->setPositionY(paddle->m_paddle->getPosition().y_ - ball->m_ball->getContentSize().y_);
}


void GamePlayScene::setPaddleX(float x) {
	float newx;

	if (x < board->getPosition().x_) {
		newx = board->getPosition().x_;
	}
	else if (x + paddle->m_paddle->getContentSize().x_ > board->getPosition().x_ + board->getContentSize().x_) {
        // Lower bound
        newx = board->getPosition().x_ + board->getContentSize().x_ - paddle->m_paddle->getContentSize().x_;
    } 
	else {
        newx = x;
    }
    paddle->m_paddle->setPositionX(newx);
	
}



float GamePlayScene::GetReflection(float hitx) {

	// Make sure the hitx variable is within the width of the paddle
	if (hitx < 0) {
		hitx = 0;
	}
	else if (hitx > paddle->m_paddle->getContentSize().x_) {
		hitx = paddle->m_paddle->getContentSize().x_;
	}

	// Everything to the left of the center of the paddle is reflected to the left
	// while everything right of the center is reflected to the right
	hitx -= paddle->m_paddle->getContentSize().x_ / 2.0f;

	// Scale the reflection, making it fall in the range -2.0f to 2.0f
	return 2.0f * (hitx / (paddle->m_paddle->getContentSize().x_ / 2.0f));
}



void GamePlayScene::CheckBoardCollisions() {
	if (ball->m_ball->getPosition().y_ < board->getPosition().y_) {
		ball->m_ball->setPositionY(board->getPosition().y_);
		ball->m_diry *= -1;
	}
	else if(ball->m_ball->getPosition().y_ + ball->m_ball->getContentSize().y_ > board->getPosition().y_ + board->getContentSize().y_){
		ResetPaddle();
		hud->updateLives();
	}

	if (ball->m_ball->getPosition().x_ <= board->getPosition().x_) {
		ball->m_ball->setPositionX(board->getPosition().x_);
		ball->m_dirx *= -1;
	}
	else if (ball->m_ball->getPosition().x_ + ball->m_ball->getContentSize().x_ > board->getPosition().x_ + board->getContentSize().x_) {
		ball->m_ball->setPositionX(board->getPosition().x_ + board->getContentSize().x_ - ball->m_ball->getContentSize().x_);
		ball->m_dirx *= -1;
	}
}

void GamePlayScene::CheckPaddleCollisions() {
	// Get the center x-coordinate of the ball
	float ballcenterx = ball->m_ball->getPosition().x_ + ball->m_ball->getContentSize().x_ / 2.0f;

	if (checkCollision->Collides(ball->m_ball, paddle->m_paddle)) {
		ball->m_ball->setPositionY(paddle->m_paddle->getPosition().y_ - ball->m_ball->getContentSize().y_);
		ball->setDirection(GetReflection(ballcenterx - paddle->m_paddle->getPosition().x_), -1);
	}
}

void GamePlayScene::CheckBrickCollisions2() {
	for (int i = 0; i<BOARD_WIDTH; i++) {
		for (int j = 0; j<BOARD_HEIGHT; j++) {
			//Brick brick = board->bricks[i][j];
			
			Brick* brick = new Brick();
			brick =(Brick*) board->bricks[i][j];
			
			// Check if brick is present
			if (brick->state) {
				// Brick x and y coordinates
				float brickx = board->brickoffsetx + board->getPosition().x_ + i*BOARD_BRWIDTH;
				float bricky = board->brickoffsety + board->getPosition().y_ + j*BOARD_BRHEIGHT;

				// Center of the ball x and y coordinates
				float ballcenterx = ball->m_ball->getPosition().x_ + 0.5f*ball->m_ball->getContentSize().x_;
				float ballcentery = ball->m_ball->getPosition().y_ + 0.5f*ball->m_ball->getContentSize().y_;

				// Center of the brick x and y coordinates
				float brickcenterx = brickx + 0.5f*BOARD_BRWIDTH;
				float brickcentery = bricky + 0.5f*BOARD_BRHEIGHT;

				if (ball->m_ball->getPosition().x_ <= brickx + BOARD_BRWIDTH && ball->m_ball->getPosition().x_ + ball->m_ball->getContentSize().x_ >= brickx && ball->m_ball->getPosition().y_ <= bricky + BOARD_BRHEIGHT && ball->m_ball->getPosition().y_ + ball->m_ball->getContentSize().y_ >= bricky) {
					// Collision detected, remove the brick
					brick->state = false;
					layer->removeNodeFromLayer(brick->m_brickSprite);

					///update score
					hud->updateScore();

					// Asume the ball goes slow enough to not skip through the bricks

					// Calculate ysize
					float ymin = 0;
					if (bricky > ball->m_ball->getPosition().y_) {
						ymin = bricky;
					}
					else {
						ymin = ball->m_ball->getPosition().y_;
					}

					float ymax = 0;
					if (bricky + BOARD_BRHEIGHT < ball->m_ball->getPosition().y_ + ball->m_ball->getContentSize().y_) {
						ymax = bricky + BOARD_BRHEIGHT;
					}
					else {
						ymax = ball->m_ball->getPosition().y_ + ball->m_ball->getContentSize().y_;
					}

					float ysize = ymax - ymin;

					// Calculate xsize
					float xmin = 0;
					if (brickx > ball->m_ball->getPosition().x_) {
						xmin = brickx;
					}
					else {
						xmin = ball->m_ball->getPosition().x_;
					}

					float xmax = 0;
					if (brickx + BOARD_BRWIDTH < ball->m_ball->getPosition().x_ + ball->m_ball->getContentSize().y_) {
						xmax = brickx + BOARD_BRWIDTH;
					}
					else {
						xmax = ball->m_ball->getPosition().x_ + ball->m_ball->getContentSize().x_;
					}

					float xsize = xmax - xmin;

					float x = ball->m_ball->getPosition().x_;

					float y = ball->m_ball->getPosition().y_;
					// The origin is at the top-left corner of the screen!
					// Set collision response
					if (xsize > ysize) {
						if (ballcentery > brickcentery) {
							// Bottom
							y += ysize + 0.01f;
							ball->m_ball->setPositionY(y); // Move out of collision
							BallBrickResponse(3);
						}
						else {
							// Top
							y  -= ysize + 0.01f;
							ball->m_ball->setPositionY(y); // Move out of collision
							BallBrickResponse(1);
						}
					}
					else {
						if (ballcenterx < brickcenterx) {
							// Left
							x -= xsize + 0.01f;
							ball->m_ball->setPositionX(x); // Move out of collision
							BallBrickResponse(0);
						}
						else {
							// Right
							x += xsize + 0.01f;
							ball->m_ball->setPositionX(x); // Move out of collision
							BallBrickResponse(2);
						}
					}

					return;
				}
			}
		}
	}
}

void GamePlayScene::BallBrickResponse(int dirindex) {
	// dirindex 0: Left, 1: Top, 2: Right, 3: Bottom

	// Direction factors
	int mulx = 1;
	int muly = 1;

	if (ball->m_dirx > 0) {
		// Ball is moving in the positive x direction
		if (ball->m_diry > 0) {
			// Ball is moving in the positive y direction
			// +1 +1
			if (dirindex == 0 || dirindex == 3) {
				mulx = -1;
			}
			else {
				muly = -1;
			}
		}
		else if (ball->m_diry < 0) {
			// Ball is moving in the negative y direction
			// +1 -1
			if (dirindex == 0 || dirindex == 1) {
				mulx = -1;
			}
			else {
				muly = -1;
			}
		}
	}
	else if (ball->m_dirx < 0) {
		// Ball is moving in the negative x direction
		if (ball->m_diry > 0) {
			// Ball is moving in the positive y direction
			// -1 +1
			if (dirindex == 2 || dirindex == 3) {
				mulx = -1;
			}
			else {
				muly = -1;
			}
		}
		else if (ball->m_diry < 0) {
			// Ball is moving in the negative y direction
			// -1 -1
			if (dirindex == 1 || dirindex == 2) {
				mulx = -1;
			}
			else {
				muly = -1;
			}
		}
	}

	// Set the new direction of the ball, by multiplying the old direction
	// with the determined direction factors
	ball->setDirection(mulx*ball->m_dirx, muly*ball->m_diry);
}