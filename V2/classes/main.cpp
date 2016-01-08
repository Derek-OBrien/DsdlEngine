/*
	Main Running Function
*/

#include "App.h"

#include "../project.win32/project.win32/MainGame.h"

int main(int argc, char** argv){
	
	MainGame mainGame;
	mainGame.run();

	return 0;
}