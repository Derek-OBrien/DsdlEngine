#pragma once

const int SCENE_INDEX_MAINMENU = 0;
const int SCENE_INDEX_GAMEPLAY = 1;

//Hard Code Window Size for now
#ifdef __WIN32__
#define GAME_WIDTH 1080
#define GAME_HEIGHT 1794
#endif

#ifdef __ANDROID__
#define GAME_WIDTH 1080
#define GAME_HEIGHT 1794
#endif