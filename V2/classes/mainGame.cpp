#include "mainGame.h"


MainGame::MainGame():

	_iScreenWidth (1024),
	_iScreenHeight (600),
	_eGameState(eGameState::PLAY){
}

MainGame::~MainGame(){}

void MainGame::run(){
	initSys();
	gameLoop();
}

//Set Up Everything
void MainGame::initSys(){
	
	_pWindow.createWindow("SDL Engine", _iScreenWidth, _iScreenHeight, SDL_WINDOW_OPENGL);

}


//Main Game Loop
void MainGame::gameLoop(){

	while (_eGameState != eGameState::EXIT){
		processInput();
		drawGame();
	}
}


//Process input
/*
	TODO: Move to input manager
*/
void MainGame::processInput(){

	SDL_Event pEvnt;

	while (SDL_PollEvent(&pEvnt)){
		switch (pEvnt.type)
		{
		case SDL_QUIT:
			_eGameState = eGameState::EXIT;
			break;
		default:
			break;
		}
	}
}

//Draw stuff
/*
	TODO : Move to Renderer Manager
*/
void MainGame::drawGame(){

	//Swap buffer

}