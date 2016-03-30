#ifndef _TIMING_
#define _TIMING_
/*
	File: Timing.h
	Author: Derek O Brien
	Description: timming file handles setting up of caluclating and controlling frame rate
*/

namespace DsdlEngine{

	class FpsLimiter {
	public:
		//Constructor
		FpsLimiter();
		~FpsLimiter();

		// Initializes the FPS limiter.
		void init(float maxFPS);

		// Sets the desired max FPS
		void setMaxFPS(float maxFPS);

		//Start timer
		void begin();

		// end() will return the current FPS as a float
		float end();

	private:
		// Calculates the current FPS
		void calculateFPS();

		float m_fFps, m_fMaxFPS, m_fFrameTime;
		unsigned int m_iStartTicks;
	};
}

#endif