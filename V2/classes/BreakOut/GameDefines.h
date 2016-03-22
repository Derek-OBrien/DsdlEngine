#pragma once

const int SCENE_INDEX_MAINMENU = 0;
const int SCENE_INDEX_GAMEPLAY = 1;

//Hard Code Window Size for now
#ifdef __WIN32__
#define GAME_WIDTH 800
#define GAME_HEIGHT 600


// Define the dimensions of the board and bricks
#define BOARD_WIDTH 12
#define BOARD_HEIGHT 12
#define BOARD_BRWIDTH 64
#define BOARD_BRHEIGHT 24

#endif

#ifdef __ANDROID__
#define GAME_WIDTH 1080
#define GAME_HEIGHT 1794

// Define the dimensions of the board and bricks
#define BOARD_WIDTH 16
#define BOARD_HEIGHT 16
#define BOARD_BRWIDTH 64
#define BOARD_BRHEIGHT 24
#endif

