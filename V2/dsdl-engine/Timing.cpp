
#include "EngineDefines.h"
#include "Timing.h"

namespace DsdlEngine{

	FpsLimiter::FpsLimiter() {}


	void FpsLimiter::init(float maxFPS) {
		setMaxFPS(maxFPS);
	}

	void FpsLimiter::setMaxFPS(float maxFPS) {
		m_fMaxFPS = maxFPS;
	}

	void FpsLimiter::begin() {
		m_iStartTicks = SDL_GetTicks();
	}

	float FpsLimiter::end() {
		calculateFPS();

		float frameTicks = (float)(SDL_GetTicks() - m_iStartTicks);
		//Limit the FPS to the max FPS
		if (1000.0f / m_fMaxFPS > frameTicks) {
			SDL_Delay((Uint32)(1000.0f / m_fMaxFPS - frameTicks));
		}

		return m_fFps;
	}

	void FpsLimiter::calculateFPS() {
		//The number of frames to average
		static const int NUM_SAMPLES = 5;
		//Stores all the frametimes for each frame that we will average
		static float frameTimes[NUM_SAMPLES];
		//The current frame we are on
		static int currentFrame = 0;
		//the ticks of the previous frame
		static Uint32 prevTicks = SDL_GetTicks();

		//Ticks for the current frame
		Uint32 currentTicks = SDL_GetTicks();

		//Calculate the number of ticks (ms) for this frame
		m_fFrameTime = (float)(currentTicks - prevTicks);
		frameTimes[currentFrame % NUM_SAMPLES] = m_fFrameTime;

		//current ticks is now previous ticks
		prevTicks = currentTicks;

		//The number of frames to average
		int count;

		currentFrame++;
		if (currentFrame < NUM_SAMPLES) {
			count = currentFrame;
		}
		else {
			count = NUM_SAMPLES;
		}

		//Average all the frame times
		float frameTimeAverage = 0;
		for (int i = 0; i < count; i++) {
			frameTimeAverage += frameTimes[i];
		}
		frameTimeAverage /= count;

		//Calculate FPS
		if (frameTimeAverage > 0) {
			m_fFps = 1000.0f / frameTimeAverage;
		}
		else {
			m_fFps = 120.0f;	//MAX ALLOWED 
		}
	}
}