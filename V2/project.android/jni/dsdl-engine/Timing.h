#ifndef _TIMING_
#define _TIMING_


namespace DsdlEngine{

	///Calculates FPS and also limits FPS
	class FpsLimiter {
	public:
		FpsLimiter();

		// Initializes the FPS limiter. For now, this is
		// analogous to setMaxFPS
		void init(float maxFPS);

		// Sets the desired max FPS
		void setMaxFPS(float maxFPS);

		void begin();

		// end() will return the current FPS as a float
		float end();
	private:
		// Calculates the current FPS
		void calculateFPS();

		// Variables
		float m_fFps;
		float m_fMaxFPS;
		float m_fFrameTime;
		unsigned int m_iStartTicks;
	};
}

#endif