
#ifndef _ENGINEDEFINES_
#define _ENGINEDEFINES_

#include <SDL.h>
//#include <SDL_image.h>
//#include <SDL_ttf.h>
//#include <SDL_mixer.h>


#include <string>
#include <iostream>
#include <memory>
#include <vector>

#include "EngineError.h"


///Engine Enums

/*
	Type of audio to play
	BG_ = Mix_Music = baground music 
	SFX_ = Mix_Chunk = Sound Effect
*/
typedef enum{ BG_, SFX_ }audio_type;

#endif