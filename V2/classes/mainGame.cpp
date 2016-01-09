
#include "mainGame.h"

MainGame::MainGame() :
m_screenHeight(600),
m_screenWidth(1024),
m_gameState(GameState::PLAY),
m_fps(0){

	//Empty
}

MainGame::~MainGame(){}


void MainGame::run(){

	initSystems();

	gameLoop();
}

void MainGame::initSystems(){
	DsdlEngine::init();

	m_window.createWindow("TestGame", m_screenWidth, m_screenHeight, 2);

	m_Player.createSprite(100.0f, 200.0f, 73.0f, 79.0f,"../../assets/Character.png", m_window.getRenderer());
}


void MainGame::gameLoop(){
	const float DESIRED_FPS = 60.0f;
	const float MS_PER_SECOND = 1000;

	const float DESIRED_FRAMETIME = MS_PER_SECOND / DESIRED_FPS; // The desired frame time per frame
	const float MAX_DELTA_TIME = 1.0f; // Maximum size of deltaTime

	// Used to cap the FPS
	DsdlEngine::FpsLimiter fpsLimiter;
	fpsLimiter.setMaxFPS(60.0f);

	// Start our previousTicks variable
	float previousTicks = SDL_GetTicks();


	while (m_gameState == GameState::PLAY)
	{
		fpsLimiter.begin();
		// Calculate the frameTime in milliseconds
		float newTicks = SDL_GetTicks();
		float frameTime = newTicks - previousTicks;
		previousTicks = newTicks; // Store newTicks in previousTicks so we can use it next frame
		// Get the total delta time
		float totalDeltaTime = frameTime / DESIRED_FRAMETIME;


		m_inputManager.update();

		processInput();
		SDL_RenderClear(m_window.getRenderer());

		m_Player.draw(m_window.getRenderer());


		//Update screen
		SDL_RenderPresent(m_window.getRenderer());
		// End the frame, limit the FPS, and get the current FPS.
		m_fps = fpsLimiter.end();
	//	std::cout << m_fps << std::endl;
	}
}


/// Handles input processing
void MainGame::processInput(){
	SDL_Event evnt;
	//Will keep looping until there are no more events to process
	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
		case SDL_QUIT:
			m_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			m_inputManager.setMouseCoords(evnt.motion.x, evnt.motion.y);
			break;
		case SDL_KEYDOWN:
			m_inputManager.pressKey(evnt.key.keysym.sym);
			break;
		case SDL_KEYUP:
			m_inputManager.releaseKey(evnt.key.keysym.sym);
			break;
		case SDL_MOUSEBUTTONDOWN:
			m_inputManager.pressKey(evnt.button.button);
			break;
		case SDL_MOUSEBUTTONUP:
			m_inputManager.releaseKey(evnt.button.button);
			break;
		}
	}
}
