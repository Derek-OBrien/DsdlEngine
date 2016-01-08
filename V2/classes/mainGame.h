#ifndef _MAINGAME_
#define _MAINGAME_

#include <Include.h>

enum class eGameState{ PLAY, EXIT };

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();
	
private:
	void initSys();
	void processInput();
	void gameLoop();
	void drawGame();


	DsdlEngine::Window _pWindow;

	int _iScreenWidth;
	int _iScreenHeight;


	eGameState _eGameState;
};


#endif