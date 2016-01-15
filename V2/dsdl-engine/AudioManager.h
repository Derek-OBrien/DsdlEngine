
#ifndef _AUDIOMANAGER_
#define _AUDIOMANAGER_

#include "EngineDefines.h"

namespace DsdlEngine{
	class SFX{
	public:
		friend class AudioManager;
		//@param loops == -1 : loop forever, 0 : loop once, 1+ : loop that many times
		void play(int loop = 0);
	private:
		Mix_Chunk* m_Chunk = nullptr;
	};

	class Music{
	public:
		friend class AudioManager;
		//@param loops == -1 : loop forever, 0 : loop once, 1+ : loop that many times
		void play(int loop = -1){ Mix_PlayMusic(m_Music, loop); };
		void audioPauseBG(){ Mix_PauseMusic(); };
		void audioResumeBG(){ Mix_ResumeMusic(); };
		void audioStopBG(){ Mix_HaltMusic(); };

	private:
		Mix_Music* m_Music = nullptr;
	};


	class AudioManager{
	public:
		AudioManager(){ init(); };
		~AudioManager(){ destroy(); };

		void init();
		void destroy();
		
		SFX loadSFX(std::string audioPath);
		Music loadMusic(std::string audioPath);

	private:
		//Maps to chache audio files so they are not loaded more than once
		std::map<std::string, Mix_Chunk*> m_sfxAudioMap;
		std::map<std::string, Mix_Music*> m_bgAudioMap;

		bool m_bisInitialized = false;
	};
}

#endif