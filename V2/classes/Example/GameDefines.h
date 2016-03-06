
#pragma once
const int SCENE_INDEX_SPLASH = 0;
const int SCENE_INDEX_MAINMENU = 1;
const int SCENE_INDEX_GAMEPLAY = 2;
const int SCENE_INDEX_OVER = 3;
const int SCENE_INDEX_PAUSE = 4;


//Hard Code Window Size for now
#ifdef __WIN32__
	#define GAME_WIDTH 1980
	#define GAME_HEIGHT 1080
#endif

#ifdef __ANDROID__
	#define GAME_WIDTH 1794
	#define GAME_HEIGHT 1080
#endif


typedef enum { ALIVE, DEAD, POWERUP, JUMPING, FALLING, SLIDING }EPlayerState;