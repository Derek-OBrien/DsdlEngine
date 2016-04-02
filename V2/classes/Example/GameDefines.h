
#pragma once
const int SCENE_INDEX_SPLASH = 0;
const int SCENE_INDEX_MAINMENU = 1;
const int SCENE_INDEX_GAMEPLAY = 2;
const int SCENE_INDEX_OVER = 3;
const int SCENE_INDEX_PAUSE = 4;

//Collision Filters
#define PLAYER_FILTER 0x01
#define ENEMY_FILTER 0x02
#define COIN_FILTER 0x03
#define GROUND_FILTER 0x04

#define OBJECT_CAT 0x05

//Hard Code Window Size for now
#ifdef __WIN32__
	#define GAME_WIDTH 1980
	#define GAME_HEIGHT 1080
#endif

#ifdef __ANDROID__
	#define GAME_WIDTH 1794
	#define GAME_HEIGHT 1080
#endif

#ifdef __WINRT__
	#define GAME_WIDTH 1980
	#define GAME_HEIGHT 1080
#endif


typedef enum { ALIVE, DEAD, POWERUP, JUMPING, FALLING, SLIDING }EPlayerState;