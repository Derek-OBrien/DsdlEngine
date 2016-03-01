
#ifndef _ENGINEDEFINES_
#define _ENGINEDEFINES_


#include <SDL.h>
#include "../dependencies/SDL2/SDL_image/SDL_image.h"
#include "../dependencies/SDL2/SDL_ttf/SDL_ttf.h"
#include "../dependencies/SDL2/SDL_mixer/SDL_mixer.h"
//#include <SDL_image.h>
//#include <SDL_ttf.h>
//#include <SDL_mixer.h>



#include <Box2D\Box2D.h>
//#include "../dependencies/include/Box2D/Box2D.h"

#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <unordered_map>

#include <functional> //for std::function (CALLBACK FUNCTION)


#include "EngineError.h"
#include "EngineMath.h"
#include "EngineMaster.h"


//Set Macro Defines for Namespace
#define USING_NS_DSDL	using namespace DsdlEngine
#define NS_DSDL_START	namespace DsdlEngine{
#define NS_DSDL_END		}


enum class NodeType{
	BASENODE,
	SPRITE,
	LABEL,
	BUTTON
};

enum class ButtonState{
	NORMAL,
	PRESSED,
	HOVERING
};

enum class ButtonType {
	LABEL_BTN,
	SPRITE_BTN
};


#define DEFAULT_ROOT_NAME "DefaultRoot"
#define XML_FILE "Default.xml"



///Box2D scaling defines
#define METRESTOPIXELS 30
#define PIXELSTOMETRES 1/30.0f
#define RADTODEG  (-180/3.1415926536f)  
#define DEGTORAD -0.0174532925199432957f

#define GRAVITYSCALE 9.0f

#endif