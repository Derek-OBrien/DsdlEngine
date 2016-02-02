/*
	Main Running
*/


#include "Example\App.h"

int main(int argc, char* args[])
{


	App* mainGame = new App();

	mainGame->run();


	//Free resources and close SDL
	return 0;
}