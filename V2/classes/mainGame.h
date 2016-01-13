#pragma once

#include <dsdl-engine/DsdlEngine.h>
#include <dsdl-engine/Window.h>
#include <dsdl-engine/Timing.h>
#include <dsdl-engine/InputManager.h>
#include <dsdl-engine/Sprite.h>

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


	int m_screenWidth = 1024;
	int m_screenHeight = 768;

	float m_fps;


	GameState m_gameState;
};