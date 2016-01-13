#pragma once
/*/
#include <dsdl-engine\DsdlEngine.h>
#include "dsdl-engine\Window.h"
#include <dsdl-engine\Timing.h>
#include <dsdl-engine\InputManager.h>
#include <dsdl-engine\Sprite.h>
#include <dsdl-engine\AudioManager.h>
*/

//Needed this type include for android build to complete???
#include "../dsdl-engine/AudioManager.h"
#include "../dsdl-engine/DsdlEngine.h"
#include "../dsdl-engine/InputManager.h"
#include "../dsdl-engine/Sprite.h"	
#include "../dsdl-engine/Timing.h"
#include "../dsdl-engine/Window.h"

enum class GameState{
	PLAY,
	EXIT
};

class MainGame{
public:
	MainGame();
	~MainGame();

	void run();
private:

	/// Initializes the core systems
	void initSystems();

	/// Initializes the level and sets up everything
	void initLevel();

	/// Main game loop for the program
	void gameLoop();

	/// Handles input processing
	void processInput();

	/// Render Everyting
	void draw();

	/// Member Variables
	DsdlEngine::Window m_window; ///< The game window
	DsdlEngine::InputManager m_inputManager;
	DsdlEngine::Sprite m_Player;
	DsdlEngine::AudioManager m_AudioManager;

	int m_screenWidth = 1024;
	int m_screenHeight = 768;

	float m_fps;


	GameState m_gameState;
};