#ifndef _TIMING_
#define _TIMING_
/**
*	@author Derek O Brien
*/

namespace DsdlEngine{

	/**
	*	Timming file handles setting up of caluclating and controlling frame rate of the engine.
	*/
	class FpsLimiter {
	public:
		/**
		*	Constructor
		*/
		FpsLimiter();

		/**
		*	Deconstructor
		*/
		~FpsLimiter();

		/**
		*	Initializes the FPS limiter.
		*	@param maxFPS, the max frame rate allowed.
		*/
		void init(float maxFPS);

		/**
		*	Sets the desired max FPS
		*	@param maxFPS, the desired Frame Rate.
		*/
		void setMaxFPS(float maxFPS);

		/**
		*	Start the Frame Rate Timer
		*/
		void begin();

		/**
		*	End the frame rate timer
		*	@return float, the current fps vlaue.
		*/
		float end();

	private:
		/**
		*	Calculate the running fps and keep it under control
		*/
		void calculateFPS();

		float m_fFps, m_fMaxFPS, m_fFrameTime;		/**< float values for claculations*/
		unsigned int m_iStartTicks;					/**< starting timestamp*/
	};
}

#endif